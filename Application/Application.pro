TEMPLATE = app

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH +=  ../Core

CONFIG(debug, debug|release) {
LIBS+=  -L../lib/debug -lCore
} else {
LIBS+=  -L../lib/release -lCore
}

#TARGET = "PHPEditor"

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

win32 {## For Windows builds
    CONFIG(debug, debug|release) {
        LIB_FILES += ../lib/debug/Core.dll
    } else {
        LIB_FILES += ../lib/release/Core.dll
    }
}

unix {                     ## For unix builds
    #LIB_FILES += $$DESTDIR/...xxxxxx....
}

## Define what files are 'extra_libs' and where to put them
extra_libs.files = $$LIB_FILES
extra_libs.path = $$DESTDIR

## Tell qmake to add the moving of them to the 'install' target
INSTALLS += extra_libs
