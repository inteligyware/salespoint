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

#include "include/produits.h"
#include "include/ventes.h"

using namespace odb::core;
using SPODBDatabase = QSharedPointer<odb::database>;

class QObject;
class QAbstractTableModel;

class ProxyModel : public QSortFilterProxyModel{
    Q_OBJECT
public:
    explicit ProxyModel(QObject *parent = Q_NULLPTR): QSortFilterProxyModel(parent){}
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const;
};

class IAbstractDataModel : public QAbstractTableModel{
    Q_OBJECT

public:
    static SPODBDatabase DB;
public :
    explicit IAbstractDataModel (QObject* parent = Q_NULLPTR);
    virtual void setDefaultSortColumn(uint col) = 0;
    virtual uint defaultSortColumn() const = 0;
    virtual bool hasChildren(const QModelIndex &parent) const;
};

class ProduitModel : public IAbstractDataModel
{
    Q_OBJECT
public:

    explicit ProduitModel(QObject* parent = Q_NULLPTR);
    void setDefaultSortColumn(uint col);
    uint defaultSortColumn() const ;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
//    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
//    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    QVariant headerData(int section,Qt::Orientation orientation = Qt::Horizontal,int role = Qt::DisplayRole) const;
    const SPProduit& at(int pos) const;

private:
    void fetchData();
    void loadCSV(QString filename);
    bool storeCSV();

    using value_type = QVector<SPProduit>;
    uint _default_sort_column;
    value_type _data ;
    QStringList _headers;

public:
    enum Column : char
    {
        NUMERO,
        REFERENCE,
        DESIGNATION,
        PU_ACHAT,
        PU_VENTE,
        CODEBARE
    };
 };

class ConstProduitModel : public ProduitModel{
public:
    explicit ConstProduitModel(QObject* parent = Q_NULLPTR);
    Qt::ItemFlags flags(const QModelIndex &index) const final ;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) final ;
};

class SortieModel : public IAbstractDataModel
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

class SalesModel : public IAbstractDataModel
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

    void initModel(int id = 1);
    bool isEmpty( ) {return  _data.isNull();}
    virtual void setDefaultSortColumn(uint){}
    virtual uint defaultSortColumn() const { return 0 ;}

//    void addItem(const QSharedPointer<DetailsSortie>& detail);
    void addItem(const QSharedPointer<Produit>& prod , quint32 qte = 1);
    void removeItems(const QList<int>* list);
    void removeItem(int pos);
//    void removeItems(const spDetails& items);
    quint32 getMontant();

    int indexOf(const SPProduit &prod);
    SPSortie reset();
    void setSale(const SPSortie&);
    QString salesContent();


    //    bool insertRows(int row, int count, const QModelIndex &parent);
    //    bool removeRows(int row, int count, const QModelIndex &parent);

private:
    void fetchData();
    QSharedPointer<Sortie> _data;
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

class AttenteModel : public IAbstractDataModel
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
    QVector<SPSortie> _data ;
    QStringList _headers;
    QStringList _details;

public :
    enum Column : char
    {
        NUMERO,
        REFERENCE,
        VENDEUR,
        CLIENT,
        REMISE,
        DATE,
        TOTAL
    };
};
#endif // MODEL_H
