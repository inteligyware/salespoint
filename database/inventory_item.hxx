/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _INVENTORY_ITEM_HXX
#define _INVENTORY_ITEM_HXX

    #include "inventory_item.h"
    #include "../version.hxx"
    #include <QtCore/QSharedPointer>

    #pragma db object(InventoryItem) definition
    #pragma db member(InventoryItem::id_) id auto

    #pragma db member(InventoryItem::produit_) on_delete(cascade ) not_null
    #pragma db member(InventoryItem::inventory_) on_delete( cascade ) not_null

    #pragma db index(InventoryItem::"produit-inventory_i") unique members ( produit_ , inventory_ )

    #ifdef ODB_COMPILER
        #include "../produits/produit.hxx"
        #include "inventory.hxx"
    #endif

#endif //_INVENTORY_ITEM_HXX
