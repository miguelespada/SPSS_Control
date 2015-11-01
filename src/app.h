#ifndef __app__
#define __app__

#include "baseApp.h"
#include "standbyState.h"
#include "robot.h"
#include "ofxOsc.h"


class App: public BaseApp
{
    ofxOscSender *sender;
    
public:
    App();
    ~App();
    void keyPressed(int key);
    
    Robot *robots[3];
    
    void update();
    void draw();
    
    void cleanGrid(int b);
    void drawGridColor();
    ofColor gridColor;
    
    void sendToMax();
};


#endif
