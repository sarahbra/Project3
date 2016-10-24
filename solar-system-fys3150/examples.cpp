#include "examples.h"
#include "system.h"
#include "particle.h"
#include "Integrators/euler.h"
#include "Integrators/velocityverlet.h"
#include "Potentials/newtoniangravity.h"
#include "InitialConditions/twobody.h"
#include "InitialConditions/threebody.h"
#include "InitialConditions/solarsystem.h"
#include <iostream>
#include <cmath>

double pi = std::atan(1.0)*4;
double G = 4*pi*pi;

void Examples::twoBodyProblemEuler() {

    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator        (new Euler(twoBodySystem));
    twoBodySystem->setPotential         (new NewtonianGravity(G));
    twoBodySystem->setInitialCondition  (new TwoBody());
    twoBodySystem->setFileWriting       (true);
<<<<<<< HEAD
    twoBodySystem->removeLinearMomentum ();
    twoBodySystem->integrate            (300000);
=======
    twoBodySystem->integrate            (100000);
>>>>>>> 7e61dc4c701a1e6dd8b029abfb61325ee1d915ad

}

void Examples::twoBodyProblemVelVerlet() {
    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator        (new VelocityVerlet(twoBodySystem));
    twoBodySystem->setPotential         (new NewtonianGravity(G));
    twoBodySystem->setInitialCondition  (new TwoBody());
    twoBodySystem->setFileWriting       (true);
    twoBodySystem->integrate            (100000);
}

void Examples::threeBodyProblemOriginSun() {
    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator         (new VelocityVerlet(threeBodySystem));
    threeBodySystem->setPotential          (new NewtonianGravity(G));
    threeBodySystem->setInitialCondition   (new ThreeBody());
    threeBodySystem->setFileWriting        (true);
<<<<<<< HEAD
    threeBodySystem->removeLinearMomentum  ();
    threeBodySystem->integrate             (300000);
=======
    threeBodySystem->integrate             (150000);

}
>>>>>>> 7e61dc4c701a1e6dd8b029abfb61325ee1d915ad

void Examples::threeBodyProblemCenterOfMass() {
    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator         (new VelocityVerlet(threeBodySystem));
    threeBodySystem->setPotential          (new NewtonianGravity(G));
    threeBodySystem->setInitialCondition   (new ThreeBody());
    threeBodySystem->setFileWriting        (true);
    threeBodySystem->removeLinearMomentum  ();
    threeBodySystem->integrate             (150000);
}

void Examples::manyBodyProblem() {
    System* manyBodySystem = new System();
    manyBodySystem->setIntegrator         (new VelocityVerlet(manyBodySystem));
    manyBodySystem->setPotential          (new NewtonianGravity(G));
    manyBodySystem->setInitialCondition   (new SolarSystem());
    manyBodySystem->setFileWriting        (true);
    manyBodySystem->removeLinearMomentum  ();
    manyBodySystem->integrate             (300000);
}

