#include "noiseState.h"
#include "assets.h"

#define MIN_DIST 100

NoiseState::NoiseState(Robot *r):BaseState(){
    BaseState::initialize();
    robot = r;
    next();
};

NoiseState::~NoiseState(){
};

void NoiseState::draw(){
};

void NoiseState::update(){
    if(!robot->bRunning && ofGetFrameNum() % 20 == 0)
        next();
    
};

void NoiseState::next(){
    int time = 1;
    int a = Assets::getInstance()->getPosition(robot->id);
    
    a = ofClamp(a + ofRandom(-20, 20), 0, 180);
    
    if(a != int(robot->angle))
        robot->setDestinationAngle(a, time);
    
};

