QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = progICC_gl

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    mainwindow.cpp \
    mountain_tab.cpp \
    parameters.cpp \
    parameters_dialog.cpp \
    vue_opengl.cc

HEADERS += \
    glwidget.h \
    mainwindow.h \
    mountain_tab.h \
    parameters.h \
    parameters_dialog.h \
    vertex_shader.h \
    vue_opengl.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h \
    ../general/contenu.h

RESOURCES += \
    resource.qrc

FORMS += \
    parameters_dialog.ui
