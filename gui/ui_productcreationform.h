/********************************************************************************
** Form generated from reading UI file 'productcreationform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTCREATIONFORM_H
#define UI_PRODUCTCREATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ProductCreationForm
{
public:
    QGroupBox *gbox_parent;
    QLabel *lbl_parent_product;
    QComboBox *cbox_article;
    QLabel *lbl_family;
    QComboBox *cbox_family;
    QPushButton *pbtn_new;
    QGroupBox *gbox_inventory;
    QLabel *label_3;
    QDateTimeEdit *last_inventory;
    QGroupBox *gbox_phys_stock;
    QFormLayout *formLayout;
    QLineEdit *ledit_phys_gros;
    QLineEdit *ledit_phys_details;
    QLineEdit *ledit_phys_added_gros;
    QLineEdit *ledit_phys_added_details;
    QPlainTextEdit *justification;
    QLabel *label_17;
    QGroupBox *gbox_theo_stock;
    QFormLayout *formLayout_2;
    QLineEdit *ledit_theo_gros;
    QLineEdit *ledit_theo_details;
    QGroupBox *gbox_article;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *ledit_bar_code;
    QLabel *label_15;
    QLineEdit *ledit_reference;
    QLineEdit *ledit_designation;
    QGroupBox *gbox_price;
    QLabel *lbl_purchase_price;
    QLineEdit *ledit_puchase_price;
    QLabel *lbl_sale_price;
    QLineEdit *ledit_sale_price;
    QCheckBox *ckbox_vta;
    QLineEdit *vta;
    QLabel *lbl_tva_percentage;
    QCheckBox *ckbox_reduction;
    QLineEdit *reduction;
    QLabel *lbl_reduction_percentage;
    QLineEdit *ledit_colise_mere;
    QLabel *lbl_colise_mere;
    QLineEdit *ledit_colise_derive;
    QLabel *lbl_colise_derive;
    QPushButton *pbtn_save;
    QPushButton *pbtn_quit;
    QPushButton *pbtn_clear;
    QGroupBox *gbox_prod_type;
    QRadioButton *rbtn_medicament;
    QRadioButton *rbtn_article;
    QComboBox *cbox_med;

    void setupUi(QDialog *ProductCreationForm)
    {
        if (ProductCreationForm->objectName().isEmpty())
            ProductCreationForm->setObjectName(QStringLiteral("ProductCreationForm"));
        ProductCreationForm->resize(650, 685);
        ProductCreationForm->setMinimumSize(QSize(650, 685));
        ProductCreationForm->setMaximumSize(QSize(650, 685));
        gbox_parent = new QGroupBox(ProductCreationForm);
        gbox_parent->setObjectName(QStringLiteral("gbox_parent"));
        gbox_parent->setGeometry(QRect(9, 51, 631, 97));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbox_parent->sizePolicy().hasHeightForWidth());
        gbox_parent->setSizePolicy(sizePolicy);
        lbl_parent_product = new QLabel(gbox_parent);
        lbl_parent_product->setObjectName(QStringLiteral("lbl_parent_product"));
        lbl_parent_product->setGeometry(QRect(12, 29, 85, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_parent_product->sizePolicy().hasHeightForWidth());
        lbl_parent_product->setSizePolicy(sizePolicy1);
        cbox_article = new QComboBox(gbox_parent);
        cbox_article->setObjectName(QStringLiteral("cbox_article"));
        cbox_article->setGeometry(QRect(122, 29, 497, 22));
        sizePolicy.setHeightForWidth(cbox_article->sizePolicy().hasHeightForWidth());
        cbox_article->setSizePolicy(sizePolicy);
        lbl_family = new QLabel(gbox_parent);
        lbl_family->setObjectName(QStringLiteral("lbl_family"));
        lbl_family->setGeometry(QRect(12, 57, 104, 16));
        sizePolicy1.setHeightForWidth(lbl_family->sizePolicy().hasHeightForWidth());
        lbl_family->setSizePolicy(sizePolicy1);
        cbox_family = new QComboBox(gbox_parent);
        cbox_family->setObjectName(QStringLiteral("cbox_family"));
        cbox_family->setGeometry(QRect(122, 57, 476, 22));
        sizePolicy.setHeightForWidth(cbox_family->sizePolicy().hasHeightForWidth());
        cbox_family->setSizePolicy(sizePolicy);
        pbtn_new = new QPushButton(gbox_parent);
        pbtn_new->setObjectName(QStringLiteral("pbtn_new"));
        pbtn_new->setGeometry(QRect(598, 57, 21, 22));
        QIcon icon;
        icon.addFile(QStringLiteral(":/sales/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_new->setIcon(icon);
        pbtn_new->setAutoDefault(false);
        gbox_inventory = new QGroupBox(ProductCreationForm);
        gbox_inventory->setObjectName(QStringLiteral("gbox_inventory"));
        gbox_inventory->setEnabled(true);
        gbox_inventory->setGeometry(QRect(10, 410, 631, 231));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gbox_inventory->sizePolicy().hasHeightForWidth());
        gbox_inventory->setSizePolicy(sizePolicy2);
        gbox_inventory->setCheckable(true);
        gbox_inventory->setChecked(false);
        label_3 = new QLabel(gbox_inventory);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 25, 121, 16));
        last_inventory = new QDateTimeEdit(gbox_inventory);
        last_inventory->setObjectName(QStringLiteral("last_inventory"));
        last_inventory->setEnabled(false);
        last_inventory->setGeometry(QRect(490, 25, 130, 23));
        gbox_phys_stock = new QGroupBox(gbox_inventory);
        gbox_phys_stock->setObjectName(QStringLiteral("gbox_phys_stock"));
        gbox_phys_stock->setGeometry(QRect(330, 50, 291, 91));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(gbox_phys_stock->sizePolicy().hasHeightForWidth());
        gbox_phys_stock->setSizePolicy(sizePolicy3);
        formLayout = new QFormLayout(gbox_phys_stock);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        ledit_phys_gros = new QLineEdit(gbox_phys_stock);
        ledit_phys_gros->setObjectName(QStringLiteral("ledit_phys_gros"));

        formLayout->setWidget(0, QFormLayout::LabelRole, ledit_phys_gros);

        ledit_phys_details = new QLineEdit(gbox_phys_stock);
        ledit_phys_details->setObjectName(QStringLiteral("ledit_phys_details"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ledit_phys_details);

        ledit_phys_added_gros = new QLineEdit(gbox_phys_stock);
        ledit_phys_added_gros->setObjectName(QStringLiteral("ledit_phys_added_gros"));

        formLayout->setWidget(1, QFormLayout::LabelRole, ledit_phys_added_gros);

        ledit_phys_added_details = new QLineEdit(gbox_phys_stock);
        ledit_phys_added_details->setObjectName(QStringLiteral("ledit_phys_added_details"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ledit_phys_added_details);

        justification = new QPlainTextEdit(gbox_inventory);
        justification->setObjectName(QStringLiteral("justification"));
        justification->setGeometry(QRect(10, 150, 611, 61));
        label_17 = new QLabel(gbox_inventory);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 130, 271, 22));
        gbox_theo_stock = new QGroupBox(gbox_inventory);
        gbox_theo_stock->setObjectName(QStringLiteral("gbox_theo_stock"));
        gbox_theo_stock->setGeometry(QRect(10, 50, 271, 71));
        sizePolicy3.setHeightForWidth(gbox_theo_stock->sizePolicy().hasHeightForWidth());
        gbox_theo_stock->setSizePolicy(sizePolicy3);
        formLayout_2 = new QFormLayout(gbox_theo_stock);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setVerticalSpacing(0);
        ledit_theo_gros = new QLineEdit(gbox_theo_stock);
        ledit_theo_gros->setObjectName(QStringLiteral("ledit_theo_gros"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, ledit_theo_gros);

        ledit_theo_details = new QLineEdit(gbox_theo_stock);
        ledit_theo_details->setObjectName(QStringLiteral("ledit_theo_details"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, ledit_theo_details);

        gbox_article = new QGroupBox(ProductCreationForm);
        gbox_article->setObjectName(QStringLiteral("gbox_article"));
        gbox_article->setGeometry(QRect(10, 160, 631, 231));
        sizePolicy.setHeightForWidth(gbox_article->sizePolicy().hasHeightForWidth());
        gbox_article->setSizePolicy(sizePolicy);
        label_13 = new QLabel(gbox_article);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 29, 81, 16));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_14 = new QLabel(gbox_article);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 60, 81, 16));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        ledit_bar_code = new QLineEdit(gbox_article);
        ledit_bar_code->setObjectName(QStringLiteral("ledit_bar_code"));
        ledit_bar_code->setGeometry(QRect(120, 29, 231, 21));
        label_15 = new QLabel(gbox_article);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(360, 30, 71, 20));
        ledit_reference = new QLineEdit(gbox_article);
        ledit_reference->setObjectName(QStringLiteral("ledit_reference"));
        ledit_reference->setGeometry(QRect(430, 30, 191, 21));
        ledit_designation = new QLineEdit(gbox_article);
        ledit_designation->setObjectName(QStringLiteral("ledit_designation"));
        ledit_designation->setGeometry(QRect(120, 60, 501, 21));
        gbox_price = new QGroupBox(gbox_article);
        gbox_price->setObjectName(QStringLiteral("gbox_price"));
        gbox_price->setGeometry(QRect(10, 80, 611, 141));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(gbox_price->sizePolicy().hasHeightForWidth());
        gbox_price->setSizePolicy(sizePolicy4);
        lbl_purchase_price = new QLabel(gbox_price);
        lbl_purchase_price->setObjectName(QStringLiteral("lbl_purchase_price"));
        lbl_purchase_price->setGeometry(QRect(5, 35, 101, 16));
        ledit_puchase_price = new QLineEdit(gbox_price);
        ledit_puchase_price->setObjectName(QStringLiteral("ledit_puchase_price"));
        ledit_puchase_price->setGeometry(QRect(110, 30, 231, 22));
        sizePolicy.setHeightForWidth(ledit_puchase_price->sizePolicy().hasHeightForWidth());
        ledit_puchase_price->setSizePolicy(sizePolicy);
        lbl_sale_price = new QLabel(gbox_price);
        lbl_sale_price->setObjectName(QStringLiteral("lbl_sale_price"));
        lbl_sale_price->setGeometry(QRect(5, 65, 101, 16));
        ledit_sale_price = new QLineEdit(gbox_price);
        ledit_sale_price->setObjectName(QStringLiteral("ledit_sale_price"));
        ledit_sale_price->setGeometry(QRect(110, 60, 231, 22));
        sizePolicy.setHeightForWidth(ledit_sale_price->sizePolicy().hasHeightForWidth());
        ledit_sale_price->setSizePolicy(sizePolicy);
        ckbox_vta = new QCheckBox(gbox_price);
        ckbox_vta->setObjectName(QStringLiteral("ckbox_vta"));
        ckbox_vta->setGeometry(QRect(110, 90, 81, 20));
        vta = new QLineEdit(gbox_price);
        vta->setObjectName(QStringLiteral("vta"));
        vta->setGeometry(QRect(110, 110, 55, 22));
        sizePolicy2.setHeightForWidth(vta->sizePolicy().hasHeightForWidth());
        vta->setSizePolicy(sizePolicy2);
        vta->setMinimumSize(QSize(55, 0));
        vta->setMaximumSize(QSize(55, 22));
        vta->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        vta->setReadOnly(true);
        lbl_tva_percentage = new QLabel(gbox_price);
        lbl_tva_percentage->setObjectName(QStringLiteral("lbl_tva_percentage"));
        lbl_tva_percentage->setGeometry(QRect(168, 110, 21, 22));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lbl_tva_percentage->sizePolicy().hasHeightForWidth());
        lbl_tva_percentage->setSizePolicy(sizePolicy5);
        QFont font;
        font.setPointSize(11);
        lbl_tva_percentage->setFont(font);
        ckbox_reduction = new QCheckBox(gbox_price);
        ckbox_reduction->setObjectName(QStringLiteral("ckbox_reduction"));
        ckbox_reduction->setGeometry(QRect(270, 90, 71, 20));
        reduction = new QLineEdit(gbox_price);
        reduction->setObjectName(QStringLiteral("reduction"));
        reduction->setGeometry(QRect(270, 110, 55, 22));
        sizePolicy2.setHeightForWidth(reduction->sizePolicy().hasHeightForWidth());
        reduction->setSizePolicy(sizePolicy2);
        reduction->setMinimumSize(QSize(55, 0));
        reduction->setMaximumSize(QSize(55, 22));
        reduction->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbl_reduction_percentage = new QLabel(gbox_price);
        lbl_reduction_percentage->setObjectName(QStringLiteral("lbl_reduction_percentage"));
        lbl_reduction_percentage->setGeometry(QRect(328, 110, 16, 22));
        sizePolicy5.setHeightForWidth(lbl_reduction_percentage->sizePolicy().hasHeightForWidth());
        lbl_reduction_percentage->setSizePolicy(sizePolicy5);
        lbl_reduction_percentage->setFont(font);
        ledit_colise_mere = new QLineEdit(gbox_price);
        ledit_colise_mere->setObjectName(QStringLiteral("ledit_colise_mere"));
        ledit_colise_mere->setGeometry(QRect(470, 30, 131, 22));
        lbl_colise_mere = new QLabel(gbox_price);
        lbl_colise_mere->setObjectName(QStringLiteral("lbl_colise_mere"));
        lbl_colise_mere->setGeometry(QRect(350, 35, 111, 16));
        sizePolicy.setHeightForWidth(lbl_colise_mere->sizePolicy().hasHeightForWidth());
        lbl_colise_mere->setSizePolicy(sizePolicy);
        ledit_colise_derive = new QLineEdit(gbox_price);
        ledit_colise_derive->setObjectName(QStringLiteral("ledit_colise_derive"));
        ledit_colise_derive->setGeometry(QRect(470, 60, 131, 22));
        lbl_colise_derive = new QLabel(gbox_price);
        lbl_colise_derive->setObjectName(QStringLiteral("lbl_colise_derive"));
        lbl_colise_derive->setGeometry(QRect(350, 65, 111, 16));
        sizePolicy.setHeightForWidth(lbl_colise_derive->sizePolicy().hasHeightForWidth());
        lbl_colise_derive->setSizePolicy(sizePolicy);
        pbtn_save = new QPushButton(ProductCreationForm);
        pbtn_save->setObjectName(QStringLiteral("pbtn_save"));
        pbtn_save->setGeometry(QRect(370, 650, 80, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/product/validate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_save->setIcon(icon1);
        pbtn_save->setAutoDefault(false);
        pbtn_quit = new QPushButton(ProductCreationForm);
        pbtn_quit->setObjectName(QStringLiteral("pbtn_quit"));
        pbtn_quit->setGeometry(QRect(560, 650, 80, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/sales/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_quit->setIcon(icon2);
        pbtn_quit->setAutoDefault(false);
        pbtn_clear = new QPushButton(ProductCreationForm);
        pbtn_clear->setObjectName(QStringLiteral("pbtn_clear"));
        pbtn_clear->setGeometry(QRect(465, 650, 80, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/product/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_clear->setIcon(icon3);
        pbtn_clear->setAutoDefault(false);
        gbox_prod_type = new QGroupBox(ProductCreationForm);
        gbox_prod_type->setObjectName(QStringLiteral("gbox_prod_type"));
        gbox_prod_type->setGeometry(QRect(10, 0, 631, 61));
        rbtn_medicament = new QRadioButton(gbox_prod_type);
        rbtn_medicament->setObjectName(QStringLiteral("rbtn_medicament"));
        rbtn_medicament->setGeometry(QRect(10, 30, 101, 20));
        rbtn_medicament->setChecked(true);
        rbtn_article = new QRadioButton(gbox_prod_type);
        rbtn_article->setObjectName(QStringLiteral("rbtn_article"));
        rbtn_article->setGeometry(QRect(150, 30, 121, 20));
        cbox_med = new QComboBox(ProductCreationForm);
        cbox_med->setObjectName(QStringLiteral("cbox_med"));
        cbox_med->setGeometry(QRect(131, 80, 497, 22));
        sizePolicy.setHeightForWidth(cbox_med->sizePolicy().hasHeightForWidth());
        cbox_med->setSizePolicy(sizePolicy);
#ifndef QT_NO_SHORTCUT
        lbl_parent_product->setBuddy(cbox_med);
        lbl_family->setBuddy(cbox_family);
        label_3->setBuddy(last_inventory);
        label_17->setBuddy(justification);
        label_13->setBuddy(ledit_bar_code);
        label_14->setBuddy(ledit_designation);
        label_15->setBuddy(ledit_reference);
        lbl_purchase_price->setBuddy(ledit_puchase_price);
        lbl_sale_price->setBuddy(ledit_sale_price);
        lbl_colise_mere->setBuddy(ledit_colise_mere);
        lbl_colise_derive->setBuddy(ledit_colise_derive);
#endif // QT_NO_SHORTCUT

        retranslateUi(ProductCreationForm);

        pbtn_save->setDefault(true);


        QMetaObject::connectSlotsByName(ProductCreationForm);
    } // setupUi

    void retranslateUi(QDialog *ProductCreationForm)
    {
        ProductCreationForm->setWindowTitle(QApplication::translate("ProductCreationForm", "Cr\303\251er un Nouvel Article", Q_NULLPTR));
        gbox_parent->setTitle(QString());
        lbl_parent_product->setText(QApplication::translate("ProductCreationForm", "Produit M\303\250re :", Q_NULLPTR));
        lbl_family->setText(QApplication::translate("ProductCreationForm", "Famille Associ\303\251e:", Q_NULLPTR));
        pbtn_new->setText(QString());
        gbox_inventory->setTitle(QApplication::translate("ProductCreationForm", "Inventorier l'Article", Q_NULLPTR));
        label_3->setText(QApplication::translate("ProductCreationForm", "Dernier Inventaire :", Q_NULLPTR));
        last_inventory->setDisplayFormat(QApplication::translate("ProductCreationForm", "dd/MM/yyyy HH:mm", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gbox_phys_stock->setToolTip(QApplication::translate("ProductCreationForm", "Stock de produit obtenu  apr\303\250s le nouvel inventaire", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        gbox_phys_stock->setTitle(QApplication::translate("ProductCreationForm", "Stock Physique Actuel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_phys_gros->setToolTip(QApplication::translate("ProductCreationForm", "Entrer la qunatit\303\251 gros obtenue apr\303\250s comptage physique", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_phys_gros->setPlaceholderText(QApplication::translate("ProductCreationForm", "Qunatit\303\251 (Gros)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_phys_details->setToolTip(QApplication::translate("ProductCreationForm", "Entrer la qunatit\303\251 d\303\251conditionn\303\251e obtenue apr\303\250s comptage physique", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_phys_details->setPlaceholderText(QApplication::translate("ProductCreationForm", "Quantit\303\251 (D\303\251tails)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_phys_added_gros->setToolTip(QApplication::translate("ProductCreationForm", "Entrer la qunatit\303\251 physique gros \303\240 ajouter", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_phys_added_gros->setPlaceholderText(QApplication::translate("ProductCreationForm", "Qt\303\251 Ajout\303\251e (Gros)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_phys_added_details->setToolTip(QApplication::translate("ProductCreationForm", "Entrer la qunatit\303\251 physique d\303\251conditionn\303\251e \303\240 ajouter", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_phys_added_details->setPlaceholderText(QApplication::translate("ProductCreationForm", "Qt\303\251 Ajout\303\251e (D\303\251tails)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        justification->setToolTip(QApplication::translate("ProductCreationForm", "Indiquer les raisons de la difference entre les quantit\303\251s physiques et les quantit\303\251s th\303\251oriques obtenues lors du decompte", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        justification->setPlaceholderText(QApplication::translate("ProductCreationForm", "Indiquer les raisons de la difference entre les quantit\303\251s physiques et les quantit\303\251s th\303\251oriques obtenues lors du decompte", Q_NULLPTR));
        label_17->setText(QApplication::translate("ProductCreationForm", "Justifier de la diff\303\251rence Physique/Th\303\251orique", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gbox_theo_stock->setToolTip(QApplication::translate("ProductCreationForm", "Stock de produit indiqu\303\251 par le systeme", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        gbox_theo_stock->setTitle(QApplication::translate("ProductCreationForm", "Stock Th\303\251orique Actuel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_theo_gros->setToolTip(QApplication::translate("ProductCreationForm", "Quantit\303\251 (Gros)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_theo_gros->setPlaceholderText(QApplication::translate("ProductCreationForm", "Qunatit\303\251 (Gros)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_theo_details->setToolTip(QApplication::translate("ProductCreationForm", "Quantit\303\251 (D\303\251tails)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_theo_details->setPlaceholderText(QApplication::translate("ProductCreationForm", "Quantit\303\251 (D\303\251tails)", Q_NULLPTR));
        gbox_article->setTitle(QApplication::translate("ProductCreationForm", "Article", Q_NULLPTR));
        label_13->setText(QApplication::translate("ProductCreationForm", "Code Barre: ", Q_NULLPTR));
        label_14->setText(QApplication::translate("ProductCreationForm", "D\303\251signation :", Q_NULLPTR));
        label_15->setText(QApplication::translate("ProductCreationForm", "R\303\251f\303\251rence:", Q_NULLPTR));
        gbox_price->setTitle(QString());
        lbl_purchase_price->setText(QApplication::translate("ProductCreationForm", "Prix d'Achat :", Q_NULLPTR));
        lbl_sale_price->setText(QApplication::translate("ProductCreationForm", "Prix de Vente :", Q_NULLPTR));
        ckbox_vta->setText(QApplication::translate("ProductCreationForm", "T.V.A", Q_NULLPTR));
        lbl_tva_percentage->setText(QApplication::translate("ProductCreationForm", "% ", Q_NULLPTR));
        ckbox_reduction->setText(QApplication::translate("ProductCreationForm", "Remise", Q_NULLPTR));
        lbl_reduction_percentage->setText(QApplication::translate("ProductCreationForm", "% ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_colise_mere->setToolTip(QApplication::translate("ProductCreationForm", "Quantit\303\251 par unit\303\251 de conditionnement", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledit_colise_mere->setText(QString());
        lbl_colise_mere->setText(QApplication::translate("ProductCreationForm", "Qt\303\251 Colis\303\251e M\303\250re", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledit_colise_derive->setToolTip(QApplication::translate("ProductCreationForm", "Quantit\303\251 par unit\303\251 de conditionnement pour le produit derive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lbl_colise_derive->setText(QApplication::translate("ProductCreationForm", "Qt\303\251 Colis\303\251e:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbtn_save->setToolTip(QApplication::translate("ProductCreationForm", "Enr\303\251gister l'article et Passer a la cr\303\251ation d'un nouvel article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_save->setText(QApplication::translate("ProductCreationForm", "Enregister", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbtn_quit->setToolTip(QApplication::translate("ProductCreationForm", "Quiter la fenettre sans rien enr\303\251gister", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_quit->setText(QApplication::translate("ProductCreationForm", "Quiter", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbtn_clear->setToolTip(QApplication::translate("ProductCreationForm", "Effacer le contenu du formulaire et recommencer pour un nouvel article", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_clear->setText(QApplication::translate("ProductCreationForm", "Effacer", Q_NULLPTR));
        gbox_prod_type->setTitle(QApplication::translate("ProductCreationForm", "Types de Produits", Q_NULLPTR));
        rbtn_medicament->setText(QApplication::translate("ProductCreationForm", "M\303\251dicaments", Q_NULLPTR));
        rbtn_article->setText(QApplication::translate("ProductCreationForm", "Autres Articles", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProductCreationForm: public Ui_ProductCreationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTCREATIONFORM_H
