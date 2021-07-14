#ifndef VUES_H
#define VUES_H

#include "produit.h"
#include "medicament.h"
#include "article.h"
#include "famille.h"

struct AViewMedicament{
    ulong id;
    QString libele;
    QString codebare;
    qreal prix_achat_moy;
    quint64 prix_vente;
    float remise;
    float qte_unitaire;
    QString CIP;
};

struct AViewArticle{
    ulong id;
    QString libele;
    QString codebare;
    qreal prix_achat_moy;
    quint64 prix_vente;
    float remise;
    float qte_unitaire;
    QString reference;
};

#endif // VUES_H
