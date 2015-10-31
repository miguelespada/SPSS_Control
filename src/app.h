#ifndef __app__
#define __app__

#include "baseApp.h"
#include "standbyState.h"
#include "robot.h"


class App: public BaseApp
{
    
public:
    App();
    ~App();
    void keyPressed(int key);
    
    Robot *robots[3];
    StandbyState *states[3];
    
    void update();
    void draw();
    
};


#endif
