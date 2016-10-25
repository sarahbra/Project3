
#pragma once
#include "../InitialConditions/initialcondition.h"
#include <string>


class PerihelionPrecession : public InitialCondition {
public:
    PerihelionPrecession() {}
    void setupParticles(class System& system);
    std::string getName();
};
