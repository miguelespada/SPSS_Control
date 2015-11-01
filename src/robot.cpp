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

    clean();
}

void Robot::clean(){
    
    angle = 0;
    setDestinationAngle(angle, 1);
    bCameraAlive = false;
    bMotorAlive = false;
    
    lastColor = ofColor(0);
    for(int i = 0; i < 180; i ++)
        colors[i] = lastColor;
}

Robot::~Robot(){
    delete sender;
}

void Robot::setDestinationAngle(float a, int t){
    ofxOscMessage m;
    m.setAddress("/servo");
    m.addIntArg(angle);
    m.addIntArg(a);
    m.addIntArg(t);
    ofLogNotice() << "[ROBOT " << id << "] " << m.getArgAsInt32(0) << " --> "  << m.getArgAsInt32(1) << " : "  << m.getArgAsInt32(2) << " s";
    sender->sendMessage(m);
}

void Robot::setCurrentAngle(float a){
    bMotorAlive = true;
    angle = a;
}

void Robot::setCurrentState(BaseState *s){
    current_state = s;
}

void Robot::setCurrentColor(int r, int g, int b){
    lastColor = ofColor(r, g, b);
    colors[angle] = lastColor;
}

void Robot::scan(){
    setCurrentState(new ScanState(this));
}

void Robot::draw(){
    ofPushMatrix();
    ofPushStyle();
    
    drawFrame();
    drawLastColor();
    drawColors();
    drawInfo();
    drawAlive();
    
    ofPopStyle();
    ofPopMatrix();
    
}

void Robot::drawLastColor(){
    ofPushMatrix();
    ofPushStyle();
    
    ofTranslate(100, 5);
    ofSetColor(lastColor);
    ofRect(0, 0, 45, 45);
    
    ofTranslate(50, 0);
    ofSetColor(ofColor(lastColor.getBrightness()));
    ofRect(0, 0, 45, 45);
    
    ofTranslate(50, 0);
    ofColor c = lastColor;
    c.setSaturation(255);
    ofSetColor(c);
    ofRect(0, 0, 45, 45);
    
    
    ofPopStyle();
    ofPopMatrix();
    
    
}

void Robot::drawColors(){
    
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(100, 55);
    for(int i = 0; i < 180; i ++){
        ofColor c = colors[i];
        ofPushMatrix();
        ofSetColor(c);
        ofLine(i, 0, i, 30);
        
        ofTranslate(0, 35);
        ofSetColor(ofColor(c.getBrightness()));
        ofLine(i, 0, i, 30);
        
        ofTranslate(0, 35);
        c.setSaturation(255);
        ofSetColor(c);
        ofLine(i, 0, i, 30);
        
        ofPopMatrix();
    }
    ofTranslate(angle, 102);
    ofSetColor(255, 0, 0);
    ofLine(0, 0, 0, 5);
    
    ofPopStyle();
    ofPopMatrix();
}

void Robot::drawFrame(){
    
    ofPushMatrix();
    ofPushStyle();
    
    ofNoFill();
    ofSetLineWidth(5);
    ofSetColor(0);
    ofRect(0, 0, 400, ofGetHeight()/3);
    
    ofPopStyle();
    ofPopMatrix();
}

void Robot::drawInfo(){
    ofPushMatrix();
    ofPushStyle();
    
    ofTranslate(10, 15);
    ofTrueTypeFont *font = Assets::getInstance()->getFont(10);
    ofSetColor(0);
    font->drawString(ofToString(id), 0, 0);
    ofTranslate(0, 15);
    font->drawString(ofToString(angle) + "º", 0, 0);
    ofTranslate(0, 15);
    font->drawString(ofToString(current_state->toString()), 0, 0);
    
    ofPopStyle();
    ofPopMatrix();
}

void Robot::drawAlive(){
    
    ofPushMatrix();
    ofPushStyle();
    
    ofSetColor(127);
    if(bCameraAlive)
        ofSetColor(0, 255, 0);
    
    ofCircle(370, 15, 5);
    
    ofSetColor(127);
    if(bMotorAlive)
        ofSetColor(0, 255, 0);
    
    ofCircle(385, 15, 5);
    
    ofPopStyle();
    ofPopMatrix();
}

void Robot::update(){
    if(ofGetFrameNum() % 30 == 0){
        bMotorAlive = false;
        bCameraAlive = false;
    }
}