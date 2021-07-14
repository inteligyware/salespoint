/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "personne.h"

Personne::Personne(){}
Personne::~Personne(){}
Personne::Personne(QString noms,
           QString prenoms,
           QString tel,
           QString adresse,
           QString email)
{
    setId(0);
    setNoms(noms);
    setPrenoms(prenoms);
    setTel(tel);
    setAdresse(adresse);
    setEmail(email);
}

void Personne::setId(quint32 id){
    id_ = id;
}

quint32 Personne::getId() const
{
    return id_;
}

void Personne::setNoms(QString noms){
    if(!noms.isEmpty())
        noms_ = noms.simplified().toUpper();
}
const QString& Personne::getNoms() const
{
    return noms_;
}

void Personne::setPrenoms(QString prenoms)
{
    if(!prenoms.isEmpty())
        prenoms_ = prenoms.simplified().toUpper();
}

const QString& Personne::getPrenoms() const{
    return prenoms_;
}

void Personne::setAdresse(QString adresse)
{
    if(!adresse.isEmpty())
        adresse_ = adresse.simplified();
}

const QString & Personne::getAdresse() const{
    return adresse_;
}

void Personne::setTel(QString tel){
    if(!tel.isEmpty())
        tel_ = tel.trimmed();
}

const QString & Personne::getTel() const{
    return tel_;
}

void Personne::setEmail(QString email){
    if(!email.isEmpty())
        email_ = email.simplified();
}

const QString& Personne::getEmail() const{
    return email_;
}

void Personne::setCni(QString cni){
    if(!cni.isEmpty())
        cni_ = cni.simplified();
}

const QString& Personne::getCni() const{
    return cni_;
}
