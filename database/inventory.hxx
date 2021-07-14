/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _INVENTORY_HXX
#define _INVENTORY_HXX

    #include "inventory.h"
    #include "../version.hxx"

    #pragma db object(Inventory) definition
    #pragma db member(Inventory::id_) id auto
    #pragma db member(Inventory::date_started_) not_null default("now()")
    #pragma db member(Inventory::date_ended_) null options("CHECK(date_ended_ > date_started_)")

    #pragma db member(Inventory::responsable_) on_delete( cascade) not_null
    #pragma db member(Inventory::items_) inverse (inventory_) value_not_null

    #pragma db index(Inventory::"responsable-date_started_i") unique members ( responsable_ , date_started_)

    #ifdef ODB_COMPILER
        #include "../personnels/personnel.hxx"
        #include "inventory_item.hxx"
    #endif

#endif //_INVENTORY_HXX
