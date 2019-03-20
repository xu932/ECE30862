//
// Created by alex on 3/19/19.
//

#ifndef ECE30862_SET_H
#define ECE30862_SET_H

#include <iostream>

class Set {
public:
    int size;
    int n_copy;
    uint32_t *arr;

    Set(int n);
    Set(const Set& s);
    virtual ~Set();

    virtual int getCopyCount();
    void operator=(const Set& s);
    friend std::ostream& operator<<(std::ostream& os, const Set& s);

#ifdef PARTA
    Set operator+(int n);
    Set operator-(int n);
    Set operator&(const Set& s);
    Set operator~();
    Set operator/(const Set& s);
#endif

#ifdef PARTB
    friend Set operator+(const Set& s, int n);
    friend Set operator-(const Set& s, int n);
    friend Set operator&(const Set& s1, const Set& s2);
    friend Set operator~(const Set& s);
    friend Set operator/(const Set& s1, const Set& s2);
#endif
};


#endif //ECE30862_SET_H
