/********************************************************************************
** Form generated from reading UI file 'product.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCT_H
#define UI_PRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_product
{
public:
    QGroupBox *gbox_parent;
    QFormLayout *formLayout_3;
    QLabel *label;
    QComboBox *cbox_paren_product;
    QLabel *label_2;
    QComboBox *cbox_family;
    QGroupBox *gbox_inventory;
    QLabel *label_8;
    QLineEdit *ledit_chuncked;
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
    QLabel *label_9;
    QLineEdit *ledit_puchase_price;
    QLabel *label_10;
    QLineEdit *ledit_sale_price;
    QGroupBox *gbox_reduction;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *reduction;
    QLabel *label_11;
    QGroupBox *gbox_vta;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *vta;
    QLabel *label_12;
    QPushButton *pbtn_save;
    QPushButton *pbtn_quit;
    QPushButton *pbtn_clear;

    void setupUi(QDialog *product)
    {
        if (product->objectName().isEmpty())
            product->setObjectName(QStringLiteral("product"));
        product->resize(650, 620);
        product->setMinimumSize(QSize(650, 620));
        product->setMaximumSize(QSize(650, 620));
        gbox_parent = new QGroupBox(product);
        gbox_parent->setObjectName(QStringLiteral("gbox_parent"));
        gbox_parent->setGeometry(QRect(9, -10, 631, 97));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gbox_parent->sizePolicy().hasHeightForWidth());
        gbox_parent->setSizePolicy(sizePolicy);
        formLayout_3 = new QFormLayout(gbox_parent);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label = new QLabel(gbox_parent);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        cbox_paren_product = new QComboBox(gbox_parent);
        cbox_paren_product->setObjectName(QStringLiteral("cbox_paren_product"));
        sizePolicy.setHeightForWidth(cbox_paren_product->sizePolicy().hasHeightForWidth());
        cbox_paren_product->setSizePolicy(sizePolicy);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, cbox_paren_product);

        label_2 = new QLabel(gbox_parent);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_2);

        cbox_family = new QComboBox(gbox_parent);
        cbox_family->setObjectName(QStringLiteral("cbox_family"));
        sizePolicy.setHeightForWidth(cbox_family->sizePolicy().hasHeightForWidth());
        cbox_family->setSizePolicy(sizePolicy);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, cbox_family);

        gbox_inventory = new QGroupBox(product);
        gbox_inventory->setObjectName(QStringLiteral("gbox_inventory"));
        gbox_inventory->setGeometry(QRect(10, 310, 631, 271));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gbox_inventory->sizePolicy().hasHeightForWidth());
        gbox_inventory->setSizePolicy(sizePolicy2);
        gbox_inventory->setCheckable(true);
        gbox_inventory->setChecked(true);
        label_8 = new QLabel(gbox_inventory);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 33, 100, 16));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        ledit_chuncked = new QLineEdit(gbox_inventory);
        ledit_chuncked->setObjectName(QStringLiteral("ledit_chuncked"));
        ledit_chuncked->setGeometry(QRect(120, 30, 101, 22));
        label_3 = new QLabel(gbox_inventory);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 33, 110, 16));
        last_inventory = new QDateTimeEdit(gbox_inventory);
        last_inventory->setObjectName(QStringLiteral("last_inventory"));
        last_inventory->setEnabled(false);
        last_inventory->setGeometry(QRect(490, 30, 131, 23));
        gbox_phys_stock = new QGroupBox(gbox_inventory);
        gbox_phys_stock->setObjectName(QStringLiteral("gbox_phys_stock"));
        gbox_phys_stock->setGeometry(QRect(10, 80, 291, 91));
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
        justification->setGeometry(QRect(10, 200, 611, 61));
        label_17 = new QLabel(gbox_inventory);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(350, 180, 271, 22));
        gbox_theo_stock = new QGroupBox(gbox_inventory);
        gbox_theo_stock->setObjectName(QStringLiteral("gbox_theo_stock"));
        gbox_theo_stock->setGeometry(QRect(350, 80, 271, 71));
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

        gbox_article = new QGroupBox(product);
        gbox_article->setObjectName(QStringLiteral("gbox_article"));
        gbox_article->setGeometry(QRect(10, 110, 631, 191));
        sizePolicy.setHeightForWidth(gbox_article->sizePolicy().hasHeightForWidth());
        gbox_article->setSizePolicy(sizePolicy);
        label_13 = new QLabel(gbox_article);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 29, 72, 16));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);
        label_14 = new QLabel(gbox_article);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 60, 81, 16));
        sizePolicy1.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy1);
        ledit_bar_code = new QLineEdit(gbox_article);
        ledit_bar_code->setObjectName(QStringLiteral("ledit_bar_code"));
        ledit_bar_code->setGeometry(QRect(120, 29, 241, 21));
        label_15 = new QLabel(gbox_article);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(400, 30, 54, 16));
        ledit_reference = new QLineEdit(gbox_article);
        ledit_reference->setObjectName(QStringLiteral("ledit_reference"));
        ledit_reference->setGeometry(QRect(470, 30, 151, 21));
        ledit_designation = new QLineEdit(gbox_article);
        ledit_designation->setObjectName(QStringLiteral("ledit_designation"));
        ledit_designation->setGeometry(QRect(120, 60, 501, 21));
        gbox_price = new QGroupBox(product);
        gbox_price->setObjectName(QStringLiteral("gbox_price"));
        gbox_price->setGeometry(QRect(20, 190, 611, 101));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(gbox_price->sizePolicy().hasHeightForWidth());
        gbox_price->setSizePolicy(sizePolicy4);
        label_9 = new QLabel(gbox_price);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 30, 91, 16));
        ledit_puchase_price = new QLineEdit(gbox_price);
        ledit_puchase_price->setObjectName(QStringLiteral("ledit_puchase_price"));
        ledit_puchase_price->setGeometry(QRect(110, 30, 191, 22));
        sizePolicy.setHeightForWidth(ledit_puchase_price->sizePolicy().hasHeightForWidth());
        ledit_puchase_price->setSizePolicy(sizePolicy);
        label_10 = new QLabel(gbox_price);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 60, 81, 16));
        ledit_sale_price = new QLineEdit(gbox_price);
        ledit_sale_price->setObjectName(QStringLiteral("ledit_sale_price"));
        ledit_sale_price->setGeometry(QRect(110, 60, 191, 22));
        sizePolicy.setHeightForWidth(ledit_sale_price->sizePolicy().hasHeightForWidth());
        ledit_sale_price->setSizePolicy(sizePolicy);
        gbox_reduction = new QGroupBox(gbox_price);
        gbox_reduction->setObjectName(QStringLiteral("gbox_reduction"));
        gbox_reduction->setGeometry(QRect(500, 30, 91, 51));
        gbox_reduction->setFlat(true);
        gbox_reduction->setCheckable(true);
        gbox_reduction->setChecked(false);
        layoutWidget = new QWidget(gbox_reduction);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 81, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        reduction = new QLineEdit(layoutWidget);
        reduction->setObjectName(QStringLiteral("reduction"));
        sizePolicy2.setHeightForWidth(reduction->sizePolicy().hasHeightForWidth());
        reduction->setSizePolicy(sizePolicy2);
        reduction->setMinimumSize(QSize(20, 0));
        reduction->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(reduction);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(label_11);

        gbox_vta = new QGroupBox(gbox_price);
        gbox_vta->setObjectName(QStringLiteral("gbox_vta"));
        gbox_vta->setGeometry(QRect(380, 30, 91, 51));
        gbox_vta->setFlat(true);
        gbox_vta->setCheckable(true);
        gbox_vta->setChecked(false);
        layoutWidget1 = new QWidget(gbox_vta);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 81, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        vta = new QLineEdit(layoutWidget1);
        vta->setObjectName(QStringLiteral("vta"));
        sizePolicy2.setHeightForWidth(vta->sizePolicy().hasHeightForWidth());
        vta->setSizePolicy(sizePolicy2);
        vta->setMinimumSize(QSize(20, 0));
        vta->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(vta);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy5.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy5);

        horizontalLayout_3->addWidget(label_12);

        pbtn_save = new QPushButton(product);
        pbtn_save->setObjectName(QStringLiteral("pbtn_save"));
        pbtn_save->setGeometry(QRect(380, 590, 80, 22));
        QIcon icon;
        icon.addFile(QStringLiteral(":/product/validate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_save->setIcon(icon);
        pbtn_quit = new QPushButton(product);
        pbtn_quit->setObjectName(QStringLiteral("pbtn_quit"));
        pbtn_quit->setGeometry(QRect(560, 590, 80, 22));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/sales/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_quit->setIcon(icon1);
        pbtn_clear = new QPushButton(product);
        pbtn_clear->setObjectName(QStringLiteral("pbtn_clear"));
        pbtn_clear->setGeometry(QRect(470, 590, 80, 22));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/product/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_clear->setIcon(icon2);

        retranslateUi(product);

        QMetaObject::connectSlotsByName(product);
    } // setupUi

    void retranslateUi(QDialog *product)
    {
        product->setWindowTitle(QApplication::translate("product", "Cr\303\251er un Nouvel Article", 0));
        gbox_parent->setTitle(QString());
        label->setText(QApplication::translate("product", "Produit D\303\251riv\303\251e", 0));
        label_2->setText(QApplication::translate("product", "Famille Associ\303\251e", 0));
        gbox_inventory->setTitle(QApplication::translate("product", "Inventorier l'Article", 0));
        label_8->setText(QApplication::translate("product", "Qt\303\251 Colis\303\251e", 0));
#ifndef QT_NO_TOOLTIP
        ledit_chuncked->setToolTip(QApplication::translate("product", "Quantit\303\251 par unit\303\251 de conditionnement", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("product", "Dernier Inventaire", 0));
        last_inventory->setDisplayFormat(QApplication::translate("product", "dd/MM/yyyy HH:mm", 0));
#ifndef QT_NO_TOOLTIP
        gbox_phys_stock->setToolTip(QApplication::translate("product", "Stock de produit obtenu par un decompte physique", 0));
#endif // QT_NO_TOOLTIP
        gbox_phys_stock->setTitle(QApplication::translate("product", "Stock Physique", 0));
#ifndef QT_NO_TOOLTIP
        ledit_phys_gros->setToolTip(QApplication::translate("product", "Qunatit\303\251 (Gros)", 0));
#endif // QT_NO_TOOLTIP
        ledit_phys_gros->setPlaceholderText(QApplication::translate("product", "Qunatit\303\251 (Gros)", 0));
#ifndef QT_NO_TOOLTIP
        ledit_phys_details->setToolTip(QApplication::translate("product", "Quantit\303\251 (D\303\251tails)", 0));
#endif // QT_NO_TOOLTIP
        ledit_phys_details->setPlaceholderText(QApplication::translate("product", "Quantit\303\251 (D\303\251tails)", 0));
#ifndef QT_NO_TOOLTIP
        ledit_phys_added_gros->setToolTip(QApplication::translate("product", "Quantit\303\251 a ajouter (Gros)", 0));
#endif // QT_NO_TOOLTIP
        ledit_phys_added_gros->setPlaceholderText(QApplication::translate("product", "Qt\303\251 Ajout\303\251e (Gros)", 0));
#ifndef QT_NO_TOOLTIP
        ledit_phys_added_details->setToolTip(QApplication::translate("product", "Qunatit\303\251 D\303\251conditionn\303\251e a Ajouter", 0));
#endif // QT_NO_TOOLTIP
        ledit_phys_added_details->setPlaceholderText(QApplication::translate("product", "Qt\303\251 Ajout\303\251e (D\303\251tails)", 0));
#ifndef QT_NO_TOOLTIP
        justification->setToolTip(QApplication::translate("product", "Indiquer les raisons de la difference entre les quantit\303\251s physiques et les quantit\303\251s th\303\251oriques obtenues lors du decompte", 0));
#endif // QT_NO_TOOLTIP
        justification->setPlaceholderText(QApplication::translate("product", "Indiquer les raisons de la difference entre les quantit\303\251s physiques et les quantit\303\251s th\303\251oriques obtenues lors du decompte", 0));
        label_17->setText(QApplication::translate("product", "Justifier de la difference Physique/Theorique", 0));
#ifndef QT_NO_TOOLTIP
        gbox_theo_stock->setToolTip(QApplication::translate("product", "Stock de produit obtenu par un decompte physique", 0));
#endif // QT_NO_TOOLTIP
        gbox_theo_stock->setTitle(QApplication::translate("product", "Stock Th\303\251orique", 0));
#ifndef QT_NO_TOOLTIP
        ledit_theo_gros->setToolTip(QApplication::translate("product", "Quantit\303\251 (Gros)", 0));
#endif // QT_NO_TOOLTIP
        ledit_theo_gros->setPlaceholderText(QApplication::translate("product", "Qunatit\303\251 (Gros)", 0));
#ifndef QT_NO_TOOLTIP
        ledit_theo_details->setToolTip(QApplication::translate("product", "Quantit\303\251 (D\303\251tails)", 0));
#endif // QT_NO_TOOLTIP
        ledit_theo_details->setPlaceholderText(QApplication::translate("product", "Quantit\303\251 (D\303\251tails)", 0));
        gbox_article->setTitle(QApplication::translate("product", "Article", 0));
        label_13->setText(QApplication::translate("product", "Code Barre ", 0));
        label_14->setText(QApplication::translate("product", "D\303\251signation", 0));
        label_15->setText(QApplication::translate("product", "Refernce", 0));
        gbox_price->setTitle(QString());
        label_9->setText(QApplication::translate("product", "Prix d'Achat", 0));
        label_10->setText(QApplication::translate("product", "Prix de Vente", 0));
        gbox_reduction->setTitle(QApplication::translate("product", "Remise", 0));
        label_11->setText(QApplication::translate("product", "% ", 0));
        gbox_vta->setTitle(QApplication::translate("product", "T.V.A", 0));
        label_12->setText(QApplication::translate("product", "% ", 0));
#ifndef QT_NO_TOOLTIP
        pbtn_save->setToolTip(QApplication::translate("product", "Enr\303\251gister l'article et Passer a la cr\303\251ation d'un nouvelle article", 0));
#endif // QT_NO_TOOLTIP
        pbtn_save->setText(QApplication::translate("product", "Enregister", 0));
#ifndef QT_NO_TOOLTIP
        pbtn_quit->setToolTip(QApplication::translate("product", "Quiter la fenettre sans rien enr\303\251gister", 0));
#endif // QT_NO_TOOLTIP
        pbtn_quit->setText(QApplication::translate("product", "Quiter", 0));
#ifndef QT_NO_TOOLTIP
        pbtn_clear->setToolTip(QApplication::translate("product", "Effacer le contenu du formulaire et recommencer pour un nouvelle article", 0));
#endif // QT_NO_TOOLTIP
        pbtn_clear->setText(QApplication::translate("product", "Effacer", 0));
    } // retranslateUi

};

namespace Ui {
    class product: public Ui_product {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCT_H
