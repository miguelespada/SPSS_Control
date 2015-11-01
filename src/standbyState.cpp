#include "standbyState.h"

StandbyState::StandbyState(Robot *r):BaseState(){
    BaseState::initialize();
    robot = r;
};

StandbyState::~StandbyState(){
};

void StandbyState::draw(){
    robot->draw();
};

void StandbyState::update(){
    robot->update();
};

void StandbyState::next(){
    delete this;
};

