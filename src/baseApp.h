#ifndef __baseApp__
#define __baseApp__

#include "ofMain.h"
#include "baseState.h"
#include "assets.h"

class BaseApp
{
    
protected:
    Assets *assets;
    
public:
    BaseApp();
    
    void keyPressed(ofKeyEventArgs& eventArgs);
    void update(ofEventArgs &args);
    virtual void keyPressed(int key)=0;
    virtual void update()=0;
    
    Assets *getAssets();
};

#endif