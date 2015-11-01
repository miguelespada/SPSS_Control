#pragma once

#include "ofMain.h"
#include "app.h"
#include "OscAdapter.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
        App *app;
        OscAdapter *osc;
        bool bFull;
        void setFullScreen();
    
};
