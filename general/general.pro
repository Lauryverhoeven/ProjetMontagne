TEMPLATE = lib

CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++11
#Adds the debug symbols in the libtrary when compiling with debug flag
QMAKE_CXXFLAGS += -g


SOURCES += \
    ChaineDeMontagnes.cpp \
    ChampPotentiels.cpp \
    Echantillon.cpp \
    Montagne.cpp \
    Montagne_pointu.cpp \
    Nuages.cpp \
    Systeme.cpp \
    TextViewer.cpp \
    Vecteur2D.cpp

HEADERS += \
    ChaineDeMontagnes.h \
    ChampPotentiels.h \
    constantes.h \
    Dessinable.h \
    Echantillon.h \
    glwidget.h \
    MontagneAbstraite.h \
    Montagne.h \
    Montagne_pointu.h \
    Nuages.h \
    support_a_dessin.h \
    Systeme.h \
    TextViewer.h \
    Vecteur2D.h
