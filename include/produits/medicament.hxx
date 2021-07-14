/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _MEDICAMENT_HXX
#define _MEDICAMENT_HXX

    #include "medicament.h"
    #include "../version.hxx"

    #pragma db object(Medicament) definition
    #pragma db member(Medicament::CIP_) unique not_null

//    #pragma db view (ViewMedicament) definition  object(Produit) query("ORDER BY" + Produit::id_)

    #ifdef ODB_COMPILER
        #include "produit.hxx"
    #endif

#endif //_MEDICAMENT_HXX
