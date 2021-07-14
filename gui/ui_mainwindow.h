/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hlyt_midle_;
    QListWidget *listwgt;
    QStackedWidget *stackwgt;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(554, 625);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        hlyt_midle_ = new QHBoxLayout();
        hlyt_midle_->setSpacing(0);
        hlyt_midle_->setObjectName(QStringLiteral("hlyt_midle_"));
        listwgt = new QListWidget(centralwidget);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/sale"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listwgt);
        __qlistwidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignTop);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/stat"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listwgt);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignTop);
        __qlistwidgetitem1->setFont(font);
        __qlistwidgetitem1->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/recherche"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listwgt);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignTop);
        __qlistwidgetitem2->setFont(font);
        __qlistwidgetitem2->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/stock"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listwgt);
        __qlistwidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignTop);
        __qlistwidgetitem3->setFont(font);
        __qlistwidgetitem3->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/paiement"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listwgt);
        __qlistwidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignTop);
        __qlistwidgetitem4->setFont(font);
        __qlistwidgetitem4->setIcon(icon5);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/user"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listwgt);
        __qlistwidgetitem5->setTextAlignment(Qt::AlignHCenter|Qt::AlignTop);
        __qlistwidgetitem5->setFont(font);
        __qlistwidgetitem5->setIcon(icon6);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/help"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listwgt);
        __qlistwidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignTop);
        __qlistwidgetitem6->setFont(font);
        __qlistwidgetitem6->setIcon(icon7);
        listwgt->setObjectName(QStringLiteral("listwgt"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listwgt->sizePolicy().hasHeightForWidth());
        listwgt->setSizePolicy(sizePolicy1);
        listwgt->setMaximumSize(QSize(70, 16777215));
        QPalette palette;
        QBrush brush(QColor(108, 108, 108, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(119, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        listwgt->setPalette(palette);
        listwgt->setMouseTracking(true);
        listwgt->setFocusPolicy(Qt::ClickFocus);
        listwgt->setStyleSheet(QLatin1String("background-image: url(:/backgroung/bgimage);\n"
"border: 1px solid gray;\n"
"border-radius: 6px;"));
        listwgt->setInputMethodHints(Qt::ImhSensitiveData);
        listwgt->setFrameShape(QFrame::NoFrame);
        listwgt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listwgt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listwgt->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        listwgt->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listwgt->setTabKeyNavigation(true);
        listwgt->setProperty("showDropIndicator", QVariant(true));
        listwgt->setDragDropMode(QAbstractItemView::DragDrop);
        listwgt->setSelectionBehavior(QAbstractItemView::SelectRows);
        listwgt->setIconSize(QSize(60, 60));
        listwgt->setTextElideMode(Qt::ElideNone);
        listwgt->setFlow(QListView::LeftToRight);
        listwgt->setProperty("isWrapping", QVariant(true));
        listwgt->setResizeMode(QListView::Adjust);
        listwgt->setSpacing(10);
        listwgt->setViewMode(QListView::IconMode);
        listwgt->setUniformItemSizes(true);
        listwgt->setSelectionRectVisible(true);

        hlyt_midle_->addWidget(listwgt);

        stackwgt = new QStackedWidget(centralwidget);
        stackwgt->setObjectName(QStringLiteral("stackwgt"));
        stackwgt->setAutoFillBackground(false);

        hlyt_midle_->addWidget(stackwgt);


        verticalLayout->addLayout(hlyt_midle_);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        listwgt->setCurrentRow(-1);
        stackwgt->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {

        const bool __sortingEnabled = listwgt->isSortingEnabled();
        listwgt->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listwgt->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Vente", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem->setToolTip(QApplication::translate("MainWindow", "Effectiuer la vente des articles", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem1 = listwgt->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Rapport", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem1->setToolTip(QApplication::translate("MainWindow", "Consulter l'historique des Ventes", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem2 = listwgt->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Produits", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem2->setToolTip(QApplication::translate("MainWindow", "Gestion des Articles", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem3 = listwgt->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "Stock", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem3->setToolTip(QApplication::translate("MainWindow", "D\303\251finir les stocks de produis, faire les inventaires", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem4 = listwgt->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "Compta", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem4->setToolTip(QApplication::translate("MainWindow", "Comptabiliter", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem5 = listwgt->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "Profils", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem5->setToolTip(QApplication::translate("MainWindow", "G\303\251rer les profils utilisateurs", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem6 = listwgt->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindow", "A Propos", Q_NULLPTR));
        listwgt->setSortingEnabled(__sortingEnabled);

        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
