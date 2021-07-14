/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _PERSONNEL_H
#define _PERSONNEL_H

#include <QtCore/QString>
#include <QtCore/QSharedPointer>
#include <QtCore/QDate>

#include <odb/core.hxx>
#include "personne.h"
#include "fonction.h"

using SPPFonction = QSharedPointer<Fonction>;
class Personnel : public Personne{
protected:
    QString matricule_;
    QDate date_naissance_;
    QDate date_embauche_{QDate::currentDate()};
    quint32 salaire_{0};

    SPPFonction fonction_;

    friend class odb::access;
    Personnel();

public:
    virtual ~Personnel();
    Personnel(const SPPFonction& fonction,
              QString noms,
              QString prenoms,
              QString tel,
              QString matricule = "");

    void setMatricule(QString matricule);
    const QString& getMatricule() const;

    void setDateNaissance(QDate);
    QDate getDateNaissance() const;

    void setDateEmbauche(QDate);
    QDate getDateEmbauche() const;

    void setSalaire(quint32 salaire);
    quint32 getSalaire() const;

    void setFonction(const SPPFonction&);
    const SPPFonction& getFonction() const;
};

#endif //_PERSONNEL_H
