//
// Created by alex on 2/9/19.
//

#include "../Headers/Map.h"

Map::Map(std::unordered_map<std::string, std::vector<rapidxml::xml_node<>*>>& elements) {
    std::vector<rapidxml::xml_node<>*> nodes;

    nodes = elements["item"];
    for (auto n : nodes)    addItem(n);

    nodes = elements["creature"];
    for (auto n : nodes)    addCreature(n);

    nodes = elements["container"];
    for (auto n : nodes)    addContainer(n);

    nodes = elements["room"];
    for (auto n : nodes)    {
        std::cout << n->name() << std::endl;
        addRoom(n);
    }
}

Map::~Map() {}

void Map::addRoom(rapidxml::xml_node<> *root) {
    std::shared_ptr<Room> room = std::make_shared<Room>();
    rapidxml::xml_node<>* node;
    for (node = root->first_node(); node; node = node->next_sibling()) {
        std::string name(node->name());
        std::cout << "\t" << name << std::endl;
        if (name == "container") {
            std::string temp(node->value());
            if (containers.find(temp) != containers.end()) {
                room->addContainer(temp, containers[temp]);
            } else {
                std::cerr << "Container does not exist" << std::endl;
                exit(1);
            }
        } else if (name == "item") {
            std::string temp(node->value());
            if (items.find(temp) != items.end()) {
                room->addItem(temp, items[temp]);
            } else {
                std::cerr << "Item does not exist" << std::endl;
                exit(1);
            }
        } else if (name == "creature") {
            std::string temp(node->value());
            if (creatures.find(temp) != creatures.end()) {
                room->addCreature(temp, creatures[temp]);
            } else {
                std::cerr << "Creature does not exist" << std::endl;
                exit(1);
            }
        } else if (name == "trigger") {
            std::shared_ptr<Trigger> trig = std::make_shared<Trigger>(node);
            room->addTrigger(trig);
        } else if (name == "border") {
            room->addBorder(node);
        } else {
            room->addInfo(name, std::string(node->value()));
        }
    }
    std::string name(room->getInfo("name"));
    if (name != "[ERROR]")      rooms[name] = room;
}

void Map::addItem(rapidxml::xml_node<> *root) {
    std::shared_ptr<Item> item = std::make_shared<Item>();
    rapidxml::xml_node<>* node;
    for (node = root->first_node(); node; node = node->next_sibling()) {
        std::string name(node->name());
        if (name == "turnon") {
            std::string print = node->first_node("print")->value();
            std::string action = node->first_node("action")->value();
            item->initTurnOn(print, action);
        } else if (name == "trigger") {
            std::shared_ptr<Trigger> trig = std::make_shared<Trigger>(node);
            item->addTrigger(trig);
        } else {
            item->addInfo(name, std::string(node->value()));
        }
    }

    std::string name = item->getInfo("name");
    if (name != "[ERROR]")      items[name] = item;
}

void Map::addContainer(rapidxml::xml_node<> *root) {
    std::shared_ptr<Container> container = std::make_shared<Container>();
    rapidxml::xml_node<>* node;
    for (node = root->first_node(); node; node = node->next_sibling()) {
        std::string name(node->name());
        if (name == "trigger") {
            std::shared_ptr<Trigger> trig = std::make_shared<Trigger>(node);
            container->addTrigger(trig);
        } else if (name == "accept") {
            container->addAccepts(name);
        } else if (name == "item") {
            container->addItem(name, items);
        } else {
            container->addInfo(name, std::string(node->value()));
        }
    }

    std::string name = container->getInfo("name");
    if (name != "[ERROR]")      containers[name] = container;
}

void Map::addCreature(rapidxml::xml_node<> *root) {
    std::shared_ptr<Creature> creature = std::make_shared<Creature>();
    rapidxml::xml_node<>* node;
    for (node = root->first_node(); node; node = node->next_sibling())
        creature->addInfo(std::string(node->name()), node);

    std::string name = creature->getInfo("name");
    if (name != "[ERROR]")      creatures[name] = creature;
}

void Map::print() {
    std::cout << items["torch"]->getInfo("name") << std::endl;
    std::cout << containers["lock"]->getInfo("name") << std::endl;
    creatures["gnome"]->print();
}