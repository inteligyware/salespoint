/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "inventory.h"
#include "inventory_item.h"

#include "inventory-odb.hxx"
#include "inventory_item-odb.hxx"
#include "produits/produit.h"

#include <iostream>

/**
 * Inventory implementation
 */

Inventory::Inventory(){}
Inventory::~Inventory(){}

Inventory::Inventory(const SPPersonnel &responsable){
    setId(0);
    setDateStared();
    setResponsable(responsable);
}

void Inventory::setId(ulong id){
    id_ = id;
}

ulong Inventory::getId(){
    return id_;
}

QDateTime Inventory::getDateStarted() const {
    return date_started_;
}

void Inventory::setDateStared(const QDateTime &date){
   date_started_ = date;
}

QDateTime Inventory::getDateEnded() const {
    return date_ended_;
}

void Inventory::setDateEnded(const QDateTime &date){
    date_ended_ = date;
}

const QString& Inventory::getReport() const{
    return report_;
}

void Inventory::setReport(const QString& report){
    report_ = report.simplified();
}

const SPPersonnel& Inventory::getResponsable() const{
    return responsable_;
}

void Inventory::setResponsable(const SPPersonnel &responsable){
    responsable_ = responsable;
}

const SPItem& Inventory::getItem(int pos) const{
    return items_.at(pos);
}

const SPItems& Inventory::getItems() const{
    return items_;
}

bool Inventory::removeItem(int pos){
    bool valid = (pos >= 0 && pos < items_.size());
        if ( valid ) items_.remove(pos);
    return valid;
}

void Inventory::addItem(const SPProduit& prod, ItemQty qtes){
    bool exist = false;
    foreach (auto item, items_)
        if ( item->getProduit()->getId() == prod->getId()){
            item->updateQuantities(qtes);
            exist = true ;
            break;
        }
    if ( !exist ){
       SPItem item (new InventoryItem(prod, qtes));
       items_.push_back(item);
       item->setInventory(sharedFromThis());
    }
}

bool Inventory::removeItems(const QList<int> *list){

    bool valid = ( list->at(0) >= 0 && list->at(list->size() -1) < items_.size());
    if( valid){
        QList<SPItem>* lwps = new QList<SPItem>;
        foreach(int pos , *list) lwps->append(items_[pos]);
        foreach (auto lwp, *lwps) items_.removeOne(lwp);
        delete lwps;
    }
    return valid;
}

int Inventory::indexOf(const SPProduit& prod){
    int index = -1;

    for (int i = 0 ; i != items_.size() ; i++)
        if ( items_[i]->getProduit()->getId() == prod->getId())
            index = i ;
    return index;
}

void Inventory::persist(SPODBDatabase db){
    db->persist(sharedFromThis());
    for(auto& item : items_) db->persist(item);
}
