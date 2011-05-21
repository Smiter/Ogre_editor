
QT       += core
QT       += gui
CONFIG   += console
TARGET = OGRE_EDITOR
TEMPLATE = app
QT += opengl

HEADERS +=   mainwindow.h \
        QtWidget.h \
    precomp.h \
    Engine/Transform.h \
    Engine/Object.h \
    Engine/MeshRenderer.h \
    Engine/GameObject.h \
    Engine/Component.h \
    projectexplorertree.h

CONFIG += precompile_header
PRECOMPILED_HEADER = precomp.h

INCLUDEPATH += "d:/Program Files/OgreSDK_mingw/include/OGRE" \
"d:/Program Files/OgreSDK_mingw/boost_1_44"

LIBS += -L"d:/Program Files/OgreSDK_mingw/lib/debug" -lOgreMain_d

SOURCES += \
    Application.cpp \
    QtWidget.cpp \
    mainwindow.cpp \
    Engine/Transform.cpp \
    Engine/Object.cpp \
    Engine/MeshRenderer.cpp \
    Engine/GameObject.cpp \
    Engine/Component.cpp \
    projectexplorertree.cpp

FORMS += \
    mainwindow.ui
