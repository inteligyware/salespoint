/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */
#include "fournisseur.h"
#include "fournisseur-odb.hxx"

#include <QtCore/QString>
#include <QtCore/QDate>
#include <QtCore/QSharedPointer>

#include <odb/vector.hxx>
#include <odb/qt/lazy-ptr.hxx>

/**
 * Fournisseur implementation
 */

Fournisseur::Fournisseur(){}
Fournisseur::~Fournisseur(){}

Fournisseur::Fournisseur(const QString& nom,
                         const QString& tel,
                         const QString& initiale,
                         const QString& type_fourn,
                         const QString& email,
                         const QString& description)
{
    setNom(nom);
    setTel(tel);
    setInitiale(initiale);
    setType_fourn(type_fourn);
    setEmail(email);
    setDescription(description);

}


void Fournisseur::setId(ulong id)
{
    id_ = id ;
}

ulong Fournisseur::getId() const
{
    return id_ ;
}

void Fournisseur::setNom(const QString& nom)
{
    nom_ = nom.simplified().toUpper() ;
}

const QString& Fournisseur::getNom() const
{
    return nom_ ;
}

void Fournisseur::setTel(const QString& tel)
{
    tel_ = tel.simplified();
}

const QString& Fournisseur::getTel() const
{
    return tel_ ;
}

void Fournisseur::setInitiale(const QString& initiale)
{
    initiale_ = initiale;
}

const QString& Fournisseur::getInitiale() const
{
    return initiale_;
}

void Fournisseur::setType_fourn(const QString& type_fourn)
{
    type_fourn_ = type_fourn.toUpper() ;
}

const QString& Fournisseur::getType_fourn() const
{
    return type_fourn_ ;
}

void Fournisseur::setEmail(const QString& email)
{
    if( email != "" ) email_ = email.simplified().toLower();
}

const QString& Fournisseur::getEmail() const
{
    return email_ ;
}

void Fournisseur::setDescription(const QString& description)
{
    description_ = description.simplified();
}

const QString& Fournisseur::getDescription() const
{
    return description_ ;
}

void Fournisseur::setPrixfourns(const LWPPrixFourn& prixfourn)
{
    prixfourns_.push_back(prixfourn);
}

const odb::vector<LWPPrixFourn >& Fournisseur::getPrixfourns() const
{
    return prixfourns_;
}
