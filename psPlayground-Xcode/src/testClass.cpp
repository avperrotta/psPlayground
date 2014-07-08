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

#include "testClass.h"


testClass::testClass(){
    
    msg = new t_atom[3];
    //t_atom argv[3];
    
    atom_setlong(msg, 43);
    atom_setsym(msg + 1, gensym("crazy"));
    atom_setfloat(msg + 2, 8.34);

    
    /*
    msg = new t_atom[9];
    post("msg created");
    
    
    std::string tagStr;
    tagStr = "/traj";
    post("%s", tagStr.c_str());
    unsigned char* tag;
    tag = new unsigned char[6];
    strcpy((char*)tag, tagStr.c_str());
    
    post("%c", tag[0]);
    post("%c", tag[1]);
    post("%c", tag[2]);
    post("%c", tag[3]);
    post("%c", tag[4]);
    post("%c", tag[5]);
    
    atom_setchar_array(0, msg, 5, tag);
    
    /*
    t_symbol* sym;
    sym = new t_symbol;
    strcpy(sym->s_name, "/traj");
    post(sym->s_name);
    
    if(msg){
        atom_setsym(msg, sym);
        atom_setlong(msg + 1, 1);
        atom_setfloat(msg + 2, 10.2);
        atom_setfloat(msg + 3, 980.342);
    }
    */
    

}

testClass::~testClass(){
    
}

float testClass::getV(){
    return 0.75;
}

t_atom* testClass::getAtom(){
    return msg;
}