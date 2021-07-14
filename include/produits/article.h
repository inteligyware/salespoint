/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef ARTICLE_H
#define ARTICLE_H

#include <QtCore/QString>
#include <odb/core.hxx>

#include <QtCore/QSharedPointer>

#include <odb/vector.hxx>
#include <odb/qt/lazy-ptr.hxx>

#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include "produit.h"

using namespace std;
using namespace odb::core;
class Article : public Produit{

private:

    QString reference_; // 6 digits of form fffssssss automatically generated. combination of famille + serial number in fammille

    SPFamille famille_;

    friend class odb::access;
    Article();
    void setFamille(const SPFamille& famille);

public:

   Article(
        const SPFamille& famille,
        const QString& libele,
           float qtecolise = 1,
           SPProduit parent = SPProduit {NULL}
        );

    virtual ~Article();
    const SPFamille& getFamille() const;
    const QString& getReference() const;
    void setReference(const QString& reference);
    QString getLibeleFamille() const;
    QString type() const;
};

#endif // ARTICLE_H

