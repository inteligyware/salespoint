/********************************************************************************
** Form generated from reading UI file 'productfamily.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTFAMILY_H
#define UI_PRODUCTFAMILY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ProductFamily
{
public:
    QLabel *label;
    QLineEdit *ledit_reference;
    QLabel *label_2;
    QLineEdit *ledit_designation;
    QPlainTextEdit *description;
    QLabel *label_3;
    QPushButton *pbtn_quit;
    QPushButton *pbtn_clear;
    QPushButton *pbtn_save;

    void setupUi(QDialog *ProductFamily)
    {
        if (ProductFamily->objectName().isEmpty())
            ProductFamily->setObjectName(QStringLiteral("ProductFamily"));
        ProductFamily->resize(590, 188);
        ProductFamily->setMinimumSize(QSize(590, 188));
        ProductFamily->setMaximumSize(QSize(590, 188));
        label = new QLabel(ProductFamily);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 16, 81, 16));
        ledit_reference = new QLineEdit(ProductFamily);
        ledit_reference->setObjectName(QStringLiteral("ledit_reference"));
        ledit_reference->setGeometry(QRect(20, 30, 115, 22));
        label_2 = new QLabel(ProductFamily);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(135, 16, 59, 14));
        ledit_designation = new QLineEdit(ProductFamily);
        ledit_designation->setObjectName(QStringLiteral("ledit_designation"));
        ledit_designation->setGeometry(QRect(135, 30, 446, 22));
        description = new QPlainTextEdit(ProductFamily);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(20, 80, 561, 70));
        label_3 = new QLabel(ProductFamily);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 66, 71, 16));
        pbtn_quit = new QPushButton(ProductFamily);
        pbtn_quit->setObjectName(QStringLiteral("pbtn_quit"));
        pbtn_quit->setGeometry(QRect(500, 160, 80, 22));
        QIcon icon;
        icon.addFile(QStringLiteral(":/product/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_quit->setIcon(icon);
        pbtn_clear = new QPushButton(ProductFamily);
        pbtn_clear->setObjectName(QStringLiteral("pbtn_clear"));
        pbtn_clear->setGeometry(QRect(410, 160, 80, 22));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/product/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_clear->setIcon(icon1);
        pbtn_save = new QPushButton(ProductFamily);
        pbtn_save->setObjectName(QStringLiteral("pbtn_save"));
        pbtn_save->setGeometry(QRect(320, 160, 81, 22));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/product/validate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_save->setIcon(icon2);

        retranslateUi(ProductFamily);

        QMetaObject::connectSlotsByName(ProductFamily);
    } // setupUi

    void retranslateUi(QDialog *ProductFamily)
    {
        ProductFamily->setWindowTitle(QApplication::translate("ProductFamily", "Creation Famille d'Article", 0));
        label->setText(QApplication::translate("ProductFamily", "Reference", 0));
        label_2->setText(QApplication::translate("ProductFamily", "Libele", 0));
        label_3->setText(QApplication::translate("ProductFamily", "Description", 0));
        pbtn_quit->setText(QApplication::translate("ProductFamily", "Quiter", 0));
        pbtn_clear->setText(QApplication::translate("ProductFamily", "Effacer", 0));
        pbtn_save->setText(QApplication::translate("ProductFamily", "Enregistrer", 0));
    } // retranslateUi

};

namespace Ui {
    class ProductFamily: public Ui_ProductFamily {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTFAMILY_H
