#include "FieldCell.hpp"

FieldCell::FieldCell() : status(CellStatus::Water), revealed(false), shipSegment(nullptr) {}


CellStatus FieldCell::getStatus() {
    return status;
}

void FieldCell::reveal() {
    revealed = true;
}

bool FieldCell::isRevealed() {
    return revealed;
}

void FieldCell::attackSegment() {
    revealed = true;
    if (shipSegment == nullptr) {
        return;
    }

    shipSegment->takeDamage(1);
    if (shipSegment->isDestroyed()) {
        status = CellStatus::Destroyed;
    } else {
        status = CellStatus::Hit;
    }
}

bool FieldCell::setShipSegment(ShipSegment* segment) {
    if (shipSegment != nullptr) {
        return false;
    }

    shipSegment = segment;
    status = CellStatus::ShipPart;
    return true;
}
