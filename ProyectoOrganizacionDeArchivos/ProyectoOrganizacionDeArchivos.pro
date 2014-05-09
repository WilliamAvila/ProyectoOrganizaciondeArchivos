#-------------------------------------------------
#
# Project created by QtCreator 2014-04-27T14:43:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProyectoOrganizacionDeArchivos
TEMPLATE = app


SOURCES += main.cpp\
        bd.cpp \
    creartabla.cpp \
    filebinario.cpp \
    bloque.cpp \
    Data.cpp \
    DefinicionDeCampo.cpp \
    masterblock.cpp \
    metadata.cpp

HEADERS  += bd.h \
    creartabla.h \
    filebinario.h \
    bloque.h \
    Data.h \
    DefinicionDeCampo.h \
    masterblock.h \
    metadata.h

FORMS    += bd.ui \
    creartabla.ui
