QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
LIBS+= -lqscintilla2

HEADERS += \
    Plugin/PluginManager.h \
    Plugin/PluginInterface.h \
    MainWindow.h \
    Export.h \
    CodeEditor.h \
    Workspace/Workspace.h \
    Workspace/Dock.h \
    Workspace/Perspective.h \
    Plugin/PluginsDialog.h \
    Plugin/PluginItem.h \
    Plugin/PluginData.h \
    Editor/EditorManager.h \
    Editor/Editor.h \
    Setting/SettingManager.h \
    Setting/SettingsDialog.h \
    Setting/SettingsTreeItem.h\
    Setting/Section/SettingEditorsSection.h \
    Setting/Section/SettingGeneralSection.h \
    Setting/SettingsDialogSection.h \
    Theme/ThemeManager.h \
    Theme/Theme.h \
    Setting/Section/SettingThemeSection.h \
    Setting/Section/SettingFileAssociationSection.h \
    MenuBar.h \
    Setting/Section/ExtensionItem.h \
    Setting/Section/ExtensionDialog.h

SOURCES += \
    Plugin/PluginManager.cpp \
    MainWindow.cpp \
    CodeEditor.cpp \
    Workspace/Workspace.cpp \
    Workspace/Perspective.cpp \
    Plugin/PluginsDialog.cpp \
    Plugin/PluginItem.cpp \
    Plugin/PluginData.cpp \
    Editor/EditorManager.cpp \
    Editor/Editor.cpp \
    Setting/SettingManager.cpp \
    Setting/SettingsDialog.cpp \
    Setting/SettingsTreeItem.cpp \
    Setting/Section/SettingEditorsSection.cpp \
    Setting/Section/SettingGeneralSection.cpp \
    Setting/SettingsDialogSection.cpp \
    Theme/ThemeManager.cpp \
    Theme/Theme.cpp \
    Setting/Section/SettingThemeSection.cpp \
    Setting/Section/SettingFileAssociationSection.cpp \
    MenuBar.cpp \
    Setting/Section/ExtensionItem.cpp \
    Setting/Section/ExtensionDialog.cpp

DEFINES += CE_LIBRARY


FORMS += \
    ui/Plugin/PluginsDialog.ui \
    ui/Plugin/PluginItem.ui \
    ui/Setting/SettingsDialog.ui \
    ui/Setting/SettingEditorsSection.ui \
    ui/Setting/SettingGeneralSection.ui \
    ui/Setting/SettingThemeSection.ui \
    ui/Setting/SettingFileAssociationSection.ui \
    ui/Setting/SettingFileAssociationExtensionDialog.ui

CONFIG(debug, debug|release) {
    DESTDIR = ../lib/debug
    EXEC_DIR = ../bin/debug

} else {
    DESTDIR = ../lib/release
    EXEC_DIR = ../bin/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.rcc

win32 {
LIB_FILES += $$DESTDIR/CodeEditor.dll


## Define what files are 'extra_libs' and where to put them
extra_libs.files = $$LIB_FILES
extra_libs.path = $$DESTDIR

## Tell qmake to add the moving of them to the 'install' target
INSTALLS += extra_libs
}


data_files.files = ../data/*
data_files.path = $$EXEC_DIR/data

theme_files.files = ../themes/*
theme_files.path = $$EXEC_DIR/themes

## Tell qmake to add the moving of them to the 'install' target
INSTALLS += data_files theme_files

#unix {
#    CONFIG(debug, debug|release) {
#        LIB_FILES += ../lib/debug/libCore.so
#    } else {
#        LIB_FILES += ../lib/release/libCore.so
#    }
#}

## Define what files are 'extra_libs' and where to put them
#extra_libs.files = $$LIB_FILES
#extra_libs.path = $$DESTDIR

## Tell qmake to add the moving of them to the 'install' target
#INSTALLS += extra_libs

OTHER_FILES += \
    plugins.json \
    workspace.json
