#-------------------------------------------------
#
# Project created by QtCreator 2013-03-06T20:15:05
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = qt_rpn_ga
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    wheel.cpp \
    util.cpp \
    rpn_gene.cpp \
    rpn_dna.cpp \
    rpn.cpp \
    rpn_pool.cpp \
    rpn_dna_comparator.cpp

HEADERS += \
    wheel.h \
    util.h \
    rpn_gene.h \
    rpn_dna.h \
    rpn.h \
    rpn_pool.h \
    rpn_dna_comparator.h
