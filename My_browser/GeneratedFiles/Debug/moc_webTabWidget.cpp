/****************************************************************************
** Meta object code from reading C++ file 'webTabWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../webTabWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webTabWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_webTabWidget_t {
    QByteArrayData data[10];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_webTabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_webTabWidget_t qt_meta_stringdata_webTabWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "webTabWidget"
QT_MOC_LITERAL(1, 13, 12), // "loadpressnum"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "send_Title_url"
QT_MOC_LITERAL(4, 42, 8), // "QString&"
QT_MOC_LITERAL(5, 51, 5), // "QUrl&"
QT_MOC_LITERAL(6, 57, 11), // "CloseSingal"
QT_MOC_LITERAL(7, 69, 9), // "startload"
QT_MOC_LITERAL(8, 79, 10), // "currentUrl"
QT_MOC_LITERAL(9, 90, 11) // "clearCookie"

    },
    "webTabWidget\0loadpressnum\0\0send_Title_url\0"
    "QString&\0QUrl&\0CloseSingal\0startload\0"
    "currentUrl\0clearCookie"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_webTabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    2,   47,    2, 0x06 /* Public */,
       6,    0,   52,    2, 0x06 /* Public */,
       7,    0,   53,    2, 0x06 /* Public */,
       8,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 5,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void webTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        webTabWidget *_t = static_cast<webTabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadpressnum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->send_Title_url((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QUrl(*)>(_a[2]))); break;
        case 2: _t->CloseSingal(); break;
        case 3: _t->startload(); break;
        case 4: _t->currentUrl((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 5: _t->clearCookie((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (webTabWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&webTabWidget::loadpressnum)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (webTabWidget::*_t)(QString & , QUrl & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&webTabWidget::send_Title_url)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (webTabWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&webTabWidget::CloseSingal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (webTabWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&webTabWidget::startload)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (webTabWidget::*_t)(QUrl & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&webTabWidget::currentUrl)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject webTabWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_webTabWidget.data,
      qt_meta_data_webTabWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *webTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *webTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_webTabWidget.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int webTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void webTabWidget::loadpressnum(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void webTabWidget::send_Title_url(QString & _t1, QUrl & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void webTabWidget::CloseSingal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void webTabWidget::startload()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void webTabWidget::currentUrl(QUrl & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
