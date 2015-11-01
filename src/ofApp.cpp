#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    
    ofLogNotice() << "Running app";
    app = new App();
    osc = new OscAdapter(app);
    bFull = false;
    ofSetBackgroundAuto(false);
    ofSetWindowPosition(0, 0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    app->draw();

    Assets::getInstance()->gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            app->scan();
            break;
        case '2':
            app->manual();
            break;
        case '3':
            app->noise();
            break;
        case '4':
            app->search();
            break;
        case '0':
            Assets::getInstance()->automatic = !Assets::getInstance()->automatic;
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
            
        case 's':
            Assets::getInstance()->gui.saveToFile("settings.xml");
            break;
            
        case 'l':
            Assets::getInstance()->gui.loadFromFile("settings.xml");
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