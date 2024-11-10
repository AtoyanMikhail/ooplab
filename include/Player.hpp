#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ShipManager.hpp"
#include "Field.hpp"
#include "Abilities.hpp"
#include "Result.hpp"


class Player{
public:
    Player(Field* f, ShipManager* sm) : field(f), shipManager(sm) {}
    ~Player() {delete shipManager; delete field;}
    Field* GetField();
    ShipManager* GetShipManager();
    Result HandleAttack(int x, int y);

    bool TakeDoubleDamage;
private:
    Field* field;
    ShipManager* shipManager;
};

#endif