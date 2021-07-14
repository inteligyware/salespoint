#ifndef CASHDESKCLOSURE_H
#define CASHDESKCLOSURE_H

#include <QDialog>

namespace Ui {
class CashDeskClosure;
}

class CashDeskClosure : public QDialog
{
    Q_OBJECT

public:
    explicit CashDeskClosure(QWidget *parent = 0);
    ~CashDeskClosure();

private:
    Ui::CashDeskClosure *ui;
};

#endif // CASHDESKCLOSURE_H
