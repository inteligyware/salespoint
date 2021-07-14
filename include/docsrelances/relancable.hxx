/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _RELANCABLE_HXX
#define _RELANCABLE_HXX

    #include "relancable.h"
    #include "../version.hxx"

    #pragma db object(Relancable) polymorphic definition

    #pragma db member(Relancable::relances_) inverse (relancee_) value_not_null

    #ifdef ODB_COMPILER
        #include "relance.hxx"
        #include "document.hxx"
    #endif

#endif //_RELANCABLE_HXX
