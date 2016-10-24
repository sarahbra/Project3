#include "examples.h"
#include "system.h"
#include "particle.h"
#include "Integrators/euler.h"
#include "Integrators/velocityverlet.h"
#include "Potentials/newtoniangravity.h"
#include "InitialConditions/twobody.h"
#include "InitialConditions/threebody.h"
#include <iostream>
#include <cmath>

double pi = std::atan(1.0)*4;
double G = 4*pi*pi;

void Examples::twoBodyProblem() {

    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator        (new Euler(twoBodySystem));
    twoBodySystem->setPotential         (new NewtonianGravity(G));
    twoBodySystem->setInitialCondition  (new TwoBody());
    twoBodySystem->setFileWriting       (true);
    twoBodySystem->removeLinearMomentum ();
    twoBodySystem->integrate            (100000);

}
void Examples::threeBodyProblem() {
    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator         (new VelocityVerlet(threeBodySystem));
    threeBodySystem->setPotential          (new NewtonianGravity(G));
    threeBodySystem->setInitialCondition   (new ThreeBody());
    threeBodySystem->setFileWriting        (true);
    threeBodySystem->removeLinearMomentum  ();
    threeBodySystem->integrate             (20000);

}

