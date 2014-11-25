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


class pspParticle{
public:
    
    pspParticle();
    ~pspParticle();
    
    virtual void setup();
    virtual void update();
    virtual void draw();
    
private:
    
    
};




#endif /* defined(__psPsa_001__pspParticle__) */
