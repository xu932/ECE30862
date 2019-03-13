//
// Created by alex on 2/10/19.
//

#ifndef ECE30862_CONDITION_H
#define ECE30862_CONDITION_H

#include <unordered_map>
#include <string>

enum Type {LONG, SHORT};

class Condition {
private:
    bool has;
    Type type;
    std::string object;
    std::string owner;
    std::string status;

public:
    Condition(std::unordered_map<std::string, std::string>& map);
    virtual ~Condition();

};


#endif //ECE30862_CONDITION_H
