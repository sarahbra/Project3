#include "system.h"
#include "Integrators/integrator.h"
#include "Potentials/potential.h"
#include "InitialConditions/initialcondition.h"
#include "particle.h"
<<<<<<< HEAD

=======
>>>>>>> c40fe2f0d1c42d44589321f448342edafefd7a9d
#include <iostream>
using std::cout;
using std::endl;



void System::computeForces() {
<<<<<<< HEAD
    /*
     * Here you should sum over all particle pairs and compute the forces
     * between each one. This should be done by the Potential::computeForces
     * method which takes pointers to two Particles as input. I.e. the forces
     * between particle i and particle j should be computed by
     *
     *      m_potential->computeForces(m_particles.at(i), m_particles.at(j));
     *
     * Note: It is important that you do not sum over each particle pair more
     * than once. A simple way to ensure this is done is by a double foor loop,
     * one running from i=0...n, and the other running from j=i+1...n. You
     * should convince yourself that this is true before you implement this
     * loop.
     */
    m_potential->computeForces(*m_particles.at(0), *m_particles.at(1));
    resetAllForces();
    m_potential->resetPotentialEnergy();
=======
    for (int i=0; i<m_numberOfParticles; i++) {
        for (int j=i+1; i<m_numberOfParticles; i++) {
            Particle *a = m_particles.at(i);
            Particle *b = m_particles.at(j);
            m_potential->computeForces(*a, *b);
        }
    }
>>>>>>> c40fe2f0d1c42d44589321f448342edafefd7a9d
}

void System::resetAllForces() {
    for (int i=0; i<m_numberOfParticles; i++) {
        m_particles.at(i)->resetForces();
    }
}

void System::setPotential(Potential* potential) {
<<<<<<< HEAD
    std::cout << potential << std::endl;
    m_potential = potential;
=======
    m_potential = potential;
    cout << m_potential << endl;
>>>>>>> c40fe2f0d1c42d44589321f448342edafefd7a9d
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
    m_integrateSteps = numberOfSteps;
    printIntegrateInfo(0);
    for (int i=1; i<numberOfSteps+1; i++) {
        m_integrator->integrateOneStep(m_particles);
        printIntegrateInfo(i);
        writePositionsToFile();
<<<<<<< HEAD
=======
        resetAllForces();
        m_potential->resetPotentialEnergy();
>>>>>>> c40fe2f0d1c42d44589321f448342edafefd7a9d
    }
    closeOutFile();
}

void System::addParticle(Particle* p) {
    m_particles.push_back(p);
    m_numberOfParticles += 1;
}

double System::computeKineticEnergy() {
    /*
     * Here, the kinetic energy of the entire system should be computed. Since
     * this is independent of the potential in use, we place this method
     * directly in the system class.
     *
     * Remember that you can access the mass and velocity of particle i by
     *
     *      m_particles.at(i)->getMass()
     *      m_particles.at(i)->getVelocity()
     *
     * Remember also that the Particle class has a built in method
     * Particle::velocitySquared which can be used here.
     */
    m_kineticEnergy = 0;
<<<<<<< HEAD
=======
    // for(int i = 0; i<m_numberOfParticles; i++) {
    //     vec3 v_squared = m_particles.at(i).getVelocity();
     //   m_kineticEnergy += m_particles.at(i).getMass()*v_squared;
   // }
>>>>>>> c40fe2f0d1c42d44589321f448342edafefd7a9d
    return m_kineticEnergy;
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
    } else if (stepNumber % 1000 == 0) {
        m_kineticEnergy     = computeKineticEnergy();
        m_potentialEnergy   = m_potential->getPotentialEnergy();
        m_totalEnergy       = m_kineticEnergy + m_potentialEnergy;
        printf("Step: %5d    E =%10.5f   Ek =%10.5f    Ep =%10.5f\n",
               stepNumber, m_totalEnergy, m_kineticEnergy, m_potentialEnergy);
        fflush(stdout);
    }
}

void System::removeLinearMomentum() {
    /*
     * Here you should remove the total momentum of the entire system, to
     * ensure the entire system does not drift away during long integration
     * times.
     *
     * Remember that you can access the mass and velocity of particle i by
     *
     *      m_particles.at(i)->getMass();
     *      m_particles.at(i)->getVelocity();
     *
     * Remember also that the vec3-vector class supports the += and -=
     * operators, so you can do
     *
     *      totalMomentum += p->getVelocity() * p->getMass();
     */

    vec3 totalMomentum = vec3(0,0,0);
}

void System::setFileWriting(bool writeToFile) {
    m_writeToFile = writeToFile;
}

void System::writePositionsToFile() {
    if (m_outFileOpen == false) {
        m_outFile.open("positions.dat", std::ios::out);
        m_outFileOpen = true;
    }
    /*
     * This is where you should print the positions of each particle to file.
     * Note that the file, "positions.dat", is already open; it is opened in
     * the above if-test the first time this method is called in
     * System::Integrate.
     *
     * Which format you choose for the data file is up to you.
     */
<<<<<<< HEAD
    m_outFile << "x" << endl;

=======
>>>>>>> c40fe2f0d1c42d44589321f448342edafefd7a9d
}

void System::closeOutFile() {
    if (m_writeToFile == true) {
        m_outFile.close();
        m_outFileOpen = false;
    }
}






