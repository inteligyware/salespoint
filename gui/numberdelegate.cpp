#include "delegates.h"
#include <QPainter>

NumberDelegate::NumberDelegate(Qt::Alignment align, QObject* parent): QStyledItemDelegate(parent){
    alignment_ = align;
}

void NumberDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
    if (option.state & QStyle::State_Selected)
        painter->fillRect(option.rect, option.palette.highlight());

    QLocale::setDefault(QLocale("fr_FR"));
    QLocale locale;
    QString value = index.model()->data(index,Qt::DisplayRole).toString().remove(QRegExp("\\s"));
    if(!value.isEmpty()){
        bool ok = true ;
        value.toLongLong(&ok);
        if(ok)
            painter->drawText(option.rect,locale.toCurrencyString(value.toLongLong() , QString(" ")).trimmed(),QTextOption(alignment_));
        else
            painter->drawText(option.rect,locale.toCurrencyString(value.toDouble() , QString(" ")).trimmed(),QTextOption(alignment_));
    }
    painter->restore();
}

NumberSpinBox::NumberSpinBox(double min, double max, QWidget* parent): QDoubleSpinBox(parent){
    setRange(min, max);
    setDecimals(2);
    setAlignment(Qt::AlignVCenter|Qt::AlignRight);
    //    ledit_percu_->setValidator(new QDoubleValidator(0,std::numeric_limits<double>::max(),2,ledit_percu_));
}
