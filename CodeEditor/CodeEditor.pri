INCLUDEPATH *= $$PWD/src
INCLUDEPATH += $$getUIDir($$PROJECT_PATH/build/CodeEditor/CodeEditor)

PRE_TARGETDEPS  *= $$PWD

LIBS += -L$$PROJECT_PATH/lib/$$buildMode() -l$$targetForMode("CodeEditor")

