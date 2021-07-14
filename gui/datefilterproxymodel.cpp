#include "models.h"
#include <QDateTime>

DateFilterProxyModel::DateFilterProxyModel(QObject *parent, const QDateTime& from_date, const QDateTime& to_date)
    : QSortFilterProxyModel(parent),_from_date{from_date}, _to_date{to_date}
{
    setSortCaseSensitivity(Qt::CaseInsensitive);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setSortLocaleAware(true);
}

void DateFilterProxyModel::setSourceModel(QAbstractItemModel *sourcemodel){
    COLUMN_DATE = -1;
    for(auto col = 0 ; col != sourcemodel->columnCount() ; col++){
        QVariant value =  sourcemodel->data(sourcemodel->index(0 , col));
        if(value.type() == QVariant::Date || value.type() == QVariant::DateTime || value.type() == QVariant::Time){
            COLUMN_DATE = col;
            break;
        }
    }
    invalidate();
    QSortFilterProxyModel::setSourceModel(sourcemodel);
    isSourceModelSet = true;
}

bool DateFilterProxyModel::isUnique(const QString& value, int column) const{
    Q_ASSERT(column >= 0 && column < columnCount());
    return match(index(0, column), Qt::DisplayRole, value, 1, Qt::MatchFlags(Qt::MatchFixedString|Qt::MatchWrap)).isEmpty();
}

bool DateFilterProxyModel::modelHasDateField(){
   return  isSourceModelSet && COLUMN_DATE != -1  ;
}

bool DateFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const{
    if (COLUMN_DATE == -1)  return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);

    QModelIndex index = sourceModel()->index(source_row , COLUMN_DATE, source_parent);
    QDateTime current = sourceModel()->data(index).toDateTime();
    return  current >= _from_date && current <= _to_date  && QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent) ;
}

void DateFilterProxyModel::setFromDate(const QDateTime& from_date){
    _from_date = from_date;
    _from_date.setTime(QTime(_from_date.time().hour(),_from_date.time().minute()));
}

void DateFilterProxyModel::setToDate(const QDateTime& to_date){
    _to_date = to_date;
    _to_date.setTime(QTime(_to_date.time().hour(),_to_date.time().minute(),59,999));
}

const QDateTime& DateFilterProxyModel::fromDate() const{
    return _from_date;
}

const QDateTime& DateFilterProxyModel::toDate() const{
    return _to_date;
}
