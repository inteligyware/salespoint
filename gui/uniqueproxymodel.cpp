#include "models.h"
UniqueProxyModel::UniqueProxyModel(int column , QObject* parent):
        QSortFilterProxyModel(parent),COLUMN(column) {
    setSortCaseSensitivity(Qt::CaseInsensitive);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortLocaleAware(true);
}

void UniqueProxyModel::setSourceModel(QAbstractItemModel *sourceModel){
    connect(sourceModel, SIGNAL(modelReset()), SLOT(clearCache()));
    QSortFilterProxyModel::setSourceModel(sourceModel);
}

bool UniqueProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const{

    QModelIndex index = sourceModel()->index(sourceRow, COLUMN, sourceParent);
    const QString &text = sourceModel()->data(index).toString();

    //We have a duplicate row, we ignore it
    if (cache.contains(text)) return false;

    //We met the row for the first time, we cache it
    cache << text;
    return QSortFilterProxyModel::filterAcceptsRow(sourceRow,sourceParent);
}

////Filter out unretailable product
//index = sourceModel()->index(sourceRow, ODBProductModel::QTE_COLISEE, sourceParent);
//if(index.isValid()){
//    auto colise = sourceModel()->data(index).toString().toLong();
//    if (colise == 1) return false;
//}
