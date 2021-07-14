#include "models.h"

RetailableProductProxyModel::RetailableProductProxyModel(bool onlymed, QObject* parent):
    QSortFilterProxyModel(parent) , accept_med{onlymed}{
    setSortCaseSensitivity(Qt::CaseInsensitive);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortLocaleAware(true);
}

bool RetailableProductProxyModel::filterAcceptsRow(int sourceRow,const QModelIndex &sourceParent) const{

    auto model = sourceModel();
    auto idparent = model->index(sourceRow, ODBProductModel::ID_PRODUIT_PARENT).data().toLongLong();
    auto colise = model->index(sourceRow, ODBProductModel::QTE_COLISEE).data().toLongLong();
    auto famille = model->index(sourceRow, ODBProductModel::FAMILLE).data().toString();

    //Retailable if idparent == 0 && colise > 1
    if(idparent != 0 || colise <= 1 ) return false;
    if( accept_med )
         return famille.contains("Medicament", Qt::CaseInsensitive)
                 && QSortFilterProxyModel::filterAcceptsRow(sourceRow,sourceParent);
     else
         return !famille.contains("Medicament", Qt::CaseInsensitive)
                 && QSortFilterProxyModel::filterAcceptsRow(sourceRow,sourceParent);
}

//void RetailableProductProxyModel::setAcceptsOnlyMedicament(bool accept){
//    accept_med = accept;
//    accept_others = !accept;
//}

//void RetailableProductProxyModel::setAcceptsOnlyOthers(bool accept){
//    accept_others = accept;
//    accept_med = !accept;
//}
