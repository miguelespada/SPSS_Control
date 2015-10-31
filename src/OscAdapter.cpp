#include "OscAdapter.h"
#include "assets.h"

OscAdapter::OscAdapter(App *a){
    app = a;
    int localPort = Assets::getInstance()->getLocalPort();
    
    receiver = new ofxOscReceiver;
    receiver->setup(localPort);
    
    ofLogNotice() << "listening for osc messages on port " << localPort;
    bOnline = false;
    
    ofAddListener(ofEvents().update, this, &OscAdapter::update);
}

OscAdapter::~OscAdapter(){
    delete receiver;
}

void OscAdapter::update(ofEventArgs &args){
    while(receiver->hasWaitingMessages()){
        bOnline = true;
        ofxOscMessage m;
        receiver->getNextMessage(&m);
        
        if(m.getAddress() == "/angle"){
            app->robots[m.getArgAsInt32(0)]->angle = m.getArgAsInt32(1);
        }
        
        if(m.getAddress() == "/setAngle"){
            app->robots[m.getArgAsInt32(0)]->setAngle(m.getArgAsInt32(1), m.getArgAsInt32(2));
        }
        
        if(m.getAddress() == "/scan"){
            app->robots[m.getArgAsInt32(0)]->scan();
        }
    }
}
