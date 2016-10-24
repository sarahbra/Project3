#include "system.h"
#include "Integrators/integrator.h"
#include "Potentials/potential.h"
#include "InitialConditions/initialcondition.h"
#include "particle.h"
#include "time.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;


void System::computeForces() {
    //resetting forces and potential energy before calculating new forces
    resetAllForces();
    m_potential->resetPotentialEnergy();

    for (int i=0; i<m_numberOfParticles; i++) {
        for (int j=i+1; j<m_numberOfParticles; j++) {
            Particle *a = m_particles.at(i);
            Particle *b = m_particles.at(j);
            m_potential->computeForces(*a, *b);
        }
    }
}

void System::resetAllForces() {
    for (int i=0; i<m_numberOfParticles; i++) {
        m_particles.at(i)->resetForces();
        m_particles.at(i)->resetPotentialEnergy();
    }
}


void System::setPotential(Potential* potential) {
    m_potential = potential;
}

void System::setIntegrator(Integrator* integrator) {
    m_integrator = integrator;
}

void System::setInitialCondition(InitialCondition* initialCondition) {
    m_initialCondition = initialCondition;
    m_initialCondition->setupParticles(*this);
}

void System::setDt(double dt) {
    m_integrator->setDt(dt);
}

void System::integrate(int numberOfSteps) {
    clock_t start, finish;
    start = clock();

    m_integrateSteps = numberOfSteps;
    printIntegrateInfo(0);
    removeLinearMomentum();
    for (int i=1; i<numberOfSteps+1; i++) {
        m_integrator->integrateOneStep(m_particles);
        printIntegrateInfo(i);
        writePositionsToFile();
    }
    finish =clock();
    double t = ((finish-start));
    double seconds = t/CLOCKS_PER_SEC;
    cout << "Time computations took:    " << seconds <<"s"<< endl;
    closeOutFile();
}

void System::addParticle(Particle* p) {
    m_particles.push_back(p);
    m_numberOfParticles += 1;
}

void System::computeKineticEnergy() {
    m_kineticEnergy = 0;

    for(int i = 0; i<m_numberOfParticles; i++) {
        Particle *p = m_particles.at(i);
        double v_squared = p->velocitySquared();
        m_kineticEnergy += (v_squared *p->getMass());
    }
}

void System::integratePerihelionAngle(int numberOfSteps) {
    m_integrateSteps = numberOfSteps;
    printIntegrateInfo(0);
    removeLinearMomentum();
    for (int i=1; i<numberOfSteps+1; i++) {
        m_integrator->integrateOneStep(m_particles);
        vec3 temp = m_particles[1]->getPosition();
        temp.operator -=(m_particles[0]->getPosition());
        double rCurrent = temp.length();
        if ( rCurrent > m_rPrevious && m_rPrevious < m_rPreviousPrevious ) {

                // If we are perihelion, print *previous* angle (in radians) to terminal.
                double x = m_rPreviousPosition[0];
                double y = m_rPreviousPosition[1];
                m_angle = atan2(y,x);
        printIntegrateInfo(i);
        writePositionsToFile();
    }
    m_rPreviousPrevious = m_rPrevious;
    m_rPrevious = rCurrent;
    m_rPreviousPosition = m_particles[1]->getPosition().operator -= (m_particles[0]->getPosition());
     closeOutFile();
    }

}

void System::computePotentialEnergy() {
    m_potentialEnergy = 0;
    for (int i=0; i<m_numberOfParticles; i++) {
        Particle *p = m_particles.at(i);
        m_potentialEnergy += p->getPotentialEnergy();
    }

}

void System::printIntegrateInfo(int stepNumber) {
    if (stepNumber == 0) {
        cout << endl
             << " STARTING INTEGRATION "    << endl
             << "-------------------------" << endl
             << "  o Number of steps:     " << m_integrateSteps << endl
             << "  o Time step, dt:       " << m_integrator->getDt() << endl
             << "  o Initial condition:   " << m_initialCondition->getName() << endl
             << "  o Number of particles: " << m_particles.size() << endl
             << "  o Potential in use:    " << m_potential->getName() << endl
             << "  o Integrator in use:   " << m_integrator->getName() << endl
             << endl;
    } else if (stepNumber % 10000 == 0) {
        computeKineticEnergy();
        computePotentialEnergy();
        computeTotalMomentum();
        m_totalEnergy       = m_kineticEnergy + m_potentialEnergy;
        printf("Step: %5d   E =%8.5f   Ek =%8.5f   Ep =%8.5f   M=%8.5f\n"   ,
            stepNumber, m_totalEnergy, m_kineticEnergy, m_potentialEnergy, m_totalMomentum);
        fflush(stdout);
    }
}

void System::removeLinearMomentum() { 
    computeTotalMomentum();
    m_particles.at(0)->getVelocity().operator -=(m_vecMomentum);
}

void System::computeTotalMomentum()  {
    m_vecMomentum = vec3(0,0,0);
    m_totalMomentum = 0;
    vec3 v_temp = vec3(0,0,0);
    for (int i = 0; i<m_numberOfParticles; i++)  {
        Particle *p = m_particles.at(i);
        double m = p->getMass();
        v_temp = p->getVelocity();

        m_vecMomentum.operator += (v_temp.operator *=(m));
    }
    m_totalMomentum = m_vecMomentum.length();
}

void System::setFileWriting(bool writeToFile) {
    m_writeToFile = writeToFile;
}

void System::writePositionsToFile() {
    if (m_outFileOpen == false) {
        m_outFile.open("positions.dat", std::ios::out);
        m_outFileOpen = true;
    }

    if (m_angle!=0.0) {
        m_outFile << m_angle;
    } else {

        double x[m_numberOfParticles];
        double y[m_numberOfParticles];
        for (int i = 0; i<m_numberOfParticles; i++) {
            Particle *p = m_particles.at(i);
            vec3 r = p->getPosition();
            x[i] = r[0];
            y[i] = r[1];
            if (i<(m_numberOfParticles-1)) {
                m_outFile << x[i] <<  "," << y[i]<< ",";
            } else {
                m_outFile << x[i] << "," << y[i];
            }
        }
    } m_outFile << endl;
}

void System::closeOutFile() {
    if (m_writeToFile == true) {
        m_outFile.close();
        m_outFileOpen = false;
    }
}






