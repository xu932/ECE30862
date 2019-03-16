//
// Created by alex on 2/9/19.
//

#ifndef ECE30862_ROOM_H
#define ECE30862_ROOM_H

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

#include "rapidxml.hpp"
#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include "Trigger.h"

class Room {
private:
    std::unordered_map<std::string, std::string> attr;

    std::unordered_map<std::string, std::weak_ptr<Item>> items;
    std::unordered_map<std::string, std::weak_ptr<Container>> containers;
    std::unordered_map<std::string, std::weak_ptr<Creature>> creatures;
    std::unordered_map<std::string, std::string> borders;

    std::vector<std::shared_ptr<Trigger>> triggers;


public:
    Room();
    virtual ~Room();

    void addInfo(std::string key, std::string value);
    void addBorder(const rapidxml::xml_node<>* node);
    void addItem(std::string name, std::weak_ptr<Item> item);
    void addContainer(std::string name, std::weak_ptr<Container> container);
    void addCreature(std::string name, std::weak_ptr<Creature> creature);
    void addTrigger(std::shared_ptr<Trigger> trig);

    std::string getInfo(std::string key);
};


#endif //ECE30862_ROOM_H
