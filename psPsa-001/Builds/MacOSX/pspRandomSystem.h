//
//  pspRandomSystem.h
//  psPsa-001
//
//  Created by Andre Perrotta on 02/12/14.
//
//

#ifndef __psPsa_001__pspRandomSystem__
#define __psPsa_001__pspRandomSystem__
#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>
#include "pspParticleSystem.h"
#include "pspMathUtils.h"
#include "pspRandomParticle.h"
#include "pspSystemsProperties.h"


using namespace std;

class pspParticleSystemsManager;

class pspRandomSystem : public pspParticleSystem{
    
public:
    
    pspRandomSystem(pspParticleSystemsManager* sm, String n, int np);
    ~pspRandomSystem();
    
    void specificSetup();
    void specificUpdate();
    void drawParticles();
    void drawSystem();
    
    void showGui();
    
    void setBounds(CubeLimits cl) override;
    CubeLimits* getBounds();
    
protected:
    
    CubeLimits* bounds;
    limits lx, ly, lz;
    
    void addParticleSpecific(int np);
    
};


class pspRandomSystemPropertiesComponent : public pspSystemsPropertiesComponent{
public:
    
    pspRandomSystemPropertiesComponent(pspRandomSystem* ms);
    ~pspRandomSystemPropertiesComponent();
    
    void createSpecificWidgets();
    void sliderChanged(Slider* s);
    
protected:
    
    
    //pspRandomSystem* mySystem;
    
    pspLimitSlider* minlx;
    pspLimitSlider* minly;
    pspLimitSlider* minlz;
    
    pspLimitSlider* maxlx;
    pspLimitSlider* maxly;
    pspLimitSlider* maxlz;
    
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspRandomSystemPropertiesComponent);
    
};


class pspRandomSystemWindowGui : public DocumentWindow{
    
public:
    
    pspRandomSystemWindowGui(pspRandomSystem* ms, const String& name, Colour backgroundColour, int buttonsNeeded);
    
    ~pspRandomSystemWindowGui();
    
    void paint(Graphics& g)override;
    void resized()override;
    
    
    void closeButtonPressed();
    
protected:
    
    ScopedPointer<pspRandomSystemPropertiesComponent> myContent;
    
    pspRandomSystem* mySystem;
    
    void changeListenerCallback(ChangeBroadcaster* source);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspRandomSystemWindowGui);
    
};


#endif /* defined(__psPsa_001__pspRandomSystem__) */
