#include "newtoniangravity.h"
#include <iostream>

#include <cmath>


NewtonianGravity::NewtonianGravity(double G) : m_G(G) {

}


void NewtonianGravity::computeForces(Particle &a, Particle &b) {
    double m1 = a.getMass();
    double m2 = b.getMass();

    double Fx, Fy;

    vec3 r = b.getPosition();
    double r_length = r.length();
    Fx = (-(m1*m2)*m_G)/pow(r_length,3)*r[0];
    Fy = (-(m1*m2)*m_G)/pow(r_length,3)*r[1];
    b.addForce(Fx, Fy, 0);
}

std::string NewtonianGravity::getName() {
    return "Newtonian gravity";
}
