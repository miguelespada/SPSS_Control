#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    
    ofLogNotice() << "Running app";
    app = new App();
    osc = new OscAdapter(app);
    bFull = false;
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    app->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '0':
            app->robots[0]->scan();
            break;
        case '1':
            app->robots[1]->scan();
            break;
        case '2':
            app->robots[2]->scan();
            break;
            
        case 'f':
            bFull = !bFull;
            setFullScreen();
            break;
            
            
        case 'b':
            app->cleanGrid(0);
            break;
            
        case 'w':
            app->cleanGrid(255);
            break;
            
            
        default:
            break;
    }
}

void ofApp::setFullScreen(){
    if(bFull){
        ofSetFullscreen(true);
        ofSetWindowPosition(-1280, 0);
        ofHideCursor();
    }
    else{
        ofSetFullscreen(false);
        ofSetWindowPosition(0, 0);
        ofShowCursor();
    }
    
}