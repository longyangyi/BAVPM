#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T16:16:31
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ticketGenerator
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp\
           uECC.cpp \
           Convertion.cpp\
           sha3.cpp

HEADERS  += mainwindow.h\
            ECC.h\
            uECC.h \
            Convertion.h\
            sha3.h

FORMS    += \
    MainWindow.ui

DISTFILES += \
    img/ETHEREUM-ICON_Black.png \
    img/follower.png \
    img/master.png \
    img/pic1.png \
    img/pic2.ico \
    img/success.png \
    img/ticket.png \
    img/ticket2.png \
    ticket2.png
