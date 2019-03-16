//
// Created by alex on 2/9/19.
//

#ifndef ECE30862_MAP_H
#define ECE30862_MAP_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

#include "rapidxml.hpp"
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include "Trigger.h"

class Map {
private:
    std::unordered_map<std::string, std::shared_ptr<Item>> items;
    std::unordered_map<std::string, std::shared_ptr<Container>> containers;
    std::unordered_map<std::string, std::shared_ptr<Creature>> creatures;
    std::unordered_map<std::string, std::shared_ptr<Room>> rooms;


public:
    Map(std::unordered_map<std::string, std::vector<rapidxml::xml_node<>*>>& elements);
    virtual ~Map();

    void addRoom(rapidxml::xml_node<> *root);
    void addItem(rapidxml::xml_node<> *root);
    void addContainer(rapidxml::xml_node<> *root);
    void addCreature(rapidxml::xml_node<> *root);

    void print();
};


#endif //ECE30862_MAP_H
