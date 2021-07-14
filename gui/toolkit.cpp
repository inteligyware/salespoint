#include "toolkit.h"
#include <QValidator>
#include <QKeyEvent>

CurrencyEdit::CurrencyEdit(QWidget *parent) : QLineEdit(parent) , _result(0){
    setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]*[.]?[0-9]{0,2}(\\+[1-9][0-9]*[.]?[0-9]{0,2})?") , this));
    connect(this , SIGNAL(textChanged(QString)) , this , SLOT(calculate(QString)));
}

qint64 CurrencyEdit::result() const{
    return _result ;
}

void CurrencyEdit::calculate(QString value){
    QString left, right;
    QLocale locale;
    QStringList item = value.remove(QRegExp("\\s")).split("+");
    left = item.at(0);
    _result = left.toLongLong();
    left = locale.toCurrencyString(left.toLongLong(),QString(" ")).trimmed();
    if(value.contains(QChar('+'))){
        left.append("+");
        right = item.at(1);
        _result += right.toLongLong();
        if(!right.isEmpty()){
            right = locale.toCurrencyString(right.toLongLong(),QString(" ")).trimmed();
            left.append(right);
        }
    }
    setText(left);
}

void CurrencyEdit::calculate(){
    QLocale locale;
    setText(locale.toCurrencyString(_result,QString(" ")).trimmed());
}

void CurrencyEdit::keyPressEvent(QKeyEvent *ke){
    if (ke->key() == Qt::Key_Enter || ke->key() == Qt::Key_Return)
        calculate();
    QLineEdit::keyPressEvent(ke);
}

quint64 generateSalePrice(qreal purchase_price, float percentage, quint8 price_pgcd){
    float gain = (1 + percentage/100);
    quint64 prix = ceil(gain*purchase_price);
    return ( prix + ( price_pgcd - prix % price_pgcd ) % price_pgcd);
}
