PLUGINNAME = Project
BUILD_DIR = PluginProject
include (../../config.pri)
include (../Plugins.pri)
include (../../CodeEditor/CodeEditor.pri)

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += Plugin.cpp \
    ProjectManager.cpp \
    ProjectExplorer.cpp \
    NewProjectDialog.cpp \
    Project.cpp \
    ProjectTree/ProjectTreeModel.cpp \
    ProjectTree/ProjectTreeItem.cpp \
    ProjectTree/ProjectTreeView.cpp \
    ProjectExplorerDock.cpp
HEADERS += Plugin.h \
    ProjectManager.h \
    ProjectExplorer.h \
    NewProjectDialog.h \
    Project.h \
    ProjectTree/ProjectTreeModel.h \
    ProjectTree/ProjectTreeItem.h \
    ProjectTree/ProjectTreeView.h \
    ProjectExplorerDock.h

OTHER_FILES += \
    project.json \
    plugin.json

FORMS += \
    ui/NewProjectDialog.ui
