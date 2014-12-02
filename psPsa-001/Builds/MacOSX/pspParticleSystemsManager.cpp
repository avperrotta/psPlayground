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
    
    createColorVector();
    
    /*
    for(int i=0; i<1; i++){
        addSystem("generic", 1);
    }
    for(int i=0; i<1; i++){
        addSystem("random", 1);
    }
    */
    
    //cout<<pSystems->size();
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


void pspParticleSystemsManager::addSystem(juce::String type, int np){
    
    if(pSystems == nullptr){
        pSystems = new vector<pspParticleSystem*>();
    }
    
    int lastIndex = pSystems->size();
    
    if(type == "generic"){
        pSystems->push_back(new pspParticleSystem(this, String(lastIndex + 1), np));
    }
    else if(type == "random"){
        pSystems->push_back(new pspRandomSystem(this, String(lastIndex + 1), np));
    }
    
    pSystems->back()->setColor(colors[colorIndex]);
    pSystems->back()->showGui();
    incrementColorIndex();
    
    
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

void pspParticleSystemsManager::createColorVector(){
    colorIndex = 0;
    
    colors.push_back(Colours::tomato);
    colors.push_back(Colours::coral);
    colors.push_back(Colours::cornflowerblue);
    colors.push_back(Colours::darkred);
    colors.push_back(Colours::firebrick);
    colors.push_back(Colours::forestgreen);
    colors.push_back(Colours::khaki);
    colors.push_back(Colours::lemonchiffon);
    colors.push_back(Colours::lightsalmon);
    colors.push_back(Colours::lightyellow);
    colors.push_back(Colours::maroon);
    colors.push_back(Colours::darkseagreen);
    colors.push_back(Colours::darkblue);
    colors.push_back(Colours::lavenderblush);
    colors.push_back(Colours::mediumaquamarine);
    colors.push_back(Colours::plum);
    colors.push_back(Colours::springgreen);
    colors.push_back(Colours::sienna);
    colors.push_back(Colours::seashell);
    colors.push_back(Colours::steelblue);
    colors.push_back(Colours::aliceblue);
}

void pspParticleSystemsManager::incrementColorIndex(){
    colorIndex++;
    if(colorIndex >= colors.size()){
        colorIndex = 0;
    }
}

void pspParticleSystemsManager::showPsystemGui(int ps){
    if(pSystems != nullptr){
        if(ps >= 0 && ps < pSystems->size()){
            (*pSystems)[ps]->showGui();
        }
    }
}
