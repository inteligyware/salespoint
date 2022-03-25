/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#include "medicament.h"
#include "medicament.hxx"
#include "medicament-odb.hxx"

#include <QtCore/QString>

/**
 * Medicament implementation
 */




Medicament::Medicament(const QString& CIP,
                 const QString& libele,
                 float qtecolise,
                 SPProduit parent
                ) : Produit (libele, qtecolise, parent)
{
    setReference(CIP);
}

void Medicament::setCIP(const QString& CIP){ // should be unsigned long

    CIP_ = CIP.simplified().toUpper();
}

const QString& Medicament::getCIP() const{
    return CIP_;
}

const QString& Medicament::getReference() const{
     return getCIP();
}

void Medicament::setReference(const QString& ref){
    setCIP(ref);
}

QString Medicament::getLibeleFamille() const{
    return QString("MEDICAMENTS");
}

QString Medicament::type() const{
    return typeid(this).name();
}
