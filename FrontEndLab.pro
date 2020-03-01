TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS += \
    -lwthttp \
    -lwt \
    -lstdc++fs \
    -lpthread \
    -lboost_system

SOURCES += \
        calculation.cpp \
        feescalculation.cpp \
        header.cpp \
        main.cpp \
        mainpage.cpp \
        text_generators.cpp \
        trademarkpage.cpp \
        yesnowidget.cpp

HEADERS += \
    bootstrap_config.h \
    calculation.h \
    fees.h \
    feescalculation.h \
    header.h \
    industrialdesignpage.h \
    inventionpage.h \
    mainpage.h \
    text_generators.h \
    trademarkpage.h \
    utilitymodelpage.h \
    yesnowidget.h
