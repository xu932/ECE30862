#include "dPublic.h"

dPublic( ) { }
~dPublic( ){ }
void print( ) { 
   cout << "dPublic" << endl;
   cout << "privB: " << privB; 
   cout << ", protB: " << protB;
   cout << ", publicB: " << publicB; 
   cout << endl << endl;
}

