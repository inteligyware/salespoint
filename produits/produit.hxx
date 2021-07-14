/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _PRODUIT_HXX
#define _PRODUIT_HXX

    #include "produit.h"
    #include "../version.hxx"

    #pragma db object(Produit) polymorphic definition
    #pragma db member(Produit::id_) id auto
    #pragma db member(Produit::libele_) unique not_null
    #pragma db member(Produit::codebare_) unique null
//    #pragma db member(Produit::remise_) null options("CHECK(remise >= 0)")

    #pragma db member(Produit::children_) inverse (parent_) value_null
    #pragma db member(Produit::parent_) on_delete( cascade ) null

    #pragma db member(Produit::prixfourns_) inverse (produit_) value_null
    #pragma db member(Produit::tonnages_) inverse (produits_) value_null
    #pragma db member(Produit::hist_prixs_) inverse (produit_) value_null

    #pragma db view (DBViewProduits) definition  object(Produit) query("ORDER BY" + Produit::id_)
    #pragma db view (ViewProduit) definition  object(Produit) query("ORDER BY" + Produit::id_)

    #ifdef ODB_COMPILER
        #include "prixfourn.hxx"
        #include "tonnage.hxx"
        #include "histprix.hxx"
    #endif

#endif //_PRODUIT_HXX
