#include "models.h"

SPODBDatabase AbstractODBModel::DB {NULL};

AbstractODBModel::AbstractODBModel (QObject* parent): QAbstractTableModel(parent){}

bool AbstractODBModel::hasChildren(const QModelIndex &parent) const{
    return !( parent.isValid() && parent.column() == 0);
}

bool AbstractODBModel::isUnique(const QString& value, int column) const{
    Q_ASSERT(column >= 0 && column < columnCount());
    return !value.isEmpty() && match(index(0, column), Qt::DisplayRole, value, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap)).isEmpty();
}
