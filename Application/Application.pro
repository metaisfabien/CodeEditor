TEMPLATE = app
TARGET = "PHPEditor"
QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = "PHPEditor"

# Input
SOURCES += main.cpp \
    Application.cpp

HEADERS += \
    Application.h


CONFIG(debug, debug|release) {
    DESTDIR = ../bin/debug
    OBJECTS_DIR = ../bin/debug/.obj
    MOC_DIR = ../bin/debug/.moc
    RCC_DIR = ../bin/debug/.rcc
    UI_DIR = ../bin/debug/.ui
} else {
    DESTDIR = ../bin/release
    OBJECTS_DIR = ../bin/release/.obj
    MOC_DIR = ../bin/release/.moc
    RCC_DIR = ../bin/release/.rcc
    UI_DIR = ../bin/debug/.ui
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug -lCore
else:unix:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release -lCore
else:unix:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug -lCore

INCLUDEPATH += $$PWD/../Core
DEPENDPATH += $$PWD/../Core
