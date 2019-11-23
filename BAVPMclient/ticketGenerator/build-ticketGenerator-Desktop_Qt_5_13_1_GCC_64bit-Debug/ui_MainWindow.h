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
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit1;
    QLabel *label_2;
    QLineEdit *lineEdit2;
    QLabel *label_4;
    QLineEdit *lineEdit3;
    QLabel *label_5;
    QLineEdit *lineEdit4;
    QCommandLinkButton *generateButton;
    QFormLayout *formLayout_3;
    QTextEdit *textEdit1;
    QLabel *label_6;
    QTextEdit *textEdit2;
    QLabel *label_7;
    QTextEdit *textEdit3;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(704, 418);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../img/ticket2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 983, 348));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit1 = new QLineEdit(horizontalLayoutWidget);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));
        lineEdit1->setMinimumSize(QSize(540, 0));
        lineEdit1->setMaximumSize(QSize(540, 16777215));
        lineEdit1->setMaxLength(64);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit1);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));
        lineEdit2->setMaximumSize(QSize(100, 16777215));
        lineEdit2->setMaxLength(2);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit2);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEdit3 = new QLineEdit(horizontalLayoutWidget);
        lineEdit3->setObjectName(QString::fromUtf8("lineEdit3"));
        lineEdit3->setMaximumSize(QSize(100, 16777215));
        lineEdit3->setMaxLength(2);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit3);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        lineEdit4 = new QLineEdit(horizontalLayoutWidget);
        lineEdit4->setObjectName(QString::fromUtf8("lineEdit4"));
        lineEdit4->setMinimumSize(QSize(540, 0));
        lineEdit4->setMaximumSize(QSize(540, 16777215));
        lineEdit4->setMaxLength(64);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit4);


        verticalLayout_2->addLayout(formLayout);

        generateButton = new QCommandLinkButton(horizontalLayoutWidget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setMinimumSize(QSize(0, 40));
        generateButton->setMaximumSize(QSize(300, 30));

        verticalLayout_2->addWidget(generateButton);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        textEdit1 = new QTextEdit(horizontalLayoutWidget);
        textEdit1->setObjectName(QString::fromUtf8("textEdit1"));
        textEdit1->setMinimumSize(QSize(540, 50));
        textEdit1->setMaximumSize(QSize(540, 40));
        textEdit1->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, textEdit1);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_6);

        textEdit2 = new QTextEdit(horizontalLayoutWidget);
        textEdit2->setObjectName(QString::fromUtf8("textEdit2"));
        textEdit2->setMinimumSize(QSize(540, 50));
        textEdit2->setMaximumSize(QSize(540, 40));
        textEdit2->setReadOnly(true);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, textEdit2);

        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_7);

        textEdit3 = new QTextEdit(horizontalLayoutWidget);
        textEdit3->setObjectName(QString::fromUtf8("textEdit3"));
        textEdit3->setMinimumSize(QSize(540, 50));
        textEdit3->setMaximumSize(QSize(540, 40));
        textEdit3->setReadOnly(true);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, textEdit3);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);


        verticalLayout_2->addLayout(formLayout_3);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 704, 23));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Ticket generator", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PL private key: ", nullptr));
        lineEdit1->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Platoon ID: ", nullptr));
        lineEdit2->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "PM Object ID: ", nullptr));
        lineEdit3->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "PM private key: ", nullptr));
        lineEdit4->setText(QString());
        generateButton->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "PM address: ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "PM ticket: ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "PM public key:    ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
