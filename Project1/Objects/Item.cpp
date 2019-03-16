//
// Created by alex on 2/9/19.
//

#include "../Headers/Item.h"

Item::Item() {}

Item::~Item() {}

void Item::addInfo(std::string key, std::string value) {
    attr[key] = value;
}

void Item::initTurnOn(std::string print, std::string action) {
    turn_on["print"] = print;
    turn_on["action"] = action;
}

std::string Item::getInfo(std::string key) {
    if (attr.find(key) != attr.end())    return attr["name"];
    return "[ERROR]";
}

void Item::addTrigger(std::shared_ptr<Trigger> trig) {
    triggers.push_back(trig);
}
