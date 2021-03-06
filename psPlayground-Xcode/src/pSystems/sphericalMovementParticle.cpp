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
#include "sphericalMovementParticle.h"

SphericalMovementParticle::SphericalMovementParticle(){
	
}

SphericalMovementParticle::SphericalMovementParticle(pSystem* sys, int ind){
	setup(sys, ind);
}

SphericalMovementParticle::~SphericalMovementParticle(){
	
}

void SphericalMovementParticle::customSetup(){
    
    
    coordinateSystem = "spherical";
    
	reset();
}

void SphericalMovementParticle::customRestart(){
	
	
    posOffset = posOffsetIni;
	posRad = posRadIni;
    speed = speedIni;
    calculateLimits();
    
}

void SphericalMovementParticle::reset(){
    
    resetLimits();
    
    posOffsetIni = generateRandomVec3f(randomness, ofVec3f(0., 0., 0.));
    posOffsetFinal = generateRandomVec3f(randomness, ofVec3f(0., 0., 0.));
	posRadIni = generateRandomVec3f(randomness, ofVec3f(0.25, 0., 0.));
	posRadFinal = generateRandomVec3f(randomness, ofVec3f(0.75, 0., 0.));
	
	speedIni = generateRandomVec3f(randomness, ofVec3f(0., 0.1, 0.1));
	
	
	restart();
}


void SphericalMovementParticle::customUpdate(){
    
	posRad += speed;
	/*
	 if(posRad.y > M_PI){
	 posRad.y = posRad.y - M_PI;
	 }
	 if(posRad.z > 2.*M_PI){
	 posRad.z = posRad.z - 2*M_PI;
	 }
	 */
	posCar.z = posRad.x*sin(posRad.y)*cos(posRad.z) + posOffset.z;
	posCar.x = posRad.x*sin(posRad.y)*sin(posRad.z) + posOffset.x;
	posCar.y = posRad.x*cos(posRad.y) + posOffset.y;
	
	if(posRad.x > maxRadius){
		posRad.x = maxRadius;
		speed.x *= -1.;
	}
	if(posRad.x < 0.0){
		posRad.x = 0.0;
		speed.x *= -1.;
	}
}

void SphericalMovementParticle::trajectoryUpdate(){
    
    
    posRad.x = posRadIni.x + (posRadFinal.x - posRadIni.x)*lifeTime/timeToLive;
    posRad.y = posRadIni.y + (posRadFinal.y - posRadIni.y)*lifeTime/timeToLive;
    posRad.z = posRadIni.z + (posRadFinal.z - posRadIni.z)*lifeTime/timeToLive;
    
    posOffset.x = posOffsetIni.x + (posOffsetFinal.x - posOffsetIni.x)*lifeTime/timeToLive;
    posOffset.y = posOffsetIni.y + (posOffsetFinal.y - posOffsetIni.y)*lifeTime/timeToLive;
    posOffset.z = posOffsetIni.z + (posOffsetFinal.z - posOffsetIni.z)*lifeTime/timeToLive;
    
    
    posCar.z = posRad.x*sin(posRad.y)*cos(posRad.z) + posOffset.z;
    posCar.x = posRad.x*sin(posRad.y)*sin(posRad.z) + posOffset.x;
    posCar.y = posRad.x*cos(posRad.y) + posOffset.y;
    
	//post("posRad = %lf %lf %lf", posRad.x, posRad.y, posRad.z);
}


void SphericalMovementParticle::calculateLimits(){
    
    double auxMin;
    
    auxMin = min(abs(limits_x.max - limits_x.min)*0.5, abs(limits_y.max - limits_y.min)*0.5);
    
    maxRadius = min(auxMin, abs(limits_z.max - limits_z.min)*0.5);
    
    posOffset.x = (limits_x.min + limits_x.max)*0.5;
    posOffset.y = (limits_y.min + limits_y.max)*0.5;
    posOffset.z = (limits_z.min + limits_z.max)*0.5;
}


















