TEMPLATE = app
TARGET = "CodeEditor"
QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = "PHPEditor"

# Input
SOURCES += main.cpp \
    Application.cpp \
    LogBrowserDialog.cpp \
    LogBrowser.cpp

HEADERS += \
    Application.h \
    LogBrowserDialog.h \
    LogBrowser.h


CONFIG(debug, debug|release) {
    DESTDIR = ../bin/debug
} else {
    DESTDIR = ../bin/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.rcc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release -lCodeEditor
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug -lCodeEditor
else:unix:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release -lCodeEditor
else:unix:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug -lCodeEditor

INCLUDEPATH += $$PWD/../CodeEditor
DEPENDPATH += $$PWD/../CodeEditor
