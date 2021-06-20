/****************************************************************************
** Meta object code from reading C++ file 'imageswitch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imageswitch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageswitch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageSwitch_t {
    QByteArrayData data[11];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageSwitch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageSwitch_t qt_meta_stringdata_ImageSwitch = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ImageSwitch"
QT_MOC_LITERAL(1, 12, 10), // "setChecked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "isChecked"
QT_MOC_LITERAL(4, 34, 14), // "setButtonStyle"
QT_MOC_LITERAL(5, 49, 24), // "ImageSwitch::ButtonStyle"
QT_MOC_LITERAL(6, 74, 11), // "buttonStyle"
QT_MOC_LITERAL(7, 86, 11), // "ButtonStyle"
QT_MOC_LITERAL(8, 98, 13), // "ButtonStyle_1"
QT_MOC_LITERAL(9, 112, 13), // "ButtonStyle_2"
QT_MOC_LITERAL(10, 126, 13) // "ButtonStyle_3"

    },
    "ImageSwitch\0setChecked\0\0isChecked\0"
    "setButtonStyle\0ImageSwitch::ButtonStyle\0"
    "buttonStyle\0ButtonStyle\0ButtonStyle_1\0"
    "ButtonStyle_2\0ButtonStyle_3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageSwitch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   30, // properties
       1,   36, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00095003,
       6, 0x80000000 | 7, 0x0009510b,

 // enums: name, flags, count, data
       7, 0x0,    3,   40,

 // enum data: key, value
       8, uint(ImageSwitch::ButtonStyle_1),
       9, uint(ImageSwitch::ButtonStyle_2),
      10, uint(ImageSwitch::ButtonStyle_3),

       0        // eod
};

void ImageSwitch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageSwitch *_t = static_cast<ImageSwitch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setButtonStyle((*reinterpret_cast< const ImageSwitch::ButtonStyle(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ImageSwitch *_t = static_cast<ImageSwitch *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getChecked(); break;
        case 1: *reinterpret_cast< ButtonStyle*>(_v) = _t->getButtonStyle(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ImageSwitch *_t = static_cast<ImageSwitch *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setChecked(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setButtonStyle(*reinterpret_cast< ButtonStyle*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ImageSwitch::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageSwitch.data,
      qt_meta_data_ImageSwitch,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ImageSwitch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageSwitch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageSwitch.stringdata0))
        return static_cast<void*>(const_cast< ImageSwitch*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageSwitch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
