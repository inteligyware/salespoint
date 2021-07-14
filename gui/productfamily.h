#ifndef PRODUCTFAMILY_H
#define PRODUCTFAMILY_H

#include <QDialog>

namespace Ui {
class ProductFamily;
}

class ProductFamily : public QDialog
{
    Q_OBJECT

public:
    explicit ProductFamily(QWidget *parent = 0);
    ~ProductFamily();

private:
    Ui::ProductFamily *ui;
};

#endif // PRODUCTFAMILY_H
