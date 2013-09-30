#-------------------------------------------------
#
# Project created by QtCreator 2013-09-14T18:46:55
#
#-------------------------------------------------

TEMPLATE = lib
CONFIG   += plugin
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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

CONFIG(debug, debug|release) {
    DESTDIR = ../../bin/debug/plugins/PHPProject
    OBJECTS_DIR = ../../bin/debug/plugins/PHPProject/.obj
    MOC_DIR = ../../bin/debug/plugins/PHPProject/.moc
    RCC_DIR = ../../bin/debug/plugins/PHPProject/.rcc
    UI_DIR = ../../bin/debug/plugins/PHPProject/.ui
} else {
    DESTDIR = ../../bin/release/plugins/PHPProject
    OBJECTS_DIR = ../../bin/release/plugins/PHPProject/.obj
    MOC_DIR = ../../bin/release/plugins/PHPProject/.moc
    RCC_DIR = ../../bin/release/plugins/PHPProject/.rcc
    UI_DIR = ../../bin/release/plugins/PHPProject/.ui
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/debug/ -lCore
else:unix:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/release -lCore
else:unix:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/debug -lCore

INCLUDEPATH += $$PWD/../../Core
DEPENDPATH += $$PWD/../../Core

install_files.files = plugin.json
install_files.path = $$DESTDIR

## Tell qmake to add the moving of them to the 'install' target
INSTALLS += install_files
