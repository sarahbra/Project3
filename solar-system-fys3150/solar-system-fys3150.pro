TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vec3.cpp \
    system.cpp \
    particle.cpp \
    Integrators/integrator.cpp \
    Potentials/potential.cpp \
    Potentials/newtoniangravity.cpp \
    examples.cpp \
    Integrators/velocityverlet.cpp \
    InitialConditions/initialcondition.cpp \
    InitialConditions/twobody.cpp \
    InitialConditions/threebody.cpp \
    Integrators/euler.cpp \
    InitialConditions/solarsystem.cpp \
    Potentials/newtonianrelativisticgravity.cpp \
    InitialConditions/perihelionprecession.cpp


HEADERS += \
    vec3.h \
    system.h \
    particle.h \
    Integrators/integrator.h \
    Potentials/potential.h \
    Potentials/newtoniangravity.h \
    examples.h \
    Integrators/velocityverlet.h \
    InitialConditions/initialcondition.h \
    InitialConditions/twobody.h \
    InitialConditions/threebody.h \
    Integrators/euler.h \
    InitialConditions/solarsystem.h \
    Potentials/newtonianrelativisticgravity.h \
    InitialConditions/perihelionprecession.h

