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
    
    deleteFlag = false;
}

pspParticleSystem::pspParticleSystem(pspParticleSystemsManager* sm, String n, int np){
    setup(sm, n, np);
}



pspParticleSystem::~pspParticleSystem(){
    
    //delete myGuiWindow;
    
    if(particles != nullptr){
        while(!particles->empty()){
            delete particles->back();
            particles->pop_back();
        }
        delete particles;
    }
    
}

void pspParticleSystem::setDeleteFlag(bool f){
    deleteFlag = f;
}

bool pspParticleSystem::getDeleteFlag(){
    return deleteFlag;
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
    
    oscSender = systemsManager->getOscSender();
    
    sendOscFlag = true;
}

void pspParticleSystem::specificSetup(){
    type = "generic";
}

void pspParticleSystem::update(){
    
    threadLock = true;
    
    if(particles != nullptr){
        for(int i=0; i<particles->size(); i++){
            (*particles)[i]->update();
        }
        
        if(sendOscFlag){
            if(particles->size() > 0){
                char buffer[OSC_MSG_BUFFER_SIZE * particles->size()];
                osc::OutboundPacketStream p(buffer, OSC_MSG_BUFFER_SIZE * particles->size());
                p << osc::BeginBundleImmediate;
                juce::String path = "/" + type + ":" + name;
                for(int i=0; i<particles->size(); i++){
                    p << osc::BeginMessage(path.getCharPointer());
                    p << i + 1;
                    for(int j=0; j<(*particles)[i]->getRawOscMsg().size(); j++){
                        p << (float)(*particles)[i]->getRawOscMsg()[j];
                    }
                    p << osc::EndMessage;
                }
                p << osc::EndBundle;
                oscSender->Send(p.Data(), p.Size());
            }
        }
    }
    
    specificUpdate();
    
    threadLock = false;
}

void pspParticleSystem::specificUpdate(){
    
}

void pspParticleSystem::draw(){
    threadLock = true;
    glPushMatrix();
    glColor4f(myColour.getFloatRed(), myColour.getFloatGreen(), myColour.getFloatBlue(), alpha);
    drawParticles();
    drawSystem();
    glPopMatrix();
    threadLock = false;
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

void pspParticleSystem::changeNumParticles(int np){
    if(np >= 0){
        if(particles != nullptr){
            if(np > particles->size()){
                addParticles(np - particles->size());
            }
            else if(np < particles->size()){
                removeParticles(particles->size() - np);
            }
        }
    }
}
void pspParticleSystem::removeParticles(int np){
    if(particles != nullptr){
        if(np > 0){
            int rm = np;
            while(rm > 0 && !particles->empty()){
                delete particles->back();
                particles->pop_back();
                rm--;
            }
        }
    }
}

int pspParticleSystem::getNumParticles(){
    if(particles != nullptr){
        return particles->size();
    }
    return 0;
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

//child virtual methods
void pspParticleSystem::setBounds(CubeLimits cl){
    
}

