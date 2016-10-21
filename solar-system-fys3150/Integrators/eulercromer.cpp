#include "eulercromer.h"
#include "../system.h"
#include <iostream>
EulerCromer::EulerCromer(System* system)
    : Integrator(system) {
}

void EulerCromer::integrateOneStep(std::vector<Particle*> particles) {
    m_system->computeForces();
    for (int i=0; i<particles.size(); i++) {
        Particle *p = particles.at(i);
        /*
         * This is where you need to update the positions and the velocities
         * and the velocities of each particle according to the Euler-Cromer
         * scheme.
         *
         * You can access the position of particle number i by
         *
         *      p->getPosition()
         *
         * Remember that the positions and velocities of all the particles are
         * vec3 vectors, which you can use the +=, -=, etc. operators on.
         */
        vec3 r = p->getPosition();
        vec3 v = p->getVelocity();
        vec3 F = p->getForce();
        double m = p->getMass();
        double dt = getDt();


        double x = r[0];
        double y = r[1];
        double vx = v[0];
        double vy = v[1];
        double Fx = F[0];
        double Fy = F[1];

        double ax = Fx/m;
        double ay = Fy/m;
        vx += ax*dt;
        vy += ay*dt;
        x += vx*dt;
        y += vy*dt;

        std:: cout << "x" << x << "y" << y << std::endl;
        r[0] = x;
        r[1] = y;
        v[0] = vx;
        v[1] = vy;
        p->setPosVel(r,v);

    }
}

std::string EulerCromer::getName() {
    return "Euler-Cromer";
}
