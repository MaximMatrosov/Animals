#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T15:32:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Animals
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    animal.cpp \
    cat.cpp \
    parrot.cpp \
    hamster.cpp \
    dog.cpp

HEADERS  += widget.h \
    animal.h \
    cat.h \
    parrot.h \
    hamster.h \
    dog.h

FORMS    += widget.ui

DISTFILES +=
