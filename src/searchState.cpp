#include "searchState.h"
#include "assets.h"


SearchState::SearchState(Robot *r):BaseState(){
    BaseState::initialize();
    robot = r;
    next();
};

SearchState::~SearchState(){
};

void SearchState::draw(){
};

void SearchState::update(){
    if(!robot->bRunning && ofGetFrameNum() % 20 == 0)
        robot->noise();
};

void SearchState::next(){
    int a = robot->findBestColor();
    Assets::getInstance()->setPosition(robot->id, a);
    
    if(a != int(robot->angle))
        robot->setDestinationAngle(a, 5);
    
};

