#pragma once

#include "ofMain.h"

#include "app.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
        App *app;
};
