#-------------------------------------------------
#
# Project created by QtCreator 2017-01-17T10:57:05
#
#-------------------------------------------------

QT       -= gui
TARGET   = produits
VERSION = 0.1
TEMPLATE = lib
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5 \
               /usr/include/x86_64-linux-gnu/qt5/QtCore

DEFINES += PRODUITS_LIBRARY

SOURCES += \
    fournisseur.cpp \
    medicament.cpp \
    produit.cpp \
    tonnage.cpp \
    histprix.cpp \
    prixfourn.cpp \
    article.cpp \
    emballage.cpp \
    famille.cpp

HEADERS += \
    emballage.h \
    fournisseur.h \
    medicament.h \
    produit.h \
    tonnage.h \
    types.h \
    histprix.h \
    prixfourn.h \
    article.h \
    famille.h
#    vues.h

unix {
    target.path = /usr/local/salespoint/lib
    INSTALLS += target
}

##ODB parameters starts here

# List of header files that should be compiled with the ODB compiler.
ODB_FILES += \
    produit.hxx \
    emballage.hxx \
    tonnage.hxx \
    fournisseur.hxx \
    prixfourn.hxx \
    medicament.hxx \
    histprix.hxx \
    article.hxx \
    famille.hxx
#    vues.hxx

HEADERS += $$ODB_FILES

# ODB compiler flags.
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
ODB_FLAGS += -I$$[QT_INSTALL_HEADERS]

# Newer versions of QtCreator do builds in a separate directory. As a
# result, we need to append the source directory to ODB files.
#

for(file, ODB_FILES) {
  ODB_PWD_FILES += $$PWD/$${file}
}

odb.name = odb ${QMAKE_FILE_IN}
odb.input = ODB_PWD_FILES
odb.output = ${QMAKE_FILE_BASE}-odb.cxx
odb.commands = odb $$ODB_FLAGS ${QMAKE_FILE_IN}
odb.depends = $$ODB_PWD_FILES
odb.variable_out = SOURCES
odb.clean = ${QMAKE_FILE_BASE}-odb.cxx ${QMAKE_FILE_BASE}-odb.hxx ${QMAKE_FILE_BASE}-odb.ixx ${QMAKE_FILE_BASE}.sql ${QMAKE_FILE_BASE}.xml
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
