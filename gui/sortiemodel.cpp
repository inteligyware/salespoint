#include "models.h"
#include <QDateTime>

SortieModel::SortieModel(QObject* parent)
    : AbstractODBModel(parent)
{

    _headers << tr("N°")
             << tr("Reference")
             << tr("Date")
             << tr("Seller")
             << tr("Customer")
             << tr("Rate")
             << tr("Amount");

    _details << tr("Ref")
             << tr("Designation")
             << tr("Qty")
             << tr("U.P")
             << tr("Total");

    //Default sort by column "Designation"
   setDefaultSortColumn(2);

   {
      transaction t( DB->begin());
        t.tracer (stderr_tracer);
        fetchData();
      t.commit();
   }
}

void SortieModel::setDefaultSortColumn(uint col)
{
    _default_sort_column = col;
}

uint SortieModel::defaultSortColumn() const
{
    return _default_sort_column;
}

void SortieModel::fetchData()
{
    using Query = odb::query<EchangeSortie>;
    using Result = odb::result<EchangeSortie>;
    Result res {DB->query<EchangeSortie>( Query::id <= 500)};

    for( auto i_res = res.begin() ; i_res != res.end() ; ++i_res )
        _data.push_back(( QSharedPointer<EchangeSortie>) i_res.load());
}

QVariant SortieModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( orientation == Qt::Horizontal && role == Qt::DisplayRole )
        return _headers.at(section);
    return QAbstractTableModel::headerData(section , orientation,role);
}

int SortieModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _data.count();
}

int SortieModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  _headers.count();
}

QVariant SortieModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    const QSharedPointer<EchangeSortie> record = _data.at(index.row());

    {
      transaction t (DB->begin());
      t.tracer (stderr_tracer);
        if( role == Qt::DisplayRole || role == Qt::EditRole)
        switch (index.column())
        {
            case N : return static_cast<qulonglong> (record->getId());
            case Reference : return record->getFacture()->getReference().toUpper();
            case Date : return record->getDate();
            case Seller : return record->getResponsable()->getNoms();
            case Customer : return record->getFournisseur().load()->getNom();
            case Reduction : return record->getTauxInteret();
            case Amount : return record->getMontant();
        }
        t.commit();
    }

    {

        transaction t( DB->begin());
        t.tracer (stderr_tracer);
        if( role == Qt::ToolTipRole )
        {
            QString tip ;

            tip = "<table>";
            tip += QString("<tr><td><b>%1</b></td>"
                                "<td><b>%2</b></td>"
                                "<td><b>%3</b></td>"
                                "<td><b>%4</b></td>"
                                "<td><b>%5</b></td>"
                        "</tr>").arg(_details.at(0) ,
                                    _details.at(1) ,
                                    _details.at(2) ,
                                    _details.at(3) ,
                                    _details.at(4));

            QVariant quantity , unit_price, sub_total , total;
//            for ( auto id  = record->getDetails().begin() ; id != record->getDetails().end() ; id++ )
            foreach (auto id, record->getDetails())
            {
                quantity = id->getQte();
                unit_price = id->getProduit()->getPrixVente();
                sub_total = id->getMontant();

                tip += QString("<tr><td>%1</td>"
                                   "<td><i>%2</i></td>"
                                   "<td><i>%3</i></td>"
                                   "<td><i>%4</i></td>"
                                   "<td><i>%5</i></td>"
                                "</tr>").arg(id->getProduit()->getReference(),
                                            id->getProduit()->getLibele() ,
                                            quantity.toString() ,
                                            unit_price.toString() ,
                                            sub_total.toString());
            }

            total = record->getMontant();
            tip += QString("<tr></tr>"
                           "<tr><td><b>%1</b></td>"
                                "<td><b>%2</b></td>"
                                "<td><b>%3</b></td>"
                                "<td><b>%4</b></td>"
                                "<td><b>%5</b></td>"
                            "</tr>").arg("Total",
                                            "",
                                            "",
                                            "",
                                            total.toString());
            tip += "</table>";
            return tip;
        }
        t.commit();
    }

    if ( role == Qt::TextAlignmentRole &&  index.column() >= 5 )
        return Qt::AlignRight;
    return QVariant();
}

//bool SortieModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if(index.isValid() &&  role == Qt::EditRole )
//    {
//        switch (index.column())
//        {
//            case 1 : _data[index.row()]->setReference(value.toString());
//            break;

//            case 2 : _data[index.row()]->setLibele(value.toString());
//            break;

//            case 3 :
//                     {
//                       transaction t( _db->begin());
//                            _data[index.row()]->setPrixAchatMoy(value.toInt() , _db);
//                       t.commit();
//                     }
//            break;
//        }

//        {
//             transaction t( _db->begin());
//                 _db->update(_data[index.row()]);
//             t.commit();
//        }
//        emit dataChanged(index , index);
//        return true;
//    }
//    return false;
//}

//Qt::ItemFlags SortieModel::flags(const QModelIndex &index) const
//{
//    if (!index.isValid() || index.column() == 0 || index.column() == 4 )
//        return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;
//    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
//}

//bool SortieModel::insertRows(int row, int count, const QModelIndex &parent)
//{
//    Q_UNUSED(parent);

//   QSharedPointer<EchangeSortie> record ;

//    beginInsertRows(QModelIndex() , row , row + count -1 );
//         _data.insert( _data.begin() + row, record);
//    endInsertRows();
//    return true;
//}

//bool SortieModel::removeRows(int row, int count, const QModelIndex &parent)
//{
//    Q_UNUSED(parent);
//    if (row - count - 1 > _data.count() - 1) return false;
//    beginRemoveRows(QModelIndex() , row , row + count - 1);
//    for(int i = 0 ; i < count ; i++)
//        _data.removeAt( row + 1 );
//    endRemoveRows();
//    return true;
//}
