/**
 * Project InteligyPharma
 * @author Gilles BENE
 * @version 1.0
 */

#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <QtCore/QDateTime>
#include <QtCore/QSharedPointer>
#include <QtCore/QVector>

#include <odb/qt/lazy-ptr.hxx>

using namespace odb::core;

using SPODBDatabase = QSharedPointer<odb::database>;

class Personnel;
class InventoryItem;
class Produit;
struct ItemQty;

using SPItem = QSharedPointer<InventoryItem>;
using SPItems = QVector<SPItem>;
using SPPersonnel = QSharedPointer<Personnel>;
using SPProduit = QSharedPointer<Produit>;

class Inventory : public QEnableSharedFromThis<Inventory>{

private:
    ulong id_;
    QDateTime date_started_;
    QDateTime date_ended_;
    QString report_;

    SPPersonnel responsable_;
    SPItems items_;

    friend class odb::access;
    Inventory();
    void setId(ulong id);
    void setDateStared( const QDateTime& date = QDateTime::currentDateTime());
    void setDateEnded( const QDateTime& date = QDateTime::currentDateTime());
    void setResponsable(const SPPersonnel &responsable);

public:
    virtual ~Inventory();
    Inventory(const SPPersonnel& responsable);
    ulong getId();

    QDateTime getDateStarted() const;
    QDateTime getDateEnded() const;

    const QString& getReport() const;
    void setReport(const QString& report);

    const SPPersonnel &getResponsable() const;

    const SPItems& getItems() const;
    const SPItem &getItem(int pos) const ;

    void addItem(const SPProduit& prod,ItemQty qtes);
    bool removeItem(int);
    bool removeItems(const QList<int>* pos);
    int  indexOf(const SPProduit& prod);
    int count() const { return items_.size() ; }

    void signeInventory();
    void persist(SPODBDatabase db);
};

#endif //_INVENTORY_H
