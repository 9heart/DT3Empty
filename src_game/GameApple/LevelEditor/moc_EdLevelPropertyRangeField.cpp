/****************************************************************************
** Meta object code from reading C++ file 'EdLevelPropertyRangeField.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/DT3LevelEditor/Properties/EdLevelPropertyRangeField.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EdLevelPropertyRangeField.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EdLevelPropertyRangeField_t {
    QByteArrayData data[12];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_EdLevelPropertyRangeField_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_EdLevelPropertyRangeField_t qt_meta_stringdata_EdLevelPropertyRangeField = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 9),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 7),
QT_MOC_LITERAL(4, 45, 7),
QT_MOC_LITERAL(5, 53, 9),
QT_MOC_LITERAL(6, 63, 8),
QT_MOC_LITERAL(7, 72, 10),
QT_MOC_LITERAL(8, 83, 12),
QT_MOC_LITERAL(9, 96, 13),
QT_MOC_LITERAL(10, 110, 14),
QT_MOC_LITERAL(11, 125, 17)
    },
    "EdLevelPropertyRangeField\0doCommand\0"
    "\0command\0recache\0doKeyMenu\0property\0"
    "global_pos\0doReadParams\0doWriteParams\0"
    "doWriteParams2\0doKeyframePressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EdLevelPropertyRangeField[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x05,
       5,    2,   49,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    0,   54,    2, 0x0a,
       9,    0,   55,    2, 0x0a,
      10,    0,   56,    2, 0x0a,
      11,    0,   57,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QPointF,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EdLevelPropertyRangeField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EdLevelPropertyRangeField *_t = static_cast<EdLevelPropertyRangeField *>(_o);
        switch (_id) {
        case 0: _t->doCommand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->doKeyMenu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2]))); break;
        case 2: _t->doReadParams(); break;
        case 3: _t->doWriteParams(); break;
        case 4: _t->doWriteParams2(); break;
        case 5: _t->doKeyframePressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EdLevelPropertyRangeField::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EdLevelPropertyRangeField::doCommand)) {
                *result = 0;
            }
        }
        {
            typedef void (EdLevelPropertyRangeField::*_t)(QString , const QPointF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EdLevelPropertyRangeField::doKeyMenu)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject EdLevelPropertyRangeField::staticMetaObject = {
    { &EdLevelPropertyBase::staticMetaObject, qt_meta_stringdata_EdLevelPropertyRangeField.data,
      qt_meta_data_EdLevelPropertyRangeField,  qt_static_metacall, 0, 0}
};


const QMetaObject *EdLevelPropertyRangeField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EdLevelPropertyRangeField::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EdLevelPropertyRangeField.stringdata))
        return static_cast<void*>(const_cast< EdLevelPropertyRangeField*>(this));
    return EdLevelPropertyBase::qt_metacast(_clname);
}

int EdLevelPropertyRangeField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = EdLevelPropertyBase::qt_metacall(_c, _id, _a);
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
void EdLevelPropertyRangeField::doCommand(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EdLevelPropertyRangeField::doKeyMenu(QString _t1, const QPointF & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
