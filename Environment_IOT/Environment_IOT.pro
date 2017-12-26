#-------------------------------------------------
#
# Project created by QtCreator 2017-12-07T10:22:55
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Environment_IOT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    register.cpp \
    forgetpassword.cpp \
    showmainwindow.cpp \
    comform.cpp \
    protocolanalysis.cpp

HEADERS  += mainwindow.h \
    register.h \
    forgetpassword.h \
    showmainwindow.h \
    comform.h \
    protocolanalysis.h

FORMS    += mainwindow.ui \
    register.ui \
    forgetpassword.ui \
    showmainwindow.ui \
    comform.ui
