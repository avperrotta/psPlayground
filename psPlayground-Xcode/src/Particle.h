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

#ifndef __psPlayground__Particle__
#define __psPlayground__Particle__

#include <iostream>
#include "ofVectorMath.h"
#include "mathUtils.h"
#include "jit.common.h"
#include "jit.gl.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_strings.h"
#include "ext_common.h"
#include "ext_systhread.h"
#include "dbap.h"

class pSystem;
class ConcertRoom;
class AttractorParticle;
class Particle{
    
public:
    
    Particle();
    Particle(pSystem* sys, int ind);
    virtual ~Particle();
    
    virtual void setup();
    virtual void setup(pSystem* sys, int ind);
    virtual void customSetup();
    virtual void update();
    virtual void draw();
    virtual void restart();
	virtual void customRestart();
    virtual void reset();

    virtual void customUpdate();
    std::string systemName;
    
    int status;
    int index;
    
    bool play;
    
    double minLife;
    double maxLife;
    double life;
    limits lifeLimits;
    double avgLife;
    double age;
    virtual void setLifeLimits(t_atom* argv);
    
    double currentTime;
    double previousTime;
    double initialTime;
    double dTime;
    double lifeTime;
    double timeToLive;
    void resetTime();
	virtual void updateTime();
	bool updateByTime;
	
    virtual void triggerTrajectory(t_atom* argv);
    virtual void triggerTrajectory(float ttl);
    virtual void trajectoryControl();
    virtual void trajectoryUpdate();
    bool onTrajectory;
    int trajectoryLoopType;
    bool trajectoryFinished;
	void setTrajectoryLoopType(t_atom* argv);
    
    
    
    
    int trigger;
    
    
    double gain;
    
    double randomness;
    void setRandomness(double r);
    
    std::string coordinateSystem;
    
    ofVec3f posCarIniMin;
    ofVec3f posCarIniMax;
    ofVec3f posCarIni;
	ofVec3f posCarFinal;
    ofVec3f posRadIniMin;
    ofVec3f posRadIniMax;
    ofVec3f posRadIni;
	ofVec3f posRadFinal;
    ofVec3f posCar;
    ofVec3f posRad;
    ofVec3f speedIniMin;
    ofVec3f speedIniMax;
    ofVec3f speedIni;
	ofVec3f speedFinal;
    ofVec3f speed;
    
    virtual void setPos(ofVec3f pos);
	virtual void setPos(t_atom* argv);
    virtual void setX(t_atom* argv);
    virtual void setY(t_atom* argv);
    virtual void setZ(t_atom* argv);
    
    virtual void setPosIni(t_atom* argv);
    virtual void setPosFinal(t_atom* argv);
    
    virtual void setSpeed(t_atom* argv);
    virtual void setSpeed(ofVec3f sp);
    virtual void setSpeedIni(t_atom* argv);
    virtual void setSpeedFinal(t_atom* argv);
    virtual void setVx(t_atom* argv);
    virtual void setVy(t_atom* argv);
    virtual void setVz(t_atom* argv);
    
    virtual void setPosCarIni(t_atom* argv);
	virtual void setPosCar(t_atom* argv);
	virtual void setPosCarFinal(t_atom* argv);
	virtual void setPosRad(t_atom* argv);
    virtual void setPosRadIni(t_atom* argv);
	virtual void setPosRadFinal(t_atom* argv);
    
    virtual void setRadius(t_atom* argv);
    virtual void setTheta(t_atom* argv);
    virtual void setPhi(t_atom* argv);
    virtual void setRadiusSpeed(t_atom* argv);
    virtual void setThetaSpeed(t_atom* argv);
    virtual void setPhiSpeed(t_atom* argv);
    
    
    ofVec3f posOffset;
    ofVec3f posOffsetIni;
    ofVec3f posOffsetFinal;
    ofVec3f posOffsetIniMin;
    ofVec3f posOffsetIniMax;
    ofVec3f posOffsetSpeed;
    ofVec3f posOffsetSpeedIni;
    ofVec3f posOffsetSpeedIniMin;
    ofVec3f posOffsetSpeedIniMax;
    
    virtual void setOffset(t_atom* argv);
    virtual void setOffsetIni(t_atom* argv);
    virtual void setOffsetFinal(t_atom* argv);
    
    ofVec3f accelIniMin;
    ofVec3f accelIniMax;
    ofVec3f accelIni;
    ofVec3f accel;
    ofVec3f force;
    
    ofVec4f color;
    void setColor(ofVec4f c);
    
    double mass;
    double width;
    double height;
    
    double x, y, z;
    double x0, y0, z0;
    double vx, vy, vz;
    double vx0, vy0, vz0;
    double ax, ay, az;
    double ax0, ay0, az0;
    
    limits limits_x;
    limits limits_y;
    limits limits_z;
    
    CubeLimits bounds;
    virtual void resetLimits();
    virtual void setSizeLimits(double x1, double x2, double y1, double y2, double z1, double z2);
    virtual void setSizeLimits(t_atom* argv);
    virtual void calculateLimits();
    
    virtual void setLimitsX(t_atom* argv);
    virtual void setLimitsY(t_atom* argv);
    virtual void setLimitsZ(t_atom* argv);
    virtual void setLimitsX(limits lx);
    virtual void setLimitsY(limits ly);
    virtual void setLimitsZ(limits lz);
    
    limits limits_vx;
    limits limits_vy;
    limits limits_vz;
    virtual void setSpeedLimits(double x1, double x2, double y1, double y2, double z1, double z2);
    virtual void setSpeedLimits(t_atom* argv);
    double speedDirectionProbability;
    virtual void setSpeedDirectionProbability(t_atom* argv);
    
    limits limits_ax;
    limits limits_ay;
    limits limits_az;
    
    double easing_x;
    double easing_y;
    double easing_z;
    limits easingLimits_x;
    limits easingLimits_y;
    limits easingLimits_z;
    
    
    //attractors
    vector<AttractorParticle*>* attractors;
    virtual void updateAttractorInfluence();

    //environment
    ConcertRoom* concertRoom;
    pSystem* mySystem;
    
    
    //spatialization
    bool useDbap;
    Dbap* dbap;
    vector<double>* dbapGains;
    
    
    //output parsing
    bool outputRaw;
    bool outputDbap;
    bool outputEnv;
    bool outputSpecific;
    void outputDbapRoutine();
    void outputRawRoutine();
    void outputEnvRoutine();
    void outputSpecificRoutine();
    void outputTrajectoryTriggerTriggers();
    //void outputSpecificTriggers();
    void createOutput();
    vector<double> rawData;
    vector<double> specificData;
    virtual void createRawOutputVector();
    virtual void createSpecificOutputVector();
    
    //recording trajectory
	FILE* recFile;
	bool recMode;
	bool playRec;
	int playRecHead;
	void loadRec(std::string fn);
	void saveRec(std::string fn);
	vector<timedPos> rec;
	std::string recFileName;
    void setRecMode(long argc, t_atom* argv);
	void recUpdate();
	void setPlayRec(long argc, t_atom* argv);
    
    
};


#endif /* defined(__psPlayground__Particle__) */
