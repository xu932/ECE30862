//
// Created by alex on 2/9/19.
//

#ifndef ECE30862_XML_PARSER_H
#define ECE30862_XML_PARSER_H

#include <iostream>
#include <string>
#include <unordered_map>

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "Map.h"

#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"


class XML_parser {
private:
    char* filename;
    rapidxml::xml_document<> doc;
    std::unordered_map<std::string, std::vector<rapidxml::xml_node<>*>> elements;

    virtual void extractElements();

public:
    XML_parser(char* xmlFile);
    virtual ~XML_parser();

    virtual void init();
    virtual Map* parseElements();
};

#endif //ECE30862_XML_PARSER_H
