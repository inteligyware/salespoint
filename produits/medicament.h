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
public:
    Medicament(
        const QString& CIP,
        const QString& libele,
        float qtecolise = 1,
        SPProduit parent = SPProduit {NULL}
        );

    virtual ~Medicament(){}

    const QString& getCIP() const;
    void setReference(const QString& ref);
    const QString& getReference() const;
    QString getLibeleFamille() const;
    QString type() const;

private:
    Medicament() {}
    QString CIP_;
    friend class odb::access;
    void setCIP(const QString& CIP);

};

//struct ViewMedicament{
//    ulong id;
//    QString libele;
//    QString codebare;
//    qreal prix_achat_moy;
//    quint64 prix_vente;
//    float remise;
//    float qte_unitaire;
//    QString CIP;
//};

#endif //_MEDICAMENT_H
