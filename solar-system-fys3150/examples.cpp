#include "examples.h"
#include "system.h"
#include "particle.h"
#include "Integrators/euler.h"
#include "Integrators/velocityverlet.h"
#include "Potentials/newtoniangravity.h"
#include "Potentials/newtonianrelativisticgravity.h"
#include "InitialConditions/twobody.h"
#include "InitialConditions/threebody.h"
#include "InitialConditions/solarsystem.h"
#include "InitialConditions/perihelionprecession.h"
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

    twoBodySystem->integrate            (1000000);


}

void Examples::twoBodyProblemVelVerlet() {
    System* twoBodySystem = new System();
    twoBodySystem->setIntegrator        (new VelocityVerlet(twoBodySystem));
    twoBodySystem->setPotential         (new NewtonianGravity(G));
    twoBodySystem->setInitialCondition  (new TwoBody());
    twoBodySystem->setFileWriting       (true);
    twoBodySystem->integrate            (1000000);
}

void Examples::threeBodyProblemOriginSun() {
    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator         (new VelocityVerlet(threeBodySystem));
    threeBodySystem->setPotential          (new NewtonianGravity(G));
    threeBodySystem->setInitialCondition   (new ThreeBody());
    threeBodySystem->setFileWriting        (true);

    threeBodySystem->integrate             (30000);

}


void Examples::threeBodyProblemCenterOfMass() {
    System* threeBodySystem = new System();
    threeBodySystem->setIntegrator         (new VelocityVerlet(threeBodySystem));
    threeBodySystem->setPotential          (new NewtonianGravity(G));
    threeBodySystem->setInitialCondition   (new ThreeBody());
    threeBodySystem->setFileWriting        (true);
    threeBodySystem->removeLinearMomentum  ();
    threeBodySystem->integrate             (3000000);
}

void Examples::manyBodyProblem() {
    System* manyBodySystem = new System();
    manyBodySystem->setIntegrator         (new VelocityVerlet(manyBodySystem));
    manyBodySystem->setPotential          (new NewtonianGravity(G));
    manyBodySystem->setInitialCondition   (new SolarSystem());
    manyBodySystem->setFileWriting        (true);
    manyBodySystem->removeLinearMomentum  ();
    manyBodySystem->integrate             (100000);
}

void Examples::perihelionPrecessionProblem() {
    System* perihelionPrecessionSystem = new System();
    perihelionPrecessionSystem->setIntegrator               (new VelocityVerlet(perihelionPrecessionSystem));
    perihelionPrecessionSystem->setPotential                (new NewtonianRelativisticGravity(G));
    perihelionPrecessionSystem->setInitialCondition         (new PerihelionPrecession());
    perihelionPrecessionSystem->setFileWriting              (true);
    perihelionPrecessionSystem->integratePerihelionAngle    (10e6);
}

