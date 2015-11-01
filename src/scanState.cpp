#include "scanState.h"

ScanState::ScanState(Robot *r):BaseState(){
    BaseState::initialize();
    robot = r;
    
   
    
};

ScanState::~ScanState(){
};

void ScanState::draw(){
};

void ScanState::update(){
    if(!robot->bRunning)
        next();
};

void ScanState::next(){
    int time = ofRandom(2, 6);
    int a = 0;
    if(robot->angle == 0)
        a = 180;
    robot->setDestinationAngle(a, time);
};

