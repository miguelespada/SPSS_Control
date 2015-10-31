#include "standbyState.h"

StandbyState::StandbyState(Robot *r):BaseState(){
    BaseState::initialize();
    robot = r;
};

StandbyState::~StandbyState(){
};

void StandbyState::draw(){
};

void StandbyState::update(){
};

void StandbyState::next(){
    delete this;
};

