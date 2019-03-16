//
// Created by alex on 3/16/19.
//

#include "../Headers/Player.h"

std::ostream& operator<<(std::ostream& os, Player* player) {
    os << "Inventory: ";
    if (player->inventory.size() == 0) {
        os << "empty";
    }
    else {
        std::vector<std::string> temp;
        for (auto i : player->inventory)
            temp.push_back(i.second->getInfo("name"));
        os << temp[0];
        for (unsigned int i = 1; i < temp.size(); i++)
            os << ", " << temp[i];
    }
    return os;
}




