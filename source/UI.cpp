#include "UI.hpp"

const int INDENTATION = 5;

char* colorUserStatus(CellStatus status){
    switch (status) {
        case CellStatus::Water: return "\033[1;34m~\033[0m";
        case CellStatus::ShipPart: return "\033[1;32mS\033[0m";
        case CellStatus::Hit: return "\033[1;33mX\033[0m";
        case CellStatus::Destroyed: return "\033[1;31mX\033[0m";
    }
}

char* colorEnemyStatus(CellStatus status, bool revealed){
    if (!revealed) return "\033[1;34m~\033[0m";
    switch (status) {
        case CellStatus::Water: return "\033[1;31m~\033[0m";
        case CellStatus::ShipPart: return "\033[1;35mS\033[0m";
        case CellStatus::Hit: return "\033[1;33mX\033[0m";
        case CellStatus::Destroyed: return "\033[1;31mX\033[0m";
    }
}

void UI::drawField(std::vector<std::vector<FieldCell>> field, bool isEnemyField) {
    if (isEnemyField) {    
        std::cout << "\033[1;31m" << std::setw(field[0].size() + INDENTATION*2 + 4) << "ENEMY'S FIELD" << "\033[0m\n";
    } else {
        std::cout << "\033[1;32m" << std::setw(field[0].size() + INDENTATION*2 + 2) << "YOUR FIELD" << "\033[0m\n";
    }

    std::cout << "        ";
    char column = 'A';
    for (int i = 0; i < field[0].size();i++) {
        std::cout << column << " ";
        column++;
    } 
    std::cout << std::endl;
    
    
    std::cout << "      +";
    for (int i = 0; i < field[0].size();i++) { 
        std::cout << "——";
    } 
    std::cout << "—+\n";

    int row = 0;
    for (auto vec: field) {     
        std::cout << std::setw(INDENTATION) <<row<< " | ";
        for (auto cell: vec) {
            if (isEnemyField) {
                std::cout << colorEnemyStatus(cell.getStatus(), cell.isRevealed()) << " ";
            } else {
                std::cout << colorUserStatus(cell.getStatus()) << " ";
            }
        }
        std::cout << "|\n";
        row++;
    }

     std::cout << "      +";
    for (int i = 0; i < field[0].size();i++) {
        std::cout << "——";
    } 
    
    std::cout << "—+\n";
}