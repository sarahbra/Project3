#include "newtoniangravity.h"
#include <iostream>
#include <cmath>


NewtonianGravity::NewtonianGravity(double G) : m_G(G) {

}

void NewtonianGravity::computeForces(Particle &a, Particle &b) {
    double m1 = a.getMass();
    double m2 = b.getMass();

    double Fxa, Fya, Fxb, Fyb;

    vec3 rb = b.getPosition();
    vec3 ra = a.getPosition();
    vec3 r = rb.operator -=(ra);
    double r_length = r.length();
    Fxa = (-(m1*m2)*m_G)/pow(r_length,3)*ra[0];
    Fya = (-(m1*m2)*m_G)/pow(r_length,3)*ra[1];
    Fxb = (-(m1*m2)*m_G)/pow(r_length,3)*rb[0];
    Fyb = (-(m1*m2)*m_G)/pow(r_length,3)*rb[1];
    a.addForce(Fxa, Fya, 0);
    b.addForce(Fxb, Fyb, 0);
}

std::string NewtonianGravity::getName() {
    return "Newtonian gravity";
}
