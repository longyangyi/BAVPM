pragma solidity ^0.5.0;

contract BAVPM {
    
	mapping (address => bytes) public ids ;
	mapping (uint8 => address) public PlatoonIDtoPL  ; 
	mapping (uint8 => address) public PlatoonMember ;
	
	mapping (uint8 => string ) public intraMessage ;
	mapping (uint8 => string ) public message;
	
	
	struct Ticket{
	    uint256 r;
	    uint256 s;
	}
	Ticket[] public tickets;

  	constructor() public payable
   	{
   	    
   	}
	
	modifier ControlOf(uint8 sender, uint8 receiver) {
		address addrSender   = PlatoonMember[sender  ] ;
		address addrReceiver = PlatoonMember[receiver] ;

		require(addrSender   != 0x0000000000000000000000000000000000000000,"addrSender == 0");
		require(addrReceiver != 0x0000000000000000000000000000000000000000,"addrReceiver == 0");
		require(ids[addrSender][0] == ids[addrReceiver][0],"ids s and r not equal");
	    
		_ ;
	}

	modifier OnlyConcernedObject (uint8 addr) {
		require(PlatoonMember[addr] == msg.sender ,"sender is not BAVPM member");
	    
		_ ;
	}
//node
	function BAVPM_AddNode (uint8 _category, uint8 _PlatoonID, uint8 _id, uint256 _r, uint256 _s) public payable
	{
		require(bytes(ids[msg.sender]).length == 0);
		require(PlatoonMember [_id] == 0x0000000000000000000000000000000000000000);

		if (_category == 0) {
			require(PlatoonIDtoPL[_PlatoonID] == 0x0000000000000000000000000000000000000000);
		    PlatoonIDtoPL [_PlatoonID] = msg.sender ;
		    
		} else {
		    //verify ticket
			bytes memory inputData = BAVPM_BytesConcat(_PlatoonID, _id, msg.sender) ;
	    	require(BAVPM_Verify (inputData, bytes32(_r), bytes32(_s), PlatoonIDtoPL[_PlatoonID]) == true);
    		uint k=0;
    		for(uint i=0;i<tickets.length;i++){
    		    if(tickets[i].r==_r && tickets[i].s==_s){
    		        k=1;
    		    }
    		}
    		require(k==0,"ticket used");
    		tickets.push(Ticket({r:_r,s:_s}));
		}
		PlatoonMember [_id] = msg.sender;
		BAVPM_SaveNode(msg.sender, _PlatoonID, _id) ;
	}
	function BAVPM_SaveNode(address _addr, uint8 _PlatoonID, uint8 _id) public {
		ids[_addr] = BAVPM_Concat2Bytes(_PlatoonID, _id) ;
	}
    function removeNode(uint8 _PlatoonID, uint8 _id) public{
        require( msg.sender == PlatoonMember[_id]);
        address _addr =PlatoonMember [_id];
        PlatoonMember [_id] =0x0000000000000000000000000000000000000000;
        delete ids[_addr] ;
    }
//communicate in Platoon
    function BAVPM_Send ( uint8 _sender,uint8 _PlatoonID, string memory msg)  public 
	{
	    address sender=PlatoonMember[_sender];
	    require(ids[sender][0]==ids[PlatoonIDtoPL[_PlatoonID]][0],"not belong to this Platoon");
	    string memory _str=	intraMessage[_PlatoonID]  ;
	    string memory _ss=strConcat(_str, msg);
	    intraMessage[_PlatoonID]=_ss;
    }
    function BAVPM_ReadMSG (uint8 PlatoonID)  public view returns (string memory) 
	{   address PlatoonLeader = PlatoonIDtoPL[PlatoonID];
	    require(ids[msg.sender][0]==ids[PlatoonLeader][0]);
		return intraMessage[PlatoonID];
   	}
//communicate with other Platoon
    function sendToOtherPlatoon(uint8 sender,uint8 grpFrom ,uint8 PlatoonIDTo,string memory msg) public{
        require( PlatoonMember[sender] ==PlatoonIDtoPL[grpFrom],"you are not Platoon Leader");
        
        address sender=PlatoonMember[sender];
	    string memory _str=	message[PlatoonIDTo]  ;
	    string memory _ss=strConcat(_str, msg);
	    message[PlatoonIDTo]=_ss;
    }
    function readMsgFromOtherPlatoon(uint8 myPlatoonID)public view returns(string memory){
        require(PlatoonIDtoPL[myPlatoonID]==msg.sender,"you are not Platoon Leader");
        return  message[myPlatoonID];
    }
//other tools
	function BAVPM_Concat2Bytes (uint8 v1, uint8 v2) public returns (bytes memory) {
		bytes memory res = new bytes(2) ;
		
		uint i = 0 ;
		res[i++] = byte(v1) ;
		res[i++] = byte(v2) ;
		
		return res ;
	}
	function BAVPM_Verify (bytes memory inputData, bytes32 _r, bytes32 _s, address PlatoonLeaderAddr)
		public returns (bool){
        	bytes32 hash = keccak256(inputData) ;
        	uint8   v    = 27 ;

        	if ((ecrecover(hash, v, _r, _s) == PlatoonLeaderAddr) || (ecrecover(hash, v+1, _r, _s) == PlatoonLeaderAddr)) 
            	return true ;
        	else
            	return false ;
	}
	function BAVPM_BytesConcat(uint8 v1, uint8 v2, address addr) internal returns (bytes memory)
	{
	    bytes memory baddr = BAVPM_FromAddressToBytes(addr) ;
		bytes memory res   = new bytes (1 + 1 + 20) ;
        
		uint i = 0 ;
		res[i++] = byte(v1) ;
		res[i++] = byte(v2) ;
		uint j = 0 ;
		for (j = 0; j < 20; j++)
			res[i++] = baddr[j] ;
	
		return res ;
	}
	function BAVPM_FromAddressToBytes(address a) public  view returns (bytes memory b) {
        assembly {
			let m := mload(0x40)
			mstore(add(m, 20), xor(0x140000000000000000000000000000000000000000, a))
			mstore(0x40, add(m, 52))
			b := m
        }
    }
    function BAVPM_FromBytesToBytes32(bytes memory src) public returns (bytes32 res) {
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
