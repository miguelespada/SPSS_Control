#include "baseState.h"

BaseState::BaseState(){
    timer = ofGetElapsedTimef();
}

void BaseState::initialize(){
    ofLogNotice() << "State: " << toString();
}

BaseState::~BaseState(){
    
}

bool BaseState::isDone(int duration){
    return (ofGetElapsedTimef() - timer) >= duration;
}
