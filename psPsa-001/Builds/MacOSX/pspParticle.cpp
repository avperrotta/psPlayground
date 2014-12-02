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
    
    specificSetup();
}

void pspParticle::specificSetup(){
    
}

void pspParticle::update(){
    
    
}

void pspParticle::draw(){
    
}