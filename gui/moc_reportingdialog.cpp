/****************************************************************************
** Meta object code from reading C++ file 'reportingdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "reportingdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reportingdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReportingDialog_t {
    QByteArrayData data[12];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReportingDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReportingDialog_t qt_meta_stringdata_ReportingDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ReportingDialog"
QT_MOC_LITERAL(1, 16, 18), // "setFilterKeyColumn"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "column"
QT_MOC_LITERAL(4, 43, 12), // "displayStats"
QT_MOC_LITERAL(5, 56, 17), // "selectSourceModel"
QT_MOC_LITERAL(6, 74, 3), // "pos"
QT_MOC_LITERAL(7, 78, 15), // "showProgression"
QT_MOC_LITERAL(8, 94, 10), // "reloadData"
QT_MOC_LITERAL(9, 105, 5), // "total"
QT_MOC_LITERAL(10, 111, 11), // "refreshView"
QT_MOC_LITERAL(11, 123, 20) // "resetValidToDateTime"

    },
    "ReportingDialog\0setFilterKeyColumn\0\0"
    "column\0displayStats\0selectSourceModel\0"
    "pos\0showProgression\0reloadData\0total\0"
    "refreshView\0resetValidToDateTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReportingDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x08 /* Private */,
       5,    1,   58,    2, 0x08 /* Private */,
       7,    1,   61,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::ULong,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ReportingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReportingDialog *_t = static_cast<ReportingDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFilterKeyColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->displayStats(); break;
        case 2: _t->selectSourceModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->showProgression((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->reloadData(); break;
        case 5: { ulong _r = _t->total();
            if (_a[0]) *reinterpret_cast< ulong*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->refreshView(); break;
        case 7: _t->resetValidToDateTime(); break;
        default: ;
        }
    }
}

const QMetaObject ReportingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ReportingDialog.data,
      qt_meta_data_ReportingDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ReportingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReportingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReportingDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ReportingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
