// #ifndef ABILITYMANAGER_HPP
// #define ABILITYMANAGER_HPP

// #include <iostream>
// #include <random>
// #include <queue>

// #include "Exceptions.hpp"
// #include "Abilities.hpp"

// class AbilityManager {
// public:
//     AbilityManager(std::vector<Ability> abilities) {
//         for (auto& ability : abilities){
//             push(ability);
//         }
//     }

//     void push(Ability ability) {
//         abilities.push(ability);
//     }

//     Ability pop() {
//         if (abilities.empty()) {
//             throw NoAbilitiesException(); // Исключение, если нет способностей
//         }
//         Ability ability = abilities.front();
//         abilities.pop();
//         return ability;
//     }

// private:
//     std::queue<Ability> abilities;
// };

// #endif