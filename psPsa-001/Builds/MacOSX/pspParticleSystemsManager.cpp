//
//  pspParticleSystemsManager.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 22/11/14.
//
//

#include "pspParticleSystemsManager.h"

using namespace std;

pspParticleSystemsManager::pspParticleSystemsManager(){
    setup();
}

pspParticleSystemsManager::~pspParticleSystemsManager(){
    if(pSystems){
        while(!pSystems->empty()){
            delete pSystems->back();
            pSystems->pop_back();
        }
        delete pSystems;
    }
    
    if(concertRoom){
        delete concertRoom;
    }
    
}

void pspParticleSystemsManager::setup(){
    pSystems = new vector<pspParticleSystem*>();
    concertRoom = new ConcertRoom();
    
    
    for(int i=0; i<10; i++){
        addSystem("generic", to_string(i));
    }
    
    cout<<pSystems->size();
}
void pspParticleSystemsManager::update(){
    if(pSystems){
        for(int i=0; i<pSystems->size(); i++){
            (*pSystems)[i]->update();
        }
    }
}
void pspParticleSystemsManager::draw(){
    if(pSystems){
        for(int i=0; i<pSystems->size(); i++){
            (*pSystems)[i]->draw();
        }
    }
    
    concertRoom->draw();
}


int pspParticleSystemsManager::getNumSystems(){
    if(pSystems != NULL){
        return pSystems->size();
    }
    return 0;
}

void pspParticleSystemsManager::debug(){
    cout<<endl<<"works !";
}

vector<pspParticleSystem*>* pspParticleSystemsManager::getSystems(){
    if(pSystems != nullptr){
        return pSystems;
    }
    pSystems = new vector<pspParticleSystem*>();
    return pSystems;
    
}

String pspParticleSystemsManager::getSystemName(int s){
    if(pSystems != nullptr){
        if(pSystems->size() > s){
            return (*pSystems)[s]->getName();
        }
    }
    return "no system to call";
}
String pspParticleSystemsManager::getSystemType(int s){
    if(pSystems != nullptr){
        if(pSystems->size() > s){
            return (*pSystems)[s]->getType();
        }
    }
    return "no system to call";
}


void pspParticleSystemsManager::addSystem(juce::String type, juce::String name){

    if(pSystems == nullptr){
        pSystems = new vector<pspParticleSystem*>();
    }
    
    pSystems->push_back(new pspParticleSystem(name));
}

void pspParticleSystemsManager::deleteSystem(int s){
    if(pSystems != nullptr){
        if(pSystems->size() > s){
            delete (*pSystems)[s];
            pSystems->erase(pSystems->begin() + s);
            cout<<endl<<"system deleted";
            cout<<endl<<"new size = "<<pSystems->size();
        }
    }
    
}

pspParticleSystem* pspParticleSystemsManager::getSystem(int s){
    if(pSystems != nullptr){
        if(pSystems->size() > s){
            return (*pSystems)[s];
        }
        return (*pSystems->begin());
    }
    pSystems = new vector<pspParticleSystem*>();
    return (*pSystems->begin());
}

ConcertRoom* pspParticleSystemsManager::getConcertRoom(){
    return concertRoom;
}

int pspParticleSystemsManager::getNumSpeakers(){
    if(concertRoom != nullptr){
        return concertRoom->getNumSpeakers();
    }
    return 0;
}

