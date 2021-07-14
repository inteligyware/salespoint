/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _FAMILLE_HXX
#define _FAMILLE_HXX

    #include "famille.h"
    #include "../version.hxx"

    #pragma db object(Famille) definition
    #pragma db member(Famille::id_) id auto
    #pragma db member(Famille::reference_) type("VARCHAR(5)") unique not_null
    #pragma db member(Famille::libele_) unique not_null
    #pragma db member(Famille::description_)  null

    #pragma db member(Famille::children_) inverse (parent_) value_null
    #pragma db member(Famille::parent_) on_delete( cascade ) null

    #ifdef ODB_COMPILER
        #include "produit.hxx"
    #endif

#endif //_FAMILLE_HXX
