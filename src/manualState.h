
#ifndef __manual__state__
#define __manual__state__

#include "baseState.h"
#include "robot.h"

class ManualState: public BaseState
{
    Robot *robot;
    int t;
public:
    ManualState(Robot *r);
    ~ManualState();
    string toString() { return "Manual"; }
    void update();
    void draw();
    void next();

    
};

#endif