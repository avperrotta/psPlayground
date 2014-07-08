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
    
    posOffsetIni = ofVec3f(-0.5, -0.5, -0.5);
    posOffset = posOffsetIni;
    posRadIni = ofVec3f(0.25, 0., 0.);
    posRad = posRadIni;
    
    speedIni = ofVec3f(0., 0.1, 0.1);
    speed = speedIni;
    
    maxRadius = sqrt((limits_x.min - limits_x.max)*(limits_x.min - limits_x.max) +
                     (limits_y.min - limits_y.max)*(limits_y.min - limits_y.max) +
                     (limits_z.min - limits_z.max)*(limits_z.min - limits_z.max));
    
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

void SphericalMovementParticle::restart(){
	
	
}


void SphericalMovementParticle::setRadius(t_atom* argv){
    speed.x = 0.0;
    posRad.x = crop(atom_getfloat(argv), 0.0, 1000000000.);
}
void SphericalMovementParticle::setTheta(t_atom* argv){
    speed.y = 0.0;
    posRad.y = atom_getfloat(argv);
}
void SphericalMovementParticle::setPhi(t_atom* argv){
    speed.z = 0.0;
    posRad.z = atom_getfloat(argv);
}
void SphericalMovementParticle::setRadiusSpeed(t_atom* argv){
    speed.x = atom_getfloat(argv);
}
void SphericalMovementParticle::setThetaSpeed(t_atom* argv){
    speed.y = atom_getfloat(argv);
}
void SphericalMovementParticle::setPhiSpeed(t_atom* argv){
    speed.z = atom_getfloat(argv);
}


void SphericalMovementParticle::setSizeLimits(long argc, t_atom* argv){
    if(argc == 6){
        if(argv){
            limits_x.min = atom_getfloat(argv + 0);
            limits_x.max = atom_getfloat(argv + 1);
            limits_y.min = atom_getfloat(argv + 2);
            limits_y.max = atom_getfloat(argv + 3);
            limits_z.min = atom_getfloat(argv + 4);
            limits_z.max = atom_getfloat(argv + 5);
            
            maxRadius = sqrt((limits_x.min - limits_x.max)*(limits_x.min - limits_x.max) +
                             (limits_y.min - limits_y.max)*(limits_y.min - limits_y.max) +
                             (limits_z.min - limits_z.max)*(limits_z.min - limits_z.max));
        }
    }
    
}





















