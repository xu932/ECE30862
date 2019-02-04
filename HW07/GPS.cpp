#include <iostream>
#include "GPS.h"

GPS::GPS(int s) : {
   obs = new Observer*[size];
}

GPS::~GPS( ) {
   delete obs;
}
