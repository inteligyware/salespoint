QT       += core network gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = salespointi7
CONFIG -= app_bundle
TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH +=\
    ../produits \
    ../personnels \
    ../sortiesventes \
    ../docsrelances \
    .. \
    .

LIBS +=\
    -L"../produits" -lproduits \
    -L"../personnels" -lpersonnels \
    -L"../sortiesventes" -lventes \
    -L"../docsrelances" -ldocsrelances \
    -L"../gui" -lgui

LIBS += -lodb-pgsql
LIBS += -lodb-qt
LIBS += -lodb

QMAKE_CXXFLAGS += -std=c++11 -pedantic-errors -Wall

# Suppress unknown pragmas GCC warnings.
QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas -Wno-deprecated-declarations -Wno-potentially-evaluated-expression
