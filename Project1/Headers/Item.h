//
// Created by alex on 2/9/19.
//

#ifndef ECE30862_ITEM_H
#define ECE30862_ITEM_H

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

#include "Trigger.h"

class Item {
private:
    std::unordered_map<std::string, std::string> attr;
    std::unordered_map<std::string, std::string> turn_on;
    std::vector<std::shared_ptr<Trigger>> triggers;

public:
    Item();
    ~Item();

    void addInfo(std::string key, std::string value);
    void initTurnOn(std::string print, std::string action);
    void addTrigger(std::shared_ptr<Trigger> trig);

    std::string getInfo(std::string key);
};


#endif //ECE30862_ITEM_H
