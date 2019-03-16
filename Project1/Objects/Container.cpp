//
// Created by alex on 2/9/19.
//

#include "../Headers/Container.h"


Container::Container() {}
Container::~Container() {}



void Container::addInfo(std::string key, std::string value) {
    attr[key] = value;
}

void Container::addAccepts(std::string item) {
    accepts.insert(item);
}

void Container::addItem(std::string item, std::unordered_map<std::string, std::shared_ptr<Item>>& items) {
    if (items.find(item) != items.end()) {
        this->items[item] = items[item];
    }
}

std::string Container::getInfo(std::string key) {
    if (attr.find(key) != attr.end())    return attr["name"];
    return "[ERROR]";
}

void Container::addTrigger(std::shared_ptr<Trigger> trig) {
    triggers.push_back(trig);
}
