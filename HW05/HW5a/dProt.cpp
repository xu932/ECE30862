#include "dProt.h"

dProt::dProt( ) { }
dProt::~dProt( ){ }
void dProt::print( ) { 
   cout << "dProt" << endl;
   cout << "privB: " << getPrivB(); 
   cout << ", protB: " << protB;
   cout << ", publicB: " << publicB; 
   cout << endl << endl;
}

