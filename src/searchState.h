
#ifndef __search__state__
#define __search__state__

#include "baseState.h"
#include "robot.h"

class SearchState: public BaseState
{
    Robot *robot;
    int t;
public:
    SearchState(Robot *r);
    ~SearchState();
    string toString() { return "Search"; }
    void update();
    void draw();
    void next();

    
};

#endif