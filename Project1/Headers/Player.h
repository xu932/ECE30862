//
// Created by alex on 3/16/19.
//

#ifndef PROJECT1_PLAYER_H
#define PROJECT1_PLAYER_H

#include <string>
#include <unordered_map>
#include <memory>
#include <iostream>
#include <vector>

#include "Item.h"

class Player {
public:
    std::unordered_map<std::string, std::shared_ptr<Item>> inventory;

    friend std::ostream& operator<<(std::ostream& os, Player *player);
};



#endif //PROJECT1_PLAYER_H
