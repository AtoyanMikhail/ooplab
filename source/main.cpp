#include "UI.hpp"
#include "Field.hpp"
#include "ShipManager.hpp"
#include <iostream>
#include <vector>

int main(){
    UI ui;
    auto field = new Field(10, 10);
    auto manager = new ShipManager(4, std::vector<int>({4, 3, 2, 1}));
    
    auto ships = manager->getShips();
    field->PlaceShip(ships[0], 'A'-'A', 1, true);
    field->PlaceShip(ships[1], 'C'-'A', 2, false);
    field->PlaceShip(ships[2], 'H'-'A', 3, true);
    field->PlaceShip(ships[3], 'I'-'A', 7, false);
   
    system("clear");

    ui.drawField(field->getCells(), false);
    ui.drawField(field->getCells(), true);

    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++) {
            field->attackCell(i, j);
        }
    }

    std::cout << field->attackCell('I'-'A', 7) << std::endl;
    std::cout << field->attackCell('I'-'A', 7) << std::endl;
    std::cout << manager->update() << std::endl;

    ui.drawField(field->getCells(), false);
    ui.drawField(field->getCells(), true);

    delete field;
    delete manager;
    std::cout << "Game over!" << std::endl; 
    return 0;
}