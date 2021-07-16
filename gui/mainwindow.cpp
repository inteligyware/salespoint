#include "mainwindow.h"
#include "delegates.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    setupUi(this);
    createWidgets();
    layoutWidgets();
    connectWidgets();
    setStyleSheet("QMainWindow::separator { background: yellow;  width: 10px; height: 10px;} \
                   QHeaderView::section { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\
                                          stop:0 #616161, stop: 0.5 #505050, \
                                          stop: 0.6 #434343, stop:1 #656565); \
                                          color: white; \
                                          padding-left: 4px;\
                                          border: 1px solid #6c6c6c;}  \
                    QHeaderView::down-arrow { image: url(:/main/down_arrow);} \
                    QHeaderView::up-arrow { image: url(:/main/up_arrow);} \
                    QLineEdit { border: 1px solid gray; \
                                border-radius: 6px; \
                                selection-background-color: #aec8ae;} \
                    QLineEdit:disabled { background-color: #eff0f1}");
}

MainWindow::MainWindow(bool populate , QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    if(populate){
        createWidgets();
        layoutWidgets();
    }
    connectWidgets();
}

void MainWindow::createWidgets(){
    QLocale::setDefault(QLocale("fr_FR"));
    product = makeProductManagementTab(&productmodel);
    sales = makeSalesManagementTab(productmodel);
    report = makeReportManagementTab();
    stock = makeStockManagementTab();
    accounting = makeAccountingManagementTab();
    profile = makeProfileManagementTab();
}

void MainWindow::layoutWidgets(){
    stackwgt->addWidget(sales);
    stackwgt->addWidget(report);
    stackwgt->addWidget(product);
    stackwgt->addWidget(stock);
    stackwgt->addWidget(accounting);
    stackwgt->addWidget(profile);

    listwgt->setRowHidden(STOCK,true);
    listwgt->setRowHidden(COMPTA,true);
    listwgt->setRowHidden(PROFILE,true);
}

void MainWindow::connectWidgets(){
    connect(listwgt, SIGNAL(currentRowChanged(int)), SLOT(setCurrentIndex(int)));
}

void MainWindow::setCurrentIndex(int index){
    if(index == ABOUT)  about();
    stackwgt->setCurrentIndex(index);
}

void MainWindow::about(){
        QString msg = qApp->applicationName()+" "+qApp->applicationVersion()+", Copyright (®) 2016-2020\n";
        msg.append("Gilles BENE POUGOUE <gilles.benepougoue@gmail.com>\n");
        msg.append("Phone : (+237) 697 02 63 76 / 670 27 53 39\n");
        QMessageBox::information(this, qApp->organizationName(), msg);
}

void MainWindow::addWidget(QWidget *widget){
    stackwgt->addWidget(widget);
}

ListingDialog* MainWindow::makeProductDialog(FamilyCreationForm* form){
//The intension of this Query is to check the size of the DB product and create the model accordingly
//But we dont use it yet because, we still dont know how to update a QSqlQueryModel
//    QSqlQuery query("SELECT COUNT(*) FROM produit;");
//    query.exec();

//    auto productmodel = new QProductModel(this);
    auto  productmodel = new ODBProductModel(this);
    productmodel->load();

    ListingDialog* productdlg = new ProductListingDialog(productmodel, ODBProductModel::DESIGNATION , form, this);
    productdlg->setColumnHidden(QProductModel::ID_PRODUIT,true);

    for( int col = ODBProductModel::ID_PRODUIT_PARENT ; col < productmodel->columnCount() ; col++)
       productdlg->setColumnHidden(col,true);

    productdlg->setVisibleTailItem(ListingDialog::NEW,true);
    QAbstractItemDelegate* numberDelegate = new NumberDelegate(Qt::AlignRight|Qt::AlignVCenter, this);
    productdlg->view()->setItemDelegateForColumn(ODBProductModel::PU_ACHAT,numberDelegate);
    productdlg->view()->setItemDelegateForColumn(ODBProductModel::PU_VENTE,numberDelegate);

    return productdlg;
}

SalesDialog* MainWindow::makeSalesDialog(QAbstractItemModel* productmodel){
    SalesDialog* salesdlg = new SalesDialog(productmodel);
    return salesdlg;
}

QDialog* MainWindow::makeSalesManagementTab(QAbstractItemModel* productmodel){
    return makeSalesDialog(productmodel);
}

QDialog* MainWindow::makeReportManagementTab(){
    QString query,title;
    QStringList header;

    query = "SELECT DISTINCT  p.id , libele , AVG(ds.prix_unitaire), AVG(ds.remise), SUM(ds.qte) AS Quantite ,  \
                SUM(ds.qte*ds.prix_unitaire*(1-ds.remise/100)) AS Total \
                FROM detailssortie ds \
                    INNER JOIN produit p ON ds.produit = p.id \
                GROUP BY p.id, libele\
                ORDER BY p.id;";
    header << tr("Index")  << tr("Désignation") <<  tr("P.U Moy.") << tr("Remise(%)")  << tr("Qté Totale")  << tr("Montant");
    title = "Ventes Globales Par Articles Indépendement de la Période";
    auto reportdlg0 = new ReportingDialog();
    reportdlg0->addModelFromQuery(query,header,title);
    reportdlg0->setAlignmentsForQuery(0,QList<int>() << 2 << 3 << 4 << 5 , Qt::AlignVCenter|Qt::AlignRight);


    query= "SELECT libele , date , pu , remise, SUM(qte) as qte , SUM(total) as total  \
                FROM product_dayly_sales  \
                GROUP BY libele , date, pu , remise;";
    header.clear();
    header << tr("Désignation")  << tr("Date de Vente") << tr("Prix Unitaire") << tr("Remise (%)") << tr("Quantité") << tr("Montant");
    title = "Ventes Journalières Par Articles";
    auto reportdlg1 = new ReportingDialog();
    reportdlg1->addModelFromQuery(query,header,title);
    reportdlg1->setAlignmentsForQuery(0,QList<int>() << 2 << 3 << 4 << 5 , Qt::AlignVCenter|Qt::AlignRight);

    query = "SELECT s.id  as Numero , f.reference as Reference ,  ps.noms as Seller , \
                     date as Date, SUM(ds.qte*ds.prix_unitaire*(1 - ds.remise/100)) as Amount \
                     FROM sortie s \
                        LEFT JOIN personne ps ON s.responsable = ps.id \
                        LEFT JOIN detailssortie ds ON s.id = ds.sortie \
                        LEFT JOIN facture f ON  s.facture  = f.id  \
                            WHERE  s.id = ds.sortie AND s.responsable = ps.id  \
                      GROUP BY s.id , f.reference , ps.noms , date \
                      ORDER BY Date DESC";
    header.clear();
    header << tr("Index") << tr("Numéro de Transaction") << tr("Vendeur") << tr("Date") << tr("Montant");
    title = "Ventes Généralisées";
    auto reportdlg2 = new ReportingDialog();
    reportdlg2->addModelFromQuery(query,header,title);
    reportdlg2->setAlignmentsForQuery(0,QList<int>() << 4 , Qt::AlignVCenter|Qt::AlignRight);

    query = "SELECT saler , date , SUM(amount) as total FROM employees_dayly_sales GROUP BY saler , date;";
    header.clear();
    header << tr("Vendeur") << tr("Jour de l'Année")  << tr("Total");
    title = "Ventes Journalières par Vendeur";
    auto reportdlg3 = new ReportingDialog();
    reportdlg3->addModelFromQuery(query,header,title);
    reportdlg3->setAlignmentsForQuery(0,QList<int>() << 2 , Qt::AlignVCenter|Qt::AlignRight);

    query = "SELECT saler , date , SUM(amount) as total FROM employees_monthly_sales GROUP BY saler , date ORDER BY saler;";
    header.clear();
    header << tr("Vendeur") << tr("Mois De l'Année")  << tr("Montant");
    title = "Ventes Mensuelles par Vendeur";
    auto reportdlg4 = new ReportingDialog();
    reportdlg4->addModelFromQuery(query,header,title);
    reportdlg4->setAlignmentsForQuery(0,QList<int>() << 2 , Qt::AlignVCenter|Qt::AlignRight);

    auto report = new TabDialog();
    report->addTab(reportdlg0 , tr("Ventes Globales Par Articles"));
    report->addTab(reportdlg1 , tr("Ventes Journalières Par Articles"));
    report->addTab(reportdlg2 , tr("Ventes Générales Par Vendeurs"));
    report->addTab(reportdlg3 , tr("Ventes Journalières Par Vendeur"));
    report->addTab(reportdlg4 , tr("Ventes Mensuelles Par Vendeur"));
    report->setCurrentIndex(2);

    return report;
}

//QDialog* MainWindow::makeProductManagementTab(QAbstractItemModel **productmodelptr){
//    ListingDialog* productdlg = makeProductDialog();
//    *productmodelptr = productdlg->sourceModel();

//    QString query;
//    QStringList header;

//    query = "SELECT reference , libele , description FROM famille;";
//    header << tr("Référence") << tr("Libele") << tr("Description");
//    ListingModel* familymodel = new ListingModel(query,header,QString(),this);
//    familymodel->setAlignments(QList<int>() << familymodel->columnCount() - 1 , Qt::AlignLeft|Qt::AlignVCenter);
//    ListingDialog* familydlg  = new ListingDialog(familymodel , this , 1);

//    query = "SELECT nom , initiale , type_fourn , tel , email , description FROM fournisseur;";
//    header.clear();
//    header << tr("Raison Sociale") << tr("Initiales") << tr("Type") << tr("Téléphone")
//           << tr("Email") << tr("Description");

//    ListingModel* suppliermodel = new ListingModel(query,header,QString(),this);
//    suppliermodel->setAlignments(QList<int>() << familymodel->columnCount() - 1 , Qt::AlignLeft|Qt::AlignVCenter);
//    ListingDialog* supplierdlg  = new ListingDialog(suppliermodel , this , 0);

//    TabDialog* _product = new TabDialog();
//    _product->addTab(productdlg , tr("Articles"));
//    _product->addTab(familydlg , tr("Familles"));
//    _product->addTab(supplierdlg , tr("Fournissour"));
////    product = _product;
//    return _product;
//}

QDialog* MainWindow::makeProductManagementTab(QAbstractItemModel **productmodelptr){

    auto familymodel = new ODBFamilyModel;
    familymodel->load();
    auto familydlg = new FamilyListingDialog(familymodel , ODBFamilyModel::DESIGNATION , this);
    ListingDialog* productdlg = makeProductDialog(familydlg->creationForm());
    *productmodelptr = productdlg->sourceModel();

    QString query , title;
    QStringList header;

    query = "SELECT reference , libele , description FROM famille;";
    header << tr("Référence") << tr("Libele") << tr("Description");
    title = tr("Liste des Familles d'Aritles");

//    ReportingDialog* reportdlg1 = new ReportingDialog();
//    reportdlg1->setQueryComboboxEnabled(false);
//    reportdlg1->setDateEditsVisible(false);
//    reportdlg1->setFieldComboboxEnabled(false);

//    reportdlg1->addModelFromQuery(query,header,title);
//    reportdlg1->setAlignmentsForQuery(0,QList<int>() << 2 , Qt::AlignLeft|Qt::AlignVCenter);

//    auto familymodel = new ListingModel(query,header,title);


    query = "SELECT nom , initiale , type_fourn , tel , email , description FROM fournisseur;";
    header.clear();
    header << tr("Raison Sociale") << tr("Initiales") << tr("Type") << tr("Téléphone")
           << tr("Email") << tr("Description");
    title = tr("Liste Des Fournissour");

    ReportingDialog* reportdlg2 = new ReportingDialog();
    reportdlg2->setQueryComboboxEnabled(false);
    reportdlg2->setDateEditsVisible(false);
    reportdlg2->setFieldComboboxEnabled(false);

    reportdlg2->addModelFromQuery(query,header,title);
    reportdlg2->setAlignmentsForQuery(0,QList<int>() << 5 , Qt::AlignLeft|Qt::AlignVCenter);

    TabDialog* _product = new TabDialog();
    _product->addTab(productdlg , tr("Articles"));
//    _product->addTab(reportdlg1 , tr("Familles"));
     _product->addTab(familydlg , tr("Familles"));
    _product->addTab(reportdlg2 , tr("Fournissour"));
    return _product;
}

QDialog* MainWindow::makeStockManagementTab(){
    TabDialog* _stock = new TabDialog();
//    stock = _stock;
    return _stock;
}

QDialog* MainWindow::makeAccountingManagementTab(){
    TabDialog* _accounting = new TabDialog();
    return _accounting;
}

QDialog* MainWindow::makeProfileManagementTab(){
    TabDialog* _profile = new TabDialog();
    return _profile;
}




