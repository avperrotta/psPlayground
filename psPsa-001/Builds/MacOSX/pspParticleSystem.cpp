//
//  pspParticleSystem.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 22/11/14.
//
//

#include "pspParticleSystem.h"

using namespace std;

pspParticleSystem::pspParticleSystem(){
    type = "generic";
    name = "noName";
    
    focus = false;
    //particles = nullptr;
    //particles = new vector<pspParticle*>();
    //particles->clear();
}

pspParticleSystem::pspParticleSystem(String n){
    type = "generic";
    name = n;
    
    particles = nullptr;
    //particles = new vector<pspParticle*>();
    //particles->clear();
}


pspParticleSystem::~pspParticleSystem(){
    if(particles != nullptr){
        cout<<endl<<"entrei 1";
        while(!particles->empty()){
            cout<<endl<<"entrei 2";
            delete particles->back();
            particles->pop_back();
        }
        delete particles;
    }
}

void pspParticleSystem::setup(){
    
}

void pspParticleSystem::update(){
    
}

void pspParticleSystem::draw(){
    
}



String pspParticleSystem::getType(){
    return type;
}

String pspParticleSystem::getName(){
    return name;
}

void pspParticleSystem::setFocus(bool f){
    focus = f;
}