#include "models.h"
#include "include/produits.h"

ODBProductModel::ODBProductModel(QObject* parent) : AbstractODBModel(parent){
    _headers << tr("Index")
             << tr("Référence")
             << tr("Désignation")
             << tr("Famille")
             << tr("Prix Achat")
             << tr("Remise(%)")
             << tr("Prix Vente")
             << tr("Colisée")
             << tr("Code Barre")
             << tr("N° Produit Parent")
             /*<< tr("N° Famille")
             << tr("N° Famille ParentT")*/;

    //By default, sort by column ""Désignation"
   setDefaultSortColumn(DESIGNATION);
}

void ODBProductModel::setDefaultSortColumn(uint col){
    _default_sort_column = col;
}

uint ODBProductModel::defaultSortColumn() const{
    return _default_sort_column;
}

void ODBProductModel::load(){

    using result = odb::result<Produit>;
    using query = odb::query<Produit>;

    try{
        transaction t(DB->begin());
        t.tracer (stderr_tracer);
            result res {DB->query<Produit>("ORDER BY " + query::id)};

        for( auto prod = res.begin(); prod != res.end(); prod++)
            _data.push_back(( SPProduit) prod.load());
        t.commit();
    }catch(const std::exception& e){
        qDebug() << e.what();
    }
}

QVariant ODBProductModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if( orientation == Qt::Horizontal && role == Qt::DisplayRole )
        return _headers.at(section);

    if ( role == Qt::TextAlignmentRole &&  ( section == PU_ACHAT ||  section == REMISE ||  section == PU_VENTE
                                             ||  section == QTE_COLISEE || section == CODEBARE))
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);

    return QAbstractTableModel::headerData(section , orientation , role);
}

int ODBProductModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return _data.count();
}

int ODBProductModel::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return  _headers.count();
}

QVariant ODBProductModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()) return QVariant();
    int row = index.row();
    int col = index.column();

    const SPProduit record = _data.at(row);

    if( role == Qt::DisplayRole || role == Qt::EditRole)
    switch (col)
    {
        case ID_PRODUIT : return static_cast<qulonglong> (record->getId());
        case REFERENCE : return record->getReference();
        case DESIGNATION : return record->getLibele();
        case FAMILLE   : return record->getLibeleFamille();
        case PU_ACHAT : return record->getPrixAchatMoy();
        case PU_VENTE : return record->getPrixVente();
        case REMISE   : return record->getRemise();
        case QTE_COLISEE : return record->getQteColise();
        //We should return "  ", SPACE so that we have the possibility to edit the empty barecode
        case CODEBARE : return !record->getCodebare().isEmpty() ? record->getCodebare() : QString(" ");
//        case ID_FAMILLE : return static_cast<qulonglong> (record->getId());
        case ID_PRODUIT_PARENT : {
            if(record->getParent().isNull()) return 0;
            return static_cast<qulonglong> (record->getParent()->getId());
        }
//        case ID_FAMILLE_PARENT : return static_cast<qulonglong> (record->getId());
    }

    if( role == Qt::ToolTipRole )
    {
        QString tooltip , title;
        QVariant value;

        for (int column = 0 ; column <  _headers.count() ; column++)
        {
            switch (column)
            {
                case ID_PRODUIT : value = static_cast<qulonglong> (record->getId()); break;
                case REFERENCE : value = record->getReference();                     break;
                case DESIGNATION : value = record->getLibele();                      break;
                case FAMILLE   : value = record->getLibeleFamille(); break;
                case PU_ACHAT : value = record->getPrixAchatMoy();  break;
                case REMISE   : value = record->getRemise();        break;
                case PU_VENTE : value = record->getPrixVente();     break;
                case QTE_COLISEE : value = record->getQteColise();break;
                case CODEBARE : value = record->getCodebare(); break;
//                case ID_FAMILLE : value =  static_cast<qulonglong>(record->getId());
//                case ID_PRODUIT_PARENT : value = static_cast<qulonglong> ( record->getParent()->getId());
//                case ID_FAMILLE_PARENT : value = static_cast<qulonglong> ( record->getId());

                default : value.clear();
            }

            if( !value.isNull()){
                title = headerData(column , Qt::Horizontal , Qt::DisplayRole).toString();
                tooltip += QString("<tr><td><b>%1</b>: %2</td></tr>").arg(title,value.toString());
            }
        }

        QVariant gain = record->gain();
        tooltip += QString("<tr><td><b>%1</b>: %2 % </td></tr>").arg("Gain", gain.toString());
        tooltip.prepend("<table>").append("</table>");
        return tooltip;
    }

    if ( role == Qt::TextAlignmentRole &&  ( col == PU_ACHAT  ||  col == REMISE ||  col == PU_VENTE ||
                                             col == QTE_COLISEE || col == CODEBARE ) )
        return QVariant(Qt::AlignRight | Qt::AlignVCenter);

    if ( role == Qt::BackgroundRole && record->getId() % 7 == 1)
//        return QVariant(QBrush(Qt::red));
        return QVariant(QColor(Qt::red));


    return QVariant();
}

bool ODBProductModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() &&  role == Qt::EditRole)
    {
       int col = index.column();
      {
        ulong id = this->index(index.row(), ODBProductModel::ID_PRODUIT).data().toLongLong();
        SPProduit product {NULL};

        for(auto prod : _data){
            if(prod->getId() == id){
                product = prod;
                break;
            }
        }


            switch (col)
            {
                case DESIGNATION :
                    if(!isUnique(value.toString().simplified(), DESIGNATION)) return false;
                    product->setLibele(value.toString());
                break;

                case PU_ACHAT :{
                    transaction t( DB->begin());
                        product->setPrixAchatMoy(value.toDouble(), DB);
                    t.commit();
                 }
                 break;

                case REMISE : product->setRemise(value.toFloat()); break;

                case PU_VENTE : product->setPrixVente(value.toLongLong()); break;

                case QTE_COLISEE : product->setQteColise(value.toFloat()); break;

                case CODEBARE :
                    if(!isUnique(value.toString().simplified(), CODEBARE)) return false;
                    product->setCodebare(value.toString());
                break;
            }
        transaction t( DB->begin());
            DB->update(product);
        t.commit();
      }
      emit dataChanged(index , index);
      return true;
    }
    return false;
}

Qt::ItemFlags ODBProductModel::flags(const QModelIndex &index) const
{
    if (!index.isValid() || index.column() <= REFERENCE || index.column() == FAMILLE || index.column() >= ID_PRODUIT_PARENT )
        return  Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

SPProduit ODBProductModel::getItemById(ulong id) const{
    SPProduit spproduit{NULL};
    for(auto prod : _data){
        if(prod->getId() == id){
            spproduit = prod;
            break;
        }
    }
    return  spproduit;
}

SPProduit ODBProductModel::getItemByReference(const QString& reference) const{
    SPProduit spproduit{NULL};
    auto indexlist = match(index(0, ODBProductModel::REFERENCE), Qt::DisplayRole, reference, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap));
    if(!indexlist.isEmpty()){
        auto id = data(index(indexlist.first().row(),ODBProductModel::ID_PRODUIT), Qt::DisplayRole).toLongLong();
        spproduit = getItemById(id);
    }
    return spproduit;
}

//SPProduit ODBProductModel::getItemByLabel(const QString& libele) const{
//    SPProduit spproduit{NULL};
//    auto indexlist = match(index(0, ODBProductModel::DESIGNATION), Qt::DisplayRole, libele, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap));
//    if(!indexlist.isEmpty()){
//        auto id = data(index(indexlist.first().row(),ODBProductModel::ID_PRODUIT), Qt::DisplayRole).toLongLong();
//        spproduit = getItemById(id);
//    }
//    return spproduit;
//}

SPProduit ODBProductModel::getItemByLabel(const QString& libele) const{
    SPProduit spproduit{NULL};
    auto indexlist = match(index(0, ODBProductModel::DESIGNATION), Qt::DisplayRole, libele, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap));
    if(!indexlist.isEmpty()){
        auto id = index(indexlist.first().row(), ODBProductModel::ID_PRODUIT).data().toLongLong();
        return getItemById(id);
    }
    return spproduit;
}

bool ODBProductModel::addItem(const SPProduit& spproduit){
    bool added = !spproduit.isNull();
    if( added && spproduit->getId() == 0){ //We check that the object is not persistent(id == 0)
        try{
            transaction t(DB->begin());
                DB->persist(spproduit);
            t.commit();
            beginResetModel();
                _data.push_back(spproduit);
            endResetModel();
        }catch(const odb::exception& e){
            qDebug() << e.what();
        }
    }
    return added;
}

bool ODBProductModel::removeItemsByIds(const QList<ulong> &ids){
    QVector<SPProduit> cache;
    for(auto id : ids){
        auto spproduit = getItemById(id);
        if(!spproduit.isNull()) cache.push_back(spproduit);
    }
    try{

        transaction t(DB->begin());
        beginResetModel();
        for(auto spproduit : cache){
            DB->erase(spproduit);
            _data.removeAll(spproduit);
        }
        endResetModel();
        t.commit();
    }
    catch(const odb::exception& e){
        qDebug() << e.what();
    }
    return cache.size() == ids.size();
}

bool ODBProductModel::removeItemById(ulong id){
    return removeItemsByIds(QList<ulong>() << id);
}

bool ODBProductModel::removeItemByReference(const QString& reference){
    auto spproduit = getItemByReference(reference);
    bool removed = !spproduit.isNull();
    if( removed){
        removeItemById(spproduit->getId());
    }
    return removed;
}

bool ODBProductModel::removeItemByLabel(const QString& libele){
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

bool ODBProductModel::save(){
    //To Do: We return true by default because all object here are already persistant
    return true;
}

ConstODBProductModel::ConstODBProductModel(QObject* parent): ODBProductModel(parent){
    Q_UNUSED(parent);
}

Qt::ItemFlags ConstODBProductModel::flags(const QModelIndex &index) const{
    return QAbstractItemModel::flags(index) ;
}

bool ConstODBProductModel::setData(const QModelIndex &index, const QVariant &value, int role){
    Q_UNUSED(index);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return false ;
}
