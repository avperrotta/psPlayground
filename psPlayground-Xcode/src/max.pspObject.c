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
#include "pspGlobals.h"
#include "z_dsp.h"


typedef struct _max_psPlayground 
{
	t_object ob;
    void* m_outlet1;
    void* m_outlet2;
    void* m_outlet3;
    void* m_outlet4;
    void* m_outlet5;
    void* m_updateOutlet;
	void* obex;
} t_max_psPlayground;

t_jit_err psPlayground_init(void);

void *max_psPlayground_new(t_symbol *s, long argc, t_atom *argv);
void max_psPlayground_free(t_max_psPlayground *x);


t_class *max_psPlayground_class;
		 	



int C74_EXPORT main(void)
{	
	
    post("psPlayground version 1.0.0");
    post("created by André V. Perrotta");
    post("@ Porto - Portugal, 2014");
    post("www.avperrotta.org");
    
    
    t_class *maxclass, *jitclass;
	
	// create our Max class
	maxclass = class_new("psPlayground", (method)max_psPlayground_new, (method)max_psPlayground_free, sizeof(t_max_psPlayground), NULL, A_GIMME, 0);
    
    // initialize our Jitter class
	psPlayground_init();

	// specify a byte offset to keep additional information about our object
	max_jit_class_obex_setup(maxclass, calcoffset(t_max_psPlayground, obex));
	
	// look up our Jitter class in the class registry
	jitclass = jit_class_findbyname(gensym("psPlayground"));	
	
	// wrap our Jitter class with the standard methods for Jitter objects
    max_jit_class_wrap_standard(maxclass, jitclass, 0);
    			   
   	// use standard ob3d assist method
    class_addmethod(maxclass, (method)max_jit_ob3d_assist, "assist", A_CANT, 0);
    

	// add methods for 3d drawing
    max_jit_class_ob3d_wrap(maxclass);
    
    
	
	// register our class with max
	class_register(CLASS_BOX, maxclass);
	max_psPlayground_class = maxclass;
	return 0;
}









void max_psPlayground_free(t_max_psPlayground *x)
{
    
    // lookup our internal Jitter object instance and free
	jit_object_free(max_jit_obex_jitob_get(x));
	
	// free resources associated with our obex entry
	max_jit_object_free(x);
}

void *max_psPlayground_new(t_symbol *s, long argc, t_atom *argv)
{
	
    t_max_psPlayground *x;
	void *jit_ob;
	long attrstart;
	t_symbol *dest_name_sym = _jit_sym_nothing;

	if ((x = (t_max_psPlayground *)max_jit_object_alloc(max_psPlayground_class, gensym("psPlayground"))))
	{
		
        
        // get first normal arg, the destination name
		attrstart = max_jit_attr_args_offset(argc,argv);
		if (attrstart&&argv) 
		{
			jit_atom_arg_getsym(&dest_name_sym, 0, attrstart, argv);
		}

		// instantiate Jitter object with dest_name arg
		if ((jit_ob = jit_object_new(gensym("psPlayground"), dest_name_sym))) 
		{
			// set internal jitter object instance
			max_jit_obex_jitob_set(x, jit_ob);
			
            
            // add the update outlet (rightmost)
            x->m_updateOutlet = outlet_new(x, NULL);
            updateOutlet = x->m_updateOutlet;
			max_jit_obex_dumpout_set(x, x->m_updateOutlet);
            
            
            x->m_outlet1 = outlet_new(x, NULL);
            superOutlet1 = x->m_outlet1;
			max_jit_obex_dumpout_set(x, x->m_outlet1);
            
            x->m_outlet2 = outlet_new(x, NULL);
            superOutlet2 = x->m_outlet2;
			max_jit_obex_dumpout_set(x, x->m_outlet2);
            
            x->m_outlet3 = outlet_new(x, NULL);
            superOutlet3 = x->m_outlet3;
			max_jit_obex_dumpout_set(x, x->m_outlet3);
            
            x->m_outlet4 = outlet_new(x, NULL);
            superOutlet4 = x->m_outlet4;
			max_jit_obex_dumpout_set(x, x->m_outlet4);
            
            x->m_outlet5 = outlet_new(x, NULL);
            superOutlet5 = x->m_outlet5;
			max_jit_obex_dumpout_set(x, x->m_outlet5);
			
			// process attribute arguments 
			max_jit_attr_args(x, argc, argv);		
			
			// attach the jit object's ob3d to a new outlet 	
			// this outlet is used in matrixoutput mode
			max_jit_ob3d_attach(x, jit_ob, outlet_new(x, "jit_matrix"));
            
            
            

            

		} 
		else 
		{
			error("jit.gl.simple: could not allocate object");
			freeobject((t_object *)x);
			x = NULL;
		}
	}
	return (x);
}


