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

#include "farfalharSystem.h"

FarfalharSystem::FarfalharSystem(){
	
}
FarfalharSystem::FarfalharSystem(ConcertRoom* cr, std::string ns, int np){
	setup(cr, ns, np);
}
FarfalharSystem::~FarfalharSystem(){
	
}

void FarfalharSystem::customSetup(){
	for(int i=0; i<numParticles; i++){
        particles->push_back(new FarfalharParticle(this, i+1));
    }
    
    redraw = 0;
    collapse = false;
    nota = "nada";
}
void FarfalharSystem::customUpdate(){
	if(play){
        for(int i=0; i<particles->size(); i++){
            
            
            static_cast<FarfalharParticle*>((*particles)[i])->redraw(redraw);
            (*particles)[i]->update();
            if(collapse){
                static_cast<FarfalharParticle*>((*particles)[i])->collapse(nota);
            }
            
        }
    }
    
    redraw = 0;
    collapse = false;
    nota = "nada";
    
}


void FarfalharSystem::customDraw(){
    //drawLimits();
}


t_jit_err FarfalharSystem::messageControl(long argc, t_atom* argv){
    std::string task;
    task = jit_atom_getsym(argv)->s_name;
    
    
    if(task == "setMaxBeating"){
        if(argc == 2){
            if(argv){
                for(int i=0; i<particles->size(); i++){
                    static_cast<FarfalharParticle*>((*particles)[i])->setMaxBeating(atom_getfloat(argv + 1));
                }
            }
        }
    }
    else if(task == "setBeatingSpeed"){
        if(argc == 2){
            if(argv){
                for(int i=0; i<particles->size(); i++){
                    static_cast<FarfalharParticle*>((*particles)[i])->setBeatingSpeed(atom_getfloat(argv + 1));
                }
            }
        }
    }
    else if(task == "setResolutionProbability"){
        if(argc == 2){
            if(argv){
                for(int i=0; i<particles->size(); i++){
                    static_cast<FarfalharParticle*>((*particles)[i])->setResolutionProb(atom_getfloat(argv + 1));
                }
            }
        }
    }
    else if(task == "setNotes"){
        if(argc == 9){
            if(argv){
                for(int i=0; i<particles->size(); i++){
                    static_cast<FarfalharParticle*>((*particles)[i])->setNotes(argc - 1, argv + 1);
                }
            }
        }
    }
    
    else if(task == "redraw"){
        if(argc == 2){
            if(argv){
                redraw = atom_getlong(argv + 1);
            }
        }
    }
    else if(task == "collapse"){
        if(argc == 2){
            if(argv){
                collapse = true;
                int collapseArg = atom_getlong(argv + 1);
                
                switch(collapseArg){
                    case 0:
                        collapse = true;
                        nota = "G#3";
                        break;
                    case 1:
                        collapse = true;
                        nota = "Bb3";
                        break;
                    case 2:
                        collapse = true;
                        nota = "D4";
                        break;
                    case 3:
                        collapse = true;
                        nota = "F#4";
                        break;
                    case 4:
                        collapse = true;
                        nota = "G4";
                        break;
                    case 5:
                        collapse = true;
                        nota = "C5";
                        break;
                    case 6:
                        collapse = true;
                        nota = "E5";
                        break;
                    case 7:
                        collapse = true;
                        nota = "A5";
                        break;
                    case 8:
                        collapse = true;
                        nota = "G3_2";
                        break;
                    case 9:
                        collapse = true;
                        nota = "F#4_2";
                        break;
                    case 10:
                        collapse = true;
                        nota = "D5_2";
                        break;
                    case 11:
                        collapse = true;
                        nota = "E5_2";
                        break;
                    case 12:
                        collapse = true;
                        nota = "A#5_2";
                        break;
                    case 13:
                        collapse = true;
                        nota = "B4_3";
                        break;
                }
            }
        }
        
        return JIT_ERR_NONE;
    }
    
    pSystem::messageControl(argc, argv);
    
    return JIT_ERR_INVALID_INPUT;
}