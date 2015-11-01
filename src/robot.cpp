#include "robot.h"
#include "assets.h"
#include "scanState.h"
#include "manualState.h"
#include "noiseState.h"
#include "searchState.h"

Robot::Robot(int _id){
    id = _id;
    string host = Assets::getInstance()->getRemoteIp(id);
    int port = Assets::getInstance()->getRemotePort();
    
    cout << id <<" sending to "<< host << " " << port << endl;
    sender = new ofxOscSender();
    sender->setup(host, port);
    bRunning = false;
    clean();
}

void Robot::clean(){
    
    angle = 0;
    setDestinationAngle(angle, 1);
    bCameraAlive = false;
    bMotorAlive = false;
    
    lastColor = ofColor(0);
    for(int i = 0; i <= 180; i ++)
        colors[i] = lastColor;
}

Robot::~Robot(){
    delete sender;
}

void Robot::setDestinationAngle(float a, int t){
    if(bRunning)
        return;
    bRunning = true;
    
    ofxOscMessage m;
    m.setAddress("/servo");
    m.addIntArg(a);
    m.addIntArg(t);
    ofLogNotice() << "[ROBOT " << id << "] " << angle << " --> "  << m.getArgAsInt32(0) << " : "  << m.getArgAsInt32(1) << " s";
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
    bCameraAlive = true;
    r = ofClamp( r * Assets::getInstance()->r, 0, 255);
    g = ofClamp( g * Assets::getInstance()->g, 0, 255);
    b = ofClamp( b * Assets::getInstance()->b, 0, 255);
    lastColor = ofColor(r, g, b);
    float saturation = ofClamp(lastColor.getSaturation() * Assets::getInstance()->saturation, 0, 255);
    float brightness = ofClamp(lastColor.getBrightness() *  Assets::getInstance()->brightness, 0, 255);
    lastColor.setSaturation(saturation);
    lastColor.setBrightness(brightness);
    colors[angle] = lastColor;
}

void Robot::scan(){
    delete current_state;
    setCurrentState(new ScanState(this));
}

void Robot::manual(){
    delete current_state;
    setCurrentState(new ManualState(this));
}

void Robot::noise(){
    delete current_state;
    setCurrentState(new NoiseState(this));
}

void Robot::search(){
    delete current_state;
    setCurrentState(new SearchState(this));
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
    c.setBrightness(255);
    ofSetColor(c);
    ofRect(0, 0, 45, 45);
    
    
    ofPopStyle();
    ofPopMatrix();
    
    
}

void Robot::drawColors(){
    
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(100, 55);
    for(int i = 0; i <= 180; i ++){
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
    ofTranslate(0, 15);
    font->drawString(ofToString(bRunning), 0, 0);
    
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
    current_state->update();
    if(ofGetFrameNum() % 60 == 0){
        bMotorAlive = false;
        bCameraAlive = false;
    }
}

int Robot::getBrightness(){
    return lastColor.getBrightness();
}

void Robot::setMotorState(bool s){
    bRunning = s;
}

int Robot::findBestColor(){
    int a = -1;
    int best = -1;
    
    for(int i = 0; i <= 180; i ++){
        int v = colors[i].getSaturation();
        if(v > best){
            best = v;
            a = i;
        }
    }
    ofLogNotice() << "[BEST ANGLE] " << a;
    return a;
}