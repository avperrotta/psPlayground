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
#include "cylindricalMovementParticle.h"

CylindricalMovementParticle::CylindricalMovementParticle(){
	
}

CylindricalMovementParticle::CylindricalMovementParticle(pSystem* sys, int ind){
	setup(sys, ind);
}

CylindricalMovementParticle::~CylindricalMovementParticle(){
	
}

void CylindricalMovementParticle::customSetup(){
    
    coordinateSystem = "cylindrical";
    
	reset();
}

void CylindricalMovementParticle::customRestart(){
	
	
    posOffset = posOffsetIni;
	posRad = posRadIni;
    speed = speedIni;
    calculateLimits();
}

void CylindricalMovementParticle::reset(){
    
    resetLimits();
    
    posOffsetIni = generateRandomVec3f(randomness, ofVec3f(0., 0., 0.));
    posOffsetFinal = generateRandomVec3f(randomness, ofVec3f(0., 0., 0.));
	posRadIni = generateRandomVec3f(randomness, ofVec3f(0.25, 0., 0.));
	posRadFinal = generateRandomVec3f(randomness, ofVec3f(0.75, 0., 0.));
	speedIni = generateRandomVec3f(randomness, ofVec3f(0., 0.1, 0.1));
	
    direction = 1;
	
	restart();
}


void CylindricalMovementParticle::customUpdate(){
    
    if(posRad.x > maxRadius){
		posRad.x = maxRadius;
		speed.x *= -1.;
	}
	if(posRad.x < 0.0){
		posRad.x = 0.0;
		speed.x *= -1.;
	}
    
    if(direction == 1){
        
        posCar.x = posRad.x*cos(posRad.y) + posOffset.x;
        posCar.y = posRad.z + posOffset.y;
        posCar.z = posRad.x*sin(posRad.y) + posOffset.z;
        
        if(posCar.y > limits_y.max){
            posCar.y = limits_y.max;
            speed.z *= -1.;
        }
        if(posCar.y < limits_y.min){
            posCar.y = limits_y.min;
            speed.z *= -1.;
        }
        
    }
    else if(direction == 2){
        posCar.x = posRad.x*cos(posRad.y) + posOffset.x;
        posCar.y = posRad.x*sin(posRad.y) + posOffset.y;
        posCar.z = posRad.z + posOffset.z;
        
        if(posCar.z > limits_z.max){
            posCar.z = limits_z.max;
            speed.z *= -1.;
        }
        if(posCar.z < limits_z.min){
            posCar.z = limits_z.min;
            speed.z *= -1.;
        }

    }
    else if(direction == 3){
        posCar.x = posRad.z + posOffset.x;
        posCar.y = posRad.x*cos(posRad.y) + posOffset.y;
        posCar.z = posRad.x*sin(posRad.y) + posOffset.z;
        
        if(posCar.x > limits_x.max){
            posCar.x = limits_x.max;
            speed.z *= -1.;
        }
        if(posCar.x < limits_x.min){
            posCar.x = limits_x.min;
            speed.z *= -1.;
        }
    }
    
    posRad += speed;
	
    
}

void CylindricalMovementParticle::trajectoryUpdate(){
    
    
    posRad.x = posRadIni.x + (posRadFinal.x - posRadIni.x)*lifeTime/timeToLive;
    posRad.y = posRadIni.y + (posRadFinal.y - posRadIni.y)*lifeTime/timeToLive;
    posRad.z = posRadIni.z + (posRadFinal.z - posRadIni.z)*lifeTime/timeToLive;
    
    posOffset.x = posOffsetIni.x + (posOffsetFinal.x - posOffsetIni.x)*lifeTime/timeToLive;
    posOffset.y = posOffsetIni.y + (posOffsetFinal.y - posOffsetIni.y)*lifeTime/timeToLive;
    posOffset.z = posOffsetIni.z + (posOffsetFinal.z - posOffsetIni.z)*lifeTime/timeToLive;
    
    if(direction == 1){
        posCar.x = posRad.x*cos(posRad.y) + posOffset.x;
        posCar.y = posRad.z + posOffset.y;
        posCar.z = posRad.x*sin(posRad.y) + posOffset.z;
    }
    else if(direction == 2){
        posCar.x = posRad.x*cos(posRad.y) + posOffset.x;
        posCar.y = posRad.x*sin(posRad.y) + posOffset.y;
        posCar.z = posRad.z + posOffset.z;
    }
    else if(direction == 3){
        posCar.x = posRad.z + posOffset.x;
        posCar.y = posRad.x*cos(posRad.y) + posOffset.y;
        posCar.z = posRad.x*sin(posRad.y) + posOffset.z;
    }
    
	//post("posRad = %lf %lf %lf", posRad.x, posRad.y, posRad.z);
}




void CylindricalMovementParticle::setRadius(t_atom* argv){
    speed.x = 0.0;
    posRad.x = crop(atom_getfloat(argv), 0.0, 1000000000.);
}
void CylindricalMovementParticle::setTheta(t_atom* argv){
    speed.y = 0.0;
    posRad.y = atom_getfloat(argv);
}
void CylindricalMovementParticle::setHeight(t_atom* argv){
    speed.z = 0.0;
    posRad.z = atom_getfloat(argv);
}
void CylindricalMovementParticle::setRadiusSpeed(t_atom* argv){
    speed.x = atom_getfloat(argv);
}
void CylindricalMovementParticle::setThetaSpeed(t_atom* argv){
    speed.y = atom_getfloat(argv);
}
void CylindricalMovementParticle::setHeightSpeed(t_atom* argv){
    speed.z = atom_getfloat(argv);
}

void CylindricalMovementParticle::setDirection(t_atom* argv){
    direction = (int)crop(atom_getfloat(argv), 1, 3);
}

void CylindricalMovementParticle::calculateLimits(){
    if(direction == 1){
        maxRadius = min(abs(limits_x.max - limits_x.min)*0.5, abs(limits_z.max - limits_z.min)*0.5);
        
        
        posOffset.x = (limits_x.min + limits_x.max)*0.5;
        posOffset.y = limits_y.min;
        posOffset.z = (limits_z.min + limits_z.max)*0.5;
        
    }
    else if(direction == 2){
        maxRadius = min(abs(limits_x.max - limits_x.min)*0.5, abs(limits_y.max - limits_y.min)*0.5);
        
        posOffset.x = (limits_x.min + limits_x.max)*0.5;
        posOffset.y = (limits_y.min + limits_y.max)*0.5;
        posOffset.z = limits_z.min;
    }
    else if(direction == 3){
        maxRadius = min(abs(limits_y.max - limits_y.min)*0.5, abs(limits_z.max - limits_z.min)*0.5);
        
        posOffset.x = limits_x.min;
        posOffset.y = (limits_y.min + limits_y.max)*0.5;
        posOffset.z = (limits_z.min + limits_z.max)*0.5;;
    }
    
    
}



















