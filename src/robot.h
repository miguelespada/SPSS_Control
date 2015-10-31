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
    
public:
    int angle;
    Robot(int _id);
    ~Robot();
    void setAngle(float a, int t);
    void setCurrentState(BaseState *s);
    void scan();
    void draw();
    
};


#endif /* defined(__SPSS__robot__) */
