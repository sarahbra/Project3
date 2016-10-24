#include "solarsystem.h"
#include "../vec3.h"
#include "../system.h"
#include <cmath>

void SolarSystem::setupParticles(System &system) {
    double pi = std::atan(1.0)*4;

    Particle* sun = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);
    Particle* earth = new Particle(vec3(1,0,0), vec3(0,2*pi,0), 3e-6);
    Particle* jupiter = new Particle(vec3(5.2,0,0), vec3(0.21,-2.61,0), 9.5e-4);
    Particle* mars = new Particle(vec3(1.52,0,0), vec3(0,0,0), 3.3e-7);
    Particle* venus = new Particle(vec3(0.72,0,0), vec3(0,0,0),2.45e-6);
    Particle* saturn = new Particle(vec3(9.54,0,0), vec3(0,0,0), 2.75e-4);
    Particle* mercury = new Particle(vec3(0.39,0,0), vec3(0,0,0), 1.65e-7);
    Particle* uranus = new Particle(vec3(19.19,0,0), vec3(0,0,0), 4.4e-5);
    Particle* neptune = new Particle(vec3(30.06,0,0), vec3(0,0,0), 5.15e-5);
    Particle* pluto = new Particle(vec3(39.53,0,0), vec3(0,0,0), 6.55e-9);

    system.addParticle(sun);
    system.addParticle(earth);
    system.addParticle(jupiter);
    system.addParticle(mars);
    system.addParticle(venus);
    system.addParticle(saturn);
    system.addParticle(mercury);
    system.addParticle(uranus);
    system.addParticle(neptune);
    system.addParticle(pluto);
}

std::string SolarSystem::getName() {
        return "Many-Body Solar-system";

}
