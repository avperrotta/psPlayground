//
//  pspSystemsProperties.h
//  psPsa-001
//
//  Created by Andre Perrotta on 05/12/14.
//
//

#ifndef __psPsa_001__pspSystemsProperties__
#define __psPsa_001__pspSystemsProperties__

#include <iostream>
#include "../JuceLibraryCode/JuceHeader.h"
#include "pspParticleSystem.h"


class pspNumParticlesSlider : public SliderPropertyComponent{
public:
    pspNumParticlesSlider(const String& propertyName, pspParticleSystem* ms);
    
    ~pspNumParticlesSlider();
    
    void setValue (double newValue) override;
    void sliderValueChanged(Slider* slider) override;
    void sliderDragStarted(Slider*) override;
    void sliderDragEnded(Slider*) override;
    
protected:
    
    pspParticleSystem* mySystem;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspNumParticlesSlider);
};



class pspSystemsPropertiesComponent : public Component{
public:
    pspSystemsPropertiesComponent();
    pspSystemsPropertiesComponent(pspParticleSystem* ms);
    virtual ~pspSystemsPropertiesComponent();
    
    void setup();
    
    void paint(Graphics& g) override;
    void resized() override;
    
    void createGenericWidgets();
    virtual void createSpecificWidgets();
    
    pspParticleSystem* getSystem();
    
    
    virtual void sliderChanged(Slider* s);
    
protected:
    
    pspParticleSystem* mySystem;
    
    PropertyPanel panel;
    Array<PropertyComponent*> comps;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspSystemsPropertiesComponent);
};


class pspLimitSlider : public SliderPropertyComponent
{
public:
    pspLimitSlider (pspSystemsPropertiesComponent* pc, const String& propertyName, double min, double max, double step)
    : SliderPropertyComponent (propertyName, min, max, step)
    {
        myComponent = pc;
    }
    
    ~pspLimitSlider(){
        
        myComponent = nullptr;
        
    }
    
    void setValue (double newValue) override
    {
        slider.setValue (newValue);
    }
    
    void sliderValueChanged(Slider* slider) override{
        myComponent->sliderChanged(slider);
    }
    
    Slider* getSlider(){
        return &slider;
    }
    
private:
    
    pspSystemsPropertiesComponent* myComponent;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspLimitSlider)
};




#endif /* defined(__psPsa_001__pspSystemsProperties__) */
