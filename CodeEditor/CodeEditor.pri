INCLUDEPATH *= $$PWD/src
INCLUDEPATH += $$getUIDir($$PROJECT_PATH/build/CodeEditor/CodeEditor)

PRE_TARGETDEPS  *= $$PWD

win32:CONFIG(release, debug|release): LIBS += -L$$PROJECT_PATH/lib/release -l$$targetForMode("CodeEditor")
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PROJECT_PATH/lib/debug -l$$targetForMode("CodeEditor")
else:unix:CONFIG(release, debug|release): LIBS += -L$$PROJECT_PATH/lib/release -l$$targetForMode("CodeEditor")
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PROJECT_PATH/lib/debug -l$$targetForMode("CodeEditor")


