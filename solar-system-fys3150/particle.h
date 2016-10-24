#pragma once
#include "vec3.h"

class Particle {
private:
    vec3    m_position  = vec3(0,0,0);
    vec3    m_velocity  = vec3(0,0,0);
    vec3    m_forces    = vec3(0,0,0);
    double  m_mass      = 0;
    double  m_potential_energy = 0;

public:
    Particle();
    Particle(class vec3 position, class vec3 velocity, double mass);
    void resetForces();
    void addForce(double dFx, double dFy, double dFz);
    void resetPotentialEnergy();
    void addPotentialEnergy(double PotEnergy);
    double velocitySquared();


    // Getters.
    vec3& getPosition() { return m_position; }
    vec3& getVelocity() { return m_velocity; }
    vec3& getForce()    { return m_forces; }
    double getPotentialEnergy() { return m_potential_energy; }
    double getMass()    { return m_mass; }
};

