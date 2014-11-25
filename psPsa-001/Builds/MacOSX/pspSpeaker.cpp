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

#include "pspSpeaker.h"
#include "pspConcertRoom.h"
#include <OpenGL/OpenGL.h>
#include <OpenGl/gl.h>
#include <OpenGL/glu.h>



Speaker::Speaker(){
    
}

Speaker::Speaker(int n, double x_, double y_, double z_){
    setup(n, x_, y_, z_);
}

Speaker::Speaker(int n, ofVec3f pos_){
    setup(n, pos_);
}

Speaker::~Speaker(){
    
    
    if(speakerCalibration){
        
        while(!speakerCalibration->empty()){
            delete speakerCalibration->back();
            speakerCalibration->pop_back();
        }
        
        speakerCalibration->clear();
        delete speakerCalibration;
    }
    
        
    
}

void Speaker::setup(){
    speakerCalibration = new vector<ofVec2f*>();
    
    for(int i=0; i<10; i++){
        speakerCalibration->push_back(new ofVec2f(i, -120.));
    }
    
    width = 0.07;
    height = 0.07;
    
    scaledPos.x = 0.;
    scaledPos.x = 0.;
    scaledPos.x = 0.;
    
}

void Speaker::setup(int n, double x_, double y_, double z_){
    num = n;
    active = true;
    x = x_;
    y = y_;
    z = z_;
    pos = ofVec3f(x, y, z);
    
    
    setup();
}

void Speaker::setup(int n, ofVec3f pos_){
    num = n;
    pos = pos_;
    
    x = pos.x;
    y = pos.y;
    z = pos.z;
    
    setup();
}

void Speaker::update(){
    
}

void Speaker::draw(){
    
    glPushMatrix();
    glColor3f(0., 0., 1.);
    glTranslated(scaledPos.x, scaledPos.y, scaledPos.z);
    glBegin(GL_QUADS);
    glVertex3f(-0.5*width, 0.5*height, 0.5*width);
    glVertex3f(0.5*width, 0.5*height, 0.5*width);
    glVertex3f(0.5*width, 0.5*height, -0.5*width);
    glVertex3f(-0.5*width, 0.5*height, -0.5*width);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.5*width, 0.5*height, 0.5*width);
    glVertex3f(-0.5*width, 0.5*height, -0.5*width);
    glVertex3f(-0.5*width, -0.5*height, -0.5*width);
    glVertex3f(-0.5*width, -0.5*height, 0.5*width);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.5*width, 0.5*height, 0.5*width);
    glVertex3f(0.5*width, 0.5*height, -0.5*width);
    glVertex3f(0.5*width, -0.5*height, 0.5*width);
    glVertex3f(0.5*width, -0.5*height, -0.5*width);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.5*width, 0.5*height, 0.5*width);
    glVertex3f(-0.5*width, 0.5*height, 0.5*width);
    glVertex3f(-0.5*width, -0.5*height, 0.5*width);
    glVertex3f(0.5*width, -0.5*height, 0.5*width);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.5*width, 0.5*height, -0.5*width);
    glVertex3f(0.5*width, 0.5*height, -0.5*width);
    glVertex3f(0.5*width, -0.5*height, -0.5*width);
    glVertex3f(-0.5*width, -0.5*height, -0.5*width);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.5*width, -0.5*height, 0.5*width);
    glVertex3f(0.5*width, -0.5*height, 0.5*width);
    glVertex3f(0.5*width, -0.5*height, -0.5*width);
    glVertex3f(-0.5*width, -0.5*height, -0.5*width);
    glEnd();
    glPopMatrix();
    
    
}

void Speaker::scalePosition(double* rs){
    if(rs){
        scaledPos.x = rs[0]*pos.x;
        scaledPos.y = rs[1]*pos.y;
        scaledPos.z = rs[2]*pos.z;
    }
}

void Speaker::setPosition(ofVec3f pos_){
    pos = pos_;
    
    x = pos.x;
    y = pos.y;
    z = pos.z;
    
    
}

void Speaker::setPosition(double x_, double y_, double z_){
    x = x_;
    y = y_;
    z = z_;
    pos = ofVec3f(x, y, z);
    
    
}


void Speaker::setSize(double w, double h){
    width = w;
    height = h;
    
    
}


void Speaker::setSpeakerCalibration(int sp){
    
}


vector<ofVec2f*>* Speaker::getSpeakerCalibration(){
    return speakerCalibration;
}
























