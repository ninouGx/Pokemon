TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ai.cpp \
        functions.cpp \
        functionsPoke.cpp \
        gameloop.cpp \
        main.cpp \
        pokemon.cpp \
        trainer.cpp

HEADERS += \
    ai.h \
    functions.h \
    functionsPoke.h \
    gameloop.h \
    pokemon.h \
    trainer.h
