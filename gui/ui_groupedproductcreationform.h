/********************************************************************************
** Form generated from reading UI file 'groupedproductcreationform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPEDPRODUCTCREATIONFORM_H
#define UI_GROUPEDPRODUCTCREATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GroupedProductCreationForm
{
public:
    QAction *actn_add_;
    QAction *actn_enregistrer_;
    QAction *actn_delete_;
    QAction *actn_quit_;
    QGridLayout *mainlyt_;
    QHBoxLayout *hlyt_bottom;
    QSpacerItem *hspcr_bottom;
    QVBoxLayout *vlyt_bottom_amount;
    QSpacerItem *vspcr_amount;
    QHBoxLayout *hlyt_bottom_btn;
    QPushButton *pbtn_validate;
    QSpacerItem *hspcr_rihgt;
    QPushButton *pbtn_cancel;
    QHBoxLayout *hlyt_top;
    QFormLayout *flyt_top_left;
    QLabel *lbl_product;
    QComboBox *cbx_product;
    QComboBox *cbx_family;
    QLabel *lbl_family;
    QHBoxLayout *hlyt_mid;
    QLineEdit *ledit_reference;
    QComboBox *cbox_field;
    QPushButton *pbtn_add;
    QPushButton *pbtn_delete;
    QTableWidget *tblwidget_details_;

    void setupUi(QDialog *GroupedProductCreationForm)
    {
        if (GroupedProductCreationForm->objectName().isEmpty())
            GroupedProductCreationForm->setObjectName(QStringLiteral("GroupedProductCreationForm"));
        GroupedProductCreationForm->setEnabled(true);
        GroupedProductCreationForm->resize(811, 499);
        QIcon icon;
        icon.addFile(QStringLiteral(":/main/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        GroupedProductCreationForm->setWindowIcon(icon);
        GroupedProductCreationForm->setSizeGripEnabled(true);
        GroupedProductCreationForm->setModal(true);
        actn_add_ = new QAction(GroupedProductCreationForm);
        actn_add_->setObjectName(QStringLiteral("actn_add_"));
        actn_enregistrer_ = new QAction(GroupedProductCreationForm);
        actn_enregistrer_->setObjectName(QStringLiteral("actn_enregistrer_"));
        actn_delete_ = new QAction(GroupedProductCreationForm);
        actn_delete_->setObjectName(QStringLiteral("actn_delete_"));
        actn_quit_ = new QAction(GroupedProductCreationForm);
        actn_quit_->setObjectName(QStringLiteral("actn_quit_"));
        mainlyt_ = new QGridLayout(GroupedProductCreationForm);
        mainlyt_->setObjectName(QStringLiteral("mainlyt_"));
        mainlyt_->setHorizontalSpacing(5);
        mainlyt_->setVerticalSpacing(0);
        mainlyt_->setContentsMargins(5, 0, 5, 5);
        hlyt_bottom = new QHBoxLayout();
        hlyt_bottom->setSpacing(0);
        hlyt_bottom->setObjectName(QStringLiteral("hlyt_bottom"));
        hspcr_bottom = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlyt_bottom->addItem(hspcr_bottom);

        vlyt_bottom_amount = new QVBoxLayout();
        vlyt_bottom_amount->setObjectName(QStringLiteral("vlyt_bottom_amount"));
        vspcr_amount = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vlyt_bottom_amount->addItem(vspcr_amount);

        hlyt_bottom_btn = new QHBoxLayout();
        hlyt_bottom_btn->setSpacing(0);
        hlyt_bottom_btn->setObjectName(QStringLiteral("hlyt_bottom_btn"));
        pbtn_validate = new QPushButton(GroupedProductCreationForm);
        pbtn_validate->setObjectName(QStringLiteral("pbtn_validate"));
        QFont font;
        font.setPointSize(10);
        pbtn_validate->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/sales/validate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_validate->setIcon(icon1);

        hlyt_bottom_btn->addWidget(pbtn_validate);

        hspcr_rihgt = new QSpacerItem(13, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        hlyt_bottom_btn->addItem(hspcr_rihgt);

        pbtn_cancel = new QPushButton(GroupedProductCreationForm);
        pbtn_cancel->setObjectName(QStringLiteral("pbtn_cancel"));
        pbtn_cancel->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/sales/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_cancel->setIcon(icon2);

        hlyt_bottom_btn->addWidget(pbtn_cancel);


        vlyt_bottom_amount->addLayout(hlyt_bottom_btn);


        hlyt_bottom->addLayout(vlyt_bottom_amount);


        mainlyt_->addLayout(hlyt_bottom, 4, 0, 1, 1);

        hlyt_top = new QHBoxLayout();
        hlyt_top->setSpacing(0);
        hlyt_top->setObjectName(QStringLiteral("hlyt_top"));
        hlyt_top->setContentsMargins(-1, 5, -1, 5);
        flyt_top_left = new QFormLayout();
        flyt_top_left->setObjectName(QStringLiteral("flyt_top_left"));
        flyt_top_left->setLabelAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        flyt_top_left->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        flyt_top_left->setHorizontalSpacing(15);
        flyt_top_left->setVerticalSpacing(5);
        lbl_product = new QLabel(GroupedProductCreationForm);
        lbl_product->setObjectName(QStringLiteral("lbl_product"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_product->sizePolicy().hasHeightForWidth());
        lbl_product->setSizePolicy(sizePolicy);
        lbl_product->setMinimumSize(QSize(100, 16));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        lbl_product->setFont(font1);
        lbl_product->setLayoutDirection(Qt::LeftToRight);

        flyt_top_left->setWidget(0, QFormLayout::LabelRole, lbl_product);

        cbx_product = new QComboBox(GroupedProductCreationForm);
        cbx_product->setObjectName(QStringLiteral("cbx_product"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbx_product->sizePolicy().hasHeightForWidth());
        cbx_product->setSizePolicy(sizePolicy1);
        cbx_product->setMinimumSize(QSize(110, 20));
        cbx_product->setMaximumSize(QSize(16777215, 25));
        cbx_product->setBaseSize(QSize(0, 0));

        flyt_top_left->setWidget(0, QFormLayout::FieldRole, cbx_product);

        cbx_family = new QComboBox(GroupedProductCreationForm);
        cbx_family->setObjectName(QStringLiteral("cbx_family"));
        sizePolicy1.setHeightForWidth(cbx_family->sizePolicy().hasHeightForWidth());
        cbx_family->setSizePolicy(sizePolicy1);
        cbx_family->setMinimumSize(QSize(110, 20));
        cbx_family->setMaximumSize(QSize(16777215, 25));

        flyt_top_left->setWidget(1, QFormLayout::FieldRole, cbx_family);

        lbl_family = new QLabel(GroupedProductCreationForm);
        lbl_family->setObjectName(QStringLiteral("lbl_family"));
        sizePolicy.setHeightForWidth(lbl_family->sizePolicy().hasHeightForWidth());
        lbl_family->setSizePolicy(sizePolicy);
        lbl_family->setMinimumSize(QSize(100, 16));
        lbl_family->setFont(font1);

        flyt_top_left->setWidget(1, QFormLayout::LabelRole, lbl_family);


        hlyt_top->addLayout(flyt_top_left);


        mainlyt_->addLayout(hlyt_top, 0, 0, 1, 1);

        hlyt_mid = new QHBoxLayout();
        hlyt_mid->setSpacing(0);
        hlyt_mid->setObjectName(QStringLiteral("hlyt_mid"));
        ledit_reference = new QLineEdit(GroupedProductCreationForm);
        ledit_reference->setObjectName(QStringLiteral("ledit_reference"));
        ledit_reference->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ledit_reference->sizePolicy().hasHeightForWidth());
        ledit_reference->setSizePolicy(sizePolicy2);
        ledit_reference->setMinimumSize(QSize(250, 0));
        ledit_reference->setFont(font);
        ledit_reference->setAutoFillBackground(false);
        ledit_reference->setClearButtonEnabled(true);

        hlyt_mid->addWidget(ledit_reference);

        cbox_field = new QComboBox(GroupedProductCreationForm);
        cbox_field->setObjectName(QStringLiteral("cbox_field"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cbox_field->sizePolicy().hasHeightForWidth());
        cbox_field->setSizePolicy(sizePolicy3);
        cbox_field->setMinimumSize(QSize(150, 0));

        hlyt_mid->addWidget(cbox_field);

        pbtn_add = new QPushButton(GroupedProductCreationForm);
        pbtn_add->setObjectName(QStringLiteral("pbtn_add"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pbtn_add->sizePolicy().hasHeightForWidth());
        pbtn_add->setSizePolicy(sizePolicy4);
        pbtn_add->setMinimumSize(QSize(22, 22));
        pbtn_add->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/sales/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_add->setIcon(icon3);

        hlyt_mid->addWidget(pbtn_add);

        pbtn_delete = new QPushButton(GroupedProductCreationForm);
        pbtn_delete->setObjectName(QStringLiteral("pbtn_delete"));
        pbtn_delete->setEnabled(false);
        sizePolicy4.setHeightForWidth(pbtn_delete->sizePolicy().hasHeightForWidth());
        pbtn_delete->setSizePolicy(sizePolicy4);
        pbtn_delete->setMinimumSize(QSize(22, 22));
        pbtn_delete->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/sales/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_delete->setIcon(icon4);
        pbtn_delete->setCheckable(false);
        pbtn_delete->setFlat(false);

        hlyt_mid->addWidget(pbtn_delete);


        mainlyt_->addLayout(hlyt_mid, 1, 0, 1, 1);

        tblwidget_details_ = new QTableWidget(GroupedProductCreationForm);
        if (tblwidget_details_->columnCount() < 12)
            tblwidget_details_->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblwidget_details_->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_details_->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        tblwidget_details_->setObjectName(QStringLiteral("tblwidget_details_"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(tblwidget_details_->sizePolicy().hasHeightForWidth());
        tblwidget_details_->setSizePolicy(sizePolicy5);
        tblwidget_details_->setAutoScrollMargin(15);
        tblwidget_details_->setAlternatingRowColors(true);
        tblwidget_details_->setShowGrid(false);
        tblwidget_details_->setWordWrap(false);
        tblwidget_details_->horizontalHeader()->setDefaultSectionSize(75);
        tblwidget_details_->horizontalHeader()->setStretchLastSection(true);
        tblwidget_details_->verticalHeader()->setVisible(false);
        tblwidget_details_->verticalHeader()->setDefaultSectionSize(0);
        tblwidget_details_->verticalHeader()->setMinimumSectionSize(0);

        mainlyt_->addWidget(tblwidget_details_, 2, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        lbl_product->setBuddy(cbx_product);
        lbl_family->setBuddy(cbx_family);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(cbx_product, ledit_reference);
        QWidget::setTabOrder(ledit_reference, pbtn_add);
        QWidget::setTabOrder(pbtn_add, pbtn_delete);
        QWidget::setTabOrder(pbtn_delete, pbtn_validate);
        QWidget::setTabOrder(pbtn_validate, pbtn_cancel);

        retranslateUi(GroupedProductCreationForm);

        QMetaObject::connectSlotsByName(GroupedProductCreationForm);
    } // setupUi

    void retranslateUi(QDialog *GroupedProductCreationForm)
    {
        GroupedProductCreationForm->setWindowTitle(QApplication::translate("GroupedProductCreationForm", "Sales Point", Q_NULLPTR));
        actn_add_->setText(QApplication::translate("GroupedProductCreationForm", "Ajout manuel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_add_->setToolTip(QApplication::translate("GroupedProductCreationForm", "Ajouter manuellement un article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_add_->setShortcut(QApplication::translate("GroupedProductCreationForm", "F1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_enregistrer_->setText(QApplication::translate("GroupedProductCreationForm", "Enregistrer les produits", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_enregistrer_->setToolTip(QApplication::translate("GroupedProductCreationForm", "Enregistrer les produits cr\303\251\303\251s", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_enregistrer_->setShortcut(QApplication::translate("GroupedProductCreationForm", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_delete_->setText(QApplication::translate("GroupedProductCreationForm", "Supprimer", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actn_delete_->setShortcut(QApplication::translate("GroupedProductCreationForm", "Del", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actn_quit_->setText(QApplication::translate("GroupedProductCreationForm", "Quiter la page", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actn_quit_->setToolTip(QApplication::translate("GroupedProductCreationForm", "Quiter la Page", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actn_quit_->setShortcut(QApplication::translate("GroupedProductCreationForm", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pbtn_validate->setText(QApplication::translate("GroupedProductCreationForm", "&Enr\303\251gistrer", Q_NULLPTR));
        pbtn_cancel->setText(QApplication::translate("GroupedProductCreationForm", "&Quiter", Q_NULLPTR));
        lbl_product->setText(QApplication::translate("GroupedProductCreationForm", "&Produit D\303\251riv\303\251", Q_NULLPTR));
        lbl_family->setText(QApplication::translate("GroupedProductCreationForm", "&Famille Associ\303\251e", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_reference->setToolTip(QApplication::translate("GroupedProductCreationForm", "Saisir la reference article ou le Code Barre ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_reference->setText(QString());
        ledit_reference->setPlaceholderText(QApplication::translate("GroupedProductCreationForm", "Rechercher", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbtn_add->setToolTip(QApplication::translate("GroupedProductCreationForm", "Ajouter un  article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_add->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbtn_delete->setToolTip(QApplication::translate("GroupedProductCreationForm", "Supprimer un article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_delete->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tblwidget_details_->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GroupedProductCreationForm", "TVA", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tblwidget_details_->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GroupedProductCreationForm", "Code Barre", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tblwidget_details_->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GroupedProductCreationForm", "R\303\251f\303\251rence", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem2->setToolTip(QApplication::translate("GroupedProductCreationForm", "Code Unique de  R\303\251f\303\251rence", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem3 = tblwidget_details_->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("GroupedProductCreationForm", "D\303\251signation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem3->setToolTip(QApplication::translate("GroupedProductCreationForm", "Designation de l'article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem4 = tblwidget_details_->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("GroupedProductCreationForm", "Prix Achat", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tblwidget_details_->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("GroupedProductCreationForm", "Remise", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem5->setToolTip(QApplication::translate("GroupedProductCreationForm", "Remise Applicable a l'article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem6 = tblwidget_details_->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("GroupedProductCreationForm", "Prix Vente", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tblwidget_details_->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("GroupedProductCreationForm", "Colis\303\251e", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem7->setToolTip(QApplication::translate("GroupedProductCreationForm", "Quantit\303\251 Colis\303\251", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem8 = tblwidget_details_->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("GroupedProductCreationForm", "Stock P.G", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem8->setToolTip(QApplication::translate("GroupedProductCreationForm", "Stock Physique Gros", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem9 = tblwidget_details_->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("GroupedProductCreationForm", "Stock P.C", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem9->setToolTip(QApplication::translate("GroupedProductCreationForm", "Stock Physique Colis\303\251", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem10 = tblwidget_details_->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("GroupedProductCreationForm", "Stock T.G", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem10->setToolTip(QApplication::translate("GroupedProductCreationForm", "Stock Th\303\251orique Gros", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem11 = tblwidget_details_->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("GroupedProductCreationForm", "Stock T.C", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem11->setToolTip(QApplication::translate("GroupedProductCreationForm", "Stock Th\303\251orique Colis\303\251", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class GroupedProductCreationForm: public Ui_GroupedProductCreationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPEDPRODUCTCREATIONFORM_H
