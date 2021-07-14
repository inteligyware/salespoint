#ifndef MODEL_H
#define MODEL_H

#include <QStringList>
#include <QtCore/QSharedPointer>
#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include <QtSql>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/pgsql/database.hxx>
#include <QVector>
#include <QList>

#include "produits/produits.h"
#include "sortiesventes/ventes.h"
#include "inventaires/inventaires.h"
#include "include/produits/vues.hxx"

using namespace odb::core;
using SPODBDatabase = QSharedPointer<odb::database>;

class QObject;
class QAbstractTableModel;

class UniqueProxyModel : public QSortFilterProxyModel{
    Q_OBJECT

public:
    explicit UniqueProxyModel(int column , QObject* parent = Q_NULLPTR);

    void setSourceModel(QAbstractItemModel *sourceModel);

protected:
    bool filterAcceptsRow(int sourceRow,const QModelIndex &sourceParent) const;

private slots:
    void clearCache() { cache.clear(); }

private:
    const int COLUMN;
    mutable QSet<QString> cache;
};

class RetailableProductProxyModel : public QSortFilterProxyModel{
    Q_OBJECT

bool accept_med;

public:
    explicit RetailableProductProxyModel(bool onlymed, QObject* parent = Q_NULLPTR);

protected:
    bool filterAcceptsRow(int sourceRow,const QModelIndex &sourceParent) const;
};

class DateFilterProxyModel : public QSortFilterProxyModel{
    Q_OBJECT
public:
    explicit DateFilterProxyModel(QObject *parent = Q_NULLPTR ,
                        const QDateTime& from_date = QDateTime::currentDateTime(),
                        const QDateTime& to_date = QDateTime::currentDateTime());
    void setSourceModel(QAbstractItemModel *sourceModel);
    bool isUnique(const QString& value, int column) const;
    bool modelHasDateField();
    void setFromDate(const QDateTime& from_date);
    void setToDate(const QDateTime& to_date);
    const QDateTime& fromDate() const;
    const QDateTime& toDate() const;


protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    QDateTime _from_date , _to_date;
    int COLUMN_DATE = -1;
    bool isSourceModelSet = false;

};

class AbstractODBModel : public QAbstractTableModel{
    Q_OBJECT

protected:
    explicit AbstractODBModel (QObject* parent = Q_NULLPTR);

public:
    static SPODBDatabase DB;

    virtual void setDefaultSortColumn(uint col) = 0;
    virtual uint defaultSortColumn() const = 0;
    virtual bool hasChildren(const QModelIndex &parent) const;
    bool isUnique(const QString& value, int column) const;
};

class ODBFamilyModel : public AbstractODBModel
{

public:
    explicit ODBFamilyModel(QObject* parent = Q_NULLPTR);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant headerData(int section,Qt::Orientation orientation = Qt::Horizontal,int role = Qt::DisplayRole) const;

    void load();
    SPFamille getItemById(ulong id) const;
    SPFamille getItemByReference(const QString& reference) const;
    SPFamille getItemByLabel(const QString& libele) const;

    bool addItem(const SPFamille& spfamille);

    bool removeItemsByIds(const QList<ulong> &ids);
    bool removeItemById(ulong id);
    bool removeItemByReference(const QString& reference);
    bool removeItemByLabel(const QString& libele);

    bool save();

    void setDefaultSortColumn(uint col);
    uint defaultSortColumn() const ;

protected:
    void loadCSV(QString filename);
    bool storeCSV();

    QVector<SPFamille> _data;
    uint _default_sort_column;
    QStringList _headers;

public:
    static const enum  Column : char
    {
        ID,
        REFERENCE,
        DESIGNATION,
        DESCRIPTION
    } Column;
 };

class QProductModel : public QSqlQueryModel{
    Q_OBJECT

    QString _query;
    QStringList _headers;

    void load();

public:
    QProductModel(QObject* parent = Q_NULLPTR);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int = Qt::EditRole);
    bool isUnique(const QString& value, int column) const;
//    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
//    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

    enum Column : char
    {
        ID_PRODUIT,
        REFERENCE,
        DESIGNATION,
        FAMILLE,
        PU_ACHAT,
        REMISE,
        PU_VENTE,
        QTE_COLISEE,
        CODEBARE,
        ID_FAMILLE,
        ID_PRODUIT_PARENT,
        ID_FAMILLE_PARENT
    };

};

struct ListingModelParam{
    QString query;
    QStringList header;
    QString title;
    QList<int> colums;
    Qt::Alignment algnmt;
};

class ListingModel : public QSqlQueryModel {
    Q_OBJECT

    QString _query;
    QStringList _headers;
    QString _querytitle;
    QVector<Qt::Alignment> alignments;

public:    
    ListingModel(QObject* parent = Q_NULLPTR); //The default constructor buildsthe history of instant sales
    ListingModel(const ListingModelParam& param, QObject* parent = Q_NULLPTR);
    ListingModel(const QString& query, const QStringList& header , const QString& title, QObject* parent = Q_NULLPTR);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;

    virtual void load();
    void resetModel();
    bool isUnique(const QString& value, int column) const;
    void setAlignments(const QList<int>& columns , Qt::Alignment algnmt = Qt::AlignRight | Qt::AlignVCenter);
    const QString& query() const;
    const QStringList& headers() const;
    const QString& title() const;

private:
    void initModel(const QString& query, const QStringList& header);
    void initAlignments();
};

class SalesListingModel : public ListingModel {
    Q_OBJECT

public:
    SalesListingModel(QObject* parent = Q_NULLPTR):ListingModel(parent){} //The default constructor builds the history of instant sales
    QVariant data(const QModelIndex &index, int role) const;
};

class ODBProductModel : public AbstractODBModel
{
    Q_OBJECT
public:
    explicit ODBProductModel(QObject* parent = Q_NULLPTR);
    void setDefaultSortColumn(uint col);
    uint defaultSortColumn() const ;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    void load();
    QVariant headerData(int section,Qt::Orientation orientation = Qt::Horizontal,int role = Qt::DisplayRole) const;

    SPProduit getItemById(ulong id) const;
    SPProduit getItemByReference(const QString& reference) const;
    SPProduit getItemByLabel(const QString& libele) const;

    bool addItem(const SPProduit& spproduit);

    bool removeItemsByIds(const QList<ulong> &ids);
    bool removeItemById(ulong id);
    bool removeItemByReference(const QString& reference);
    bool removeItemByLabel(const QString& libele);

    bool save();

private:
    void loadCSV(QString filename);
    bool storeCSV();

    QVector<SPProduit> _data;
    uint _default_sort_column;
    QStringList _headers;

public:
    static const enum  Column : char
    {
        ID_PRODUIT,
        REFERENCE,
        DESIGNATION,
        FAMILLE,
        PU_ACHAT,
        REMISE,
        PU_VENTE,        
        QTE_COLISEE,
        CODEBARE,
        ID_PRODUIT_PARENT,
        ID_FAMILLE,        
        ID_FAMILLE_PARENT
    } Column;
 };

class ConstODBProductModel : public ODBProductModel{
public:
    explicit ConstODBProductModel(QObject* parent = Q_NULLPTR);
    Qt::ItemFlags flags(const QModelIndex &index) const final ;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) final ;
};

class SortieModel : public AbstractODBModel
{
    Q_OBJECT
public:

    explicit SortieModel(QObject* parent = Q_NULLPTR);
    void setDefaultSortColumn(uint col);
    uint defaultSortColumn() const ;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
//    Qt::ItemFlags flags(const QModelIndex &index) const;
//    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    QVariant headerData(int section,
                        Qt::Orientation orientation = Qt::Horizontal ,
                        int role = Qt::DisplayRole) const;

private:
    void fetchData();

private:

    using value_type = QVector<QSharedPointer<EchangeSortie>>;
    int _default_sort_column;
    value_type _data ;
    QStringList _headers;
    QStringList _details;

    enum ColonneSortie : char
    {
        N,
        Reference,
        Date,
        Seller,
        Customer,
        Reduction,
        Amount
    };

//    enum Details : char
//    {
//        Reference,
//        Designation,
//        Quantity,
//        UnitPrice,
//        SubTotal
//    };
 };

class SalesModel : public AbstractODBModel
{
    Q_OBJECT
public:
    using  spDetailsSortie = QSharedPointer<DetailsSortie>;
    using  spDetails = QVector<spDetailsSortie>;

    explicit SalesModel(QObject* parent = Q_NULLPTR);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    QVariant headerData(int section,Qt::Orientation orientation = Qt::Horizontal , int role = Qt::DisplayRole) const;

    void initModel(int saler_id = 1);
    bool isEmpty( ) {return  _data.isNull();}
    virtual void setDefaultSortColumn(uint){}
    virtual uint defaultSortColumn() const { return 0 ;}

    void addItem(const QSharedPointer<Produit>& prod , quint32 qte = 1);
    void removeItems(const QList<int>* list);
    void removeItem(int pos);
    quint32 getMontant();

    int indexOf(const SPProduit &prod);
    SPSortie reset();
    void setSale(const SPSortie&);
    QString salesContent();
    const SPPersonnel& saler();
    const SPPersonnel& cashier();

    void save();

private:
    void fetchData();
    SPSortie _data;
    QStringList _headers;

public :
    enum Column : char
    {
        REFERENCE,
        DESIGNATION,
        PU,
        QTE,
        COND,
        REMISE,
        TOTAL
    };
 };

class AttenteModel : public AbstractODBModel
{
    Q_OBJECT
public:

    explicit AttenteModel(QObject* parent = Q_NULLPTR);
    void setDefaultSortColumn(uint col);
    uint defaultSortColumn() const ;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section,
                        Qt::Orientation orientation = Qt::Horizontal ,
                        int role = Qt::DisplayRole) const;
    SPSortie takeAt(int pos);
    void addItem(const SPSortie&);
    void removeItem(int);
    void removeItems(const QList<int>*);
    bool isEmpty( ) {return  _data.isEmpty();}

private:
    void fetchData();

private:

    int _default_sort_column;
    QVector<SPSortie> _data;
    QStringList _headers;
    QStringList _details;

public :
    enum Column : char
    {
//        NUMERO,
//        REFERENCE,
        VENDEUR,
        CLIENT,
        REMISE,
        DATE,
        TOTAL
    };
};

//class InventoryModel : public AbstractODBModel
//{
//    Q_OBJECT
//public:
//    explicit InventoryModel(QObject* parent = Q_NULLPTR);
//    int rowCount(const QModelIndex &parent = QModelIndex()) const;
//    int columnCount(const QModelIndex &parent = QModelIndex()) const;
//    QVariant data(const QModelIndex &index, int role) const;
//    Qt::ItemFlags flags(const QModelIndex &index) const;
//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
//    QVariant headerData(int section,Qt::Orientation orientation = Qt::Horizontal , int role = Qt::DisplayRole) const;

//    void initModel(int inventorer_id = 1);
//    bool isEmpty( ) {return  _data.isNull();}
//    virtual void setDefaultSortColumn(uint){}
//    virtual uint defaultSortColumn() const { return 0 ;}

//    void addItem(const QSharedPointer<Produit>& prod , ItemQty qtes);
//    void removeItems(const QList<int>* list);
//    void removeItem(int pos);

//    int indexOf(const SPProduit &prod);
//    SPInventory reset();
//    void setInventory(const SPInventory& inventory);
//    QString inventoryContent();
//    const SPPersonnel& inventorer();
//    void save();

//private:
//    void fetchData();
//    SPInventory _data;
//    QStringList _headers;

//public :
//    enum Column : char
//    {
//        REFERENCE,
//        CODEBARRE,
//        DESIGNATION,
//        QTE_THEO_GROS,
//        QTE_THEO_DETAILS,
//        QTE_PHYS_GROS,
//        QTE_PHYS_DETAILS,
//        QTE_AJOUTE_GROS,
//        QTE_AJOUTE_DETAILS
////        MACHINE,
////        OPERATOR
//    };
// };

#endif // MODEL_H
