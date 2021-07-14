#include "models.h"

QProductModel::QProductModel(QObject* parent):QSqlQueryModel(parent)
{
    _query = "SELECT p.id idp, a.reference, p.libele , f.libele famille, prix_achat_moy, remise as remise,\
                 prix_vente, qte_colise, codebare, f.id idf, p.parent idpp , f.parent idfp, m.cip \
                 FROM produit p \
                      LEFT JOIN article a  ON p.id = a.id  \
                      LEFT JOIN medicament m  ON p.id = m.id \
                      LEFT JOIN famille f ON f.id = a.famille";

   _headers << tr("Index")
            << tr("Référence")
            << tr("Désignation")
            << tr("Famille")
            << tr("Prix Achat")
            << tr("Remise(%)")
            << tr("Prix Vente")
            << tr("Colisée")
            << tr("Code Barre")
            /*<< tr("N° Famille")
            << tr("N° Produit Parent")
            << tr("N° Famille Parent")*/;

    load();
}

QVariant QProductModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if ( role == Qt::TextAlignmentRole &&  ( section == PU_ACHAT ||  section == REMISE ||  section == PU_VENTE
                                             ||  section == QTE_COLISEE || section == CODEBARE))
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);

    return QSqlQueryModel::headerData(section , orientation , role);
}

void QProductModel::load(){
    int section = 0;
    setQuery(_query);
    for(auto& header : _headers)
        setHeaderData(section++ , Qt::Horizontal, header);
}

Qt::ItemFlags QProductModel::flags(const QModelIndex &index) const{

    Qt::ItemFlags flags = QSqlQueryModel::flags(index);

    if (index.column() > ID_PRODUIT &&  index.column() < ID_FAMILLE &&  index.column() != FAMILLE)
        flags |= Qt::ItemIsEditable;
   return flags;
}

QVariant QProductModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()) return QVariant();

    int row = index.row();
    int col = index.column();

    if( role == Qt::DisplayRole || role == Qt::EditRole)

        switch (col )
        {
            case REFERENCE :
                return !QSqlQueryModel::data(index).isNull()
                       ? QSqlQueryModel::data(index).toString()
                       : QSqlQueryModel::data(QSqlQueryModel::index(row, columnCount() - 1)).toString();

            case FAMILLE   :
                return !QSqlQueryModel::data(index).isNull()
                    ? QSqlQueryModel::data(index).toString()
                    : QString("MEDICAMENTS");
            default :
                return QSqlQueryModel::data(index,role);
        }

    if( role == Qt::ToolTipRole )
    {
        QString tooltip , title;
        QVariant value;

        for (int column = 0 ; column <  columnCount() ; column++)
        {
            switch (column)
            {
                case REFERENCE :
                    value  = ! QSqlQueryModel::index(row, REFERENCE).data().isNull()
                              ? QSqlQueryModel::index(row,REFERENCE).data()
                              : QSqlQueryModel::index(row, columnCount() - 1).data(); //We return the CIP insted we is the last colum
                break;
                case FAMILLE   :
                    value  = ! QSqlQueryModel::index(row, FAMILLE).data().isNull()
                             ? QSqlQueryModel::index(row, FAMILLE).data()
                             : QVariant("MEDICAMENTS");
                break;
                case ID_PRODUIT :   value = QSqlQueryModel::index(row, ID_PRODUIT).data();   break;
                case DESIGNATION :  value = QSqlQueryModel::index(row, DESIGNATION).data(); break;
                case PU_ACHAT :     value = QSqlQueryModel::index(row, PU_ACHAT).data(); break;
                case REMISE :       value = QSqlQueryModel::index(row, REMISE).data(); break;
                case PU_VENTE :     value = QSqlQueryModel::index(row, PU_VENTE).data(); break;
                case QTE_COLISEE :  value = QSqlQueryModel::index(row, QTE_COLISEE).data(); break;
                case CODEBARE :     value = QSqlQueryModel::index(row, CODEBARE).data(); break;

                default :
                    value.clear();
            }
            if( !value.isNull()){
                title = headerData(column , Qt::Horizontal , Qt::DisplayRole).toString();
                tooltip += QString("<tr><td><b>%1</b>: %2</td></tr>").arg(title,value.toString());
            }
        }

        qreal prix_achat_moy = QSqlQueryModel::index(index.row(), PU_ACHAT).data().toDouble();
        ulong prix_vente = QSqlQueryModel::index(index.row(), PU_VENTE).data().toLongLong();
        QVariant gain = (1 - prix_achat_moy/prix_vente)*100;
        tooltip += QString("<tr><td><b>%1</b>: %2 % </td></tr>").arg("Gain", gain.toString());
        tooltip.prepend("<table>").append("</table>");
        return tooltip;
    }

    if ( role == Qt::TextAlignmentRole &&  ( col == PU_ACHAT  ||  col == REMISE ||  col == PU_VENTE
                                             || col == QTE_COLISEE || col == CODEBARE ) )
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);

    return QSqlQueryModel::data(index,role);
}

bool QProductModel::setData(const QModelIndex &index, const QVariant &value, int /* role */ ){

    if( !index.isValid() || index.column() <= ID_PRODUIT ||  index.column() >= ID_FAMILLE)
        return false;

    ulong id = QSqlQueryModel::index(index.row(), ID_PRODUIT).data().toLongLong();

    bool update = true;
    try{
        transaction t( AbstractODBModel::DB->begin());
            SPProduit produit = AbstractODBModel::DB->load<Produit>(id);
            QSqlRecord record = QSqlQueryModel::record(index.row());
            switch (index.column()){
                case REFERENCE :
                    record.setValue(REFERENCE,value);
                    produit->setReference(value.toString());
                break;
                case DESIGNATION :
                    record.setValue(DESIGNATION,value);
                    produit->setLibele(value.toString());
                break;
//                case FAMILLE   : produit->getLibeleFamille(); break;
                case PU_ACHAT:
                    record.setValue(PU_ACHAT,value);
                    produit->setPrixAchatMoy(value.toDouble());
                break;
                case REMISE   :
                    record.setValue(REMISE,value);
                    produit->setRemise(value.toFloat());
                break;
                case PU_VENTE :
                    record.setValue(PU_VENTE,value);
                    produit->setPrixVente(value.toLongLong());
                break;
                case QTE_COLISEE :
                    record.setValue(QTE_COLISEE,value);
                    produit->setQteColise(value.toFloat());
                break;
                case CODEBARE :
                    record.setValue(CODEBARE,value);
                    produit->setCodebare(value.toString()); break;
                default : update = false;
            }

            if(update){
                AbstractODBModel::DB->update(produit);
                beginResetModel();
                    load();
                endResetModel();
            }
        t.commit();
    }
    catch( const odb::exception& e){
        qDebug() << e.what();
        return false;
    }

    return update;
}

bool QProductModel::isUnique(const QString& value, int column) const{
    Q_ASSERT(column >= 0 && column < columnCount());
    return match(index(0, column), Qt::DisplayRole, value, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap)).isEmpty();
}

//bool LargeProductModel::insertRows(int row, int count, const QModelIndex &parent){
//    return false;
//}

//bool LargeProductModel::removeRows(int row, int count, const QModelIndex &parent){
//    return false;
//}
