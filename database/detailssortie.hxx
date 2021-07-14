/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _DETAILSSORTIE_HXX
#define _DETAILSSORTIE_HXX

    #include "detailssortie.h"
    #include "../version.hxx"
    #include <QtCore/QSharedPointer>

    #pragma db object(DetailsSortie) definition
    #pragma db member(DetailsSortie::id_) id auto
    #pragma db member(DetailsSortie::qte_) not_null options("CHECK(qte > 0)")
    #pragma db member(DetailsSortie::prix_unitaire_) not_null options("CHECK(prix_unitaire > 0)")
    #pragma db member(DetailsSortie::remise_)  options("CHECK(remise_ > 0 AND remise_ < 100)")

    #pragma db member(DetailsSortie::produit_) on_delete(cascade ) not_null
    #pragma db member(DetailsSortie::sortie_) on_delete( cascade ) not_null

    #pragma db index(DetailsSortie::"produit-sortie_i") unique members ( produit_ , sortie_ )

    #ifdef ODB_COMPILER
        #include "../produits/produit.hxx"
        #include "sortie.hxx"
    #endif

#endif //_DETAILSSORTIE_HXX
