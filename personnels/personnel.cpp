/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#include "personnel.h"

/**
 * Personnel implementation
 */

Personnel::Personnel(){}
Personnel::~Personnel(){}
Personnel::Personnel(const SPPFonction& fonction,
          QString noms,
          QString prenoms,
          QString tel,
          QString matricule) : Personne(noms,prenoms,tel)
{
    setMatricule(matricule);
    setFonction(fonction);
}

void Personnel::setMatricule(QString matricule){
    if(!matricule.isEmpty())
        matricule_ = matricule.simplified().toUpper();
}

const QString& Personnel::getMatricule() const{
    return matricule_;
}

void Personnel::setDateNaissance(QDate date){
    if(date.isValid() && date < QDate::currentDate())
        date_naissance_ = date;
}

QDate Personnel::getDateNaissance() const{
    return date_naissance_;
}

void Personnel::setDateEmbauche(QDate date){
    if(date.isValid() && date > date_naissance_ )
        date_embauche_ = date;
}

QDate Personnel::getDateEmbauche() const{
    return date_embauche_;
}

void Personnel::setSalaire(quint32 salaire){
    salaire_ = salaire;
}

quint32 Personnel::getSalaire() const{
    return salaire_;
}

void Personnel::setFonction(const SPPFonction& fonction){
    if(!fonction.isNull())
        fonction_ = fonction;
}

const SPPFonction& Personnel::getFonction() const{
    return fonction_;
}
