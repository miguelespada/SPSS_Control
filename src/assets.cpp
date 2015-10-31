#include "assets.h"

void Assets::loadAssets(){
}

string Assets::getRemoteIp(int id){
    return getData("remote_ip_" + ofToString(id)).asString();
}

int Assets::getRemotePort(){
    return getData("remote_port").asInt();
}
