/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _PERSONNEL_HXX
#define _PERSONNEL_HXX

    #include "personnel.h"
    #include "../version.hxx"

    #pragma db object(Personnel) definition
    #pragma db member(Personnel::matricule_) unique null
    #pragma db member(Personnel::fonction_) on_delete( cascade )  null

    #ifdef ODB_COMPILER
        #include "personne.hxx"
        #include "fonction.hxx"
    #endif

#endif //_PERSONNEL_HXX
