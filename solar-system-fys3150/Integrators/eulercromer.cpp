#include "eulercromer.h"
#include "../system.h"

#include <iostream>
using namespace std;
EulerCromer::EulerCromer(System* system)
    : Integrator(system) {
}

void EulerCromer::integrateOneStep(std::vector<Particle*> particles) {
    m_system->computeForces();
    for (int i=0; i<particles.size(); i++) {
        Particle *p = particles.at(i);
        double m = p->getMass();
        vec3 F = p->getForce();
        double dt = getDt();
        vec3 a = F/m;
        p->getVelocity().operator +=(a*dt);
        p->getPosition().operator +=(p->getVelocity()*dt);

        std:: cout << "v" << p->getVelocity() << "r" << p->getPosition() << endl;
    }

}

std::string EulerCromer::getName() {
    return "Euler-Cromer";
}
