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
    
    void setBounds(CubeLimits cl);
    CubeLimits* getBounds();
    
protected:
    
    CubeLimits* bounds;
    limits lx, ly, lz;
    
    void addParticleSpecific(int np);
    
};


class pspRandomSystemWGCC : public Component, public Slider::Listener, public ButtonListener, public TextEditor::Listener{
public:
    
    pspRandomSystemWGCC(pspRandomSystem* ms);
    ~pspRandomSystemWGCC();
    
    void paint(Graphics& g)override;
    void resized()override;
    
    void sliderValueChanged(Slider* slider) override;
    void sliderDragStarted(Slider*) override;
    void sliderDragEnded(Slider*) override;
    
    void buttonClicked (Button* buttonThatWasClicked);
    
    virtual void textEditorTextChanged(TextEditor& t) override;
    virtual void textEditorReturnKeyPressed(TextEditor& t) override;
    virtual void textEditorEscapeKeyPressed(TextEditor& t) override;
    virtual void textEditorFocusLost(TextEditor& t) override;
    
private:
    
    ScopedPointer<Slider> numParticles;
    ScopedPointer<Label> numParticlesLabel;
    
    ScopedPointer<Slider> limitsX;
    ScopedPointer<Label> limitsXLabel;
    ScopedPointer<TextEditor>lxmin;
    ScopedPointer<TextEditor>lxmax;
    
    ScopedPointer<Slider> limitsY;
    ScopedPointer<Label> limitsYLabel;
    ScopedPointer<TextEditor>lymin;
    ScopedPointer<TextEditor>lymax;
    
    ScopedPointer<Slider> limitsZ;
    ScopedPointer<Label> limitsZLabel;
    ScopedPointer<TextEditor>lzmin;
    ScopedPointer<TextEditor>lzmax;
    
    
    
    pspRandomSystem* mySystem;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspRandomSystemWGCC)
    
};


class pspRandomSystemWindowGui : public DocumentWindow{
    
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
