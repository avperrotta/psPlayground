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

#include "emitterSource.h"
#include <math.h>

EmitterSource::EmitterSource(){
	
}

EmitterSource::EmitterSource(pSystem* sys, int ind){
	setup(sys, ind);
}

EmitterSource::~EmitterSource(){
	
}

void EmitterSource::customSetup(){
	reset();
}

void EmitterSource::customUpdate(){
	
}

void EmitterSource::customRestart(){
	
	
}

void EmitterSource::reset(){
    
    resetLimits();
    
    width = 0.1;
    posCar = ofVec3f(0., 0., 0.);
    
    horizontalRange = limits(0., 0.5*M_PI);
    verticalRange = limits(0., M_PI);
    speedRange = limits(0.01, 0.1);
    
    
    calculateRangeDrawingCoordinates();
    
    restart();
}

void EmitterSource::draw(){
    
    //post("aqui");
    
    glPushMatrix();
    glColor4f(color.x, color.y, color.z, gain);
    glTranslatef(posCar.x, posCar.y, posCar.z);
    
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(h1.x, h1.y, h1.z);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(h2.x, h2.y, h2.z);
    glEnd();
    
    for(int i=0; i<(h.size() - 1); i++){
        glBegin(GL_LINES);
        glVertex3f(h[i].x, h[i].y, h[i].z);
        glVertex3f(h[i + 1].x, h[i + 1].y, h[i + 1].z);
        glEnd();
    }
    
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(v1.x, v1.y, v1.z);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0., 0., 0.);
    glVertex3f(v2.x, v2.y, v2.z);
    glEnd();
    
    for(int i=0; i<(v.size() - 1); i++){
        glBegin(GL_LINES);
        glVertex3f(v[i].x, v[i].y, v[i].z);
        glVertex3f(v[i + 1].x, v[i + 1].y, v[i + 1].z);
        glEnd();
    }
    
    glPopMatrix();
    
    
}

void EmitterSource::calculateRangeDrawingCoordinates(){
    
    double dT;
    ofVec3f aux;
    
    h1.x = width*cos(horizontalRange.min);
    h1.y = 0.;
    h1.z = width*sin(horizontalRange.min);
    
    h2.x = width*cos(horizontalRange.max);
    h2.y = 0.;
    h2.z = width*sin(horizontalRange.max);
    
    h.clear();
    h.push_back(h1);
    dT = abs(horizontalRange.max - horizontalRange.min)*0.1;
    
    for(int i=1; i<10; i++){
        double t = i*dT + horizontalRange.min;
        aux.x = width*cos(t);
        aux.y = 0.;
        aux.z = width*sin(t);
        h.push_back(aux);
    }
    h.push_back(h2);
    
    
    
    /*
    v1.x = width*cos(verticalRange.min);
    v1.y = width*sin(verticalRange.min);
    v1.z = 0.;
    
    v2.x = width*cos(verticalRange.max);
    v2.y = width*sin(verticalRange.max);
    v2.z = 0.;
    
    v.clear();
    v.push_back(v1);
    dT = abs(verticalRange.max - verticalRange.min)*0.1;
    
    for(int i=1; i<10; i++){
        double t = i*dT + verticalRange.min;
        aux.x = width*cos(t);
        aux.y = width*sin(t);
        aux.z = 0.;
        v.push_back(aux);
    }
    v.push_back(v2);
    */
    
    double phi = (horizontalRange.max + horizontalRange.min)*0.5;
    
    v1.x = width*sin(verticalRange.min)*cos(phi);
    v1.y = width*cos(verticalRange.min);
    v1.z = width*sin(verticalRange.min)*sin(phi);
    
    v2.x = width*sin(verticalRange.max)*cos(phi);
    v2.y = width*cos(verticalRange.max);
    v2.z = width*sin(verticalRange.max)*sin(phi);
    
    v.clear();
    v.push_back(v1);
    dT = abs(verticalRange.max - verticalRange.min)*0.1;
    
    for(int i=1; i<10; i++){
        double t = i*dT + verticalRange.min;
        aux.x = width*sin(t)*cos(phi);
        aux.y = width*cos(t);
        aux.z = width*sin(t)*sin(phi);
        v.push_back(aux);
    }
    v.push_back(v2);
    
}


void EmitterSource::setHorizontalRange(t_atom* argv){
    horizontalRange = limits(atom_getfloat(argv), atom_getfloat(argv + 1));
    horizontalRange.max = crop(horizontalRange.max, 0., 2.*M_PI);
    horizontalRange.min = crop(horizontalRange.min, 0., 2.*M_PI);
    
    if(horizontalRange.min > horizontalRange.max){
        horizontalRange = limits(horizontalRange.max, horizontalRange.min);
    }
    
    calculateRangeDrawingCoordinates();
}

void EmitterSource::setVerticalRange(t_atom* argv){
    verticalRange = limits(atom_getfloat(argv), atom_getfloat(argv + 1));
    verticalRange.max = crop(verticalRange.max, 0., M_PI);
    verticalRange.min = crop(verticalRange.min, 0., M_PI);
    
    if(verticalRange.min > verticalRange.max){
        verticalRange = limits(verticalRange.max, verticalRange.min);
    }
    
    calculateRangeDrawingCoordinates();
}

void EmitterSource::setSpeedRange(t_atom* argv){
    speedRange = limits(atom_getfloat(argv), atom_getfloat(argv + 1));
    
    calculateRangeDrawingCoordinates();
}

















