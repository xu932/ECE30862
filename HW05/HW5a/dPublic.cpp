#include "dPublic.h"

dPublic::dPublic( ) { }
dPublic::~dPublic( ){ }
void dPublic::print( ) { 
   cout << "dPublic" << endl;
   cout << "privB: " << getPrivB(); 
   cout << ", protB: " << protB;
   cout << ", publicB: " << publicB; 
   cout << endl << endl;
}

