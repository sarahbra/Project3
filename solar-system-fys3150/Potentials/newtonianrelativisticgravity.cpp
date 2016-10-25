#include "newtonianrelativisticgravity.h"
#include <cmath>



NewtonianRelativisticGravity::NewtonianRelativisticGravity(double G) : m_G(G) {

}

void NewtonianRelativisticGravity::computeForces(Particle &a, Particle &b) {

    //initiating variables
    double m1 = a.getMass();
    double m2 = b.getMass();
    double c = 63145.0;

    double Fx, Fy, F, r_length, temp;

    vec3 r = b.getPosition();
    vec3 vel = b.getVelocity();
    r_length = r.length();

    temp = ((r.cross(vel).lengthSquared()*3)/(pow(r_length,3)*c*c));
    F = (((-m_G*m1*m2)/pow(r_length,3))*(1+temp));
    Fx = F*r[0];
    Fy = F*r[1];

    //adding forces
    b.addForce(Fx, Fy, 0);
}

std::string NewtonianRelativisticGravity::getName() {
    return "Newtonian relativistic gravity";
}
