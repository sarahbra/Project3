#include "threebody.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>

void ThreeBody::setupParticles(System &system) {
    double twopi = std::atan(1.0)*8;
    double mass1 = 3.0e-6;
    double mass2 = 9.5e-4;


    Particle* sun = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);

    Particle* earth = new Particle(vec3(1.0,0,0), vec3(0,twopi,0), mass1);
    Particle* jupiter = new Particle(vec3(5.2,0,0), vec3(0,-2.68,0), mass2);

    //Finding the mass center


    system.addParticle(sun);
    system.addParticle(earth);
    system.addParticle(jupiter);
}

std::string ThreeBody::getName() {
    return "Three-body";
}
