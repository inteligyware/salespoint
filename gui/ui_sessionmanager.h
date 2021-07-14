/********************************************************************************
** Form generated from reading UI file 'sessionmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SESSIONMANAGER_H
#define UI_SESSIONMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SessionManager
{
public:
    QAction *actionDelete_Cancel;
    QGridLayout *gridLayout;
    QGroupBox *gbox;
    QHBoxLayout *hlyt;
    QVBoxLayout *vboxlyt;
    QLineEdit *ledt_login_;
    QLineEdit *ledt_pwd_;
    QHBoxLayout *hboxlyt;
    QSpacerItem *hspcr;
    QPushButton *btn_cancel_;
    QPushButton *btn_connect_;

    void setupUi(QDialog *SessionManager)
    {
        if (SessionManager->objectName().isEmpty())
            SessionManager->setObjectName(QStringLiteral("SessionManager"));
        SessionManager->resize(504, 274);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(70);
        sizePolicy.setVerticalStretch(70);
        sizePolicy.setHeightForWidth(SessionManager->sizePolicy().hasHeightForWidth());
        SessionManager->setSizePolicy(sizePolicy);
        SessionManager->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        SessionManager->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/logo"), QSize(), QIcon::Normal, QIcon::Off);
        SessionManager->setWindowIcon(icon);
        SessionManager->setAutoFillBackground(true);
        SessionManager->setStyleSheet(QStringLiteral(""));
        SessionManager->setSizeGripEnabled(true);
        SessionManager->setModal(true);
        actionDelete_Cancel = new QAction(SessionManager);
        actionDelete_Cancel->setObjectName(QStringLiteral("actionDelete_Cancel"));
        gridLayout = new QGridLayout(SessionManager);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gbox = new QGroupBox(SessionManager);
        gbox->setObjectName(QStringLiteral("gbox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gbox->sizePolicy().hasHeightForWidth());
        gbox->setSizePolicy(sizePolicy1);
        gbox->setMinimumSize(QSize(410, 180));
        hlyt = new QHBoxLayout(gbox);
        hlyt->setSpacing(0);
        hlyt->setObjectName(QStringLiteral("hlyt"));
        hlyt->setContentsMargins(20, 20, 20, 20);
        vboxlyt = new QVBoxLayout();
        vboxlyt->setSpacing(0);
        vboxlyt->setObjectName(QStringLiteral("vboxlyt"));
        vboxlyt->setSizeConstraint(QLayout::SetDefaultConstraint);
        ledt_login_ = new QLineEdit(gbox);
        ledt_login_->setObjectName(QStringLiteral("ledt_login_"));
        ledt_login_->setMinimumSize(QSize(0, 23));
        ledt_login_->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(12);
        ledt_login_->setFont(font1);
        ledt_login_->setStyleSheet(QStringLiteral(""));
        ledt_login_->setClearButtonEnabled(true);

        vboxlyt->addWidget(ledt_login_);

        ledt_pwd_ = new QLineEdit(gbox);
        ledt_pwd_->setObjectName(QStringLiteral("ledt_pwd_"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ledt_pwd_->sizePolicy().hasHeightForWidth());
        ledt_pwd_->setSizePolicy(sizePolicy2);
        ledt_pwd_->setMinimumSize(QSize(0, 23));
        ledt_pwd_->setMaximumSize(QSize(16777215, 20));
        ledt_pwd_->setFont(font1);
        ledt_pwd_->setEchoMode(QLineEdit::Password);
        ledt_pwd_->setClearButtonEnabled(true);

        vboxlyt->addWidget(ledt_pwd_);

        hboxlyt = new QHBoxLayout();
        hboxlyt->setSpacing(0);
        hboxlyt->setObjectName(QStringLiteral("hboxlyt"));
        hboxlyt->setSizeConstraint(QLayout::SetNoConstraint);
        hspcr = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxlyt->addItem(hspcr);

        btn_cancel_ = new QPushButton(gbox);
        btn_cancel_->setObjectName(QStringLiteral("btn_cancel_"));
        btn_cancel_->setAutoDefault(false);

        hboxlyt->addWidget(btn_cancel_);

        btn_connect_ = new QPushButton(gbox);
        btn_connect_->setObjectName(QStringLiteral("btn_connect_"));
        btn_connect_->setEnabled(false);
        sizePolicy1.setHeightForWidth(btn_connect_->sizePolicy().hasHeightForWidth());
        btn_connect_->setSizePolicy(sizePolicy1);
        btn_connect_->setMinimumSize(QSize(80, 25));
        btn_connect_->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/cadenas"), QSize(), QIcon::Normal, QIcon::Off);
        btn_connect_->setIcon(icon1);
        btn_connect_->setAutoDefault(true);

        hboxlyt->addWidget(btn_connect_);


        vboxlyt->addLayout(hboxlyt);


        hlyt->addLayout(vboxlyt);


        gridLayout->addWidget(gbox, 0, 0, 1, 1);


        retranslateUi(SessionManager);

        btn_connect_->setDefault(true);


        QMetaObject::connectSlotsByName(SessionManager);
    } // setupUi

    void retranslateUi(QDialog *SessionManager)
    {
        SessionManager->setWindowTitle(QApplication::translate("SessionManager", "Autentification - InteligyPharma", Q_NULLPTR));
        actionDelete_Cancel->setText(QApplication::translate("SessionManager", "Delete Cancel", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionDelete_Cancel->setShortcut(QApplication::translate("SessionManager", "Esc", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        ledt_login_->setToolTip(QApplication::translate("SessionManager", "Saisir le login", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledt_login_->setText(QString());
        ledt_login_->setPlaceholderText(QApplication::translate("SessionManager", "login", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ledt_pwd_->setToolTip(QApplication::translate("SessionManager", "Saisir un mot de passe d'au moins 8 caractes", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ledt_pwd_->setInputMask(QString());
        ledt_pwd_->setText(QString());
        ledt_pwd_->setPlaceholderText(QApplication::translate("SessionManager", "password", Q_NULLPTR));
        btn_cancel_->setText(QApplication::translate("SessionManager", "Cancel", Q_NULLPTR));
        btn_connect_->setText(QApplication::translate("SessionManager", "Connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SessionManager: public Ui_SessionManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SESSIONMANAGER_H
