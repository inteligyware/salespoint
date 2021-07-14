#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "salesdialog.h"
#include "tabdialog.h"
#include "views.h"
#include "reportingdialog.h"

class MainWindow : public QMainWindow , private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(bool populate , QWidget *parent = 0);
    explicit MainWindow(QWidget *parent = 0);

    ListingDialog* makeProductDialog(FamilyCreationForm *form);
    SalesDialog* makeSalesDialog(QAbstractItemModel* productmodel);
    void addWidget(QWidget *widget);

    //Factory Methods
    QDialog* makeSalesManagementTab(QAbstractItemModel* productmodel);
    QDialog* makeReportManagementTab();
    QDialog* makeProductManagementTab(QAbstractItemModel** productmodelptr);
    QDialog* makeStockManagementTab();
    QDialog* makeAccountingManagementTab();
    QDialog* makeProfileManagementTab();

    enum menuItem : char {
       SALES,
       REPORT,
       PRODUCT,
       STOCK,
       COMPTA,
       PROFILE,
       ABOUT
    };
private slots:
    void setCurrentIndex(int index);
    void about();

private :
    void createWidgets();
    void layoutWidgets();
    void connectWidgets();    

    //views
    QDialog *sales, *report, *product, *stock, *accounting, *profile;

    //models
    QAbstractItemModel* productmodel;
//    ListingModel *familymodel, *supplyermodel;

};

#endif // MAINWINDOW_H
