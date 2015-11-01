
#ifndef __noise__state__
#define __noise__state__

#include "baseState.h"
#include "robot.h"

class NoiseState: public BaseState
{
    Robot *robot;
    int t;
public:
    NoiseState(Robot *r);
    ~NoiseState();
    string toString() { return "Noise"; }
    void update();
    void draw();
    void next();

    
};

#endif