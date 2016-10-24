#include "euler.h"
#include "../system.h"

#include <iostream>
using namespace std;
Euler::Euler(System* system)
    : Integrator(system) {
}

void Euler::integrateOneStep(std::vector<Particle*> particles) {
    m_system->computeForces();
    for (int i=0; i<particles.size(); i++) {
        Particle *p = particles.at(i);
        double m = p->getMass();

        vec3 F = p->getForce();
        vec3 a = F.operator /=(m);
        vec3 v = p->getVelocity();
        double dt = getDt();

        p->getPosition().operator +=(v.operator *=(dt));
        p->getVelocity().operator +=(a.operator *=(dt));

    }

}

std::string Euler::getName() {
    return "Euler";
}
