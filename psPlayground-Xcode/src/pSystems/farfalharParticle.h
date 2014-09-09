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

#ifndef __psPlayground__farfalharParticle__
#define __psPlayground__farfalharParticle__

#include <iostream>
#include "jit.common.h"
#include "jit.gl.h"
#include "Particle.h"
#include "ofVectorMath.h"
#include "mathUtils.h"
#include "ConcertRoom.h"


class FarfalharParticle : public Particle{
public:
    
    FarfalharParticle();
    FarfalharParticle(pSystem* sys, int ind);
    ~FarfalharParticle();
    
    void customSetup();
    void customUpdate();
    void draw();
    void outputSpecificRoutine();
    
    
    //void
    void customRestart();
    void setBaseNotes();
    void setupNotes();
    float notes[40];
	float notes2[66];
	float notes3[40];
    int conjunto;
    int stayCounter;
    double note;
    double beatingNote;
    double beating;
    double beatingSpeed;
    double maxBeating;
    void setMaxBeating(double mb);
    void setBeatingSpeed(double bs);
    double resolutionProbability;
    void setResolutionProb(double rp);
    double resolutionIndexes[8];
    
    double collapseRadius;
    int gainStatus;
    
    void rollDice();
    void redraw(int r);
    void collapse(std::string n);
    
    void setNotes(long argc, t_atom* argv);
    
    float amp1;
	float amp2;
	float amp3;
	float amp4;
    
    double ea1;
    double ea2;
    double ea3;
    double ea4;
    double ea5;
    double ea6;
    double ea7;
    
};

#endif /* defined(__psPlayground__farfalharParticle__) */
