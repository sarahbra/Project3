#include "solarsystem.h"
#include "../vec3.h"
#include "../system.h"

void SolarSystem::setupParticles(System &system) {

    Particle* sun = new Particle(vec3(0,0,0), vec3(0,0,0), 1.0);
    Particle* earth = new Particle(vec3(0.90,0.43,0), vec3(-2.83,5.62,0), 3.0e-6);
    Particle* jupiter = new Particle(vec3(-5.43,-4.82,0), vec3(0.21,-2.61,0), 9.5e-4);
    Particle* mars = new Particle(vec3(1.19,-6.98e-1,0), vec3(2.79,4.85,0), 3.3e-7);
    Particle* venus = new Particle(vec3(2.77e-1,-0.67,0), vec3(6.78,2.75,0),2.45e-6);
    Particle* saturn = new Particle(vec3(-2.25,-9.78,0), vec3(1.87,-0.46,0), 2.75e-4);
    Particle* mercury = new Particle(vec3(-0.39,-2.71e-2,0), vec3(-1.34,-10.44,0), 1.65e-7);
    Particle* uranus = new Particle(vec3(18.46,7.58,0), vec3(-0.55,1.26,0), 4.4e-5);
    Particle* neptune = new Particle(vec3(28.27,-9.91,0), vec3(0.37,1.09,0), 5.15e-5);
    Particle* pluto = new Particle(vec3(9.44,-31.81,0), vec3(1.12,0.09,0), 6.55e-9);

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
