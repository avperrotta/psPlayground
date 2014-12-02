//
//  pspParticleSystem.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 22/11/14.
//
//

#include "pspParticleSystem.h"
#include "pspParticleSystemsManager.h"

using namespace std;

pspParticleSystem::pspParticleSystem(){
    type = "generic";
    name = "noName";
    systemsManager = nullptr;
    myGuiWindow = nullptr;
    particles = nullptr;
}

pspParticleSystem::pspParticleSystem(pspParticleSystemsManager* sm, String n, int np){
    setup(sm, n, np);
}



pspParticleSystem::~pspParticleSystem(){
    if(particles != nullptr){
        while(!particles->empty()){
            delete particles->back();
            particles->pop_back();
        }
        delete particles;
    }
}


void pspParticleSystem::setup(pspParticleSystemsManager* sm, String n, int np){
    systemsManager = sm;
    particles = new vector<pspParticle*>();
    
    name = n;
    
    numParticles = np;
    if(numParticles < 0){
        numParticles = 1;
    }
    addParticles(numParticles);
    
    specificSetup();
    
    setFocus(true);
}

void pspParticleSystem::specificSetup(){
    type = "generic";
}

void pspParticleSystem::update(){
    if(particles != nullptr){
        for(int i=0; i<particles->size(); i++){
            (*particles)[i]->update();
        }
    }
}

void pspParticleSystem::draw(){
    glPushMatrix();
    glColor4f(myColour.getFloatRed(), myColour.getFloatGreen(), myColour.getFloatBlue(), alpha);
    drawParticles();
    drawSystem();
    glPopMatrix();
}

void pspParticleSystem::drawParticles(){
    
    if(particles != nullptr){
        for(int i=0; i<particles->size(); i++){
            (*particles)[i]->draw();
        }
    }
}

void pspParticleSystem::drawSystem(){
    
}

void pspParticleSystem::addParticles(int np){
    
    int numParticlesToAdd;
    
    if(np < 0){
        numParticlesToAdd = 0;
    }
    else{
        
        if(particles == nullptr){
            particles = new vector<pspParticle*>();
        }
        
        numParticlesToAdd = np;
        
        if((numParticlesToAdd + particles->size()) > MAX_NUM_PARTICLES){
            numParticlesToAdd = MAX_NUM_PARTICLES - particles->size();
        }
        
        addParticleSpecific(numParticlesToAdd);
    }
}

void pspParticleSystem::addParticleSpecific(int np){
    int indexStart = particles->size();
    for(int i=0; i<np; i++){
        particles->push_back(new pspParticle(this, i + indexStart));
    }
}

pspParticleSystemsManager* pspParticleSystem::getManager(){
    return systemsManager;
}


String pspParticleSystem::getType(){
    return type;
}

String pspParticleSystem::getName(){
    return name;
}

void pspParticleSystem::setFocus(bool f){
    focus = f;
    
    if(focus){
        alpha = 1.;
    }
    else{
        alpha = 0.5;
    }
}

void pspParticleSystem::setColor(Colour c){
    myColour = c;
}

void pspParticleSystem::showGui(){
    
}