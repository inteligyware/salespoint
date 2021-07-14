/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _FOURNISSEUR_HXX
#define _FOURNISSEUR_HXX

#include "fournisseur.h"
#include "../version.hxx"

    #pragma db object(Fournisseur) definition
    #pragma db member(Fournisseur::id_) id auto
    #pragma db member(Fournisseur::nom_) unique not_null
    #pragma db member(Fournisseur::tel_) unique not_null
    #pragma db member(Fournisseur::initiale_) unique not_null
    #pragma db member(Fournisseur::type_fourn_) not_null
    #pragma db member(Fournisseur::email_) unique

    #pragma db member(Fournisseur::prixfourns_) inverse(fournisseur_) value_not_null
    
    #ifdef ODB_COMPILER
        #include "prixfourn.hxx"
    #endif

#endif //_FOURNISSEUR_HXX
