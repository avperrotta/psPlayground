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

#ifndef __psPlayground__pSystem__
#define __psPlayground__pSystem__

#include <iostream>
#include <string>
#include "Particle.h"
#include "ConcertRoom.h"
#include "jit.common.h"
#include "jit.gl.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_strings.h"
#include "ext_common.h"
#include "ext_systhread.h"
#include "pspGlobals.h"
#include "ofVectorMath.h"

extern std::string absPath;

class pSystem{
public:
    
    pSystem();
    pSystem(ConcertRoom* cr, std::string ns, int np);
    virtual ~pSystem();
    
    virtual void setup();
    virtual void setup(ConcertRoom* cr, std::string ns, int np);
    virtual void customSetup();
    virtual void update();
    virtual void customUpdate();
    virtual void draw();
    virtual void customDraw();
    virtual void addParticles(int num);
    virtual void killParticles(int num);
    
    virtual t_jit_err messageControl(long argc, t_atom* argv);
    
    virtual void createOutput();
    
    std::string name;
    std::string getName();
    
    ConcertRoom* concertRoom;
    ConcertRoom* getConcertRoom();
    
    vector<Particle*>* particles;
    
    int numParticles;
    int maxNumParticles;
    
    bool outputRaw;
    bool outputDbap;
    
    int currentTime;
    int previousTime;
    
    ofVec4f color;
    ofVec4f getColor();
    
    
    void restart();
    bool stop;
    bool play;
    
    limits lx;
    limits ly;
    limits lz;
    void setLimits(long argc, t_atom* argv);
    void drawLimits();
    
    
    //trajectory recording
	std::string recFilesPath;
	std::string getRecFilesPath();
    
};

#endif /* defined(__psPlayground__pSystem__) */
