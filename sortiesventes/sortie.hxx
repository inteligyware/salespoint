/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _SORTIE_HXX
#define _SORTIE_HXX

    #include "sortie.h"
    #include "../version.hxx"

    #pragma db object(Sortie) polymorphic definition
    #pragma db member(Sortie::id_) id auto
    #pragma db member(Sortie::date_) not_null default("now()")

    #pragma db member(Sortie::responsable_) on_delete( cascade) not_null
    #pragma db member(Sortie::facture_) on_delete( cascade ) null
    #pragma db member(Sortie::details_) inverse (sortie_) value_not_null

    #pragma db index(Sortie::"responsable-date_i") unique members ( responsable_ , date_ )

    #ifdef ODB_COMPILER
        #include "../personnels/personnel.hxx"
        #include "facture.hxx"
        #include "detailssortie.hxx"
    #endif

#endif //_SORTIE_HXX
