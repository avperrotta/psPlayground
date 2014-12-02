//
//  pspParticle.h
//  psPsa-001
//
//  Created by Andre Perrotta on 22/11/14.
//
//

#ifndef __psPsa_001__pspParticle__
#define __psPsa_001__pspParticle__

#include <iostream>
#include "../JuceLibraryCode/JuceHeader.h"
#include "ofVectorMath.h"
#include <OpenGL/OpenGL.h>
#include <OpenGl/gl.h>
#include <OpenGL/glu.h>

class pspParticleSystem;
class pspParticleSystemsManager;
class pspConcertRoom;

class pspParticle{
public:
    
    pspParticle();
    pspParticle(pspParticleSystem* ms, int ind);
    virtual ~pspParticle();
    
    void setup(pspParticleSystem* ms, int ind);
    virtual void specificSetup();
    virtual void update();
    virtual void draw();
    
    void setVel(ofVec3f);
    void setVariance(double v);
    
protected:
    
    int index;
    
    double size;
    
    ofVec3f pos;
    ofVec3f vel;
    
    pspParticleSystem* mySystem;
    pspParticleSystemsManager* systemsManager;
    pspConcertRoom* myConcertRoom;
    
    double variance;
    
};




#endif /* defined(__psPsa_001__pspParticle__) */
