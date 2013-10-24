# get current path
PROJECT_PATH = $$PWD
# helpers functions
include( $$PROJECT_PATH/functions.pri )

# package destdir
CONFIG(debug, debug|release) {
    PACKAGE_DESTDIR = $$PROJECT_PATH/bin/debug
} else {
    PACKAGE_DESTDIR = $$PROJECT_PATH/bin/release
}

# temporary path for building
PACKAGE_BUILD_PATH  = $$PROJECT_PATH/build/CodeEditor/$$BUILD_DIR
RAMDISK_PATH = /media/ramdisk

exists( $$RAMDISK_PATH ) {
    PACKAGE_BUILD_PATH  = $$RAMDISK_PATH/CodeEditor/$$BUILD_DIR
}

setTemporaryDirectories( $$PACKAGE_BUILD_PATH )


INCLUDEPATH *= $${UI_DIR} # some qmake versions has bug and do not do it automatically
# define config mode paths
CONFIG( debug, debug|release ) {
    message( Building in DEBUG for $${Q_TARGET_ARCH} )
    CONFIG  *= console
} else {
    message( Building in RELEASE for $${Q_TARGET_ARCH} )
}

CONFIG += object_parallel_to_source

# define some usefull values
QMAKE_TARGET_COMPANY    = "The Code Editor Team"
QMAKE_TARGET_PRODUCT    = "Code Editor"
QMAKE_TARGET_DESCRIPTION    = "Crossplatform Integrated Development Environment"
QMAKE_TARGET_COPYRIGHT  = "\\251 2005 - 2012 Fabien Metais and $$QMAKE_TARGET_COMPANY"
