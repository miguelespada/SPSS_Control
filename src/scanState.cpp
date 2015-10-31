#include "scanState.h"

#define MIN_DIST 100

ScanState::ScanState(Robot *r):BaseState(){
    BaseState::initialize();
    robot = r;
    
    int time = ofRandom(2, 6);
    int a = ofRandom(0, 180);
    
    while(abs(r->angle - a) < MIN_DIST)
         a = ofRandom(0, 180);
    
    t = (int)ofRandom(4, 8);
    
    r->setAngle(a, t);
};

ScanState::~ScanState(){
};

void ScanState::draw(){
};

void ScanState::update(){
    if(isDone(t))
        next();
};

void ScanState::next(){
    robot->setCurrentState(new ScanState(robot));
    delete this;
};

