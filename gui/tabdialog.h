#ifndef TABDIALOG_H
#define TABDIALOG_H

#include "ui_tabdialog.h"
#include "views.h"

#include <QDialog>

class TabDialog : public QDialog , private Ui::TabDialog{
public:
    explicit TabDialog(QWidget *parent = 0);
    void addTab(QWidget *tab, const QString& title);
    void setCurrentIndex(int index);
};

#endif // PRODUCTMANAGEMENTDIALOG_H
