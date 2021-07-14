#ifndef VIEWS_H
#define VIEWS_H

#include "models.h"
#include <QWidget>
#include <QDialog>
#include <QDoubleSpinBox>

class QPushButton;
class QTreeView;
class QAbstractItemModel;
class QVBoxLayout;
class QHBoxLayout;

class IAbstarctViews : public QWidget
{
    Q_OBJECT
public:
    explicit IAbstarctViews(IAbstractDataModel *model, QWidget *parent = Q_NULLPTR);
    explicit IAbstarctViews(QAbstractItemModel *model, QWidget *parent = Q_NULLPTR);

public slots:
    inline void setFilterKeyColumn(int col) { proxymodel_.setFilterKeyColumn(col);}

private:
    QSortFilterProxyModel proxymodel_ { this };
};

class ListingDialog : public QDialog
{
    Q_OBJECT

public:
    static const int WIDTH;
    static const int HEIGT;

    explicit ListingDialog(IAbstractDataModel *model, QWidget *parent = Q_NULLPTR);
    explicit ListingDialog(QAbstractItemModel *model, QWidget *parent = Q_NULLPTR);

    void setVisibleHead(bool);
    void setVisibleTail(bool);
    void setVisibleTailItem(int item, bool visible);
    void setColumnHidden(int item, bool visible);
    void enableHeadItem(int item, bool visible);
    void enableTailItem(int item, bool visible);
    QTreeView* view();
    const QSortFilterProxyModel* proxymodel() const ;

public slots:
    inline void setFilterKeyColumn(int col) { proxymodel_->setFilterKeyColumn(col);}

protected :
    void resizeEvent(QResizeEvent*);

private:

    void createWidgets();
    void layoutWidgets();
    void setupProxyModel(QAbstractItemModel *model);
    void setupHead(IAbstractDataModel *model);
    int setupBody(IAbstractDataModel *model);
    void setupTail();
    void connectWidgets();

    QSortFilterProxyModel* proxymodel_ ;

    QVBoxLayout* mainlay_;
    QHBoxLayout* toplay_;
    QHBoxLayout* bottomlay_;

    QVector<QWidget*> head_;
    QVector<QWidget*> tail_;
    QTreeView* view_;

    //Default head widgets
    QLineEdit* search_;
    QComboBox* cbox_;

    //Default tail widgets
    QPushButton *close_, *delete_ , *new_, *open_;
};

class TableView : public QWidget
{
    Q_OBJECT
public:
    explicit TableView(IAbstractDataModel *model, QWidget *parent = Q_NULLPTR);
    explicit TableView(QAbstractItemModel *model, QWidget *parent = Q_NULLPTR);

public slots:
    inline void setFilterKeyColumn(int col){ proxymodel_.setFilterKeyColumn(col);}

private:
    QSortFilterProxyModel proxymodel_ { this };
};

#endif // VIEWS_H
