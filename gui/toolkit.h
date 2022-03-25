#ifndef CURRENCYEDIT_H
#define CURRENCYEDIT_H
#include <QLineEdit>

class CurrencyEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit  CurrencyEdit(QWidget* parent = Q_NULLPTR);
    qint64 result() const;

protected:
    void keyPressEvent(QKeyEvent *);
private slots:
    void calculate(QString value);
    void calculate();

private:
    qint64 _result;
};

quint64 generateSalePrice(qreal purchase_price, float percentage, quint8 price_pgcd);


#endif // CURRENCYEDIT_H
