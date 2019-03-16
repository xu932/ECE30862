//
// Created by Alex Xu on 2019-02-08.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "Headers/rapidxml.hpp"
#include "Headers/rapidxml_utils.hpp"
#include "Headers/Map.h"
//#include "Headers/Player.h"

std::unordered_map<std::string, std::vector<rapidxml::xml_node<>*>> extractElements(rapidxml::xml_node<>* root) {
    std::unordered_map<std::string, std::vector<rapidxml::xml_node<>*>> elements;

    for (auto node = root->first_node(); node; node = node->next_sibling()) {
        std::string name(node->name());
        if (elements.find(name) == elements.end()) {
            std::vector<rapidxml::xml_node<>*> temp;
            temp.push_back(node);
            elements[name] = temp;
        } else {
            elements[name].push_back(node);
        }

    }
    return elements;
}

std::string direction(std::string dir) {
    if (dir == "n")         return "north";
    else if (dir == "s")    return "south";
    else if (dir == "e")    return "east";
    else if (dir == "w")    return "west";
    else                    return "[ERROR]";
}

int parseCommand(std::string command, std::vector<std::string>& parse) {
    int idx = 0, prev = 0;
    for (unsigned int i = 1; i < command.length(); i++) {
        if (command[i] != ' ')  continue;
        parse[idx++] = command.substr(prev, i - prev);
        prev = i + 1;
    }
    parse[idx++] = command.substr(prev);

    if (parse[0] == "n" || parse[0] == "s" || parse[0] == "e" || parse[0] == "w")   return 1;
    else if (parse[0] == "i" || parse[0] == "inventory")                            return 2;
    else if (parse[0] == "take")                                                    return 3;
    else if (parse[0] == "open") {
        if (idx >= 2 && parse[1] != "exit")                                         return 4;
        else if (idx >= 2)                                                          return 5;
        else return 0;
    } else if (parse[0] == "read" && idx >= 2)                                      return 6;
    else if (parse[0] == "drop" && idx >= 2)                                        return 7;
    else if (parse[0] == "put") {
        for (int i = 1; i < idx - 1; i++) {
            if (parse[i] == "in")                                                   return 8;
        }
        return 0;
    } else if (parse[0] == "turn" && idx >= 3 && parse[1] == "on")                  return 9;
    else if (parse[0] == "attack") {
        for (int i = 1; i < idx - 1; i++) {
            if (parse[i] == "with")                                                 return 10;
        }
        return 0;
    } else
        return 0;
}

void runZork(Map *map) {
/*
    Player *player = new Player;                                // the player
    std::string command;                                        // for user input command
    std::vector<std::string> parse(10, "");                     // vector for parsing user command
    int type;                                                   // the game command type. List in order as displayed in project description

    std::shared_ptr<Room> current = map->getRoom("Entrance");  // the current room

    // check error
    if (current == nullptr) {
        std::cerr << "error: nullptr" << std::endl;
        delete player;
        delete map;
        exit(2);
    }

    std::cout << current << std::endl;

    // keep running until the game has ended
    while (map->hasGameEnded()) {
        type = 0;
        do {
            std::getline(std::cin, command);
            type = parseCommand(command, parse);
            if (type == 0)      std::cerr << "Error" << std::endl;
        } while (type == 0);


        std::shared_ptr<Trigger> trig = current->trig(command);
        bool check;
        if (trig != nullptr) {
            check = map->activateTrig(trig, player->inventory);
        }

        if (!check) {
            if (type == 1) {            // n, s, w, e
                std::shared_ptr <Room> next = map->getRoom(move(direction(parse[0])));
                if (next != nullptr)
                    current = next;
            } else if (type == 2) {     // i
                std::cout << player << std::endl;
            } else if (type == 3) {     // take (item)
                std::shared_ptr <Item> item = map->getItem(parse[1]);
                if (item != nullptr) {

                }
            } else if (type == 4) {     // open (container)

            } else if (type == 5) {     // open exit

            } else if (type == 6) {     // read (item)

            } else if (type == 7) {     // drop (item)

            } else if (type == 8) {     // put (item) in (container)

            } else if (type == 9) {     // turn on item

            } else if (type == 10) {    // attach (creature) with (item)

            }
        }
    }
    delete player;
    */
}

int main(int argc, char ** argv) {
    rapidxml::file<> xmlFile(argv[1]);
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());

    auto elements = extractElements(doc.first_node());

    Map *map = new Map(elements);

    runZork(map);


    delete map;
    return EXIT_SUCCESS;
}