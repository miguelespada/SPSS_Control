#include "assets.h"

void Assets::loadAssets(){
    
    gui.setup();
    gui.setPosition(1290, 200);
    gui.add(saturation.setup( "saturation", 1, 0, 2 ));
    gui.add(brightness.setup( "brightness", 1, 0, 2 ));
    gui.add(r.setup( "r", 1, 0, 2 ));
    gui.add(g.setup( "g", 1, 0, 2 ));
    gui.add(b.setup( "b", 1, 0, 2 ));
    
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
