#-------------------------------------------------
#
# Project created by QtCreator 2014-10-28T14:03:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lithium
TEMPLATE = app


SOURCES += main.cpp\
        lithium.cpp \
    unkisotop.cpp \
    unkmaterial.cpp \
    unkzone.cpp \
    unkmacsin.cpp \
    tempdialog.cpp

HEADERS  += lithium.h \
    unkisotop.h \
    unkmaterial.h \
    unkzone.h \
    unkmacsin.h \
    FlexLexer.h \
    UNK.l \
    tempdialog.h

FORMS    += lithium.ui \
    temp.ui
