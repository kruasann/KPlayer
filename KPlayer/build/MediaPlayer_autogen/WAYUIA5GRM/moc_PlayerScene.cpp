/****************************************************************************
** Meta object code from reading C++ file 'PlayerScene.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/UI/PlayerScene.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlayerScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPlayerSceneENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPlayerSceneENDCLASS = QtMocHelpers::stringData(
    "PlayerScene",
    "togglePlayPause",
    "",
    "stopPlayback",
    "setVolume",
    "value",
    "seek",
    "updateProgress",
    "position",
    "openFile",
    "exitApplication",
    "handleError",
    "errorString",
    "updateMarquee"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPlayerSceneENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[12];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[10];
    char stringdata5[6];
    char stringdata6[5];
    char stringdata7[15];
    char stringdata8[9];
    char stringdata9[9];
    char stringdata10[16];
    char stringdata11[12];
    char stringdata12[12];
    char stringdata13[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPlayerSceneENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPlayerSceneENDCLASS_t qt_meta_stringdata_CLASSPlayerSceneENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "PlayerScene"
        QT_MOC_LITERAL(12, 15),  // "togglePlayPause"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 12),  // "stopPlayback"
        QT_MOC_LITERAL(42, 9),  // "setVolume"
        QT_MOC_LITERAL(52, 5),  // "value"
        QT_MOC_LITERAL(58, 4),  // "seek"
        QT_MOC_LITERAL(63, 14),  // "updateProgress"
        QT_MOC_LITERAL(78, 8),  // "position"
        QT_MOC_LITERAL(87, 8),  // "openFile"
        QT_MOC_LITERAL(96, 15),  // "exitApplication"
        QT_MOC_LITERAL(112, 11),  // "handleError"
        QT_MOC_LITERAL(124, 11),  // "errorString"
        QT_MOC_LITERAL(136, 13)   // "updateMarquee"
    },
    "PlayerScene",
    "togglePlayPause",
    "",
    "stopPlayback",
    "setVolume",
    "value",
    "seek",
    "updateProgress",
    "position",
    "openFile",
    "exitApplication",
    "handleError",
    "errorString",
    "updateMarquee"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPlayerSceneENDCLASS[] = {

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
       4,    1,   70,    2, 0x08,    3 /* Private */,
       6,    1,   73,    2, 0x08,    5 /* Private */,
       7,    1,   76,    2, 0x08,    7 /* Private */,
       9,    0,   79,    2, 0x08,    9 /* Private */,
      10,    0,   80,    2, 0x08,   10 /* Private */,
      11,    1,   81,    2, 0x08,   11 /* Private */,
      13,    0,   84,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlayerScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSPlayerSceneENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPlayerSceneENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPlayerSceneENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlayerScene, std::true_type>,
        // method 'togglePlayPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopPlayback'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'seek'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'openFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exitApplication'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateMarquee'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PlayerScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayerScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->togglePlayPause(); break;
        case 1: _t->stopPlayback(); break;
        case 2: _t->setVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->seek((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->updateProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 5: _t->openFile(); break;
        case 6: _t->exitApplication(); break;
        case 7: _t->handleError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->updateMarquee(); break;
        default: ;
        }
    }
}

const QMetaObject *PlayerScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPlayerSceneENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PlayerScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
