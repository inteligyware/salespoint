#include "models.h"

QVariant SalesListingModel::data(const QModelIndex &index, int role) const{

    if(!index.isValid()) return QVariant();

    if( role == Qt::ToolTipRole )
    {
        QString tip ;
        SPSortie record;
        try{
            transaction t( AbstractODBModel::DB->begin());
            QModelIndex curindex = this->index(index.row(),0);
            ulong id = QSqlQueryModel::data(curindex).toLongLong();
            record = AbstractODBModel::DB->load<Sortie>(id);
            t.commit();
            tip = "<table white-space: nowrap>";
            //Retrieving headers
            tip += QString("<tr><td><b>%1</b></td>"
                                "<td><b>%2</b></td>"
                                "<td><b>%3</b></td>"
                                "<td><b>%4</b></td>"
                                "<td><b>%5</b></td>"
                        "</tr>").arg(tr("Reference"),
                                     tr("Designation"),
                                     tr("Quantite"),
                                     tr("Prix Unitaire"),
                                     tr("Montant"));

            QVariant quantity , unit_price, sub_total , total;

            QLocale locale;
            foreach (auto id, record->getDetails())
            {
                quantity = id->getQte();
                unit_price = id->getProduit()->getPrixVente();
                sub_total = id->getMontant();


                tip += QString("<tr><td>%1</td>"
                                   "<td><i>%2</i></td>"
                                   "<td>%3</td>"
                                   "<td>%4</td>"
                                   "<td>%5</td>"
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
            tip += "</table>";
            return tip;

        }
        catch( const odb::exception& e){
            qDebug() << e.what();
            return QVariant();
        }

    }

    return ListingModel::data(index,role);
}
