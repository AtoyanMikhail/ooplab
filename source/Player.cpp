#include "Player.hpp"

Field* Player::GetField() {
    return field;
};

ShipManager* Player::GetShipManager() {
    return shipManager;
};

Result Player::HandleAttack(int x, int y) {
    try {
        int aliveShips = shipManager->countAliveShips();
        std::string message = field->attackCell(x, y);
        int updatedLiveShips = shipManager->countAliveShips();
        return Result{message, true, shipManager->countAliveShips()==0, aliveShips - updatedLiveShips};
    } catch (std::exception& e) {
        return Result{e.what(), false, false, false};
    }
};