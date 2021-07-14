/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _FACTURE_HXX
#define _FACTURE_HXX

    #include "facture.h"
    #include "../version.hxx"

    #pragma db object(Facture) definition
    #pragma db member(Facture::reference_) unique not_null

    #pragma db member(Facture::sortie_) inverse ( facture_ ) not_null
    #pragma db member(Facture::reglements_) inverse ( facture_ ) null

    #ifdef ODB_COMPILER
        #include "../docsrelances/relancable.hxx"
        #include "reglement.hxx"
        #include "sortie.hxx"
    #endif

#endif //_FACTURE_HXX
