QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
#CONFIG+= staticlib
# Input
UI_DIR = ui
#LIBS+= -lqscintilla

HEADERS += \
    Plugin/PluginManager.h \
    Plugin/PluginInterface.h \
    MainWindow.h \
    ConfigManager.h \
    LogBrowser.h \
    LogBrowserDialog.h \
    Export.h \
    Core.h \
    Workspace/Workspace.h \
    Workspace/Dock.h \
    Workspace/Perspective.h \
    Plugin/PluginsDialog.h \
    Plugin/PluginItem.h \
    Plugin/PluginData.h

SOURCES += \
    Plugin/PluginManager.cpp \
    MainWindow.cpp \
    ConfigManager.cpp \
    LogBrowser.cpp \
    LogBrowserDialog.cpp \
    Core.cpp \
    Workspace/Workspace.cpp \
    Workspace/Perspective.cpp \
    Plugin/PluginsDialog.cpp \
    Plugin/PluginItem.cpp \
    Plugin/PluginData.cpp

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
    Plugin/PluginsDialog.ui \
    Plugin/PluginItem.ui
