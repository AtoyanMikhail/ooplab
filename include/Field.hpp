#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>
#include "FieldCell.hpp"
#include "Ship.hpp"

class Field {
public:
    Field(int height, int width);
    ~Field();
    std::vector<std::vector<FieldCell>> getCells();
    std::string attackCell(int x, int y);
    // Returns true if ship was placed successfully, false otherwise
    bool PlaceShip(Ship* ship, int horizontalPos, int verticalPosition, bool vertical);

private:
    std::vector<std::vector<FieldCell*>> field;
};

#endif