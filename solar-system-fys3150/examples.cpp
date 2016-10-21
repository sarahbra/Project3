#include "examples.h"
#include "system.h"
#include "particle.h"
#include "Integrators/eulercromer.h"
#include "Integrators/velocityverlet.h"
#include "Potentials/newtoniangravity.h"
#include "Potentials/nopotential.h"
#include "InitialConditions/twobody.h"
#include "InitialConditions/threebody.h"
#include <iostream>
#include <cmath>

double pi = std::atan(1)*4;
double G = (4*pi*pi)/(2e30);

void Examples::twoBodyProblem() {

    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator        (new VelocityVerlet(twoBodySystem));
    twoBodySystem->setPotential         (new NewtonianGravity(G));
    twoBodySystem->setInitialCondition  (new TwoBody());
    twoBodySystem->setFileWriting       (true);
    twoBodySystem->removeLinearMomentum ();
    twoBodySystem->integrate            (200000);

}

// void Examples::threeBodyProblem() {
//    System* threeBodySystem = new System();
//    threeBodySystem->setIntegrator         (new VelocityVerlet(threeBodySystem));
//    threeBodySystem->setPotential          (new NewtonianGravity(G));
//    threeBodySystem->setInitialCondition   (new ThreeBody());
//    threeBodySystem->setFileWriting        (true);
//    threeBodySystem->removeLinearMomentum  ();
//    threeBodySystem->integrate             (200000);

    /*
     * This is where you should set up a three-body problem, using the
     * InitialCondition::ThreeBody class as System's InitialCondition.
     *
     * You should start by considering the two-body case in
     * Examples::twoBodyProblem, before continuing with this more complicated
     * case.
     */
// }
