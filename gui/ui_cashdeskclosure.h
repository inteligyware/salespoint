/********************************************************************************
** Form generated from reading UI file 'cashdeskclosure.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASHDESKCLOSURE_H
#define UI_CASHDESKCLOSURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CashDeskClosure
{
public:
    QGroupBox *groupBox;
    QTableWidget *tblwidget_notes;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *tblwidget_coins;
    QPushButton *ptn_quit;
    QPushButton *pbtn_validate;
    QPushButton *pbtn_clear;
    QFrame *line_bottom;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *total_notes;
    QLabel *total_coins;
    QLabel *grand_total;
    QLineEdit *ledit_passwd;
    QLabel *label_6;
    QLabel *cashier_name;
    QLabel *lbl_passwd;
    QDateTimeEdit *date;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *sales_session_number;
    QFrame *line_top;

    void setupUi(QDialog *CashDeskClosure)
    {
        if (CashDeskClosure->objectName().isEmpty())
            CashDeskClosure->setObjectName(QStringLiteral("CashDeskClosure"));
        CashDeskClosure->resize(660, 445);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CashDeskClosure->sizePolicy().hasHeightForWidth());
        CashDeskClosure->setSizePolicy(sizePolicy);
        CashDeskClosure->setMinimumSize(QSize(660, 445));
        CashDeskClosure->setMaximumSize(QSize(660, 445));
        CashDeskClosure->setSizeGripEnabled(true);
        CashDeskClosure->setModal(true);
        groupBox = new QGroupBox(CashDeskClosure);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 641, 221));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        tblwidget_notes = new QTableWidget(groupBox);
        if (tblwidget_notes->columnCount() < 3)
            tblwidget_notes->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setBackground(QColor(152, 152, 152));
        tblwidget_notes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        __qtablewidgetitem1->setBackground(QColor(152, 152, 152));
        tblwidget_notes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem2->setFont(font);
        __qtablewidgetitem2->setBackground(QColor(152, 152, 152));
        tblwidget_notes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tblwidget_notes->rowCount() < 5)
            tblwidget_notes->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblwidget_notes->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblwidget_notes->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblwidget_notes->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblwidget_notes->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblwidget_notes->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem8->setFont(font);
        __qtablewidgetitem8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_notes->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_notes->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem10->setFont(font);
        __qtablewidgetitem10->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_notes->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_notes->setItem(1, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem12->setFont(font);
        __qtablewidgetitem12->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_notes->setItem(2, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_notes->setItem(2, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem14->setFont(font);
        __qtablewidgetitem14->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_notes->setItem(3, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_notes->setItem(3, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem16->setFont(font);
        __qtablewidgetitem16->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_notes->setItem(4, 1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_notes->setItem(4, 2, __qtablewidgetitem17);
        tblwidget_notes->setObjectName(QStringLiteral("tblwidget_notes"));
        tblwidget_notes->setGeometry(QRect(0, 40, 280, 180));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        tblwidget_notes->setFont(font1);
        tblwidget_notes->setAlternatingRowColors(true);
        tblwidget_notes->setSelectionMode(QAbstractItemView::SingleSelection);
        tblwidget_notes->setGridStyle(Qt::DashLine);
        tblwidget_notes->setWordWrap(false);
        tblwidget_notes->horizontalHeader()->setDefaultSectionSize(80);
        tblwidget_notes->horizontalHeader()->setMinimumSectionSize(80);
        tblwidget_notes->horizontalHeader()->setStretchLastSection(true);
        tblwidget_notes->verticalHeader()->setVisible(false);
        tblwidget_notes->verticalHeader()->setDefaultSectionSize(20);
        tblwidget_notes->verticalHeader()->setMinimumSectionSize(10);
        tblwidget_notes->verticalHeader()->setStretchLastSection(false);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 281, 16));
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 20, 271, 16));
        label_2->setFont(font);
        tblwidget_coins = new QTableWidget(groupBox);
        if (tblwidget_coins->columnCount() < 3)
            tblwidget_coins->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem18->setFont(font);
        __qtablewidgetitem18->setBackground(QColor(152, 152, 152));
        tblwidget_coins->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font);
        __qtablewidgetitem19->setBackground(QColor(152, 152, 152));
        tblwidget_coins->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem20->setFont(font);
        __qtablewidgetitem20->setBackground(QColor(152, 152, 152));
        tblwidget_coins->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        if (tblwidget_coins->rowCount() < 8)
            tblwidget_coins->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblwidget_coins->setVerticalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tblwidget_coins->setVerticalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tblwidget_coins->setVerticalHeaderItem(2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tblwidget_coins->setVerticalHeaderItem(3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tblwidget_coins->setVerticalHeaderItem(4, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tblwidget_coins->setVerticalHeaderItem(5, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tblwidget_coins->setVerticalHeaderItem(6, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tblwidget_coins->setVerticalHeaderItem(7, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem29->setFont(font);
        __qtablewidgetitem29->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_coins->setItem(0, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_coins->setItem(0, 2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem31->setFont(font);
        __qtablewidgetitem31->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_coins->setItem(1, 1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_coins->setItem(1, 2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem33->setFont(font);
        __qtablewidgetitem33->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_coins->setItem(2, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_coins->setItem(2, 2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem35->setFont(font);
        __qtablewidgetitem35->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_coins->setItem(3, 1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_coins->setItem(3, 2, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem37->setFont(font);
        __qtablewidgetitem37->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_coins->setItem(4, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        tblwidget_coins->setItem(4, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem39->setFont(font);
        __qtablewidgetitem39->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_coins->setItem(5, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem40->setFont(font);
        __qtablewidgetitem40->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_coins->setItem(6, 1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem41->setFont(font);
        __qtablewidgetitem41->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tblwidget_coins->setItem(7, 1, __qtablewidgetitem41);
        tblwidget_coins->setObjectName(QStringLiteral("tblwidget_coins"));
        tblwidget_coins->setGeometry(QRect(360, 40, 280, 180));
        tblwidget_coins->setFont(font1);
        tblwidget_coins->setAlternatingRowColors(true);
        tblwidget_coins->setSelectionMode(QAbstractItemView::SingleSelection);
        tblwidget_coins->setGridStyle(Qt::DashLine);
        tblwidget_coins->setWordWrap(false);
        tblwidget_coins->horizontalHeader()->setDefaultSectionSize(80);
        tblwidget_coins->horizontalHeader()->setMinimumSectionSize(80);
        tblwidget_coins->horizontalHeader()->setStretchLastSection(true);
        tblwidget_coins->verticalHeader()->setVisible(false);
        tblwidget_coins->verticalHeader()->setDefaultSectionSize(20);
        tblwidget_coins->verticalHeader()->setMinimumSectionSize(10);
        tblwidget_coins->verticalHeader()->setStretchLastSection(true);
        ptn_quit = new QPushButton(CashDeskClosure);
        ptn_quit->setObjectName(QStringLiteral("ptn_quit"));
        ptn_quit->setGeometry(QRect(400, 420, 80, 22));
        pbtn_validate = new QPushButton(CashDeskClosure);
        pbtn_validate->setObjectName(QStringLiteral("pbtn_validate"));
        pbtn_validate->setGeometry(QRect(580, 420, 80, 22));
        pbtn_clear = new QPushButton(CashDeskClosure);
        pbtn_clear->setObjectName(QStringLiteral("pbtn_clear"));
        pbtn_clear->setGeometry(QRect(490, 420, 80, 22));
        line_bottom = new QFrame(CashDeskClosure);
        line_bottom->setObjectName(QStringLiteral("line_bottom"));
        line_bottom->setGeometry(QRect(0, 405, 661, 20));
        line_bottom->setFrameShape(QFrame::HLine);
        line_bottom->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(CashDeskClosure);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 330, 111, 16));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_4 = new QLabel(CashDeskClosure);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(370, 280, 141, 20));
        label_4->setFont(font2);
        label_5 = new QLabel(CashDeskClosure);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 280, 141, 21));
        label_5->setFont(font2);
        total_notes = new QLabel(CashDeskClosure);
        total_notes->setObjectName(QStringLiteral("total_notes"));
        total_notes->setGeometry(QRect(150, 280, 141, 20));
        total_notes->setFont(font2);
        total_coins = new QLabel(CashDeskClosure);
        total_coins->setObjectName(QStringLiteral("total_coins"));
        total_coins->setGeometry(QRect(510, 280, 141, 20));
        total_coins->setFont(font2);
        grand_total = new QLabel(CashDeskClosure);
        grand_total->setObjectName(QStringLiteral("grand_total"));
        grand_total->setGeometry(QRect(370, 323, 280, 31));
        grand_total->setFont(font2);
        ledit_passwd = new QLineEdit(CashDeskClosure);
        ledit_passwd->setObjectName(QStringLiteral("ledit_passwd"));
        ledit_passwd->setGeometry(QRect(540, 385, 120, 22));
        ledit_passwd->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(CashDeskClosure);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 10, 81, 16));
        label_6->setFont(font2);
        cashier_name = new QLabel(CashDeskClosure);
        cashier_name->setObjectName(QStringLiteral("cashier_name"));
        cashier_name->setGeometry(QRect(90, 10, 241, 16));
        cashier_name->setFont(font1);
        lbl_passwd = new QLabel(CashDeskClosure);
        lbl_passwd->setObjectName(QStringLiteral("lbl_passwd"));
        lbl_passwd->setGeometry(QRect(420, 390, 101, 16));
        lbl_passwd->setFont(font2);
        date = new QDateTimeEdit(CashDeskClosure);
        date->setObjectName(QStringLiteral("date"));
        date->setEnabled(false);
        date->setGeometry(QRect(510, 10, 141, 23));
        date->setFont(font);
        label_7 = new QLabel(CashDeskClosure);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(370, 10, 101, 16));
        label_7->setFont(font2);
        label_9 = new QLabel(CashDeskClosure);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 40, 71, 16));
        label_9->setFont(font2);
        sales_session_number = new QLabel(CashDeskClosure);
        sales_session_number->setObjectName(QStringLiteral("sales_session_number"));
        sales_session_number->setGeometry(QRect(90, 38, 241, 20));
        sales_session_number->setFont(font1);
        line_top = new QFrame(CashDeskClosure);
        line_top->setObjectName(QStringLiteral("line_top"));
        line_top->setGeometry(QRect(10, 60, 641, 20));
        line_top->setFrameShape(QFrame::HLine);
        line_top->setFrameShadow(QFrame::Sunken);

        retranslateUi(CashDeskClosure);

        QMetaObject::connectSlotsByName(CashDeskClosure);
    } // setupUi

    void retranslateUi(QDialog *CashDeskClosure)
    {
        CashDeskClosure->setWindowTitle(QApplication::translate("CashDeskClosure", "Billetage Pour Fermeture de Caisse", Q_NULLPTR));
        groupBox->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = tblwidget_notes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CashDeskClosure", "Nombre", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tblwidget_notes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CashDeskClosure", "Nature", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tblwidget_notes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CashDeskClosure", "Total", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tblwidget_notes->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tblwidget_notes->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tblwidget_notes->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tblwidget_notes->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tblwidget_notes->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));

        const bool __sortingEnabled = tblwidget_notes->isSortingEnabled();
        tblwidget_notes->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = tblwidget_notes->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("CashDeskClosure", "10 000", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tblwidget_notes->item(1, 1);
        ___qtablewidgetitem9->setText(QApplication::translate("CashDeskClosure", "5 000", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tblwidget_notes->item(2, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("CashDeskClosure", "2 000", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tblwidget_notes->item(3, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("CashDeskClosure", "1 000", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tblwidget_notes->item(4, 1);
        ___qtablewidgetitem12->setText(QApplication::translate("CashDeskClosure", "500", Q_NULLPTR));
        tblwidget_notes->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("CashDeskClosure", "BILLETS", Q_NULLPTR));
        label_2->setText(QApplication::translate("CashDeskClosure", "PIECES", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tblwidget_coins->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("CashDeskClosure", "Nombre", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tblwidget_coins->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("CashDeskClosure", "Nature", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tblwidget_coins->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("CashDeskClosure", "Total", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tblwidget_coins->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tblwidget_coins->verticalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tblwidget_coins->verticalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tblwidget_coins->verticalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tblwidget_coins->verticalHeaderItem(4);
        ___qtablewidgetitem20->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tblwidget_coins->verticalHeaderItem(5);
        ___qtablewidgetitem21->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tblwidget_coins->verticalHeaderItem(6);
        ___qtablewidgetitem22->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tblwidget_coins->verticalHeaderItem(7);
        ___qtablewidgetitem23->setText(QApplication::translate("CashDeskClosure", "New Row", Q_NULLPTR));

        const bool __sortingEnabled1 = tblwidget_coins->isSortingEnabled();
        tblwidget_coins->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem24 = tblwidget_coins->item(0, 1);
        ___qtablewidgetitem24->setText(QApplication::translate("CashDeskClosure", "500", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tblwidget_coins->item(1, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("CashDeskClosure", "100", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tblwidget_coins->item(2, 1);
        ___qtablewidgetitem26->setText(QApplication::translate("CashDeskClosure", "50", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tblwidget_coins->item(3, 1);
        ___qtablewidgetitem27->setText(QApplication::translate("CashDeskClosure", "25", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tblwidget_coins->item(4, 1);
        ___qtablewidgetitem28->setText(QApplication::translate("CashDeskClosure", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tblwidget_coins->item(5, 1);
        ___qtablewidgetitem29->setText(QApplication::translate("CashDeskClosure", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tblwidget_coins->item(6, 1);
        ___qtablewidgetitem30->setText(QApplication::translate("CashDeskClosure", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tblwidget_coins->item(7, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("CashDeskClosure", "1", Q_NULLPTR));
        tblwidget_coins->setSortingEnabled(__sortingEnabled1);

#ifndef QT_NO_TOOLTIP
        ptn_quit->setToolTip(QApplication::translate("CashDeskClosure", "Quiter sans Rien Enregistrer", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ptn_quit->setText(QApplication::translate("CashDeskClosure", "Quiter", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbtn_validate->setToolTip(QApplication::translate("CashDeskClosure", "Valider la Fermeture de caisse", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_validate->setText(QApplication::translate("CashDeskClosure", "Valider", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbtn_clear->setToolTip(QApplication::translate("CashDeskClosure", "Effacer le Formulaire", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbtn_clear->setText(QApplication::translate("CashDeskClosure", "Effacer", Q_NULLPTR));
        label_3->setText(QApplication::translate("CashDeskClosure", "Total General :", Q_NULLPTR));
        label_4->setText(QApplication::translate("CashDeskClosure", "Total Pieces :", Q_NULLPTR));
        label_5->setText(QApplication::translate("CashDeskClosure", "Total Billets :", Q_NULLPTR));
        total_notes->setText(QApplication::translate("CashDeskClosure", "### ### ### ###", Q_NULLPTR));
        total_coins->setText(QApplication::translate("CashDeskClosure", "### ### ### ###", Q_NULLPTR));
        grand_total->setText(QApplication::translate("CashDeskClosure", " #  ### ### ### ### ### ### ### ", Q_NULLPTR));
        ledit_passwd->setText(QString());
        ledit_passwd->setPlaceholderText(QApplication::translate("CashDeskClosure", "Mot de Passe", Q_NULLPTR));
        label_6->setText(QApplication::translate("CashDeskClosure", "Caissier :", Q_NULLPTR));
        cashier_name->setText(QApplication::translate("CashDeskClosure", "Non Du Caissier", Q_NULLPTR));
        lbl_passwd->setText(QApplication::translate("CashDeskClosure", "Mot de Passe", Q_NULLPTR));
        date->setDisplayFormat(QApplication::translate("CashDeskClosure", "dd/MM/yyyy HH:mm", Q_NULLPTR));
        label_7->setText(QApplication::translate("CashDeskClosure", "Date/Heure :", Q_NULLPTR));
        label_9->setText(QApplication::translate("CashDeskClosure", "Session :", Q_NULLPTR));
        sales_session_number->setText(QApplication::translate("CashDeskClosure", "Non Du Caissier", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CashDeskClosure: public Ui_CashDeskClosure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASHDESKCLOSURE_H
