#include "velocityverlet.h"
#include "../system.h"

#include <iostream>


VelocityVerlet::VelocityVerlet(System* system)
    : Integrator(system) {
}

std::string VelocityVerlet::getName() {
    return "Velocity verlet";
}

void VelocityVerlet::integrateOneStep(std::vector<Particle*> particles) {

    m_system->computeForces();

    for (int i = 0; i < particles.size(); i++) {
        Particle *p = particles.at(i);
        double dt = getDt();
        double m = p->getMass();
        vec3 a1 = p->getForce()/m;
        p->getPosition().operator +=(dt*p->getVelocity().operator +=(a1*(dt*dt)/2.0));

        m_system->computeForces();
        vec3 a2 = p->getForce()/m;
        p->getVelocity().operator +=(dt/2.0*a2.operator +=(a1));

    }
}
