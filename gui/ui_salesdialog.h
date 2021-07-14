/********************************************************************************
** Form generated from reading UI file 'salesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALESDIALOG_H
#define UI_SALESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
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
#include "toolkit.h"

QT_BEGIN_NAMESPACE

class Ui_SalesDialog
{
public:
    QAction *actn_add_;
    QAction *actn_list_;
    QAction *actn_validate_;
    QAction *actn_delete_;
    QAction *actn_full_screen_;
    QAction *actn_contiue_saling_;
    QGridLayout *mainlyt_;
    QTreeView *tview_details_;
    QHBoxLayout *hlyt_bottom_;
    QTreeView *tview_en_attente_;
    QSpacerItem *hspcr_bottom_;
    QVBoxLayout *vlyt_bottom_amount_;
    QGroupBox *gbox_amount_;
    QFormLayout *formLayout;
    QLabel *lbl_devise_;
    QComboBox *cbox_devise_;
    QLabel *lbl_percu_;
    CurrencyEdit *ledit_percu_;
    QLabel *lbl_a_rendre_;
    QLabel *lbl_a_rendre_valeur_;
    QSpacerItem *vspcr_amount_;
    QHBoxLayout *hlyt_bottom_btn_;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbtn_hold_;
    QSpacerItem *hspcr_left_;
    QPushButton *pbtn_validate_;
    QSpacerItem *hspcr_rihgt_;
    QPushButton *pbtn_cancel_;
    QFrame *hline_;
    QHBoxLayout *hlyt_mid_;
    QLineEdit *ledit_reference_;
    QSpacerItem *hspcr_mid_left_;
    QLineEdit *ledit_client_;
    QPushButton *pbtn_search_;
    QSpacerItem *hspcr_mid_right_;
    QPushButton *pbtn_add_;
    QPushButton *pbtn_delete_;
    QHBoxLayout *horizontalLayout;
    QFormLayout *flyt_top_left_;
    QLabel *lbl_vendeur_;
    QComboBox *cbx_vendeur_;
    QLabel *lbl_tarif_;
    QComboBox *cbx_tarif_;
    QLabel *lbl_caissier_;
    QLabel *lbl_nom_caissier_;
    QSpacerItem *hspcr_top_;
    QLabel *lbl_total_valeur_;

    void setupUi(QDialog *SalesDialog)
    {
        if (SalesDialog->objectName().isEmpty())
            SalesDialog->setObjectName(QStringLiteral("SalesDialog"));
        SalesDialog->setEnabled(true);
        SalesDialog->resize(739, 640);
        SalesDialog->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        SalesDialog->setWindowIcon(icon);
        SalesDialog->setSizeGripEnabled(true);
        SalesDialog->setModal(false);
        actn_add_ = new QAction(SalesDialog);
        actn_add_->setObjectName(QStringLiteral("actn_add_"));
        actn_list_ = new QAction(SalesDialog);
        actn_list_->setObjectName(QStringLiteral("actn_list_"));
        actn_validate_ = new QAction(SalesDialog);
        actn_validate_->setObjectName(QStringLiteral("actn_validate_"));
        actn_delete_ = new QAction(SalesDialog);
        actn_delete_->setObjectName(QStringLiteral("actn_delete_"));
        actn_full_screen_ = new QAction(SalesDialog);
        actn_full_screen_->setObjectName(QStringLiteral("actn_full_screen_"));
        actn_contiue_saling_ = new QAction(SalesDialog);
        actn_contiue_saling_->setObjectName(QStringLiteral("actn_contiue_saling_"));
        mainlyt_ = new QGridLayout(SalesDialog);
        mainlyt_->setSpacing(0);
        mainlyt_->setObjectName(QStringLiteral("mainlyt_"));
        mainlyt_->setContentsMargins(-1, 0, 2, -1);
        tview_details_ = new QTreeView(SalesDialog);
        tview_details_->setObjectName(QStringLiteral("tview_details_"));
        tview_details_->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(tview_details_->sizePolicy().hasHeightForWidth());
        tview_details_->setSizePolicy(sizePolicy);
        tview_details_->setFrameShape(QFrame::StyledPanel);
        tview_details_->setFrameShadow(QFrame::Raised);
        tview_details_->setLineWidth(2);
        tview_details_->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tview_details_->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tview_details_->setTabKeyNavigation(false);
        tview_details_->setAlternatingRowColors(true);
        tview_details_->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tview_details_->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tview_details_->setAutoExpandDelay(-1);
        tview_details_->setRootIsDecorated(false);
        tview_details_->setUniformRowHeights(true);
        tview_details_->setItemsExpandable(false);
        tview_details_->setSortingEnabled(true);
        tview_details_->setAnimated(false);
        tview_details_->setAllColumnsShowFocus(true);
        tview_details_->setExpandsOnDoubleClick(false);
        tview_details_->header()->setCascadingSectionResizes(true);
        tview_details_->header()->setDefaultSectionSize(115);
        tview_details_->header()->setMinimumSectionSize(115);
        tview_details_->header()->setProperty("showSortIndicator", QVariant(false));
        tview_details_->header()->setStretchLastSection(true);

        mainlyt_->addWidget(tview_details_, 3, 0, 1, 1);

        hlyt_bottom_ = new QHBoxLayout();
        hlyt_bottom_->setSpacing(0);
        hlyt_bottom_->setObjectName(QStringLiteral("hlyt_bottom_"));
        tview_en_attente_ = new QTreeView(SalesDialog);
        tview_en_attente_->setObjectName(QStringLiteral("tview_en_attente_"));
        tview_en_attente_->setMinimumSize(QSize(410, 0));
        QFont font;
        font.setPointSize(10);
        tview_en_attente_->setFont(font);
        tview_en_attente_->setFrameShape(QFrame::StyledPanel);
        tview_en_attente_->setAlternatingRowColors(true);
        tview_en_attente_->setRootIsDecorated(false);

        hlyt_bottom_->addWidget(tview_en_attente_);

        hspcr_bottom_ = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_bottom_->addItem(hspcr_bottom_);

        vlyt_bottom_amount_ = new QVBoxLayout();
        vlyt_bottom_amount_->setObjectName(QStringLiteral("vlyt_bottom_amount_"));
        gbox_amount_ = new QGroupBox(SalesDialog);
        gbox_amount_->setObjectName(QStringLiteral("gbox_amount_"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gbox_amount_->sizePolicy().hasHeightForWidth());
        gbox_amount_->setSizePolicy(sizePolicy1);
        gbox_amount_->setFont(font);
        gbox_amount_->setTitle(QStringLiteral(""));
        gbox_amount_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        gbox_amount_->setFlat(false);
        gbox_amount_->setCheckable(false);
        gbox_amount_->setChecked(false);
        formLayout = new QFormLayout(gbox_amount_);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(5);
        formLayout->setContentsMargins(5, 0, 5, 0);
        lbl_devise_ = new QLabel(gbox_amount_);
        lbl_devise_->setObjectName(QStringLiteral("lbl_devise_"));
        lbl_devise_->setFont(font);
        lbl_devise_->setAutoFillBackground(false);
        lbl_devise_->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, lbl_devise_);

        cbox_devise_ = new QComboBox(gbox_amount_);
        cbox_devise_->setObjectName(QStringLiteral("cbox_devise_"));
        cbox_devise_->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbox_devise_->sizePolicy().hasHeightForWidth());
        cbox_devise_->setSizePolicy(sizePolicy2);
        cbox_devise_->setMaximumSize(QSize(16777215, 23));
        cbox_devise_->setEditable(false);
        cbox_devise_->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        formLayout->setWidget(0, QFormLayout::FieldRole, cbox_devise_);

        lbl_percu_ = new QLabel(gbox_amount_);
        lbl_percu_->setObjectName(QStringLiteral("lbl_percu_"));
        lbl_percu_->setFont(font);
        lbl_percu_->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_percu_);

        ledit_percu_ = new CurrencyEdit(gbox_amount_);
        ledit_percu_->setObjectName(QStringLiteral("ledit_percu_"));
        sizePolicy2.setHeightForWidth(ledit_percu_->sizePolicy().hasHeightForWidth());
        ledit_percu_->setSizePolicy(sizePolicy2);
        ledit_percu_->setMinimumSize(QSize(0, 0));
        ledit_percu_->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setPointSize(12);
        ledit_percu_->setFont(font1);
        ledit_percu_->setLayoutDirection(Qt::LeftToRight);
        ledit_percu_->setInputMethodHints(Qt::ImhPreferNumbers);
        ledit_percu_->setCursorPosition(0);
        ledit_percu_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ledit_percu_->setReadOnly(false);
        ledit_percu_->setClearButtonEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, ledit_percu_);

        lbl_a_rendre_ = new QLabel(gbox_amount_);
        lbl_a_rendre_->setObjectName(QStringLiteral("lbl_a_rendre_"));
        lbl_a_rendre_->setMinimumSize(QSize(0, 30));
        lbl_a_rendre_->setFont(font);
        lbl_a_rendre_->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        formLayout->setWidget(2, QFormLayout::LabelRole, lbl_a_rendre_);

        lbl_a_rendre_valeur_ = new QLabel(gbox_amount_);
        lbl_a_rendre_valeur_->setObjectName(QStringLiteral("lbl_a_rendre_valeur_"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lbl_a_rendre_valeur_->sizePolicy().hasHeightForWidth());
        lbl_a_rendre_valeur_->setSizePolicy(sizePolicy3);
        lbl_a_rendre_valeur_->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setPointSize(40);
        lbl_a_rendre_valeur_->setFont(font2);
        lbl_a_rendre_valeur_->setLayoutDirection(Qt::LeftToRight);
        lbl_a_rendre_valeur_->setAutoFillBackground(false);
        lbl_a_rendre_valeur_->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        lbl_a_rendre_valeur_->setLineWidth(0);
        lbl_a_rendre_valeur_->setScaledContents(true);
        lbl_a_rendre_valeur_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, lbl_a_rendre_valeur_);


        vlyt_bottom_amount_->addWidget(gbox_amount_);

        vspcr_amount_ = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vlyt_bottom_amount_->addItem(vspcr_amount_);

        hlyt_bottom_btn_ = new QHBoxLayout();
        hlyt_bottom_btn_->setSpacing(0);
        hlyt_bottom_btn_->setObjectName(QStringLiteral("hlyt_bottom_btn_"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_bottom_btn_->addItem(horizontalSpacer);

        pbtn_hold_ = new QPushButton(SalesDialog);
        pbtn_hold_->setObjectName(QStringLiteral("pbtn_hold_"));
        pbtn_hold_->setMaximumSize(QSize(16777215, 23));
        pbtn_hold_->setFont(font);

        hlyt_bottom_btn_->addWidget(pbtn_hold_);

        hspcr_left_ = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hlyt_bottom_btn_->addItem(hspcr_left_);

        pbtn_validate_ = new QPushButton(SalesDialog);
        pbtn_validate_->setObjectName(QStringLiteral("pbtn_validate_"));
        pbtn_validate_->setMaximumSize(QSize(16777215, 23));
        pbtn_validate_->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/sales/validate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_validate_->setIcon(icon1);

        hlyt_bottom_btn_->addWidget(pbtn_validate_);

        hspcr_rihgt_ = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hlyt_bottom_btn_->addItem(hspcr_rihgt_);

        pbtn_cancel_ = new QPushButton(SalesDialog);
        pbtn_cancel_->setObjectName(QStringLiteral("pbtn_cancel_"));
        pbtn_cancel_->setMaximumSize(QSize(16777215, 23));
        pbtn_cancel_->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/sales/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_cancel_->setIcon(icon2);

        hlyt_bottom_btn_->addWidget(pbtn_cancel_);


        vlyt_bottom_amount_->addLayout(hlyt_bottom_btn_);


        hlyt_bottom_->addLayout(vlyt_bottom_amount_);


        mainlyt_->addLayout(hlyt_bottom_, 6, 0, 1, 1);

        hline_ = new QFrame(SalesDialog);
        hline_->setObjectName(QStringLiteral("hline_"));
        hline_->setFrameShadow(QFrame::Raised);
        hline_->setFrameShape(QFrame::HLine);

        mainlyt_->addWidget(hline_, 1, 0, 1, 1);

        hlyt_mid_ = new QHBoxLayout();
        hlyt_mid_->setSpacing(0);
        hlyt_mid_->setObjectName(QStringLiteral("hlyt_mid_"));
        hlyt_mid_->setContentsMargins(-1, -1, -1, 0);
        ledit_reference_ = new QLineEdit(SalesDialog);
        ledit_reference_->setObjectName(QStringLiteral("ledit_reference_"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ledit_reference_->sizePolicy().hasHeightForWidth());
        ledit_reference_->setSizePolicy(sizePolicy4);
        ledit_reference_->setMinimumSize(QSize(255, 25));
        ledit_reference_->setMaximumSize(QSize(16777215, 25));
        ledit_reference_->setAutoFillBackground(false);
        ledit_reference_->setClearButtonEnabled(true);

        hlyt_mid_->addWidget(ledit_reference_);

        hspcr_mid_left_ = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hlyt_mid_->addItem(hspcr_mid_left_);

        ledit_client_ = new QLineEdit(SalesDialog);
        ledit_client_->setObjectName(QStringLiteral("ledit_client_"));
        sizePolicy2.setHeightForWidth(ledit_client_->sizePolicy().hasHeightForWidth());
        ledit_client_->setSizePolicy(sizePolicy2);
        ledit_client_->setMinimumSize(QSize(250, 25));
        ledit_client_->setMaximumSize(QSize(16777215, 25));
        ledit_client_->setClearButtonEnabled(true);

        hlyt_mid_->addWidget(ledit_client_);

        pbtn_search_ = new QPushButton(SalesDialog);
        pbtn_search_->setObjectName(QStringLiteral("pbtn_search_"));
        pbtn_search_->setEnabled(false);
        sizePolicy4.setHeightForWidth(pbtn_search_->sizePolicy().hasHeightForWidth());
        pbtn_search_->setSizePolicy(sizePolicy4);
        pbtn_search_->setMinimumSize(QSize(22, 25));
        pbtn_search_->setMaximumSize(QSize(16777215, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/sales/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_search_->setIcon(icon3);

        hlyt_mid_->addWidget(pbtn_search_);

        hspcr_mid_right_ = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_mid_->addItem(hspcr_mid_right_);

        pbtn_add_ = new QPushButton(SalesDialog);
        pbtn_add_->setObjectName(QStringLiteral("pbtn_add_"));
        sizePolicy4.setHeightForWidth(pbtn_add_->sizePolicy().hasHeightForWidth());
        pbtn_add_->setSizePolicy(sizePolicy4);
        pbtn_add_->setMinimumSize(QSize(22, 25));
        pbtn_add_->setMaximumSize(QSize(16777215, 25));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/sales/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_add_->setIcon(icon4);

        hlyt_mid_->addWidget(pbtn_add_);

        pbtn_delete_ = new QPushButton(SalesDialog);
        pbtn_delete_->setObjectName(QStringLiteral("pbtn_delete_"));
        pbtn_delete_->setEnabled(false);
        sizePolicy4.setHeightForWidth(pbtn_delete_->sizePolicy().hasHeightForWidth());
        pbtn_delete_->setSizePolicy(sizePolicy4);
        pbtn_delete_->setMinimumSize(QSize(22, 25));
        pbtn_delete_->setMaximumSize(QSize(16777215, 25));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/sales/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_delete_->setIcon(icon5);
        pbtn_delete_->setCheckable(false);
        pbtn_delete_->setFlat(false);

        hlyt_mid_->addWidget(pbtn_delete_);


        mainlyt_->addLayout(hlyt_mid_, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        flyt_top_left_ = new QFormLayout();
        flyt_top_left_->setObjectName(QStringLiteral("flyt_top_left_"));
        flyt_top_left_->setLabelAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        flyt_top_left_->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        flyt_top_left_->setHorizontalSpacing(5);
        flyt_top_left_->setVerticalSpacing(5);
        flyt_top_left_->setContentsMargins(-1, 0, -1, -1);
        lbl_vendeur_ = new QLabel(SalesDialog);
        lbl_vendeur_->setObjectName(QStringLiteral("lbl_vendeur_"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lbl_vendeur_->sizePolicy().hasHeightForWidth());
        lbl_vendeur_->setSizePolicy(sizePolicy5);
        lbl_vendeur_->setMinimumSize(QSize(100, 16));
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        lbl_vendeur_->setFont(font3);
        lbl_vendeur_->setLayoutDirection(Qt::LeftToRight);
        lbl_vendeur_->setMargin(5);
        lbl_vendeur_->setIndent(0);

        flyt_top_left_->setWidget(1, QFormLayout::LabelRole, lbl_vendeur_);

        cbx_vendeur_ = new QComboBox(SalesDialog);
        cbx_vendeur_->setObjectName(QStringLiteral("cbx_vendeur_"));
        sizePolicy2.setHeightForWidth(cbx_vendeur_->sizePolicy().hasHeightForWidth());
        cbx_vendeur_->setSizePolicy(sizePolicy2);
        cbx_vendeur_->setMinimumSize(QSize(110, 23));
        cbx_vendeur_->setMaximumSize(QSize(16777215, 23));
        cbx_vendeur_->setBaseSize(QSize(0, 0));

        flyt_top_left_->setWidget(1, QFormLayout::FieldRole, cbx_vendeur_);

        lbl_tarif_ = new QLabel(SalesDialog);
        lbl_tarif_->setObjectName(QStringLiteral("lbl_tarif_"));
        sizePolicy5.setHeightForWidth(lbl_tarif_->sizePolicy().hasHeightForWidth());
        lbl_tarif_->setSizePolicy(sizePolicy5);
        lbl_tarif_->setMinimumSize(QSize(100, 16));
        lbl_tarif_->setFont(font3);
        lbl_tarif_->setMargin(3);
        lbl_tarif_->setIndent(0);

        flyt_top_left_->setWidget(2, QFormLayout::LabelRole, lbl_tarif_);

        cbx_tarif_ = new QComboBox(SalesDialog);
        cbx_tarif_->setObjectName(QStringLiteral("cbx_tarif_"));
        sizePolicy2.setHeightForWidth(cbx_tarif_->sizePolicy().hasHeightForWidth());
        cbx_tarif_->setSizePolicy(sizePolicy2);
        cbx_tarif_->setMinimumSize(QSize(110, 23));
        cbx_tarif_->setMaximumSize(QSize(16777215, 23));

        flyt_top_left_->setWidget(2, QFormLayout::FieldRole, cbx_tarif_);

        lbl_caissier_ = new QLabel(SalesDialog);
        lbl_caissier_->setObjectName(QStringLiteral("lbl_caissier_"));
        sizePolicy4.setHeightForWidth(lbl_caissier_->sizePolicy().hasHeightForWidth());
        lbl_caissier_->setSizePolicy(sizePolicy4);
        lbl_caissier_->setMinimumSize(QSize(100, 16));
        lbl_caissier_->setFont(font3);
        lbl_caissier_->setMargin(5);
        lbl_caissier_->setIndent(0);

        flyt_top_left_->setWidget(0, QFormLayout::LabelRole, lbl_caissier_);

        lbl_nom_caissier_ = new QLabel(SalesDialog);
        lbl_nom_caissier_->setObjectName(QStringLiteral("lbl_nom_caissier_"));
        sizePolicy2.setHeightForWidth(lbl_nom_caissier_->sizePolicy().hasHeightForWidth());
        lbl_nom_caissier_->setSizePolicy(sizePolicy2);
        lbl_nom_caissier_->setMinimumSize(QSize(150, 22));
        QFont font4;
        font4.setItalic(false);
        lbl_nom_caissier_->setFont(font4);
        lbl_nom_caissier_->setIndent(0);

        flyt_top_left_->setWidget(0, QFormLayout::FieldRole, lbl_nom_caissier_);


        horizontalLayout->addLayout(flyt_top_left_);

        hspcr_top_ = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(hspcr_top_);

        lbl_total_valeur_ = new QLabel(SalesDialog);
        lbl_total_valeur_->setObjectName(QStringLiteral("lbl_total_valeur_"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(1);
        sizePolicy6.setHeightForWidth(lbl_total_valeur_->sizePolicy().hasHeightForWidth());
        lbl_total_valeur_->setSizePolicy(sizePolicy6);
        lbl_total_valeur_->setMinimumSize(QSize(400, 70));
        lbl_total_valeur_->setMaximumSize(QSize(16777215, 80));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(50, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(212, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(85, 127, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(113, 170, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush7(QColor(170, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lbl_total_valeur_->setPalette(palette);
        QFont font5;
        font5.setPointSize(65);
        lbl_total_valeur_->setFont(font5);
        lbl_total_valeur_->setLayoutDirection(Qt::LeftToRight);
        lbl_total_valeur_->setAutoFillBackground(false);
        lbl_total_valeur_->setStyleSheet(QLatin1String("background-image: url(:/backgroung/total);\n"
"border: 1px solid gray; \n"
"border-radius: 8px;"));
        lbl_total_valeur_->setFrameShape(QFrame::NoFrame);
        lbl_total_valeur_->setFrameShadow(QFrame::Sunken);
        lbl_total_valeur_->setLineWidth(0);
        lbl_total_valeur_->setScaledContents(true);
        lbl_total_valeur_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_total_valeur_->setIndent(0);

        horizontalLayout->addWidget(lbl_total_valeur_);


        mainlyt_->addLayout(horizontalLayout, 0, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        lbl_devise_->setBuddy(cbox_devise_);
        lbl_percu_->setBuddy(ledit_percu_);
        lbl_vendeur_->setBuddy(cbx_vendeur_);
        lbl_tarif_->setBuddy(cbx_tarif_);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(ledit_reference_, ledit_client_);
        QWidget::setTabOrder(ledit_client_, pbtn_search_);
        QWidget::setTabOrder(pbtn_search_, pbtn_add_);
        QWidget::setTabOrder(pbtn_add_, pbtn_delete_);
        QWidget::setTabOrder(pbtn_delete_, tview_details_);
        QWidget::setTabOrder(tview_details_, tview_en_attente_);
        QWidget::setTabOrder(tview_en_attente_, cbox_devise_);
        QWidget::setTabOrder(cbox_devise_, ledit_percu_);
        QWidget::setTabOrder(ledit_percu_, pbtn_hold_);
        QWidget::setTabOrder(pbtn_hold_, pbtn_validate_);
        QWidget::setTabOrder(pbtn_validate_, pbtn_cancel_);

        retranslateUi(SalesDialog);

        cbox_devise_->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SalesDialog);
    } // setupUi

    void retranslateUi(QDialog *SalesDialog)
    {
        SalesDialog->setWindowTitle(QApplication::translate("SalesDialog", "Sales Point", Q_NULLPTR));
        actn_add_->setText(QApplication::translate("SalesDialog", "Ajout manuel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_add_->setToolTip(QApplication::translate("SalesDialog", "Ajouter manuellement un article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_add_->setShortcut(QApplication::translate("SalesDialog", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_list_->setText(QApplication::translate("SalesDialog", "Lister les articles", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_list_->setToolTip(QApplication::translate("SalesDialog", "Lister les articles", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_list_->setShortcut(QApplication::translate("SalesDialog", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_validate_->setText(QApplication::translate("SalesDialog", "Valider Facture", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_validate_->setToolTip(QApplication::translate("SalesDialog", "Valider Facture", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_validate_->setShortcut(QApplication::translate("SalesDialog", "F3", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_delete_->setText(QApplication::translate("SalesDialog", "Supprimer", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actn_delete_->setShortcut(QApplication::translate("SalesDialog", "Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_full_screen_->setText(QApplication::translate("SalesDialog", "Show Full Screen", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_full_screen_->setToolTip(QApplication::translate("SalesDialog", "Show Full Screen", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_full_screen_->setShortcut(QApplication::translate("SalesDialog", "F11", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_contiue_saling_->setText(QApplication::translate("SalesDialog", "Contiue Saling ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_contiue_saling_->setToolTip(QApplication::translate("SalesDialog", "Contiue Saling ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_contiue_saling_->setShortcut(QApplication::translate("SalesDialog", "Esc", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        lbl_devise_->setText(QApplication::translate("SalesDialog", "&R\303\250glement", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbox_devise_->setToolTip(QApplication::translate("SalesDialog", "D\303\251finir le mode de r\303\251glement", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cbox_devise_->setCurrentText(QString());
        lbl_percu_->setText(QApplication::translate("SalesDialog", "&Per\303\247u", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_percu_->setToolTip(QApplication::translate("SalesDialog", "Entrer le montant percu du Client", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_percu_->setText(QString());
        ledit_percu_->setPlaceholderText(QApplication::translate("SalesDialog", "Montant Percu", Q_NULLPTR));
        lbl_a_rendre_->setText(QApplication::translate("SalesDialog", "A Rendre", Q_NULLPTR));
        lbl_a_rendre_valeur_->setText(QString());
        pbtn_hold_->setText(QApplication::translate("SalesDialog", "&Attendre", Q_NULLPTR));
        pbtn_validate_->setText(QApplication::translate("SalesDialog", "&Valider", Q_NULLPTR));
        pbtn_cancel_->setText(QApplication::translate("SalesDialog", "A&nnuler", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_reference_->setToolTip(QApplication::translate("SalesDialog", "Saisir la reference article ou le Code Barre ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_reference_->setPlaceholderText(QApplication::translate("SalesDialog", "R\303\251f\303\251rence", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_client_->setToolTip(QApplication::translate("SalesDialog", "Entrer  le Nom ou le Numero de Telephone du client ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_client_->setPlaceholderText(QApplication::translate("SalesDialog", "Nom et/ou Pr\303\251nom du Client", Q_NULLPTR));
        pbtn_search_->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbtn_add_->setToolTip(QApplication::translate("SalesDialog", "Ajouter un  article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_add_->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbtn_delete_->setToolTip(QApplication::translate("SalesDialog", "Supprimer un article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_delete_->setText(QString());
        lbl_vendeur_->setText(QApplication::translate("SalesDialog", "Vendeur", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbx_vendeur_->setToolTip(QApplication::translate("SalesDialog", "Choisir le Vendeur", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lbl_tarif_->setText(QApplication::translate("SalesDialog", "&Tarif", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbx_tarif_->setToolTip(QApplication::translate("SalesDialog", "Sp\303\251cifier le tarifs de vente", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lbl_caissier_->setText(QApplication::translate("SalesDialog", "Caissier", Q_NULLPTR));
        lbl_nom_caissier_->setText(QString());
        lbl_total_valeur_->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SalesDialog: public Ui_SalesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALESDIALOG_H
