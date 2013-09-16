QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
#CONFIG+= staticlib
# Input
UI_DIR = ui

HEADERS += \
    PluginManager.h \
    PluginInterface.h \
    MainWindow.h \
    ConfigManager.h \
    LogBrowser.h \
    LogBrowserDialog.h \
    Export.h \
    Core.h \
    NewProjectDialog.h

SOURCES += \
    PluginManager.cpp \
    MainWindow.cpp \
    ConfigManager.cpp \
    LogBrowser.cpp \
    LogBrowserDialog.cpp \
    Core.cpp \
    NewProjectDialog.cpp

DEFINES += CORE_LIBRARY

Release:DESTDIR = ../lib/release
Release:OBJECTS_DIR = ../lib/release/.obj
Release:MOC_DIR = ../lib/release/.moc
Release:RCC_DIR = ../lib/release/.rcc


Debug:DESTDIR = ../lib/debug
Debug:OBJECTS_DIR = ../lib/debug/.obj
Debug:MOC_DIR = ../lib/debug/.moc
Debug:RCC_DIR = ../lib/debug/.rcc

FORMS += \
    NewProjectDialog.ui
