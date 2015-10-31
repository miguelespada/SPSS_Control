#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    
    ofLogNotice() << "Running app";
    app = new App();
    osc = new OscAdapter(app);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(233);
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
            
        default:
            break;
    }
}
