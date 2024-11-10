#ifndef ABILITIES_HPP
#define ABILITIES_HPP

#include <algorithm>
#include <random>

#include "Player.hpp"
#include "Result.hpp"
#include "Context.hpp"

// Класс-интерфейс для способности
class Ability {
public:
    virtual Result Apply(Player* player, Context ctx) = 0;
};

// Двойной урон
class DoubleDamage : public Ability {
    public:
    Result Apply(Player* player, Context ctx) noexcept;
};

// Сканер
class Scanner : public Ability {
    public:
    Result Apply(Player* player, Context ctx) noexcept;
};

// Обстрел
class Bombardment : public Ability {
    public:
    Result Apply(Player* player, Context ctx) noexcept;
};

#endif