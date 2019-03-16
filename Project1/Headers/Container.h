//
// Created by alex on 2/9/19.
//

#ifndef ECE30862_CONTAINER_H
#define ECE30862_CONTAINER_H

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <memory>

#include "Item.h"
#include "Trigger.h"

class Container {
private:
    std::unordered_map<std::string, std::string> attr;
    std::unordered_set<std::string> accepts;
    std::unordered_map<std::string, std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<Trigger>> triggers;

public:
    Container();
    ~Container();

    void addInfo(std::string key, std::string value);
    void addItem(std::string item, std::unordered_map<std::string, std::shared_ptr<Item>>& items);
    void addAccepts(std::string item);
    void addTrigger(std::shared_ptr<Trigger> trig);

    std::string getInfo(std::string key);

};


#endif //ECE30862_CONTAINER_H
