

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
};

#endif
