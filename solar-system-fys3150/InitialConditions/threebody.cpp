#include "threebody.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>

void ThreeBody::setupParticles(System &system) {
    double twopi = std::atan(1.0)*8;
    double mass1 = 3.0e-6;
    double mass2 = 9.5e-4;

    Particle* sun = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);
<<<<<<< HEAD
    Particle* earth = new Particle(vec3(1,0,0), vec3(0,2*pi,0), 3.0e-6);
    Particle* jupiter = new Particle(vec3(-5.43,-4.82,0), vec3(0.21,-2.61,0), 9.5e-3);
=======
    Particle* earth = new Particle(vec3(1.0,0,0), vec3(0,twopi,0), mass1);
    Particle* jupiter = new Particle(vec3(5.2,0,0), vec3(0,-2.68,0), mass2);
>>>>>>> 7e61dc4c701a1e6dd8b029abfb61325ee1d915ad

    system.addParticle(sun);
    system.addParticle(earth);
    system.addParticle(jupiter);
}

std::string ThreeBody::getName() {
    return "Three-body";
}
