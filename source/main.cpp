#include "UI.hpp"
#include "Field.hpp"
#include "ShipManager.hpp"
#include "Player.hpp"
#include "AbilityManager.hpp"

#include <iostream>
#include <vector>



int main(){
    std::srand(std::time(nullptr)); 
    
    UI ui;
    auto field = new Field(10, 10);
    auto manager = new ShipManager(4, std::vector<int>({4, 3, 2, 1}));

    Factory* factory = new Factory;
    AbilityManager abilitymanager = AbilityManager(factory);
    
    auto ships = manager->getShips();
    field->PlaceShip(ships[0], 'A'-'A', 1, true);
    field->PlaceShip(ships[1], 'C'-'A', 2, false);
    field->PlaceShip(ships[2], 'H'-'A', 3, true);
    field->PlaceShip(ships[3], 'I'-'A', 7, false);
   
    Player* player = new Player(field, manager); 

    system("clear");
    ui.drawField(player->GetFieldCells(), false);
    ui.drawField(player->GetFieldCells(), true);

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 7; j++) {
            player->HandleAttack(i, j);
        }
    }

    Ability* a = new Scanner;
    Context ctx;
    ctx.SetParam("x", "8");
    ctx.SetParam("y", "7");
    auto res = a->Apply(player, ctx);
    std::cout<<res.Message()<<std::endl;

    a = new DoubleDamage;
    a->Apply(player, ctx);
    res = player->HandleAttack(8, 7);
    std::cout<<res.Message()<<std::endl;
    for (int i = 0; i < res.ShipsDestroyed(); i++) {
        abilitymanager.addRandom();
    }
    res = player->HandleAttack(8, 7);
    std::cout<<res.Message()<<std::endl;
    
    ui.drawField(player->GetFieldCells(), false);
    ui.drawField(player->GetFieldCells(), true); 
    
    for (int i = 0; i < 4; i++) {
        std::cout << abilitymanager.previewNextAbility() << std::endl;
        abilitymanager.pop();
    }

    delete player;
    std::cout << "------------Game over!------------" << std::endl; 

    return 0;
}

