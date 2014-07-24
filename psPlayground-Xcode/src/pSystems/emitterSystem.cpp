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
    
    autoEmitter = true;
    birthTrigger = 0.;
    birthRate = 100.;
    birthProbability = 1.;
    birthSize = 1;
    
    particles->clear();
    attractors->clear();
    
}
void EmitterSystem::customUpdate(){
	if(play){
        
        birthController();
        
        for(int i=0; i<particles->size(); i++){
            (*particles)[i]->update();
            if((*particles)[i]->status == 0){
                delete (*particles)[i];
                particles->erase(particles->begin() + i);
            }
        }
    }
}

void EmitterSystem::injectParticles(t_atom *argv){
    int np = atom_getlong(argv);
    injectParticles(np);
}

void EmitterSystem::injectParticles(int np){
    
    
    for(int i=0; i<np; i++){
        if(particles->size() < MAX_NUM_EMITTER_PARTICLES){
            particles->push_back(new EmitterParticle(this, particles->size()+1));
        }
        else {
            break;
        }
        
    }
}

void EmitterSystem::birthController(){
    if(autoEmitter){
        if((currentTime - birthTrigger) >= birthRate){
            birthTrigger = currentTime;
            if(rangedRandom(0., 1.) <= birthProbability){
                injectParticles(birthSize);
            }
        }
    }
}

void EmitterSystem::customDraw(){
    src->draw();
}

void EmitterSystem::setBirthRate(t_atom *argv){
    birthRate = crop(atom_getfloat(argv), 0., atom_getfloat(argv));
}

void EmitterSystem::setBirthProbability(t_atom *argv){
    birthProbability = crop(atom_getfloat(argv), 0., 1.);
}

void EmitterSystem::setBirthSize(t_atom *argv){
    birthSize = (int)crop(atom_getfloat(argv), 1., 1000.);
}



t_jit_err EmitterSystem::messageControl(long argc, t_atom* argv){
	std::string task;
    task = jit_atom_getsym(argv)->s_name;
    
    if(task == "setBirthRate"){
        if(argv){
            if(argc == 2){
                setBirthRate(argv + 1);
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setBirthProbability"){
        if(argv){
            if(argc == 2){
                setBirthProbability(argv + 1);
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setBirthSize"){
        if(argv){
            if(argc == 2){
                setBirthSize(argv + 1);
            }
        }
        return JIT_ERR_NONE;
    }
    
    
    else if(task == "setSourceHorizontalEmittingRange"){
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
    else if(task == "setSourcePosition"){
        if(argv){
            if(argc == 4){
                src->setPos(argv + 1);
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setLifeLimits"){
        if(argv){
            if(argc == 3){
                src->setLifeLimits(argv + 1);
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setAutoEmitter"){
        if(argv){
            if(argc == 2){
                autoEmitter = atom_getlong(argv + 1);
            }
        }
    }
    else if(task == "injectParticles"){
        if(argv){
            if(argc == 2){
                int np = (int)crop(atom_getfloat(argv + 1), 1., atom_getfloat(argv + 1));
                injectParticles(np);
            }
        }
    }
    
    pSystem::messageControl(argc, argv);
    
    return JIT_ERR_INVALID_INPUT;
}

EmitterSource* EmitterSystem::getSrc(){
    return src;
}







