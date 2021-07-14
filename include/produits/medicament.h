/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _MEDICAMENT_H
#define _MEDICAMENT_H

#include <QtCore/QString>
#include <odb/core.hxx>
#include "produit.h"
#include "types.h"

using namespace std;

class Medicament : public Produit{

private:

    QString CIP_;

    friend class odb::access;
    Medicament();
    void setCIP(const QString& CIP);

public:

   Medicament(
        const QString& CIP,
        const QString& libele,
           float qtecolise = 1,
           SPProduit parent = SPProduit {NULL}
        );

    virtual ~Medicament();
    const QString& getCIP() const;
    void setReference(const QString& ref);
    const QString& getReference() const;
    QString getLibeleFamille() const;
    QString type() const;
};

#endif //_MEDICAMENT_H
