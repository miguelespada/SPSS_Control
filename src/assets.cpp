#include "assets.h"

void Assets::loadAssets(){
    
    gui.setup();
    gui.setPosition(1690, 0);
    gui.add(saturation.setup( "saturation", 1, 0, 2 ));
    gui.add(brightness.setup( "brightness", 1, 0, 2 ));
    gui.add(r.setup( "r", 1, 0, 2 ));
    gui.add(g.setup( "g", 1, 0, 2 ));
    gui.add(b.setup( "b", 1, 0, 2 ));
    
    
    gui.add(sync.setup("sync", true));
    
    gui.add(speed.setup( "time", 1, 1, 10 ));
    gui.add(pos_0.setup( "pos_0", 90, 0, 180 ));
    gui.add(pos_1.setup( "pos_1", 90, 0, 180 ));
    gui.add(pos_2.setup( "pos_2", 90, 0, 180 ));
    
    gui.loadFromFile("settings.xml");
}

string Assets::getRemoteIp(int id){
    return getData("remote_ip_" + ofToString(id)).asString();
}

int Assets::getRemotePort(){
    return getData("remote_port").asInt();
}

int Assets::getMaxPort(){
    return getData("max_port").asInt();
}

int Assets::getPosition(int idx){
    if(sync) return pos_0;
    switch (idx) {
        case 0:
            return pos_0;
            break;
        case 1:
            return pos_1;
            break;
        case 2:
            return pos_2;
            break;
            
        default:
            break;
    }
}


void Assets::setPosition(int idx, int pos){
    switch (idx) {
        case 0:
            pos_0 = pos;
            break;
        case 1:
            pos_1 = pos;
            break;
        case 2:
            pos_2 = pos;
            break;
            
        default:
            break;
    }
}
