# ---------------------------------------------------------------
# Subdirectories relative to principal directory of salespoint: .

DISTFILES += AUTHORS \
             LICENSE \
             README.md

#sub projects
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

ipharma.depends = gui sortiesventes produits docsrelances personnels inventaires
gui.depends = sortiesventes produits docsrelances personnels inventaires
sortiesventes.depends =  produits personnels docsrelances
inventaires.depends = produits personnels

TEMPLATE =  subdirs
