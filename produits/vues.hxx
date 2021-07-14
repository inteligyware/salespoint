#ifndef VUES_HXX
#define VUES_HXX

#include "vues.h"
#include "../version.hxx"

//#pragma db view (AViewProduit) definition  object(Produit = p) object(Article = a : p::id_ == a::id_ )
//    object (Medicament = m : p::id_ = m::id_) object(Famille = f : f::id_ == a::famille) query("ORDER BY" + Produit::id_)

#pragma db view query("SELECT p.id idp, a.reference, p.libele, prix_achat_moy, remise, prix_vente, qte_unitaire, codebare, "\
"f.id idf, p.parent idpp , f.parent idfp, m.cip, f.libele famille "\
    "FROM produit p  LEFT JOIN article a  ON p.id = a.id  LEFT JOIN medicament m  "\
    "ON p.id = m.id LEFT JOIN famille f ON f.id = a.famille;")

struct AViewProduit{
    #pragma db type("BIGINT")
    ulong idp;      //id produit

    #pragma db type("VARCHAR(10)")
    QString reference;

    #pragma db type("TEXT")
    QString libele;

    #pragma db type("DOUBLE PRECISION")
    qreal prix_achat_moy;

    #pragma db type("REAL")
    float remise;
    
    #pragma db type("BIGINT")
    quint64 prix_vente;    

    #pragma db type("REAL")
    float qte_unitaire;

    #pragma db type("TEXT")
    QString codebare;

    #pragma db type("INTEGER")
    quint32 idf;      //id famille

    #pragma db type("BIGINT")
    ulong idpp;     //id produit parent

    #pragma db type("INTEGER")
    quint32 idfp;     //id famille parent

    #pragma db type("TEXT")
    QString cip;

    #pragma db type("TEXT")
    QString famille;   
};

#ifdef ODB_COMPILER
    #include "famille.hxx"
    #include "produit.hxx"
    #include "medicament.hxx"
    #include "article.hxx"
#endif

#endif // VUES_HXX
