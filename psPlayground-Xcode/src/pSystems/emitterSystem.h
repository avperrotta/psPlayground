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

#ifndef __psPlayground__emitterSytem__
#define __psPlayground__emitterSytem__

#include <iostream>
#include "jit.common.h"
#include "jit.gl.h"
#include "pSystem.h"
#include "pspGlobals.h"
#include "mathUtils.h"
#include "ofVectorMath.h"
#include "emitterParticle.h"
#include "emitterSource.h"
#include "attractorParticle.h"

#define MAX_NUM_EMITTER_PARTICLES 1000


class EmitterSystem : public pSystem{
public:
    
    EmitterSystem();
    EmitterSystem(ConcertRoom* cr, std::string ns, int np);
    ~EmitterSystem();
    
    void customSetup();
    void customUpdate();
    void customDraw();
    
    t_jit_err messageControl(long argc, t_atom* argv);
    
    EmitterSource* src;
    EmitterSource* getSrc();
    
    double birthRate;
    double birthProbability;
    int birthSize;
    int birthTrigger;
    
    void injectParticles(t_atom* argv);
    void injectParticles(int np);
    
    bool autoEmitter;
    void birthController();
    
    void setBirthRate(t_atom* argv);
    void setBirthProbability(t_atom* argv);
    void setBirthSize(t_atom* argv);
    
    int freeIndex[MAX_NUM_EMITTER_PARTICLES][2];
    int getFreeIndex();
    
};

#endif /* defined(__psPlayground__emitterSytem__) */
