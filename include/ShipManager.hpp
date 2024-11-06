#include <cstdarg>
#include <string>

#include "Ship.hpp"

class ShipManager{
public:
    ShipManager(int amount, std::vector<int> sizes);
    ~ShipManager();
    ShipManager(const ShipManager& other);
    ShipManager(ShipManager&& other) noexcept;

    ShipManager& operator=(const ShipManager& other);
    ShipManager& operator=(ShipManager&& other) noexcept;
    std::vector<Ship*> getShips() const;
    int countAliveShips() const;
    std::string update();
private:
    std::vector<Ship*> ships;
    int AliveCnt;
};