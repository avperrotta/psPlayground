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

#include "spatCalibrationParticle.h"
#include "mathUtils.h"


SpatCalibrationParticle::SpatCalibrationParticle(){
    
}

SpatCalibrationParticle::SpatCalibrationParticle(pSystem* sys, int ind){
    setup(sys, ind);
}

SpatCalibrationParticle::~SpatCalibrationParticle(){
    
}

void SpatCalibrationParticle::customSetup(){
    
    
    
    speakers = concertRoom->getSpeakers();
    
    for(int i=0; i<speakers->size(); i++){
        positions.push_back((*speakers)[i]->scaledPos);
    }
    
    
    positions.push_back(ofVec3f(-0.5*concertRoom->getSoundLimits()[0], -0.5*concertRoom->getSoundLimits()[1], -0.5*concertRoom->getSoundLimits()[2]));
    positions.push_back(ofVec3f(0.5*concertRoom->getSoundLimits()[0], -0.5*concertRoom->getSoundLimits()[1], -0.5*concertRoom->getSoundLimits()[2]));
    positions.push_back(ofVec3f(-0.5*concertRoom->getSoundLimits()[0], -0.5*concertRoom->getSoundLimits()[1], 0.5*concertRoom->getSoundLimits()[2]));
    positions.push_back(ofVec3f(0.5*concertRoom->getSoundLimits()[0], -0.5*concertRoom->getSoundLimits()[1], 0.5*concertRoom->getSoundLimits()[2]));
    
    
    speedIni = ofVec3f(0.05, 0.05, 0.05);
    
    restart();
    
    
    
    
}

void SpatCalibrationParticle::restart(){
    
    
    if(positions.size() > 0){
        currentPos = 0;
        nextPos = 1;
        
        if(nextPos >= positions.size()){
            nextPos = 0;
        }
        
        posCarIni = positions[currentPos];
        posCar = posCarIni;
        posCarNext = positions[nextPos];
        
        speed = speedIni;
        
        reach = 0;
    }
    
    
}


void SpatCalibrationParticle::customUpdate(){
    
    
    if(positions.size() > 0){
        if(dist3d(posCar, posCarNext) < speedIni.x){
            reach++;
            if(reach == 1){
                posCar = positions[nextPos];
                posCarNext = positions[currentPos];
            }
            else if(reach == 2){
                reach = 0;
                nextPos++;
                if(nextPos == currentPos){
                    nextPos++;
                }
                if(nextPos >= positions.size()){
                    nextPos = 0;
                    currentPos++;
                    if(currentPos >= positions.size()){
                        currentPos = 0;
                    }
                    
                }
                posCar = positions[currentPos];
                posCarNext = positions[nextPos];
            }
            
        }
        
        
        dx = posCarNext.x - posCar.x;
        dy = posCarNext.y - posCar.y;
        dz = posCarNext.z - posCar.z;
        
        double d;
        d = sqrt(dx*dx + dy*dy + dz*dz);
        
        if(d != 0.0){
            speed.x = dx/d * speedIni.x;
            speed.y = dy/d * speedIni.y;
            speed.z = dz/d * speedIni.z;
        }
        else{
            speed = ofVec3f(0., 0., 0.);
        }
        posCar += speed;
    }
}



void SpatCalibrationParticle::setSpeed(ofVec3f sv){
    speedIni = sv;
}





































