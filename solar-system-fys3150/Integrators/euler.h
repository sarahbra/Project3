#pragma once
#include "integrator.h"
#include "../particle.h"
#include <vector>

class Euler : public Integrator {
public:
    Euler(class System* system);
    void integrateOneStep(std::vector<Particle*> particles);
    std::string getName();
};
