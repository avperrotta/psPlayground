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

#include "emitterSystem.h"

EmitterSystem::EmitterSystem(){
	
}
EmitterSystem::EmitterSystem(ConcertRoom* cr, std::string ns, int np){
	setup(cr, ns, np);
}
EmitterSystem::~EmitterSystem(){
	delete src;
}

void EmitterSystem::customSetup(){
    
    src = new EmitterSource(this, 1);
    src->setPos(ofVec3f((lx.min+lx.max)*0.5, (ly.min+ly.max)*0.5, (lz.min+lz.max)*0.5));
    
    particles->clear();
    
    /*
	for(int i=0; i<numParticles; i++){
        particles->push_back(new EmitterParticle(this, i+1));
    }
    */
}
void EmitterSystem::customUpdate(){
	if(play){
        
        if(rangedRandom(0., 10.) > 5.){
            particles->push_back(new EmitterParticle(this, particles->size()+1));
        }
        
        
        for(int i=0; i<particles->size(); i++){
            (*particles)[i]->update();
            if((*particles)[i]->status == 0){
                delete (*particles)[i];
                particles->erase(particles->begin() + i);
            }
        }
    }
    
}
void EmitterSystem::customDraw(){
    src->draw();
    drawLimits();
}
t_jit_err EmitterSystem::messageControl(long argc, t_atom* argv){
	std::string task;
    task = jit_atom_getsym(argv)->s_name;
    
    if(task == "setSourceHorizontalEmittingRange"){
        if(argv){
            if(argc == 3){
                src->setHorizontalRange(argv + 1);
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setSourceVerticalEmittingRange"){
        if(argv){
            if(argc == 3){
                src->setVerticalRange(argv + 1);
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setSourceSpeedRange"){
        if(argv){
            if(argc == 3){
                src->setSpeedRange(argv + 1);
            }
        }
        return JIT_ERR_NONE;
    }
    
    pSystem::messageControl(argc, argv);
    
    return JIT_ERR_INVALID_INPUT;
}

EmitterSource* EmitterSystem::getSrc(){
    return src;
}

void EmitterSystem::setLimits(t_atom *argv){
    if(argv){
        lx.min = atom_getfloat(argv + 0);
        lx.max = atom_getfloat(argv + 1);
        ly.min = atom_getfloat(argv + 2);
        ly.max = atom_getfloat(argv + 3);
        lz.min = atom_getfloat(argv + 4);
        lz.max = atom_getfloat(argv + 5);
    }
    
    src->setPos(ofVec3f((lx.min+lx.max)*0.5, (ly.min+ly.max)*0.5, (lz.min+lz.max)*0.5));
}





