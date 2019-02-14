#include "Subject.h"
#include "Observer.h"
#include "GPS.h"
#include "Map.h"
#include "Alarm.h"
#include <string>
#include <iostream>

int main(void) {
   GPS* gps = new GPS(3);     // nothing
   Map* map = new Map(gps);   // nothing
   Alarm* alarm1 = new Alarm(gps, 1, 0.0, 0.0, 0.9);  // nothing
   Alarm* alarm2 = new Alarm(gps, 2, 1.0, 1.0, 1.0);  // nothing
   Alarm* alarm3 = new Alarm(gps, 3, 5.0, 5.0, 1.0);  // error: obs full, size: 3, idx: 3

   gps->update(1.0, 1.0);  // new map location: (1, 1)
                           // Alarm1 sounded! Moved 1.41421 meters
   gps->update(4.0, 4.0);  // new map location: (4, 4)
                           // Alarm1 Sounded! Moved 5.65685 meters
                           // Alarm2 Sounded! Moved 4.24264 meters


   delete alarm1;
   delete alarm2;
   delete alarm3;

   delete map;
   delete gps;

}
