//
// Created by alex on 2/9/19.
//

#ifndef ECE30862_CREATURE_H
#define ECE30862_CREATURE_H

#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

#include "rapidxml.hpp"
#include "Attack.h"

class Creature {
private:
    std::unordered_map<std::string, std::string> attr;
    std::unordered_set<std::string> vulner;
    Attack *attack;

public:
    Creature();
    virtual ~Creature();

    void addInfo(std::string name, rapidxml::xml_node<>* node);

    std::string getInfo(std::string key);

    void print();
};


#endif //ECE30862_CREATURE_H
