/********************************************************************************
** Form generated from reading UI file 'reportingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTINGDIALOG_H
#define UI_REPORTINGDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_ReportingDialog
{
public:
    QAction *actn_add_;
    QAction *actn_enregistrer_;
    QAction *actn_delete_;
    QAction *actn_quit_;
    QGridLayout *gridlay;
    QHBoxLayout *hlay_mid;
    QLineEdit *search;
    QComboBox *cbox_field;
    QLabel *debut;
    QDateTimeEdit *from_date;
    QLabel *fin;
    QDateTimeEdit *to_date;
    QPushButton *go;
    QHBoxLayout *hlay_top;
    QComboBox *cbox_query;
    QPushButton *reload;
    QHBoxLayout *hlay_bottom;
    QLabel *nbitem;
    QSpacerItem *hspcr_left;
    QLabel *total;
    QLabel *total_value;
    QLabel *label;
    QTreeView *view_;

    void setupUi(QDialog *ReportingDialog)
    {
        if (ReportingDialog->objectName().isEmpty())
            ReportingDialog->setObjectName(QStringLiteral("ReportingDialog"));
        ReportingDialog->setEnabled(true);
        ReportingDialog->resize(900, 461);
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ReportingDialog->setWindowIcon(icon);
        ReportingDialog->setSizeGripEnabled(true);
        ReportingDialog->setModal(true);
        actn_add_ = new QAction(ReportingDialog);
        actn_add_->setObjectName(QStringLiteral("actn_add_"));
        actn_enregistrer_ = new QAction(ReportingDialog);
        actn_enregistrer_->setObjectName(QStringLiteral("actn_enregistrer_"));
        actn_delete_ = new QAction(ReportingDialog);
        actn_delete_->setObjectName(QStringLiteral("actn_delete_"));
        actn_quit_ = new QAction(ReportingDialog);
        actn_quit_->setObjectName(QStringLiteral("actn_quit_"));
        gridlay = new QGridLayout(ReportingDialog);
        gridlay->setObjectName(QStringLiteral("gridlay"));
        gridlay->setVerticalSpacing(0);
        gridlay->setContentsMargins(-1, -1, -1, 5);
        hlay_mid = new QHBoxLayout();
        hlay_mid->setObjectName(QStringLiteral("hlay_mid"));
        search = new QLineEdit(ReportingDialog);
        search->setObjectName(QStringLiteral("search"));
        search->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(search->sizePolicy().hasHeightForWidth());
        search->setSizePolicy(sizePolicy);
        search->setMinimumSize(QSize(250, 0));
        QFont font;
        font.setPointSize(10);
        search->setFont(font);
        search->setAutoFillBackground(false);
        search->setClearButtonEnabled(true);

        hlay_mid->addWidget(search);

        cbox_field = new QComboBox(ReportingDialog);
        cbox_field->setObjectName(QStringLiteral("cbox_field"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbox_field->sizePolicy().hasHeightForWidth());
        cbox_field->setSizePolicy(sizePolicy1);
        cbox_field->setMinimumSize(QSize(150, 0));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        cbox_field->setFont(font1);

        hlay_mid->addWidget(cbox_field);

        debut = new QLabel(ReportingDialog);
        debut->setObjectName(QStringLiteral("debut"));
        debut->setFont(font1);

        hlay_mid->addWidget(debut);

        from_date = new QDateTimeEdit(ReportingDialog);
        from_date->setObjectName(QStringLiteral("from_date"));
        from_date->setProperty("showGroupSeparator", QVariant(true));
        from_date->setDate(QDate(2017, 1, 1));
        from_date->setMaximumDate(QDate(2030, 12, 31));
        from_date->setMinimumDate(QDate(2000, 1, 1));
        from_date->setCalendarPopup(true);

        hlay_mid->addWidget(from_date);

        fin = new QLabel(ReportingDialog);
        fin->setObjectName(QStringLiteral("fin"));
        fin->setFont(font1);

        hlay_mid->addWidget(fin);

        to_date = new QDateTimeEdit(ReportingDialog);
        to_date->setObjectName(QStringLiteral("to_date"));
        to_date->setProperty("showGroupSeparator", QVariant(true));
        to_date->setDate(QDate(2017, 1, 1));
        to_date->setMaximumDate(QDate(2030, 12, 31));
        to_date->setMinimumDate(QDate(2000, 1, 1));
        to_date->setCalendarPopup(true);

        hlay_mid->addWidget(to_date);

        go = new QPushButton(ReportingDialog);
        go->setObjectName(QStringLiteral("go"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(go->sizePolicy().hasHeightForWidth());
        go->setSizePolicy(sizePolicy2);
        go->setMaximumSize(QSize(30, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/sales/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        go->setIcon(icon1);

        hlay_mid->addWidget(go);


        gridlay->addLayout(hlay_mid, 1, 0, 1, 1);

        hlay_top = new QHBoxLayout();
        hlay_top->setSpacing(0);
        hlay_top->setObjectName(QStringLiteral("hlay_top"));
        cbox_query = new QComboBox(ReportingDialog);
        cbox_query->setObjectName(QStringLiteral("cbox_query"));
        sizePolicy1.setHeightForWidth(cbox_query->sizePolicy().hasHeightForWidth());
        cbox_query->setSizePolicy(sizePolicy1);
        cbox_query->setMinimumSize(QSize(0, 0));
        cbox_query->setFont(font1);

        hlay_top->addWidget(cbox_query);

        reload = new QPushButton(ReportingDialog);
        reload->setObjectName(QStringLiteral("reload"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(reload->sizePolicy().hasHeightForWidth());
        reload->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/report/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        reload->setIcon(icon2);

        hlay_top->addWidget(reload);


        gridlay->addLayout(hlay_top, 0, 0, 1, 1);

        hlay_bottom = new QHBoxLayout();
        hlay_bottom->setSpacing(0);
        hlay_bottom->setObjectName(QStringLiteral("hlay_bottom"));
        nbitem = new QLabel(ReportingDialog);
        nbitem->setObjectName(QStringLiteral("nbitem"));
        nbitem->setMinimumSize(QSize(100, 0));
        nbitem->setFont(font1);

        hlay_bottom->addWidget(nbitem);

        hspcr_left = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlay_bottom->addItem(hspcr_left);

        total = new QLabel(ReportingDialog);
        total->setObjectName(QStringLiteral("total"));
        total->setMinimumSize(QSize(0, 25));
        total->setFont(font1);

        hlay_bottom->addWidget(total);

        total_value = new QLabel(ReportingDialog);
        total_value->setObjectName(QStringLiteral("total_value"));
        total_value->setFont(font1);
        total_value->setLayoutDirection(Qt::RightToLeft);
        total_value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        total_value->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        hlay_bottom->addWidget(total_value);

        label = new QLabel(ReportingDialog);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(15, 0));
        label->setMaximumSize(QSize(15, 16777215));
        label->setFont(font1);

        hlay_bottom->addWidget(label);


        gridlay->addLayout(hlay_bottom, 3, 0, 1, 1);

        view_ = new QTreeView(ReportingDialog);
        view_->setObjectName(QStringLiteral("view_"));
        view_->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        view_->setTabKeyNavigation(true);
        view_->setAlternatingRowColors(true);
        view_->setSelectionMode(QAbstractItemView::ExtendedSelection);
        view_->setTextElideMode(Qt::ElideMiddle);
        view_->setIndentation(50);
        view_->setRootIsDecorated(false);
        view_->setUniformRowHeights(true);
        view_->setSortingEnabled(true);
        view_->setAnimated(true);

        gridlay->addWidget(view_, 2, 0, 1, 1);


        retranslateUi(ReportingDialog);

        QMetaObject::connectSlotsByName(ReportingDialog);
    } // setupUi

    void retranslateUi(QDialog *ReportingDialog)
    {
        ReportingDialog->setWindowTitle(QApplication::translate("ReportingDialog", "Sales Point", Q_NULLPTR));
        actn_add_->setText(QApplication::translate("ReportingDialog", "Ajout manuel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_add_->setToolTip(QApplication::translate("ReportingDialog", "Ajouter manuellement un article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_add_->setShortcut(QApplication::translate("ReportingDialog", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_enregistrer_->setText(QApplication::translate("ReportingDialog", "Enregistrer les produits", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_enregistrer_->setToolTip(QApplication::translate("ReportingDialog", "Enregistrer les produits cr\303\251\303\251s", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_enregistrer_->setShortcut(QApplication::translate("ReportingDialog", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_delete_->setText(QApplication::translate("ReportingDialog", "Supprimer", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actn_delete_->setShortcut(QApplication::translate("ReportingDialog", "Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_quit_->setText(QApplication::translate("ReportingDialog", "Quiter la page", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_quit_->setToolTip(QApplication::translate("ReportingDialog", "Quiter la Page", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_quit_->setShortcut(QApplication::translate("ReportingDialog", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        search->setToolTip(QApplication::translate("ReportingDialog", "Specifier une valuer pour la recherche", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        search->setText(QString());
        search->setPlaceholderText(QApplication::translate("ReportingDialog", "Rechercher", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbox_field->setToolTip(QApplication::translate("ReportingDialog", "Selectionner le champ de recherche", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        debut->setText(QApplication::translate("ReportingDialog", "    D\303\251but     ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        from_date->setToolTip(QApplication::translate("ReportingDialog", "Date  de d\303\251but", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        fin->setText(QApplication::translate("ReportingDialog", "    Fin     ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        to_date->setToolTip(QApplication::translate("ReportingDialog", "Date de fin", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        go->setToolTip(QApplication::translate("ReportingDialog", "Lancer  le filtrage suivant la date ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        go->setText(QString());
#ifndef QT_NO_TOOLTIP
        cbox_query->setToolTip(QApplication::translate("ReportingDialog", "S\303\251lectionner l'Op\303\251ration", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        reload->setToolTip(QApplication::translate("ReportingDialog", "Actualiser", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        reload->setText(QString());
        nbitem->setText(QString());
        total->setText(QApplication::translate("ReportingDialog", "Total      ", Q_NULLPTR));
        total_value->setText(QString());
        label->setText(QString());
#ifndef QT_NO_TOOLTIP
        view_->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ReportingDialog: public Ui_ReportingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTINGDIALOG_H
