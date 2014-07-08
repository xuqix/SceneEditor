/****************************************************************************
** Meta object code from reading C++ file 'ListWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TollgateEditor/ListWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ListWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ListWidget_t {
    QByteArrayData data[8];
    char stringdata[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListWidget_t qt_meta_stringdata_ListWidget = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 16),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 18),
QT_MOC_LITERAL(4, 48, 16),
QT_MOC_LITERAL(5, 65, 17),
QT_MOC_LITERAL(6, 83, 6),
QT_MOC_LITERAL(7, 90, 3)
    },
    "ListWidget\0addSpriteToScene\0\0"
    "setSpriteAttribute\0changeSpriteType\0"
    "delSelectedSprite\0filter\0str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void ListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ListWidget *_t = static_cast<ListWidget *>(_o);
        switch (_id) {
        case 0: _t->addSpriteToScene(); break;
        case 1: _t->setSpriteAttribute(); break;
        case 2: _t->changeSpriteType(); break;
        case 3: _t->delSelectedSprite(); break;
        case 4: _t->filter((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ListWidget.data,
      qt_meta_data_ListWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ListWidget.stringdata))
        return static_cast<void*>(const_cast< ListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
