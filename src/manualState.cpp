#include "manualState.h"
#include "assets.h"


ManualState::ManualState(Robot *r):BaseState(){
    BaseState::initialize();
    robot = r;
    next();
};

ManualState::~ManualState(){
};

void ManualState::draw(){
};

void ManualState::update(){
    if(!robot->bRunning && ofGetFrameNum() % 20 == 0)
        next();
};

void ManualState::next(){
        int time = Assets::getInstance()->speed;
        int a = Assets::getInstance()->getPosition(robot->id);
    
        if(a != int(robot->angle))
            robot->setDestinationAngle(a, time);
    
};

