#ifndef ABILITIES_HPP
#define ABILITIES_HPP

#include "Player.hpp"
#include "Context.hpp"

#include <algorithm>
#include <random>
#include <ctime>

// Класс-интерфейс для способности
class Ability {
public:
    virtual Result Apply(Player* player, Context ctx) = 0;
    virtual std::string Name() const = 0;
};

// Двойной урон
class DoubleDamage : public Ability {
public:
    Result Apply(Player* player, Context ctx) noexcept;
    std::string Name() const {return "Double Damage";};
};

// Сканер
class Scanner : public Ability {
public:
    Result Apply(Player* player, Context ctx) noexcept;
    std::string Name() const {return "Scanner";};
};

// Обстрел
class Bombardment : public Ability {
public:
    Result Apply(Player* player, Context ctx) noexcept;
    std::string Name() const {return "Bombardment";};
};

#endif