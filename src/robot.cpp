#include "robot.h"
#include "assets.h"
#include "scanState.h"

Robot::Robot(int _id){
    id = _id;
    string host = Assets::getInstance()->getRemoteIp(id);
    int port = Assets::getInstance()->getRemotePort();
    
    cout << "Sending to "<< host << " " << port << endl;
    sender = new ofxOscSender();
    sender->setup(host, port);

    angle = 0;
    setAngle(angle, 1);
}

Robot::~Robot(){
    delete sender;
}

void Robot::setAngle(float a, int t){
    ofxOscMessage m;
    m.setAddress("/servo");
    m.addIntArg(angle);
    m.addIntArg(a);
    m.addIntArg(t);
    ofLogNotice() << "[ROBOT " << id << "] " << m.getArgAsInt32(0) << " --> "  << m.getArgAsInt32(1) << " : "  << m.getArgAsInt32(2) << " s";
    sender->sendMessage(m);

}

void Robot::setCurrentState(BaseState *s){
    current_state = s;
}

void Robot::scan(){
    setCurrentState(new ScanState(this));
}

void Robot::draw(){
    
    ofTrueTypeFont *font = Assets::getInstance()->getFont(12);
    ofSetColor(0);
    font->drawString("[ID] " + ofToString(id) + " [STATE] " + current_state->toString() + " [Angle] " + ofToString(angle), 0, 0);
}