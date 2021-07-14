/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _DOCUMENT_H
#define _DOCUMENT_H

#include <QtCore/QString>
#include <odb/core.hxx>

class Document {
protected:

    ulong id_;
    //QString contenu_;
    static QString entete_;
    static QString pieds_;

    friend class odb::access;
    Document();
    void setId(ulong id);

public: 

    ulong getId() const;
    static void setEntete(const QString& entete);
    static const QString& getEntete() ;

    static void setPieds(const QString& pieds);
    static const QString& getPieds();

    //void setContenu(const QString& contenu);
    //const QString& getContenu() const ;
};

#endif //_DOCUMENT_H
