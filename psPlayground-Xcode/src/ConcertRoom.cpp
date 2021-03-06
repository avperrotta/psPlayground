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

#include "ConcertRoom.h"


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


t_jit_err ConcertRoom::setBounds(long argc, t_atom* argv){
    if(argv){
        if(argc == 4){
            roomBounds[0] = jit_atom_getfloat(argv + 1);
            roomBounds[1] = jit_atom_getfloat(argv + 2);
            roomBounds[2] = jit_atom_getfloat(argv + 3);
            
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
            
            return JIT_ERR_NONE;
        }
    }
    
    return JIT_ERR_INVALID_INPUT;
    
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


t_jit_err ConcertRoom::setNumSpeakers(long argc, t_atom* argv){
    if(argv){
        if(argc == 2){
            int ns = jit_atom_getlong(argv + 1);
            if(ns > numSpeakers){
                for(int i=0; i<(ns - numSpeakers); i++){
                    speakers->push_back(new Speaker(i+1, 0., 0., 0.));
                }
                numSpeakers = speakers->size();
                return JIT_ERR_NONE;
            }
            else if(ns < numSpeakers && ns > 0){
                while(speakers->size() > ns){
                    delete speakers->back();
                    speakers->pop_back();
                }
                
                numSpeakers = speakers->size();
                return JIT_ERR_NONE;
            }
        }
    }
    
    return JIT_ERR_INVALID_INPUT;
}

t_jit_err ConcertRoom::setSpeakerPosition(long argc, t_atom* argv){
    
    if(argv){
        if(argc == 5){
            if(speakers->size() > 0){
                int sn = jit_atom_getlong(argv + 1);
                //post("setting %d", sn);
                if(sn >= 1 && sn <= numSpeakers){
                    post("setting speaker %d position = %lf %lf %lf", sn, jit_atom_getfloat(argv + 2), jit_atom_getfloat(argv + 3), jit_atom_getfloat(argv + 4));
                    (*speakers)[sn - 1]->setPosition(jit_atom_getfloat(argv + 2), jit_atom_getfloat(argv + 3), jit_atom_getfloat(argv + 4));
                    (*speakers)[sn - 1]->scalePosition(getBounds());
                    return JIT_ERR_NONE;
                }
                post("choose speaker number first !!!!");
                return JIT_ERR_INVALID_INPUT;
            }
        }
    }
    post("set the number of speakers first !!!!   (msg = psp setNumSpeakers int)");
    return JIT_ERR_INVALID_INPUT;
}

t_jit_err ConcertRoom::setSpeakerCalibration(long argc, t_atom* argv){
    if(argv){
        if(argc >= 5){
            for(int i=0; i< speakers->size(); i++){
                post("setting speaker %d gain calibration", i + 1);
                (*speakers)[i]->setSpeakerCalibration(argc - 1, argv + 1);
            }
        }
        return JIT_ERR_NONE;
    }
    return JIT_ERR_INVALID_INPUT;
    
    
}

t_jit_err ConcertRoom::setReverbGain(long argc, t_atom* argv){
    if(argv){
        if(argc >= 5){
            if(reverbGain){
                argc--;
                argv++;
                while(!reverbGain->empty()){
                    delete reverbGain->back();
                    reverbGain->pop_back();
                }
                reverbGain->clear();
                post("setting reverb gain calibration");
                for(int i=0; i<argc; i+=2){
                    reverbGain->push_back(new ofVec2f(jit_atom_getfloat(argv+i), jit_atom_getfloat(argv+i+1)));
                }
                for(int i=0; i<reverbGain->size(); i++){
                    post("%lf %lf", (*reverbGain)[i]->x, (*reverbGain)[i]->y);
                }
                return JIT_ERR_NONE;
            }
        }
    }
    return JIT_ERR_INVALID_INPUT;
}

vector<ofVec2f*>* ConcertRoom::getReverbGain(){
    return reverbGain;
}

t_jit_err ConcertRoom::setReverbSize(long argc, t_atom* argv){
    if(argv){
        if(argc >= 5){
            if(reverbSize){
                argc--;
                argv++;
                while(!reverbSize->empty()){
                    delete reverbSize->back();
                    reverbSize->pop_back();
                }
                reverbSize->clear();
                post("setting reverb size calibration");
                for(int i=0; i<argc; i+=2){
                    reverbSize->push_back(new ofVec2f(jit_atom_getfloat(argv+i), jit_atom_getfloat(argv+i+1)));
                }
                for(int i=0; i<reverbSize->size(); i++){
                    post("%lf %lf", (*reverbSize)[i]->x, (*reverbSize)[i]->y);
                }
                return JIT_ERR_NONE;
            }
        }
    }
    return JIT_ERR_INVALID_INPUT;
}

vector<ofVec2f*>* ConcertRoom::getReverbSize(){
    return reverbSize;
}

void ConcertRoom::draw(){
    
    
    //draw speakers;
    for(int i=0; i<speakers->size(); i++){
        (*speakers)[i]->draw();
    }
    
    
    
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




















