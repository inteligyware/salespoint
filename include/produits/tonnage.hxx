/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _TONNAGE_HXX
#define _TONNAGE_HXX

    #include "tonnage.h"
    #include "../version.hxx"

    #pragma db object(Tonnage) definition
    #pragma db member(Tonnage::id_) id auto
    #pragma db member(Tonnage::nb_unite_) not_null options("CHECK(nb_unite > 0)")
    #pragma db member(Tonnage::qte_par_unite_) not_null options("CHECK(qte_par_unite > 0)") default("1")

    #pragma db member(Tonnage::produits_) value_not_null on_delete(cascade)
    #pragma db member(Tonnage::emballages_) value_not_null on_delete(cascade)
    #pragma db index(Tonnage::"nb_unite-qte_par_unite_i") unique members (nb_unite_, qte_par_unite_)

    #ifdef ODB_COMPILER
        #include "produit.hxx"
        #include "emballage.hxx"
    #endif

#endif //_TONNAGE_HXX
