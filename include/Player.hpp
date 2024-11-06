#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ShipManager.hpp"
#include "UI.hpp"
#include "Field.hpp"
#include "AbilityManager.hpp"

class Player {
public:
    Player(ShipManager* sM, Field* f, UI* ui);
    ShipManager* getShipManager() const;
    Field* getEnemyField() const;
    UI* getUI() const;
    ~Player();
private:
    ShipManager* shipManager;
    Field* enemyField;
    UI* ui;
};

#endif