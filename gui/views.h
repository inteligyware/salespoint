#ifndef VIEWS_H
#define VIEWS_H

#include "models.h"
#include <QWidget>
#include <QDialog>
#include <QDoubleSpinBox>
#include <QTreeView>
#include <QGroupBox>

class QPushButton;
class QTreeView;
class QAbstractItemModel;
class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class ProductCreationForm;
class FamilyCreationForm;

class ListingDialog : public QDialog
{
    Q_OBJECT

public:
    static const int WIDTH;
    static const int HEIGT;

    explicit ListingDialog(QAbstractItemModel *model , int defaultsortcolumn = 1,  QWidget *parent = Q_NULLPTR);

    void setVisibleHead(bool visible);
    void setVisibleSearches(bool visible);
    void setVisibleGroupBox(bool visible);
    void setVisibleTail(bool visible);
    void setVisibleTailItem(int item, bool visible);

    void setColumnHidden(int item, bool hide);
    void enableHeadItem(int item, bool enabled);
    void enableTailItem(int item, bool enabled);
    void removeComboboxItem(int index);
    void setCurrentIndex(int index);
    QTreeView* view();
    const QSortFilterProxyModel* proxyModel() const ;
    QAbstractItemModel *sourceModel();

protected slots:
    virtual void setFilterKeyColumn(int col);
    virtual int addItem(){ return 0;}
    virtual void removeItems(){}
    virtual void showItem(){}

private slots:
    void showItemsCount();
    void enableButtons();
    void resizeSearchItem(int col);
    void moveSearchItem(int, int odlposition , int newposition);
    void disableEscape();

protected :
    void resizeEvent(QResizeEvent*);

private:
    void createWidgets();
    void layoutWidgets();
    void connectWidgets();

    void setProxyModel(QAbstractItemModel *model);
    void setupHead(QAbstractItemModel *model);
    int  setupBody(QAbstractItemModel *model);
    void setupTail();

private:
    const int SORT_COLUMN;

    //Default head widgets
    QLineEdit* ledit_search;
    QComboBox* cbox_field;
    QSortFilterProxyModel* proxymodel {new DateFilterProxyModel(this)};

    //Optional head widgets
    QLabel *related_product_ , *family_;
    QComboBox *cbxrelated_product_, *cbxfamily_;
    QVector<QWidget*> searchs_;

    //Default Body widget
    QTreeView* treeview;

    //Default tail widgets
    QPushButton *pbtn_close, *pbtn_delete , *pbtn_new, *pbtn_open;
    QLabel* lbl_count /*, *place_holder_*/;


    QVBoxLayout* mainlay_;
    QHBoxLayout *toplay_, *midletoplay_, *midlelay_,*bottomlay_;
    QGroupBox *box_;

    QVector<QWidget*> head_;
    QVector<QWidget*> tail_;

public:
    enum Contorls : char {
        OPEN,
        NEW,
        DELETE,
        CLOSE
    };

    enum Search : char {
        SEARCH,
        CBOX
    };
};

class ProductListingDialog : public ListingDialog{

    Q_OBJECT
public:
    explicit ProductListingDialog(QAbstractItemModel *model, int defaultsortcolumn, FamilyCreationForm* familyform , QWidget *parent = Q_NULLPTR);
    ProductCreationForm* creationForm() const;

protected slots:
    int addItem();
    void removeItems();
    void showItem();

private:
    ProductCreationForm* form;
    FamilyCreationForm *family_form;
};

class FamilyListingDialog : public ListingDialog{

    Q_OBJECT

public:
    explicit FamilyListingDialog(ODBFamilyModel *model , int defaultsortcolumn = ODBFamilyModel::DESIGNATION,  QWidget *parent = Q_NULLPTR);
//    explicit FamilyListingDialog(AbstractFamilyModel *model , int defaultsortcolumn = 1,  QWidget *parent = Q_NULLPTR);
    FamilyCreationForm* creationForm() const;

protected slots:
    int addItem();
    void removeItems();
    void showItem();

private:
    FamilyCreationForm* form;

};

#endif // VIEWS_H
