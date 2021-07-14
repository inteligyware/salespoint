/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 **/

#ifndef _SORTIE_H
#define _SORTIE_H

#include <QtCore/QDateTime>
#include <QtCore/QSharedPointer>

#include <odb/vector.hxx>
#include <QtCore/QVector>
#include <odb/qt/lazy-ptr.hxx>
#include <QtCore/QList>

using SPODBDatabase = QSharedPointer<odb::database>;

class Produit;
class Facture;
class Personnel;
class DetailsSortie;

using SPDetailsSortie = QSharedPointer<DetailsSortie>;
using SPDetails = QVector<SPDetailsSortie>;

using SPProduit = QSharedPointer<Produit>;
using SPFacture = QSharedPointer<Facture>;
using SPPersonnel = QSharedPointer<Personnel>;

class Sortie : public QEnableSharedFromThis<Sortie>{
protected:

    ulong id_;
    QDateTime date_;
    SPPersonnel responsable_;
    SPFacture facture_;
    SPDetails details_;

    friend class odb::access;
    Sortie();
    void setId(ulong id);
    void setDate( const QDateTime& date = QDateTime::currentDateTime() );

public: 
    virtual ~Sortie();
    Sortie(const SPPersonnel& responsable);
    ulong getId();

    QDateTime getDate() const;

    const SPPersonnel &getResponsable() const;
    void setResponsable(const SPPersonnel &responsable);

    const SPFacture& getFacture() const;
    void setFacture(const SPFacture &facture);

    virtual const SPDetails& getDetails() const;
    virtual const SPDetailsSortie& getDetails(int pos) const ;

    void addDetails(const SPProduit& prod , quint32 qte = 1);
    virtual bool removeDetails(const QList<int> *);
    virtual bool removeDetail(int);

    virtual quint32 getMontant() const = 0;
    virtual int count() const { return details_.size() ; }
    int indexOf(const SPProduit& prod);
    void persist(SPODBDatabase db);

    //    virtual Client buyer() const = 0;
    //    virtual Personnel seller() const = 0;
};

#endif //_SORTIE_H
