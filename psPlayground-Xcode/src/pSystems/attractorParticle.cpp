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

#include "attractorParticle.h"
#include "pSystem.h"
#include "emitterSystem.h"

AttractorParticle::AttractorParticle(){
	
}

AttractorParticle::AttractorParticle(pSystem* sys, int ind){
	setup(sys, ind);
}

AttractorParticle::~AttractorParticle(){
	
}

void AttractorParticle::customSetup(){
    
    useDbap = false;
    outputRaw = false;
    outputEnv = false;
    outputDbap = false;
    outputSpecific = false;
    reset();
    
    
}

void AttractorParticle::customUpdate(){
	
}

void AttractorParticle::customRestart(){
	
}

void AttractorParticle::reset(){
    posCar = ofVec3f(0., 0., 0.);
    intensity = 0.001;
    width = 50.*intensity;
    restart();
}

void AttractorParticle::setIntensity(t_atom *argv){
    intensity = crop(atom_getfloat(argv), 0., atom_getfloat(argv));
    
    width = 50.*intensity;
}

ofVec3f AttractorParticle::calculateAttraction(ofVec3f p){
    
    ofVec3f acc;
    ofVec3f dists;
    double norm = dist3d(p, posCar);
    dists.x = dist2d(p.x, posCar.x);
    dists.y = dist2d(p.y, posCar.y);
    dists.z = dist2d(p.z, posCar.z);
    
    acc.x = -1.*intensity*(p.x - posCar.x)/norm;
    acc.y = -1.*intensity*(p.y - posCar.y)/norm;
    acc.z = -1.*intensity*(p.z - posCar.z)/norm;
    
    
    if(norm != 0.){
        acc.x = -1.*intensity*(p.x - posCar.x)/norm;
        acc.y = -1.*intensity*(p.y - posCar.y)/norm;
        acc.z = -1.*intensity*(p.z - posCar.z)/norm;
    }
    else{
        acc = ofVec3f(0., 0., 0.);
    }
    
    
    
    return acc;
}

void AttractorParticle::draw(){
    
     glPushMatrix();
     glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
     glEnable(GL_BLEND);
     glBlendEquation(GL_FUNC_ADD);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
     glColor4f(color.x, color.y, color.z, 0.05);
     GLUquadricObj* Sphere;
     glTranslatef(posCar.x, posCar.y, posCar.z);
     Sphere = gluNewQuadric();
     gluSphere(Sphere, width, 16, 16);
     gluDeleteQuadric(Sphere);
     glDisable(GL_BLEND);
     glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
     glPopMatrix();
    

}

