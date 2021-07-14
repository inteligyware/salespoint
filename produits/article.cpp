/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#include "article.h"
#include "article-odb.hxx"
#include "famille.h"
#include "famille-odb.hxx"


#include <QtCore/QString>

/**
 * Article implementation
 */


Article::Article() {}
Article::~Article() {}

Article::Article(const SPFamille& famille,
        const QString& libele,
        float qtecolise,
        SPProduit parent
        ) : Produit (libele, qtecolise, parent)
{
    setFamille(famille);
}

void Article::setFamille(const SPFamille& famille){

    if(famille_.isNull()) famille_ = famille;
}

const SPFamille& Article::getFamille() const{
    return famille_;
}

void Article::setReference(const QString& reference){
    reference_ = reference;
}

const QString& Article::getReference() const{
    return reference_;
}

QString Article::getLibeleFamille() const{
    return famille_->getLibele();
}

QString Article::type() const{
    return typeid(this).name();
}

//QString Article::nextSerial(QSharedPointer<database>& db){

//    typedef odb::query<Article> query;
//    SPArticle tmp = db->query<Article>( query::famille == getFamille());

//    if (tmp.isNull())

//        return QString("000001");

//    else
//    {
//        tmp->setPrixVente(old_prix_vente);
//        db->update(tmp);
//    }

//}


