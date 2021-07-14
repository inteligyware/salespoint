#include "cashdeskclosure.h"
#include "ui_cashdeskclosure.h"

CashDeskClosure::CashDeskClosure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CashDeskClosure)
{
    ui->setupUi(this);
}

CashDeskClosure::~CashDeskClosure()
{
    delete ui;
}
