/********************************************************************************
** Form generated from reading UI file 'tabdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABDIALOG_H
#define UI_TABDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>

QT_BEGIN_NAMESPACE

class Ui_TabDialog
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabwidget_;

    void setupUi(QDialog *TabDialog)
    {
        if (TabDialog->objectName().isEmpty())
            TabDialog->setObjectName(QStringLiteral("TabDialog"));
        TabDialog->resize(632, 476);
        TabDialog->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(TabDialog);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, 2);
        tabwidget_ = new QTabWidget(TabDialog);
        tabwidget_->setObjectName(QStringLiteral("tabwidget_"));
        tabwidget_->setMovable(true);
        tabwidget_->setTabBarAutoHide(true);

        gridLayout->addWidget(tabwidget_, 0, 0, 1, 1);


        retranslateUi(TabDialog);

        tabwidget_->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(TabDialog);
    } // setupUi

    void retranslateUi(QDialog *TabDialog)
    {
        TabDialog->setWindowTitle(QApplication::translate("TabDialog", "Gestion des Produits", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TabDialog: public Ui_TabDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABDIALOG_H
