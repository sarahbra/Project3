#pragma once
#include "particle.h"
#include "potential.h"
#include <string>

class NewtonianRelativisticGravity : public Potential {
private:
    double m_G;

public:
    NewtonianRelativisticGravity(double G);
    void computeForces(Particle& a, Particle& b);
    std::string getName();
};
