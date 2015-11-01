
#ifndef __standby__state__
#define __standby__state__

#include "baseState.h"
#include "robot.h"

class StandbyState: public BaseState
{
    Robot *robot;
    
public:
    StandbyState(Robot *r);
    ~StandbyState();
    string toString() { return "stand by"; }
    void update();
    void draw();
    void next();
    void setDestinationAngle();
};

#endif