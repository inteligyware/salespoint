/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _ECHANGESORTIE_HXX
#define _ECHANGESORTIE_HXX

    #include "echangesortie.h"
    #include "../version.hxx"

    #pragma db object(EchangeSortie)  definition
    #pragma db member(EchangeSortie::taux_) not_null options("CHECK(taux > 1)") default (1)

    #pragma db member(EchangeSortie::fournisseur_) on_delete(cascade) not_null

    #ifdef ODB_COMPILER
        #include "sortie.hxx"
        #include "../produits/fournisseur.hxx"
    #endif

#endif //_ECHANGESORTIE_HXX
