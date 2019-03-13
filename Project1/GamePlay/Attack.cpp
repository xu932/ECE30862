//
// Created by alex on 2/9/19.
//

#include "../Headers/Attack.h"

Attack::Attack(rapidxml::xml_node<> *root) {
    rapidxml::xml_node<>* node;
    for (node = root->first_node(); node; node = node->next_sibling()) {
        std::string name(node->name());
        if (name == "condition") {
            std::unordered_map<std::string, std::string> attr;
            rapidxml::xml_node<>* n;
            for (n = node->first_node(); n; n = n->next_sibling())
                attr[std::string(n->name())] = std::string(n->value());

            std::shared_ptr<Condition> cond = std::make_shared<Condition>(attr);
            conditions.push_back(cond);
        } else if (name == "action") {
            // TODO
        } else {
            prints.push_back(std::string(node->value()));
        }
    }
}

Attack::~Attack() {}


void Attack::print() {
    std::cout << prints[0] << std::endl;
}

