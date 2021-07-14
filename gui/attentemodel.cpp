#include "models.h"
#include <QDateTime>
#include <QDate>

AttenteModel::AttenteModel(QObject* parent): AbstractODBModel(parent){
    _headers /*<< tr("N°")
             << tr("Référence")*/
             << tr("Vendeur")
             << tr("Client")
             << tr("Reduction")
             << tr("Heure")
             << tr("Montant");

    _details << tr("Référence")
             << tr("Désignation")
             << tr("Quantité")
             << tr("P.U")
             << tr("Total");

    //Default sort by column "Designation"
   setDefaultSortColumn(AttenteModel::DATE);
}

void AttenteModel::setDefaultSortColumn(uint col){
    _default_sort_column = col;
}

uint AttenteModel::defaultSortColumn() const{
    return _default_sort_column;
}

void AttenteModel::fetchData(){}

QVariant AttenteModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if( orientation == Qt::Horizontal && role == Qt::DisplayRole )
        return _headers.at(section);

    if ( role == Qt::TextAlignmentRole &&  (section ==  REMISE ||   section == TOTAL ))
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);

    return QAbstractTableModel::headerData(section , orientation , role);
}

int AttenteModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _data.size();
}

int AttenteModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  _headers.count();
}

QVariant AttenteModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    const SPSortie& record = _data.at(index.row());
    QLocale locale;

    {
        if( role == Qt::DisplayRole || role == Qt::EditRole)
        switch (index.column())
        {
//            case NUMERO : return static_cast<qulonglong> (record->getId());
//            case REFERENCE : return QString("") /*record->getFacture()->getReference().toUpper()*/;
            case DATE : return record->getDate().time().toString();
            case VENDEUR : return record->getResponsable()->getNoms();
            case CLIENT : return QString("Divers");
            case REMISE : return QString("");
            case TOTAL : return record->getMontant();
        }

    }

    {

        if( role == Qt::ToolTipRole ){
            QString tip;
            //Retrieving headers
            tip += QString("<tr>< th align=left><b>%1</b></th>"
                                "<th align=left><b>%2</b></th>"
                                "<th align=right><b>%3</b></th>"
                                "<th align=right><b>%4</b></th>"
                                "<th align=right><b>%5</b></th>"
                            "</tr>").arg(_details.at(0),
                                    _details.at(1),
                                    _details.at(2),
                                    _details.at(3),
                                    _details.at(4));

            QVariant quantity , unit_price, sub_total , total;

            for(auto id : record->getDetails()){
                quantity = id->getQte();
                unit_price = id->getProduit()->getPrixVente();
                sub_total = id->getMontant();
                tip += QString("<tr><td align=left>%1</td>"
                                   "<td align=left><i>%2</i></td>"
                                   "<td align=right>%3</td>"
                                   "<td align=right >%4</td>"
                                   "<td align=right>%5</td>"
                                "</tr>").arg(id->getProduit()->getReference(),
                                            id->getProduit()->getLibele() ,
                                            quantity.toString() ,
                                             locale.toCurrencyString(unit_price.toLongLong(), QString(" ")) ,
                                             locale.toCurrencyString(sub_total.toLongLong() , QString(" ")));
            }

            total = record->getMontant();
            tip += QString("<tr></tr>"
                           "<tr><td><b>%1</b></td>"
                                "<td><b>%2</b></td>"
                                "<td><b>%3</b></td>"
                                "<td><b>%4</b></td>"
                                "<td><b>%5</b></td>"
                            "</tr>").arg("Total","", "", "",locale.toCurrencyString(record->getMontant(), QString(" ")));
            tip.prepend("<table cellspacing = 10 white-space=nowrap>").append("</table>");
            return tip;
        }
    }

    int section = index.column();
    if ( role == Qt::TextAlignmentRole &&  (section ==  REMISE ||  section == TOTAL ))
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);

    return QVariant();
}

SPSortie AttenteModel::takeAt(int pos){
   beginResetModel();
     SPSortie tmp = _data.takeAt(pos);
   endResetModel();
   return tmp;
}

void AttenteModel::addItem(const SPSortie& sortie){
    beginResetModel();
    _data.push_back(sortie);
    endResetModel();
}

void AttenteModel::removeItem(int pos){
    QList<int> list;
    list.append(pos);
    removeItems(&list);
}

void AttenteModel::removeItems(const QList<int>* list){

    bool valid = ( list->at(0) >= 0 && list->at(list->size() -1) < _data.size());

    beginResetModel();
        if(valid){
            QList<SPSortie>* sps = new QList<SPSortie>;
            foreach(int pos , *list) sps->append(_data[pos]);
            foreach (auto sp, *sps) _data.removeOne(sp);
            delete sps;
        }
    endResetModel();
}
