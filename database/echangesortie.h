/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _ECHANGESORTIE_H
#define _ECHANGESORTIE_H

#include "sortie.h"
#include "../produits/fournisseur.h"

using LSPFournisseur = QLazySharedPointer<Fournisseur>;
using SPFournisseur = QSharedPointer<Fournisseur>;

class EchangeSortie: public Sortie {

private:
    float taux_;
    LSPFournisseur fournisseur_;

    friend class odb::access;
    EchangeSortie();

public: 
    virtual ~EchangeSortie();
    EchangeSortie(const SPPersonnel &respo,
                  const SPFournisseur& fournisseur,
                  float taux = 1.25);

    virtual float getTauxInteret() const ;
    virtual void setTauxInteret(float taux);

    virtual void setFournisseur(const SPFournisseur& fournisseur);
    virtual const LSPFournisseur &getFournisseur() const;

    virtual quint32 getMontant() const;
};
#endif //_ECHANGESORTIE_H
