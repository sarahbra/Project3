#pragma once
#include "../InitialConditions/initialcondition.h"
#include <string>


class TwoBody : public InitialCondition {
public:
    TwoBody() {}
    void setupParticles(class System& system);
    std::string getName();
};

