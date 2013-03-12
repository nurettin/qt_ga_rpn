#-------------------------------------------------
#
# Project created by QtCreator 2013-03-10T19:43:00
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_tests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
SOURCES += ../util.cpp
SOURCES += ../rpn.cpp

SOURCES += tst_tests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
