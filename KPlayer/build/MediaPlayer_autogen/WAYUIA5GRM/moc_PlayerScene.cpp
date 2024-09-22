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
    "rewind",
    "fastForward",
    "createActions",
    "createMenus",
    "seek",
    "updateProgress",
    "position",
    "openFile",
    "exitApplication",
    "handleError",
    "errorString",
    "updateMarquee",
    "handleHasVideoChanged",
    "hasVideo",
    "goBack"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPlayerSceneENDCLASS_t {
    uint offsetsAndSizes[42];
    char stringdata0[12];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[10];
    char stringdata5[6];
    char stringdata6[7];
    char stringdata7[12];
    char stringdata8[14];
    char stringdata9[12];
    char stringdata10[5];
    char stringdata11[15];
    char stringdata12[9];
    char stringdata13[9];
    char stringdata14[16];
    char stringdata15[12];
    char stringdata16[12];
    char stringdata17[14];
    char stringdata18[22];
    char stringdata19[9];
    char stringdata20[7];
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
        QT_MOC_LITERAL(58, 6),  // "rewind"
        QT_MOC_LITERAL(65, 11),  // "fastForward"
        QT_MOC_LITERAL(77, 13),  // "createActions"
        QT_MOC_LITERAL(91, 11),  // "createMenus"
        QT_MOC_LITERAL(103, 4),  // "seek"
        QT_MOC_LITERAL(108, 14),  // "updateProgress"
        QT_MOC_LITERAL(123, 8),  // "position"
        QT_MOC_LITERAL(132, 8),  // "openFile"
        QT_MOC_LITERAL(141, 15),  // "exitApplication"
        QT_MOC_LITERAL(157, 11),  // "handleError"
        QT_MOC_LITERAL(169, 11),  // "errorString"
        QT_MOC_LITERAL(181, 13),  // "updateMarquee"
        QT_MOC_LITERAL(195, 21),  // "handleHasVideoChanged"
        QT_MOC_LITERAL(217, 8),  // "hasVideo"
        QT_MOC_LITERAL(226, 6)   // "goBack"
    },
    "PlayerScene",
    "togglePlayPause",
    "",
    "stopPlayback",
    "setVolume",
    "value",
    "rewind",
    "fastForward",
    "createActions",
    "createMenus",
    "seek",
    "updateProgress",
    "position",
    "openFile",
    "exitApplication",
    "handleError",
    "errorString",
    "updateMarquee",
    "handleHasVideoChanged",
    "hasVideo",
    "goBack"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPlayerSceneENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    0,  105,    2, 0x08,    2 /* Private */,
       4,    1,  106,    2, 0x08,    3 /* Private */,
       6,    0,  109,    2, 0x08,    5 /* Private */,
       7,    0,  110,    2, 0x08,    6 /* Private */,
       8,    0,  111,    2, 0x08,    7 /* Private */,
       9,    0,  112,    2, 0x08,    8 /* Private */,
      10,    1,  113,    2, 0x08,    9 /* Private */,
      11,    1,  116,    2, 0x08,   11 /* Private */,
      13,    0,  119,    2, 0x08,   13 /* Private */,
      14,    0,  120,    2, 0x08,   14 /* Private */,
      15,    1,  121,    2, 0x08,   15 /* Private */,
      17,    0,  124,    2, 0x08,   17 /* Private */,
      18,    1,  125,    2, 0x08,   18 /* Private */,
      20,    0,  128,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
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
        // method 'rewind'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'fastForward'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createActions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createMenus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleHasVideoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'goBack'
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
        case 3: _t->rewind(); break;
        case 4: _t->fastForward(); break;
        case 5: _t->createActions(); break;
        case 6: _t->createMenus(); break;
        case 7: _t->seek((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->updateProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 9: _t->openFile(); break;
        case 10: _t->exitApplication(); break;
        case 11: _t->handleError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->updateMarquee(); break;
        case 13: _t->handleHasVideoChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->goBack(); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
