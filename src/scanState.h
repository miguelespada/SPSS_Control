
#ifndef __scan__state__
#define __scan__state__

#include "baseState.h"
#include "robot.h"

class ScanState: public BaseState
{
    Robot *robot;
    int t;
public:
    ScanState(Robot *r);
    ~ScanState();
    string toString() { return "SCAN"; }
    void update();
    void draw();
    void next();
    
};

#endif