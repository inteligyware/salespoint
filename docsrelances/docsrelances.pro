#-------------------------------------------------
#
# Project created by QtCreator 2017-02-02T09:56:37
#
#-------------------------------------------------

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = docsrelances
TEMPLATE = lib
VERSION = 0.1
DEFINES += DOCSRELANCES_LIBRARY

SOURCES +=\
    document.cpp \
    relancable.cpp \
    relance.cpp

HEADERS +=\
    document.h \
    relancable.h \
    relance.h

unix {
    target.path = /usr/local/salespoint/lib
    INSTALLS += target
}

##ODB parameters starts here

# List of header files that should be compiled with the ODB compiler.
#
ODB_FILES +=\
    document.hxx \
    relancable.hxx \
    relance.hxx

# ODB compiler flags.
#
ODB_FLAGS =\
     -x -fPIC -x --std=c++11 \
    --database pgsql \
    --sql-name-case lower \
    --profile qt \
    --hxx-prologue-file "../default_ptr.hxx" \
    --generate-query \
    --generate-session

QMAKE_CXXFLAGS += -std=c++11
# Suppress unknown pragmas GCC warnings.

QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas -Wno-deprecated-declarations

# Link to the ODB runtime libraries.
#
#LIBS += -lodb-pgsql
#LIBS += -lodb-qt
#LIBS += -lodb

# ODB compilation rules. Normally you don't need to change anything here.
#

# Add the Qt headers directory to the ODB include directory list.
#
ODB_FLAGS += -I$$[QT_INSTALL_HEADERS]

# Newer versions of QtCreator do builds in a separate directory. As a
# result, we need to append the source directory to ODB files.
#
for(dir, ODB_FILES) {
  ODB_PWD_FILES += $$PWD/$${dir}
}

odb.name = odb ${QMAKE_FILE_IN}
odb.input = ODB_PWD_FILES
odb.output = ${QMAKE_FILE_BASE}-odb.cxx
odb.commands = odb $$ODB_FLAGS ${QMAKE_FILE_IN}
odb.depends = $$ODB_PWD_FILES
odb.variable_out = SOURCES
odb.clean = ${QMAKE_FILE_BASE}-odb.cxx ${QMAKE_FILE_BASE}-odb.hxx ${QMAKE_FILE_BASE}-odb.ixx ${QMAKE_FILE_BASE}.sql
QMAKE_EXTRA_COMPILERS += odb


odbh.name = odb ${QMAKE_FILE_IN}
odbh.input = ODB_PWD_FILES
odbh.output = ${QMAKE_FILE_BASE}-odb.hxx
odbh.commands = @true
odbh.CONFIG = no_link
odbh.depends = ${QMAKE_FILE_BASE}-odb.cxx
QMAKE_EXTRA_COMPILERS += odbh

odbi.name = odb ${QMAKE_FILE_IN}
odbi.input = ODB_PWD_FILES
odbi.output = ${QMAKE_FILE_BASE}-odb.ixx
odbi.commands = @true
odbi.CONFIG = no_link
odbi.depends = ${QMAKE_FILE_BASE}-odb.cxx
QMAKE_EXTRA_COMPILERS += odbi
