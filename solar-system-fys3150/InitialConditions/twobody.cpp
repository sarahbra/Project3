#include "twobody.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void TwoBody::setupParticles(System &system) {

<<<<<<< HEAD
    double pi = std::atan(1.0)*4;
=======
    double pi = std::atan(1)*4;
    double vy = 2*pi;

>>>>>>> 47bbc333ba2255411328fef961ceeedb3dcaf4a3
    Particle* largeBody = new Particle(vec3(0,0,0), vec3(0,0,0), 2e30);
    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0,2*pi,0), 6e24);
    system.addParticle(largeBody);
    system.addParticle(smallBody);
}

std::string TwoBody::getName() {
    return "Two-body";
}
