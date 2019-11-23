pragma solidity ^0.5.0;

contract BCTrustV2 {
    
	mapping (address => bytes) public ids ;
	mapping (uint8 => address) public grpIdMasters  ; 
	mapping (uint8 => address) public BCTrustMember ;
	
	mapping (uint8 => string ) public boxes ;  //组内通信
	mapping (uint8 => string ) public message;  //组间通信
	
	
	struct Ticket{
	    uint256 r;
	    uint256 s;
	}
	Ticket[] public tickets;

  	constructor() public payable
   	{
   	    
   	}
	
	modifier ControlOf(uint8 sender, uint8 receiver) {
		address addrSender   = BCTrustMember[sender  ] ;
		address addrReceiver = BCTrustMember[receiver] ;

		require(addrSender   != 0x0000000000000000000000000000000000000000,"addrSender == 0");
		require(addrReceiver != 0x0000000000000000000000000000000000000000,"addrReceiver == 0");
		require(ids[addrSender][0] == ids[addrReceiver][0],"ids s and r not equal");
	    
		_ ;
	}

	modifier OnlyConcernedObject (uint8 addr) {
		require(BCTrustMember[addr] == msg.sender ,"sender is not BCTrust member");
	    
		_ ;
	}
//node
	function BCTrustV2_AddNode (uint8 _category, uint8 _grpId, uint8 _id, uint256 _r, uint256 _s) public payable
	{
		require(bytes(ids[msg.sender]).length == 0);
		require(BCTrustMember [_id] == 0x0000000000000000000000000000000000000000);

		if (_category == 0) {
			require(grpIdMasters[_grpId] == 0x0000000000000000000000000000000000000000);
		    grpIdMasters [_grpId] = msg.sender ;
		    
		} else {
		    //verify ticket
			bytes memory inputData = BCTrustV2_BytesConcat(_grpId, _id, msg.sender) ;
	    	require(BCTrustV2_Verify (inputData, bytes32(_r), bytes32(_s), grpIdMasters[_grpId]) == true);
    		uint k=0;
    		for(uint i=0;i<tickets.length;i++){
    		    if(tickets[i].r==_r && tickets[i].s==_s){
    		        k=1;
    		    }
    		}
    		require(k==0,"ticket used");
    		tickets.push(Ticket({r:_r,s:_s}));
		}
		BCTrustMember [_id] = msg.sender;
		BCTrustV2_SaveNode(msg.sender, _grpId, _id) ;
	}
	function BCTrustV2_SaveNode(address _addr, uint8 _grpId, uint8 _id) public {
		ids[_addr] = BCTrustV2_Concat2Bytes(_grpId, _id) ;
	}
    function removeNode(uint8 _grpId, uint8 _id) public{
        require( msg.sender == BCTrustMember[_id]);
        address _addr =BCTrustMember [_id];
        BCTrustMember [_id] =0x0000000000000000000000000000000000000000;
        delete ids[_addr] ;
    }
//communicate in group
    function BCTrustV2_Send ( uint8 _sender,uint8 _grpId, string memory msg)  public 
	{
	    address sender=BCTrustMember[_sender];
	    require(ids[sender][0]==ids[grpIdMasters[_grpId]][0],"not belong to this group");
	    string memory _str=	boxes[_grpId]  ;
	    string memory _ss=strConcat(_str, msg);
	    boxes[_grpId]=_ss;
    }
    function BCTrustV2_ReadMSG (uint8 grpid)  public view returns (string memory) 
	{   address master =grpIdMasters[grpid];
	    require(ids[msg.sender][0]==ids[master][0]);
		return boxes[grpid];
   	}
//communicate with other group
    function sendToOtherGroup(uint8 sender,uint8 grpFrom ,uint8 grpIdTo,string memory msg) public{
        require( BCTrustMember[sender] ==grpIdMasters[grpFrom],"you are not master");
        
        address sender=BCTrustMember[sender];
	    string memory _str=	message[grpIdTo]  ;
	    string memory _ss=strConcat(_str, msg);
	    message[grpIdTo]=_ss;
    }
    function readMsgFromOtherGroup(uint8 mygrpId)public view returns(string memory){
        require(grpIdMasters[mygrpId]==msg.sender,"you are not master");
        return  message[mygrpId];
    }
//other tools
	function BCTrustV2_Concat2Bytes (uint8 v1, uint8 v2) public returns (bytes memory) {
		bytes memory res = new bytes(2) ;
		
		uint i = 0 ;
		res[i++] = byte(v1) ;
		res[i++] = byte(v2) ;
		
		return res ;
	}
	function BCTrustV2_Verify (bytes memory inputData, bytes32 _r, bytes32 _s, address masterAddr)
		public returns (bool){
        	bytes32 hash = keccak256(inputData) ;
        	uint8   v    = 27 ;

        	if ((ecrecover(hash, v, _r, _s) == masterAddr) || (ecrecover(hash, v+1, _r, _s) == masterAddr)) 
            	return true ;
        	else
            	return false ;
	}
	function BCTrustV2_BytesConcat(uint8 v1, uint8 v2, address addr) internal returns (bytes memory)
	{
	    bytes memory baddr = BCTrustV2_FromAddressToBytes(addr) ;
		bytes memory res   = new bytes (1 + 1 + 20) ;
        
		uint i = 0 ;
		res[i++] = byte(v1) ;
		res[i++] = byte(v2) ;
		uint j = 0 ;
		for (j = 0; j < 20; j++)
			res[i++] = baddr[j] ;
	
		return res ;
	}
	function BCTrustV2_FromAddressToBytes(address a) public  view returns (bytes memory b) {
        assembly {
			let m := mload(0x40)
			mstore(add(m, 20), xor(0x140000000000000000000000000000000000000000, a))
			mstore(0x40, add(m, 52))
			b := m
        }
    }
    function BCTrustV2_FromBytesToBytes32(bytes memory src) public returns (bytes32 res) {
        assembly {
            res := mload(add(src, 32))
        }
        
    }
    function strConcat(string memory _a, string memory _b) public returns (string memory){
        bytes memory _ba = bytes(_a);
        bytes memory _bb = bytes(_b);
        string memory ret = new string(_ba.length + _bb.length );
        bytes memory bret = bytes(ret);
        uint k = 0;
        for (uint i = 0; i < _ba.length; i++)bret[k++] = _ba[i];
        for (uint i = 0; i < _bb.length; i++) bret[k++] = _bb[i];
        return string(ret);
   } 
}
