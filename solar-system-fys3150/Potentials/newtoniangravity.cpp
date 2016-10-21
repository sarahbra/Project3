#include "newtoniangravity.h"
#include <iostream>
#include <cmath>


NewtonianGravity::NewtonianGravity(double G) : m_G(G) {

}


void NewtonianGravity::computeForces(Particle &a, Particle &b) {
    double m1 = a.getMass();
    double m2 = b.getMass();

    double Fx, Fy;

    vec3 rb = b.getPosition();
    vec3 ra = a.getPosition();
    double r_length = (rb.operator -=(ra)).length();
    Fx = (-(m1*m2)*m_G)/pow(r_length,3)*rb[0];
    Fy = (-(m1*m2)*m_G)/pow(r_length,3)*rb[1];
    b.addForce(Fx, Fy, 0);
}

std::string NewtonianGravity::getName() {
    return "Newtonian gravity";
}
