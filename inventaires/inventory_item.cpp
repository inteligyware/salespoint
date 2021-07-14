/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "inventory_item.h"
#include "inventory_item-odb.hxx"
#include "../produits/produit.h"

/**
 * InventoryItem implementation
 */

InventoryItem::InventoryItem(){}
InventoryItem::~InventoryItem(){}

InventoryItem::InventoryItem(SPProduit produit , ItemQty qtes){
    setProduit(produit);
    produit->desactivate();
    updateQuantities(qtes);
}

void InventoryItem::setId(quint64 id){
    id_ = id;
}

const SPProduit& InventoryItem::getProduit() const{
    return produit_;
}

void InventoryItem::setInventory(const SPInventory& inventory){
    inventory_ = inventory;
}

SPInventory InventoryItem::getInventory() const{
    return inventory_.load();
}

void InventoryItem::setProduit(const SPProduit& produit){
    produit_ = produit;
    qte_theo_gros_ = produit->getQteGros();
    qte_theo_details_ = produit->getQteDetails();
}

ulong InventoryItem::getId() const{
    return id_;
}

quint32 InventoryItem::getQtePhysGros() const{
    return qte_phys_gros_;
}

void InventoryItem::setQtePhysGros(quint32 qte){
    qte_phys_gros_ = qte;
}

quint32 InventoryItem::getQtePhysDetails() const{
    return qte_phys_details_;
}

void InventoryItem::setQtePhysDetails(quint32 qte){
    qte_phys_details_ = qte;
}

quint32 InventoryItem::getQteAjouteGros() const{
    return qte_ajoute_gros_;
}

void InventoryItem::setQteAjouteGros(quint32 qte){
        qte_ajoute_gros_ = qte;
}

quint32 InventoryItem::getQteAjouteDetails() const {
     return qte_ajoute_details_;
}

void InventoryItem::setQteAjouteDetails(quint32 qte){
    if(produit_->isRetailable() && produit_->getQteColise() > qte)
        qte_ajoute_details_ = qte;
}

quint32 InventoryItem::getQteTheoGros() const{
    return qte_theo_gros_;
}

void InventoryItem::setQteTheoGros(quint32 qte){
    qte_theo_gros_ = qte;
}

quint32 InventoryItem::getQteTheoDetails() const{
    return qte_theo_details_;
}

void InventoryItem::setQteTheoDetails(quint32 qte){
    qte_theo_details_ = qte;
}

void InventoryItem::updateQuantities(ItemQty qtes){
       qte_phys_gros_   = qtes.qte_phys_gros_ ;
       qte_ajoute_gros_ = qtes.qte_ajoute_gros_ ;

       if(produit_->isRetailable()){

            if( produit_->getQteColise() > qtes.qte_phys_details_)
                qte_phys_details_ = qtes.qte_phys_details_;

            if( produit_->getQteColise() > qtes.qte_ajoute_details_)
                qte_ajoute_details_ = qtes.qte_ajoute_details_;
       }
}

const QString& InventoryItem::getJustificatif() const{
    return justification_;
}

void InventoryItem::setJustificatif(const QString& justification){
    if(!justification.simplified().isEmpty())
        justification_ = justification.simplified();
}
