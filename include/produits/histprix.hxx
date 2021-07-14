/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _HISTPRIX_HXX
#define _HISTPRIX_HXX

    #include "histprix.h"
    #include "../version.hxx"

    #pragma db object(HistPrix) definition
    #pragma db member(HistPrix::id_) id auto
    #pragma db member(HistPrix::date_fin_) not_null options("CHECK(date_fin <= CURRENT_DATE)") default("now()")

    #pragma db member(HistPrix::produit_) not_null on_delete (cascade)
    #pragma db index(HistPrix::"produit-date_fin_i") unique members ( produit_ , date_fin_ )

    #ifdef ODB_COMPILER
        #include "produit.hxx"
    #endif

#endif //_HISTPRIX_HXX
