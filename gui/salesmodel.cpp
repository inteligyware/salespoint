#include "models.h"

SalesModel::SalesModel(QObject* parent) : AbstractODBModel(parent)
{
    _headers << tr("Référence")
             << tr("Désignation")
             << tr("Prix U.")
             << tr("Quantité")
             << tr("Conditionnement")
             << tr("Remise ( % )")
             << tr("Total");
    initModel();
}

void SalesModel::fetchData(){}

QVariant SalesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( orientation == Qt::Horizontal && role == Qt::DisplayRole )
        return _headers.at(section);

    if ( role == Qt::TextAlignmentRole &&  (section == PU  ||  section == QTE ||  section == REMISE ||  section == TOTAL ))
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);

    return QAbstractTableModel::headerData(section , orientation , role);
}

int SalesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _data->count();
}

int SalesModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  _headers.count();
}

QVariant SalesModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    auto record = _data->getDetails(index.row());

    if( role == Qt::DisplayRole || role == Qt::EditRole)
    switch (index.column())
    {

        case REFERENCE : if (!record->getProduit()->getCodebare().isNull()) return record->getProduit()->getCodebare();
                         else return record->getProduit()->getReference();
        case DESIGNATION : return record->getProduit()->getLibele();
        case PU : return  record->getProduit()->getPrixVente();
        case QTE : return record->getQte();
        case COND : return QString("");
        case REMISE : if(record->getRemise()) return record->getRemise();
                      return QString("");
        case TOTAL : return    record->getMontant();
    }

    if ( role == Qt::TextAlignmentRole &&  (index.column() == PU  ||  index.column() == QTE ||
                                            index.column() == REMISE ||  index.column() == TOTAL ))
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);
    return QVariant();
}

bool SalesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() &&  role == Qt::EditRole)
    {
      {
        switch (index.column())
        {
            case QTE : if ( value.toInt() > 0 ) _data->getDetails(index.row())->setQte(value.toInt()); break;
            case PU : _data->getDetails(index.row())->negocierPrix(value.toLongLong()); break;
            case REMISE : _data->getDetails(index.row())->setRemise(value.toFloat()); break;
        }
      }
        emit dataChanged(index , index);

        return true;
    }
    return false;
}

Qt::ItemFlags SalesModel::flags(const QModelIndex &index) const
{
    if (!index.isValid() || (index.column() != PU && index.column() != QTE && index.column() != REMISE ))
        return   Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void SalesModel::initModel(int saler_id){

    SPSortie tmp{NULL};
    {
        transaction t(DB->begin());
            tmp.reset (new Destockage(DB->query_one<Personnel>(odb::query<Personnel>::id == saler_id)));
        t.commit();
    }
    _data = tmp ;
}

void SalesModel::addItem(const SPProduit &prod , quint32 qte)  {
    beginResetModel();
       _data->addDetails(prod , qte);
    endResetModel();
}

quint32 SalesModel::getMontant(){
    if(_data.isNull()) return 0;
    else return _data->getMontant() ;
}

int SalesModel::indexOf(const SPProduit &prod){
    return  _data->indexOf(prod);
}

void SalesModel::removeItem(int pos){
    beginRemoveRows(QModelIndex() , pos, pos );
        _data->removeDetail(pos);
    endRemoveRows();
}

void SalesModel::removeItems(const QList<int>* list){
    beginResetModel();
        _data->removeDetails(list);
    endResetModel();
}

SPSortie SalesModel::reset(){
    SPSortie old = _data;
    beginResetModel();
        initModel();
    endResetModel();
    return old;
}

void SalesModel::setSale(const SPSortie& sale){
    beginResetModel();
        _data = sale;
    endResetModel();
}

QString SalesModel::salesContent(){
    QString content;
    QLocale locale;
    content += QString("%1;%2;%3;%4").arg(_headers.at(DESIGNATION),
                                            _headers.at(PU),
                                            _headers.at(QTE),
                                            _headers.at(TOTAL));

    QVariant quantity , unit_price, sub_total , total;
     foreach (auto detail, _data->getDetails())
     {
         quantity = detail->getQte();
         unit_price = detail->getProduit()->getPrixVente();
         sub_total = detail->getMontant();
         content += QString("\n%1;%2;%3;%4").arg(detail->getProduit()->getLibele(),
                                                    locale.toCurrencyString(unit_price.toLongLong(), QString(" ")).trimmed(),
                                                    locale.toCurrencyString( quantity.toInt(), QString(" ")).trimmed(),
                                                    locale.toCurrencyString( sub_total.toLongLong() , QString(" ")).trimmed());
     }
     total = _data->getMontant();
     content += QString("\n%1;%2;%3;%4").arg("Total","","", locale.toCurrencyString(total.toLongLong() , QString(" ")).trimmed());
     return content;
}

const SPPersonnel& SalesModel::saler(){
    return _data->getResponsable();
}

const SPPersonnel& SalesModel::cashier(){
    return saler();
}

void SalesModel::save(){
    _data->persist(SalesModel::DB);
}
