PLUGINNAME = PHP
BUILD_DIR = PluginPHP
include (../../config.pri)
include (../Plugins.pri)
include (../../CodeEditor/CodeEditor.pri)

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS+= -lqscintilla2

OTHER_FILES += \
    php.json \
    plugin.json


SOURCES += Plugin.cpp \
    Editor/PHPEditor.cpp \
    Editor/PHPEditorWidget.cpp
HEADERS += Plugin.h \
    Editor/PHPEditor.h \
    Editor/PHPEditorWidget.h
