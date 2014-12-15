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
#include "OscOutboundPacketStream.h"
#include "pspGlobalVariables.h"


class pspParticleSystem;
class pspParticleSystemsManager;
class pspConcertRoom;

class pspParticle{
public:
    
    pspParticle();
    pspParticle(pspParticleSystem* ms, int ind);
    virtual ~pspParticle();
    
    void setup(pspParticleSystem* ms, int ind);
    void update();
    void draw();
    
    virtual void specificSetup();
    virtual void specificUpdate();
    virtual void specificDraw();
    
    void setVel(ofVec3f);
    void setVariance(double v);
    
    void setOscTag(bool ot);
    osc::OutboundPacketStream* getOscMsg();
    vector<double> getRawOscMsg();
    
protected:
    
    int index;
    
    double size;
    
    ofVec3f pos;
    ofVec3f vel;
    
    pspParticleSystem* mySystem;
    pspParticleSystemsManager* systemsManager;
    pspConcertRoom* myConcertRoom;
    
    double variance;
    
    vector<double> rawOscMsg;
    bool sendOsc;
    void createOscMessage();
    char buffer[OSC_MSG_BUFFER_SIZE];
    osc::OutboundPacketStream* oscMsg;
    
    
    void debug();
};




#endif /* defined(__psPsa_001__pspParticle__) */
