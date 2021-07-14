#include "productfamily.h"
#include "ui_productfamily.h"

ProductFamily::ProductFamily(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductFamily)
{
    ui->setupUi(this);
}

ProductFamily::~ProductFamily()
{
    delete ui;
}
