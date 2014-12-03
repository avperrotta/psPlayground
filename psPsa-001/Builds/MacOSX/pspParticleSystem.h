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
#include <OpenGL/OpenGL.h>
#include <OpenGl/gl.h>
#include <OpenGL/glu.h>

using namespace std;

class pspParticleSystemsManager;

class pspParticleSystem{
public:
    
    pspParticleSystem();
    pspParticleSystem(pspParticleSystemsManager* sm, String n, int np);
    virtual ~pspParticleSystem();
    
    void setup(pspParticleSystemsManager* sm, String n, int np);
    virtual void specificSetup();
    virtual void update();
    void draw();
    virtual void drawParticles();
    virtual void drawSystem();
    
    virtual void showGui();
    
    
    String getName();
    String getType();
    
    void setFocus(bool f);
    
    pspParticleSystemsManager* getManager();
    
    void addParticles(int np);
    void changeNumParticles(int np);
    void removeParticles(int np);
    
    void setColor(Colour c);
    
    
    
protected:
    
    pspParticleSystemsManager* systemsManager;
    String type;
    String name;
    bool focus;
    int numParticles;
    
    vector<pspParticle*>* particles;
    virtual void addParticleSpecific(int np);
    
    DocumentWindow* myGuiWindow;
    Array< Component::SafePointer<Component> > myGuiWindowRef;
    
    Colour myColour;
    double alpha;
    
};





#endif /* defined(__psPsa_001__pspParticleSystem__) */
