#include "models.h"
#include "include/produits.h"

ODBFamilyModel::ODBFamilyModel(QObject* parent) : AbstractODBModel(parent){
    _headers << tr("Index")
             << tr("Référence")
             << tr("Désignation")
             << tr("Description");

    //By default, sort by column ""Désignation"
   setDefaultSortColumn(DESIGNATION);
}

void ODBFamilyModel::setDefaultSortColumn(uint col){
    _default_sort_column = col;
}

uint ODBFamilyModel::defaultSortColumn() const{
    return _default_sort_column;
}

void ODBFamilyModel::load(){
    using result = odb::result<Famille>;
    using query = odb::query<Famille>;
    try{
        transaction t(DB->begin());
        t.tracer (stderr_tracer);
            result res {DB->query<Famille>("ORDER BY " + query::libele)};

        for( auto famille = res.begin(); famille != res.end(); famille++)
            _data.push_back(( SPFamille) famille.load());
        t.commit();
    }catch(const std::exception& e){
        qDebug() << e.what();
    }
}

QVariant ODBFamilyModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if( orientation == Qt::Horizontal && role == Qt::DisplayRole )
        return _headers.at(section);
    return QAbstractTableModel::headerData(section, orientation, role);
}

int ODBFamilyModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return _data.count();
}

int ODBFamilyModel::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return  _headers.count();
}

QVariant ODBFamilyModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()) return QVariant();
    int row = index.row();
    int col = index.column();

    const SPFamille record = _data.at(row);

    if( role == Qt::DisplayRole || role == Qt::EditRole)
    switch (col){
        case ID : return static_cast<qulonglong> (record->getId());
        case REFERENCE : return record->getReference();
        case DESIGNATION : return record->getLibele();
        case DESCRIPTION   : return record->getDescription();
    }

    if( role == Qt::ToolTipRole )
    {
        QString tooltip , title;
        QVariant value;

        for (int column = 0 ; column <  _headers.count() ; column++)
        {
            switch (column)
            {
                case ID : value = static_cast<qulonglong> (record->getId()); break;
                case REFERENCE : value = record->getReference();             break;
                case DESIGNATION : value = record->getLibele();              break;
                case DESCRIPTION   : value = record->getDescription();       break;

                default : value.clear();
            }

            if( !value.isNull()){
                title = headerData(column , Qt::Horizontal , Qt::DisplayRole).toString();
                tooltip += QString("<tr><td><b>%1</b>: %2</td></tr>").arg(title,value.toString());
            }
        }

        tooltip.prepend("<table>").append("</table>");
        return tooltip;
    }

    if ( role == Qt::TextAlignmentRole)
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);

    return QVariant();
}

bool ODBFamilyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int col = -1;
    if(index.isValid() &&  role == Qt::EditRole)
    {
       col = index.column();

        ulong id = this->index(index.row(), ODBFamilyModel::ID).data().toLongLong();
        SPFamille spfamille = getItemById(id);

        switch(col){
            case DESIGNATION :
              if(!isUnique(value.toString().simplified(), DESIGNATION)) return false;
                  spfamille->setLibele(value.toString());
            break;
            case DESCRIPTION : spfamille->setDescription(value.toString()); break;
        }
        try{
            transaction t( DB->begin());
                if(col == DESIGNATION || col == DESCRIPTION ) DB->update(spfamille);
            t.commit();
            emit dataChanged(index, index);
        }catch(const odb::exception& e){
                qDebug() << e.what();
        }
    }
    return col == DESIGNATION || col == DESCRIPTION ;
}

Qt::ItemFlags ODBFamilyModel::flags(const QModelIndex &index) const
{
    if (!index.isValid() || index.column() <= REFERENCE )
        return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

SPFamille ODBFamilyModel::getItemById(ulong id) const{
    SPFamille famille{NULL};
    for(auto fam : _data){
        if(fam->getId() == id){
            famille = fam;
            break;
        }
    }
    return  famille;
}

SPFamille ODBFamilyModel::getItemByReference(const QString& reference) const{
    SPFamille spfamile{NULL};
    auto indexlist = match(index(0, ODBFamilyModel::REFERENCE), Qt::DisplayRole, reference, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap));
    if(!indexlist.isEmpty()){
        auto id = data(index(indexlist.first().row(),ODBFamilyModel::ID), Qt::DisplayRole).toLongLong();
        spfamile = getItemById(id);
    }
    return spfamile;
}

SPFamille ODBFamilyModel::getItemByLabel(const QString& libele) const{
    SPFamille spfamile{NULL};
    auto indexlist = match(index(0, ODBFamilyModel::DESIGNATION), Qt::DisplayRole, libele, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap));
    if(!indexlist.isEmpty()){
        auto id = data(index(indexlist.first().row(),ODBFamilyModel::ID), Qt::DisplayRole).toLongLong();
        spfamile = getItemById(id);
    }
    return spfamile;
}

bool ODBFamilyModel::addItem(const SPFamille& spfamille){
    bool added = !spfamille.isNull();
    if( added && spfamille->getId() == 0){ //We check that the object is not persistent(id == 0)
        try{
            transaction t(DB->begin());
                DB->persist(spfamille);
            t.commit();
            beginResetModel();
                _data.push_back(spfamille);
            endResetModel();
        }catch(const odb::exception& e){
            qDebug() << e.what();
        }
    }
    return added;
}

bool ODBFamilyModel::removeItemsByIds(const QList<ulong> &ids){
    QVector<SPFamille> cache;
    for(auto id : ids){
        auto spfamille = getItemById(id);
        if(!spfamille.isNull()) cache.push_back(spfamille);
    }
    try{

        transaction t(DB->begin());
        beginResetModel();
        for(auto spfamille : cache){
            DB->erase(spfamille);
            _data.removeAll(spfamille);
        }
        endResetModel();
        t.commit();
    }
    catch(const odb::exception& e){
        qDebug() << e.what();
    }
    return cache.size() == ids.size();
}

bool ODBFamilyModel::removeItemById(ulong id){
    return removeItemsByIds(QList<ulong>() << id);
}

bool ODBFamilyModel::removeItemByReference(const QString& reference){
    auto spfamile = getItemByReference(reference);
    bool removed = !spfamile.isNull();
    if( removed){
        removeItemById(spfamile->getId());
    }
    return removed;
}

bool ODBFamilyModel::removeItemByLabel(const QString& libele){
    auto spfamille = getItemByLabel(libele);
    auto removed = !spfamille.isNull();
    if( removed){
        try{
        transaction t(DB->begin());
        beginResetModel();
            DB->erase(spfamille);
        endResetModel();
        t.commit();
         _data.removeAll(spfamille);
        }catch(const odb::exception& e){
            qDebug() << e.what();
        }
    }
    return removed;
}

bool ODBFamilyModel::save(){
    return true;
}
