//-----------------------------------------------------
// name: "freeverb"
// version: "1.0"
// author: "Grame"
// license: "BSD"
// copyright: "(c) GRAME 2006"
//
// Code generated with Faust 0.9.66 (http://faust.grame.fr)
//-----------------------------------------------------
/* link with  */
/************************************************************************

	IMPORTANT NOTE : this file contains two clearly delimited sections :
	the ARCHITECTURE section (in two parts) and the USER section. Each section
	is governed by its own copyright and license. Please check individually
	each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
	Copyright (C) 2004-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either version 3
	of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

	EXCEPTION : As a special exception, you may create a larger work
	that contains this FAUST architecture section and distribute
	that work under terms of your choice, so long as this FAUST
	architecture section is not modified.

	MAX MSP SDK : in order to compile a MaxMSP external with this
	architecture file you will need the official MaxMSP SDK from
	cycling'74. Please check the corresponding license.

 ************************************************************************
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>

#include <iostream>
#include <fstream>
#include <sstream>

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#include <unistd.h>
#endif

#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

class UI
{

 public:

	UI() {}

	virtual ~UI() {}

    // -- widget's layouts

    virtual void openTabBox(const char* label) = 0;
    virtual void openHorizontalBox(const char* label) = 0;
    virtual void openVerticalBox(const char* label) = 0;
    virtual void closeBox() = 0;

    // -- active widgets

    virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

    // -- passive widgets

    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

	// -- metadata declarations

    virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************************************************************
	IMPORTANT NOTE : this file contains two clearly delimited sections :
	the ARCHITECTURE section (in two parts) and the USER section. Each section
	is governed by its own copyright and license. Please check individually
	each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

	EXCEPTION : As a special exception, you may create a larger work
	that contains this FAUST architecture section and distribute
	that work under terms of your choice, so long as this FAUST
	architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;

//----------------------------------------------------------------
//  signal processor definition
//----------------------------------------------------------------

class dsp {
 protected:
	int fSamplingFreq;
 public:
	dsp() {}
	virtual ~dsp() {}

	virtual int getNumInputs() 										= 0;
	virtual int getNumOutputs() 									= 0;
	virtual void buildUserInterface(UI* ui_interface) 				= 0;
	virtual void init(int samplingRate) 							= 0;
 	virtual void compute(int len, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) 	= 0;
};

// On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
// flags to avoid costly denormals
#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>

/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
};

#endif


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int	lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }
inline int 	int2pow2(int x)		{ int r=0; while ((1<<r)<x) r++; return r; }

long lopt(char *argv[], const char *name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

bool isopt(char *argv[], const char *name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

const char* lopts(char *argv[], const char *name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}
#endif


using namespace std;

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/********************END ARCHITECTURE SECTION (part 1/2)****************/

/**************************BEGIN USER SECTION **************************/

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

typedef long double quad;

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	float 	fRec9[2];
	FAUSTFLOAT 	fslider2;
	int 	IOTA;
	float 	fVec0[2048];
	float 	fRec8[2];
	float 	fRec11[2];
	float 	fVec1[2048];
	float 	fRec10[2];
	float 	fRec13[2];
	float 	fVec2[2048];
	float 	fRec12[2];
	float 	fRec15[2];
	float 	fVec3[2048];
	float 	fRec14[2];
	float 	fRec17[2];
	float 	fVec4[2048];
	float 	fRec16[2];
	float 	fRec19[2];
	float 	fVec5[2048];
	float 	fRec18[2];
	float 	fRec21[2];
	float 	fVec6[2048];
	float 	fRec20[2];
	float 	fRec23[2];
	float 	fVec7[2048];
	float 	fRec22[2];
	float 	fVec8[1024];
	float 	fRec6[2];
	float 	fVec9[512];
	float 	fRec4[2];
	float 	fVec10[512];
	float 	fRec2[2];
	float 	fVec11[256];
	float 	fRec0[2];
	float 	fRec33[2];
	float 	fVec12[2048];
	float 	fRec32[2];
	float 	fRec35[2];
	float 	fVec13[2048];
	float 	fRec34[2];
	float 	fRec37[2];
	float 	fVec14[2048];
	float 	fRec36[2];
	float 	fRec39[2];
	float 	fVec15[2048];
	float 	fRec38[2];
	float 	fRec41[2];
	float 	fVec16[2048];
	float 	fRec40[2];
	float 	fRec43[2];
	float 	fVec17[2048];
	float 	fRec42[2];
	float 	fRec45[2];
	float 	fVec18[2048];
	float 	fRec44[2];
	float 	fRec47[2];
	float 	fVec19[2048];
	float 	fRec46[2];
	float 	fVec20[1024];
	float 	fRec30[2];
	float 	fVec21[512];
	float 	fRec28[2];
	float 	fVec22[512];
	float 	fRec26[2];
	float 	fVec23[256];
	float 	fRec24[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("name", "freeverb");
		m->declare("version", "1.0");
		m->declare("author", "Grame");
		m->declare("license", "BSD");
		m->declare("copyright", "(c) GRAME 2006");
	}

	virtual int getNumInputs() 	{ return 2; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fslider0 = 0.3333f;
		fslider1 = 0.5f;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		fslider2 = 0.5f;
		IOTA = 0;
		for (int i=0; i<2048; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2048; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2048; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2048; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2048; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2048; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2048; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2048; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<1024; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<512; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<512; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<256; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2048; i++) fVec12[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2048; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2048; i++) fVec14[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2048; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2048; i++) fVec16[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2048; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2048; i++) fVec18[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2048; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<1024; i++) fVec20[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<512; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<512; i++) fVec22[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<256; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("Freeverb");
		interface->addHorizontalSlider("Damp", &fslider1, 0.5f, 0.0f, 1.0f, 0.025f);
		interface->addHorizontalSlider("RoomSize", &fslider2, 0.5f, 0.0f, 1.0f, 0.025f);
		interface->addHorizontalSlider("Wet", &fslider0, 0.3333f, 0.0f, 1.0f, 0.025f);
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = float(fslider0);
		float 	fSlow1 = (1 - fSlow0);
		float 	fSlow2 = (0.4f * float(fslider1));
		float 	fSlow3 = (1 - fSlow2);
		float 	fSlow4 = (0.7f + (0.28f * float(fslider2)));
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			float fTemp0 = (float)input0[i];
			fRec9[0] = ((fSlow2 * fRec9[1]) + (fSlow3 * fRec8[1]));
			float fTemp1 = (float)input1[i];
			float fTemp2 = (0.015f * (fTemp0 + fTemp1));
			fVec0[IOTA&2047] = (fTemp2 + (fSlow4 * fRec9[0]));
			fRec8[0] = fVec0[(IOTA-1617)&2047];
			fRec11[0] = ((fSlow2 * fRec11[1]) + (fSlow3 * fRec10[1]));
			fVec1[IOTA&2047] = (fTemp2 + (fSlow4 * fRec11[0]));
			fRec10[0] = fVec1[(IOTA-1557)&2047];
			fRec13[0] = ((fSlow2 * fRec13[1]) + (fSlow3 * fRec12[1]));
			fVec2[IOTA&2047] = (fTemp2 + (fSlow4 * fRec13[0]));
			fRec12[0] = fVec2[(IOTA-1491)&2047];
			fRec15[0] = ((fSlow2 * fRec15[1]) + (fSlow3 * fRec14[1]));
			fVec3[IOTA&2047] = (fTemp2 + (fSlow4 * fRec15[0]));
			fRec14[0] = fVec3[(IOTA-1422)&2047];
			fRec17[0] = ((fSlow2 * fRec17[1]) + (fSlow3 * fRec16[1]));
			fVec4[IOTA&2047] = (fTemp2 + (fSlow4 * fRec17[0]));
			fRec16[0] = fVec4[(IOTA-1356)&2047];
			fRec19[0] = ((fSlow2 * fRec19[1]) + (fSlow3 * fRec18[1]));
			fVec5[IOTA&2047] = (fTemp2 + (fSlow4 * fRec19[0]));
			fRec18[0] = fVec5[(IOTA-1277)&2047];
			fRec21[0] = ((fSlow2 * fRec21[1]) + (fSlow3 * fRec20[1]));
			fVec6[IOTA&2047] = (fTemp2 + (fSlow4 * fRec21[0]));
			fRec20[0] = fVec6[(IOTA-1188)&2047];
			fRec23[0] = ((fSlow2 * fRec23[1]) + (fSlow3 * fRec22[1]));
			fVec7[IOTA&2047] = ((fSlow4 * fRec23[0]) + fTemp2);
			fRec22[0] = fVec7[(IOTA-1116)&2047];
			float fTemp3 = (((((((fRec22[0] + fRec20[0]) + fRec18[0]) + fRec16[0]) + fRec14[0]) + fRec12[0]) + fRec10[0]) + fRec8[0]);
			fVec8[IOTA&1023] = (fTemp3 + (0.5f * fRec6[1]));
			fRec6[0] = fVec8[(IOTA-556)&1023];
			float 	fRec7 = (0 - (fTemp3 - fRec6[1]));
			fVec9[IOTA&511] = (fRec7 + (0.5f * fRec4[1]));
			fRec4[0] = fVec9[(IOTA-441)&511];
			float 	fRec5 = (fRec4[1] - fRec7);
			fVec10[IOTA&511] = (fRec5 + (0.5f * fRec2[1]));
			fRec2[0] = fVec10[(IOTA-341)&511];
			float 	fRec3 = (fRec2[1] - fRec5);
			fVec11[IOTA&255] = (fRec3 + (0.5f * fRec0[1]));
			fRec0[0] = fVec11[(IOTA-225)&255];
			float 	fRec1 = (fRec0[1] - fRec3);
			output0[i] = (FAUSTFLOAT)((fSlow0 * fRec1) + (fSlow1 * fTemp0));
			fRec33[0] = ((fSlow2 * fRec33[1]) + (fSlow3 * fRec32[1]));
			fVec12[IOTA&2047] = (fTemp2 + (fSlow4 * fRec33[0]));
			fRec32[0] = fVec12[(IOTA-1640)&2047];
			fRec35[0] = ((fSlow2 * fRec35[1]) + (fSlow3 * fRec34[1]));
			fVec13[IOTA&2047] = (fTemp2 + (fSlow4 * fRec35[0]));
			fRec34[0] = fVec13[(IOTA-1580)&2047];
			fRec37[0] = ((fSlow2 * fRec37[1]) + (fSlow3 * fRec36[1]));
			fVec14[IOTA&2047] = (fTemp2 + (fSlow4 * fRec37[0]));
			fRec36[0] = fVec14[(IOTA-1514)&2047];
			fRec39[0] = ((fSlow2 * fRec39[1]) + (fSlow3 * fRec38[1]));
			fVec15[IOTA&2047] = (fTemp2 + (fSlow4 * fRec39[0]));
			fRec38[0] = fVec15[(IOTA-1445)&2047];
			fRec41[0] = ((fSlow2 * fRec41[1]) + (fSlow3 * fRec40[1]));
			fVec16[IOTA&2047] = (fTemp2 + (fSlow4 * fRec41[0]));
			fRec40[0] = fVec16[(IOTA-1379)&2047];
			fRec43[0] = ((fSlow2 * fRec43[1]) + (fSlow3 * fRec42[1]));
			fVec17[IOTA&2047] = (fTemp2 + (fSlow4 * fRec43[0]));
			fRec42[0] = fVec17[(IOTA-1300)&2047];
			fRec45[0] = ((fSlow2 * fRec45[1]) + (fSlow3 * fRec44[1]));
			fVec18[IOTA&2047] = (fTemp2 + (fSlow4 * fRec45[0]));
			fRec44[0] = fVec18[(IOTA-1211)&2047];
			fRec47[0] = ((fSlow2 * fRec47[1]) + (fSlow3 * fRec46[1]));
			fVec19[IOTA&2047] = (fTemp2 + (fSlow4 * fRec47[0]));
			fRec46[0] = fVec19[(IOTA-1139)&2047];
			float fTemp4 = (((((((fRec46[0] + fRec44[0]) + fRec42[0]) + fRec40[0]) + fRec38[0]) + fRec36[0]) + fRec34[0]) + fRec32[0]);
			fVec20[IOTA&1023] = (fTemp4 + (0.5f * fRec30[1]));
			fRec30[0] = fVec20[(IOTA-579)&1023];
			float 	fRec31 = (0 - (fTemp4 - fRec30[1]));
			fVec21[IOTA&511] = (fRec31 + (0.5f * fRec28[1]));
			fRec28[0] = fVec21[(IOTA-464)&511];
			float 	fRec29 = (fRec28[1] - fRec31);
			fVec22[IOTA&511] = (fRec29 + (0.5f * fRec26[1]));
			fRec26[0] = fVec22[(IOTA-364)&511];
			float 	fRec27 = (fRec26[1] - fRec29);
			fVec23[IOTA&255] = (fRec27 + (0.5f * fRec24[1]));
			fRec24[0] = fVec23[(IOTA-248)&255];
			float 	fRec25 = (fRec24[1] - fRec27);
			output1[i] = (FAUSTFLOAT)((fSlow0 * fRec25) + (fSlow1 * fTemp1));
			// post processing
			fRec24[1] = fRec24[0];
			fRec26[1] = fRec26[0];
			fRec28[1] = fRec28[0];
			fRec30[1] = fRec30[0];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec8[1] = fRec8[0];
			IOTA = IOTA+1;
			fRec9[1] = fRec9[0];
		}
	}
};



/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/


/* Faust code wrapper ------- */

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include <string.h>

#define ASSIST_INLET 	1  		/* should be defined somewhere ?? */
#define ASSIST_OUTLET 	2		/* should be defined somewhere ?? */

#define EXTERNAL_VERSION "0.53"

class mspUI;

struct Max_Meta1 : Meta
{
    int fCount;
    
    Max_Meta1():fCount(0)
    {}
     
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            fCount++;
        }
    }
};

struct Max_Meta2 : Meta
{
    void declare(const char* key, const char* value)
    {
        if ((strcmp("name", key) == 0) || (strcmp("author", key) == 0)) {
            post("%s : %s", key, value);
        }
    }
};


/*--------------------------------------------------------------------------*/
typedef struct faust
{
    t_pxobject m_ob;
    t_atom *m_seen, *m_want;
    short m_where;
    bool m_mute;
    void** args;
    mspUI* dspUI;
    mydsp* dsp;
} t_faust;

void *faust_class;

/*--------------------------------------------------------------------------*/
class mspUIObject {

	protected:

		string fLabel;
		FAUSTFLOAT* fZone;

		FAUSTFLOAT range(FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT val) {return (val < min) ? min : (val > max) ? max : val;}

	public:

		mspUIObject(const string& label, FAUSTFLOAT* zone):fLabel(label),fZone(zone) {}
		virtual ~mspUIObject() {}

		virtual void setValue(double f) {*fZone = range(0.0,1.0,f);}
		virtual void toString(char* buffer) {}
		virtual string getName() {return fLabel;}
};

/*--------------------------------------------------------------------------*/
class mspCheckButton : public mspUIObject {

	public:

		mspCheckButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspCheckButton() {}

		void toString(char* buffer)
		{
            sprintf(buffer, "CheckButton(float): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspButton : public mspUIObject {

	public:

		mspButton(const string& label, FAUSTFLOAT* zone):mspUIObject(label,zone) {}
		virtual ~mspButton() {}

		void toString(char* buffer)
		{
            sprintf(buffer, "Button(float): %s", fLabel.c_str());
		}
};

/*--------------------------------------------------------------------------*/
class mspSlider : public mspUIObject{

	private:

		FAUSTFLOAT fInit;
		FAUSTFLOAT fMin;
		FAUSTFLOAT fMax;
		FAUSTFLOAT fStep;

	public:

		mspSlider(const string& label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
			:mspUIObject(label,zone),fInit(init),fMin(min),fMax(max),fStep(step) {}
		virtual ~mspSlider() {}

		void toString(char* buffer)
		{
            stringstream s; 
            s << "Slider(float): " << fLabel << " [init=" << fInit << ":min=" << fMin << ":max=" << fMax << ":step=" << fStep << ":cur=" << *fZone << "]";
            strcpy(buffer, s.str().c_str());
		}

		void setValue(double f) {*fZone = range(fMin,fMax,f);}
};

#define MULTI_SIZE  256

/*--------------------------------------------------------------------------*/
class mspUI : public UI
{
   private:

		map<string, mspUIObject*> fUITable;
        map<const char*, const char*> fDeclareTable;
        //FAUSTFLOAT* fMultiTable[MULTI_SIZE];
    
        string CreateLabel(const char* label)
        {
            map<const char*, const char*>::reverse_iterator it;
            if (fDeclareTable.size() > 0) {
                unsigned int i = 0;
                string res = string(label);
                char sep = '[';
                for (it = fDeclareTable.rbegin(); it != fDeclareTable.rend(); it++, i++) {
                    res = res + sep + (*it).first + ":" + (*it).second;
                    sep = ',';
                }
                res += ']';
                fDeclareTable.clear();
                return res;
            } else {
                return string(label);
            }
        }

	public:
    
		typedef map<string,mspUIObject*>::iterator iterator;

		mspUI() 
        {
            /*
     		for (int i = 0; i < MULTI_SIZE; i++) {
                fMultiTable[i] = 0;
            }
            */
        }
		virtual ~mspUI()
		{
			clear();
   		}
     
		void addButton(const char* label, FAUSTFLOAT* zone) {fUITable[string(label)] = new mspButton(CreateLabel(label), zone);}

		void addCheckButton(const char* label, FAUSTFLOAT* zone) {fUITable[string(label)] = new mspCheckButton(CreateLabel(label), zone);}

		void addSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            fUITable[string(label)] = new mspSlider(CreateLabel(label), zone, init, min, max, step);
        }
        
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }
        
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addSlider(label, zone, init, min, max, step);
        }

		void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
		{
			fUITable[string(label)] = new mspSlider(CreateLabel(label), zone, init, min, max, step);
		}
          
        // To be implemented
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {fDeclareTable.clear();}
		void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {fDeclareTable.clear();}
           
        void openTabBox(const char* label) {fDeclareTable.clear();}
		void openHorizontalBox(const char* label) {fDeclareTable.clear();}
		void openVerticalBox(const char* label) {fDeclareTable.clear();}
		void closeBox() {fDeclareTable.clear();}
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            /*
            if (strcmp(key,"multi") == 0) {
                int index = atoi(val);
                if (index >= 0 && index < MULTI_SIZE) {
                    fMultiTable[index] = zone;
                } else {
                    post("Invalid multi index = %d", index);
                }
            }
            */
            fDeclareTable[key] = val;
        }
        /*
        void setMultiValues(FAUSTFLOAT* multi, int buffer_size)
		{
			if (fMultiTable[index]) {
                *fMultiTable[index] = f;
            }
		}
        */
    
        bool isValue(string name) 
        {
            return fUITable.count(name);
        }

		bool setValue(string name, double f)
		{
     		if (fUITable.count(name)) {
                fUITable[name]->setValue(f);
                return true;
            } else {
                return false;
            }
		}
		iterator begin()	{ return fUITable.begin(); }
		iterator end()		{ return fUITable.end(); }
        
        int itemsCount() { return fUITable.size(); }
        void clear() 
        { 
            iterator it;
            for (it = begin(); it != end(); it++) {
                delete (*it).second;
            }
            fUITable.clear(); 
        }

};

//--------------------------------------------------------------------------
static bool check_digit(const string& name)
{
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) return true;
    }
    return false;
}

static int count_digit(const string& name)
{
    int count = 0;
    for (int i = name.size() - 1; i >= 0; i--) {
        if (isdigit(name[i])) count++;
    }
    return count;
}

void faust_method(t_faust* obj, t_symbol* s, short ac, t_atom* av)
{
    bool res = false;
    string name = string((s)->s_name);
     
    if (ac < 0) return;
    
    // Check if no argument is there, consider it is a toggle message for a button
    if (ac == 0 && obj->dspUI->isValue(name)) {
        
        string name = string((s)->s_name);
        float off = 0.0f;
        float on = 1.0f;
        obj->dspUI->setValue(name, off);
        obj->dspUI->setValue(name, on);
        
        av[0].a_type = A_FLOAT;
        av[0].a_w.w_float = off;
        faust_method(obj, s, 1, av);
        
        return;
    }
 
    // List of values
    if (check_digit(name)) {
        
        int ndigit = 0;
        int pos;
        
        for (pos = name.size() - 1; pos >= 0; pos--) {
            if (isdigit(name[pos]) || name[pos] == ' ') {
                ndigit++;
            } else {
                break;
            }
        }
        pos++;
        
        string prefix = name.substr(0, pos);
        string num_base = name.substr(pos);
        int num = atoi(num_base.c_str());
        
        int i;
        t_atom* ap;
       
        // Increment ap each time to get to the next atom
        for (i = 0, ap = av; i < ac; i++, ap++) {
            float value;
            switch (atom_gettype(ap)) {
                case A_LONG: {
                    value = (float)ap[0].a_w.w_long;
                    break;
                }
                case A_FLOAT:
                    value = ap[0].a_w.w_float;
                    break;
                    
                default:
                    post("Invalid argument in parameter setting"); 
                    return;         
            }
            
            stringstream num_val;
            num_val << num + i;
            char param_name[256];
            
            switch (ndigit - count_digit(num_val.str())) {
                case 0: 
                    sprintf(param_name, "%s%s", prefix.c_str(), num_val.str().c_str());
                    break;
                case 1: 
                    sprintf(param_name, "%s %s", prefix.c_str(), num_val.str().c_str());
                    break;
                case 2: 
                    sprintf(param_name, "%s  %s", prefix.c_str(), num_val.str().c_str());
                    break;
            }
            
            //printf("param_name = %s value = %f\n", param_name, value);
            res = obj->dspUI->setValue(param_name, value); // Doesn't have any effect if name is unknown
        }
    // Standard parameter
    } else {
        float value = (av[0].a_type == A_LONG) ? (float)av[0].a_w.w_long : av[0].a_w.w_float;
        //printf("name = %s value = %f\n", name.c_str(), value);
        res = obj->dspUI->setValue(name, value); // Doesn't have any effect if name is unknown
    }
    
    if (!res) {
        post("Unknown parameter : %s", (s)->s_name);
    }
}

/*--------------------------------------------------------------------------*/
void* faust_new(t_symbol* s, short ac, t_atom* av)
{
    t_faust* x = (t_faust*)newobject(faust_class);

    x->m_mute = false;

    x->dsp = new mydsp();
    x->dspUI = new mspUI();

    x->dsp->init(long(sys_getsr()));
    x->dsp->buildUserInterface(x->dspUI);

    x->args = (void**)calloc((x->dsp->getNumInputs()+x->dsp->getNumOutputs())+2, sizeof(void*));

    /* Multi in */
    dsp_setup((t_pxobject*)x, x->dsp->getNumInputs());

    /* Multi out */
    for (int i = 0; i< x->dsp->getNumOutputs(); i++) {
        outlet_new((t_pxobject*)x, (char*)"signal");
    }

    ((t_pxobject*)x)->z_misc = Z_NO_INPLACE; // To assure input and output buffers are actually different
    return x;
}

/*--------------------------------------------------------------------------*/
void faust_assist(t_faust* x, void* b, long msg, long a, char* dst)
{
    if (msg == ASSIST_INLET) {
        if (a == 0) {
            if (x->dsp->getNumInputs() == 0) {
                sprintf(dst, "(signal) : Unused Input");
            } else {
                sprintf(dst, "(signal) : Audio Input %ld", (a+1));
			}
			post((char*)"------------------");
			for (mspUI::iterator it = x->dspUI->begin(); it != x->dspUI->end(); ++it) {
				char param[256];
				it->second->toString(param);
				post(param);
			}
        } else if (a < x->dsp->getNumInputs()) {
            sprintf(dst, "(signal) : Audio Input %ld", (a+1));
        }
    } else if (msg == ASSIST_OUTLET) {
        sprintf(dst, "(signal) : Audio Output %ld", (a+1));
    }
}

/*--------------------------------------------------------------------------*/
void faust_mute(t_faust* obj, t_symbol* s, short ac, t_atom* at)
{
    if (atom_gettype(at) == A_LONG) {
        obj->m_mute = atom_getlong(at);
    }
}

/*--------------------------------------------------------------------------*/
void faust_free(t_faust* x)
{
	dsp_free((t_pxobject*)x);
	if (x->dsp) delete x->dsp;
	if (x->dspUI) delete x->dspUI;
	if (x->args) free(x->args);
}

/*--------------------------------------------------------------------------*/
t_int *faust_perform(t_int *w)
{
	t_faust* x = (t_faust*) (w[1]);
	long n = w[2];
	int offset = 3;
	AVOIDDENORMALS;
    if (x->m_mute) {
        float** outputs = ((float**)&w[offset+x->dsp->getNumInputs()]);
        // Write null buffers to outs
        for (int i = 0; i < x->dsp->getNumOutputs(); i++) {
             memset(outputs[i], 0, sizeof(float) * n);
        }
    } else {
        x->dsp->compute(n, ((float**)&w[offset]), ((float**)&w[offset+x->dsp->getNumInputs()]));
    }
	return (w + (x->dsp->getNumInputs()+x->dsp->getNumOutputs()) + 2 + 1);
}

/*--------------------------------------------------------------------------*/
void  faust_dsp(t_faust* x, t_signal **sp, short* count)
{
	x->args[0] = x;
	x->args[1] = (void*)sp[0]->s_n;
	for (int i = 0; i<(x->dsp->getNumInputs()+x->dsp->getNumOutputs()); i++) {
		x->args[i + 2] = sp[i]->s_vec;
    }
	dsp_addv(faust_perform, (x->dsp->getNumInputs()+x->dsp->getNumOutputs()) + 2, x->args);
}

/*--------------------------------------------------------------------------*/
extern "C" int main(void)
{
	setup((t_messlist**)&faust_class, (method)faust_new, (method)faust_free,
		(short)sizeof(t_faust), 0L, A_DEFFLOAT, 0);

	dsp* thedsp = new mydsp();
	mspUI dspUI;
 	thedsp->buildUserInterface(&dspUI);
  
	// Add the same method for every parameters and use the symbol as a selector
	// inside this method
	for (mspUI::iterator it = dspUI.begin(); it != dspUI.end(); ++it) {
        addmess((method)faust_method, (char*)(it->first.c_str()), A_GIMME, 0);
	}

	addmess((method)faust_dsp, (char*)"dsp", A_CANT, 0);
	addmess((method)faust_assist, (char*)"assist", A_CANT, 0);
    addmess((method)faust_mute, (char*)"mute", A_GIMME, 0);
	dsp_initclass();
    
    post((char*)"Faust DSP object 32 bits v%s", EXTERNAL_VERSION);
    post((char*)"Copyright (c) 2012-2014 Grame");
    Max_Meta1 meta1;
    mydsp::metadata(&meta1);
    if (meta1.fCount > 0) {
        Max_Meta2 meta2;
        post("------------------------------");
        mydsp::metadata(&meta2);
        post("------------------------------");
    }

    delete(thedsp);
	return 0;
}

/********************END ARCHITECTURE SECTION (part 2/2)****************/




