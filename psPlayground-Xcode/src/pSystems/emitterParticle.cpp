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

#include "emitterParticle.h"
#include "pSystem.h"
#include "emitterSystem.h"
#include "attractorParticle.h"

EmitterParticle::EmitterParticle(){
	
}

EmitterParticle::EmitterParticle(pSystem* sys, int ind){
	setup(sys, ind);
}

EmitterParticle::~EmitterParticle(){
	
}

void EmitterParticle::customSetup(){
    
    src = static_cast<EmitterSystem*>(mySystem)->getSrc();
    
    attractors = mySystem->getAttractors();
    
    width = 0.01;
    
    reset();
    
    
}

void EmitterParticle::customUpdate(){
    
    updateAttractorInfluence();
    
    speed += accel;
	posCar += speed;
    
    /*
    if(posCar.x < limits_x.min || posCar.x > limits_x.max
       || posCar.y < limits_y.min || posCar.y > limits_y.max
       || posCar.z < limits_z.min || posCar.z > limits_z.max){
        
        status = 0;
    }
    */
    
    age++;
    if(age > life){
        status = 0;
    }
    gain = 1. - (double)age/(double)life;
}

void EmitterParticle::customRestart(){
	
    posCar = src->posCar;
    
    double absSpeed = rangedRandom(src->speedRange.min, src->speedRange.max);
    double theta = rangedRandom(src->verticalRange.min, src->verticalRange.max);
    double phi = rangedRandom(src->horizontalRange.min, src->horizontalRange.max);
    
    ofVec3f aux;
    
    aux.x = sin(theta)*cos(phi);
    aux.y = cos(theta);
    aux.z = sin(theta)*sin(phi);
    
    aux += src->posCar;
    
    speed = (aux - posCar)*absSpeed;
    
    life = rangedRandom(src->lifeLimits.min, src->lifeLimits.max);
    
    age = 0;
    lifeTime = 0;
	
}

void EmitterParticle::reset(){
    
    status = 1;
    
    limits_x = mySystem->lx;
    limits_y = mySystem->ly;
    limits_z = mySystem->lz;
    
    restart();
}








