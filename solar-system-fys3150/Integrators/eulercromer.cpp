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
        F.operator /=(m);
        F.operator *=(dt);
        p->getVelocity().operator +=(F);
        p->getPosition().operator +=(p->getVelocity().operator *=(dt));
        cout << "euler"<<endl;

    }

}

std::string EulerCromer::getName() {
    return "Euler-Cromer";
}
