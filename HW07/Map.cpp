#include <iostream>
#include "Map.h"

Map::Map(Subject * s) {  
   s->subscribe(this);
}

Map::~Map( ) { }

void Map::notify(double x, double y) {
   std::cout << "new map location: (" << x << ", " << y << ")" << std::endl;
}
