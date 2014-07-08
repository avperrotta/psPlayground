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

#include "farfalharParticle.h"

FarfalharParticle::FarfalharParticle(){
	
}

FarfalharParticle::FarfalharParticle(pSystem* sys, int ind){
	setup(sys, ind);
}

FarfalharParticle::~FarfalharParticle(){
	
}

void FarfalharParticle::customSetup(){
    //floating = 1
    //collapse = 2
    //stay = 3
    //discollapse = 4
    //inverseCollapse = 5
    //inverseStay = 6
    //inverseDiscollapse = 7
    
    setBaseNotes();
    setupNotes();
    
    outputSpecific = true;
    
    conjunto  = 1;
	
	rollDice();
    
    posRad.x = rangedRandom(0.5, 0.7);
	posRadIni.x = posRad.x;
    
	posRad.y = rangedRandom(350, 360);
	speed.y = rangedRandom(3.0, 9.0);
	speed.x = 0.0;
	
	gain = 0.01;
	
	status = 1;
	
	collapseRadius = rangedRandom(0.0, 0.1);
	
	gainStatus = 1;
    
    ea1 = 40.;
    ea2 = 0.01;
    ea3 = 0.01;
    ea4 = 0.01;
    ea5 = 0.01;
    ea6 = 0.01;
    ea7 = 0.01;
    
    beating = 0.;
    beatingSpeed = rangedRandom(-0.005, 0.005);
    beatingNote = note;
    maxBeating = rangedRandom(-1.5, 1.5);
    
    resolutionProbability = 0.6;
    
	
}

void FarfalharParticle::customUpdate(){
    if(status == 2){
		posRad.x = posRad.x - posRad.x/40.0;
		if(fabs(posRad.x - collapseRadius) < 0.05){
			status = 3;
			stayCounter = 0;
		}
		gain = gain + gain/20.0;
		if(gain > 0.05){
			gain = 0.05;
		}
		
	}
	else if(status == 3){
		stayCounter++;
		if(stayCounter > 20){
			status = 4;
		}
		gain = gain + gain/10.0;
		if(gain > 0.05){
			gain = 0.05;
		}
	}
	else if(status == 4){
		posRad.x = posRad.x + (posRadIni.x - posRad.x)/30.0;
		if(fabs(posRad.x - posRadIni.x) < 0.05){
			posRad.x = posRadIni.x;
			status = 1;
		}
		gain = gain - gain/25.0;
		if(gain < 0.01){
			gain = 0.01;
		}
	}
	else if(status == 5){
		gain = gain - gain/25.0;
		if(gain < 0.0005){
			gain = 0.0005;
			status = 6;
		}
	}
	else if(status == 6){
		stayCounter++;
		if(stayCounter > 60){
			status = 7;
			rollDice();
		}
	}
	else if(status == 7){
		gain = gain + gain/40.0;
		if(gain > 0.01){
			gain = 0.01;
			status = 1;
		}
	}
	
	//cout<<endl;
	//cout<<vol;
	
	posRad.y += speed.y;
	posCar.x = posRad.x*cos(posRad.y*M_PI/180.0);
	posCar.z = posRad.x*sin(posRad.y*M_PI/180.0);
    
    
    
    beatingNote = note + maxBeating*sin(beating);
    beating += beatingSpeed;
    
    outputSpecificRoutine();
    
}

void FarfalharParticle::restart(){
	customSetup();
	
}

void FarfalharParticle::outputSpecificRoutine(){
    //post("entrei");
    if(outputSpecific){
        
        t_atom* aux;
        aux = new t_atom[4];
        atom_setsym(aux, gensym(systemName.c_str()));
        atom_setlong(aux + 1, index);
        atom_setfloat(aux + 2, note);
        atom_setfloat(aux + 3, beatingNote);
        
        if(superOutlet4 && aux){
            outlet_list(superOutlet4, 0L, 4, aux);
        }
        
        delete[] aux;
    }
}

void FarfalharParticle::rollDice(){
	
	if(conjunto == 1){
		int noteIndex;
		int path = rangedRandom(0., 10.);
		if(path < 6.0){
			noteIndex = (int)floor(rangedRandom(0, 8));
		}
		else{
			noteIndex = (int)floor(rangedRandom(8, 40));
		}
		
        
		speed.y = rangedRandom(3.0, 9.0);
		//cout<<endl;
		//cout<<noteIndex;
		note = notes[noteIndex];
        //post("noteIndex = %d note = %lf", noteIndex, note);
	}
	if(conjunto == 2){
		
		int noteIndex;
		int path = rangedRandom(0., 10.);
		if(path < 4.0){
			noteIndex = (int)floor(rangedRandom(0, 11));
		}
		else{
			noteIndex = (int)floor(rangedRandom(11, 66));
		}
		note = notes2[noteIndex];
		
		speed.y = rangedRandom(2.0, 5.0);
	}
	if(conjunto == 3){
		int noteIndex;
		int path = rangedRandom(0., 10.);
		if(path < resolutionProbability){
			 noteIndex = resolutionIndexes[(int)floor(rangedRandom(0., 8.))];
		}
		else{
			noteIndex = (int)floor(rangedRandom(16, 40));
		}
		note = notes3[noteIndex];
		speed.y = rangedRandom(0.8, 3.0);
	}
	
}

void FarfalharParticle::setMaxBeating(double mb){
    maxBeating = rangedRandom(-1.*mb, mb);
}

void FarfalharParticle::setBeatingSpeed(double bs){
    beatingSpeed = rangedRandom(-1.*bs, bs);
}

void FarfalharParticle::setResolutionProb(double rp){
    resolutionProbability = rp;
}

void FarfalharParticle::redraw(int r){
    if(r > 0){
        conjunto = r;
        rollDice();
    }
    
}

void FarfalharParticle::collapse(std::string n){
    //floating = 1
    //collapse = 2
    //stay = 3
    //discollapse = 4
    //inverseCollapse = 5
    //inverseStay = 6
    //inverseDiscollapse = 7
    
    
    std::string nota = n;
    if(nota == "G#3"){
        if(note == notes[0] || note == notes[8] || note == notes[9] || note == notes[10] || note == notes[32]){
            if(status == 1){
                status = 2;
                conjunto = 1;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 1;
            }
            
        }
    }
    else if(nota == "Bb3"){
        if(note == notes[1] || note == notes[11] || note == notes[12] ||note == notes[13] || note == notes[33]){
            if(status == 1){
                status = 2;
                conjunto = 1;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 1;
            }
            
        }
    }
    else if(nota == "D4"){
        if(note == notes[2] || note == notes[14] || note == notes[15] || note == notes[16] || note == notes[34]){
            if(status == 1){
                status = 2;
                conjunto = 1;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 1;
            }
            
        }
    }
    else if(nota == "F#4"){
        if(note == notes[3] || note == notes[17] || note == notes[18] ||note == notes[19] || note == notes[35]){
            if(status == 1){
                status = 2;
                conjunto = 1;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 1;
            }
            
        }
    }
    else if(nota == "G4"){
        if(note == notes[4] || note == notes[20] || note == notes[21] || note == notes[22] || note == notes[36]){
            if(status == 1){
                status = 2;
                conjunto = 1;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 1;
            }
            
        }
    }
    else if(nota == "C5"){
        if(note == notes[5] || note == notes[23] || note == notes[24] ||note == notes[25] || note == notes[31]){
            if(status == 1){
                status = 2;
                conjunto = 1;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 1;
            }
            
        }
    }
    else if(nota == "E5"){
        if(note == notes[6] || note == notes[26] || note == notes[27] || note == notes[28] || note == notes[35]){
            if(status == 1){
                status = 2;
                conjunto = 1;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 1;
            }
            
        }
    }
    else if(nota == "A5"){
        if(note == notes[7] || note == notes[29] || note == notes[30] ||note == notes[31] || note == notes[39]){
            if(status == 1){
                status = 2;
                conjunto = 1;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 1;
            }
            
        }
    }
    
    else if(nota == "G3_2"){
        if(note == notes2[0] || note == notes2[11] || note == notes2[12] ||
           note == notes2[13] || note == notes2[14] || note == notes2[15] ||
           note == notes2[1] || note == notes2[16] || note == notes2[17] ||
           note == notes2[18] || note == notes2[19] || note == notes2[20] || note == notes2[21]){
            if(status == 1){
                status = 2;
                conjunto = 2;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 2;
            }
            
        }
    }
    else if(nota == "F#4_2"){
        if(note == notes2[2] || note == notes2[22] || note == notes2[23] ||
           note == notes2[24] || note == notes2[25] || note == notes2[26] ||
           note == notes2[3] || note == notes2[27] || note == notes2[28] ||
           note == notes2[29] || note == notes2[30] ||
           note == notes2[4] || note == notes2[31] || note == notes2[32] ||
           note == notes2[33] || note == notes2[34] || note == notes2[35]){
            if(status == 1){
                status = 2;
                conjunto = 2;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 2;
            }
            
        }
    }
    else if(nota == "D5_2"){
        if(note == notes2[5] || note == notes2[36] || note == notes2[37] ||
           note == notes2[38] || note == notes2[39] || note == notes2[40] ||
           note == notes2[6] || note == notes2[41] || note == notes2[42] ||
           note == notes2[43] || note == notes2[44] || note == notes2[45]){
            if(status == 1){
                status = 2;
                conjunto = 2;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 2;
            }
            
        }
    }
    else if(nota == "E5_2"){
        if(note == notes2[7] || note == notes2[46] || note == notes2[47] ||
           note == notes2[48] || note == notes2[49] || note == notes2[50] ||
           note == notes2[10] || note == notes2[61] || note == notes2[62] ||
           note == notes2[63] || note == notes2[64] ||note == notes2[65]){
            if(status == 1){
                status = 2;
                conjunto = 2;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 2;
            }
            
        }
    }
    else if(nota == "A#5_2"){
        if(note == notes2[8] || note == notes2[51] || note == notes2[52] ||
           note == notes2[53] || note == notes2[54] || note == notes2[55] ||
           note == notes2[9] || note == notes2[56] || note == notes2[57] ||
           note == notes2[58] || note == notes2[59] || note == notes2[60]){
            if(status == 1){
                status = 2;
                conjunto = 2;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 2;
            }
            
        }
    }
    
    else if(nota == "B4_3"){
        if(note == notes3[5] || note == notes3[11] || note == notes3[12] ||
           note == notes3[13] || note == notes3[14] || note == notes3[15] || note == notes3[26] || note == notes3[27]){
            if(status == 1){
                status = 2;
                conjunto = 3;
            }
        }
        else{
            if(status == 1){
                status = 5;
                conjunto = 3;
            }
            
        }
    }
}
void FarfalharParticle::setBaseNotes(){
    notes[0] = 207.65;
	notes[1] = 233.08;
	notes[2] = 293.66;
	notes[3] = 369.99;
	notes[4] = 391.99;
	notes[5] = 523.25;
	notes[6] = 659.25;
	notes[7] = 880.00;
    
    notes2[0] = 195.99;
	notes2[1] = 220.00;
	notes2[2] = 261.62;
	notes2[3] = 369.99;
	notes2[4] = 415.30;
	notes2[5] = 493.88;
	notes2[6] = 587.32;
	notes2[7] = 659.25;
	notes2[8] = 932.32;
	notes2[9] = 1108.73;
	notes2[10] = 1244.50;
    
    notes3[0] = 195.99;
	notes3[1] = 220.00;
	notes3[2] = 261.62;
	notes3[3] = 369.99;
	notes3[4] = 415.30;
	notes3[5] = 493.88;
	notes3[6] = 587.32;
	notes3[7] = 659.25;
	notes3[8] = 932.32;
	notes3[9] = 1108.73;
	notes3[10] = 1244.50;
}

void FarfalharParticle::setupNotes(){
    
	
	notes[8] = notes[0]*2.0;
	notes[9] = notes[0]*1.414*2.0;
	notes[10] = notes[0]*1.782*4.0;
	
	
	notes[11] = notes[1]*2.0;
	notes[12] = notes[1]*1.414*2.0;
	notes[13] = notes[1]*1.782*4.0;
	
	notes[14] = notes[2]*2.0;
	notes[15] = notes[2]*1.414*2.0;
	notes[16] = notes[2]*1.782*4.0;
	
	notes[17] = notes[3]*2.0;
	notes[18] = notes[3]*1.414*2.0;
	notes[19] = notes[3]*1.782*4.0;
	
	notes[20] = notes[4]*2.0;
	notes[21] = notes[4]*1.414*2.0;
	notes[22] = notes[4]*1.782*4.0;
	
	notes[23] = notes[5]*2.0;
	notes[24] = notes[5]*1.414*2.0;
	notes[25] = notes[5]*1.782*4.0;
	
	notes[26] = notes[6]*2.0;
	notes[27] = notes[6]*1.414*2.0;
	notes[28] = notes[6]*1.782*4.0;
	
	notes[29] = notes[7]*2.0;
	notes[30] = notes[7]*1.414*2.0;
	notes[31] = notes[7]*1.782*4.0;
	
	notes[32] = notes[0]*0.25;
	notes[33] = notes[1]*0.25;
	notes[34] = notes[2]*0.25;
	notes[35] = notes[3]*0.25;
	notes[36] = notes[4]*0.25;
	notes[37] = notes[5]*0.25;
	notes[38] = notes[6]*0.25;
	notes[39] = notes[7]*0.25;
	
	
	
	notes2[11] = notes2[0]*2.0*1.122;
	notes2[12] = notes2[0]*2.0*1.414;
	notes2[13] = notes2[0]/8.0;
	notes2[14] = notes2[0]*4.0*1.587;
	notes2[15] = notes2[0]*8.0*1.888;
	
	notes2[16] = notes2[1]*2.0*1.122;
	notes2[17] = notes2[1]*2.0*1.414;
	notes2[18] = notes2[1]/8.0;
	notes2[19] = notes2[1]*4.0*1.587;
	notes2[20] = notes2[1]*8.0*1.888;
	
	notes2[21] = notes2[2]*2.0*1.122;
	notes2[22] = notes2[2]*2.0*1.414;
	notes2[23] = notes2[2]/8.0;
	notes2[24] = notes2[2]*4.0*1.587;
	notes2[25] = notes2[2]*8.0*1.888;
	
	notes2[26] = notes2[3]*2.0*1.122;
	notes2[27] = notes2[3]*2.0*1.414;
	notes2[28] = notes2[3]/8.0;
	notes2[29] = notes2[3]*4.0*1.587;
	notes2[30] = notes2[3]*8.0*1.888;
	
	notes2[31] = notes2[4]*2.0*1.122;
	notes2[32] = notes2[4]*2.0*1.414;
	notes2[33] = notes2[4]/8.0;
	notes2[34] = notes2[4]*4.0*1.587;
	notes2[35] = notes2[4]*8.0*1.888;
	
	notes2[36] = notes2[5]*2.0*1.122;
	notes2[37] = notes2[5]*2.0*1.414;
	notes2[38] = notes2[5]/8.0;
	notes2[39] = notes2[5]*4.0*1.587;
	notes2[40] = notes2[5]*8.0*1.888;
	
	notes2[41] = notes2[6]*2.0*1.122;
	notes2[42] = notes2[6]*2.0*1.414;
	notes2[43] = notes2[6]/8.0;
	notes2[44] = notes2[6]*4.0*1.587;
	notes2[45] = notes2[6]*8.0*1.888;
	
	notes2[46] = notes2[7]*2.0*1.122;
	notes2[47] = notes2[7]*2.0*1.414;
	notes2[48] = notes2[7]/8.0;
	notes2[49] = notes2[7]*4.0*1.587;
	notes2[50] = notes2[7]*8.0*1.888;
	
	notes2[51] = notes2[8]*2.0*1.122;
	notes2[52] = notes2[8]*2.0*1.414;
	notes2[53] = notes2[8]/8.0;
	notes2[54] = notes2[8]*4.0*1.587;
	notes2[55] = notes2[8]*8.0*1.888;
	
	notes2[56] = notes2[9]*2.0*1.122;
	notes2[57] = notes2[9]*2.0*1.414;
	notes2[58] = notes2[9]/8.0;
	notes2[59] = notes2[9]*4.0*1.587;
	notes2[60] = notes2[9]*8.0*1.888;
	
	notes2[61] = notes2[10]*2.0*1.122;
	notes2[62] = notes2[10]*2.0*1.414;
	notes2[63] = notes2[10]/8.0;
	notes2[64] = notes2[10]*4.0*1.587;
	notes2[65] = notes2[10]*8.0*1.888;
	
	
    resolutionIndexes[0] = 5;
    resolutionIndexes[1] = 11;
    resolutionIndexes[2] = 12;
    resolutionIndexes[3] = 13;
    resolutionIndexes[4] = 14;
    resolutionIndexes[5] = 15;
    resolutionIndexes[6] = 26;
    resolutionIndexes[7] = 27;
    
	notes3[11] = notes3[5]*2.0;
	notes3[12] = notes3[5]*2.0*1.414;
	notes3[13] = notes3[5]*4.0*1.122;
	notes3[14] = notes3[5]*0.25/1.414;
	notes3[15] = notes3[5]*0.125/1.414;
	
	notes3[16] = notes3[0]*2.0*1.587;
	notes3[17] = notes3[0]*8.0;
	
	notes3[18] = notes3[1]*2.0*1.587;
	notes3[19] = notes3[1]*8.0;
	
	notes3[20] = notes3[2]*2.0*1.587;
	notes3[21] = notes3[2]*8.0;
	
	notes3[22] = notes3[3]*2.0*1.587;
	notes3[23] = notes3[3]*8.0;
	
	notes3[24] = notes3[4]*2.0*1.587;
	notes3[25] = notes3[4]*8.0;
	
	notes3[26] = notes3[5]*2.0*1.587;
	notes3[27] = notes3[5]*8.0;
	
	notes3[28] = notes3[6]*2.0*1.587;
	notes3[29] = notes3[6]*8.0;
	
	notes3[30] = notes3[7]*2.0*1.587;
	notes3[31] = notes3[7]*8.0;
	
	notes3[32] = notes3[8]*2.0*1.587;
	notes3[33] = notes3[8]*8.0;
	
	notes3[34] = notes3[9]*2.0*1.587;
	notes3[35] = notes3[9]*8.0;
	
	notes3[36] = notes3[10]*2.0*1.587;
	notes3[37] = notes3[10]*8.0;
	
	notes3[38] = notes3[11]*2.0*1.587;
	notes3[39] = notes3[11]*8.0;
}


void FarfalharParticle::setNotes(long argc, t_atom* argv){
    if(argc == 8){
        if(argv){
            for(int i=0; i<8; i++){
                notes[i] = atom_getfloat(argv + i);
            }
            conjunto = 1;
            setupNotes();
            rollDice();
        }
    }
}
















