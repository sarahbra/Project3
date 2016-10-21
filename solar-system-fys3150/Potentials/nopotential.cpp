#include "nopotential.h"
#include <iostream>


std::string NoPotential::getName() {
    return "No potential";
}


void NoPotential::computeForces(Particle&, Particle&) {
    /*
     * No potential means just no forces acting between the particles, so
     * we dont have to do anything here. This potential can be used to test
     * certain aspects of your code, without the complication of forces.
     */
    std::cout << "funker" << std::endl;
}
