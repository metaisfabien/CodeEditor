TEMPLATE = app

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH +=  ../Core

CONFIG(debug, debug|release) {
LIBS+=  -L../lib/debug -lCore -lqscintilla2
} else {
LIBS+=  -L../lib/release -lCore -lqscintilla2
}

# Input
SOURCES += main.cpp \
    Application.cpp

HEADERS += \
    Application.h

Release:DESTDIR = ../bin/release
Release:OBJECTS_DIR = ../bin/release/.obj
Release:MOC_DIR = ../bin/release/.moc
Release:RCC_DIR = ../bin/release/.rcc
Release:UI_DIR = ../bin/release/.ui

Debug:DESTDIR = ../bin/debug
Debug:OBJECTS_DIR = ../bin/debug/.obj
Debug:MOC_DIR = ../bin/debug/.moc
Debug:RCC_DIR = ../bin/debug/.rcc
Debug:UI_DIR = ../bin/debug/.ui
