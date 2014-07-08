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


#include "jit.common.h"
#include "jit.gl.h"
#include "testClass.h"
#include "psPlaygroundManager.h"
#include "pspGlobals.h"

typedef struct _psPlayground 
{
	t_object ob;
	void* ob3d;
    
    psPlaygroundManager* pspMng;
    t_atom pspMngMessages;
    t_atom speakerPosition;
    t_atom speakerDistanceGain;
    bool lock;

} t_psPlayground;

static void *_psPlayground_class = NULL;
t_psPlayground* selfRef;

BEGIN_USING_C_LINKAGE
t_jit_err psPlayground_init(void);
t_psPlayground *psPlayground_new(t_symbol * dest_name);
void psPlayground_free(t_psPlayground *x);
t_jit_err psPlayground_draw(t_psPlayground *x);
t_jit_err psPlayground_dest_closing(t_psPlayground *x);
t_jit_err psPlayground_dest_changed(t_psPlayground *x);
t_jit_err build_simple_chunk(t_psPlayground *x);
t_jit_err psPlayground_pspMngMessageControl(t_psPlayground *x, void *attr, long argc, t_atom *argv);
t_jit_err psPlayground_update(t_psPlayground *x);
END_USING_C_LINKAGE

// --------------------------------------------------------------------------------




t_jit_err psPlayground_init(void) 
{

    long ob3d_flags = JIT_OB3D_NO_MATRIXOUTPUT; // no matrix output
	void *ob3d;
    
    t_jit_object *attr;
    long attrflags=0;
    
	_psPlayground_class = jit_class_new("psPlayground", 
		(method)psPlayground_new, (method)psPlayground_free,
		sizeof(t_psPlayground),A_DEFSYM,0L);
	
	// set up object extension for 3d object, customized with flags
	ob3d = jit_ob3d_setup(_psPlayground_class, 
				calcoffset(t_psPlayground, ob3d), 
				ob3d_flags);
	
	// define our OB3D draw method.  called in automatic mode by 
	// jit.gl.render or otherwise through ob3d when banged. this 
	// method is A_CANT because our draw setup needs to happen 
	// in the ob3d beforehand to initialize OpenGL state 
	jit_class_addmethod(_psPlayground_class, 
		(method)psPlayground_draw, "ob3d_draw", A_CANT, 0L);
	
	// define our dest_closing and dest_changed methods. 
	// these methods are called by jit.gl.render when the 
	// destination context closes or changes: for example, when 
	// the user moves the window from one monitor to another. Any 
	// resources your object keeps in the OpenGL machine 
	// (e.g. textures, display lists, vertex shaders, etc.) 
	// will need to be freed when closing, and rebuilt when it has 
	// changed. In this object, these functions do nothing, and 
	// could be omitted.
	jit_class_addmethod(_psPlayground_class, 
		(method)psPlayground_dest_closing, "dest_closing", A_CANT, 0L);
	jit_class_addmethod(_psPlayground_class, 
		(method)psPlayground_dest_changed, "dest_changed", A_CANT, 0L);
    
    //=================================
    //my attributes and messages
    attrflags = JIT_ATTR_GET_DEFER_LOW | JIT_ATTR_SET_USURP_LOW;
    
    attr = (t_jit_object*)jit_object_new(_jit_sym_jit_attr_offset, "psp", _jit_sym_atom, attrflags, (method)0L, (method)psPlayground_pspMngMessageControl, calcoffset(t_psPlayground, pspMngMessages));
	jit_class_addattr(_psPlayground_class, attr);
    

    //=================================
    
	// must register for ob3d use
	jit_class_addmethod(_psPlayground_class, 
		(method)jit_object_register, "register", A_CANT, 0L);

	jit_class_register(_psPlayground_class);
    
    
    
    

	return JIT_ERR_NONE;
}


t_psPlayground *psPlayground_new(t_symbol * dest_name)
{
    
    
    
    t_psPlayground *x;

	// make jit object
	if (x = (t_psPlayground *)jit_object_alloc(_psPlayground_class)) 
	{
		selfRef = x;
        // create and attach ob3d
		jit_ob3d_new(x, dest_name);
        
        x->pspMng = new psPlaygroundManager();
	} 
	else 
	{
		x = NULL;
	}	
	return x;
}


void psPlayground_free(t_psPlayground *x)
{
    
	delete x->pspMng;
    
	jit_ob3d_free(x);
}

t_jit_err psPlayground_dest_closing(t_psPlayground *x)
{
    
    // nothing in this object to free.
	return JIT_ERR_NONE;
}

t_jit_err psPlayground_dest_changed(t_psPlayground *x)
{
	// nothing in this object to update.
	return JIT_ERR_NONE;
}


t_jit_err psPlayground_update(t_psPlayground *x){
    
    
    x->pspMng->update();
    
    return JIT_ERR_NONE;
    
}




t_jit_err psPlayground_draw(t_psPlayground *x)
{

    psPlayground_update(x);
    x->pspMng->draw();
    
    
    
	return JIT_ERR_NONE;
}




t_jit_err psPlayground_pspMngMessageControl(t_psPlayground *x, void *attr, long argc, t_atom *argv)
{
    if(x && argv){
        x->pspMng->messageControl(argc, argv);
    }
    return JIT_ERR_NONE;
}



