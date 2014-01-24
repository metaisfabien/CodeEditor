# include config file
include( ../config.pri )


TARGET = $$targetForMode("CTags")
TEMPLATE    = lib
CONFIG  *= staticlib
CONFIG  -= qt

DESTDIR = $$PROJECT_PATH/lib/$$buildMode()

DEFINES *= HAVE_REGCOMP
win32:DEFINES   *= WIN32 REGEX_MALLOC STDC_HEADERS=1 __USE_GNU HAVE_STDBOOL_H
unix:DEFINES    *= HAVE_STDLIB_H \
    HAVE_FGETPOS \
    HAVE_SYS_STAT_H \
    HAVE_FCNTL_H \
    HAVE_REGEX \
    HAVE_UNISTD_H \
    HAVE_STRSTR


INCLUDEPATH *= src

HEADERS *= \
    src/debug.h \
    src/entry.h \
    src/general.h \
    src/get.h \
    src/keyword.h \
    src/options.h \
    src/parse.h \
    src/read.h \
    src/routines.h \
    src/strlist.h \
    src/vstring.h \
    src/readtags.h \
    src/sort.h \
    src/args.h \
    src/ctags.h \
    src/exuberantCtags.h \

SOURCES *= \
src/asm.c \
    src/asp.c \
    src/awk.c \
    src/basic.c \
    src/beta.c \
    src/c.c \
    src/cobol.c \
    src/eiffel.c \
    #   src/debug.c \
    src/entry.c \
    src/erlang.c \
    src/fortran.c \
    src/get.c \
    src/html.c \
    src/jscript.c \
    src/keyword.c \
    src/lisp.c \
    src/lregex.c \
    src/lua.c \
    src/make.c \
    src/options.c \
    src/parse.c \
    src/pascal.c \
    src/perl.c \
    src/php.c \
    src/python.c \
    src/read.c \
    src/rexx.c \
    src/routines.c \
    src/ruby.c \
    src/scheme.c \
    src/sh.c \
    src/slang.c \
    src/sml.c \
    src/sql.c \
    src/strlist.c \
    src/tcl.c \
    src/verilog.c \
    src/vim.c \
    src/vstring.c \
    src/yacc.c \
    src/tex.c \
    src/flex.c \
    src/vhdl.c \
    src/matlab.c \
    src/ant.c \
    src/ocaml.c \
    src/dosbatch.c \
    src/exuberantCtags.c \

OTHER_FILES +=

