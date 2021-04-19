TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    CodeCompiler.cpp \
    CppUnitGenerator.cpp \
    CppUnits.cpp \
    CsUnitGenerator.cpp \
    CsUnits.cpp \
    JavaUnitGenerator.cpp \
    JavaUnits.cpp \
    main.cpp \
    Units.cpp

HEADERS += \
    CodeCompiler.h \
    CppUnitGenerator.h \
    CppUnits.h \
    CsUnitGenerator.h \
    CsUnits.h \
    IUnitGenerator.h \
    JavaUnitGenerator.h \
    JavaUnits.h \
    Units.h
