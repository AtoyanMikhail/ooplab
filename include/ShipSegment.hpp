#ifndef SHIPSEGMENT_HPP
#define SHIPSEGMENT_HPP

#include <cstdint>
#include <Exceptions.hpp>

class ShipSegment{
public:
    explicit ShipSegment();
    ~ShipSegment();
    void takeDamage(uint8_t damage);
    bool isDestroyed();
    bool isDamaged();

private:
    uint8_t HP; 
    bool DamageTaken = false;
};

#endif