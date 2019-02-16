#ifndef ALARM_H
#define ALARM_H
#include "Subject.h"
#include "Observer.h"

class Alarm : public Observer {
public:
    Alarm(Subject*,int,double,double,double);
    virtual ~Alarm( );
    virtual void notify(double,double);
private:
    double x;
    double y;
    double soundAlarm;
    int id;
};

#endif /* ALARM_H */
