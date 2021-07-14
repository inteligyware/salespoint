/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _PRIXFOURN_HXX
#define _PRIXFOURN_HXX

    #include "prixfourn.h"
    #include "../version.hxx"

    #pragma db object(PrixFourn) definition
    #pragma db member(PrixFourn::id_) id auto
    #pragma db member(PrixFourn::prix_) not_null options("CHECK(prix > 0)")
    #pragma db member(PrixFourn::date_effet_) not_null options("CHECK(date_effet <= CURRENT_DATE)") default("now()")

    #pragma db member(PrixFourn::produit_) not_null on_delete(cascade)
    #pragma db member(PrixFourn::fournisseur_) not_null  on_delete(cascade)
    #pragma db index(PrixFourn::"produit-fournisseur-date_effet_i") unique members ( produit_ , fournisseur_ , date_effet_ )

    #ifdef ODB_COMPILER
        # include "produit.hxx"
        # include "fournisseur.hxx"
    #endif

#endif //_PRIXFOURN_HXX
