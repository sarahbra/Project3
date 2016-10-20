#include "velocityverlet.h"
#include "../system.h"

VelocityVerlet::VelocityVerlet(System* system)
    : Integrator(system) {
}

std::string VelocityVerlet::getName() {
    return "Velocity verlet";
}

void VelocityVerlet::integrateOneStep(std::vector<Particle*> particles) {
    for (int i = 0; i < particles.size(); i++) {
        Particle *p = particles.at(i);
        vec3 pos = p->getposition();
        vec3 vel = p->getVelocity();
        double dt = Integrator.getDt();


    }
}
