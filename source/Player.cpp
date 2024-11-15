#include "Player.hpp"

std::vector<std::vector<FieldCell>> Player::GetFieldCells() {
    return field->getCells();
};


std::vector<Ship*> Player::GetShips() {
    return shipManager->getShips();
};

Result Player::HandleAttack(int x, int y) noexcept {
    std::string message;
    int aliveShips;
    int updatedLiveShips;

    try {
        aliveShips = shipManager->countAliveShips();
        uint8_t damage = 1;
        if (TakeDoubleDamage) {
            damage = 2;
            TakeDoubleDamage = false;
        }
        message = field->attackCell(x, y, damage);
        updatedLiveShips = shipManager->countAliveShips();
    } catch (std::exception& e) {
        return Result{e.what(), false, false, false};
    }

    return Result{message, true, shipManager->countAliveShips()==0, aliveShips - updatedLiveShips};
};