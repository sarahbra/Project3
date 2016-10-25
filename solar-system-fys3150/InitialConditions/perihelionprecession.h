<<<<<<< HEAD
=======

>>>>>>> 443e202c5bf2e477b81570fa68dfce523473df78
#pragma once
#include "../InitialConditions/initialcondition.h"
#include <string>

<<<<<<< HEAD
=======

>>>>>>> 443e202c5bf2e477b81570fa68dfce523473df78
class PerihelionPrecession : public InitialCondition {
public:
    PerihelionPrecession() {}
    void setupParticles(class System& system);
    std::string getName();
};
