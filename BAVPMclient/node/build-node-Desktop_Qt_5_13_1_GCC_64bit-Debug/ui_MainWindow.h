/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPicture;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit1;
    QLabel *label_2;
    QLineEdit *lineEdit2;
    QLabel *label_3;
    QLineEdit *lineEdit3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QLineEdit *lineEdit4;
    QLabel *label_6;
    QLineEdit *lineEdit5;
    QLabel *label_7;
    QLineEdit *lineEdit6;
    QLabel *label_8;
    QTextEdit *textEdit;
    QPushButton *leaveButton;
    QLabel *labTansaction;
    QSpacerItem *verticalSpacer;
    QPushButton *startButton;
    QFormLayout *formLayout_2;
    QLabel *labTo;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit7;
    QCommandLinkButton *sendButton;
    QCommandLinkButton *readButton;
    QLabel *labMessage;
    QTextEdit *textEdit2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QTextEdit *textEdit3;
    QHBoxLayout *horizontalLayout_6;
    QCommandLinkButton *sendIntraMsgButton;
    QCommandLinkButton *readIntraMsgButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(975, 400);
        MainWindow->setMinimumSize(QSize(0, 400));
        MainWindow->setMaximumSize(QSize(16777215, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../img/follower.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 937, 701));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelPicture = new QLabel(verticalLayoutWidget);
        labelPicture->setObjectName(QString::fromUtf8("labelPicture"));
        labelPicture->setMinimumSize(QSize(150, 0));
        labelPicture->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(labelPicture);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label);

        lineEdit1 = new QLineEdit(verticalLayoutWidget);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));
        lineEdit1->setMinimumSize(QSize(75, 0));
        lineEdit1->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_2->addWidget(lineEdit1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(label_2);

        lineEdit2 = new QLineEdit(verticalLayoutWidget);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));
        lineEdit2->setMinimumSize(QSize(45, 0));
        lineEdit2->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_2->addWidget(lineEdit2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(125, 0));
        label_3->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_2->addWidget(label_3);

        lineEdit3 = new QLineEdit(verticalLayoutWidget);
        lineEdit3->setObjectName(QString::fromUtf8("lineEdit3"));
        lineEdit3->setMinimumSize(QSize(295, 0));
        lineEdit3->setMaximumSize(QSize(275, 16777215));

        horizontalLayout_2->addWidget(lineEdit3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(15, -1, 0, -1);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(125, 0));
        label_4->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMaximumSize(QSize(285, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(125, 0));
        label_5->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        lineEdit4 = new QLineEdit(verticalLayoutWidget);
        lineEdit4->setObjectName(QString::fromUtf8("lineEdit4"));
        lineEdit4->setMinimumSize(QSize(60, 0));
        lineEdit4->setMaximumSize(QSize(60, 16777215));
        lineEdit4->setMaxLength(2);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit4);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(125, 0));
        label_6->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        lineEdit5 = new QLineEdit(verticalLayoutWidget);
        lineEdit5->setObjectName(QString::fromUtf8("lineEdit5"));
        lineEdit5->setMinimumSize(QSize(60, 0));
        lineEdit5->setMaximumSize(QSize(60, 16777215));
        lineEdit5->setMaxLength(2);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit5);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(125, 0));
        label_7->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        lineEdit6 = new QLineEdit(verticalLayoutWidget);
        lineEdit6->setObjectName(QString::fromUtf8("lineEdit6"));
        lineEdit6->setMinimumSize(QSize(285, 0));
        lineEdit6->setMaximumSize(QSize(285, 16777215));
        lineEdit6->setMaxLength(40);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit6);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(125, 0));
        label_8->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_8);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(60, 95));
        textEdit->setMaximumSize(QSize(285, 60));

        formLayout->setWidget(6, QFormLayout::FieldRole, textEdit);

        leaveButton = new QPushButton(verticalLayoutWidget);
        leaveButton->setObjectName(QString::fromUtf8("leaveButton"));

        formLayout->setWidget(7, QFormLayout::FieldRole, leaveButton);


        horizontalLayout_3->addLayout(formLayout);

        labTansaction = new QLabel(verticalLayoutWidget);
        labTansaction->setObjectName(QString::fromUtf8("labTansaction"));
        labTansaction->setMinimumSize(QSize(250, 150));
        labTansaction->setMaximumSize(QSize(150, 150));

        horizontalLayout_3->addWidget(labTansaction);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout_2->addWidget(startButton);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(175, -1, 350, -1);
        labTo = new QLabel(verticalLayoutWidget);
        labTo->setObjectName(QString::fromUtf8("labTo"));
        labTo->setMinimumSize(QSize(125, 0));
        labTo->setMaximumSize(QSize(125, 16777215));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labTo);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit7 = new QLineEdit(verticalLayoutWidget);
        lineEdit7->setObjectName(QString::fromUtf8("lineEdit7"));
        lineEdit7->setMinimumSize(QSize(60, 0));
        lineEdit7->setMaximumSize(QSize(60, 16777215));
        lineEdit7->setMaxLength(2);

        horizontalLayout_4->addWidget(lineEdit7);

        sendButton = new QCommandLinkButton(verticalLayoutWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setMaximumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(sendButton);

        readButton = new QCommandLinkButton(verticalLayoutWidget);
        readButton->setObjectName(QString::fromUtf8("readButton"));
        readButton->setMaximumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(readButton);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);

        labMessage = new QLabel(verticalLayoutWidget);
        labMessage->setObjectName(QString::fromUtf8("labMessage"));
        labMessage->setMinimumSize(QSize(125, 0));
        labMessage->setMaximumSize(QSize(125, 16777215));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labMessage);

        textEdit2 = new QTextEdit(verticalLayoutWidget);
        textEdit2->setObjectName(QString::fromUtf8("textEdit2"));
        textEdit2->setMinimumSize(QSize(0, 80));
        textEdit2->setMaximumSize(QSize(285, 60));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, textEdit2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_5);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(125, 0));
        label_10->setMaximumSize(QSize(125, 16777215));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_10);

        textEdit3 = new QTextEdit(verticalLayoutWidget);
        textEdit3->setObjectName(QString::fromUtf8("textEdit3"));
        textEdit3->setMaximumSize(QSize(300, 80));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, textEdit3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        sendIntraMsgButton = new QCommandLinkButton(verticalLayoutWidget);
        sendIntraMsgButton->setObjectName(QString::fromUtf8("sendIntraMsgButton"));
        sendIntraMsgButton->setMaximumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(sendIntraMsgButton);

        readIntraMsgButton = new QCommandLinkButton(verticalLayoutWidget);
        readIntraMsgButton->setObjectName(QString::fromUtf8("readIntraMsgButton"));
        readIntraMsgButton->setMaximumSize(QSize(80, 30));

        horizontalLayout_6->addWidget(readIntraMsgButton);


        formLayout_2->setLayout(4, QFormLayout::FieldRole, horizontalLayout_6);


        verticalLayout->addLayout(formLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 975, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelPicture->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        lineEdit1->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        lineEdit2->setText(QCoreApplication::translate("MainWindow", "8545", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Contract Address:", nullptr));
        lineEdit3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Category:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Platoon Member", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Platoon Leader", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Platoon ID:", nullptr));
        lineEdit4->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "PM ID:", nullptr));
        lineEdit5->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Public address:", nullptr));
        lineEdit6->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Ticket:</p></body></html>", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p></body></html>", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "< If you access to platoon for the first time, you need to put your ticket here >", nullptr));
        leaveButton->setText(QCoreApplication::translate("MainWindow", "leave", nullptr));
        labTansaction->setText(QString());
        startButton->setText(QCoreApplication::translate("MainWindow", "Access to Platoon", nullptr));
        labTo->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>To Platoon:</p></body></html>", nullptr));
        lineEdit7->setText(QString());
        sendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        readButton->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        labMessage->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Intern Platoon Msg:</p></body></html>", nullptr));
        textEdit2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p></body></html>", nullptr));
        textEdit2->setPlaceholderText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Intra Platoon Msg:", nullptr));
        sendIntraMsgButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        readIntraMsgButton->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
