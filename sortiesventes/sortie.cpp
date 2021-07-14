/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "sortie.h"
//#include "detailssortie.h"
#include "facture.h"

#include "sortie-odb.hxx"
//#include "detailssortie-odb.hxx"
#include "facture-odb.hxx"

#include <iostream>

/**
 * Sortie implementation
 */

Sortie::Sortie(){}
Sortie::~Sortie(){}

Sortie::Sortie(const SPPersonnel &responsable){
    setId(0);
    setDate();
    setResponsable(responsable);
}

void Sortie::setId(ulong id){
    id_ = id;
}

ulong Sortie::getId(){
    return id_;
}

QDateTime Sortie::getDate() const {
    return date_;
}

void Sortie::setDate(const QDateTime &date)
{
    //QDateTime date_time = QDateTime::currentDateTime();
    //date_ = QDateTime(date_time.date() , QTime( date_time.time().hour(),  date_time.time().minute(), date_time.time().second()));
    date_ = date;
}

const SPPersonnel& Sortie::getResponsable() const{
    return responsable_;
}

void Sortie::setResponsable(const SPPersonnel &responsable){
    responsable_ = responsable;
}

const SPFacture& Sortie::getFacture() const{
    return facture_;
}

void Sortie::setFacture(const SPFacture &facture){
    facture_ = facture;
}

const SPDetailsSortie& Sortie::getDetails(int pos) const{
    return details_.at(pos);
}

const SPDetails& Sortie::getDetails() const{
    return details_;
}

bool Sortie::removeDetail(int pos){
    bool valid = (pos >= 0 && pos < details_.size());
        if ( valid ) details_.remove(pos);
    return valid;
}

void Sortie::addDetails(const SPProduit& prod , quint32 qte ){
    bool exist = false;
    foreach (auto detail, details_)
        if ( detail->getProduit()->getId() == prod->getId() )
        {
            quint32 new_qte = detail->getQte() + qte;

            cout << " Doublon " << detail->getProduit()->getId() << " - " \
                 << prod->getLibele().toStdString() << " " \
                 << " Old qte " << detail->getQte() << " New qte " << new_qte << endl;
            cout << "*********************************************************"  << endl;
            detail->setQte( new_qte );
            exist = true ;
            break;
        }
        if ( !exist )
        {
           SPDetailsSortie new_detail (new DetailsSortie(prod , qte));
           details_.push_back(new_detail);
           new_detail->setSortie(sharedFromThis());
        }
}

bool Sortie::removeDetails(const QList<int> *list){

    bool valid = ( list->at(0) >= 0 && list->at(list->size() -1) < details_.size());
    if( valid){
        QList<SPDetailsSortie>* lwps = new QList<SPDetailsSortie>;
        foreach(int pos , *list) lwps->append(details_[pos]);
        foreach (auto lwp, *lwps) details_.removeOne(lwp);
        delete lwps;
    }
    return valid;
}

int Sortie::indexOf(const SPProduit& prod){
    int index = -1;

    for (int i = 0 ; i != details_.size() ; i++)
        if ( details_[i]->getProduit()->getId() == prod->getId())
            index = i ;
    return index;
}

void Sortie::persist(SPODBDatabase db){
    SPFacture spfacture (new Facture(sharedFromThis()));
    sharedFromThis()->setFacture(spfacture);
    db->persist(spfacture);
    db->persist(sharedFromThis());
    for(auto& detail : details_) db->persist(detail);
}
