//
//  pspRandomSystem.h
//  psPsa-001
//
//  Created by Andre Perrotta on 02/12/14.
//
//

#ifndef __psPsa_001__pspRandomSystem__
#define __psPsa_001__pspRandomSystem__

#include <iostream>
#include "pspParticleSystem.h"
#include "pspMathUtils.h"
#include "pspRandomParticle.h"


using namespace std;

class pspParticleSystemsManager;

class pspRandomSystem : public pspParticleSystem{
    
public:
    
    pspRandomSystem(pspParticleSystemsManager* sm, String n, int np);
    ~pspRandomSystem();
    
    void specificSetup();
    void update();
    void drawParticles();
    void drawSystem();
    
    void showGui();
    
protected:
    
    CubeLimits* bounds;
    limits lx, ly, lz;
    
    void addParticleSpecific(int np);
    
};


class pspRandomSystemWGCC : public Component, public Slider::Listener, public ButtonListener{
public:
    
    pspRandomSystemWGCC();
    ~pspRandomSystemWGCC();
    
    void paint(Graphics& g)override;
    void resized()override;
    
    void sliderValueChanged(Slider* slider) override;
    void sliderDragStarted(Slider*) override;
    void sliderDragEnded(Slider*) override;
    
    void buttonClicked (Button* buttonThatWasClicked);
    
private:
    
    ScopedPointer<Slider> numParticles;
    ScopedPointer<TextButton> tester;
    ScopedPointer<Label> numParticlesLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspRandomSystemWGCC)
    
};


class pspRandomSystemWindowGui : public DocumentWindow, public ChangeListener{
    
public:
    
    pspRandomSystemWindowGui(pspRandomSystem* ms, const String& name, Colour backgroundColour, int buttonsNeeded);
    
    ~pspRandomSystemWindowGui();
    
    void paint(Graphics& g)override;
    void resized()override;
    
    
    void closeButtonPressed();
    
private:
    
    ScopedPointer<pspRandomSystemWGCC> myContent;
    
    pspRandomSystem* mySystem;
    
    void changeListenerCallback(ChangeBroadcaster* source);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspRandomSystemWindowGui)
    
};


#endif /* defined(__psPsa_001__pspRandomSystem__) */
