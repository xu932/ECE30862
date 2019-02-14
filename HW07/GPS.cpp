#include <iostream>
#include "GPS.h"

GPS::GPS(int s) : x(0.0), y(0.0), size(s), idx(0) {
   obs = new Observer*[size];
}

GPS::~GPS( ) {
   delete obs;
}

void GPS::subscribe(Observer* observer) {
   if (idx == size) {
      std::cerr << "Ovserver is full. Size " << size << std::endl;
   } else {
      obs[idx++] = observer;
   }
}

void GPS::update(double xx, double yy) {
   x = xx;
   y = yy;
   notify();
}

void GPS::notify() {
   for (int i = 0; i < idx; i++) {
      obs[i]->notify(x, y);
   }
}
