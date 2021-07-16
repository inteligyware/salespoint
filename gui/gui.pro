#-------------------------------------------------
#
# Project created by QtCreator 2018-02-27T23:04:31
#
#-------------------------------------------------

QT     += widgets sql
TARGET = gui
TEMPLATE = lib

DEFINES += GUI_LIBRARY

SOURCES += \
    sortiemodel.cpp \
    listingdialog.cpp \
    salesdialog.cpp \
    salesmodel.cpp \
    attentemodel.cpp \
    numberdelegate.cpp \
    toolkit.cpp \
    mainwindow.cpp \
    listingmodel.cpp \
    abstractodbmodel.cpp \
    odbproductmodel.cpp \
    reportingdialog.cpp \
    tabdialog.cpp \
    saleslistingmodel.cpp \
    datafetcherthread.cpp \
    productfamily.cpp \
    productcreationform.cpp \
    productlistingdialog.cpp \
    uniqueproxymodel.cpp \
    qproductmodel.cpp \
    familycreationform.cpp \
    familylistingdialog.cpp \
    datefilterproxymodel.cpp \
    retailableproductproxymodel.cpp \
    odbfamilymodel.cpp
#    cashdeskclosure.cpp \
#    sessionmanager.cpp \
#    inventorydialog.cpp \
#    inventorymodel.cpp

HEADERS +=\
    models.h \
    views.h \
    salesdialog.h \
    delegates.h \
    toolkit.h \
    mainwindow.h \
    reportingdialog.h \
    tabdialog.h \
    familycreationform.h \
    datafetcherthread.h \
    productfamily.h \
    productcreationform.h

#    ui_salesdialog.h \
#    ui_reportingdialog.h \
#    ui_productcreationform.h \
#    ui_familycreationform.h \
#    ui_tabdialog.h \
#    ui_mainwindow.h \
#    ui_sessionmanager.h \
#    sessionmanager.h \
#    cashdeskclosure.h \
#    inventorydialog.h

RESOURCES += resources.qrc mainwindow.qrc

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
    -L"../docsrelances" -ldocsrelances

QMAKE_CXXFLAGS += -std=c++11

# Suppress unknown pragmas GCC warnings.
QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas -Wno-deprecated-declarations


unix {
    target.path = /usr/local/salespoint/lib
    INSTALLS += target
}

FORMS +=\
    salesdialog.ui \
    mainwindow.ui \
    tabdialog.ui \
    products/productcreation.ui \
    productcreationform.ui \
    groupedproductcreationform.ui \
    familycreationform.ui

#    reportingdialog.ui \
#    inventorydialog.ui
#    sessionmanager.ui \
#    cashdeskclosure.ui \
#    advancedsalesdialog.ui
#    cashdialog.ui
