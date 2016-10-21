#pragma once
#include "../particle.h"
#include <string>

class Potential {
protected:
    double m_potentialEnergy = 0;

public:
    Potential() {}
    virtual std::string getName();
    virtual void computeForces(Particle& a, Particle& b) = 0;
    void   resetPotentialEnergy() { m_potentialEnergy = 0; }
    double getPotentialEnergy()   { return m_potentialEnergy; }
};
