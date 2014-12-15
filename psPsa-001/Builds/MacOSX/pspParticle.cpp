//
//  pspParticle.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 22/11/14.
//
//

#include "pspParticle.h"
#include "pspParticleSystem.h"
#include "pspParticleSystemsManager.h"


pspParticle::pspParticle(){
    
}

pspParticle::pspParticle(pspParticleSystem* ms, int ind){
    setup(ms, ind);
}

pspParticle::~pspParticle(){
    
}

void pspParticle::setup(pspParticleSystem* ms, int ind){
    mySystem = ms;
    systemsManager = mySystem->getManager();
    
    index = ind;
    
    sendOsc = true;
    
    
    
    specificSetup();
}

void pspParticle::specificSetup(){
    
}

void pspParticle::update(){
    //debug();
    specificUpdate();
    
    if(sendOsc){
        createOscMessage();
    }
}
void pspParticle::specificUpdate(){
    
}

void pspParticle::draw(){
    specificDraw();
}

void pspParticle::specificDraw(){
    
}

void pspParticle::setOscTag(bool ot){
    sendOsc = ot;
}

void pspParticle::createOscMessage(){
    
    /*
    osc::OutboundPacketStream auxMsg(buffer, OSC_MSG_BUFFER_SIZE);
    juce::String path = mySystem->getType() + ":" + mySystem->getName();
    auxMsg << osc::BeginMessage(path.getCharPointer());
    auxMsg << index;
    for(int i=0; i<3; i++){
        auxMsg << pos[i];
    }
    auxMsg << osc::EndMessage;
    oscMsg = &auxMsg;
    */
    
    rawOscMsg.clear();
    for(int i=0; i<3; i++){
        rawOscMsg.push_back(pos[i]);
    }
}

vector<double> pspParticle::getRawOscMsg(){
    return rawOscMsg;
}

osc::OutboundPacketStream* pspParticle::getOscMsg(){
    if(oscMsg != NULL){
        return oscMsg;
    }
    return nullptr;
    
}


void pspParticle::debug(){
    cout<<endl<<"id = "<<index;
}