/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _PRIXFOURN_H
#define _PRIXFOURN_H

#include <QtCore/QString>
#include <QtCore/QDate>
#include <QtCore/QSharedPointer>

#include <odb/vector.hxx>
#include <odb/qt/lazy-ptr.hxx>
#include "types.h"

class Produit;
class Fournisseur;

class PrixFourn : public QEnableSharedFromThis<PrixFourn>{
private:

    ulong id_;
    qreal prix_;
    QDate date_effet_;

    SPProduit produit_;
    SPFournisseur fournisseur_;

    friend class odb::access;
    PrixFourn();
    void setId(ulong id);
    void setProduit(const SPProduit& produit);
    void setFournisseur(const SPFournisseur& fournisseur);

public:

    PrixFourn( qreal prix, QDate date = QDate::currentDate());
    PrixFourn( SPProduit produit,
               SPFournisseur fournisseur,
               qreal prix,
               QDate date = QDate::currentDate()
              );
           
    virtual ~PrixFourn();
    
    void bindProdFourn (SPProduit produit, SPFournisseur fournisseur);
    
    ulong getId() const;

    void setPrix(qreal prix);
    qreal getPrix() const;

    void setDate_effet(const QDate& date);
    QDate getDate_effet() const;

    const SPProduit& getProduit() const;

    const SPFournisseur& getFournisseur() const;
};

#endif //_PRIXFOURN_H
