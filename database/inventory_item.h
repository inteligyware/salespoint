/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _INVENTORY_ITEM_H
#define _INVENTORY_ITEM_H

#include <QtCore/QString>
#include <QtCore/QDate>
#include <QtCore/QVector>
#include <QtCore/QSharedPointer>

#include <odb/qt/lazy-ptr.hxx>
#include "inventory.h"

class Produit;
using SPProduit = QSharedPointer<Produit>;
using LWPInventory = QLazyWeakPointer<Inventory>;
using SPInventory = QSharedPointer<Inventory>;

class InventoryItem{

private:
    ulong id_{0};
    quint32 qte_theo_gros_;
    quint32 qte_theo_details_;

    quint32 qte_phys_gros_{0};
    quint32 qte_phys_details_{0};

    quint32 qte_ajoute_gros_{0};
    quint32 qte_ajoute_details_{0};
    QString justification_;

    SPProduit produit_;
    LWPInventory inventory_;

    friend class odb::access;
    friend void Inventory::addItem(const SPProduit&, ItemQty qtes);

    InventoryItem();
    InventoryItem(SPProduit produit, ItemQty qtes);
    void setId(quint64 id);
    void setProduit(const SPProduit& produit);
    void setInventory(const SPInventory& inventory);

public:
    virtual ~InventoryItem();

    ulong getId() const;

    quint32 getQtePhysGros() const;
    void setQtePhysGros(quint32 qte);

    quint32 getQtePhysDetails() const;
    void setQtePhysDetails(quint32 qte);

    quint32 getQteAjouteGros() const;
    void setQteAjouteDetails(quint32 qte);

    quint32 getQteTheoGros() const;
    void setQteTheoDetails(quint32 qte);

    void updateQuantities(ItemQty qtes);

    const QString& getJustificatif() const;
    void setJustificatif(const QString& justification);

    const SPProduit& getProduit() const;

    SPInventory getInventory() const;
};

struct ItemQty{
    quint32 qte_phys_gros_{0};
    quint32 qte_phys_details_{0};
    quint32 qte_ajoute_gros_{0};
    quint32 qte_ajoute_details_{0};
};

#endif //_INVENTORY_ITEM_H
