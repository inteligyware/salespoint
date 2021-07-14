/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _REGLEMENT_HXX
#define _REGLEMENT_HXX

    #include "reglement.h"
    #include "../version.hxx"

    #pragma db object(Reglement) definition
    #pragma db member(Reglement::id_) id auto
    #pragma db member(Reglement::montant_) not_null options("CHECK(montant > 0)")
    #pragma db member(Reglement::date_) not_null default("now()")

    #pragma db member(Reglement::facture_) not_null on_delete( cascade )

    #ifdef ODB_COMPILER
        #include "facture.hxx"
    #endif

#endif //_REGLEMENT_HXX
