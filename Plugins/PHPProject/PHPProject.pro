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

Release:DESTDIR = ../../bin/release/plugins/PHPProject
Release:OBJECTS_DIR = ../../bin/release/tmp_build/plugins/PHPProject/.obj
Release:MOC_DIR = ../../bin/release/tmp_build/plugins/PHPProject/.moc
Release:RCC_DIR = ../../bin/release/tmp_build/plugins/PHPProject/.rcc
Release:UI_DIR = ../../bin/release/tmp_build/plugins/PHPProject/.ui

Debug:DESTDIR = ../../bin/debug/plugins/PHPProject
Debug:OBJECTS_DIR = ../../bin/debug/tmp_build/plugins/PHPProject/.obj
Debug:MOC_DIR = ../../bin/debug/tmp_build/plugins/PHPProject/.moc
Debug:RCC_DIR = ../../bin/debug/tmp_build/plugins/PHPProject/.rcc
Debug:UI_DIR = ../../bin/debug/tmp_build/plugins/PHPProject/.ui

SOURCES += PHPProject.cpp \
    ProjectManager.cpp \
    ProjectExplorer.cpp \
    NewProjectDialog.cpp \
    Project.cpp \
    ProjectTreeModel.cpp \
    ProjectTreeItem.cpp
HEADERS += PHPProject.h \
    ProjectManager.h \
    ProjectExplorer.h \
    NewProjectDialog.h \
    Project.h \
    ProjectTreeModel.h \
    ProjectTreeItem.h
EXAMPLE_FILES = php_project.json
OTHER_FILES += \
    php_project.json \
    plugin.json

FORMS += \
    NewProjectDialog.ui

install_files.files = plugin.json
install_files.path = $$DESTDIR

## Tell qmake to add the moving of them to the 'install' target
INSTALLS += install_files

