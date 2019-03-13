//
// Created by alex on 2/9/19.
//

#ifndef ECE30862_ATTACK_H
#define ECE30862_ATTACK_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>

#include "rapidxml.hpp"
#include "Condition.h"

class Attack {
private:
    std::vector<std::shared_ptr<Condition>> conditions;
    std::vector<std::string> prints;
public:
    Attack(rapidxml::xml_node<>* root);
    virtual ~Attack();

    void print();
};


#endif //ECE30862_ATTACK_H
