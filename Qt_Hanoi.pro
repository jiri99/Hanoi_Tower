TEMPLATE = app
TARGET = Qt_Hanoi.pro

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    navbar.cpp \
    tower.cpp

HEADERS += \
    navbar.h \
    tower.h
