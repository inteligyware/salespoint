#ifndef REPORTINGDIALOG_H
#define REPORTINGDIALOG_H

#include "ui_reportingdialog.h"
#include "models.h"
#include "views.h"

#include <QWidget>

class ReportingDialog : public QDialog , private Ui::ReportingDialog{
    Q_OBJECT
public:
    ReportingDialog(QWidget *parent = 0);
    ~ReportingDialog();
    void addModelFromQuery(const QString& query, const QStringList& header, const QString &title);
    void setAlignmentsForQuery(int queryindex, const QList<int>& columns , Qt::Alignment algnmt = Qt::AlignRight | Qt::AlignVCenter);
    void setDateEditsVisible(bool visible);
    void setQueryComboboxVisible(bool visible);
    void setQueryComboboxEnabled(bool enabled);
    void setFieldComboboxEnabled(bool enabled);

    void setColumnsStrechForForQuery(int index, const QList<float>& strech);

    QTreeView* view();
    const QSortFilterProxyModel* proxyModel() const ;

private:
    void setUpModels();
    void resetFieldComboBox();
    void connectWidgets();
    void resizeColumnsToContents();
    void showItemsCount();
    void showTotal();

public slots:
    void setFilterKeyColumn(int column);

private slots:
    void displayStats();
    void selectSourceModel(int pos);
    void showProgression(int pos);
    void reloadData();
    ulong total();
    void refreshView();
    void resetValidToDateTime();

private:
    QList<QList<float>*> strechs;
    DateFilterProxyModel* proxymodel;
    ListingModel* listingmodel;
    QVector<ListingModel*> listingmodels;
};

#endif // REPORTINGDIALOG_H
