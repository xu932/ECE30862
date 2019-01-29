#ifndef PRIVDERIVED_H
#define PRIVDERIVED_H
#include "Base.h"
#include <iostream>
#include <string>
using namespace std;

class PrivDerived : private Base {
public:
    PrivDerived( );
    virtual ~PrivDerived( );
    void print( );

    virtual int getPrivB();
    virtual int getProtB();
    virtual int getPubB();
};

#endif /* PRIVDERIVED_H */
