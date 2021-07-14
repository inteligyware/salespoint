/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _FONCTION_HXX
#define _FONCTION_HXX

    #include "fonction.h"
    #include "../version.hxx"

    #pragma db object(Fonction) definition
    #pragma db member(Fonction::id_) id auto
    #pragma db member(Fonction::libele_) unique not_null

#endif //_FONCTION_HXX
