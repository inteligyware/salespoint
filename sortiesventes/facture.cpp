/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#include "facture.h"
#include "facture-odb.hxx"

#include <QtCore/QUuid>

/**
 * Facture implementation
 */

Facture::Facture(){}
Facture::~Facture(){}

Facture::Facture(const QSharedPointer<Sortie>& sortie , const QString& reference){
    setSortie(sortie);
    setReference(reference);
}

void Facture::setReference(const QString& reference){
    if ( reference != "") reference_ = reference;
    else{
        //We remove the { } at the begining and end of th string
        QString tmp = QUuid::createUuid().toString().remove(0,1);
        reference_ = tmp.remove(tmp.length() - 1, 1).toUpper();
    }
}

quint32 Facture::getMontant() const{
    return sortie_.load()->getMontant();
}

const QLazyWeakPointer<Sortie>& Facture::getSortie() const{
    return sortie_;
}

void Facture::setSortie(const QSharedPointer<Sortie>& sortie){
    sortie_ = sortie;
}

const odb::vector<QLazyWeakPointer<Reglement>>&  Facture::getReglements() const{
    return reglements_;
}

void Facture::addReglement(const QSharedPointer<Reglement>& reglement){
    reglements_.push_back(reglement);
}

const QString Facture::getTitre() const{

    return QString("Facture N :");
}

const QString Facture::getReference() const{
    return reference_;
}
