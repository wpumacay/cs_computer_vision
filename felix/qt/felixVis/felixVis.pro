#-------------------------------------------------
#
# Project created by QtCreator 2018-01-03T19:09:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = felixVis
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += "include/" "ui/" "../../core/include"

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    src/windowWidgets/LRenderArea.cpp \
    ui/lpanelaffinetransforms.cpp \
    ui/lpanelconvolution.cpp \
    ui/lpanelhistogramequalization.cpp \
    ui/lpanelmedianfilter.cpp \
    ui/lpanelfouriertransform.cpp

HEADERS += \
        mainwindow.h \
    include/windowWidgets/LRenderArea.h \
    ui/lpanelaffinetransforms.h \
    ui/lpanelconvolution.h \
    ui/lpanelhistogramequalization.h \
    ui/lpanelmedianfilter.h \
    ui/lpanelfouriertransform.h

FORMS += \
        mainwindow.ui \
    ui/lpanelaffinetransforms.ui \
    ui/lpanelconvolution.ui \
    ui/lpanelhistogramequalization.ui \
    ui/lpanelmedianfilter.ui \
    ui/lpanelfouriertransform.ui
