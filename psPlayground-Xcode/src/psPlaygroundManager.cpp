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

#include "psPlaygroundManager.h"


psPlaygroundManager::psPlaygroundManager(){
    concertRoom = new ConcertRoom();
    
    
}
psPlaygroundManager::~psPlaygroundManager(){
    if(concertRoom){
        delete concertRoom;
    }
    
    for(pSystems_it = pSystems.begin(); pSystems_it != pSystems.end(); ++pSystems_it){
        delete pSystems_it->second;
    }
    pSystems.clear();
    
}

void psPlaygroundManager::setup(){
    
}


void psPlaygroundManager::update(){
    
    
    for(pSystems_it = pSystems.begin(); pSystems_it != pSystems.end(); ++pSystems_it){
        pSystems_it->second->update();
    }
    
    outlet_bang(updateOutlet);
    
}
void psPlaygroundManager::draw(){
    
    //draw systems
    for(pSystems_it = pSystems.begin(); pSystems_it != pSystems.end(); ++pSystems_it){
        pSystems_it->second->draw();
    }
    
    //draw room
    concertRoom->draw();
}


t_jit_err psPlaygroundManager::messageControl(long argc, t_atom *argv){
    
    std::string task;
    task = jit_atom_getsym(argv)->s_name;
    
    
    /*
    if(task == "updateSystems"){
        update();
    }
    */
    
    
    if(task == "setAbsPath"){
        if(argc == 2){
            if(argv){
                concertRoom->setFilesPath(atom_getsym(argv + 1)->s_name);
                post("absolute path = %s", atom_getsym(argv + 1)->s_name);
                return JIT_ERR_NONE;
            }
        }
    }
    
    else if(task == "setRoomSize"){
        concertRoom->setBounds(argc, argv);
        return JIT_ERR_NONE;
    }
    
    else if(task == "setNumSpeakers"){
        concertRoom->setNumSpeakers(argc, argv);
        return JIT_ERR_NONE;
    }
    
    else if(task == "setSpeakerPosition"){
        concertRoom->setSpeakerPosition(argc, argv);
        return JIT_ERR_NONE;
    }
    
    else if(task == "setSpeakerCalibration"){
        concertRoom->setSpeakerCalibration(argc, argv);
        return JIT_ERR_NONE;
    }
    
    else if(task == "setReverbGain"){
        concertRoom->setReverbGain(argc, argv);
        return JIT_ERR_NONE;
    }
    
    else if(task == "setReverbSize"){
        concertRoom->setReverbSize(argc, argv);
        return JIT_ERR_NONE;
    }
    
    else if(task == "addParticleSystem"){
        addPSystem(argc, argv);
        return JIT_ERR_NONE;
    }
    
    else if(task == "deleteParticleSystem"){
        deletePSystem(argc, argv);
        return JIT_ERR_NONE;
    }
    
    else if(task == "pSystemAccess"){
        std::string systemName;
        systemName = jit_atom_getsym(argv + 1)->s_name;
        if(pSystems.find(systemName) != pSystems.end()){
            pSystems[systemName]->messageControl(argc - 2, argv + 2);
            return JIT_ERR_NONE;
        }
    }
    
    /*
    else if(task == "particleAccess"){
        std::string systemName;
        systemName = jit_atom_getsym(argv + 1)->s_name;
        if(pSystems.find(systemName) != pSystems.end()){
            pSystems[systemName]->messageControl(argc - 2, argv + 2);
            return JIT_ERR_NONE;
        }
    }
    */
    
    return JIT_ERR_INVALID_INPUT;
}



t_jit_err psPlaygroundManager::addPSystem(long argc, t_atom* argv){
    
    
    
    if(argv){
        if(argc == 4){
            std::string systemType;
            std::string systemName;
            
            systemType = jit_atom_getsym(argv + 1)->s_name;
            systemName = jit_atom_getsym(argv + 2)->s_name;
            int numParticles = jit_atom_getlong(argv + 3);
            
            if(systemType == "simpleRandomSystem"){
                if(pSystems.find(systemName) == pSystems.end()){
                    post("inserting simpleRandomSystem: %s", systemName.c_str());
                    pSystems.insert(std::pair<std::string, pSystem*>(systemName, new SimpleRandomSystem(concertRoom, systemName, numParticles)));
                    return JIT_ERR_NONE;
                }
                post("already has a system with name: %s", systemName.c_str());
                
            }
            else if(systemType == "spatCalibrationSystem"){
                if(pSystems.find(systemName) == pSystems.end()){
                    post("inserting spatCalibrationSystem: %s", systemName.c_str());
                    pSystems.insert(std::pair<std::string, pSystem*>(systemName, new SpatCalibrationSystem(concertRoom, systemName, numParticles)));
                    return JIT_ERR_NONE;
                }
                post("already has a system with name: %s", systemName.c_str());
                
            }
            else if(systemType == "rainSystem"){
                if(pSystems.find(systemName) == pSystems.end()){
                    post("inserting rainSystem: %s", systemName.c_str());
                    pSystems.insert(std::pair<std::string, pSystem*>(systemName, new RainSystem(concertRoom, systemName, numParticles)));
                    return JIT_ERR_NONE;
                }
                post("already has a system with name: %s", systemName.c_str());
                
            }
			else if(systemType == "manualMovementSystem"){
                if(pSystems.find(systemName) == pSystems.end()){
                    post("inserting manualMovementSystem: %s", systemName.c_str());
                    pSystems.insert(std::pair<std::string, pSystem*>(systemName, new ManualMovementSystem(concertRoom, systemName, numParticles)));
                    return JIT_ERR_NONE;
                }
                post("already has a system with name: %s", systemName.c_str());
                
            }
            else if(systemType == "sphericalMovementSystem"){
                if(pSystems.find(systemName) == pSystems.end()){
                    post("inserting sphericalMovementSystem: %s", systemName.c_str());
                    pSystems.insert(std::pair<std::string, pSystem*>(systemName, new SphericalMovementSystem(concertRoom, systemName, numParticles)));
                    return JIT_ERR_NONE;
                }
                post("already has a system with name: %s", systemName.c_str());
                
            }
            else if(systemType == "farfalharSystem"){
                if(pSystems.find(systemName) == pSystems.end()){
                    post("Farfalhar das Folhas software developed by Andre V. Perrotta");
                    post("Sao Paulo - Brazil  2010");
                    post("Porto - Portugal 2014");
                    post("www.avperrotta.org");
                    post("inserting farfalharSystem: %s", systemName.c_str());
                    pSystems.insert(std::pair<std::string, pSystem*>(systemName, new FarfalharSystem(concertRoom, systemName, numParticles)));
                    return JIT_ERR_NONE;
                }
                post("already has a system with name: %s", systemName.c_str());
                
            }
        }
    }
    
    
    return JIT_ERR_INVALID_INPUT;
}


t_jit_err psPlaygroundManager::deletePSystem(long argc, t_atom *argv){
    if(argv){
        if(argc == 2){
            std::string systemName = jit_atom_getsym(argv + 1)->s_name;
            if(pSystems.find(systemName) != pSystems.end()){
                delete pSystems[systemName];
                pSystems.erase(systemName);
                return JIT_ERR_NONE;
            }
        }
    }
    return JIT_ERR_INVALID_INPUT;
}














