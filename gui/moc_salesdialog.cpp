/****************************************************************************
** Meta object code from reading C++ file 'salesdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "salesdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'salesdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SalesDialog_t {
    QByteArrayData data[20];
    char stringdata0[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SalesDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SalesDialog_t qt_meta_stringdata_SalesDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SalesDialog"
QT_MOC_LITERAL(1, 12, 4), // "sale"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 19), // "showProductsForSale"
QT_MOC_LITERAL(4, 38, 21), // "showProductsForSearch"
QT_MOC_LITERAL(5, 60, 22), // "setEnabledSearchClient"
QT_MOC_LITERAL(6, 83, 6), // "client"
QT_MOC_LITERAL(7, 90, 16), // "enableDeleteItem"
QT_MOC_LITERAL(8, 107, 11), // "updateTotal"
QT_MOC_LITERAL(9, 119, 14), // "showFullScreen"
QT_MOC_LITERAL(10, 134, 11), // "deleteGoods"
QT_MOC_LITERAL(11, 146, 15), // "activateButtons"
QT_MOC_LITERAL(12, 162, 19), // "checkToEnableSeller"
QT_MOC_LITERAL(13, 182, 21), // "checkToEnableValidate"
QT_MOC_LITERAL(14, 204, 10), // "cancelSale"
QT_MOC_LITERAL(15, 215, 12), // "validateSale"
QT_MOC_LITERAL(16, 228, 13), // "putSaleOnHold"
QT_MOC_LITERAL(17, 242, 11), // "restoreSale"
QT_MOC_LITERAL(18, 254, 16), // "calculateBalance"
QT_MOC_LITERAL(19, 271, 12) // "currencyEcho"

    },
    "SalesDialog\0sale\0\0showProductsForSale\0"
    "showProductsForSearch\0setEnabledSearchClient\0"
    "client\0enableDeleteItem\0updateTotal\0"
    "showFullScreen\0deleteGoods\0activateButtons\0"
    "checkToEnableSeller\0checkToEnableValidate\0"
    "cancelSale\0validateSale\0putSaleOnHold\0"
    "restoreSale\0calculateBalance\0currencyEcho"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SalesDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x09 /* Protected */,
       1,    1,  105,    2, 0x09 /* Protected */,
       3,    0,  108,    2, 0x09 /* Protected */,
       4,    0,  109,    2, 0x09 /* Protected */,
       5,    1,  110,    2, 0x09 /* Protected */,
       7,    0,  113,    2, 0x09 /* Protected */,
       8,    0,  114,    2, 0x09 /* Protected */,
       9,    0,  115,    2, 0x09 /* Protected */,
      10,    0,  116,    2, 0x09 /* Protected */,
      11,    0,  117,    2, 0x09 /* Protected */,
      12,    0,  118,    2, 0x09 /* Protected */,
      13,    0,  119,    2, 0x09 /* Protected */,
      14,    0,  120,    2, 0x09 /* Protected */,
      15,    0,  121,    2, 0x09 /* Protected */,
      16,    0,  122,    2, 0x09 /* Protected */,
      17,    1,  123,    2, 0x09 /* Protected */,
      18,    0,  126,    2, 0x09 /* Protected */,
      19,    1,  127,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void SalesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SalesDialog *_t = static_cast<SalesDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sale(); break;
        case 1: _t->sale((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->showProductsForSale(); break;
        case 3: _t->showProductsForSearch(); break;
        case 4: _t->setEnabledSearchClient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->enableDeleteItem(); break;
        case 6: _t->updateTotal(); break;
        case 7: _t->showFullScreen(); break;
        case 8: _t->deleteGoods(); break;
        case 9: _t->activateButtons(); break;
        case 10: _t->checkToEnableSeller(); break;
        case 11: _t->checkToEnableValidate(); break;
        case 12: _t->cancelSale(); break;
        case 13: _t->validateSale(); break;
        case 14: _t->putSaleOnHold(); break;
        case 15: _t->restoreSale((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 16: _t->calculateBalance(); break;
        case 17: _t->currencyEcho((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SalesDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SalesDialog.data,
      qt_meta_data_SalesDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SalesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SalesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SalesDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SalesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
