#include "ProtDerived.h"

ProtDerived::ProtDerived( ) { }
ProtDerived::~ProtDerived( ){ }
void ProtDerived::print( ) { 
   cout << "ProtDerived" << endl;
   cout << "privB: " << getPrivB(); 
   cout << ", protB: " << protB;
   cout << ", publicB: " << publicB; 
   cout << endl << endl;
}

int ProtDerived::getPrivB() {
    return Base::getPrivB();
}

int ProtDerived::getProtB() {
    return Base::getProtB();
}

int ProtDerived::getPubB() {
    return publicB;
}


