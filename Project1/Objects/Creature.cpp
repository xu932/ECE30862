//
// Created by alex on 2/9/19.
//

#include "../Headers/Creature.h"

Creature::Creature() : attack(nullptr) {}
Creature::~Creature() {
    if (attack != nullptr)  delete attack;
}

void Creature::addInfo(std::string name, rapidxml::xml_node<>* node) {
    if (name == "vulnerability") {
        vulner.insert(std::string(node->value()));
    } else if (name == "attack") {
        attack = new Attack(node);
    } else if (name == "trigger") {
        std::shared_ptr<Trigger> trig = std::make_shared<Trigger>(node);
        triggers.push_back(trig);
    } else {
        attr[name] = std::string(node->value());
    }
}

std::string Creature::getInfo(std::string key) {
    if (attr.find(key) != attr.end())    return attr["name"];
    return "[ERROR]";
}

void Creature::print() {
    std::cout << attr["name"] << ": ";
    attack->print();
}