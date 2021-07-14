/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _DETAILSSORTIE_H
#define _DETAILSSORTIE_H

#include "sortie.h"

#include <QtCore/QSharedPointer>
#include <odb/qt/lazy-ptr.hxx>

class Produit;

using LWPSortie = QLazyWeakPointer<Sortie>;
using SPSortie = QSharedPointer<Sortie>;
class DetailsSortie {

private:
    quint64 id_;
    quint32 qte_{1};
    quint32 prix_unitaire_;
    float remise_{0};
    SPProduit produit_;
    LWPSortie sortie_;

    friend class odb::access;
    friend void Sortie::addDetails(const SPProduit& , quint32);

    DetailsSortie();
    DetailsSortie(SPProduit produit , quint32 qte = 1);
    void setId(quint64 id);
    void setProduit(const SPProduit& produit);

public: 
    virtual ~DetailsSortie();

    quint64 getId() const;

    quint32 getQte() const;
    void setQte(quint32 qte);

    quint32 getPrixUnitaire() const;
    void setPrixUnitaire(quint32 prix_unitaite);
    bool negocierPrix(quint32 prixpropose);

    float getRemise() const;
    void setRemise(float remise);

    quint64 getMontant() const;
      
    const SPProduit& getProduit() const;

    void setSortie(const QSharedPointer<Sortie>& sortie);
    const LWPSortie& getSortie() const;
};

#endif //_DETAILSSORTIE_H
