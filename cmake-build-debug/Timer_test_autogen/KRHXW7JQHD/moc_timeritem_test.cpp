/****************************************************************************
** Meta object code from reading C++ file 'timeritem_test.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../tests/timeritem_test.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timeritem_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14timeritem_testE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN14timeritem_testE = QtMocHelpers::stringData(
    "timeritem_test",
    "init",
    "",
    "cleanUp",
    "testInitialization",
    "testSetDuration",
    "testStartPause",
    "testTimerFinished",
    "testRepeatTimer",
    "testDeleteSignal",
    "testAudioSetup"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN14timeritem_testE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    0,   74,    2, 0x08,    7 /* Private */,
       9,    0,   75,    2, 0x08,    8 /* Private */,
      10,    0,   76,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
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

Q_CONSTINIT const QMetaObject timeritem_test::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN14timeritem_testE.offsetsAndSizes,
    qt_meta_data_ZN14timeritem_testE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN14timeritem_testE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<timeritem_test, std::true_type>,
        // method 'init'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cleanUp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'testInitialization'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'testSetDuration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'testStartPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'testTimerFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'testRepeatTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'testDeleteSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'testAudioSetup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void timeritem_test::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<timeritem_test *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->init(); break;
        case 1: _t->cleanUp(); break;
        case 2: _t->testInitialization(); break;
        case 3: _t->testSetDuration(); break;
        case 4: _t->testStartPause(); break;
        case 5: _t->testTimerFinished(); break;
        case 6: _t->testRepeatTimer(); break;
        case 7: _t->testDeleteSignal(); break;
        case 8: _t->testAudioSetup(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *timeritem_test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *timeritem_test::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN14timeritem_testE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int timeritem_test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
