/**********************************************************
*                                                         *
*	Copyright (C)  2017				  *
*	GNU GENERAL PUBLIC LICENSE Version 3              *
*                                                         *
*	Author name : Mohamed Tahar HAMMI                 *
*	Date        : 01/June/2017                        *
*	Contact     : hammi_mohamed_tahar@hotmail.fr      *
*                                                         *
**********************************************************/

#include "mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include<sys/time.h>

//change path
#define FOLLOWER_IMG "/home/louis/BAVPM/BAVPMclient/img/PM.png"
#define MASTER_IMG   "/home/louis/BAVPM/BAVPMclient/img/PL.png"
#define FAIL_TRANSAC "/home/louis/BAVPM/BAVPMclient/img/failed.png"
#define SUCC_TRANSAC "/home/louis/BAVPM/BAVPMclient/img/success.png"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), blockchain (NULL), m_category (1)
{
    setupUi(this) ;
    setLogo("/home/louis/BAVPM/BAVPMclient/img/PM.png") ;
    QObject::connect(comboBox, SIGNAL(currentIndexChanged (int)), this, SLOT(SwitchLogo(int))) ;
}

MainWindow::~MainWindow()
{

}


void MainWindow::setLogo(QString imageFileName)
{
    labelPicture->setPixmap(QPixmap(imageFileName));
}

void MainWindow::SwitchLogo(int index)
{
    if (index == 0) {
        setLogo(FOLLOWER_IMG) ;
        m_category = 1 ; // follower
        textEdit->setEnabled(true) ;
    }
    else {
        setLogo(MASTER_IMG);
        m_category = 0 ;
        textEdit->setEnabled(false);
    }
}

void MainWindow::on_startButton_clicked ()
{
    QString transactionHash ;
    QString warnings = "" ;



    if (lineEdit1->text().length() < 7)
        warnings.append("Check the validity of your IP address..\n"     ) ;
    if (lineEdit2->text().isEmpty())
        warnings.append("Check the validity of your port value..\n"     ) ;
    if (lineEdit3->text().length() != 40)
        warnings.append("Check the validity of the contract address..\n") ;
    if (lineEdit4->text().isEmpty() || lineEdit4->text() == "00000000")
        warnings.append("Check the validity of your Platoon ID..\n"       ) ;
    if (lineEdit5->text().isEmpty() || lineEdit5->text() == "00000000")
        warnings.append("Check the validity of your PM ID..\n"        ) ;
    if (lineEdit6->text().length() != 40)
        warnings.append("Check the validity of your public address..\n" ) ;
    if ((textEdit->toPlainText().length() != 0) && (textEdit->toPlainText().length() != 128))
        warnings.append("Check the validity of your ticket <length should = 64 bytes or none>..\n" ) ;

    if (!warnings.isEmpty()) {
        QMessageBox::warning(this, "Warning", warnings) ;
        return ;
    }


    blockchain = new Blockchain(lineEdit1->text(), lineEdit2->text()) ;

    blockchain->setMyExternalAddress(lineEdit6->text()) ;
    blockchain->setContractAddress(lineEdit3->text());

    QString     paramsTypes ("uint8,uint8,uint8,uint256,uint256") ;
    QStringList paramsValues ;

    paramsValues.append (blockchain->EncodeUint8 (m_category)) ;                            // category
    paramsValues.append (blockchain->EncodeUint8(lineEdit4->text().toUInt(0, 16)))  ;       // platoon ID
    paramsValues.append (blockchain->EncodeUint8(lineEdit5->text().toUInt(0, 16)))  ;       // PM ID
    if(!textEdit->toPlainText().isEmpty()) {
        paramsValues.append (blockchain->EncodeUint256((const QString) textEdit->toPlainText().left(64)))  ;  // r --> (signature parameter 1)
        paramsValues.append (blockchain->EncodeUint256((const QString) textEdit->toPlainText().right(64))) ;  // s --> (signature parameter 2)
    } else {
        paramsValues.append (blockchain->EncodeString("")) ;
        paramsValues.append (blockchain->EncodeString("")) ;
    }

     transactionHash = blockchain->CallFunction("0x"+blockchain->getMyExternalAddress(),
                                                blockchain->getContractAddress(),
                                                blockchain->EncodeFunction("73881d9c",//sha3-256,0-4bytes:BAVPM_AddNode(uint8,uint8,uint8,uint256,uint256)"),
                                                                           paramsTypes,
                                                                           paramsValues),
                                                "eth_sendTransaction"
                                                ) ;
    qDebug() << "eth_sendTransaction success:"+transactionHash ;

    paramsValues.clear() ;
    paramsTypes = "" ;

    if  (transactionHash != "") {
        labTansaction->setPixmap(QPixmap(SUCC_TRANSAC)) ;
        this->setMinimumHeight(700) ;
    } else {
        labTansaction->setPixmap(QPixmap(FAIL_TRANSAC)) ;
    }

}


void MainWindow::on_sendButton_clicked()
{
    QString     transactionHash ;
    QString     paramsTypes ("uint8,uint8,uint8,string") ;
    QStringList paramsValues ;

    QString     msg ="Platoon"+ lineEdit4->text() + ": " + textEdit2->toPlainText() +"\n";

    paramsValues.append (blockchain->EncodeUint8 (lineEdit5->text().toUInt(0, 16))) ; //  ID of the sender
    paramsValues.append (blockchain->EncodeUint8 (lineEdit4->text().toUInt(0, 16))) ; //  ID of the sendPlatoon;
    paramsValues.append (blockchain->EncodeUint8 (lineEdit7->text().toUInt(0, 16))) ; //  ID of the receivePlatoon;
    paramsValues.append (blockchain->EncodeString(msg)) ;


     transactionHash = blockchain->CallFunction("0x"+blockchain->getMyExternalAddress(),
                                                blockchain->getContractAddress(),
                                                blockchain->EncodeFunction("c150af8c",//sendToOtherPlatoon(uint8,uint8,uint8,string)
                                                                           paramsTypes,
                                                                           paramsValues),
                                                "eth_sendTransaction"
                                                ) ;
    qDebug() << transactionHash ;

    paramsValues.clear() ;

}

void MainWindow::on_readButton_clicked()
{
    struct  timeval    tv;
    struct  timezone   tz;
    gettimeofday(&tv,&tz);
    long us=tv.tv_sec*1000000+tv.tv_usec;

    QString     res = "" ;
    QString     paramsTypes ("uint8") ;
    QStringList paramsValues ;

    paramsValues.append (blockchain->EncodeUint8 (lineEdit4->text().toUInt(0, 16))) ; // object ID

    res = blockchain->DecodeString(blockchain->CallFunction("0x"+blockchain->getMyExternalAddress(),
                                                            blockchain->getContractAddress(),
                                                            blockchain->EncodeFunction("7d925df9",//readMsgFromOtherPlatoon(uint8)
                                                                                       paramsTypes,
                                                                                       paramsValues),
                                                            "eth_call"
                                                            )
                                   ) ;
    if (res != "") {
        gettimeofday(&tv,&tz);
        long us2=tv.tv_sec*1000000+tv.tv_usec;
        qDebug()<<us2-us;

        textEdit2->clear();
        textEdit2->append(res) ;
    }
    paramsValues.clear() ;

}

void MainWindow::on_sendIntraMsgButton_clicked()
{
    QString     transactionHash ;
    QString     paramsTypes ("uint8,uint8,string") ;
    QStringList paramsValues ;

    QString     msg ="Node "+ lineEdit5->text() + ": " + textEdit3->toPlainText() +"\n";

    paramsValues.append (blockchain->EncodeUint8 (lineEdit5->text().toUInt(0, 16))) ; //  ID of the sender
    paramsValues.append (blockchain->EncodeUint8 (lineEdit4->text().toUInt(0, 16))) ; //  ID of the platoon;
    paramsValues.append (blockchain->EncodeString(msg)) ;


     transactionHash = blockchain->CallFunction("0x"+blockchain->getMyExternalAddress(),
                                                blockchain->getContractAddress(),
                                                blockchain->EncodeFunction("f467f2a1",//BAVPM_Send(uint8,uint8,string)
                                                                           paramsTypes,
                                                                           paramsValues),
                                                "eth_sendTransaction"
                                                ) ;
    qDebug() << transactionHash ;

    paramsValues.clear() ;

}

void MainWindow::on_readIntraMsgButton_clicked()
{
    QString     res = "" ;
    QString     paramsTypes ("uint8") ;
    QStringList paramsValues ;

    paramsValues.append (blockchain->EncodeUint8 (lineEdit4->text().toUInt(0, 16))) ; // object ID of the platoon

    res = blockchain->DecodeString(blockchain->CallFunction("0x"+blockchain->getMyExternalAddress(),
                                                            blockchain->getContractAddress(),
                                                            blockchain->EncodeFunction("f627f16f",//BAVPM_ReadMSG(uint8)
                                                                                       paramsTypes,
                                                                                       paramsValues),
                                                            "eth_call"
                                                            )
                                   ) ;
    if (res != "") {
        textEdit3->clear();
        textEdit3->append(res) ;
    }
    paramsValues.clear() ;

}

void MainWindow::on_leaveButton_clicked()
{
    QString     transactionHash ;
    QString     paramsTypes("uint8,uint8");
    QStringList paramsValues;

    paramsValues.append (blockchain->EncodeUint8 (lineEdit4->text().toUInt(0, 16))) ;
    paramsValues.append (blockchain->EncodeUint8 (lineEdit5->text().toUInt(0, 16))) ;

    transactionHash = blockchain->CallFunction("0x"+blockchain->getMyExternalAddress(),
                                               blockchain->getContractAddress(),
                                               blockchain->EncodeFunction("d67a196e",//removeNode(uint8,uint8)
                                                                          paramsTypes,
                                                                          paramsValues),
                                               "eth_sendTransaction"
                                               ) ;
   qDebug() << transactionHash ;

   paramsValues.clear() ;
}




int32_t MainWindow::FromQStringToUint8(u_int8_t * bytes, int32_t bytesLen, const QString& strArray)
{
    int32_t rc  = 0 ;

    if (bytes == NULL) {
        qDebug () << "MainWindow::FromQStringToUint8, bytes == NULL" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    if (bytesLen <= 0) {
        qDebug () << "MainWindow::FromQStringToUint8, bytesLen <= 0" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    if (strArray.isEmpty()) {
        qDebug () << "MainWindow::FromQStringToUint8, strArray.isEmpty()" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    if (strArray.length() <= 0) {
        qDebug () << "MainWindow::FromQStringToUint8, strArrayLen <= 0" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    if (bytesLen != strArray.length()/2) {
        qDebug () << "MainWindow::FromQStringToUint8, bytesLen != strArray.length()/2" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    for (int i = 0; i < bytesLen; i++)
        bytes[i] = strArray.mid(i*2,2).toUInt(0,16) ;


error:

    return rc ;
}



void MainWindow::Print_uint8 (const char * title, u_int8_t * data, int32_t dataLen)
{
    printf("%s", title) ;
    int i ;
    for (i = 0; i < dataLen; i++) {
        printf("%02X",data[i]) ;
    }
    printf("\n") ;
}
