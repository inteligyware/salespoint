#include "fonction.h"

Fonction::Fonction(){}
Fonction::Fonction(const QString& libele){
    setId(0);
    setLibele(libele);
}

void Fonction::setId(quint32 id){
    id_ = id;
}

quint32 Fonction::getId() const{
    return id_;
}

void Fonction::setLibele(const QString& libele){
    if(!libele.isEmpty())
        libele_ = libele.simplified().toUpper();
}

const QString& Fonction::getLibele() const{
    return libele_;
}
