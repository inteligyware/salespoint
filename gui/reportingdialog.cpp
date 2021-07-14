#include "reportingdialog.h"
#include "delegates.h"
#include "datafetcherthread.h"

ReportingDialog::ReportingDialog(QWidget* parent):  QDialog(parent){
    setupUi(this);
    from_date->setDate(QDate::currentDate());
    from_date->setTime(QTime(0,0,0));
    from_date->setMaximumDate(from_date->date());

    to_date->setMinimumDateTime(from_date->dateTime());
    to_date->setMaximumDate(from_date->date());
    to_date->setDate(from_date->date());
    to_date->setTime(QTime(23,59,59));

    setUpModels();        
    connectWidgets();
}

ReportingDialog::~ReportingDialog(){
    for(auto i = strechs.size(); i > 0; i--)
        delete strechs.at(0);
}

void ReportingDialog::setUpModels(){
    proxymodel = new DateFilterProxyModel(this);
    proxymodel->setFromDate(from_date->dateTime());
    proxymodel->setToDate(to_date->dateTime());
    view_->setModel(proxymodel);
}

void ReportingDialog::resizeColumnsToContents(){
    for(auto col = 0; col != proxymodel->columnCount(); col++)
        view_->resizeColumnToContents(col);
}

void ReportingDialog::connectWidgets(){    
//    connect(cbox_query, SIGNAL(activated(int)),  SLOT(reloadData()));
    connect(search, SIGNAL(textChanged(const QString&)), proxymodel, SLOT(setFilterRegExp(const QString&)));
    connect(reload, SIGNAL(clicked(bool)), SLOT(reloadData()));
    connect(cbox_field, SIGNAL(activated(int)), SLOT(setFilterKeyColumn(int)));
    connect(from_date, SIGNAL(dateTimeChanged(QDateTime)), SLOT(resetValidToDateTime()));
    connect(go, SIGNAL(clicked(bool)), SLOT(refreshView()));
    connect(search, SIGNAL(textChanged(QString)), SLOT(displayStats()));
    connect(cbox_field, SIGNAL(activated(int)), SLOT(displayStats()));
}

void ReportingDialog::addModelFromQuery(const QString& query, const QStringList& header, const QString &title){
    listingmodels.push_back(new ListingModel(query,header,title,this));
    cbox_query->addItem(title);
}

void ReportingDialog::selectSourceModel(int pos){
    proxymodel->setSourceModel(listingmodels[pos]);
    view_->setItemDelegateForColumn(proxymodel->columnCount() - 1, new NumberDelegate(Qt::AlignRight|Qt::AlignVCenter, view_));
    resetFieldComboBox();
    resizeColumnsToContents();
    displayStats();
}

//void ReportingDialog::reloadData(){
//    auto pos = cbox_query->currentIndex();
//    listingmodels[pos]->load();
//    selectSourceModel(pos);
//}

void ReportingDialog::reloadData(){
    showProgression(-1);
    auto pos = cbox_query->currentIndex();
    qRegisterMetaType<Qt::Alignment>("Qt::Alignment");
    qRegisterMetaType<QVector<Qt::Alignment> >("QVector<Qt::Alignment>");
    auto loaderThread = new DataFetcherThread(&listingmodels[pos], pos);
    connect(loaderThread, SIGNAL(resultReady(int)), SLOT(selectSourceModel(int)));
    connect(loaderThread, SIGNAL(resultReady(int)), SLOT(showProgression(int)));
    connect(loaderThread, &DataFetcherThread::finished, loaderThread, &QObject::deleteLater);
    loaderThread->start();
    refreshView();
}

void ReportingDialog::showProgression(int pos){
    if( pos >= 0 ){
        setEnabled(true);
        QApplication::restoreOverrideCursor();
    }
    else {
        setEnabled(false);
        QApplication::setOverrideCursor(Qt::WaitCursor);
    };
}

void ReportingDialog::setAlignmentsForQuery(int queryindex , const QList<int>& columns , Qt::Alignment algnmt){
    listingmodels[queryindex]->setAlignments(columns,algnmt);
}

void ReportingDialog::setColumnsStrechForForQuery(int index , const QList<float> &strech){
    if(index == strechs.size()) strechs.push_back(new QList<float>());
    if(index >=0 && index < strechs.size())
         *strechs.at(index) = strech;
}

void ReportingDialog::showItemsCount(){
    nbitem->setText(tr("%L1 éléments ...").arg(proxymodel->rowCount()));
}

ulong ReportingDialog::total(){
    ulong sum = 0;
    for(auto row = 0 ; row != proxymodel->rowCount(); row++)
        sum += proxymodel->index(row,proxymodel->columnCount() - 1 ).data().toLongLong();
    return sum;
}

void ReportingDialog::showTotal(){
//    QVariant::Type type = proxymodel->index(0,proxymodel->columnCount() - 1 ).data().type();
//    if(type != QVariant::Int || type != QVariant::LongLong || type != QVariant::Double) return;
    total_value->setText(tr("%L1").arg(total()));
    label->setText(" F");
}

void ReportingDialog::displayStats(){
    showTotal();
    showItemsCount();
}

void ReportingDialog::refreshView(){
     proxymodel->setFromDate(from_date->dateTime());
     proxymodel->setToDate(to_date->dateTime());
     proxymodel->setFilterKeyColumn(cbox_field->currentIndex());
     resizeColumnsToContents();
     displayStats();
}

void ReportingDialog::resetValidToDateTime(){
    to_date->setMinimumDateTime(from_date->dateTime());
}

QTreeView* ReportingDialog::view(){
    return view_ ;
}

const QSortFilterProxyModel* ReportingDialog::proxyModel() const{
    return proxymodel;
}

void ReportingDialog::setFilterKeyColumn(int column){
    proxymodel->setFilterKeyColumn(column);
}

void ReportingDialog::resetFieldComboBox(){
    cbox_field->clear();
    for (auto col =  0 ; col < proxymodel->columnCount() ; col++)
        cbox_field->addItem(proxymodel->headerData( col, Qt::Horizontal, Qt::DisplayRole).toString());
}

void ReportingDialog::setDateEditsVisible(bool visible){
    debut->setVisible(visible);
    from_date->setVisible(visible);
    fin->setVisible(visible);
    to_date->setVisible(visible);
    go->setVisible(visible);
}

void ReportingDialog::setQueryComboboxVisible(bool visible){
    cbox_query->setVisible(visible);
    reload->setVisible(visible);
}

void ReportingDialog::setQueryComboboxEnabled(bool enabled){
    cbox_query->setEnabled(enabled);
}

void ReportingDialog::setFieldComboboxEnabled(bool enabled){
    cbox_field->setEnabled(enabled);
}
