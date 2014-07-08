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

#include "mathUtils.h"

double rangedRandom(double x1, double x2){
    double high = 0;
	double low = 0;
	double randNum = 0;
	// if there is no range, return the value
	if (x1 == x2) return x1; 			// float == ?, wise? epsilon?
	high = MAX(x1, x2);
	low = MIN(x1, x2);
	randNum = low + ((high-low) * rand()/(RAND_MAX + 1.0f));
	return randNum;
}


double dist3d(ofVec3f v1, ofVec3f v2){
    
    return sqrt((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y) + (v1.z - v2.z)*(v1.z - v2.z));
    
}

double interpolate(ofVec2f v0, ofVec2f v1, double x){
    double y;
    
    y = v0.y + (v1.y - v0.y)*(x - v0.x)/(v1.x - v0.x);
    
    return y;
}

double getInterpolatedFromOfVec2fVector(vector<ofVec2f*>* v, double x){
    
    if(v){
        
        
        double gain = 0.;
        
        int index = -1;

        
        if(x <= (*v)[0]->x){
            gain = (*v)[0]->y;
            return gain;
        }

        
        if(x >= (*v)[v->size() - 1]->x){
            gain = (*v)[v->size() - 1]->y;
            return gain;
        }
        
        for(int i=0; i<(v->size() - 1); i++){
            if((*v)[i]->x <= x){
                if((*v)[i+1]->x >= x){
                    index = i;
                }
            }
        }
        
        gain = interpolate(ofVec2f((*v)[index]->x, (*v)[index]->y), ofVec2f((*v)[index+1]->x, (*v)[index+1]->y), x);
        
        return gain;

    }
    
    return 0.;
    
}

double getHannGain(double x, double ws){
    if(x < 0.){
        return 0.;
    }
    if(x > ws){
        return 1.;
    }
    double gain;
    gain = 0.5 + (0.5*cos(M_PI + 2*M_PI*(x/ws)));
    return gain;
}

double crop(double x, double x_min, double x_max){
    if(x < x_min){
        return x_min;
    }
    
    if(x > x_max){
        return x_max;
    }
    
    return x;
}

