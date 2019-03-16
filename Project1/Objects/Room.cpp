//
// Created by alex on 2/9/19.
//

#include "../Headers/Room.h"


Room::Room() {}
Room::~Room() {}

void Room::addInfo(std::string key, std::string value) {
    attr[key] = value;
}

void Room::addBorder(const rapidxml::xml_node<> *node) {
    std::string dir = "default";
    std::string rm = "none";
    for (rapidxml::xml_node<> *n = node->first_node(); n; n = n->next_sibling()) {
        std::string name(n->name());
        std::string value(n->value());
        if (name == "direction")    dir = value;
        if (name == "name")         rm = value;
    }

    borders[dir] = rm;
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

void Room::addTrigger(std::shared_ptr<Trigger> trig) {
    triggers.push_back(trig);
}

std::string Room::getInfo(std::string key) {
    if (attr.find(key) == attr.end()) {
        return "[ERROR]";
    } else {
        return attr[key];
    }
}



