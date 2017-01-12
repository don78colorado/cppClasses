#-------------------------------------------------
#
# Project created by QtCreator 2017-01-12T13:40:46
#
#-------------------------------------------------

QT       -= gui

TARGET = cppClasses
TEMPLATE = lib
CONFIG += staticlib

SOURCES += rational.cpp \
    ../src/Dog.cpp

HEADERS += rational.h \
    ../src/Dog.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
