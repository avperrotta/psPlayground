//
//  pspParticleSystem.h
//  psPsa-001
//
//  Created by Andre Perrotta on 22/11/14.
//
//

#ifndef __psPsa_001__pspParticleSystem__
#define __psPsa_001__pspParticleSystem__

#include <iostream>
#include "../JuceLibraryCode/JuceHeader.h"
#include "pspParticle.h"

using namespace std;

class pspParticleSystem : public Component{
public:
    
    pspParticleSystem();
    pspParticleSystem(String n);
    virtual ~pspParticleSystem();
    
    virtual void setup();
    virtual void update();
    virtual void draw();
    
    String getName();
    String getType();
    
    void setFocus(bool f);
    
private:
    
    String type;
    String name;
    
    bool focus;
    
    vector<pspParticle*>* particles;
    
    
};


#endif /* defined(__psPsa_001__pspParticleSystem__) */
