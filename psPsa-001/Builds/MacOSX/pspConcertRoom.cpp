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

#include "pspConcertRoom.h"
#include <OpenGL/OpenGL.h>
#include <OpenGl/gl.h>
#include <OpenGL/glu.h>


ConcertRoom::ConcertRoom(){
    
    setup();
    
    
    
}
ConcertRoom::~ConcertRoom(){
    if(speakers){
        while(!speakers->empty()){
            delete speakers->back();
            speakers->pop_back();
        }
        speakers->clear();
        delete speakers;
    }
    
    if(reverbGain){
        
        while(!reverbGain->empty()){
            delete reverbGain->back();
            reverbGain->pop_back();
        }
        
        reverbGain->clear();
        delete reverbGain;
    }
    
    if(reverbSize){
        
        while(!reverbSize->empty()){
            delete reverbSize->back();
            reverbSize->pop_back();
        }
        
        reverbSize->clear();
        delete reverbSize;
    }

    
    if(roomBounds){
        delete[] roomBounds;
    }
    
    if(soundLimits){
        delete[] soundLimits;
    }
}

void ConcertRoom::setup(){
    createColorsVec();
    currentColorIndex = 0;
    
    roomBounds = new double[3];
    soundLimits = new double[3];
    
    roomBounds[0] = 1.;
    roomBounds[1] = 1.;
    roomBounds[2] = 1.;
    
    roomWidth = roomBounds[0];
    roomHeight = roomBounds[1];
    roomLength = roomBounds[2];
    
    roomDiagonal = sqrt(roomBounds[0]*roomBounds[0] + roomBounds[1]*roomBounds[1] + roomBounds[2]*roomBounds[2]);
    
    soundLimits[0] = 2.*SOUND_LIMIT*roomDiagonal/sqrt(2.) + roomBounds[0];
    soundLimits[1] = roomBounds[1];
    soundLimits[2] = 2.*SOUND_LIMIT*roomDiagonal/sqrt(2.) + roomBounds[2];
    
    speakers = new vector<Speaker*>();
    reverbGain = new vector<ofVec2f*>();
    reverbSize = new vector<ofVec2f*>();
    
    speakers->push_back(new Speaker(1, -0.5, 0., -0.5));
    speakers->push_back(new Speaker(2, 0.5, 0., -0.5));
    numSpeakers = 2;
    
    for(int i=0; i<speakers->size(); i++){
        (*speakers)[i]->scalePosition(getBounds());
    }
    
    for(int i=0; i<10; i++){
        reverbGain->push_back(new ofVec2f(i, -120.));
        reverbSize->push_back(new ofVec2f(i, 0.));
    }
    
    
}


void ConcertRoom::setBounds(ofVec3f b){
    
    roomBounds[0] = b.x;
    roomBounds[1] = b.y;
    roomBounds[2] = b.z;
    
    roomWidth = roomBounds[0];
    roomHeight = roomBounds[1];
    roomLength = roomBounds[2];
    
    roomDiagonal = sqrt(roomBounds[0]*roomBounds[0] + roomBounds[1]*roomBounds[1] + roomBounds[2]*roomBounds[2]);
    
    soundLimits[0] = 2.*SOUND_LIMIT*roomDiagonal/sqrt(2.) + roomBounds[0];
    soundLimits[1] = roomBounds[1];
    soundLimits[2] = 2.*SOUND_LIMIT*roomDiagonal/sqrt(2.) + roomBounds[2];
    
    for(int i=0; i<speakers->size(); i++){
        (*speakers)[i]->scalePosition(getBounds());
    }
}

double* ConcertRoom::getBounds(){
    if(roomBounds){
        return roomBounds;
    }
    return NULL;
}

double* ConcertRoom::getSoundLimits(){
    if(soundLimits){
        return soundLimits;
    }
    return NULL;
}


vector<Speaker*>* ConcertRoom::getSpeakers(){
    return speakers;
}

std::string ConcertRoom::getFilesPath(){
    return filesPath;
}

void ConcertRoom::setFilesPath(std::string fp){
    filesPath = fp;
}


void ConcertRoom::setNumSpeakers(int n){
    int ns = n;
    if(ns > numSpeakers){
        for(int i=0; i<(ns - numSpeakers); i++){
            speakers->push_back(new Speaker(i+1, 0., 0., 0.));
        }
        numSpeakers = speakers->size();
        return;
    }
    else if(ns < numSpeakers && ns > 0){
        while(speakers->size() > ns){
            delete speakers->back();
            speakers->pop_back();
        }
        numSpeakers = speakers->size();
        return;
    }
}

int ConcertRoom::getNumSpeakers(){
    return numSpeakers;
}

void ConcertRoom::setSpeakerPosition(int sp, ofVec3f pos){
    if(speakers->size() > 0){
        if(sp >= 1 && sp <= numSpeakers){
            (*speakers)[sp - 1]->setPosition(pos.x, pos.y, pos.z);
            (*speakers)[sp - 1]->scalePosition(getBounds());
        }
    }
}

void ConcertRoom::setSpeakerCalibration(int sp){
    
    
}

void ConcertRoom::setReverbGain(int sp){
    
}

vector<ofVec2f*>* ConcertRoom::getReverbGain(){
    return reverbGain;
}

void ConcertRoom::setReverbSize(int sp){
    
}

vector<ofVec2f*>* ConcertRoom::getReverbSize(){
    return reverbSize;
}

void ConcertRoom::draw(){
    
    
    //draw speakers;
    for(int i=0; i<speakers->size(); i++){
        (*speakers)[i]->draw();
    }
    
    
    glLineWidth(2.);
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(-0.5*roomBounds[0], -0.5*roomBounds[1], 0.5*roomBounds[2]);
    glVertex3f(0.5*roomBounds[0], -0.5*roomBounds[1], 0.5*roomBounds[2]);
    glVertex3f(0.5*roomBounds[0], -0.5*roomBounds[1], -0.5*roomBounds[2]);
    glVertex3f(-0.5*roomBounds[0], -0.5*roomBounds[1], -0.5*roomBounds[2]);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glLineWidth(2.);
    glColor3f(0.5, 0., 0.);
    
    //floor
    glBegin(GL_LINES);
    glVertex3f(-0.5*roomBounds[0], -0.5*roomBounds[1], 0.5*roomBounds[2]);
    glVertex3f(0.5*roomBounds[0], -0.5*roomBounds[1], 0.5*roomBounds[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.5*roomBounds[0], -0.5*roomBounds[1], 0.5*roomBounds[2]);
    glVertex3f(0.5*roomBounds[0], -0.5*roomBounds[1], -0.5*roomBounds[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.5*roomBounds[0], -0.5*roomBounds[1], -0.5*roomBounds[2]);
    glVertex3f(-0.5*roomBounds[0], -0.5*roomBounds[1], -0.5*roomBounds[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.5*roomBounds[0], -0.5*roomBounds[1], -0.5*roomBounds[2]);
    glVertex3f(-0.5*roomBounds[0], -0.5*roomBounds[1], 0.5*roomBounds[2]);
    glEnd();
    
    //ceiling
    glBegin(GL_LINES);
    glVertex3f(-0.5*roomBounds[0], 0.5*roomBounds[1], 0.5*roomBounds[2]);
    glVertex3f(0.5*roomBounds[0], 0.5*roomBounds[1], 0.5*roomBounds[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.5*roomBounds[0], 0.5*roomBounds[1], 0.5*roomBounds[2]);
    glVertex3f(0.5*roomBounds[0], 0.5*roomBounds[1], -0.5*roomBounds[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.5*roomBounds[0], 0.5*roomBounds[1], -0.5*roomBounds[2]);
    glVertex3f(-0.5*roomBounds[0], 0.5*roomBounds[1], -0.5*roomBounds[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.5*roomBounds[0], 0.5*roomBounds[1], -0.5*roomBounds[2]);
    glVertex3f(-0.5*roomBounds[0], 0.5*roomBounds[1], 0.5*roomBounds[2]);
    glEnd();
    
    //walls
    glBegin(GL_LINES);
    glVertex3f(-0.5*roomBounds[0], 0.5*roomBounds[1], 0.5*roomBounds[2]);
    glVertex3f(-0.5*roomBounds[0], -0.5*roomBounds[1], 0.5*roomBounds[2]);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0.5*roomBounds[0], 0.5*roomBounds[1], 0.5*roomBounds[2]);
    glVertex3f(0.5*roomBounds[0], -0.5*roomBounds[1], 0.5*roomBounds[2]);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0.5*roomBounds[0], 0.5*roomBounds[1], -0.5*roomBounds[2]);
    glVertex3f(0.5*roomBounds[0], -0.5*roomBounds[1], -0.5*roomBounds[2]);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-0.5*roomBounds[0], 0.5*roomBounds[1], -0.5*roomBounds[2]);
    glVertex3f(-0.5*roomBounds[0], -0.5*roomBounds[1], -0.5*roomBounds[2]);
    glEnd();
    
    
    glPopMatrix();
    
    glPushMatrix();
    glLineWidth(2.);
    glColor3f(1., 1., 0.);
    glBegin(GL_LINES);
    glVertex3f(-0.5*soundLimits[0], -0.5*soundLimits[1], 0.5*soundLimits[2]);
    glVertex3f(0.5*soundLimits[0], -0.5*soundLimits[1], 0.5*soundLimits[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.5*soundLimits[0], -0.5*soundLimits[1], 0.5*soundLimits[2]);
    glVertex3f(0.5*soundLimits[0], -0.5*soundLimits[1], -0.5*soundLimits[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(0.5*soundLimits[0], -0.5*soundLimits[1], -0.5*soundLimits[2]);
    glVertex3f(-0.5*soundLimits[0], -0.5*soundLimits[1], -0.5*soundLimits[2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-0.5*soundLimits[0], -0.5*soundLimits[1], -0.5*soundLimits[2]);
    glVertex3f(-0.5*soundLimits[0], -0.5*soundLimits[1], 0.5*soundLimits[2]);
    glEnd();
    glPopMatrix();
    
}


void ConcertRoom::createColorsVec(){
    
    colorsVec.clear();
    
    colorsVec.push_back(ofVec4f(220, 20, 60, 255));
    colorsVec.push_back(ofVec4f(255, 110, 180, 255));
    colorsVec.push_back(ofVec4f(72, 118, 255, 255));
    colorsVec.push_back(ofVec4f(0, 238, 118, 255));
    colorsVec.push_back(ofVec4f(255, 236, 139, 255));
    colorsVec.push_back(ofVec4f(255, 153, 18, 255));
    colorsVec.push_back(ofVec4f(50, 205, 50, 255));
    colorsVec.push_back(ofVec4f(0, 255, 255, 255));
    colorsVec.push_back(ofVec4f(99, 184, 255, 255));
    colorsVec.push_back(ofVec4f(238, 0, 238, 255));
    colorsVec.push_back(ofVec4f(255, 127, 80, 255));
    colorsVec.push_back(ofVec4f(255, 0, 255, 255));
    colorsVec.push_back(ofVec4f(255, 255, 255, 255));
    colorsVec.push_back(ofVec4f(113, 198, 113, 255));
    colorsVec.push_back(ofVec4f(198, 113, 113, 255));
    colorsVec.push_back(ofVec4f(113, 113, 198, 255));
    colorsVec.push_back(ofVec4f(152, 251, 152, 255));
    colorsVec.push_back(ofVec4f(70, 130, 180, 255));
    colorsVec.push_back(ofVec4f(192, 255, 62, 255));
    colorsVec.push_back(ofVec4f(171, 130, 255, 255));
    
    for(int i=0; i<colorsVec.size(); i++){
        colorsVec[i] = colorsVec[i]/255.;
    }
    
}

ofVec4f ConcertRoom::getNextColor(){
    currentColorIndex++;
    if(currentColorIndex >= colorsVec.size()){
        currentColorIndex = 0;
    }
    return colorsVec[currentColorIndex];
}




















