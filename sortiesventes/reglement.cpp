/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "reglement.h"
#include "facture.h"

#include "reglement-odb.hxx"
#include "facture-odb.hxx"

/**
 * Reglement implementation
 */

Reglement::Reglement(){}
Reglement::~Reglement(){}

Reglement::Reglement(quint32 montant,
          const QSharedPointer<Facture>& facture)
{
    setDate();
    setMontant(montant);
    setFacture(facture);
}

void Reglement::setId( quint32 id){
    id_ = id;
}

quint32 Reglement::getId() const{
    return id_;
}

void Reglement::setMontant(quint32 montant)
{
    montant_ = montant;
}

quint32 Reglement::getMontant() const
{
    return montant_;
}

void Reglement::setDate()
{
    QDateTime date_time = QDateTime::currentDateTime();
    date_ = QDateTime(date_time.date() , QTime( date_time.time().hour(),  date_time.time().minute(), date_time.time().second()));

}

QDateTime Reglement::getDate() const {
    return date_;
}

void Reglement::setFacture(const QSharedPointer<Facture>& facture)
{
    facture_ = facture;
}

const QLazySharedPointer<Facture>& Reglement::getFacture() const
{
    return facture_;
}
