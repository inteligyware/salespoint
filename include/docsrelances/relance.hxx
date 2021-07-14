/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _RELANCE_HXX
#define _RELANCE_HXX

    #include "relance.h"
    #include "../version.hxx"

    #pragma db object(Relance)  definition
    #pragma db member(Relance::id_) id auto
    #pragma db member(Relance::date_) not_null  default("now()")

    #pragma db member(Relance::relancee_) not_null on_delete(cascade)

    #ifdef ODB_COMPILER
        #include "relancable.hxx"
    #endif

#endif //_RELANCE_HXX
