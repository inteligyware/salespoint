/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _DESTOCKAGE_H
#define _DESTOCKAGE_H

#include "sortie.h"

#include <QtCore/QString>

class Destockage: public Sortie {
private:
    QString raison_;
    QString action_;

    friend class odb::access;
    Destockage() = delete;

public: 
    virtual ~Destockage();

    Destockage(const SPPersonnel &responsable,
               const QString &raison = QString("Peremption"),
               const QString &action = QString("Destruction"));

    const QString& getRaison() const;
    void setRaison(const QString &raison);

    const QString &getAction() const;
    void setAction(const QString &action);

    virtual quint32 getMontant() const;
};

#endif //_DESTOCKAGE_H
