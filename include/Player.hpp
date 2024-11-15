#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <algorithm>
#include <random>

#include "Field.hpp"

#include "ShipManager.hpp"
#include "Result.hpp"

class Player{
public:
    Player(Field* f, ShipManager* sm) : field(f), shipManager(sm), TakeDoubleDamage(false){}
    ~Player() {delete shipManager; delete field;}
    
    std::vector<std::vector<FieldCell>> GetFieldCells();
    
    std::vector<Ship*> GetShips();
    Result HandleAttack(int x, int y) noexcept;
    bool TakeDoubleDamage;
private:
    Field* field;
    ShipManager* shipManager;
};

#endif