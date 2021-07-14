#include "salesdialog.h"
#include <iostream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include <QMessageBox>
#include "delegates.h"
#include "toolkit.h"

SalesDialog::SalesDialog(QAbstractItemModel *productmodel, QWidget *parent):QDialog(parent), SIZEMIN(QSize(970,500)){
    setupUi(this);
    createProductDialog(productmodel);
    addActions(QList<QAction*>() << actn_add_ << actn_delete_ << actn_full_screen_ << actn_list_ << actn_validate_ << actn_contiue_saling_);

    salesmodel = new SalesModel(this);
    attentemodel = new AttenteModel(this);
    lbl_nom_caissier_->setText(salesmodel->cashier()->getPrenoms());
    cbx_vendeur_->addItem(salesmodel->saler()->getPrenoms());

    salesproxymodel = new DateFilterProxyModel(this);
    attenteproxymodel = new DateFilterProxyModel(this);

    attenteproxymodel->setSourceModel(attentemodel);
    tview_en_attente_->setModel(attenteproxymodel);

    salesproxymodel->setSourceModel(salesmodel);
    tview_details_->setModel(salesproxymodel);

    tview_details_->setSortingEnabled(true);
    tview_details_->sortByColumn(SalesModel::COND);

    tview_en_attente_->setSortingEnabled(true);

    QAbstractItemDelegate* numberDelegate =  new NumberDelegate(Qt::AlignRight|Qt::AlignVCenter, this);
    tview_details_->setItemDelegateForColumn(SalesModel::PU, numberDelegate);
    tview_details_->setItemDelegateForColumn(SalesModel::TOTAL, numberDelegate);
    tview_en_attente_->setItemDelegateForColumn(AttenteModel::TOTAL, numberDelegate);

    tview_details_->hideColumn(SalesModel::COND);
    tview_details_->hideColumn(SalesModel::REFERENCE);
    tview_en_attente_->hideColumn(AttenteModel::VENDEUR);
    tview_en_attente_->hideColumn(AttenteModel::REMISE);

    tview_en_attente_->setVisible(false);
    hspcr_bottom_->changeSize(this->size().width() , 1 , QSizePolicy::Maximum);

    lbl_a_rendre_valeur_->clear();
    lbl_a_rendre_valeur_->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    ledit_reference_->setValidator(new QRegExpValidator(QRegExp("([0-9]*d*[a-z]*[A-Z]*)*") , ledit_reference_));

//    ledit_client_->setHidden(true);
//    pbtn_search_->setHidden(true);

    bool disabled = true;
    ledit_percu_->setDisabled(disabled);
    pbtn_hold_->setDisabled(disabled);
    pbtn_validate_->setDisabled(disabled);
    pbtn_cancel_->setDisabled(disabled);

    setMinimumSize(SIZEMIN);
    updateTotal();
    connectWidgets();
    waitForNextCodeBare();
}

SalesDialog::~SalesDialog(){}

void SalesDialog::createProductDialog(QAbstractItemModel *pmodel){
    productdlg = new ListingDialog(pmodel ,  QProductModel::DESIGNATION , this );
    productdlg->setWindowTitle(tr("Listing des Articles"));

    productdlg->setColumnHidden(ConstODBProductModel::ID_PRODUIT,true);
    for( int col = ODBProductModel::ID_PRODUIT_PARENT ; col < pmodel->columnCount() ; col++)
        productdlg->setColumnHidden(col,true);

    for( auto i = pmodel->columnCount() - QProductModel::ID_FAMILLE ; i > 0 ; i--)
        productdlg->removeComboboxItem(QProductModel::ID_FAMILLE);

    productdlg->setVisibleTailItem(ListingDialog::CLOSE,true);

    QAbstractItemDelegate* numberDelegate = new NumberDelegate(Qt::AlignRight|Qt::AlignVCenter, productdlg);
    productdlg->view()->setItemDelegateForColumn(ConstODBProductModel::PU_ACHAT,numberDelegate);
    productdlg->view()->setItemDelegateForColumn(ConstODBProductModel::PU_VENTE,numberDelegate);
}

void SalesDialog::connectWidgets(){
    connect(ledit_reference_ , SIGNAL(returnPressed()), SLOT(sale()));
    connect(ledit_client_,     SIGNAL(textChanged(QString)),SLOT(setEnabledSearchClient(QString)));
    connect(ledit_percu_ ,     SIGNAL(textChanged(QString)), SLOT(calculateBalance()));
    connect(ledit_percu_ ,     SIGNAL(textChanged(QString)), SLOT(checkToEnableValidate()));

    connect(actn_delete_ , SIGNAL(triggered(bool)), SLOT(deleteGoods()));
    connect(actn_delete_ , SIGNAL(triggered(bool)), SLOT(checkToEnableValidate()));
    connect(actn_add_ ,    SIGNAL(triggered(bool)) , SLOT(showProductsForSale()));
    connect(actn_list_ ,   SIGNAL(triggered(bool)) , SLOT(showProductsForSearch()));

    connect(actn_full_screen_,      SIGNAL(triggered(bool)) , SLOT(showFullScreen()));
    connect(actn_contiue_saling_,   SIGNAL(triggered(bool)) , ledit_reference_ , SLOT(setFocus()));

    connect(salesmodel , SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), SLOT(updateTotal()));
    connect(salesmodel , SIGNAL(modelReset()), SLOT(enableDeleteItem()));
    connect(salesmodel , SIGNAL(modelReset()) , SLOT(activateButtons()));
    connect(salesmodel , SIGNAL(rowsInserted(QModelIndex,int,int))  , SLOT(activateButtons()));
    connect(salesmodel , SIGNAL(rowsRemoved(QModelIndex,int,int))  , SLOT(activateButtons()));

    connect(attentemodel , SIGNAL(modelReset())  , SLOT(checkToEnableSeller()));
    connect(attentemodel , SIGNAL(rowsInserted(QModelIndex,int,int))  , SLOT(checkToEnableSeller()));
    connect(attentemodel , SIGNAL(rowsRemoved(QModelIndex,int,int))  , SLOT(checkToEnableSeller()));

    connect(pbtn_add_ , SIGNAL(clicked(bool))  , SLOT(showProductsForSale()));
    connect(pbtn_delete_,SIGNAL(clicked(bool))  , SLOT(deleteGoods()));
    connect(pbtn_delete_,SIGNAL(clicked(bool))  , SLOT(checkToEnableValidate()));
    connect(pbtn_hold_,  SIGNAL(clicked(bool))  , SLOT(putSaleOnHold()));
    connect(pbtn_validate_, SIGNAL(clicked(bool))  , SLOT(validateSale()));
    connect(pbtn_cancel_ , SIGNAL(clicked(bool))  , SLOT(cancelSale()));

    connect(productdlg->view(), SIGNAL(clicked(QModelIndex))  , SLOT(sale(QModelIndex)));
    connect(tview_en_attente_ , SIGNAL(doubleClicked(QModelIndex))  , SLOT(restoreSale(QModelIndex)));
    connect(tview_details_->selectionModel() , SIGNAL(selectionChanged(QItemSelection,QItemSelection))  , SLOT(enableDeleteItem()));
}

void SalesDialog::hideListingItem(bool ok){
    productdlg->setColumnHidden(ConstODBProductModel::REFERENCE,ok);
    productdlg->setColumnHidden(ConstODBProductModel::FAMILLE,ok);
    productdlg->setColumnHidden(ConstODBProductModel::PU_ACHAT,ok);
    productdlg->setColumnHidden(ConstODBProductModel::QTE_COLISEE,ok);
    productdlg->setColumnHidden(ConstODBProductModel::CODEBARE,ok);
    productdlg->enableHeadItem(ListingDialog::CBOX,!ok);
}

void SalesDialog::showProductsForSale(){
    hideListingItem(true);
    productdlg->view()->blockSignals(false);
    productdlg->setCurrentIndex(QProductModel::DESIGNATION);
    productdlg->exec();
}

void SalesDialog::showProductsForSearch(){
    hideListingItem(false);
    productdlg->setVisibleSearches(false);
    productdlg->view()->blockSignals(true);
    productdlg->exec();
}

QString SalesDialog::scanReference(){
    QString reference { ledit_reference_->text().simplified()} ;
    ledit_reference_->clear();
    return reference;
}

void SalesDialog::sale(){

    //We (kind of) desactivate sorting (before any adding of new item)
    //giving that this colunm content an empty string
    tview_details_->sortByColumn(SalesModel::COND);

    QString reference {scanReference()} ;
    if (reference.isEmpty()) return ;

    try
    {
        transaction t( AbstractODBModel::DB->begin());
        SPProduit produit {NULL};

        produit = AbstractODBModel::DB->query_one<Article>(
                    query<Article>::reference == reference
                    || query<Produit>::codebare == reference);

        if(produit.isNull())
        {
            produit = AbstractODBModel::DB->query_one<Medicament>(
                    query<Medicament>::CIP == reference
                    || query<Produit>::codebare == reference);
        }
        t.commit();
        if(produit && produit->getPrixVente() > 0)
        {
            if (salesmodel->getMontant() == 0) salesmodel->initModel();
                salesmodel->addItem(produit);
            updateTotal();
            scrollTo(produit);

        }
    }
    catch(const odb::exception& e){
        QMessageBox::information(this,qApp->applicationName(),QString(e.what()));
    }

}

void SalesDialog::sale(QModelIndex index){

    //We (kind of) desactivate sorting (before any adding of new item)
    //by this instruction giving that this colunm content an empty string
    tview_details_->sortByColumn(SalesModel::COND);

    if (index.isValid()){
        index = productdlg->proxyModel()->index(index.row() , ODBProductModel::ID_PRODUIT);
        productdlg->accept();
        try{
            transaction t( AbstractODBModel::DB->begin());
                SPProduit produit = AbstractODBModel::DB->load<Produit>(index.data().toLongLong());
            t.commit();
            if(produit && produit->getPrixVente() > 0){
                if (salesmodel->getMontant() == 0) salesmodel->initModel();
                    salesmodel->addItem(produit);
                updateTotal();
                scrollTo(produit);
            }
        }
        catch( const odb::exception& e){
            QMessageBox::information(this,qApp->applicationName(),QString(e.what()));
            return;
        }
    }
    waitForNextCodeBare();
}

void SalesDialog::updateTotal(){
    QLocale locale;
    lbl_total_valeur_->setText(locale.toCurrencyString( salesmodel->getMontant(), QString(" ")).trimmed());
    calculateBalance();
}

void SalesDialog::setEnabledSearchClient(QString client){
    pbtn_search_->setEnabled(!client.simplified().isEmpty());
}

void SalesDialog::enableDeleteItem(){
    if(tview_details_->selectionModel()->hasSelection())
        pbtn_delete_->setEnabled(true);
    else
        pbtn_delete_->setEnabled(false);
}

void SalesDialog::showFullScreen(){
    if (!isFullScreen()) QDialog::showFullScreen();
    else showNormal();
}

void SalesDialog::resizeEvent(QResizeEvent* event){
    if(event){
        int width =  size().width() - 15;
        for (int col = 0 ; col != salesmodel->columnCount() ; ++col)
            tview_details_->setColumnWidth(col , width/8.2 );
         tview_details_->setColumnWidth(1 , 3.2*width/8.2 );
    }
}

//void SalesDialog::timerEvent(QTimerEvent* event){
////    static int count = 0;
//    qDebug() << "Timer ID: " << event->timerId();
////    if(++count == 10 ) killTimer();
//}

void SalesDialog::deleteGoods(){
    QItemSelectionModel *selectionModel = tview_details_->selectionModel();

    if (!selectionModel->hasSelection()) return ;
    QModelIndexList indexes = selectionModel->selectedRows();

    QList<int> *list = new QList<int>;
    foreach(const QModelIndex &index , indexes)
        list->append(salesproxymodel->mapToSource(index).row());

    qSort(list->begin(),list->end());
    salesmodel->removeItems(list);
    delete list;

    emit selectionModel->selectionChanged(QItemSelection(),QItemSelection());
    updateTotal();
    waitForNextCodeBare();
}

void SalesDialog::activateButtons(){

    if(salesmodel->getMontant() == 0 ){
        ledit_percu_->clear();
        lbl_a_rendre_valeur_->clear();
        enableButtons(false);
     }
    else enableButtons(true);

 checkToEnableSeller();
}

void SalesDialog::enableButtons(bool enabled){
    pbtn_hold_->setEnabled(enabled);
    pbtn_cancel_->setEnabled(enabled);
    ledit_percu_->setEnabled(enabled);
}

void SalesDialog::checkToEnableSeller(){
    if(salesmodel->getMontant() == 0 && attentemodel->isEmpty())
        cbx_vendeur_->setEnabled(true);
    else
        cbx_vendeur_->setEnabled(false);
}

void SalesDialog::checkToEnableValidate(){
    if(ledit_percu_->isEnabled() && ledit_percu_->result() >= salesmodel->getMontant())
        pbtn_validate_->setEnabled(true);
    else
        pbtn_validate_->setEnabled(false);
}

void SalesDialog::cancelSale(){
   resetSales();
}

void SalesDialog::validateSale(){
    try{
        transaction t( AbstractODBModel::DB->begin());
            salesmodel->save();
            if(salerIsCashier())  printTicket();
        t.commit();
        resetSales();
    }
    catch(const odb::exception& e){
        QString msg(e.what());
        if(msg.contains("violates check constraint"))
            msg = "Un des enregistrement contien un prix de vente nul , veuillez le supprimer pour poursuivre";
        QMessageBox::critical(this,tr("Erreur Vente"), msg);
    }
//    resetSales();
}

void SalesDialog::putSaleOnHold(){
    hspcr_bottom_->changeSize(this->size().width()/3 , 1 , QSizePolicy::Minimum);
    tview_en_attente_->setVisible(true);
    attentemodel->addItem(resetSales());
    tview_en_attente_->scrollToBottom();
}

SPSortie SalesDialog::resetSales(){
    SPSortie old = salesmodel->reset();
    updateTotal();
    waitForNextCodeBare();
    pbtn_validate_->setDisabled(true);
    return old;
}

void SalesDialog::restoreSale(QModelIndex index){
    if (index.isValid() && salesmodel->getMontant() == 0){
        salesmodel->setSale(attentemodel->takeAt(attenteproxymodel->mapToSource(index).row()));
        tview_details_->scrollToBottom();
        updateTotal();
        if (attentemodel->isEmpty()){
            hspcr_bottom_->changeSize(this->size().width()*2/3 , 1 , QSizePolicy::Preferred);
            tview_en_attente_->setVisible(false);
        }
        waitForNextCodeBare();
    }
}

void SalesDialog::printTicket()
{
    static int i = 1;
    QPrinter printer(QPrinter::ScreenResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(QString("ticket-%1.pdf").arg(QVariant(i).toString()));
    printer.setPageOrientation(QPageLayout::Portrait);
    printer.setPageSize(QPrinter::A7);
//    printer.setColorMode(QPrinter::GrayScale);

    int POLICE = 9;
    const char* familly = "Times New Roman";
    QFont font(familly, POLICE);
    font.setPointSize(POLICE);
    QFont boldFont(familly, POLICE, 100);
    QFont headerFont("Latin Modern Roman Caps", POLICE, 100);

    QPainter painter(&printer);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setFont(font);
    QFontMetrics fontMetr = painter.fontMetrics();

    painter.setFont(headerFont);
    QFont priceFont(font);
    priceFont.setFixedPitch(true);

    int Y = 0 , X = 0 , HSPACING = 5;
    int PU_WIDTH = 0 , QTE_WIDTH = 0 , REMISE_WIDTH = 0 , TOTAL_WIDTH = 0;
    const int WIDTH = printer.pageRect().width();

    QPixmap logoPixmap(":/main/logo.png");
    painter.drawPixmap(WIDTH/2 - logoPixmap.width()/2  , Y, logoPixmap); //Center the logo
    QRect rect = painter.boundingRect(X, Y, WIDTH - logoPixmap.width(),
                                      logoPixmap.height(), Qt::AlignCenter, qApp->organizationName());

    painter.drawText(X, logoPixmap.height()/3,
                     WIDTH, rect.height(), Qt::AlignHCenter, qApp->organizationName());

    Y += qMax(rect.height(), logoPixmap.height());
    painter.setFont(boldFont);
    painter.drawLine(X, Y, WIDTH, Y);
    painter.drawText(X, Y, WIDTH, fontMetr.height(), Qt::AlignLeft,tr("Ticket N°: %1")
                     .arg(QVariant(i).toString()));

    painter.drawText(X, Y, WIDTH, fontMetr.height(), Qt::AlignRight,tr("Date : %1  %2")
                     .arg(QDate::currentDate().toString(Qt::SystemLocaleShortDate))
                     .arg(QTime::currentTime().toString()));

    Y += fontMetr.height();
    painter.drawText(X, Y, WIDTH, fontMetr.height(), Qt::AlignLeft,tr("Caissier : %1")
                     .arg(salesmodel->cashier()->getPrenoms()));
    painter.drawText(X, Y, WIDTH, fontMetr.height(), Qt::AlignRight,tr("Devise : %1")
                     .arg(QString("F CFA")));

    QStringList content = salesmodel->salesContent().split(QRegExp("\n"));
    content.takeFirst(); // Remove the header line
    QStringList total = content.takeLast().split(QRegExp(";"));

    enum POS{ DESIG = 0, PU, QTE, /*REMISE,*/ TOTAL };

    while ( !content.isEmpty() ){
        QStringList items = content.takeFirst().split(QRegExp(";"));
        int tmp_pu = fontMetr.boundingRect(items.at(PU)).width();
        if(tmp_pu > PU_WIDTH) PU_WIDTH = tmp_pu;

        int tmp_qte = fontMetr.boundingRect(items.at(QTE)).width();
        if(tmp_qte > QTE_WIDTH) QTE_WIDTH = tmp_qte;

//        int tmp_remise = fontMetr.boundingRect(items.at(REMISE)).width();
//        if(tmp_remise > REMISE_WIDTH) REMISE_WIDTH = tmp_remise;

        int tmp_total = fontMetr.boundingRect(items.at(TOTAL)).width();
        if(tmp_total > TOTAL_WIDTH) TOTAL_WIDTH = tmp_total;
    }

    PU_WIDTH = qMax(PU_WIDTH , fontMetr.boundingRect(tr("P.U")).width());
    QTE_WIDTH = qMax(QTE_WIDTH , fontMetr.boundingRect(tr("Qté")).width()) + HSPACING;
    TOTAL_WIDTH = qMax(TOTAL_WIDTH , fontMetr.boundingRect(tr("Total")).width());

    Y += 2*fontMetr.height();

    int PRICE_WIDTH = PU_WIDTH + QTE_WIDTH + REMISE_WIDTH + TOTAL_WIDTH + 3*HSPACING;
    painter.drawText(X,  Y, WIDTH - PRICE_WIDTH ,fontMetr.height(), Qt::AlignLeft, tr("Désignation"));

    int NEXT_X = WIDTH - PRICE_WIDTH + HSPACING;
    painter.drawText(NEXT_X, Y , PU_WIDTH, fontMetr.height(), Qt::AlignRight, tr("P.U"));

    NEXT_X += PU_WIDTH + HSPACING;
    painter.drawText(NEXT_X, Y, QTE_WIDTH, fontMetr.height(), Qt::AlignRight, tr("Qté"));

    NEXT_X += QTE_WIDTH + HSPACING;
//    painter.drawText(NEXT_WIDTH, y, NEXT_WIDTH + REMISE_WIDTH, fontMetr.height(), Qt::AlignRight, tr("Remise"));

//    NEXT_WIDTH += REMISE_WIDTH + 1;
    painter.drawText(NEXT_X, Y, TOTAL_WIDTH, fontMetr.height(), Qt::AlignRight, tr("Total"));

    Y += fontMetr.height();
    painter.drawLine(X, Y, WIDTH, Y);
    Y++;

    content = salesmodel->salesContent().split(QRegExp("\n"));
    content.takeFirst();
    content.takeLast();

    while ( !content.isEmpty() )
    {
      painter.setFont(font);
      QStringList items = content.takeFirst().split(QRegExp(";"));
      NEXT_X = WIDTH - PRICE_WIDTH;
      QString desig = fontMetr.elidedText(items.at(DESIG), Qt::ElideRight, WIDTH - PRICE_WIDTH);
      painter.drawText(X, Y, WIDTH - PRICE_WIDTH ,fontMetr.height(), Qt::AlignLeft, desig);

      NEXT_X += HSPACING;
      painter.drawText(NEXT_X , Y , PU_WIDTH, fontMetr.height(), Qt::AlignRight, items.at(PU));

      NEXT_X += PU_WIDTH + HSPACING;
      painter.drawText(NEXT_X, Y, QTE_WIDTH, fontMetr.height(), Qt::AlignRight, items.at(QTE));

      NEXT_X += QTE_WIDTH + HSPACING;
              ;
//      painter.drawText(NEXT_WIDTH, y, NEXT_WIDTH + REMISE_WIDTH, fontMetr.height(), Qt::AlignRight, items.at(REMISE));

//      NEXT_WIDTH += REMISE_WIDTH + HSPACING;
      painter.setFont(priceFont);
      painter.drawText(NEXT_X, Y, TOTAL_WIDTH, fontMetr.height(), Qt::AlignRight, items.at(TOTAL));

      Y += fontMetr.height();
      if ( (Y + fontMetr.height()) > printer.pageRect().height()){
        printer.newPage();
        Y = 0;
      }
    }
    painter.drawLine(0, Y, WIDTH, Y);
    QFontMetrics boldMetr(boldFont);

    // if there is not enough space for sum+tax lines, start new page
    if ( (Y + fontMetr.height()) > printer.pageRect().height() ){
      printer.newPage();
      Y = 0;
    }

    painter.setFont(boldFont);
    painter.drawText(X, Y, WIDTH  , boldMetr.height(), Qt::AlignLeft,tr("Montant Total :"));
    painter.drawText(X, Y, WIDTH  , boldMetr.height(), Qt::AlignRight, total.at(TOTAL));
    painter.end();
    if ( printer.outputFormat() == QPrinter::PdfFormat ){
        QProcess::startDetached(printer.outputFileName().prepend("lp "));
        QProcess::startDetached(printer.outputFileName().prepend("okular "));
    }
    i++;
}

void SalesDialog::calculateBalance(){
     QLocale locale;
     qint64 monaie = ledit_percu_->result() - salesmodel->getMontant();
     if(monaie >= 0)
         lbl_a_rendre_valeur_->setText(locale.toCurrencyString(monaie, QString(" ")).trimmed());
     else
         lbl_a_rendre_valeur_->setText(QString("0"));
 }

void SalesDialog::currencyEcho(QString value){
     QLocale locale;
     value = value.remove(QRegExp("\\s"));
     ledit_percu_->setText(locale.toCurrencyString(value.toLongLong(),QString(" ")).trimmed());
 }

void SalesDialog::waitForNextCodeBare(){
     ledit_reference_->setFocus();
 }

void SalesDialog::scrollTo(const SPProduit &produit){

    int row = salesmodel->indexOf(produit);
    QModelIndex startindex = salesproxymodel->mapFromSource(salesmodel->index(row , SalesModel::REFERENCE));
    QModelIndex endindex = salesproxymodel->mapFromSource(salesmodel->index(row , SalesModel::TOTAL));
    tview_details_->selectionModel()->select(QItemSelection(startindex,endindex),QItemSelectionModel::Select);
    tview_details_->scrollTo(endindex);
}

bool SalesDialog::salerIsCashier(){
    return salesmodel->cashier()->getId() == salesmodel->saler()->getId();
}
