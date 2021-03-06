/*
 Copyright (c) 2014, André V. Perrotta
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 * Neither the name of the developer nor the
 names of its contributors may be used to endorse or promote products
 derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY ANDRÉ V. PERROTTA ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL ANDRÉ V. PERROTTA BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 This file is part of psPlayground.
 
 psPlayground is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 psPlayground is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with psPlayground.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "dbap.h"
#include "Particle.h"
#include "Speaker.h"
#include "ConcertRoom.h"

Dbap::Dbap(){
    dbap = NULL;
}

Dbap::Dbap(ConcertRoom* cr, Particle* p){
    concertRoom = cr;
    myParticle = p;
    
    
    if(concertRoom && myParticle){
        if(concertRoom->getSpeakers()){
            speakers = concertRoom->getSpeakers();
            active = true;
        }
    }
    else{
        active = false;
        post("Dbap disactivated");
    }
    
    dbap = new vector<double>();
}

Dbap::~Dbap(){
    if(dbap){
        dbap->clear();
        delete dbap;
    }
    
}

void Dbap::setup(){
    
}


void Dbap::update(){
    if(dbap){
        if(!dbap->empty()){
            dbap->clear();
        }
        calculateSpeakersGain();
        calculateReverb();
    }
}

vector<double>* Dbap::getDbap(){
    return dbap;
}

void Dbap::draw(){
    
}

void Dbap::calculateSpeakersGain(){
    
    if(active && speakers->size() > 0){
        double dist;
        double gain;
        
        gain = -100.;
        
        for(int i=0; i<speakers->size(); i++){
            dist = dist3d(myParticle->posCar, (*speakers)[i]->scaledPos);
            gain = getInterpolatedFromOfVec2fVector((*speakers)[i]->getSpeakerCalibration(), dist);
            dbap->push_back(gain);
        }
    }
}

void Dbap::calculateReverb(){
    
    if(active && speakers->size() > 0){
        double dist;
        double gain;
        double size;
        
        
        dist = dist3d(myParticle->posCar, ofVec3f(0., 0., 0.));
        gain = getInterpolatedFromOfVec2fVector(concertRoom->getReverbGain(), dist);
        size = getInterpolatedFromOfVec2fVector(concertRoom->getReverbSize(), dist);
        
        dbap->push_back(gain);
        dbap->push_back(size);
        
    }
}


