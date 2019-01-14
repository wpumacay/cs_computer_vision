/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_felix__qt__LMainWindow_t {
    QByteArrayData data[10];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_felix__qt__LMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_felix__qt__LMainWindow_t qt_meta_stringdata_felix__qt__LMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 22), // "felix::qt::LMainWindow"
QT_MOC_LITERAL(1, 23, 8), // "slotOpen"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "slotSave"
QT_MOC_LITERAL(4, 42, 8), // "slotQuit"
QT_MOC_LITERAL(5, 51, 10), // "slotAffine"
QT_MOC_LITERAL(6, 62, 15), // "slotConvolution"
QT_MOC_LITERAL(7, 78, 20), // "slotHistEqualization"
QT_MOC_LITERAL(8, 99, 16), // "slotMedianFilter"
QT_MOC_LITERAL(9, 116, 20) // "slotFourierTransform"

    },
    "felix::qt::LMainWindow\0slotOpen\0\0"
    "slotSave\0slotQuit\0slotAffine\0"
    "slotConvolution\0slotHistEqualization\0"
    "slotMedianFilter\0slotFourierTransform"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_felix__qt__LMainWindow[] = {

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
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void felix::qt::LMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LMainWindow *_t = static_cast<LMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotOpen(); break;
        case 1: _t->slotSave(); break;
        case 2: _t->slotQuit(); break;
        case 3: _t->slotAffine(); break;
        case 4: _t->slotConvolution(); break;
        case 5: _t->slotHistEqualization(); break;
        case 6: _t->slotMedianFilter(); break;
        case 7: _t->slotFourierTransform(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject felix::qt::LMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_felix__qt__LMainWindow.data,
      qt_meta_data_felix__qt__LMainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *felix::qt::LMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *felix::qt::LMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_felix__qt__LMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int felix::qt::LMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
