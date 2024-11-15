#include "AbilityManager.hpp"

AbilityManager::AbilityManager(AbilityFactory* factory) :factory(factory){
    std::vector<Ability*> vec;
    for (int i = 0; i < 3; i++){
        vec.push_back(factory->createAbility(static_cast<AbilityType>(i)));  
    }
    std::random_shuffle(vec.begin(), vec.end());  
    for (Ability* ability : vec) {
        abilities.push(ability);
    }
};

std::string AbilityManager::previewNextAbility() const {
    return abilities.front()->Name();
}

void AbilityManager::addRandom() {
    AbilityType randomAbility = static_cast<AbilityType>(std::rand()%3);
    addAbility(randomAbility);
}

void AbilityManager::addAbility(AbilityType type){
    Ability* newAbility = factory->createAbility(type); 

    abilities.push(newAbility);
};

Ability* AbilityManager::pop() {
    if (!abilities.empty()) {
        Ability* ability = abilities.front();
        abilities.pop();
        return ability;
    }
    throw NoAbilitiesException();
};