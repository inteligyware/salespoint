/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _TONNAGE_H
#define _TONNAGE_H

#include <QtCore/QSharedPointer>

#include <odb/vector.hxx>
#include <odb/qt/lazy-ptr.hxx>
#include "types.h"

class Produit;
class Emballage;

class Tonnage : public QEnableSharedFromThis<Tonnage>{

private: 

    quint32 id_;
    quint32 nb_unite_;
    quint32 qte_par_unite_;
    odb::vector<LSPProduit > produits_;
    odb::vector<LSPEmballage > emballages_;

    friend class odb::access;
    Tonnage();
    void setId( quint32 id);
    void setProduits(SPProduit produit);
    void setEmballages(SPEmballage& emballage);

public:
    virtual ~Tonnage();
    Tonnage(quint32 nb_unite, quint32 qte_par_unite = 1);

    quint32 getId() const;

    void bindProdEmb(SPProduit produit,SPEmballage emballage);

    quint32 getNb_unite() const ;

    void setNb_unite(quint32 nb_unite);

    quint32 getQte_par_unite() const;

    void setQte_par_unite(quint32 qte_par_unite);

    const odb::vector<LSPProduit >& getProduits() const;

    const odb::vector<LSPEmballage >& getEmballage() const;
};

#endif //_TONNAGE_H
