#include "threebody.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void ThreeBody::setupParticles(System &system) {
    double pi = std::atan(1.0)*4;

    Particle* sun = new Particle(vec3(0,0,0), vec3(0,0,0), 2e30);
    Particle* earth = new Particle(vec3(1,0,0), vec3(0,2*pi,0), 6e24);
    Particle* jupiter = new Particle(vec3(5.2,0,0), vec3(0,0,0), 1.9e27);
    system.addParticle(sun);
    system.addParticle(earth);
    system.addParticle(jupiter);

}

std::string ThreeBody::getName() {
    return "Three-body";
}
