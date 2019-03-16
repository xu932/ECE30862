//
// Created by alex on 2/9/19.
//

#ifndef ECE30862_TRIGGER_H
#define ECE30862_TRIGGER_H

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

#include "rapidxml.hpp"
#include "Condition.h"



class Trigger {
public:
    int type;   // 1 - permanent
                // 2 - single (default)
    bool hasTriggered;
    std::vector<std::shared_ptr<Condition>> conditions;
    std::unordered_map<std::string, std::string> attr;
    std::vector<std::string> actions;
    std::vector<std::string> prints;

    Trigger(rapidxml::xml_node<> *root);
    virtual ~Trigger();

    std::string getInfo(std::string key);

};


#endif //ECE30862_TRIGGER_H
