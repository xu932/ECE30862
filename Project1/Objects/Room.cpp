//
// Created by alex on 2/9/19.
//

#include "../Headers/Room.h"


Room::Room() {}
Room::~Room() {}

void Room::addInfo(std::string key, std::string value) {
    attr[key] = value;
}

void Room::addBorder(rapidxml::xml_node<> *node) {
    std::string direction = node->first_node("direction")->value();
    std::string name = node->first_node("name")->value();
    borders[direction] = name;
}

void Room::addItem(std::string name, std::weak_ptr <Item> item) {
    items[name] = item;
}

void Room::addContainer(std::string name, std::weak_ptr <Container> container) {
    containers[name] = container;
}

void Room::addCreature(std::string name, std::weak_ptr <Creature> creature) {
    creatures[name] = creature;
}

std::string Room::getInfo(std::string key) {
    if (attr.find(key) == attr.end()) {
        return "[ERROR]";
    } else {
        return attr[key];
    }
}



