PLUGINNAME = PHP
BUILD_DIR = PluginPHP
include (../../config.pri)
include (../Plugins.pri)
include (../../CodeEditor/CodeEditor.pri)
include( ../../ctags/ctags.pri )
QT += core widgets gui

LIBS+= -lqscintilla2

INCLUDEPATH *= $$PROJECT_PATH/dependencies/QScintilla-gpl-2.9.1/Qt4Qt5

OTHER_FILES += \
    php.json \
    plugin.json \



SOURCES += Plugin.cpp \
    Editor/PHPEditor.cpp \
    Editor/PHPEditorWidget.cpp \
    Builder.cpp \

HEADERS += Plugin.h \
    Editor/PHPEditor.h \
    Editor/PHPEditorWidget.h \
    Builder.h \

