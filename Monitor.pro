#-------------------------------------------------
#
# Project created by QtCreator 2018-07-09T11:47:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Monitor
TEMPLATE = app


SOURCES += main.cpp\
        mymainwindow.cpp \
    mywindowtitle.cpp \
    customheartrate.cpp \
    myleftwindow.cpp \
    myrightwindow.cpp \
    custombcg.cpp \
    customlorenz.cpp \
    customecg.cpp \
    customstate.cpp \
    customsppr.cpp \
    customresp.cpp \
    customtemp.cpp \
    customnibp.cpp \
    customnibg.cpp \
    myreadthread.cpp \
    mywritethread.cpp \
    mystatic.cpp \
    ciclebuffer.cpp \
    cycle_fifo.c \
    smoothgenerator.cpp

HEADERS  += mymainwindow.h \
    mywindowtitle.h \
    customheartrate.h \
    myleftwindow.h \
    myrightwindow.h \
    custombcg.h \
    customlorenz.h \
    customecg.h \
    customstate.h \
    customsppr.h \
    customresp.h \
    customtemp.h \
    customnibp.h \
    customnibg.h \
    myreadthread.h \
    mywritethread.h \
    mystatic.h \
    ciclebuffer.h \
    cycle_fifo.h \
    smoothgenerator.h

DISTFILES += \
    TestJava.java

RESOURCES += \
    images.qrc \
    data.qrc
