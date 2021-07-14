/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _PERSONNE_HXX
#define _PERSONNE_HXX

    #include "personne.h"
    #include "../version.hxx"

    #pragma db object(Personne) polymorphic definition
    #pragma db member(Personne::id_) id auto
    #pragma db member(Personne::noms_) not_null
    #pragma db member(Personne::prenoms_) not_null
    #pragma db member(Personne::tel_) unique not_null
    #pragma db member(Personne::cni_) unique null
    #pragma db member(Personne::email_) unique null

    #pragma db index(Personne::"noms-prenoms-cni_i") unique members ( noms_ , prenoms_ , cni_ )
    #pragma db index(Personne::"noms-prenoms-adresse_i") unique members ( noms_ , prenoms_ , adresse_ )

#endif //_PERSONNE_HXX
