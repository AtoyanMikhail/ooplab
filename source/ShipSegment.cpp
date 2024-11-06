#include "ShipSegment.hpp"

ShipSegment::ShipSegment(): HP(2) {};

ShipSegment::~ShipSegment() {}

void ShipSegment::takeDamage(uint8_t damage) { 
    if (HP-damage>=0) {
        HP = HP-damage;
    } else {
        HP = 0;
    }
}

bool ShipSegment::isDestroyed() {
    return HP == 0;
}