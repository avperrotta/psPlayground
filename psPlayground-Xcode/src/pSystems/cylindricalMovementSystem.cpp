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

#include "cylindricalMovementSystem.h"

CylindricalMovementSystem::CylindricalMovementSystem(){
	
}
CylindricalMovementSystem::CylindricalMovementSystem(ConcertRoom* cr, std::string ns, int np){
	setup(cr, ns, np);
}
CylindricalMovementSystem::~CylindricalMovementSystem(){
	
}

void CylindricalMovementSystem::customSetup(){
	for(int i=0; i<numParticles; i++){
        particles->push_back(new CylindricalMovementParticle(this, i+1));
    }
}
void CylindricalMovementSystem::customUpdate(){
	if(play){
        for(int i=0; i<particles->size(); i++){
            (*particles)[i]->update();
        }
    }
    
}
void CylindricalMovementSystem::customDraw(){
    drawLimits();
}


t_jit_err CylindricalMovementSystem::messageControl(long argc, t_atom* argv){
	std::string task;
    task = jit_atom_getsym(argv)->s_name;
    
    if(task == "setDirection"){
        if(argc == 2){
            for(int i=0; i<numParticles; i++){
                static_cast<CylindricalMovementParticle*>((*particles)[i])->setDirection(argv + 1);
            }
            //post("direction set for %s system: %d", name.c_str(), atom_getlong(argv + 1));
        }
        else if(argc == 3){
            int j = atom_getlong(argv + 1);
            if(j > 0 && j <= particles->size()){
                static_cast<CylindricalMovementParticle*>((*particles)[j-1])->setDirection(argv + 2);
            }
        }
        
        
    }
    else if(task == "setHeight"){
        if(argc == 2){
            for(int i=0; i<numParticles; i++){
                static_cast<CylindricalMovementParticle*>((*particles)[i])->setHeight(argv + 1);
            }
        }
        else if(argc == 3){
            int j = atom_getlong(argv + 1);
            if(j > 0 && j <= particles->size()){
                static_cast<CylindricalMovementParticle*>((*particles)[j-1])->setHeight(argv + 2);
            }
        }
    }
    else if(task == "setHeightSpeed"){
        if(argc == 2){
            for(int i=0; i<numParticles; i++){
                static_cast<CylindricalMovementParticle*>((*particles)[i])->setHeightSpeed(argv + 1);
            }
        }
        else if(argc == 3){
            int j = atom_getlong(argv + 1);
            if(j > 0 && j <= particles->size()){
                static_cast<CylindricalMovementParticle*>((*particles)[j-1])->setHeightSpeed(argv + 2);
            }
        }
    }
    
    
    pSystem::messageControl(argc, argv);
    
    return JIT_ERR_INVALID_INPUT;
}

void CylindricalMovementSystem::addParticles(t_atom* argv){
    int np = atom_getlong(argv);
    
    for(int i=0; i<np; i++){
        if(particles->size() < maxNumParticles){
            particles->push_back(new CylindricalMovementParticle(this, particles->size() + i+1));
        }
    }
    
    numParticles = particles->size();
}
