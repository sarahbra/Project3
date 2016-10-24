#include "newtoniangravity.h"
#include <iostream>
#include <cmath>


NewtonianGravity::NewtonianGravity(double G) : m_G(G) {

}

void NewtonianGravity::computeForces(Particle &a, Particle &b) {

    //initiating variables
    double m1 = a.getMass();
    double m2 = b.getMass();

    double Ub, Fxa, Fya, Fxb, Fyb;

    vec3 rb = b.getPosition();
    vec3 ra = a.getPosition();
    vec3 r = rb.operator -=(ra);
    double r_length = r.length();

    //Calculating Newtonian forces (equal, but opposite for particles a and b)
    Ub = (-((m1*m2)*m_G)/r_length);
    Fxa = (-Ub/r.lengthSquared())*ra[0];
    Fya = (-Ub/r.lengthSquared())*ra[1];
    Fxb = (Ub/r.lengthSquared())*rb[0];
    Fyb = (Ub/r.lengthSquared())*rb[1];

    //adding forces
    a.addForce(Fxa, Fya, 0);
    b.addForce(Fxb, Fyb, 0);
    b.addPotentialEnergy(Ub);
}

std::string NewtonianGravity::getName() {
    return "Newtonian gravity";
}
