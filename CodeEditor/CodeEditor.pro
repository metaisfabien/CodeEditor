BUILD_DIR = CodeEditor

# include config file
include( ../config.pri )

TARGET = $$targetForMode("CodeEditor")
TEMPLATE = lib


CONFIG(debug, debug|release) {
    DESTDIR = $$PROJECT_PATH/lib/debug
} else {
    DESTDIR = $$PROJECT_PATH/lib/release
}

DEFINES += CE_LIBRARY


LIBS+= -L$$[QT_INSTALL_LIBS] -lqscintilla2

INCLUDEPATH *= src
INCLUDEPATH += $$PROJECT_PATH/dependencies/QScintilla/Qt4Qt5


QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    src/Plugin/PluginManager.h \
    src/Plugin/PluginInterface.h \
    src/MainWindow.h \
    src/Export.h \
    src/CodeEditor.h \
    src/Workspace/Workspace.h \
    src/Workspace/Perspective.h \
    src/Plugin/PluginsDialog.h \
    src/Plugin/PluginItem.h \
    src/Plugin/PluginData.h \
    src/Editor/EditorManager.h \
    src/Editor/Editor.h \
    src/Theme/ThemeManager.h \
    src/Theme/Theme.h \
    src/Setting/SettingManager.h \
    src/Setting/SettingsDialog.h \
    src/Setting/SettingsTreeItem.h\
    src/Setting/SettingsDialogSection.h \
    src/Setting/Section/FileAssociation/ExtensionItem.h \
    src/Setting/Section/FileAssociation/ExtensionDialog.h \
    src/Setting/Section/Editors.h \
    src/Setting/Section/FileAssociation.h \
    src/Setting/Section/General.h \
    src/Setting/Section/Theme.h \
    src/Dock/Dock.h \
    src/Dock/DockManager.h \
    src/Workspace/PerspectiveDock.h \
    src/Menu/Menu.h \
    src/Menu/MenuBar.h \
    src/Action/Manager.h \
    src/Widget/TabBar.h \
    src/Widget/TabWidget.h

SOURCES += \
    src/Plugin/PluginManager.cpp \
    src/MainWindow.cpp \
    src/CodeEditor.cpp \
    src/Workspace/Workspace.cpp \
    src/Workspace/Perspective.cpp \
    src/Plugin/PluginsDialog.cpp \
    src/Plugin/PluginItem.cpp \
    src/Plugin/PluginData.cpp \
    src/Editor/EditorManager.cpp \
    src/Editor/Editor.cpp \
    src/Theme/ThemeManager.cpp \
    src/Setting/SettingManager.cpp \
    src/Setting/SettingsDialog.cpp \
    src/Setting/SettingsTreeItem.cpp \
    src/Setting/SettingsDialogSection.cpp \
    src/Setting/Section/FileAssociation/ExtensionItem.cpp \
    src/Setting/Section/FileAssociation/ExtensionDialog.cpp \
    src/Setting/Section/Editors.cpp \
    src/Setting/Section/FileAssociation.cpp \
    src/Setting/Section/General.cpp \
    src/Setting/Section/Theme.cpp \
    src/Theme/Theme.cpp \
    src/Dock/DockManager.cpp \
    src/Dock/Dock.cpp \
    src/Workspace/PerspectiveDock.cpp \
    src/Menu/Menu.cpp \
    src/Menu/MenuBar.cpp \
    src/Action/Manager.cpp \
    src/Widget/TabBar.cpp \
    src/Widget/TabWidget.cpp

FORMS += \
    ui/Plugin/PluginsDialog.ui \
    ui/Plugin/PluginItem.ui \
    ui/Setting/SettingsDialog.ui \
    ui/Setting/SettingEditorsSection.ui \
    ui/Setting/SettingGeneralSection.ui \
    ui/Setting/SettingThemeSection.ui \
    ui/Setting/SettingFileAssociationSection.ui \
    ui/Setting/SettingFileAssociationExtensionDialog.ui

win32 {
LIB_FILES += $$DESTDIR/CodeEditor.dll

## Define what files are 'extra_libs' and where to put them
extra_libs.files = $$LIB_FILES
extra_libs.path = $$DESTDIR

## Tell qmake to add the moving of them to the 'install' target
INSTALLS += extra_libs
}


data_files.files = $$PWD/data/*
data_files.path = $$PACKAGE_DESTDIR/data

theme_files.files = $$PWD/themes/*
theme_files.path = $$PACKAGE_DESTDIR/themes

icons_files.files = $$PWD/icons/*
icons_files.path = $$PACKAGE_DESTDIR/icons

## Tell qmake to add the moving of them to the 'install' target
INSTALLS += data_files theme_files icons_files



OTHER_FILES += \
    plugins.json \
    workspace.json
