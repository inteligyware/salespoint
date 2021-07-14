/****************************************************************************
** Meta object code from reading C++ file 'inventorydialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inventorydialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inventorydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InventoryDialog_t {
    QByteArrayData data[10];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InventoryDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InventoryDialog_t qt_meta_stringdata_InventoryDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "InventoryDialog"
QT_MOC_LITERAL(1, 16, 9), // "inventory"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "enableDeleteItem"
QT_MOC_LITERAL(4, 44, 14), // "showFullScreen"
QT_MOC_LITERAL(5, 59, 11), // "deleteItems"
QT_MOC_LITERAL(6, 71, 15), // "activateButtons"
QT_MOC_LITERAL(7, 87, 21), // "checkToEnableValidate"
QT_MOC_LITERAL(8, 109, 15), // "cancelInventory"
QT_MOC_LITERAL(9, 125, 17) // "validateInventory"

    },
    "InventoryDialog\0inventory\0\0enableDeleteItem\0"
    "showFullScreen\0deleteItems\0activateButtons\0"
    "checkToEnableValidate\0cancelInventory\0"
    "validateInventory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InventoryDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x09 /* Protected */,
       1,    1,   60,    2, 0x09 /* Protected */,
       3,    0,   63,    2, 0x09 /* Protected */,
       4,    0,   64,    2, 0x09 /* Protected */,
       5,    0,   65,    2, 0x09 /* Protected */,
       6,    0,   66,    2, 0x09 /* Protected */,
       7,    0,   67,    2, 0x09 /* Protected */,
       8,    0,   68,    2, 0x09 /* Protected */,
       9,    0,   69,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InventoryDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InventoryDialog *_t = static_cast<InventoryDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->inventory(); break;
        case 1: _t->inventory((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->enableDeleteItem(); break;
        case 3: _t->showFullScreen(); break;
        case 4: _t->deleteItems(); break;
        case 5: _t->activateButtons(); break;
        case 6: _t->checkToEnableValidate(); break;
        case 7: _t->cancelInventory(); break;
        case 8: _t->validateInventory(); break;
        default: ;
        }
    }
}

const QMetaObject InventoryDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_InventoryDialog.data,
      qt_meta_data_InventoryDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *InventoryDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InventoryDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InventoryDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int InventoryDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
