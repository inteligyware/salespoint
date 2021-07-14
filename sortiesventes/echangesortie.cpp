/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "echangesortie.h"
#include "echangesortie-odb.hxx"
//#include "sortie-odb.hxx"

#include <iostream>

/**
 * EchangeSortie implementation
 */


EchangeSortie::EchangeSortie(){}
EchangeSortie::~EchangeSortie(){}

EchangeSortie::EchangeSortie(const SPPersonnel& respo,
                             const SPFournisseur &fournisseur,
                             float taux) : Sortie(respo)
{
    setFournisseur(fournisseur);
    setTauxInteret(taux);
}

float EchangeSortie::getTauxInteret() const
{
    return taux_;
}

void EchangeSortie::setTauxInteret(float taux)
{
    taux_ = taux;
}

const LSPFournisseur& EchangeSortie::getFournisseur() const
{
  return fournisseur_;
}

void EchangeSortie::setFournisseur(const SPFournisseur &fournisseur)
{
    fournisseur_ = fournisseur;
}

//Prevoir faire ce calcul en tenant compte taux
quint32 EchangeSortie::getMontant() const{
    quint32 montant = 0;
    foreach (auto det, details_)  montant += det->getMontant();
    return montant*getTauxInteret();
}
