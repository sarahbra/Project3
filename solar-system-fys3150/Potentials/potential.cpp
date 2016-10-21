#include "potential.h"
#include <iostream>
#include <cmath>

void Potential::computeForces(Particle &a, Particle &b){
    //B is earth
    double m = b.getMass();
    vec3 F = b.getForce();
    vec3 r = b.getPosition();

    double x = r[0];
    double y = r[1];
    double Fx, Fy, tempr, temp, radii;
    const double pi = 3.1415926535897;
    tempr = x*x + y*y;
    radii = sqrt(tempr);
    temp = ((m*4*pi*pi)/pow(tempr,3));
    Fx = -temp*x;
    Fy = -temp*y;

    b.addForce(Fx,Fy,0);


}

std::string Potential::getName() {
    return "Unknown";
}

