/****************************************************************************
** Meta object code from reading C++ file 'views.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "views.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'views.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListingDialog_t {
    QByteArrayData data[14];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListingDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListingDialog_t qt_meta_stringdata_ListingDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ListingDialog"
QT_MOC_LITERAL(1, 14, 18), // "setFilterKeyColumn"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "col"
QT_MOC_LITERAL(4, 38, 7), // "addItem"
QT_MOC_LITERAL(5, 46, 11), // "removeItems"
QT_MOC_LITERAL(6, 58, 8), // "showItem"
QT_MOC_LITERAL(7, 67, 14), // "showItemsCount"
QT_MOC_LITERAL(8, 82, 13), // "enableButtons"
QT_MOC_LITERAL(9, 96, 16), // "resizeSearchItem"
QT_MOC_LITERAL(10, 113, 14), // "moveSearchItem"
QT_MOC_LITERAL(11, 128, 11), // "odlposition"
QT_MOC_LITERAL(12, 140, 11), // "newposition"
QT_MOC_LITERAL(13, 152, 13) // "disableEscape"

    },
    "ListingDialog\0setFilterKeyColumn\0\0col\0"
    "addItem\0removeItems\0showItem\0"
    "showItemsCount\0enableButtons\0"
    "resizeSearchItem\0moveSearchItem\0"
    "odlposition\0newposition\0disableEscape"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListingDialog[] = {

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
       1,    1,   59,    2, 0x09 /* Protected */,
       4,    0,   62,    2, 0x09 /* Protected */,
       5,    0,   63,    2, 0x09 /* Protected */,
       6,    0,   64,    2, 0x09 /* Protected */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    1,   67,    2, 0x08 /* Private */,
      10,    3,   70,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,   11,   12,
    QMetaType::Void,

       0        // eod
};

void ListingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ListingDialog *_t = static_cast<ListingDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFilterKeyColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { int _r = _t->addItem();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->removeItems(); break;
        case 3: _t->showItem(); break;
        case 4: _t->showItemsCount(); break;
        case 5: _t->enableButtons(); break;
        case 6: _t->resizeSearchItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->moveSearchItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->disableEscape(); break;
        default: ;
        }
    }
}

const QMetaObject ListingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ListingDialog.data,
      qt_meta_data_ListingDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ListingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListingDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ListingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_ProductListingDialog_t {
    QByteArrayData data[5];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProductListingDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProductListingDialog_t qt_meta_stringdata_ProductListingDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ProductListingDialog"
QT_MOC_LITERAL(1, 21, 7), // "addItem"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "removeItems"
QT_MOC_LITERAL(4, 42, 8) // "showItem"

    },
    "ProductListingDialog\0addItem\0\0removeItems\0"
    "showItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductListingDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProductListingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProductListingDialog *_t = static_cast<ProductListingDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->addItem();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->removeItems(); break;
        case 2: _t->showItem(); break;
        default: ;
        }
    }
}

const QMetaObject ProductListingDialog::staticMetaObject = {
    { &ListingDialog::staticMetaObject, qt_meta_stringdata_ProductListingDialog.data,
      qt_meta_data_ProductListingDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProductListingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductListingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProductListingDialog.stringdata0))
        return static_cast<void*>(this);
    return ListingDialog::qt_metacast(_clname);
}

int ProductListingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ListingDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_FamilyListingDialog_t {
    QByteArrayData data[5];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FamilyListingDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FamilyListingDialog_t qt_meta_stringdata_FamilyListingDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "FamilyListingDialog"
QT_MOC_LITERAL(1, 20, 7), // "addItem"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "removeItems"
QT_MOC_LITERAL(4, 41, 8) // "showItem"

    },
    "FamilyListingDialog\0addItem\0\0removeItems\0"
    "showItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FamilyListingDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x09 /* Protected */,
       3,    0,   30,    2, 0x09 /* Protected */,
       4,    0,   31,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FamilyListingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FamilyListingDialog *_t = static_cast<FamilyListingDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->addItem();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->removeItems(); break;
        case 2: _t->showItem(); break;
        default: ;
        }
    }
}

const QMetaObject FamilyListingDialog::staticMetaObject = {
    { &ListingDialog::staticMetaObject, qt_meta_stringdata_FamilyListingDialog.data,
      qt_meta_data_FamilyListingDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FamilyListingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FamilyListingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FamilyListingDialog.stringdata0))
        return static_cast<void*>(this);
    return ListingDialog::qt_metacast(_clname);
}

int FamilyListingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ListingDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
