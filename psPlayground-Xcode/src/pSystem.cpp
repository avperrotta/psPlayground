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

#include "pSystem.h"

std::string absPath;


pSystem::pSystem(){
    setup();
}

pSystem::pSystem(ConcertRoom* cr, std::string ns, int np){
    setup(cr, ns, np);
    
}


pSystem::~pSystem(){
    if(particles){
        while(!particles->empty()){
            delete particles->back();
            particles->pop_back();
        }
        delete particles;
    }
}


void pSystem::setup(){
    
}

void pSystem::customSetup(){
    
}

void pSystem::setup(ConcertRoom* cr, std::string ns, int np){
    
    particles = new vector<Particle*>();
    concertRoom = cr;
    
    maxNumParticles = 1000;
    numParticles = np;
    name = ns;
    
    if(numParticles > maxNumParticles){
        numParticles = maxNumParticles;
    }
    
    currentTime = gettime();
    previousTime = gettime();
    
    if(concertRoom){
        color = concertRoom->getNextColor();
    }
    else{
        color = ofVec4f(0., 1., 0., 1.);
    }
    
    play = true;
    
    recFilesPath = "/";
    
    customSetup();
}

void pSystem::update(){
    previousTime = currentTime;
    currentTime = gettime();
    
    customUpdate();
}

void pSystem::customUpdate(){
    
}

void pSystem::draw(){
    for(int i=0; i<particles->size(); i++){
        (*particles)[i]->draw();
    }
    
    customDraw();
}

void pSystem::customDraw(){
    
}

void pSystem::addParticles(int num){
    
}

void pSystem::killParticles(int num){
    
}

t_jit_err pSystem::messageControl(long argc, t_atom *argv){
    std::string task;
    task = jit_atom_getsym(argv)->s_name;
    
    
    
    if(task == "start"){
        play = true;
        return JIT_ERR_NONE;
    }
    else if(task == "stop"){
        play = false;
        return JIT_ERR_NONE;
    }
    else if(task == "restart"){
        restart();
        return JIT_ERR_NONE;
    }
    else if(task == "recMode"){
		if(argc == 3){
			if(argv){
				int pi = atom_getlong(argv+1) - 1;
				if(pi >= 0 && pi < particles->size()){
					(*particles)[pi]->setRecMode(1, argv + 2);
				}
				
			}
		}
	}
	else if(task == "playRec"){
		if(argc == 3){
			if(argv){
				int pi = atom_getlong(argv+1) - 1;
				if(pi >= 0 && pi < particles->size()){
					(*particles)[pi]->setPlayRec(1, argv + 2);
				}
			}
		}
	}
    else if(task == "saveRec"){
		if(argc == 3){
			if(argv){
				int pi = atom_getlong(argv+1) - 1;
				if(pi >= 0 && pi < particles->size()){
					(*particles)[pi]->saveRec(atom_getsym(argv + 2)->s_name);
				}
			}
		}
	}
	else if(task == "loadRec"){
		if(argc == 3){
			if(argv){
				int pi = atom_getlong(argv+1) - 1;
				if(pi >= 0 && pi < particles->size()){
					(*particles)[pi]->loadRec(atom_getsym(argv + 2)->s_name);
				}
			}
		}
	}
	else if(task == "triggerTrajectory"){
		if(argc == 2){
			if(argv){
				for(int i=0; i<numParticles; i++){
                    (*particles)[i]->triggerTrajectory(argv + 1);
                }
			}
		}
	}
    else if(task == "setLimits"){
        if(argc == 7){
            if(argv){
                setLimits(argc - 1, argv + 1);
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setSizeLimits(argv + 1);
                }
                /*
                post("size limits set for %s system:", name.c_str(), argv);
                postatom(argv + 1);
                postatom(argv + 2);
                postatom(argv + 3);
                postatom(argv + 4);
                postatom(argv + 5);
                postatom(argv + 6);
                */
                
            }
        }
        
        return JIT_ERR_NONE;
    }
	else if(task == "setInitialPositionCartezian"){
		if(argc == 4){
			if(argv){
				for(int i=0; i<numParticles; i++){
					(*particles)[i]->setPosCarIni(argv + 1);
				}
			}
		}
	}
	else if(task == "setFinalPositionCartezian"){
		if(argc == 4){
			if(argv){
				for(int i=0; i<numParticles; i++){
					(*particles)[i]->setPosCarFinal(argv + 1);
				}
			}
		}
	}
	else if(task == "setInitialPositionPolar"){
		if(argc == 4){
			if(argv){
				for(int i=0; i<numParticles; i++){
					(*particles)[i]->setPosRadIni(argv + 1);
				}
			}
		}
	}
	else if(task == "setFinalPositionPolar"){
		if(argc == 4){
			if(argv){
				for(int i=0; i<numParticles; i++){
					(*particles)[i]->setPosRadFinal(argv + 1);
				}
			}
		}
	}
    
    else if(task == "setSpeed"){
        if(argc == 2){
            if(argv){
                
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setSpeed(argc - 1, argv + 1);
                }
                //post("setting speed for %s: %lf", name.c_str(), atom_getfloat(argv + 1));
            }
        }
        else if(argc == 4){
            for(int i=0; i<numParticles; i++){
                (*particles)[i]->setSpeed(argc - 1, argv + 1);
            }
            //post("setting speed for %s: %lf %lf %lf", name.c_str(), atom_getfloat(argv + 1), atom_getfloat(argv + 2), atom_getfloat(argv + 3));
        }
        
        return JIT_ERR_NONE;
    }
    else if(task == "setInitialSpeed"){
        if(argc == 2){
            if(argv){
                
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setInitialSpeed(argc - 1, argv + 1);
                }
                //post("setting speed for %s: %lf", name.c_str(), atom_getfloat(argv + 1));
            }
        }
        else if(argc == 4){
            for(int i=0; i<numParticles; i++){
                (*particles)[i]->setInitialSpeed(argc - 1, argv + 1);
            }
            //post("setting speed for %s: %lf %lf %lf", name.c_str(), atom_getfloat(argv + 1), atom_getfloat(argv + 2), atom_getfloat(argv + 3));
        }
        
        return JIT_ERR_NONE;
    }
    else if(task == "setOffset"){
        if(argc == 4){
            if(argv){
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setOffset(argv + 1);
                }
                //post("setting offset for %s", name.c_str());
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setRadius"){
        if(argc == 2){
            if(argv){
                
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setRadius(argv + 1);
                }
                //post("setting radius for %s: %lf", name.c_str(), atom_getfloat(argv + 1));
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setTheta"){
        if(argc == 2){
            if(argv){
                
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setTheta(argv + 1);
                }
                //post("setting Theta for %s: %lf", name.c_str(), atom_getfloat(argv + 1));
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setPhi"){
        if(argc == 2){
            if(argv){
                
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setPhi(argv + 1);
                }
                //post("setting Phi for %s: %lf", name.c_str(), atom_getfloat(argv + 1));
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setRadiusSpeed"){
        if(argc == 2){
            if(argv){
                
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setRadiusSpeed(argv + 1);
                }
                //post("setting radius speed for %s: %lf", name.c_str(), atom_getfloat(argv + 1));
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setThetaSpeed"){
        if(argc == 2){
            if(argv){
                
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setThetaSpeed(argv + 1);
                }
                //post("setting Theta speed for %s: %lf", name.c_str(), atom_getfloat(argv + 1));
            }
        }
        return JIT_ERR_NONE;
    }
    else if(task == "setPhiSpeed"){
        if(argc == 2){
            if(argv){
                
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setPhiSpeed(argv + 1);
                }
                //post("setting Phi speed for %s: %lf", name.c_str(), atom_getfloat(argv + 1));
            }
        }
        return JIT_ERR_NONE;
    }
    
    else if(task == "setRandomness"){
        if(argc == 2){
            if(argv){
                
                for(int i=0; i<numParticles; i++){
                    (*particles)[i]->setRandomness(atom_getfloat(argv + 1));
                }
                //post("setting randomness for %s: %lf", name.c_str(), atom_getfloat(argv + 1));
            }
        }
        return JIT_ERR_NONE;
    }
    
    return JIT_ERR_INVALID_INPUT;
}

void pSystem::createOutput(){
    
}

ConcertRoom* pSystem::getConcertRoom(){
    if(concertRoom){
        return concertRoom;
    }
    return NULL;
}

std::string pSystem::getName(){
    return name;
}

ofVec4f pSystem::getColor(){
    return color;
}

std::string pSystem::getRecFilesPath(){
	return recFilesPath;
}

void pSystem::restart(){
    for(int i=0; i<particles->size(); i++){
        (*particles)[i]->restart();
    }
}

void pSystem::setLimits(long argc, t_atom *argv){
    if(argc == 6){
        if(argv){
            lx.min = atom_getfloat(argv + 0);
            lx.max = atom_getfloat(argv + 1);
            ly.min = atom_getfloat(argv + 2);
            ly.max = atom_getfloat(argv + 3);
            lz.min = atom_getfloat(argv + 4);
            lz.max = atom_getfloat(argv + 5);
        }
    }
}


void pSystem::drawLimits(){
    glPushMatrix();
    glColor4f(color.x, color.y, color.z, color.w);
    
    //floor
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.min, lz.max);
    glVertex3f(lx.max, ly.min, lz.max);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.min, lz.max);
    glVertex3f(lx.max, ly.min, lz.min);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.min, lz.min);
    glVertex3f(lx.min, ly.min, lz.min);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.min, lz.min);
    glVertex3f(lx.min, ly.min, lz.max);
    glEnd();
    
    //ceiling
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.max, lz.max);
    glVertex3f(lx.max, ly.max, lz.max);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.max, lz.max);
    glVertex3f(lx.max, ly.max, lz.min);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.max, lz.min);
    glVertex3f(lx.min, ly.max, lz.min);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.max, lz.min);
    glVertex3f(lx.min, ly.max, lz.max);
    glEnd();
    
    //walls
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.max, lz.max);
    glVertex3f(lx.min, ly.min, lz.max);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.max, lz.max);
    glVertex3f(lx.max, ly.min, lz.max);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.max, lz.min);
    glVertex3f(lx.max, ly.min, lz.min);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.max, lz.min);
    glVertex3f(lx.min, ly.min, lz.min);
    glEnd();
    
    glPopMatrix();
}


















