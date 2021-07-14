/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _EMBALLAGE_HXX
#define _EMBALLAGE_HXX

    #include "emballage.h"
    #include "../version.hxx"

    #pragma db object(Emballage) definition
    #pragma db member(Emballage::libele_) id 
    #pragma db member(Emballage::description_) null 

    #pragma db member(Emballage::tonnages_) inverse (emballages_) value_null

    #ifdef ODB_COMPILER
        #include "tonnage.hxx"
    #endif

#endif //_EMBALLAGE_HXX
