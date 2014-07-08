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
#ifndef psPlayground_mathUtils_h
#define psPlayground_mathUtils_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ofVectorMath.h"
#include "jit.common.h"
#include "jit.gl.h"
#include "ext.h"
#include "ext_obex.h"
#include "ext_strings.h"
#include "ext_common.h"
#include "ext_systhread.h"

#define SIZE_NORMALIZATION 1.


//math functions
double rangedRandom(double x1, double x2);
double dist3d(ofVec3f v1, ofVec3f v2);
double getInterpolatedFromOfVec2fVector(vector<ofVec2f*>* v, double x);
double interpolate(ofVec2f v0, ofVec2f v1, double x);
double crop(double x, double x_min, double x_max);
double getHannGain(double x, double ws);


//util classes
class limits{
public:
    
    limits(){
        
    }
    limits(double x, double y){
        min = x;
        max = y;
    }

    double min;
    double max;
    
    
    
};

class timedPos{
public:
	
	timedPos(){
		
	}
	
	~timedPos(){
		
	}
	
	timedPos(int t, double x_, double y_, double z_){
		time = t;
		x = x_;
		y = y_;
		z = z_;
	}
	
	int time;
	double x;
	double y;
	double z;
};

template <class T>
std::string ofToString(const T& value){
	ostringstream out;
	out << value;
	return out.str();
}

template <class T>
std::string ofToString(const T& value, int precision){
	ostringstream out;
	out << fixed << setprecision(precision) << value;
	return out.str();
}

template<class T>
std::string ofToString(const vector<T>& values) {
	stringstream out;
	int n = values.size();
	out << "{";
	if(n > 0) {
		for(int i = 0; i < n - 1; i++) {
			out << values[i] << ", ";
		}
		out << values[n - 1];
	}
	out << "}";
	return out.str();
}


#endif
