/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#include "produit.h"
#include "produit-odb.hxx"
#include "fournisseur.h"
#include "fournisseur-odb.hxx"

#include "prixfourn.h"
#include "prixfourn.hxx"
#include "prixfourn-odb.hxx"

#include "../ise_exception.h"

#include <QtCore/QString>
#include <QtCore/QDate>
#include <QtCore/QSharedPointer>
#include <QtCore/QEnableSharedFromThis>
#include <iostream>

//#include "PrixFourn-odb.hxx" // types and functions for database persistence mechanism

/**
 * PrixFourn implementation
 */

PrixFourn::PrixFourn(){}

PrixFourn::PrixFourn(SPProduit produit,
                     SPFournisseur fournisseur,
                     qreal prix,
                     QDate date
                     )
{

    setProduit(produit);
    setFournisseur(fournisseur);
    setPrix(prix);
    setDate_effet(date);
}


PrixFourn::PrixFourn(qreal prix,QDate date)
{
    setPrix(prix);
    setDate_effet(date);
}



PrixFourn::~PrixFourn(){}

void PrixFourn::bindProdFourn(SPProduit produit, SPFournisseur fournisseur)
{
    //if(produit_ || fournisseur_) throw double_price_assignement_exception();
    if(produit_ || fournisseur_) throw ise_adv_exception<Produit>("double_price_assignement_exception" , produit);
    setProduit(produit);
    setFournisseur(fournisseur);
    produit->setPrixfourns(sharedFromThis());
    fournisseur->setPrixfourns(sharedFromThis());
}

void PrixFourn::setId(ulong id)
{
    id_ = id;
}

ulong PrixFourn::getId() const
{
    return id_ ;
}

void PrixFourn::setPrix(qreal prix)
{
    if( prix <= 0 ) throw null_or_negative_price_exception();
    prix_ = prix ;
}

qreal PrixFourn::getPrix() const
{
    return prix_ ;
}


void PrixFourn::setDate_effet(const QDate& date)
{
    date_effet_ = date;
}

QDate PrixFourn::getDate_effet() const
{
    return date_effet_ ;
}

void PrixFourn::setProduit(const SPProduit& produit)
{
    produit_ = produit;
}

const SPProduit &PrixFourn::getProduit() const
{
    return produit_;
}

void PrixFourn::setFournisseur(const SPFournisseur& fournisseur)
{
    fournisseur_ = fournisseur;
}

const SPFournisseur& PrixFourn::getFournisseur() const
{
    return fournisseur_;
}
