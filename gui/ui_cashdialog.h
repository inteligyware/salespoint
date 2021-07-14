/********************************************************************************
** Form generated from reading UI file 'cashdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHDIALOG_H
#define UI_CASHDIALOG_H

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
#include <QtWidgets/QWidget>

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
    QGridLayout *gridLayout;
    QHBoxLayout *hlyt_bottom_;
    QTreeView *tview_en_attente_;
    QSpacerItem *hspcr_bottom_;
    QVBoxLayout *vlyt_bottom_amount__;
    QGroupBox *gbox_amount_;
    QFormLayout *formLayout;
    QLabel *lbl_devise_;
    QComboBox *cbox_devise_;
    QLabel *lbl_percu_;
    QLineEdit *ledit_percu_;
    QLabel *lbl_a_rendre_;
    QLabel *lbl_a_rendre_valeur_;
    QSpacerItem *vspcr_amount_;
    QHBoxLayout *hlyt_bottom_btn_;
    QPushButton *pbtn_hold_;
    QSpacerItem *hspcr_bottom_right_;
    QPushButton *pbtn_validate_;
    QSpacerItem *hspcr_bottom_left_;
    QPushButton *pbtn_cancel_;
    QHBoxLayout *horizontalLayout;
    QFormLayout *flyt_top_left_;
    QLabel *lbl_vendeur_;
    QComboBox *cbx_vendeur_;
    QLabel *lbl_tarif_;
    QComboBox *cbx_tarif_;
    QLabel *lbl_depot_;
    QComboBox *cbx_depot_;
    QFrame *vline_top_left_;
    QGroupBox *gbx_client_;
    QWidget *layoutWidget_3;
    QFormLayout *flyt_top_right_;
    QLineEdit *ledit_ident_;
    QLineEdit *ledit_nom_;
    QLabel *lbl_ass_;
    QComboBox *cbx_ass_;
    QLabel *lbl_ref_ass_;
    QLineEdit *ledit_ref_ass_;
    QFrame *vline_top_right_;
    QSpacerItem *hspcr_total_;
    QLabel *lbl_total_;
    QLabel *lbl_total_valeur_;
    QFrame *hline_top_;
    QTreeView *tview_details_;
    QHBoxLayout *hlyt_mid_;
    QLineEdit *ledit_reference_;
    QSpacerItem *hspcr_mid_left_;
    QSpacerItem *hspcr_mid_right_;
    QPushButton *pbtn_add_;
    QPushButton *pbtn_delete_;

    void setupUi(QDialog *SalesDialog)
    {
        if (SalesDialog->objectName().isEmpty())
            SalesDialog->setObjectName(QStringLiteral("SalesDialog"));
        SalesDialog->setEnabled(true);
        SalesDialog->resize(1134, 515);
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        SalesDialog->setWindowIcon(icon);
        SalesDialog->setSizeGripEnabled(true);
        SalesDialog->setModal(true);
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
        gridLayout = new QGridLayout(SalesDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hlyt_bottom_ = new QHBoxLayout();
        hlyt_bottom_->setSpacing(0);
        hlyt_bottom_->setObjectName(QStringLiteral("hlyt_bottom_"));
        tview_en_attente_ = new QTreeView(SalesDialog);
        tview_en_attente_->setObjectName(QStringLiteral("tview_en_attente_"));
        tview_en_attente_->setMinimumSize(QSize(490, 0));
        tview_en_attente_->setFrameShape(QFrame::StyledPanel);

        hlyt_bottom_->addWidget(tview_en_attente_);

        hspcr_bottom_ = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_bottom_->addItem(hspcr_bottom_);

        vlyt_bottom_amount__ = new QVBoxLayout();
        vlyt_bottom_amount__->setObjectName(QStringLiteral("vlyt_bottom_amount__"));
        gbox_amount_ = new QGroupBox(SalesDialog);
        gbox_amount_->setObjectName(QStringLiteral("gbox_amount_"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbox_amount_->sizePolicy().hasHeightForWidth());
        gbox_amount_->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
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
        formLayout->setHorizontalSpacing(5);
        formLayout->setVerticalSpacing(5);
        formLayout->setContentsMargins(9, 9, 9, 9);
        lbl_devise_ = new QLabel(gbox_amount_);
        lbl_devise_->setObjectName(QStringLiteral("lbl_devise_"));
        lbl_devise_->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, lbl_devise_);

        cbox_devise_ = new QComboBox(gbox_amount_);
        cbox_devise_->setObjectName(QStringLiteral("cbox_devise_"));
        cbox_devise_->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbox_devise_->sizePolicy().hasHeightForWidth());
        cbox_devise_->setSizePolicy(sizePolicy1);
        cbox_devise_->setMinimumSize(QSize(0, 25));
        cbox_devise_->setEditable(false);
        cbox_devise_->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        formLayout->setWidget(0, QFormLayout::FieldRole, cbox_devise_);

        lbl_percu_ = new QLabel(gbox_amount_);
        lbl_percu_->setObjectName(QStringLiteral("lbl_percu_"));
        lbl_percu_->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_percu_);

        ledit_percu_ = new QLineEdit(gbox_amount_);
        ledit_percu_->setObjectName(QStringLiteral("ledit_percu_"));
        ledit_percu_->setMinimumSize(QSize(0, 25));
        ledit_percu_->setLayoutDirection(Qt::LeftToRight);
        ledit_percu_->setInputMethodHints(Qt::ImhPreferNumbers);
        ledit_percu_->setCursorPosition(1);
        ledit_percu_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ledit_percu_->setReadOnly(false);
        ledit_percu_->setClearButtonEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, ledit_percu_);

        lbl_a_rendre_ = new QLabel(gbox_amount_);
        lbl_a_rendre_->setObjectName(QStringLiteral("lbl_a_rendre_"));
        lbl_a_rendre_->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, lbl_a_rendre_);

        lbl_a_rendre_valeur_ = new QLabel(gbox_amount_);
        lbl_a_rendre_valeur_->setObjectName(QStringLiteral("lbl_a_rendre_valeur_"));
        lbl_a_rendre_valeur_->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setPointSize(25);
        font1.setBold(false);
        font1.setWeight(50);
        lbl_a_rendre_valeur_->setFont(font1);
        lbl_a_rendre_valeur_->setFocusPolicy(Qt::StrongFocus);
        lbl_a_rendre_valeur_->setLayoutDirection(Qt::LeftToRight);
        lbl_a_rendre_valeur_->setAutoFillBackground(false);
        lbl_a_rendre_valeur_->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        lbl_a_rendre_valeur_->setTextFormat(Qt::PlainText);
        lbl_a_rendre_valeur_->setScaledContents(false);
        lbl_a_rendre_valeur_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_a_rendre_valeur_->setIndent(0);

        formLayout->setWidget(2, QFormLayout::FieldRole, lbl_a_rendre_valeur_);


        vlyt_bottom_amount__->addWidget(gbox_amount_);

        vspcr_amount_ = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vlyt_bottom_amount__->addItem(vspcr_amount_);

        hlyt_bottom_btn_ = new QHBoxLayout();
        hlyt_bottom_btn_->setSpacing(0);
        hlyt_bottom_btn_->setObjectName(QStringLiteral("hlyt_bottom_btn_"));
        pbtn_hold_ = new QPushButton(SalesDialog);
        pbtn_hold_->setObjectName(QStringLiteral("pbtn_hold_"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbtn_hold_->sizePolicy().hasHeightForWidth());
        pbtn_hold_->setSizePolicy(sizePolicy2);

        hlyt_bottom_btn_->addWidget(pbtn_hold_);

        hspcr_bottom_right_ = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_bottom_btn_->addItem(hspcr_bottom_right_);

        pbtn_validate_ = new QPushButton(SalesDialog);
        pbtn_validate_->setObjectName(QStringLiteral("pbtn_validate_"));
        pbtn_validate_->setMaximumSize(QSize(16777215, 16777215));
        pbtn_validate_->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/sales/validate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_validate_->setIcon(icon1);

        hlyt_bottom_btn_->addWidget(pbtn_validate_);

        hspcr_bottom_left_ = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_bottom_btn_->addItem(hspcr_bottom_left_);

        pbtn_cancel_ = new QPushButton(SalesDialog);
        pbtn_cancel_->setObjectName(QStringLiteral("pbtn_cancel_"));
        pbtn_cancel_->setMaximumSize(QSize(16777215, 16777215));
        pbtn_cancel_->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/sales/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_cancel_->setIcon(icon2);

        hlyt_bottom_btn_->addWidget(pbtn_cancel_);


        vlyt_bottom_amount__->addLayout(hlyt_bottom_btn_);


        hlyt_bottom_->addLayout(vlyt_bottom_amount__);


        gridLayout->addLayout(hlyt_bottom_, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        flyt_top_left_ = new QFormLayout();
        flyt_top_left_->setObjectName(QStringLiteral("flyt_top_left_"));
        flyt_top_left_->setHorizontalSpacing(5);
        flyt_top_left_->setVerticalSpacing(15);
        flyt_top_left_->setContentsMargins(5, 15, 10, -1);
        lbl_vendeur_ = new QLabel(SalesDialog);
        lbl_vendeur_->setObjectName(QStringLiteral("lbl_vendeur_"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lbl_vendeur_->sizePolicy().hasHeightForWidth());
        lbl_vendeur_->setSizePolicy(sizePolicy3);
        lbl_vendeur_->setMinimumSize(QSize(60, 16));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        lbl_vendeur_->setFont(font2);
        lbl_vendeur_->setLayoutDirection(Qt::LeftToRight);

        flyt_top_left_->setWidget(0, QFormLayout::LabelRole, lbl_vendeur_);

        cbx_vendeur_ = new QComboBox(SalesDialog);
        cbx_vendeur_->setObjectName(QStringLiteral("cbx_vendeur_"));
        sizePolicy3.setHeightForWidth(cbx_vendeur_->sizePolicy().hasHeightForWidth());
        cbx_vendeur_->setSizePolicy(sizePolicy3);
        cbx_vendeur_->setMinimumSize(QSize(130, 22));
        cbx_vendeur_->setBaseSize(QSize(0, 0));

        flyt_top_left_->setWidget(0, QFormLayout::FieldRole, cbx_vendeur_);

        lbl_tarif_ = new QLabel(SalesDialog);
        lbl_tarif_->setObjectName(QStringLiteral("lbl_tarif_"));
        sizePolicy3.setHeightForWidth(lbl_tarif_->sizePolicy().hasHeightForWidth());
        lbl_tarif_->setSizePolicy(sizePolicy3);
        lbl_tarif_->setMinimumSize(QSize(60, 16));
        lbl_tarif_->setFont(font2);

        flyt_top_left_->setWidget(1, QFormLayout::LabelRole, lbl_tarif_);

        cbx_tarif_ = new QComboBox(SalesDialog);
        cbx_tarif_->setObjectName(QStringLiteral("cbx_tarif_"));
        sizePolicy3.setHeightForWidth(cbx_tarif_->sizePolicy().hasHeightForWidth());
        cbx_tarif_->setSizePolicy(sizePolicy3);
        cbx_tarif_->setMinimumSize(QSize(100, 22));

        flyt_top_left_->setWidget(1, QFormLayout::FieldRole, cbx_tarif_);

        lbl_depot_ = new QLabel(SalesDialog);
        lbl_depot_->setObjectName(QStringLiteral("lbl_depot_"));
        lbl_depot_->setEnabled(true);
        sizePolicy3.setHeightForWidth(lbl_depot_->sizePolicy().hasHeightForWidth());
        lbl_depot_->setSizePolicy(sizePolicy3);
        lbl_depot_->setMinimumSize(QSize(60, 16));
        lbl_depot_->setFont(font2);

        flyt_top_left_->setWidget(2, QFormLayout::LabelRole, lbl_depot_);

        cbx_depot_ = new QComboBox(SalesDialog);
        cbx_depot_->setObjectName(QStringLiteral("cbx_depot_"));
        sizePolicy3.setHeightForWidth(cbx_depot_->sizePolicy().hasHeightForWidth());
        cbx_depot_->setSizePolicy(sizePolicy3);
        cbx_depot_->setMinimumSize(QSize(100, 22));

        flyt_top_left_->setWidget(2, QFormLayout::FieldRole, cbx_depot_);


        horizontalLayout->addLayout(flyt_top_left_);

        vline_top_left_ = new QFrame(SalesDialog);
        vline_top_left_->setObjectName(QStringLiteral("vline_top_left_"));
        vline_top_left_->setFrameShape(QFrame::VLine);
        vline_top_left_->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(vline_top_left_);

        gbx_client_ = new QGroupBox(SalesDialog);
        gbx_client_->setObjectName(QStringLiteral("gbx_client_"));
        gbx_client_->setEnabled(true);
        gbx_client_->setMinimumSize(QSize(270, 130));
        gbx_client_->setFlat(true);
        gbx_client_->setCheckable(true);
        gbx_client_->setChecked(false);
        layoutWidget_3 = new QWidget(gbx_client_);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 20, 251, 113));
        flyt_top_right_ = new QFormLayout(layoutWidget_3);
        flyt_top_right_->setObjectName(QStringLiteral("flyt_top_right_"));
        flyt_top_right_->setHorizontalSpacing(5);
        flyt_top_right_->setVerticalSpacing(5);
        flyt_top_right_->setContentsMargins(10, 2, 10, 5);
        ledit_ident_ = new QLineEdit(layoutWidget_3);
        ledit_ident_->setObjectName(QStringLiteral("ledit_ident_"));
        sizePolicy1.setHeightForWidth(ledit_ident_->sizePolicy().hasHeightForWidth());
        ledit_ident_->setSizePolicy(sizePolicy1);
        ledit_ident_->setMinimumSize(QSize(100, 22));
        ledit_ident_->setReadOnly(false);
        ledit_ident_->setClearButtonEnabled(true);

        flyt_top_right_->setWidget(0, QFormLayout::SpanningRole, ledit_ident_);

        ledit_nom_ = new QLineEdit(layoutWidget_3);
        ledit_nom_->setObjectName(QStringLiteral("ledit_nom_"));
        sizePolicy1.setHeightForWidth(ledit_nom_->sizePolicy().hasHeightForWidth());
        ledit_nom_->setSizePolicy(sizePolicy1);
        ledit_nom_->setMinimumSize(QSize(100, 22));
        ledit_nom_->setReadOnly(false);
        ledit_nom_->setClearButtonEnabled(true);

        flyt_top_right_->setWidget(1, QFormLayout::SpanningRole, ledit_nom_);

        lbl_ass_ = new QLabel(layoutWidget_3);
        lbl_ass_->setObjectName(QStringLiteral("lbl_ass_"));
        sizePolicy3.setHeightForWidth(lbl_ass_->sizePolicy().hasHeightForWidth());
        lbl_ass_->setSizePolicy(sizePolicy3);
        lbl_ass_->setMinimumSize(QSize(60, 16));
        lbl_ass_->setFont(font2);

        flyt_top_right_->setWidget(2, QFormLayout::LabelRole, lbl_ass_);

        cbx_ass_ = new QComboBox(layoutWidget_3);
        cbx_ass_->setObjectName(QStringLiteral("cbx_ass_"));
        sizePolicy1.setHeightForWidth(cbx_ass_->sizePolicy().hasHeightForWidth());
        cbx_ass_->setSizePolicy(sizePolicy1);
        cbx_ass_->setMinimumSize(QSize(100, 22));

        flyt_top_right_->setWidget(2, QFormLayout::FieldRole, cbx_ass_);

        lbl_ref_ass_ = new QLabel(layoutWidget_3);
        lbl_ref_ass_->setObjectName(QStringLiteral("lbl_ref_ass_"));
        lbl_ref_ass_->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lbl_ref_ass_->sizePolicy().hasHeightForWidth());
        lbl_ref_ass_->setSizePolicy(sizePolicy4);
        lbl_ref_ass_->setMinimumSize(QSize(60, 16));
        lbl_ref_ass_->setFont(font2);

        flyt_top_right_->setWidget(3, QFormLayout::LabelRole, lbl_ref_ass_);

        ledit_ref_ass_ = new QLineEdit(layoutWidget_3);
        ledit_ref_ass_->setObjectName(QStringLiteral("ledit_ref_ass_"));
        sizePolicy1.setHeightForWidth(ledit_ref_ass_->sizePolicy().hasHeightForWidth());
        ledit_ref_ass_->setSizePolicy(sizePolicy1);
        ledit_ref_ass_->setMinimumSize(QSize(100, 22));
        ledit_ref_ass_->setReadOnly(false);
        ledit_ref_ass_->setClearButtonEnabled(true);

        flyt_top_right_->setWidget(3, QFormLayout::FieldRole, ledit_ref_ass_);


        horizontalLayout->addWidget(gbx_client_);

        vline_top_right_ = new QFrame(SalesDialog);
        vline_top_right_->setObjectName(QStringLiteral("vline_top_right_"));
        vline_top_right_->setFrameShape(QFrame::VLine);
        vline_top_right_->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(vline_top_right_);

        hspcr_total_ = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(hspcr_total_);

        lbl_total_ = new QLabel(SalesDialog);
        lbl_total_->setObjectName(QStringLiteral("lbl_total_"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lbl_total_->sizePolicy().hasHeightForWidth());
        lbl_total_->setSizePolicy(sizePolicy5);
        lbl_total_->setMinimumSize(QSize(120, 80));
        lbl_total_->setMaximumSize(QSize(16777215, 16777215));
        lbl_total_->setBaseSize(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(155, 255, 249, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(205, 255, 252, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(77, 127, 124, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(103, 170, 166, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
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
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
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
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lbl_total_->setPalette(palette);
        QFont font3;
        font3.setPointSize(30);
        font3.setBold(false);
        font3.setWeight(50);
        lbl_total_->setFont(font3);
        lbl_total_->setLayoutDirection(Qt::LeftToRight);
        lbl_total_->setAutoFillBackground(true);
        lbl_total_->setFrameShape(QFrame::StyledPanel);
        lbl_total_->setFrameShadow(QFrame::Plain);
        lbl_total_->setLineWidth(0);
        lbl_total_->setIndent(1);

        horizontalLayout->addWidget(lbl_total_);

        lbl_total_valeur_ = new QLabel(SalesDialog);
        lbl_total_valeur_->setObjectName(QStringLiteral("lbl_total_valeur_"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(3);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lbl_total_valeur_->sizePolicy().hasHeightForWidth());
        lbl_total_valeur_->setSizePolicy(sizePolicy6);
        lbl_total_valeur_->setMinimumSize(QSize(400, 80));
        lbl_total_valeur_->setMaximumSize(QSize(16777215, 16777215));
        lbl_total_valeur_->setBaseSize(QSize(0, 0));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lbl_total_valeur_->setPalette(palette1);
        QFont font4;
        font4.setPointSize(65);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setWeight(50);
        lbl_total_valeur_->setFont(font4);
        lbl_total_valeur_->setLayoutDirection(Qt::LeftToRight);
        lbl_total_valeur_->setAutoFillBackground(true);
        lbl_total_valeur_->setFrameShape(QFrame::StyledPanel);
        lbl_total_valeur_->setFrameShadow(QFrame::Plain);
        lbl_total_valeur_->setLineWidth(0);
        lbl_total_valeur_->setScaledContents(true);
        lbl_total_valeur_->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lbl_total_valeur_);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        hline_top_ = new QFrame(SalesDialog);
        hline_top_->setObjectName(QStringLiteral("hline_top_"));
        hline_top_->setFrameShape(QFrame::HLine);
        hline_top_->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(hline_top_, 1, 0, 1, 1);

        tview_details_ = new QTreeView(SalesDialog);
        tview_details_->setObjectName(QStringLiteral("tview_details_"));
        tview_details_->setEnabled(true);
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(2);
        sizePolicy7.setHeightForWidth(tview_details_->sizePolicy().hasHeightForWidth());
        tview_details_->setSizePolicy(sizePolicy7);
        tview_details_->setFont(font);
        tview_details_->setStyleSheet(QStringLiteral(""));
        tview_details_->setFrameShape(QFrame::StyledPanel);
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
        tview_details_->header()->setHighlightSections(false);
        tview_details_->header()->setMinimumSectionSize(115);
        tview_details_->header()->setProperty("showSortIndicator", QVariant(false));
        tview_details_->header()->setStretchLastSection(true);

        gridLayout->addWidget(tview_details_, 3, 0, 1, 1);

        hlyt_mid_ = new QHBoxLayout();
        hlyt_mid_->setSpacing(0);
        hlyt_mid_->setObjectName(QStringLiteral("hlyt_mid_"));
        ledit_reference_ = new QLineEdit(SalesDialog);
        ledit_reference_->setObjectName(QStringLiteral("ledit_reference_"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(ledit_reference_->sizePolicy().hasHeightForWidth());
        ledit_reference_->setSizePolicy(sizePolicy8);
        ledit_reference_->setMinimumSize(QSize(210, 25));
        ledit_reference_->setFont(font);
        ledit_reference_->setAutoFillBackground(false);
        ledit_reference_->setClearButtonEnabled(true);

        hlyt_mid_->addWidget(ledit_reference_);

        hspcr_mid_left_ = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_mid_->addItem(hspcr_mid_left_);

        hspcr_mid_right_ = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_mid_->addItem(hspcr_mid_right_);

        pbtn_add_ = new QPushButton(SalesDialog);
        pbtn_add_->setObjectName(QStringLiteral("pbtn_add_"));
        sizePolicy4.setHeightForWidth(pbtn_add_->sizePolicy().hasHeightForWidth());
        pbtn_add_->setSizePolicy(sizePolicy4);
        pbtn_add_->setMinimumSize(QSize(25, 30));
        pbtn_add_->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/sales/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_add_->setIcon(icon3);

        hlyt_mid_->addWidget(pbtn_add_);

        pbtn_delete_ = new QPushButton(SalesDialog);
        pbtn_delete_->setObjectName(QStringLiteral("pbtn_delete_"));
        pbtn_delete_->setEnabled(false);
        sizePolicy4.setHeightForWidth(pbtn_delete_->sizePolicy().hasHeightForWidth());
        pbtn_delete_->setSizePolicy(sizePolicy4);
        pbtn_delete_->setMinimumSize(QSize(25, 30));
        pbtn_delete_->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/sales/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_delete_->setIcon(icon4);
        pbtn_delete_->setCheckable(false);
        pbtn_delete_->setFlat(false);

        hlyt_mid_->addWidget(pbtn_delete_);


        gridLayout->addLayout(hlyt_mid_, 2, 0, 1, 1);

        hline_top_->raise();
        tview_details_->raise();
#ifndef QT_NO_SHORTCUT
        lbl_devise_->setBuddy(cbox_devise_);
        lbl_percu_->setBuddy(ledit_percu_);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(ledit_reference_, pbtn_add_);
        QWidget::setTabOrder(pbtn_add_, pbtn_delete_);
        QWidget::setTabOrder(pbtn_delete_, tview_details_);
        QWidget::setTabOrder(tview_details_, tview_en_attente_);
        QWidget::setTabOrder(tview_en_attente_, cbox_devise_);
        QWidget::setTabOrder(cbox_devise_, ledit_percu_);
        QWidget::setTabOrder(ledit_percu_, pbtn_validate_);
        QWidget::setTabOrder(pbtn_validate_, pbtn_cancel_);

        retranslateUi(SalesDialog);

        cbox_devise_->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SalesDialog);
    } // setupUi

    void retranslateUi(QDialog *SalesDialog)
    {
        SalesDialog->setWindowTitle(QApplication::translate("SalesDialog", "Sales Point", 0));
        actn_add_->setText(QApplication::translate("SalesDialog", "Ajout manuel", 0));
#ifndef QT_NO_TOOLTIP
        actn_add_->setToolTip(QApplication::translate("SalesDialog", "Ajouter manuellement un article", 0));
#endif // QT_NO_TOOLTIP
        actn_add_->setShortcut(QApplication::translate("SalesDialog", "F1", 0));
        actn_list_->setText(QApplication::translate("SalesDialog", "Lister les articles", 0));
#ifndef QT_NO_TOOLTIP
        actn_list_->setToolTip(QApplication::translate("SalesDialog", "Lister les articles", 0));
#endif // QT_NO_TOOLTIP
        actn_list_->setShortcut(QApplication::translate("SalesDialog", "Ctrl+F", 0));
        actn_validate_->setText(QApplication::translate("SalesDialog", "Valider Facture", 0));
#ifndef QT_NO_TOOLTIP
        actn_validate_->setToolTip(QApplication::translate("SalesDialog", "Valider Facture", 0));
#endif // QT_NO_TOOLTIP
        actn_validate_->setShortcut(QApplication::translate("SalesDialog", "F3", 0));
        actn_delete_->setText(QApplication::translate("SalesDialog", "Supprimer", 0));
        actn_delete_->setShortcut(QApplication::translate("SalesDialog", "Del", 0));
        actn_full_screen_->setText(QApplication::translate("SalesDialog", "Show Full Screen", 0));
#ifndef QT_NO_TOOLTIP
        actn_full_screen_->setToolTip(QApplication::translate("SalesDialog", "Show Full Screen", 0));
#endif // QT_NO_TOOLTIP
        actn_full_screen_->setShortcut(QApplication::translate("SalesDialog", "F11", 0));
        actn_contiue_saling_->setText(QApplication::translate("SalesDialog", "Contiue Saling ", 0));
#ifndef QT_NO_TOOLTIP
        actn_contiue_saling_->setToolTip(QApplication::translate("SalesDialog", "Contiue Saling ", 0));
#endif // QT_NO_TOOLTIP
        actn_contiue_saling_->setShortcut(QApplication::translate("SalesDialog", "Esc", 0));
        lbl_devise_->setText(QApplication::translate("SalesDialog", "&Devise", 0));
        cbox_devise_->setCurrentText(QString());
        lbl_percu_->setText(QApplication::translate("SalesDialog", "&Percu", 0));
        ledit_percu_->setText(QApplication::translate("SalesDialog", "0", 0));
        ledit_percu_->setPlaceholderText(QApplication::translate("SalesDialog", "Montant Percu", 0));
        lbl_a_rendre_->setText(QApplication::translate("SalesDialog", "A Rendre", 0));
        lbl_a_rendre_valeur_->setText(QApplication::translate("SalesDialog", "0.0", 0));
        pbtn_hold_->setText(QApplication::translate("SalesDialog", "&Attendre", 0));
        pbtn_validate_->setText(QApplication::translate("SalesDialog", "&Valider", 0));
        pbtn_cancel_->setText(QApplication::translate("SalesDialog", "A&nnuler", 0));
        lbl_vendeur_->setText(QApplication::translate("SalesDialog", "Vendeur", 0));
        lbl_tarif_->setText(QApplication::translate("SalesDialog", "Tarif", 0));
        lbl_depot_->setText(QApplication::translate("SalesDialog", "Depot", 0));
        gbx_client_->setTitle(QApplication::translate("SalesDialog", "Client", 0));
        ledit_ident_->setPlaceholderText(QApplication::translate("SalesDialog", "Numero CNI ou Passeport ", 0));
        ledit_nom_->setPlaceholderText(QApplication::translate("SalesDialog", "Noms et Prenoms", 0));
        lbl_ass_->setText(QApplication::translate("SalesDialog", "Assurance", 0));
        lbl_ref_ass_->setText(QApplication::translate("SalesDialog", "Ref. Assure", 0));
        ledit_ref_ass_->setPlaceholderText(QApplication::translate("SalesDialog", "Reference Assureur", 0));
        lbl_total_->setText(QApplication::translate("SalesDialog", "Total", 0));
        lbl_total_valeur_->setText(QString());
#ifndef QT_NO_TOOLTIP
        ledit_reference_->setToolTip(QApplication::translate("SalesDialog", "Saisir la reference article ou le Code Barre ", 0));
#endif // QT_NO_TOOLTIP
        ledit_reference_->setText(QString());
        ledit_reference_->setPlaceholderText(QApplication::translate("SalesDialog", "Reference", 0));
#ifndef QT_NO_TOOLTIP
        pbtn_add_->setToolTip(QApplication::translate("SalesDialog", "<html><head/><body><p>Ajouter un  article</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pbtn_add_->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbtn_delete_->setToolTip(QApplication::translate("SalesDialog", "Supprimer un article", 0));
#endif // QT_NO_TOOLTIP
        pbtn_delete_->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SalesDialog: public Ui_SalesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHDIALOG_H
