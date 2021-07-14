#include "tabdialog.h"
#include "delegates.h"

TabDialog::TabDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    gridLayout->setSpacing(0);
    gridLayout->addWidget(tabwidget_, 0, 0, -1, -1);
    tabwidget_->setContentsMargins(0,0,0,0);
    tabwidget_->setCurrentIndex(0);
}

void TabDialog::addTab(QWidget *tab, const QString& title){
     tabwidget_->addTab(tab, title);
}


void TabDialog::setCurrentIndex(int index){
    tabwidget_->setCurrentIndex(index);
}

