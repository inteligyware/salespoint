#ifndef NUMBERDELEGATE_H
#define NUMBERDELEGATE_H

#include <QStyledItemDelegate>
#include <QDoubleSpinBox>

class NumberDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit NumberDelegate(Qt::Alignment = Qt::AlignVCenter|Qt::AlignRight, QObject* parent = Q_NULLPTR);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    Qt::Alignment alignment_;
};

class NumberSpinBox : public QDoubleSpinBox{
public:
    explicit NumberSpinBox(double min = 0 , double max = std::numeric_limits<double>::max(), QWidget* parent = Q_NULLPTR);
};


#endif // NUMBERDELEGATE_H
