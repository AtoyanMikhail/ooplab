#include "Player.hpp"

Player::Player(ShipManager* sM, Field* f, UI* ui){
    shipManager = sM;
    enemyField = f;
    ui = ui;
}

Player::~Player(){}

ShipManager* Player::getShipManager() const {
    return shipManager;
}

Field* Player::getEnemyField() const {
    return enemyField;
}

UI* Player::getUI() const {
    return ui;
}