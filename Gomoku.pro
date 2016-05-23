#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T14:18:04
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = Gomoku
TEMPLATE = app

SOURCES += main.cpp\
        GomokuWindow.cpp \
    Field.cpp \
    Cell.cpp \
    CellItem.cpp

HEADERS  += GomokuWindow.hpp \
    Field.hpp \
    Cell.hpp \
    CellItem.hpp

FORMS    += GomokuWindow.ui
