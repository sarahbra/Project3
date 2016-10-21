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


        vec3 a1 = p->getForce().operator /=(m);
        vec3 hv = p->getVelocity().operator *=(dt);
        double temp = dt/2;
        p->getPosition().operator +=(hv);
        vec3 tempa = a1.operator *=(temp*dt);
        p->getPosition().operator +=(tempa);


        m_system->computeForces();
        vec3 a2 = p->getForce().operator /=(m);
        a2.operator +=(a1);
        a2.operator *=(temp);
        p->getVelocity().operator +=(a2);
    }
}
