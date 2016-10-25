#include "perihelionprecession.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>
#include <iostream>

void PerihelionPrecession::setupParticles(System &system) {

    double twopi = std::atan(1.0)*8;

    Particle* largeBody = new Particle(vec3(0,0,0), vec3(0,0,0), 1);
    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0,twopi + 2.6 ,0), 3e-6);

    system.addParticle(largeBody);
    system.addParticle(smallBody);
}

std::string PerihelionPrecession::getName() {
    return "Two-body";
}
