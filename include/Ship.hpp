#ifndef SHIP_HPP
#define SHIP_HPP

#include <vector>
#include <memory>
#include "ShipSegment.hpp"

class Ship{
public:
    Ship(int size);
    ~Ship();

    bool isDestroyed() const;
    int getSize() const;
    std::vector<ShipSegment*> getSegments() const;
private:
    std::vector<ShipSegment*> segments;
    uint8_t size;
};

#endif