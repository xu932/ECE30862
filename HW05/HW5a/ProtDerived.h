#ifndef PROTDERIVED_H
#define PROTDERIVED_H
#include <iostream>
#include <string>
#include "Base.h"
using namespace std;

class ProtDerived : protected Base {
public:
    ProtDerived( );
    virtual ~ProtDerived( );
    void print( );
    virtual int getPrivB();
    virtual int getProtB();
    virtual int getPubB();
};

#endif /* PROTDERIVED_H */
