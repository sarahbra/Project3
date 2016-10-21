#include "twobody.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>


void TwoBody::setupParticles(System &system) {

<<<<<<< HEAD
    double pi = std::atan(1.0)*4;
    Particle* largeBody = new Particle(vec3(0,0,0), vec3(0,0,0), 2e30);
    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0,2*pi,0), 6e24);
=======
    double pi = 3.14159265359;
    double vy = 2*pi;

    Particle* largeBody = new Particle(vec3(0,0,0), vec3(0,0,0), 2e30);

    Particle* smallBody = new Particle(vec3(1,0,0), vec3(0,vy,0), 6e24);
>>>>>>> 0a4e42c484f3cb6651e97493daa5872cb21bead4
    system.addParticle(largeBody);
    system.addParticle(smallBody);
}

std::string TwoBody::getName() {
    return "Two-body";
}
