/********************************************************************************
** Form generated from reading UI file 'inventorydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYDIALOG_H
#define UI_INVENTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InventoryDialog
{
public:
    QAction *actn_add_;
    QAction *actn_list_;
    QAction *actn_validate_;
    QAction *actn_delete_;
    QAction *actn_full_screen_;
    QAction *actn_contiue_saling_;
    QGridLayout *mainlyt_;
    QTreeView *tview_items;
    QHBoxLayout *hlyt_bottom;
    QVBoxLayout *vlyt_bottom_amount;
    QSpacerItem *vspcr_amount;
    QHBoxLayout *hlyt_bottom_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtn_hold;
    QSpacerItem *hspcr_left;
    QPushButton *pbtn_validate;
    QSpacerItem *hspcr_rihgt;
    QPushButton *pbtn_cancel;
    QHBoxLayout *hlyt_mid;
    QLineEdit *ledit_reference;
    QPushButton *pbtn_add;
    QPushButton *pbtn_delete;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QFormLayout *fly_top;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *lbl_reponsable;
    QLabel *lbl_date_started;
    QLabel *lbl_date_ended;
    QLabel *label_1;

    void setupUi(QDialog *InventoryDialog)
    {
        if (InventoryDialog->objectName().isEmpty())
            InventoryDialog->setObjectName(QStringLiteral("InventoryDialog"));
        InventoryDialog->setEnabled(true);
        InventoryDialog->resize(735, 640);
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        InventoryDialog->setWindowIcon(icon);
        InventoryDialog->setSizeGripEnabled(true);
        InventoryDialog->setModal(false);
        actn_add_ = new QAction(InventoryDialog);
        actn_add_->setObjectName(QStringLiteral("actn_add_"));
        actn_list_ = new QAction(InventoryDialog);
        actn_list_->setObjectName(QStringLiteral("actn_list_"));
        actn_validate_ = new QAction(InventoryDialog);
        actn_validate_->setObjectName(QStringLiteral("actn_validate_"));
        actn_delete_ = new QAction(InventoryDialog);
        actn_delete_->setObjectName(QStringLiteral("actn_delete_"));
        actn_full_screen_ = new QAction(InventoryDialog);
        actn_full_screen_->setObjectName(QStringLiteral("actn_full_screen_"));
        actn_contiue_saling_ = new QAction(InventoryDialog);
        actn_contiue_saling_->setObjectName(QStringLiteral("actn_contiue_saling_"));
        mainlyt_ = new QGridLayout(InventoryDialog);
        mainlyt_->setSpacing(0);
        mainlyt_->setObjectName(QStringLiteral("mainlyt_"));
        mainlyt_->setContentsMargins(-1, 0, 2, -1);
        tview_items = new QTreeView(InventoryDialog);
        tview_items->setObjectName(QStringLiteral("tview_items"));
        tview_items->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(6);
        sizePolicy.setHeightForWidth(tview_items->sizePolicy().hasHeightForWidth());
        tview_items->setSizePolicy(sizePolicy);
        tview_items->setFrameShape(QFrame::StyledPanel);
        tview_items->setFrameShadow(QFrame::Raised);
        tview_items->setLineWidth(2);
        tview_items->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tview_items->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tview_items->setTabKeyNavigation(false);
        tview_items->setAlternatingRowColors(true);
        tview_items->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tview_items->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tview_items->setAutoExpandDelay(-1);
        tview_items->setRootIsDecorated(false);
        tview_items->setUniformRowHeights(true);
        tview_items->setItemsExpandable(false);
        tview_items->setSortingEnabled(true);
        tview_items->setAnimated(false);
        tview_items->setAllColumnsShowFocus(true);
        tview_items->setExpandsOnDoubleClick(false);
        tview_items->header()->setCascadingSectionResizes(true);
        tview_items->header()->setDefaultSectionSize(115);
        tview_items->header()->setMinimumSectionSize(115);
        tview_items->header()->setProperty("showSortIndicator", QVariant(false));
        tview_items->header()->setStretchLastSection(true);

        mainlyt_->addWidget(tview_items, 3, 0, 1, 1);

        hlyt_bottom = new QHBoxLayout();
        hlyt_bottom->setSpacing(0);
        hlyt_bottom->setObjectName(QStringLiteral("hlyt_bottom"));
        vlyt_bottom_amount = new QVBoxLayout();
        vlyt_bottom_amount->setObjectName(QStringLiteral("vlyt_bottom_amount"));
        vspcr_amount = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vlyt_bottom_amount->addItem(vspcr_amount);

        hlyt_bottom_btn = new QHBoxLayout();
        hlyt_bottom_btn->setSpacing(0);
        hlyt_bottom_btn->setObjectName(QStringLiteral("hlyt_bottom_btn"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_bottom_btn->addItem(horizontalSpacer);

        pbtn_hold = new QPushButton(InventoryDialog);
        pbtn_hold->setObjectName(QStringLiteral("pbtn_hold"));
        pbtn_hold->setMaximumSize(QSize(16777215, 23));
        QFont font;
        font.setPointSize(10);
        pbtn_hold->setFont(font);

        hlyt_bottom_btn->addWidget(pbtn_hold);

        hspcr_left = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hlyt_bottom_btn->addItem(hspcr_left);

        pbtn_validate = new QPushButton(InventoryDialog);
        pbtn_validate->setObjectName(QStringLiteral("pbtn_validate"));
        pbtn_validate->setMaximumSize(QSize(16777215, 23));
        pbtn_validate->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/sales/validate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_validate->setIcon(icon1);

        hlyt_bottom_btn->addWidget(pbtn_validate);

        hspcr_rihgt = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hlyt_bottom_btn->addItem(hspcr_rihgt);

        pbtn_cancel = new QPushButton(InventoryDialog);
        pbtn_cancel->setObjectName(QStringLiteral("pbtn_cancel"));
        pbtn_cancel->setMaximumSize(QSize(16777215, 23));
        pbtn_cancel->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/sales/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_cancel->setIcon(icon2);

        hlyt_bottom_btn->addWidget(pbtn_cancel);


        vlyt_bottom_amount->addLayout(hlyt_bottom_btn);


        hlyt_bottom->addLayout(vlyt_bottom_amount);


        mainlyt_->addLayout(hlyt_bottom, 6, 0, 1, 1);

        hlyt_mid = new QHBoxLayout();
        hlyt_mid->setSpacing(0);
        hlyt_mid->setObjectName(QStringLiteral("hlyt_mid"));
        hlyt_mid->setContentsMargins(-1, -1, -1, 0);
        ledit_reference = new QLineEdit(InventoryDialog);
        ledit_reference->setObjectName(QStringLiteral("ledit_reference"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ledit_reference->sizePolicy().hasHeightForWidth());
        ledit_reference->setSizePolicy(sizePolicy1);
        ledit_reference->setMinimumSize(QSize(255, 25));
        ledit_reference->setMaximumSize(QSize(16777215, 25));
        ledit_reference->setAutoFillBackground(false);
        ledit_reference->setClearButtonEnabled(true);

        hlyt_mid->addWidget(ledit_reference);

        pbtn_add = new QPushButton(InventoryDialog);
        pbtn_add->setObjectName(QStringLiteral("pbtn_add"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbtn_add->sizePolicy().hasHeightForWidth());
        pbtn_add->setSizePolicy(sizePolicy2);
        pbtn_add->setMinimumSize(QSize(22, 25));
        pbtn_add->setMaximumSize(QSize(16777215, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/sales/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_add->setIcon(icon3);

        hlyt_mid->addWidget(pbtn_add);

        pbtn_delete = new QPushButton(InventoryDialog);
        pbtn_delete->setObjectName(QStringLiteral("pbtn_delete"));
        pbtn_delete->setEnabled(false);
        sizePolicy2.setHeightForWidth(pbtn_delete->sizePolicy().hasHeightForWidth());
        pbtn_delete->setSizePolicy(sizePolicy2);
        pbtn_delete->setMinimumSize(QSize(22, 25));
        pbtn_delete->setMaximumSize(QSize(16777215, 25));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/sales/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_delete->setIcon(icon4);
        pbtn_delete->setCheckable(false);
        pbtn_delete->setFlat(false);

        hlyt_mid->addWidget(pbtn_delete);


        mainlyt_->addLayout(hlyt_mid, 1, 0, 1, 1);

        groupBox = new QGroupBox(InventoryDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fly_top = new QFormLayout();
        fly_top->setObjectName(QStringLiteral("fly_top"));
        fly_top->setLabelAlignment(Qt::AlignCenter);
        fly_top->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        fly_top->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        fly_top->setWidget(2, QFormLayout::LabelRole, label_3);

        lbl_reponsable = new QLabel(groupBox);
        lbl_reponsable->setObjectName(QStringLiteral("lbl_reponsable"));

        fly_top->setWidget(0, QFormLayout::FieldRole, lbl_reponsable);

        lbl_date_started = new QLabel(groupBox);
        lbl_date_started->setObjectName(QStringLiteral("lbl_date_started"));

        fly_top->setWidget(1, QFormLayout::FieldRole, lbl_date_started);

        lbl_date_ended = new QLabel(groupBox);
        lbl_date_ended->setObjectName(QStringLiteral("lbl_date_ended"));

        fly_top->setWidget(2, QFormLayout::FieldRole, lbl_date_ended);

        label_1 = new QLabel(groupBox);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setFont(font1);

        fly_top->setWidget(0, QFormLayout::LabelRole, label_1);


        horizontalLayout->addLayout(fly_top);


        mainlyt_->addWidget(groupBox, 0, 0, 1, 1);

        QWidget::setTabOrder(ledit_reference, pbtn_add);
        QWidget::setTabOrder(pbtn_add, pbtn_delete);
        QWidget::setTabOrder(pbtn_delete, tview_items);
        QWidget::setTabOrder(tview_items, pbtn_hold);
        QWidget::setTabOrder(pbtn_hold, pbtn_validate);
        QWidget::setTabOrder(pbtn_validate, pbtn_cancel);

        retranslateUi(InventoryDialog);

        QMetaObject::connectSlotsByName(InventoryDialog);
    } // setupUi

    void retranslateUi(QDialog *InventoryDialog)
    {
        InventoryDialog->setWindowTitle(QApplication::translate("InventoryDialog", "Inventaire Des Produits", Q_NULLPTR));
        actn_add_->setText(QApplication::translate("InventoryDialog", "Ajout manuel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_add_->setToolTip(QApplication::translate("InventoryDialog", "Ajouter manuellement un article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_add_->setShortcut(QApplication::translate("InventoryDialog", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_list_->setText(QApplication::translate("InventoryDialog", "Lister les articles", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_list_->setToolTip(QApplication::translate("InventoryDialog", "Lister les articles", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_list_->setShortcut(QApplication::translate("InventoryDialog", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_validate_->setText(QApplication::translate("InventoryDialog", "Valider Facture", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_validate_->setToolTip(QApplication::translate("InventoryDialog", "Valider Facture", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_validate_->setShortcut(QApplication::translate("InventoryDialog", "F3", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_delete_->setText(QApplication::translate("InventoryDialog", "Supprimer", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actn_delete_->setShortcut(QApplication::translate("InventoryDialog", "Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_full_screen_->setText(QApplication::translate("InventoryDialog", "Show Full Screen", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_full_screen_->setToolTip(QApplication::translate("InventoryDialog", "Show Full Screen", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_full_screen_->setShortcut(QApplication::translate("InventoryDialog", "F11", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_contiue_saling_->setText(QApplication::translate("InventoryDialog", "Contiue Saling ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_contiue_saling_->setToolTip(QApplication::translate("InventoryDialog", "Contiue Saling ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_contiue_saling_->setShortcut(QApplication::translate("InventoryDialog", "Esc", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pbtn_hold->setText(QApplication::translate("InventoryDialog", "&Imprimer", Q_NULLPTR));
        pbtn_validate->setText(QApplication::translate("InventoryDialog", "&Valider", Q_NULLPTR));
        pbtn_cancel->setText(QApplication::translate("InventoryDialog", "A&nnuler", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_reference->setToolTip(QApplication::translate("InventoryDialog", "Saisir la reference article ou le Code Barre ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_reference->setPlaceholderText(QApplication::translate("InventoryDialog", "Saisir la R\303\251f\303\251rence , le Libele ou le Code Bare du Produit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbtn_add->setToolTip(QApplication::translate("InventoryDialog", "Ajouter un  article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_add->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbtn_delete->setToolTip(QApplication::translate("InventoryDialog", "Supprimer un article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_delete->setText(QString());
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("InventoryDialog", "Debut               :", Q_NULLPTR));
        label_3->setText(QApplication::translate("InventoryDialog", "Fin                    :", Q_NULLPTR));
        lbl_reponsable->setText(QApplication::translate("InventoryDialog", "Nkouandou Aboubakar", Q_NULLPTR));
        lbl_date_started->setText(QApplication::translate("InventoryDialog", "17 Decembre 2019  a 16:30:25", Q_NULLPTR));
        lbl_date_ended->setText(QApplication::translate("InventoryDialog", "17 Decembre 2019  a 17:15:20", Q_NULLPTR));
        label_1->setText(QApplication::translate("InventoryDialog", "Responsable    :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InventoryDialog: public Ui_InventoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYDIALOG_H
