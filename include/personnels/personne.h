/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef _PERSONNE_H
#define _PERSONNE_H

#include <QtCore/QString>

#include <odb/core.hxx>

class Personne {
protected:
    quint32 id_;
    QString noms_;
    QString prenoms_;
    QString adresse_;
    QString tel_;
    QString email_;
    QString cni_;

    friend class odb::access;
    Personne();
    void setId(quint32 id);

public:
    virtual ~Personne();
    Personne(QString noms,
               QString prenoms,
               QString tel,
               QString adresse = "",
               QString email = "");

    quint32 getId() const;

    virtual void setNoms(QString noms);
    virtual const QString& getNoms() const;

    virtual void setPrenoms(QString prenoms);
    virtual const QString & getPrenoms() const;

    virtual void setAdresse(QString adresse);
    virtual const QString & getAdresse() const;

    virtual void setTel(QString tel);
    virtual const QString & getTel() const;

    virtual void setEmail(QString email);
    virtual const QString & getEmail() const;

    virtual void setCni(QString cni);
    virtual const QString & getCni() const;
};

#endif //_PERSONNE_H
