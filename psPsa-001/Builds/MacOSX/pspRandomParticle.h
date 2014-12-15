//
//  pspRandomParticle.h
//  psPsa-001
//
//  Created by Andre Perrotta on 02/12/14.
//
//

#ifndef __psPsa_001__pspRandomParticle__
#define __psPsa_001__pspRandomParticle__

#include <iostream>
#include "pspParticle.h"
#include "pspMathUtils.h"

class pspRandomParticle : public pspParticle{
public:
    
    pspRandomParticle();
    pspRandomParticle(pspParticleSystem* ms, int ind);
    ~pspRandomParticle();
    
    void specificSetup();
    void specificUpdate();
    void specificDraw();
    
    void setBounds(CubeLimits* b);
    
protected:
    
    CubeLimits* bounds;
    
    ofVec3f posNext;
    
};


#endif /* defined(__psPsa_001__pspRandomParticle__) */
