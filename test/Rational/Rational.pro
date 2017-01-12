#-------------------------------------------------
#
# Project created by QtCreator 2017-01-12T13:39:40
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_rationaltest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_rationaltest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../cppClasses/release/ -lcppClasses
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../cppClasses/debug/ -lcppClasses
else:unix: LIBS += -L$$OUT_PWD/../../cppClasses/ -lcppClasses

INCLUDEPATH += $$PWD/../../cppClasses
DEPENDPATH += $$PWD/../../cppClasses

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../cppClasses/release/libcppClasses.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../cppClasses/debug/libcppClasses.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../cppClasses/release/cppClasses.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../cppClasses/debug/cppClasses.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../cppClasses/libcppClasses.a
