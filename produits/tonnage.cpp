/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "tonnage.h"
#include "tonnage-odb.hxx"
#include "produit.h"
#include "produit-odb.hxx"
#include "emballage.h"
#include "emballage-odb.hxx"

/**
 * Tonnage implementation
 */

Tonnage::Tonnage(){}
Tonnage::~Tonnage(){}

Tonnage::Tonnage(quint32 nb_unite, quint32 qte_par_unite)
{
    setNb_unite(nb_unite);
    setQte_par_unite(qte_par_unite);
}

void Tonnage::setId( quint32 id)
{
    id_ = id;
}

quint32 Tonnage::getId() const
{
    return id_;
}

void Tonnage::bindProdEmb(SPProduit produit,SPEmballage emballage)
{
    setProduits(produit);
    setEmballages(emballage);
    produit->setTonnages(sharedFromThis());
    emballage->setTonnages(sharedFromThis());
}

quint32 Tonnage::getNb_unite() const
{
    return nb_unite_;
}

quint32 Tonnage::getQte_par_unite() const
{
    return qte_par_unite_;
}

void Tonnage::setNb_unite(quint32 nb_unite)
{
    nb_unite_ = nb_unite;

}

void Tonnage::setQte_par_unite(quint32 qte_par_unite)
{
    qte_par_unite_ = qte_par_unite;
}

void Tonnage::setProduits(SPProduit produit)
{
    produits_.push_back(produit);
}

void Tonnage::setEmballages(SPEmballage& emballage)
{
    emballages_.push_back(emballage);
}

const odb::vector<LSPProduit >& Tonnage::getProduits() const
{
    return produits_;
}

const odb::vector<LSPEmballage >& Tonnage::getEmballage() const
{
    return emballages_;
}
