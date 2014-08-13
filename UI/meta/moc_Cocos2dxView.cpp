/****************************************************************************
** Meta object code from reading C++ file 'Cocos2dxView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Cocos2dxView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Cocos2dxView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cocos2dxView_t {
    QByteArrayData data[7];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cocos2dxView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cocos2dxView_t qt_meta_stringdata_Cocos2dxView = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 14),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 15),
QT_MOC_LITERAL(4, 45, 17),
QT_MOC_LITERAL(5, 63, 15),
QT_MOC_LITERAL(6, 79, 18)
    },
    "Cocos2dxView\0renderCocos2dx\0\0"
    "mouseMoveInView\0mouseMovePosition\0"
    "delChoiceObject\0setObjectAttribute"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cocos2dxView[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cocos2dxView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cocos2dxView *_t = static_cast<Cocos2dxView *>(_o);
        switch (_id) {
        case 0: _t->renderCocos2dx(); break;
        case 1: _t->mouseMoveInView(); break;
        case 2: _t->mouseMovePosition(); break;
        case 3: _t->delChoiceObject(); break;
        case 4: _t->setObjectAttribute(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Cocos2dxView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Cocos2dxView.data,
      qt_meta_data_Cocos2dxView,  qt_static_metacall, 0, 0}
};


const QMetaObject *Cocos2dxView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cocos2dxView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Cocos2dxView.stringdata))
        return static_cast<void*>(const_cast< Cocos2dxView*>(this));
    return QWidget::qt_metacast(_clname);
}

int Cocos2dxView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
