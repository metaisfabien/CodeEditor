#-------------------------------------------------
#
# Project created by QtCreator 2013-09-14T18:46:55
#
#-------------------------------------------------

TEMPLATE = lib
CONFIG   += plugin
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG(debug, debug|release) {
LIBS+=  -L../../lib/debug -lCore
} else {
LIBS+=  -L../../lib/release -lCore
}

INCLUDEPATH +=  ../../Core

Release:DESTDIR = ../../bin/release/plugins
Release:OBJECTS_DIR = ../../bin/release/plugins/.obj
Release:MOC_DIR = ../../bin/release/plugins/.moc
Release:RCC_DIR = ../../bin/release/plugins/.rcc
Release:UI_DIR = ../../bin/release/plugins/.ui

Debug:DESTDIR = ../../bin/debug/plugins
Debug:OBJECTS_DIR = ../../bin/debug/plugins/.obj
Debug:MOC_DIR = ../../bin/debug/plugins/.moc
Debug:RCC_DIR = ../../bin/debug/plugins/.rcc
Debug:UI_DIR = ../../bin/debug/plugins/.ui

SOURCES += TestPlugin.cpp
HEADERS += TestPlugin.h
EXAMPLE_FILES = test_plugin.json
OTHER_FILES += \
    test_plugin.json


