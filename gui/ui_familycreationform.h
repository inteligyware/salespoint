/********************************************************************************
** Form generated from reading UI file 'familycreationform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAMILYCREATIONFORM_H
#define UI_FAMILYCREATIONFORM_H

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

class Ui_FamilyCreationForm
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

    void setupUi(QDialog *FamilyCreationForm)
    {
        if (FamilyCreationForm->objectName().isEmpty())
            FamilyCreationForm->setObjectName(QStringLiteral("FamilyCreationForm"));
        FamilyCreationForm->resize(590, 188);
        FamilyCreationForm->setMinimumSize(QSize(590, 188));
        FamilyCreationForm->setMaximumSize(QSize(590, 188));
        label = new QLabel(FamilyCreationForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 15, 81, 16));
        ledit_reference = new QLineEdit(FamilyCreationForm);
        ledit_reference->setObjectName(QStringLiteral("ledit_reference"));
        ledit_reference->setGeometry(QRect(20, 30, 120, 22));
        label_2 = new QLabel(FamilyCreationForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 15, 59, 14));
        ledit_designation = new QLineEdit(FamilyCreationForm);
        ledit_designation->setObjectName(QStringLiteral("ledit_designation"));
        ledit_designation->setGeometry(QRect(140, 30, 441, 22));
        description = new QPlainTextEdit(FamilyCreationForm);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(20, 80, 561, 70));
        label_3 = new QLabel(FamilyCreationForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 65, 71, 16));
        pbtn_quit = new QPushButton(FamilyCreationForm);
        pbtn_quit->setObjectName(QStringLiteral("pbtn_quit"));
        pbtn_quit->setGeometry(QRect(500, 160, 80, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/product/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_quit->setIcon(icon);
        pbtn_clear = new QPushButton(FamilyCreationForm);
        pbtn_clear->setObjectName(QStringLiteral("pbtn_clear"));
        pbtn_clear->setGeometry(QRect(410, 160, 80, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/product/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_clear->setIcon(icon1);
        pbtn_save = new QPushButton(FamilyCreationForm);
        pbtn_save->setObjectName(QStringLiteral("pbtn_save"));
        pbtn_save->setGeometry(QRect(320, 160, 81, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/product/validate.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbtn_save->setIcon(icon2);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(ledit_reference);
        label_2->setBuddy(ledit_designation);
        label_3->setBuddy(description);
#endif // QT_NO_SHORTCUT

        retranslateUi(FamilyCreationForm);

        QMetaObject::connectSlotsByName(FamilyCreationForm);
    } // setupUi

    void retranslateUi(QDialog *FamilyCreationForm)
    {
        FamilyCreationForm->setWindowTitle(QApplication::translate("FamilyCreationForm", "Creation Famille d'Article", Q_NULLPTR));
        label->setText(QApplication::translate("FamilyCreationForm", "Reference", Q_NULLPTR));
        label_2->setText(QApplication::translate("FamilyCreationForm", "Libele", Q_NULLPTR));
        label_3->setText(QApplication::translate("FamilyCreationForm", "Description", Q_NULLPTR));
        pbtn_quit->setText(QApplication::translate("FamilyCreationForm", "Quiter", Q_NULLPTR));
        pbtn_clear->setText(QApplication::translate("FamilyCreationForm", "Effacer", Q_NULLPTR));
        pbtn_save->setText(QApplication::translate("FamilyCreationForm", "Enregistrer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FamilyCreationForm: public Ui_FamilyCreationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAMILYCREATIONFORM_H
