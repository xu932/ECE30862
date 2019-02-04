#include <iostream>
#include "D.h"

D::D( ) : j(1) {i = 2;}
D::~D( ){ }
void D::print( ) { 
   cout << "i: " << i << ", j: " << j << endl;
}

