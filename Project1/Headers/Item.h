//
// Created by alex on 2/9/19.
//

/*
 * Item – may contain name, status, description, writing, status, turn on, and trigger[ ]. If an item has a “turn on”
 * element and the “turn on” command is issued by the user, action elements in ‘turn on’ are to be executed if any of
 * the given conditions are met.
 */





#ifndef ECE30862_ITEM_H
#define ECE30862_ITEM_H

#include <string>
#include <unordered_map>

#include "Trigger.h"

enum State {ON, OFF, NA};

class Item {
private:
    std::unordered_map<std::string, std::string> attr;
    std::unordered_map<std::string, std::string> turn_on;
    State state;

public:
    Item();
    ~Item();

    void addInfo(std::string key, std::string value);
    void initTurnOn(std::string print, std::string action);

    std::string getInfo(std::string key);
};


#endif //ECE30862_ITEM_H
