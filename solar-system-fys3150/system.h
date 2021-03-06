#pragma once
#include "particle.h"
#include <vector>
#include <fstream>
#include "vec3.h"

class System {
private:
    bool                        m_writeToFile       = false;
    bool                        m_outFileOpen       = false;
    int                         m_integrateSteps    = 0;
    int                         m_numberOfParticles = 0;
    double                      m_kineticEnergy     = 0;
    double                      m_totalEnergy       = 0;
    double                      m_potentialEnergy   = 0;
    class Integrator*           m_integrator        = nullptr;
    class Potential*            m_potential         = nullptr;
    class InitialCondition*     m_initialCondition  = nullptr;
    std::ofstream               m_outFile;
    std::vector<Particle*>      m_particles;
    double                      m_totalMomentum     =0;
    vec3                        m_vecMomentum       =vec3(0,0,0);

public:
    System() {}
    void computeForces          ();
    void resetAllForces         ();
    void setPotential           (class Potential* potential);
    void setIntegrator          (class Integrator* integrator);
    void setInitialCondition    (class InitialCondition* initialCondition);
    void setDt                  (double dt);
    void integrate              (int numberOfSteps);
    void integratePerihelionAngle (int numberOfSteps);
    void addParticle            (Particle* p);
    void printIntegrateInfo     (int stepNumber);
    void removeLinearMomentum   ();
    void setFileWriting         (bool writeToFile);
    void writePositionsToFile   ();
    void closeOutFile           ();
    void computeKineticEnergy   ();
    void computeTotalMomentum   ();
    void computePotentialEnergy ();
    void computeMassCenter       ();
};

