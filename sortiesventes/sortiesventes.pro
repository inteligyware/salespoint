#-------------------------------------------------
#
# Project created by QtCreator 2017-02-13T18:13:56
#
#-------------------------------------------------

QT       -= gui

TARGET = ventes
TEMPLATE = lib
VERSION = 0.1
DEFINES += SORTIESVENTES_LIBRARY

SOURCES +=\
    destockage.cpp \
    detailssortie.cpp \
    echangesortie.cpp \
    facture.cpp \
    reglement.cpp \
    sortie.cpp
#    fichesortie.cpp \
#    vente.cpp \
#    modereglement.cpp \
#    cash.cpp \
#    carte.cpp \
#   mobilemoney.cpp \
#   orangeemoney.cpp

HEADERS +=\
    sortie.h \
    reglement.h \
    facture.h \
    echangesortie.h \
    detailssortie.h \
    destockage.h

#    vente.h \


unix {
    target.path = /usr/local/salespoint/lib
    INSTALLS += target
}

INCLUDEPATH +=\
    ../produits \
    ../personnels \
    ../docsrelances \
    .. \
    .

LIBS +=\
#    -L"../produits" -lproduits \
#    -L"../personnels" -lpersonnels \
    -L"../docsrelances" -ldocsrelances

ODB_FILES +=\
    facture.hxx \
    detailssortie.hxx \
    reglement.hxx \
    sortie.hxx \
    echangesortie.hxx \
    destockage.hxx

HEADERS += $$ODB_FILES

# ODB compiler flags.

ODB_FLAGS =\
     -x -fPIC -x --std=c++11 \
    --database pgsql \
    --sql-name-case lower \
    --profile qt \
    --hxx-prologue-file "../default_ptr.hxx" \
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
for(file, ODB_FILES) {
  ODB_PWD_FILES += $$PWD/$${file}
}

odb.name = odb ${QMAKE_FILE_NAME}
odb.input = ODB_PWD_FILES
odb.output = ${QMAKE_FILE_BASE}-odb.cxx
odb.commands = odb $$ODB_FLAGS ${QMAKE_FILE_NAME}
odb.depends = $$ODB_PWD_FILES
odb.variable_out = SOURCES
odb.clean = ${QMAKE_FILE_BASE}-odb.cxx ${QMAKE_FILE_BASE}-odb.hxx ${QMAKE_FILE_BASE}-odb.ixx ${QMAKE_FILE_BASE}.sql
QMAKE_EXTRA_COMPILERS += odb

odbh.name = odb ${QMAKE_FILE_NAME}
odbh.input = ODB_PWD_FILES
odbh.output = ${QMAKE_FILE_BASE}-odb.hxx
odbh.commands = odb $$ODB_FLAGS ${QMAKE_FILE_NAME}
odbh.CONFIG = no_link
odbh.depends = ${QMAKE_FILE_BASE}.cpp
QMAKE_EXTRA_COMPILERS += odbh

odbi.name = odb ${QMAKE_FILE_IN}
odbi.input = ODB_PWD_FILES
odbi.output = ${QMAKE_FILE_BASE}-odb.ixx
odbi.commands = @true
odbi.CONFIG = no_link
odbi.depends = ${QMAKE_FILE_BASE}-odb.cxx
QMAKE_EXTRA_COMPILERS += odbi
