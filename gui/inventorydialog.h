#ifndef INVENTORY_DIALOG_H
#define INVENTORY_DIALOG_H

#include "models.h"
#include "views.h"
#include "ui_inventorydialog.h"


#include <QDialog>
#include <QResizeEvent>

using SPODBDatabase = QSharedPointer<odb::database>;
class InventoryDialog : public QDialog , private Ui::InventoryDialog
{
    Q_OBJECT

public:

    InventoryDialog(QAbstractItemModel *productmodel, QWidget *parent = 0);
    ~InventoryDialog();
    const QSize SIZEMIN;

protected slots:
    void inventory();
    void inventory(QModelIndex);
    void enableDeleteItem();
    void showFullScreen();
    void deleteItems();
    void activateButtons();
    void checkToEnableValidate();
    void cancelInventory();
    void validateInventory();

protected :
    void resizeEvent(QResizeEvent*);

private:
    void connectWidgets();
    void enableButtons(bool = true);
    QString scanReference();
    void printInventory();
    void waitForNextCodeBare();
    void scrollTo(const SPProduit &produit);

    InventoryModel* inventorymodel;
    QSortFilterProxyModel* inventoryproxymodel;
    ListingDialog *productdlg;
};

#endif // INVENTORY_DIALOG_H
