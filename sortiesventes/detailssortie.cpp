/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "detailssortie.h"
#include "detailssortie-odb.hxx"
#include "sortie-odb.hxx"


/**
 * DetailsSortie implementation
 */

DetailsSortie::DetailsSortie(){}
DetailsSortie::~DetailsSortie(){}

DetailsSortie::DetailsSortie(SPProduit produit, quint32 qte)
{
    setId(0);
    setProduit(produit);
    setQte(qte);
    prix_unitaire_ = produit->getPrixVente();
}

void DetailsSortie::setId(quint64 id)
{
    id_ = id;
}

quint64 DetailsSortie::getId() const
{
    return id_;
}

quint32 DetailsSortie::getQte() const
{
    return qte_;
}

void DetailsSortie::setQte(quint32 qte){
    qte_ = qte;    
}

quint32 DetailsSortie::getPrixUnitaire() const{
    return prix_unitaire_;
}

void DetailsSortie::setPrixUnitaire(quint32 prix_unitaire){
    prix_unitaire_ = prix_unitaire;
}

bool DetailsSortie::negocierPrix(quint32 prixpropose){
    float prev_price = produit_->getPrixVente();
    float remise = 100*(1 - produit_->calculPrixVente(prixpropose,1,Produit::arrondi_)/prev_price);
    setRemise(remise);
    return(remise >= 0 &&  remise <= produit_->getRemise());
}

float DetailsSortie::getRemise() const{
    return remise_;
}
void DetailsSortie::setRemise(float remise){
    float prev_price = produit_->getPrixVente();
    float new_price = produit_->calculPrixVente(prev_price*(1 - remise/100),1,Produit::arrondi_);
    remise = 100*(1 - new_price /prev_price);
    if(remise >= 0 &&  remise <= produit_->getRemise()){
        remise_ = remise;
    }
}

quint64 DetailsSortie::getMontant() const
{
    return prix_unitaire_*(1 - remise_/100)*qte_;
}

void DetailsSortie::setProduit(const SPProduit& produit)
{
    produit_ = produit;
}

const SPProduit &DetailsSortie::getProduit() const
{
    return produit_;
}

void DetailsSortie::setSortie(const SPSortie& sortie)
{
    sortie_ = sortie;
}

const LWPSortie& DetailsSortie::getSortie() const{
    return sortie_;
}
