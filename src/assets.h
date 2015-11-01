

#ifndef __assets__
#define __assets__

#include "baseAssets.h"
#include "ofxGui.h"


class Assets: public BaseAssets
{
    static Assets* instance;
    Assets();

public:
    static Assets* getInstance();
    void loadAssets();
    
    string getRemoteIp(int id);
    int getRemotePort();
    int getMaxPort();
    
    
    ofxPanel gui;
    ofxFloatSlider saturation;
    ofxFloatSlider brightness;
    ofxFloatSlider r;
    ofxFloatSlider g;
    ofxFloatSlider b;
    
    ofxFloatSlider speed;
    ofxFloatSlider pos_0;
    ofxFloatSlider pos_1;
    ofxFloatSlider pos_2;
    ofxToggle sync;
    
    int getPosition(int idx);
};

#endif
