/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _FOURNISSEUR_H
#define _FOURNISSEUR_H

#include <QtCore/QString>
#include <QtCore/QDate>
#include <QtCore/QSharedPointer>

#include <odb/vector.hxx>
#include <odb/qt/lazy-ptr.hxx>
#include "types.h"

class Produit;
class PrixFourn;
class Fournisseur{

private:

    ulong id_;
    QString nom_;
    QString tel_;
    QString initiale_;
    QString type_fourn_;
    QString email_;
    QString description_;
    odb::vector <LWPPrixFourn > prixfourns_;

    friend class odb::access;
    friend class PrixFourn;

    Fournisseur();
    void setPrixfourns(const LWPPrixFourn& prixfourn);
    void setId(ulong id);
    
public:

    Fournisseur(
            const QString& nom,
            const QString& tel,
            const QString& initiale,
            const QString& type_fourn,
            const QString& email = "",
            const QString& description=""
            );
    
    virtual ~Fournisseur();    

    ulong getId() const;
    
    void setNom(const QString& nom);
    const QString& getNom() const;
    
    void setTel(const QString& tel);
    const QString& getTel() const;

    void setInitiale(const QString& initiale);
    const QString& getInitiale() const;
    
    void setType_fourn(const QString& type_fourn);
    const QString& getType_fourn() const;
    
    void setEmail(const QString& email);
    const QString& getEmail() const;
    
    void setDescription(const QString& description);
    const QString& getDescription() const;

    const odb::vector<LWPPrixFourn >& getPrixfourns() const;
    
};

#endif //_FOURNISSEUR_H
