//
// Created by alex on 2/9/19.
//

#include "../Headers/Trigger.h"


Trigger::Trigger(rapidxml::xml_node<> *root) : type(2), hasTriggered(false) {
    rapidxml::xml_node<>* node;
    for (node = root->first_node(); node; node = node->next_sibling()) {
        std::string name(node->name());
        if (name == "type") {
            if (std::string(node->value()) == "single")
                type = 1;
        } else if (name == "condition") {
            std::unordered_map<std::string, std::string> attr;
            rapidxml::xml_node<>* n;
            for (n = node->first_node(); n; n = n->next_sibling())
                attr[std::string(n->name())] = std::string(n->value());

            std::shared_ptr<Condition> cond = std::make_shared<Condition>(attr);
            conditions.push_back(cond);
        } else if (name == "action") {
            actions.push_back(std::string(node->value()));
        } else if (name == "print") {
            prints.push_back(std::string(node->value()));
        } else {
            attr[name] = std::string(node->value());
        }
    }
}

Trigger::~Trigger() {}

std::string Trigger::getInfo(std::string key) {
    if (attr.find(key) == attr.end())   return "[ERROR]";
    return attr[key];
}

