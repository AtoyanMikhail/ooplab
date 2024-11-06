#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include "FieldCell.hpp"

class UI{
public:
    void drawField(std::vector<std::vector<FieldCell>> field, bool isEnemyField);
};

#endif