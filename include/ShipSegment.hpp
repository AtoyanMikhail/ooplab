#ifndef SHIPSEGMENT_HPP
#define SHIPSEGMENT_HPP

#include <cstdint>

class ShipSegment{
public:
    explicit ShipSegment();
    ~ShipSegment();
    void takeDamage(uint8_t damage);
    bool isDestroyed();

private:
    uint8_t HP; 
};

#endif