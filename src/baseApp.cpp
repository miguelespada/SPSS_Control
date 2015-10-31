#include "baseApp.h"


BaseApp::BaseApp(){
    
    ofLogNotice() << "Initializing app...";
    
    assets = (Assets *)Assets::getInstance();
    
    // Register events and actions
    ofAddListener(ofEvents().keyPressed, this, &BaseApp::keyPressed);
    ofAddListener(ofEvents().update, this, &BaseApp::update);

}


void BaseApp::update(ofEventArgs &args){
    update();
}

void BaseApp::keyPressed (ofKeyEventArgs& eventArgs){
    keyPressed(eventArgs.key);
}



Assets * BaseApp::getAssets(){
    return assets;
}