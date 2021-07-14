#include "models.h"

InventoryModel::InventoryModel(QObject* parent) : AbstractODBModel(parent){
    _headers << tr("Référence")
             << tr("Code Barre")
             << tr("Désignation")
             << tr("Qte Theo. Gros")
             << tr("Qte Theo. Details")
             << tr("Qte Phys. Gros")
             << tr("Qte Phys. Details")
             << tr("Qte Ajoute. Gros")
             << tr("Qte Ajoute. Details");
    initModel();
}

void InventoryModel::fetchData(){}

QVariant InventoryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( orientation == Qt::Horizontal && role == Qt::DisplayRole )
        return _headers.at(section);

    if ( role == Qt::TextAlignmentRole && section > DESIGNATION )
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);

    return QAbstractTableModel::headerData(section, orientation, role);
}

int InventoryModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return _data->count();
}

int InventoryModel::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return  _headers.count();
}

QVariant InventoryModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()) return QVariant();
    auto record = _data->getItem(index.row());

    if( role == Qt::DisplayRole || role == Qt::EditRole)
    switch (index.column())
    {
        case REFERENCE : if (!record->getProduit()->getCodebare().isNull())
                                return record->getProduit()->getCodebare();
                         else
                                return record->getProduit()->getReference();
        case CODEBARRE : return record->getProduit()->getCodebare();
        case DESIGNATION : return record->getProduit()->getLibele();
        case QTE_THEO_GROS : return record->getQteTheoGros();
        case QTE_THEO_DETAILS : return record->getQteTheoDetails();
        case QTE_PHYS_GROS : return record->getQtePhysGros();
        case QTE_PHYS_DETAILS : return record->getQtePhysDetails();
        case QTE_AJOUTE_GROS : return record->getQteAjouteGros();
        case QTE_AJOUTE_DETAILS : return record->getQteAjouteDetails();
    }

    if ( role == Qt::TextAlignmentRole &&  (index.column() > DESIGNATION ))
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);
    return QVariant();
}

bool InventoryModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if(index.isValid() &&  role == Qt::EditRole){

        auto record = _data->getItem(index.row());
        switch (index.column())
        {
            case QTE_PHYS_GROS : record->setQtePhysGros(value.toInt()); break;
            case QTE_PHYS_DETAILS : record->setQtePhysDetails(value.toInt()); break;
            case QTE_AJOUTE_GROS :  record->setQteAjouteGros(value.toInt());  break;
            case QTE_AJOUTE_DETAILS : record->setQteAjouteDetails(value.toInt()); break;
        }      
        emit dataChanged(index , index);
        return true;
    }
    return false;
}

Qt::ItemFlags InventoryModel::flags(const QModelIndex &index) const{
    if ( index.isValid() && index.column() > QTE_THEO_DETAILS )
        return   Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
    return QAbstractItemModel::flags(index) ;
}

void InventoryModel::initModel(int saler_id){
    SPInventory tmp{NULL};
    {
        transaction t(DB->begin());
            tmp.reset (new Inventory(DB->query_one<Personnel>(odb::query<Personnel>::id == saler_id)));
        t.commit();
    }
    _data = tmp ;
}

void InventoryModel::addItem(const SPProduit &prod, ItemQty qtes)  {
    beginResetModel();
       _data->addItem(prod , qtes);
    endResetModel();
}

int InventoryModel::indexOf(const SPProduit &prod){
    return  _data->indexOf(prod);
}

void InventoryModel::removeItem(int pos){
    beginRemoveRows(QModelIndex(), pos, pos);
        _data->removeItem(pos);
    endRemoveRows();
}

void InventoryModel::removeItems(const QList<int>* list){
    beginResetModel();
        _data->removeItems(list);
    endResetModel();
}

SPInventory InventoryModel::reset(){
    SPInventory old = _data;
    beginResetModel();
        initModel();
    endResetModel();
    return old;
}

void InventoryModel::setInventory(const SPInventory& inventory){
    beginResetModel();
        _data = inventory;
    endResetModel();
}

//QString InventoryModel::inventoryContent(){
//    QString content;
//    content += QString("%1;%2;%3;%4;%5;%6;%7").arg(_headers.at(DESIGNATION),
//                                            _headers.at(QTE_THEO_GROS),
//                                            _headers.at(QTE_THEO_DETAILS),
//                                            _headers.at(QTE_PHYS_GROS),
//                                            _headers.at(QTE_PHYS_DETAILS),
//                                            _headers.at(QTE_AJOUTE_GROS),
//                                            _headers.at(QTE_AJOUTE_DETAILS));

//    foreach (auto item, _data->getItems())
//        content += QString("\n%1;%2;%3;%4;%5;%6;%7").arg(item->getProduit()->getLibele(),
//                                                    item->getQteTheoGros(),
//                                                    item->getQteTheoDetails(),
//                                                    item->getQtePhysGros(),
//                                                    item->getQtePhysDetails(),
//                                                    item->getQteAjouteGros(),
//                                                    item->getQteAjouteDetails());

//    return content;
//}

const SPPersonnel& InventoryModel::inventorer(){
    return _data->getResponsable();
}

void InventoryModel::save(){
    _data->persist(InventoryModel::DB);
}
