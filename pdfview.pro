#-------------------------------------------------
#
# Project created by QtCreator 2016-05-23T23:38:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pdfview
TEMPLATE = app
LIBS += -lpoppler-qt5

DEFINES += NOMINMAX

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
