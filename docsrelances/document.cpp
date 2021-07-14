/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#include "document.h"
#include "document-odb.hxx"

/**
 * Document implementation
 */

QString Document::entete_ = QString("IPHARMA");
QString Document::pieds_ = QString("Inteligy Software Entreprise® All Rights Reserved - InteligyWare®");

void Document::setId(ulong id){
    id_ = id;
}

ulong Document::getId() const{
    return id_;
}

/*
Document::Document(){
    setContenu(contenu);
}
*/

Document::Document(){}

/*void Document::setContenu(const QString& contenu){
    contenu_ = contenu.simplified();
}

const QString& Document::getContenu() const {
    return contenu_;
}
*/

const QString& Document::getEntete()
{
    return entete_;
}

const QString& Document::getPieds()
{
    return pieds_;
}

void Document::setEntete(const QString &entete){
    entete_ = entete;
}

void Document::setPieds(const QString& pieds){
    pieds_ = pieds;
}
