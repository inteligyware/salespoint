#ifndef SALESDIALOG_H
#define SALESDIALOG_H

#include "models.h"
#include "views.h"
#include "ui_salesdialog.h"
//#include "ui_cashdialog.h"

#include <QDialog>
#include <QResizeEvent>

using SPODBDatabase = QSharedPointer<odb::database>;
class SalesDialog : public QDialog , private Ui::SalesDialog
{
    Q_OBJECT

public:
//    explicit SalesDialog(QWidget *parent = 0);
//    void setProductDialog();

    SalesDialog(QAbstractItemModel *productmodel, QWidget *parent = 0);
    void createProductDialog(QAbstractItemModel *productmodel);
    ~SalesDialog();
    const QSize SIZEMIN;

protected slots:
    void sale();
    void sale(QModelIndex);
    void showProductsForSale();
    void showProductsForSearch();
    void setEnabledSearchClient(QString client);
    void enableDeleteItem();
    void updateTotal();
    void showFullScreen();
    void deleteGoods();
    void activateButtons();
    void checkToEnableSeller();
    void checkToEnableValidate();
    void cancelSale();
    void validateSale();
    void putSaleOnHold();
    void restoreSale(QModelIndex);
    void calculateBalance();
    void currencyEcho(QString);

protected :
    void resizeEvent(QResizeEvent*);
//    void timerEvent(QTimerEvent*);

private:
    void connectWidgets();
    void hideListingItem(bool = true);
    void enableButtons(bool = true);
    QString scanReference();
    SPSortie resetSales();
    void printTicket();
    void waitForNextCodeBare();
    void scrollTo(const SPProduit &produit);
    bool salerIsCashier();

    SalesModel* salesmodel;
    AttenteModel* attentemodel;
    QSortFilterProxyModel* salesproxymodel;
    QSortFilterProxyModel* attenteproxymodel;
    ListingDialog *productdlg;
};

#endif // SALESDIALOG_H
