/****************************************************************************
** Meta object code from reading C++ file 'timeritem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../timeritem.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timeritem.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9TimerItemE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN9TimerItemE = QtMocHelpers::stringData(
    "TimerItem",
    "timerDeleted",
    "",
    "TimerItem*",
    "timer",
    "timerFinished",
    "playEndTimer",
    "repeatTimer",
    "pauseTimer",
    "updateDisplay",
    "handleTimerFinished",
    "removeTimer",
    "on_startPauseButton_clicked",
    "on_deleteTimer_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN9TimerItemE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       5,    1,   77,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   80,    2, 0x08,    5 /* Private */,
       7,    0,   81,    2, 0x08,    6 /* Private */,
       8,    0,   82,    2, 0x08,    7 /* Private */,
       9,    0,   83,    2, 0x08,    8 /* Private */,
      10,    0,   84,    2, 0x08,    9 /* Private */,
      11,    0,   85,    2, 0x08,   10 /* Private */,
      12,    0,   86,    2, 0x08,   11 /* Private */,
      13,    0,   87,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

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

Q_CONSTINIT const QMetaObject TimerItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN9TimerItemE.offsetsAndSizes,
    qt_meta_data_ZN9TimerItemE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN9TimerItemE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TimerItem, std::true_type>,
        // method 'timerDeleted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TimerItem *, std::false_type>,
        // method 'timerFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TimerItem *, std::false_type>,
        // method 'playEndTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'repeatTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleTimerFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startPauseButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteTimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TimerItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TimerItem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->timerDeleted((*reinterpret_cast< std::add_pointer_t<TimerItem*>>(_a[1]))); break;
        case 1: _t->timerFinished((*reinterpret_cast< std::add_pointer_t<TimerItem*>>(_a[1]))); break;
        case 2: _t->playEndTimer(); break;
        case 3: _t->repeatTimer(); break;
        case 4: _t->pauseTimer(); break;
        case 5: _t->updateDisplay(); break;
        case 6: _t->handleTimerFinished(); break;
        case 7: _t->removeTimer(); break;
        case 8: _t->on_startPauseButton_clicked(); break;
        case 9: _t->on_deleteTimer_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TimerItem* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< TimerItem* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (TimerItem::*)(TimerItem * );
            if (_q_method_type _q_method = &TimerItem::timerDeleted; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (TimerItem::*)(TimerItem * );
            if (_q_method_type _q_method = &TimerItem::timerFinished; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *TimerItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimerItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN9TimerItemE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TimerItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void TimerItem::timerDeleted(TimerItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TimerItem::timerFinished(TimerItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
