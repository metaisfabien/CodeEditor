PLUGINNAME = PHP
BUILD_DIR = PluginPHP
include (../../config.pri)
include (../Plugins.pri)
include (../../CodeEditor/CodeEditor.pri)
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

OTHER_FILES += \
    php.json \
    plugin.json


SOURCES += Plugin.cpp
HEADERS += Plugin.h
