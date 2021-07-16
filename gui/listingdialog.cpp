#include "views.h"
#include "models.h"
#include "productcreationform.h"

#include <QAbstractItemModel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTableView>
#include <QTreeView>
#include <QHeaderView>
#include <QLabel>
#include <QWidget>
#include <QStyledItemDelegate>
#include <QScrollBar>
#include <QResizeEvent>
#include <QAction>

const int ListingDialog::WIDTH = 100;
const int ListingDialog::HEIGT = 400;

ListingDialog::ListingDialog(QAbstractItemModel *model , int defaultsortcolumn , QWidget *parent ) : QDialog(parent), SORT_COLUMN{defaultsortcolumn}
{

    setProxyModel(model);
    createWidgets();
    layoutWidgets();
    setupHead(model);

    int width_ = setupBody(model) + WIDTH;
    setupTail();

    resize(width_ , HEIGT);
    setMinimumSize(0.45*width_, HEIGT);
    setVisibleGroupBox(false);
    setVisibleSearches(false);
    showItemsCount();
    connectWidgets();
 }

void ListingDialog::setFilterKeyColumn(int col){
    proxymodel->setFilterKeyColumn(col);
}

void ListingDialog::showItemsCount(){
    lbl_count->setText(tr("%L1 éléments ...").arg(proxyModel()->rowCount()));
}

void ListingDialog::enableButtons(){
     pbtn_delete->setEnabled(view()->selectionModel()->hasSelection());
     pbtn_open->setEnabled(view()->selectionModel()->selectedRows().size() == 1);
     pbtn_new->setEnabled(!pbtn_delete->isEnabled());
}

void ListingDialog::createWidgets(){
    mainlay_ = new QVBoxLayout(this) ;
    toplay_ = new QHBoxLayout ;
    midletoplay_ = new QHBoxLayout;
    midlelay_ = new QHBoxLayout;
    bottomlay_ = new QHBoxLayout;

    box_ = new QGroupBox;
    ledit_search = new QLineEdit ;
    cbox_field = new QComboBox;

    related_product_ = new QLabel(tr("Produit Dérivé"));
    family_ = new QLabel(tr("Famille Associée"));
    cbxrelated_product_ = new QComboBox;
    cbxfamily_ = new QComboBox;

    treeview = new QTreeView ;

    for(int i = 0 ; i < proxyModel()->columnCount() ; i++)
        searchs_.push_back(new QLineEdit);

    pbtn_open = new QPushButton(tr("&Détails"));
    pbtn_open->setEnabled(false);

    pbtn_new = new QPushButton(tr("&Nouveau"));

    pbtn_delete = new QPushButton(tr("&Supprimer"));
    pbtn_delete->setEnabled(false);

    pbtn_close = new QPushButton(tr("&Fermer"));
    lbl_count = new QLabel;
}

void ListingDialog::layoutWidgets(){

    QSizePolicy szplcy_family(QSizePolicy::Expanding, QSizePolicy::Fixed);
    szplcy_family.setHorizontalStretch(1);
    szplcy_family.setHeightForWidth(cbxrelated_product_->sizePolicy().hasHeightForWidth());
    cbxrelated_product_->setSizePolicy(szplcy_family);
    cbxfamily_->setSizePolicy(szplcy_family);

    toplay_->setSpacing(0);
    toplay_->addWidget(related_product_);
    toplay_->addSpacing(5);
    toplay_->addWidget(cbxrelated_product_);
    toplay_->addSpacing(25);
    toplay_->addWidget(family_);
    toplay_->addSpacing(5);
    toplay_->addWidget(cbxfamily_);

    midletoplay_->addWidget(ledit_search);
    midletoplay_->addWidget(cbox_field);

    midlelay_->setSpacing(0);
    for(auto widget : searchs_)
        midlelay_->addWidget(widget);

    bottomlay_->addWidget(lbl_count);
    bottomlay_->addStretch();
    bottomlay_->addWidget(pbtn_open);
    bottomlay_->addSpacing(10);
    bottomlay_->addWidget(pbtn_new);
    bottomlay_->addSpacing(10);
    bottomlay_->addWidget(pbtn_delete);
    bottomlay_->addWidget(pbtn_close);

    box_->setLayout(toplay_);
    mainlay_->setSpacing(0);
    mainlay_->addWidget(box_);
    mainlay_->addLayout(midletoplay_);
    mainlay_->addLayout(midlelay_);
    mainlay_->addWidget(treeview);
    mainlay_->addSpacing(9);
    mainlay_->addLayout(bottomlay_);
}

void ListingDialog::setProxyModel(QAbstractItemModel *model){
    proxymodel->setSourceModel(model);
    proxymodel->setSortCaseSensitivity(Qt::CaseInsensitive);
    proxymodel->setFilterCaseSensitivity(Qt::CaseInsensitive);
}

void ListingDialog::setupHead(QAbstractItemModel *model ){

    head_.push_back(ledit_search);
    head_.push_back(cbox_field);
    enableHeadItem(CBOX, false);

    ledit_search->setPlaceholderText(tr("Recherche"));
    for ( int col { 0 } ; col < model->columnCount() ; col++)
        cbox_field->addItem(model->headerData( col, Qt::Horizontal, Qt::DisplayRole).toString());

    cbox_field->setCurrentIndex(SORT_COLUMN);
    setFilterKeyColumn(SORT_COLUMN);
}

int ListingDialog::setupBody(QAbstractItemModel *model){
    treeview->setAlternatingRowColors(true);
    treeview->setModel(proxymodel);
    treeview->setSortingEnabled(true);
    treeview->setRootIsDecorated(false);
    treeview->setTabKeyNavigation(true);
    treeview->setSelectionMode(QAbstractItemView::ExtendedSelection);
    treeview->setTextElideMode(Qt::ElideMiddle);
    treeview->setIndentation(25);
    treeview->setUniformRowHeights(true);
    treeview->setAnimated(true);

    int width = 0;
    for ( int col = 0  ; col < model->columnCount() ; col++){
        treeview->resizeColumnToContents(col);
        width += treeview->header()->sectionSize(col);
    }

    treeview->header()->setSortIndicator(SORT_COLUMN, Qt::AscendingOrder);
    treeview->sortByColumn(SORT_COLUMN);
    return width;
}

void ListingDialog::setupTail(){
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    lbl_count->setFont(font);

    tail_.push_back(pbtn_open);
    tail_.push_back(pbtn_new);
    tail_.push_back(pbtn_delete);
    tail_.push_back(pbtn_close);
    setVisibleTail(false);
}

void ListingDialog::connectWidgets(){
    connect(ledit_search, SIGNAL(textChanged(const QString&)), proxymodel, SLOT(setFilterRegExp(const QString&)));
    connect(cbox_field, SIGNAL(activated(int)), SLOT(setFilterKeyColumn(int)));
    connect(ledit_search, SIGNAL(textChanged(const QString&)), SLOT(showItemsCount()));
    connect(cbox_field, SIGNAL(activated(int)),  SLOT(showItemsCount()));

    connect(treeview->header(), SIGNAL(sectionResized(int,int,int)), this, SLOT(resizeSearchItem(int)));
    connect(treeview->header(), SIGNAL(sectionMoved(int,int,int)), this, SLOT(moveSearchItem(int, int, int)));
    connect(treeview->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), SLOT(enableButtons()));

    connect(pbtn_close, SIGNAL(clicked(bool)), SLOT(close()));
    connect(pbtn_new, SIGNAL(clicked(bool)), SLOT(addItem()));
    connect(pbtn_open, SIGNAL(clicked(bool)), SLOT(showItem()));
    connect(pbtn_delete, SIGNAL(clicked(bool)), SLOT(removeItems()));
}

QTreeView*  ListingDialog::view(){
    return treeview ;
}

const QSortFilterProxyModel* ListingDialog::proxyModel() const{
    return proxymodel ;
}

QAbstractItemModel* ListingDialog::sourceModel(){
    return proxymodel->sourceModel() ;
}

void ListingDialog::setVisibleHead(bool visible){
  for( int i = 0 ; i != head_.size() ; i++)
      head_[i]->setVisible(visible);
}

void ListingDialog::setVisibleSearches(bool visible){
    for(auto& widget : searchs_) widget->setVisible(visible);
}

void ListingDialog::setVisibleGroupBox(bool visible){
    box_->setVisible(visible);
}

void ListingDialog::enableHeadItem(int item, bool enabled){
    head_[item]->setEnabled(enabled);
}

void ListingDialog::setVisibleTail(bool visible){
    for( int i = 0 ; i != tail_.size() ; i++)
        tail_[i]->setVisible(visible);
}

void ListingDialog::enableTailItem(int item, bool enabled){
    tail_[item]->setEnabled(enabled);
}

void ListingDialog::removeComboboxItem(int index){
    cbox_field->removeItem(index);
}

void ListingDialog::setCurrentIndex(int index){
    cbox_field->setCurrentIndex(index);
    emit cbox_field->activated(index);
}

void ListingDialog::setColumnHidden(int col, bool hide){
     treeview->setColumnHidden(col,hide);
     searchs_.at(col)->setHidden(hide);
}

void ListingDialog::setVisibleTailItem(int item, bool visible){
    if ( item >= 0 && item < tail_.size())
        tail_[item]->setVisible(visible);
}

void ListingDialog::resizeEvent(QResizeEvent* event){
    if(event){
        for(auto col = 0 ; col != proxyModel()->sourceModel()->columnCount() ; ++col){
            treeview->resizeColumnToContents(col);
            resizeSearchItem(col);
         }
         QDialog::resizeEvent(event);
    }
}

void ListingDialog::resizeSearchItem(int col){
    searchs_.at(col)->setMinimumWidth(treeview->columnWidth(col));
    searchs_.at(col)->setMaximumHeight(treeview->header()->height());
}

void ListingDialog::moveSearchItem(int /*section*/ ,int odlposition ,int newposition){
    toplay_->replaceWidget(searchs_.at(odlposition),searchs_.at(newposition));
}

void ListingDialog::disableEscape(){
    QAction *escape;
    escape = new QAction(this);
    escape->setShortcut(tr("Esc"));
    connect(escape, SIGNAL(triggered(bool)),this , SLOT(update()));
}
