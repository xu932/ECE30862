//
// Created by alex on 2/10/19.
//

#include "../Headers/Condition.h"

Condition::Condition(std::unordered_map<std::string, std::string> &map) {
    object = map["object"];

    if (map.find("has") == map.end()) {
        type = SHORT;
        status = map["status"];
    } else {
        type = LONG;
        owner = map["owner"];
        has = map["has"] == "yes" ? true : false;
    }
}

Condition::~Condition() {}
