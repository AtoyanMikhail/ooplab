#include "Abilities.hpp"

Result DoubleDamage::Apply(Player* player, Context ctx) {
    player->TakeDoubleDamage = true;
    return Result{"Double damage applied", true, false, 0};
};

Result Scanner::Apply(Player* player, Context ctx) {
    try {
        int x = std::stoi(ctx.GetParam("x"));
        int y = std::stoi(ctx.GetParam("y"));

        for (int i = x; i < x + 1; i++) {
            for (int j = y; j < y + 1; j++) {
                if (player->GetField()->getCells()[i][j].getStatus() != CellStatus::Water) {
                    return Result{"Scanner detected a ship", true, false, 0};
                }
            }
        }
    } catch (const std::exception &e) {
        return Result{"Invalid scanner coordinates", false, false, 0};
    }
};

Result Bombardment::Apply(Player* player, Context ctx) {
    std::vector<Ship*> ships = player->GetShipManager()->getShips();
    std::vector<Ship*> aliveShips;
    std::copy_if(ships.begin(), ships.end(), std::back_inserter(aliveShips), [](Ship* ship) {return ship->isDestroyed();});
    
    std::vector<ShipSegment*> randomSegments = aliveShips[rand()%aliveShips.size()]->getSegments();
    std::vector<ShipSegment*> randomUndestroyedSegments;
    std::copy_if(randomSegments.begin(), randomSegments.end(), std::back_inserter(randomUndestroyedSegments), [](ShipSegment* segment) { return!segment->isDestroyed();});

    int aliveShipsCnt = player->GetShipManager()->countAliveShips();
    ShipSegment* segment = randomUndestroyedSegments[rand()%randomSegments.size()];
    segment->takeDamage(1);
    int aliveShipsAfterBombardmentCnt = player->GetShipManager()->countAliveShips();

    return Result("Segment hit!", true, player->GetShipManager()->countAliveShips()==0, aliveShipsCnt-aliveShipsAfterBombardmentCnt);
}