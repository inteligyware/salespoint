/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#include "destockage.h"
#include "destockage-odb.hxx"
#include "sortie-odb.hxx"

#include <iostream>

/**
 * Destockage implementation
 */


Destockage::Destockage(){}
Destockage::~Destockage(){}

Destockage::Destockage(const SPPersonnel& responsable,
                       const QString& raison,
                       const QString& action) : Sortie(responsable)
{
    setRaison(raison);
    setAction(action);
}

const QString& Destockage::getRaison() const
{
    return raison_;
}

void Destockage::setRaison(const QString& raison)
{
    raison_ = raison.simplified().toUpper();
}

const QString& Destockage::getAction() const
{
    return action_;
}

void Destockage::setAction(const QString& action)
{
    action_ = action.simplified().toUpper();
}

quint32 Destockage::getMontant() const{
    quint32 montant = 0;
    foreach (auto i, details_){
       montant += i->getMontant();
    }
    return montant;
}
