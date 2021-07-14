/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "relance.h"
#include "relance-odb.hxx"

/**
 * Relance implementation
 */

Relance::Relance(){}
Relance::~Relance(){}

Relance::Relance(const QSharedPointer<Relancable>& relancee)
{
    setId(0);
    setDate();
    relancee_ = relancee;
}

void Relance::setId(unsigned long id)
{
    id_ = id ;
}

unsigned long Relance::getId() const{
    return id_;
}

void Relance::setDate()
{
    QDateTime date_time = QDateTime::currentDateTime();
    date_ = QDateTime(date_time.date() , QTime( date_time.time().hour(),  date_time.time().minute(), date_time.time().second()));
}

QDateTime Relance::getDate() const{
   return date_;
}

const QLazySharedPointer<Relancable>& Relance::getRelancee() const {
    return relancee_;
}
