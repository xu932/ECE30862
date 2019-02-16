#include <iostream>
#include <cmath>
#include "Alarm.h"

Alarm::Alarm(Subject * s, int i, double xx, double yy, double alarm) 
     : x(xx), y(yy), soundAlarm(alarm), id(i) {
    s->subscribe(this);
}

Alarm::~Alarm( ) { }

void Alarm::notify(double xx, double yy) {
    double dist = std::sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
    if (dist > soundAlarm) {
        std::cout << "Alarm" << id << " Sounded! Moved " << dist << " meters" << std::endl;
    }
}
