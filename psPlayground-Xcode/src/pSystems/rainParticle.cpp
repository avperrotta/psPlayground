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

#include "rainParticle.h"


RainParticle::RainParticle(){
    
}

RainParticle::RainParticle(pSystem* sys, int ind){
    setup(sys, ind);
}

RainParticle::~RainParticle(){
    
}

void RainParticle::customSetup(){
    
    if(!concertRoom->getBounds()){
        limits_x = limits(-0.5*SOUND_LIMIT, 0.5*SOUND_LIMIT);
        limits_y = limits(-0.5*SOUND_LIMIT, 0.5*SOUND_LIMIT);
        limits_z = limits(-0.5*SOUND_LIMIT, 0.5*SOUND_LIMIT);
    }
    else{
        limits_x = limits(-0.5*concertRoom->getBounds()[0], 0.5*concertRoom->getBounds()[0]);
        limits_y = limits(-0.5*concertRoom->getBounds()[1], 0.5*concertRoom->getBounds()[1]);
        limits_z = limits(-0.5*concertRoom->getBounds()[2], 0.5*concertRoom->getBounds()[2]);
    }
    
    randomness = 0.4;
    direction = 1;
    lateralSpeed = 0.001;
    directionalSpeed = 0.01;
    avgLife = 200.;
    
    restart();
    
}


void RainParticle::restart(){
    
    
    
    if(direction == 1){
        
        posCarIni.x = rangedRandom(limits_x.min, limits_x.max);
        posCarIni.y = rangedRandom(limits_y.min, limits_y.max);
        posCarIni.z = limits_z.min;
        
        posCar = posCarIni;
        speed.x = rangedRandom(-lateralSpeed, lateralSpeed);
        speed.y = rangedRandom(-lateralSpeed, lateralSpeed);
        speed.z = rangedRandom(directionalSpeed - directionalSpeed*randomness, directionalSpeed + directionalSpeed*randomness);
        
    }
    else if(direction == 2){
        posCarIni.x = rangedRandom(limits_x.min, limits_x.max);
        posCarIni.y = rangedRandom(limits_y.min, limits_y.max);
        posCarIni.z = limits_z.max;
        
        posCar = posCarIni;
        
        speed.x = rangedRandom(-lateralSpeed, lateralSpeed);
        speed.y = rangedRandom(-lateralSpeed, lateralSpeed);
        speed.z = -1.*rangedRandom(directionalSpeed - directionalSpeed*randomness, directionalSpeed + directionalSpeed*randomness);
    }
    else if(direction == 3){
        posCarIni.x = limits_x.min;
        posCarIni.y = rangedRandom(limits_y.min, limits_y.max);
        posCarIni.z = rangedRandom(limits_z.min, limits_z.max);
        
        posCar = posCarIni;
        
        speed.x = rangedRandom(directionalSpeed - directionalSpeed*randomness, directionalSpeed + directionalSpeed*randomness);
        speed.y = rangedRandom(-lateralSpeed, lateralSpeed);
        speed.z = rangedRandom(-lateralSpeed, lateralSpeed);
    }
    else if(direction == 4){
        posCarIni.x = limits_x.max;
        posCarIni.y = rangedRandom(limits_y.min, limits_y.max);
        posCarIni.z = rangedRandom(limits_z.min, limits_z.max);
        
        posCar = posCarIni;
        
        speed.x = -1.*rangedRandom(directionalSpeed - directionalSpeed*randomness, directionalSpeed + directionalSpeed*randomness);
        speed.y = rangedRandom(-lateralSpeed, lateralSpeed);
        speed.z = rangedRandom(-lateralSpeed, lateralSpeed);
    }
    else if(direction == 5){
        posCarIni.x = rangedRandom(limits_x.min, limits_x.max);
        posCarIni.y = limits_y.min;
        posCarIni.z = rangedRandom(limits_z.min, limits_z.max);
        
        posCar = posCarIni;
        
        speed.x = rangedRandom(-lateralSpeed, lateralSpeed);
        speed.y = rangedRandom(directionalSpeed - directionalSpeed*randomness, directionalSpeed + directionalSpeed*randomness);
        speed.z = rangedRandom(-lateralSpeed, lateralSpeed);
    }
    else if(direction == 6){
        posCarIni.x = rangedRandom(limits_x.min, limits_x.max);
        posCarIni.y = limits_y.max;
        posCarIni.z = rangedRandom(limits_z.min, limits_z.max);
        
        posCar = posCarIni;
        
        speed.x = rangedRandom(-lateralSpeed, lateralSpeed);
        speed.y = -1.*rangedRandom(directionalSpeed - directionalSpeed*randomness, directionalSpeed + directionalSpeed*randomness);
        speed.z = rangedRandom(-lateralSpeed, lateralSpeed);
    }
    age = 0.;
    life = rangedRandom((avgLife - avgLife*randomness), (avgLife + avgLife*randomness));
    gain = getHannGain(age, life);
    
}


void RainParticle::customUpdate(){
    
    gain = getHannGain(age, life);
    age++;
    if(age > life){
        restart();
    }
    
    posCar += speed;
}


void RainParticle::setDirection(int d){
    direction = (int)crop(d, 1, 6);
}

void RainParticle::setAvgLife(double al){
    avgLife = crop(al, 0., 1000000.);
}

void RainParticle::setDirectionalSpeed(double ds){
    directionalSpeed = crop(ds, 0., 100000.);
}

void RainParticle::setLateralSpeed(double ls){
    lateralSpeed = ls;
}



















