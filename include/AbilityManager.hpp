#ifndef ABILITYMANAGER_HPP
#define ABILITYMANAGER_HPP

#include <iostream>
#include <random>
#include <queue>

#include "Abilities.hpp"
#include "AbilityFactory.hpp"


class AbilityManager {
public:
    AbilityManager(AbilityFactory* factory);

    std::string previewNextAbility() const;
    void addRandom();
    void addAbility(AbilityType);
    Ability* pop();

private:
    AbilityFactory* factory;
    std::queue<Ability*> abilities;
};

#endif