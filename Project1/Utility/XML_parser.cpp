//
// Created by alex on 2/9/19.
//

#include "../Headers/XML_parser.h"

// private:

void XML_parser::extractElements() {
    rapidxml::xml_node<> *root = doc.first_node();

    for (rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling()) {
        std::string name = node->name();
        if (elements.find(name) == elements.end()) {
            std::vector<rapidxml::xml_node<>*> temp;
            temp.push_back(node);
            elements[name] = temp;
        } else {
            elements[name].push_back(node);
        }
    }

    return;
}

// public:
XML_parser::XML_parser(char * xmlFile) : filename(xmlFile) {}
XML_parser::~XML_parser() {}

void XML_parser::init() {
    rapidxml::file<> xmlFile(filename);
    doc.parse<0>(xmlFile.data());

}

Map* XML_parser::parseElements() {
    extractElements();

    Map *map = new Map();

    std::vector<rapidxml::xml_node<>*> nodes;

    nodes = elements["item"];
    for (auto n : nodes)    map->addItem(n);

    nodes = elements["creature"];
    for (auto n : nodes)    map->addCreature(n);

    nodes = elements["container"];
    for (auto n : nodes)    map->addContainer(n);

    nodes = elements["room"];
    for (auto n : nodes)    map->addRoom(n);

    return map;
}

