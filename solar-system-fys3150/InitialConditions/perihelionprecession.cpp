#include "perihelionprecession.h"
#include "../vec3.h"
#include "../system.h"

void PerihelionPrecession::setupParticles(System &system) {

    Particle* sun = new Particle(vec3(0,0,0), vec3(0,0,0), 1);
    Particle* mercury = new Particle(vec3(0.3075,0,0), vec3(0,12.44,0), 1.65e-7);

    system.addParticle(sun);
    system.addParticle(mercury);
}

std::string PerihelionPrecession::getName() {
    return "Perihelion precession Mercury";
}
