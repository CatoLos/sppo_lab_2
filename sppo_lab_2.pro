TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    CppUnitGenerator.cpp \
    CppUnits.cpp \
    main.cpp \
    Units.cpp

HEADERS += \
    CppUnitGenerator.h \
    CppUnits.h \
    IUnitGenerator.h \
    Units.h
