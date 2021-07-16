# ---------------------------------------------------------------
# Subdirectories relative to principal directory of salespoint: .

DISTFILES += AUTHORS \
             LICENSE \
             README.md

SUBDIRS +=  \
#            admin \
#            caisse \
#            commandes \
#            comptabilites \
#            fermeturecaisse \
#            inventaires \
#            rangements \
#             clients \
            personnels \
            produits \
            docsrelances \
            gui \
            sortiesventes \
            ipharma \
            inventaires
QMAKE_CXXFLAGS += -std=c++11
TEMPLATE =  subdirs
