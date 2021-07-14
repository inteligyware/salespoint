/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _FACTURE_H
#define _FACTURE_H

#include "../docsrelances/relancable.h"
#include <odb/database.hxx>
using namespace odb::core;

class Sortie;
class Reglement;

class Facture: public Relancable {

private:
    QString reference_;
    QLazyWeakPointer<Sortie> sortie_;
    odb::vector<QLazyWeakPointer<Reglement>> reglements_;

    friend class odb::access;
    Facture();

public: 
    virtual ~Facture();
    Facture(const QSharedPointer<Sortie>& sortie, const QString &reference = "");

    const QString getTitre() const;

    const QString getReference() const;
    void setReference(const QString& reference);

    quint32 getMontant() const;

    const QLazyWeakPointer<Sortie>& getSortie() const;
    
    void setSortie(const QSharedPointer<Sortie>& sortie);
    
    const odb::vector<QLazyWeakPointer<Reglement>>&  getReglements() const;
    
    void addReglement(const QSharedPointer<Reglement>& reglement);
};

#endif //_FACTURE_H
