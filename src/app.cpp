#include "app.h"

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
    
}

void App::draw(){
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(10, 0);
    for (int i = 0; i < 3; i ++){
        ofTranslate(0, 30);
        robots[i]->draw();
    }
    ofPopMatrix();
    ofPopStyle();
}