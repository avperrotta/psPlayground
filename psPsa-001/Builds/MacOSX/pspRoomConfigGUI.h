//
//  pspRoomConfigGUI.h
//  psPsa-001
//
//  Created by Andre Perrotta on 01/12/14.
//
//

#ifndef __psPsa_001__pspRoomConfigGUI__
#define __psPsa_001__pspRoomConfigGUI__
#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>

#include "pspParticleSystemsManager.h"
#include "pspConcertRoom.h"





class pspRoomConfigGUI : public Component{
    
public:
    
    pspRoomConfigGUI(),
    pspRoomConfigGUI(pspParticleSystemsManager* psm);
    ~pspRoomConfigGUI();
    
    void setup();
    void paint (Graphics& g) override;
    void resized() override;
    
    ConcertRoom* getConcertRoom();
    void setNumSpeakers(int n);
    void setSpeakerPosition(Slider* s);
    void setRoomSize(Slider* s);
    
private:
    
    pspParticleSystemsManager* myPsm;
    ConcertRoom* myCr;
    PropertyPanel panel;
    Array<PropertyComponent*> comps;
    
    int numSpeakers;
    
    void createWidgets();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspRoomConfigGUI);
    
};




class numSpeakersSlider : public SliderPropertyComponent{
public:
    numSpeakersSlider(const String& propertyName, pspRoomConfigGUI* mg):SliderPropertyComponent(propertyName, 1, 2000, 1)
    {
        
        myPsprc = mg;
        
        setValue(myPsprc->getConcertRoom()->getNumSpeakers());
        slider.setSliderStyle(Slider::IncDecButtons);
        slider.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
        slider.setIncDecButtonsMode (Slider::incDecButtonsDraggable_Vertical);
    }
    
    void setValue (double newValue) override
    {
        slider.setValue (newValue);
        //cout<<endl<<"slider value = "<<newValue;
    }
    
    void sliderValueChanged(Slider* slider) override{
        myPsprc->setNumSpeakers(slider->getValue());
    }
    
    void sliderDragStarted(Slider*) override{
        
    }
    
    void sliderDragEnded(Slider*) override{
        
    }
    
private:
    
    pspRoomConfigGUI* myPsprc;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (numSpeakersSlider)
};

class roomConfigSlider : public SliderPropertyComponent{
public:
    roomConfigSlider(const String& propertyName, pspRoomConfigGUI* mg):SliderPropertyComponent(propertyName, 0., 1., 0.01)
    {
        
        myPsprc = mg;
        
        setValue(1.);
    }
    
    void setValue (double newValue) override
    {
        slider.setValue (newValue);
    }
    
    void sliderValueChanged(Slider* slider) override{
        myPsprc->setRoomSize(slider);
    }
    
    void sliderDragStarted(Slider*) override{
        
    }
    
    void sliderDragEnded(Slider*) override{
        
    }
    
    
private:
    
    pspRoomConfigGUI* myPsprc;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (roomConfigSlider)
};

class speakerPositionSlider : public SliderPropertyComponent{
public:
    speakerPositionSlider(const String& propertyName, pspRoomConfigGUI* mg):SliderPropertyComponent(propertyName, -0.5, 0.5, 0.005)
    {
        
        myPsprc = mg;
        
        setValue(0.);
    }
    
    void setValue (double newValue) override
    {
        slider.setValue (newValue);
    }
    
    void sliderValueChanged(Slider* slider) override{
        myPsprc->setSpeakerPosition(slider);
    }
    
    void sliderDragStarted(Slider*) override{
        
    }
    
    void sliderDragEnded(Slider*) override{
        
    }
    
private:
    
    pspRoomConfigGUI* myPsprc;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (speakerPositionSlider)
};



class loadSpeakersSetupButton : public ButtonPropertyComponent
{
public:
    loadSpeakersSetupButton (const String& propertyName, pspRoomConfigGUI* mg):ButtonPropertyComponent(propertyName, true){
        
        myPsprc = mg;
        
    }
    
    void buttonClicked() override{
        cout<<endl<<"load speakers clicked";
    }
    
    String getButtonText() const override
    {
        return "load";
    }
    
private:
    
    pspRoomConfigGUI* myPsprc;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (loadSpeakersSetupButton)
};

class saveSpeakersSetupButton : public ButtonPropertyComponent
{
public:
    saveSpeakersSetupButton (const String& propertyName, pspRoomConfigGUI* mg):ButtonPropertyComponent(propertyName, true){
        myPsprc = mg;
    }
    
    void buttonClicked() override{
        cout<<endl<<"save speakers clicked";
    }
    
    String getButtonText() const override
    {
        return "save";
    }
    
private:
    
    pspRoomConfigGUI* myPsprc;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (saveSpeakersSetupButton)
};

#endif /* defined(__psPsa_001__pspRoomConfigGUI__) */
