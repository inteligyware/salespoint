/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */


#ifndef FAMILLE_H
#define FAMILLE_H

#include <utility>
#include <odb/vector.hxx>
#include <QtCore/QSharedPointer>
#include <QtCore/QVector>

#include "types.h"
using namespace odb::core;

class Famille : public QEnableSharedFromThis<Famille>
{
private:
    quint32 id_;
    QString reference_;
    QString libele_;
    QString description_;

    QVector<LWPFamille> children_;
    SPFamille parent_ { NULL };

    friend class odb::access;
    void setId(quint32);
    void setChildren(const SPFamille& child);
    void unchild(const SPFamille& child);
    const SPFamille& getParent() const ;
    Famille();

public:
    Famille(const QString& reference, const QString& libele);
    ~Famille();

    quint32 getId() const;

    void setReference(const QString& reference);
    const QString& getReference() const;
    bool isUnique(const QString& reference , const QSharedPointer<database>& db) const;

    void setLibele(const QString& libele);
    const QString&  getLibele();

    void setDescription(const QString& description);
    const QString&  getDescription() const;

    odb::vector<SPFamille> getChildren() const;

    void setParent(const SPFamille& parent);
    const SPFamille& parent() const ;

    SPFamille childAt(int pos) const ;
    bool isChild() const ;
};

#endif // FAMILLE_H
