#include "app.h"

#define GRID_N 20
#define GRID_WEIGHT 5

App::App():BaseApp(){
    
    for (int i = 0; i < 3; i ++){
        robots[i] = new Robot(i);
        states[i] = new StandbyState(robots[i]);
        robots[i]->setCurrentState(states[i]);
    }
}

App::~App(){
    for (int i = 0; i < 3; i ++){
        delete states[i];
        delete robots[i];
    }
}

void App::keyPressed (int key){    
}

void App::update(){
    for (int i = 0; i < 3; i ++)
        states[i]->update();
    
}

void App::drawGridColor(){
    if(ofGetFrameNum() == 5)
        cleanGrid(255);

    ofPushStyle();
    
    int i = ofGetFrameNum() % 3;
    
    int x = int(ofRandom(GRID_N));
    int y = int(ofRandom(GRID_N));
    
    
    ofSetColor(robots[i]->lastColor);
    ofFill();
    ofRect(x *  1280 / GRID_N, y *  800 / GRID_N, 1280 / GRID_N, 800 / GRID_N);
    
    ofSetColor(gridColor);
    ofSetLineWidth(GRID_WEIGHT);
    ofNoFill();
    ofRect(x *  1280 / GRID_N, y *  800 / GRID_N, 1280 / GRID_N, 800 / GRID_N);
    
    ofPopStyle();
}

void App::draw(){
    drawGridColor();
    
    ofPushStyle();
    ofPushMatrix();
    ofSetColor(255);
    ofTranslate(1280, 0);
    ofRect(0, 0, 400, ofGetHeight());
    for (int i = 0; i < 3; i ++){
        states[i]->draw();
        ofTranslate(0, ofGetHeight() / 3);
    }
    ofPopMatrix();
    ofPopStyle();
}

void App::cleanGrid(int b){
    ofPushStyle();
    ofFill();
    ofSetColor(255);
    
    ofSetLineWidth(GRID_WEIGHT);
    ofRect(0, 0, 1280, 800);
    gridColor = b;
    
    ofSetColor(gridColor);
    for(int i = 0; i <= GRID_N; i ++){
        int x = i * 1280 / GRID_N;
        ofLine(x, 0, x, 800);
    }
    
    for(int i = 0; i <= GRID_N; i ++){
        int y = i * 800 / GRID_N;
        ofLine(0, y, 1280, y);
    }
    
    ofPopStyle();
}