#include "dPriv.h"

dPriv::dPriv( ) { }
dPriv::~dPriv( ){ }
void dPriv::print( ) { 
   cout << "dPriv" << endl;
   cout << "privB: " << getPrivB(); 
   cout << ", protB: " << getProtB();
   cout << ", publicB: " << getPubB(); 
   cout << endl << endl;
}

