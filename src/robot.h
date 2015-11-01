//
//  robot.h
//  SPSS
//
//  Created by miguel on 31/10/15.
//
//

#ifndef __SPSS__robot__
#define __SPSS__robot__

#include <ofMain.h>
#include "ofxOsc.h"
#include "baseState.h"

class Robot
{
    ofxOscSender *sender;
    int id;
    class BaseState *current_state;
    ofColor colors[181];
    
public:
    bool bMotorAlive;
    bool bCameraAlive;
    
    ofColor lastColor;
    int angle;
    Robot(int _id);
    ~Robot();
    void setCurrentAngle(float a);
    void setDestinationAngle(float a, int t);
    void setCurrentState(BaseState *s);
    void setCurrentColor(int r, int g, int b);
    void scan();
    void draw();
    void update();
    void clean();
    
    void drawLastColor();
    void drawColors();
    void drawInfo();
    void drawAlive();
    void drawFrame();
    
    int getBrightness();
    bool bRunning;
    void setMotorState(bool s);
    
};


#endif /* defined(__SPSS__robot__) */
