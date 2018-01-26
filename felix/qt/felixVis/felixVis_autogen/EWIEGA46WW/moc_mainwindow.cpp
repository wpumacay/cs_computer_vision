/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_felix__qt__LMainWindow_t {
    QByteArrayData data[7];
    char stringdata0[78];
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
QT_MOC_LITERAL(6, 62, 15) // "slotConvolution"

    },
    "felix::qt::LMainWindow\0slotOpen\0\0"
    "slotSave\0slotQuit\0slotAffine\0"
    "slotConvolution"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_felix__qt__LMainWindow[] = {

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
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject felix::qt::LMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_felix__qt__LMainWindow.data,
      qt_meta_data_felix__qt__LMainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *felix::qt::LMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *felix::qt::LMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_felix__qt__LMainWindow.stringdata0))
        return static_cast<void*>(const_cast< LMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int felix::qt::LMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
