BUILD_DIR = Application
# include config file
include( ../config.pri )

TEMPLATE = app
TARGET = "CodeEditor"
DESTDIR = $$PACKAGE_DESTDIR

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include ($$PROJECT_PATH/CodeEditor/CodeEditor.pri)

# Input
SOURCES += main.cpp \
    Application.cpp \
    LogBrowserDialog.cpp \
    LogBrowser.cpp

HEADERS += \
    Application.h \
    LogBrowserDialog.h \
    LogBrowser.h
