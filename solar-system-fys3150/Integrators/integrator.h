#pragma once
#include <vector>
#include <string>
#include "../particle.h"

class Integrator {
protected:
<<<<<<< HEAD
    double          m_dt        = 1e-6;
=======

    double          m_dt        = 1e-4;

>>>>>>> 443e202c5bf2e477b81570fa68dfce523473df78
    class System*   m_system    = nullptr;

public:
    Integrator(class System* system);
    void setDt(double dt);
    double getDt() { return m_dt; }
    virtual std::string getName();
    virtual void integrateOneStep(std::vector<Particle*> particles) = 0;
};
