/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _REGLEMENT_H
#define _REGLEMENT_H

#include <QtCore/QDateTime>

#include <odb/qt/lazy-ptr.hxx>

class Facture;
class Reglement {

private:
    quint32 id_;
    quint32 montant_;
    QDateTime date_;
    QLazySharedPointer<Facture> facture_;

    friend class odb::access;
    Reglement();
    void setId( quint32 id);

public:
    virtual ~Reglement();
    Reglement(quint32 montant,
              const QSharedPointer<Facture>& facture);

    quint32 getId() const;

    void setMontant(quint32 montant);
    quint32 getMontant() const;

    void setDate();
    QDateTime getDate() const;

    void setFacture(const QSharedPointer<Facture>& facture);
    const QLazySharedPointer<Facture> &getFacture() const;


};

#endif //_REGLEMENT_H
