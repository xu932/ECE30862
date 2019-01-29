#include "PrivDerived.h"

PrivDerived::PrivDerived( ) { }
PrivDerived::~PrivDerived( ){ }
void PrivDerived::print( ) { 
   cout << "PrivDerived" << endl;
   cout << "privB: " << getPrivB(); 
   cout << ", protB: " << protB;
   cout << ", publicB: " << publicB; 
   cout << endl << endl;
}

int PrivDerived::getPrivB() {
    return Base::getPrivB();
}

int PrivDerived::getProtB() {
    return Base::getProtB();
}

int PrivDerived::getPubB() {
    return publicB;
}
