//
// Created by alex on 2/9/19.
//

#include "../Headers/Item.h"

Item::Item() : state(NA){}

Item::~Item() {}

void Item::addInfo(std::string key, std::string value) {
    attr[key] = value;
}

void Item::initTurnOn(std::string print, std::string action) {
    state = OFF;
    turn_on["print"] = print;
    turn_on["action"] = action;
}

std::string Item::getInfo(std::string key) {
    if (attr.find(key) != attr.end())    return attr["name"];
    return "[ERROR]";
}

