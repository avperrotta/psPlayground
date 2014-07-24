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

#include "Particle.h"
#include "pspGlobals.h"
#include "ConcertRoom.h"
#include "pSystem.h"
#include "attractorParticle.h"

Particle::Particle(){
    
    setup();
}

Particle::Particle(pSystem* sys, int ind){
    setup(sys, ind);
}

Particle::~Particle(){
    
    gain = 0.0;
    outputEnvRoutine();
    
    if(dbap){
        delete dbap;
    }
    
}


void Particle::setup(){
    
}

void Particle::setup(pSystem* sys, int ind){
    
    mySystem = sys;
    concertRoom = mySystem->getConcertRoom();
    systemName = mySystem->getName();
    index = ind;
    
    coordinateSystem = "cartesian";
    
    
	updateByTime = false;
    onTrajectory = false;
    trajectoryFinished = false;
    trajectoryLoopType = 2;
    
    useDbap = false;
    outputDbap = false;
    
    if(concertRoom){
        dbap = new Dbap(concertRoom, this);
        useDbap = true;
        outputDbap = true;
    }
    else{
        dbap = new Dbap();
    }
    outputRaw = true;
    outputEnv = true;
    outputSpecific = false;
    gain = 1.;
    
    width = 0.02;
    
    easingLimits_x.min = 0.01;
    easingLimits_x.max = 0.2;
    easingLimits_y.min = 0.01;
    easingLimits_y.max = 0.2;
    easingLimits_z.min = 0.01;
    easingLimits_z.max = 0.2;
    
    color = mySystem->getColor();
    //post("%lf %lf %lf", color.x, color.y, color.z, color.w);
    
    
    
    //recording stuff
	recMode = false;
	playRec = false;
	playRecHead = 0;
	recFileName = mySystem->recFilesPath + mySystem->getName() + ofToString(index) + ".txt";
	//post("recFileName = %s", recFileName.c_str());
	//loadRec(recFileName);
	
	
	randomness = 0.2;
	
    customSetup();
    
}

void Particle::customSetup(){
    
}

void Particle::reset(){
    
}

void Particle::restart(){
    resetTime();
    onTrajectory = false;
    recMode = false;
	playRec = false;
    customRestart();
}


void Particle::customRestart(){
	
}

void Particle::resetTime(){
	initialTime = (double)gettime();
    currentTime = (double)gettime();
    previousTime = currentTime;
    dTime = 0;
    lifeTime = 0;
}

void Particle::update(){
    
    
    updateTime();
    
    if(playRec){
		recUpdate();
	}
	else{
		if(onTrajectory){
			trajectoryControl();
		}
		else{
			customUpdate();
		}
		
	}
    
	
	if(recMode){
		rec.push_back(timedPos(currentTime, posCar.x, posCar.y, posCar.z));
	}
    
    
    if(useDbap){
        if(dbap){
            dbap->update();
        }
    }
    
    createOutput();
    
}

void Particle::updateTime(){
    dTime = (double)gettime() - previousTime;
    lifeTime = (double)gettime() - initialTime;
    previousTime = currentTime;
    currentTime = (double)gettime();
	//post("lifeTime = %lf", lifeTime);
}

void Particle::createOutput(){
    //post("outputting %s %d", systemName.c_str(), index);
    
    outputEnvRoutine();
    outputRawRoutine();
    outputDbapRoutine();
    outputSpecificRoutine();
}

void Particle::outputDbapRoutine(){
    if(outputDbap){
        if(dbap){
            dbapGains = dbap->getDbap();
            
            
            t_atom* aux;
            
            aux = new t_atom[dbapGains->size() + 2];
            
            atom_setsym(aux, gensym(systemName.c_str()));
            
            atom_setlong(aux + 1, index);
            
            
            for(int i=0; i<dbapGains->size(); i++){
                atom_setfloat(aux + 2 + i, (*dbapGains)[i]);
            }
            
            
            if(superOutlet3 && aux){
                outlet_list(superOutlet3, 0L, dbapGains->size() + 2, aux);
            }
            
            delete[] aux;
            
            
            
        }
        
    }
}
void Particle::outputRawRoutine(){
    if(outputRaw){
        
        
        t_atom* aux;
        aux = new t_atom[5];
        atom_setsym(aux, gensym(systemName.c_str()));
        atom_setlong(aux + 1, index);
        atom_setfloat(aux + 2, posCar.x);
        atom_setfloat(aux + 3, posCar.y);
        atom_setfloat(aux + 4, posCar.z);
        
        
        if(superOutlet2 && aux){
            outlet_list(superOutlet2, 0L, 5, aux);
        }
        
        
        delete[] aux;
    }
}
void Particle::outputEnvRoutine(){
    if(outputEnv){
        t_atom* aux;
        aux = new t_atom[3];
        atom_setsym(aux, gensym(systemName.c_str()));
        atom_setlong(aux + 1, index);
        atom_setfloat(aux + 2, gain);
        
        if(superOutlet1 && aux){
            outlet_list(superOutlet1, 0L, 3, aux);
        }
        
        
        delete[] aux;
    }
}

void Particle::outputSpecificRoutine(){
    
}

void Particle::outputTrajectoryTriggerTriggers(){
    t_atom* aux;
    aux = new t_atom[3];
    atom_setsym(aux, gensym(systemName.c_str()));
    atom_setlong(aux + 1, index);
    atom_setsym(aux + 2, gensym("trajectoryFinished"));
    
    if(superOutlet5 && aux){
        outlet_list(superOutlet5, 0L, 3, aux);
    }
    
    
    delete[] aux;
}

void Particle::customUpdate(){
    
}

void Particle::draw(){
    //post("draw particle %lf %lf %lf", posCar.x, posCar.y, posCar.z);
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(color.x, color.y, color.z, gain);
    GLUquadricObj* Sphere;
    glTranslatef(posCar.x, posCar.y, posCar.z);
    Sphere = gluNewQuadric();
    gluSphere(Sphere, width, 4, 4);
    gluDeleteQuadric(Sphere);
    glDisable(GL_BLEND);
    glPopMatrix();
}



void Particle::triggerTrajectory(t_atom *argv){
	
    timeToLive = atom_getfloat(argv);
    onTrajectory = true;
    trajectoryFinished = false;
    resetTime();
    customRestart();
    
}

void Particle::triggerTrajectory(float ttl){
	
    timeToLive = ttl;
    onTrajectory = true;
    trajectoryFinished = false;
    resetTime();
    customRestart();
}


void Particle::trajectoryControl(){
    if(lifeTime >= timeToLive){
        if(!trajectoryFinished){
            outputTrajectoryTriggerTriggers();
        }
        trajectoryFinished = true;
        if(trajectoryLoopType > 0){
            resetTime();
            ofVec3f aux;
            
            if(trajectoryLoopType == 1){
                trajectoryFinished = false;
                
                if(coordinateSystem == "cartesian"){
                    posCar = posCarIni;
                }
                else{
                    posRad = posRadIni;
                }
                
                posOffset = posOffsetIni;
                
            }
            else if(trajectoryLoopType == 2){
                trajectoryFinished = false;
                
                
                if(coordinateSystem == "cartesian"){
                    aux = posCarIni;
                    posCarIni = posCarFinal;
                    posCarFinal = aux;
                    posCar = posCarIni;
                }
                else{
                    aux = posRadIni;
                    posRadIni = posRadFinal;
                    posRadFinal = aux;
                    posRad = posRadIni;
                }
                
                aux = posOffsetIni;
                posOffsetIni = posOffsetFinal;
                posOffsetFinal = aux;
                posOffset = posOffsetIni;
                
            }
        }
    }
    if(!trajectoryFinished){
        trajectoryUpdate();
    }
}

void Particle::trajectoryUpdate(){
    
}

void Particle::updateAttractorInfluence(){
    
    accel = ofVec3f(0., 0., 0.);
    if(attractors){
        for(int i=0; i<attractors->size(); i++){
            accel += (*attractors)[i]->calculateAttraction(posCar);
        }
    }
}

void Particle::setTrajectoryLoopType(t_atom *argv){
    
    int tlt = (int)crop(atom_getfloat(argv), 0, 2);
    trajectoryLoopType = tlt;
    
    triggerTrajectory(timeToLive);
    
}

void Particle::setSizeLimits(double x1, double x2, double y1, double y2, double z1, double z2){
    
}
void Particle::setSizeLimits(t_atom* argv){
    
	if(argv){
		limits_x.min = atom_getfloat(argv + 0);
		limits_x.max = atom_getfloat(argv + 1);
		limits_y.min = atom_getfloat(argv + 2);
		limits_y.max = atom_getfloat(argv + 3);
		limits_z.min = atom_getfloat(argv + 4);
		limits_z.max = atom_getfloat(argv + 5);
        
        bounds = CubeLimits(limits_x, limits_y, limits_z);
	}
    
    calculateLimits();
}

void Particle::resetLimits(){
    if(!concertRoom->getBounds()){
        limits_x = limits(-0.5*SOUND_LIMIT, 0.5*SOUND_LIMIT);
        limits_y = limits(-0.5*SOUND_LIMIT, 0.5*SOUND_LIMIT);
        limits_z = limits(-0.5*SOUND_LIMIT, 0.5*SOUND_LIMIT);
    }
    else{
        limits_x = limits(-0.5*concertRoom->getBounds()[0], 0.5*concertRoom->getBounds()[0]);
        limits_y = limits(-0.5*concertRoom->getBounds()[1], 0.5*concertRoom->getBounds()[1]);
        limits_z = limits(-0.5*concertRoom->getBounds()[2], 0.5*concertRoom->getBounds()[2]);
    }
    
    
    bounds = CubeLimits(limits_x, limits_y, limits_z);
    
    calculateLimits();
}

void Particle::calculateLimits(){
    
}


void Particle::setColor(ofVec4f c){
    color = c;
}

void Particle::setLifeLimits(t_atom *argv){
    lifeLimits.min = crop(atom_getfloat(argv), 0., atom_getfloat(argv));
    lifeLimits.max = crop(atom_getfloat(argv + 1), 0., atom_getfloat(argv + 1));
}

void Particle::setPos(t_atom* argv){
    
    setSpeed(ofVec3f(0., 0., 0.));
    
    if(coordinateSystem == "cartesian"){
        
        setPosCar(argv);
    }
    else {
        setPosRad(argv);
    }
}

void Particle::setPos(ofVec3f pos){
    
    setSpeed(ofVec3f(0., 0., 0.));
    
    if(coordinateSystem == "cartesian"){
        
        posCar = pos;
    }
    else {
        posRad = pos;
    }
}

void Particle::setPosIni(t_atom* argv){
    if(coordinateSystem == "cartesian"){
        setPosCarIni(argv);
    }
    else {
        setPosRadIni(argv);
    }
}


void Particle::setPosFinal(t_atom* argv){
    if(coordinateSystem == "cartesian"){
        setPosCarFinal(argv);
    }
    else {
        setPosRadFinal(argv);
    }
}



void Particle::setPosCar(t_atom* argv){
	
    posCar = ofVec3f(atom_getfloat(argv), atom_getfloat(argv+1), atom_getfloat(argv+2));
    
    //posCar = generateRandomVec3f(argv, randomness, bounds);
}

void Particle::setPosCarIni(t_atom* argv){
	
	
    posCarIni = generateRandomVec3f(randomness, ofVec3f(atom_getfloat(argv), atom_getfloat(argv+1), atom_getfloat(argv+2)));
	
}

void Particle::setPosCarFinal(t_atom* argv){
	
	
    posCarFinal = generateRandomVec3f(randomness, ofVec3f(atom_getfloat(argv), atom_getfloat(argv+1), atom_getfloat(argv+2)));
	
}

void Particle::setPosRad(t_atom* argv){
	
	
    posRad = ofVec3f(atom_getfloat(argv), atom_getfloat(argv+1), atom_getfloat(argv+2));
	
	
}

void Particle::setPosRadIni(t_atom* argv){
	
	
    posRadIni = generateRandomVec3f(randomness, ofVec3f(atom_getfloat(argv), atom_getfloat(argv+1), atom_getfloat(argv+2)));
    //post("posRadIni = %lf, %lf, %lf", posRadIni.x, posRadIni.y, posRadIni.z);
	
	
}

void Particle::setPosRadFinal(t_atom* argv){
	
	
    posRadFinal = generateRandomVec3f(randomness, ofVec3f(atom_getfloat(argv), atom_getfloat(argv+1), atom_getfloat(argv+2)));
    //post("posRadFinal = %lf, %lf, %lf", posRadFinal.x, posRadFinal.y, posRadFinal.z);
	
	
}

void Particle::setSpeed(t_atom *argv){
    
    speed = ofVec3f(atom_getfloat(argv), atom_getfloat(argv + 1), atom_getfloat(argv + 2));
    
}

void Particle::setSpeed(ofVec3f sp){
    speed = sp;
}

void Particle::setSpeedIni(t_atom *argv){
    
    speedIni = ofVec3f(atom_getfloat(argv), atom_getfloat(argv + 1), atom_getfloat(argv + 2));
    
}

void Particle::setSpeedFinal(t_atom *argv){
    
    speedFinal = ofVec3f(atom_getfloat(argv), atom_getfloat(argv + 1), atom_getfloat(argv + 2));
    
}

void Particle::setSpeedLimits(double x1, double x2, double y1, double y2, double z1, double z2){
    
}
void Particle::setSpeedLimits(t_atom* argv){
    
    limits_vx.min = atom_getfloat(argv + 0);
    limits_vx.max = atom_getfloat(argv + 1);
    limits_vy.min = atom_getfloat(argv + 2);
    limits_vy.max = atom_getfloat(argv + 3);
    limits_vz.min = atom_getfloat(argv + 4);
    limits_vz.max = atom_getfloat(argv + 5);
    
    easingLimits_x.min = crop(atom_getfloat(argv + 0), 0.005, 0.9);
    easingLimits_x.max = crop(atom_getfloat(argv + 1), 0.005, 0.9);
    easingLimits_y.min = crop(atom_getfloat(argv + 2), 0.005, 0.9);
    easingLimits_y.max = crop(atom_getfloat(argv + 3), 0.005, 0.9);
    easingLimits_z.min = crop(atom_getfloat(argv + 4), 0.005, 0.9);
    easingLimits_z.max = crop(atom_getfloat(argv + 5), 0.005, 0.9);
	
}


void Particle::setRandomness(double r){
    randomness = crop(r, 0., 0.99);
    
    posCarIni = generateRandomVec3f(randomness, posCarIni);
    posCarFinal = generateRandomVec3f(randomness, posCarFinal);
    posRadIni = generateRandomVec3f(randomness, posRadIni);
    posRadFinal = generateRandomVec3f(randomness, posRadFinal);
    posOffsetIni = generateRandomVec3f(randomness, posOffsetIni);
    posOffsetFinal = generateRandomVec3f(randomness, posOffsetFinal);
}


void Particle::setX(t_atom* argv){
    posCar.x = atom_getfloat(argv);
    speed.x = 0.0;
}
void Particle::setY(t_atom* argv){
    posCar.y = atom_getfloat(argv);
    speed.y = 0.0;
}
void Particle::setZ(t_atom* argv){
    posCar.z = atom_getfloat(argv);
    speed.z = 0.0;
}
void Particle::setVx(t_atom* argv){
    speed.x = atom_getfloat(argv);
}
void Particle::setVy(t_atom* argv){
    speed.y = atom_getfloat(argv);
}
void Particle::setVz(t_atom* argv){
    speed.z = atom_getfloat(argv);
}


void Particle::setRadius(t_atom* argv){
    posRad.x = atom_getfloat(argv);
    speed.x = 0.0;
}
void Particle::setTheta(t_atom* argv){
    post("entrei 2");
    posRad.y = atom_getfloat(argv);
    speed.y = 0.0;
}
void Particle::setPhi(t_atom* argv){
    posRad.z = atom_getfloat(argv);
    speed.z = 0.0;
}
void Particle::setRadiusSpeed(t_atom* argv){
    speed.x = atom_getfloat(argv);
}
void Particle::setThetaSpeed(t_atom* argv){
    speed.y = atom_getfloat(argv);
}
void Particle::setPhiSpeed(t_atom* argv){
    speed.z = atom_getfloat(argv);
}



void Particle::setOffset(t_atom* argv){
	
    posOffset = ofVec3f(atom_getfloat(argv), atom_getfloat(argv + 1), atom_getfloat(argv + 2));
}

void Particle::setOffsetIni(t_atom* argv){
	
    posOffsetIni = generateRandomVec3f(randomness, ofVec3f(atom_getfloat(argv), atom_getfloat(argv+1), atom_getfloat(argv+2)));
	
}

void Particle::setOffsetFinal(t_atom* argv){
	
    posOffsetFinal = generateRandomVec3f(randomness, ofVec3f(atom_getfloat(argv), atom_getfloat(argv+1), atom_getfloat(argv+2)));
	
}



void Particle::loadRec(std::string fn){
    
    /*
	 if(recFile){
	 fclose(recFile);
	 }
	 */
	
	recFile = fopen(fn.c_str(), "r");
	if(recFile != NULL){
		rec.clear();
		timedPos aux;
		while(!feof(recFile)){
			fscanf(recFile, "%d %lf %lf %lf", &aux.time, &aux.x, &aux.y, &aux.z);
			rec.push_back(aux);
		}
		
		
		//post("recFile.size() = %d", rec.size());
	}
	
	
}

void Particle::saveRec(std::string fn){
	
	
	recFile = fopen(fn.c_str(), "w");
	if(recFile){
		for(int i=0; i<rec.size(); i++){
			fprintf(recFile, "%d %lf %lf %lf\n", rec[i].time, rec[i].x, rec[i].y, rec[i].z);
		}
		fclose(recFile);
	}
}

void Particle::setRecMode(long argc, t_atom* argv){
	if(argc == 1){
		if(argv){
			postatom(argv);
			
			if(atom_getlong(argv) == 0){
				recMode = false;
			}
			else if(atom_getlong(argv) == 1){
				recMode = true;
				playRec = false;
				rec.clear();
			}
			
		}
		//post("setting recmode = %d", recMode);
	}
}

void Particle::setPlayRec(long argc, t_atom* argv){
	if(argc == 1){
		if(argv){
			if(atom_getlong(argv) == 0){
				playRec = false;
			}
			else if(atom_getlong(argv) == 1){
				playRec = true;
				recMode = false;
				playRecHead = 0;
			}
		}
		//post("setting playRec = %d", playRec);
	}
}



void Particle::recUpdate(){
	
	if(rec.size() > 0){
		
        posCar.x = rec[playRecHead].x;
		posCar.y = rec[playRecHead].y;
		posCar.z = rec[playRecHead].z;
		
		playRecHead++;
		if(playRecHead >= rec.size()){
			playRecHead = 0;
		}
	}
	
}

























