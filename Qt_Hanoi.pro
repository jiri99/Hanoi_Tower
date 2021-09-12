TEMPLATE = app
TARGET = Qt_Hanoi.pro

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    drawingarea.cpp \
    main.cpp \
    navbar.cpp \
    tower.cpp

HEADERS += \
    drawingarea.h \
    navbar.h \
    tower.h
