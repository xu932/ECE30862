//
// Created by Alex Xu on 2019-02-08.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "Headers/XML_parser.h"


int main(int argc, char ** argv) {
/*
    std::ifstream xmlFile(argv[1]);
    std::vector<char> buffer((std::istreambuf_iterator<char>(xmlFile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    for (auto c : buffer) {
        std::cout << c;
    }
*/

    XML_parser *xml = new XML_parser(argv[1]);
    xml->init();

    Map *map = xml->parseElements();

    map->print();

    delete map;

    return EXIT_SUCCESS;
}