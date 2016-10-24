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


        vec3 F1 = p->getForce();
        vec3 a1 = F1.operator /=(m);
        vec3 v = p->getVelocity();
        double temp = dt/2;

        p->getPosition().operator += ((v.operator *=(dt)).operator +=(a1.operator *=(temp*dt)));


        m_system->computeForces();

        vec3 F2 = p->getForce();
        vec3 a2 = F2.operator /=(m);

        p->getVelocity().operator +=((a2.operator +=(a1)).operator *=(temp));
    }
}
