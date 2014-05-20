#-------------------------------------------------
#
# Project created by QtCreator 2014-05-13T07:09:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProyectoOrga
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    creartabla.cpp \
    editartabla.cpp \
    mainwindowdatabaseengine.cpp \
    metadata.cpp \
    field.cpp \
    bloque.cpp \
    vertabla.cpp

HEADERS  += mainwindow.h \
    creartabla.h \
    editartabla.h \
    mainwindowdatabaseengine.h \
    metadata.h \
    field.h \
    bloque.h \
    vertabla.h

FORMS    += mainwindow.ui \
    creartabla.ui \
    editartabla.ui \
    mainwindowdatabaseengine.ui \
    vertabla.ui

RESOURCES += \
    Resources.qrc
