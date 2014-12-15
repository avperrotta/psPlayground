//
//  pspSystemsProperties.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 05/12/14.
//
//

#include "pspSystemsProperties.h"
//===========================================
//genericPropertiesComponent
pspSystemsPropertiesComponent::pspSystemsPropertiesComponent(){
    pspSystemsPropertiesComponent(NULL);
}


pspSystemsPropertiesComponent::pspSystemsPropertiesComponent(pspParticleSystem* ms){
    mySystem = ms;
    
}


pspSystemsPropertiesComponent::~pspSystemsPropertiesComponent(){
    
}


void pspSystemsPropertiesComponent::setup(){
    addAndMakeVisible(panel);
    createGenericWidgets();
    createSpecificWidgets();
    setName(mySystem->getType() + ":" + mySystem->getName());
}

void pspSystemsPropertiesComponent::paint (Graphics& g){
    
    g.fillAll (Colour::greyLevel (0.8f));
    
}

void pspSystemsPropertiesComponent::resized(){
    
    panel.setBounds(getLocalBounds().reduced(4));
}

void pspSystemsPropertiesComponent::createGenericWidgets(){
    comps.clear();
    comps.add(new pspNumParticlesSlider("num particles", this->mySystem));
    panel.addSection("Generic attributes", comps);
}

void pspSystemsPropertiesComponent::createSpecificWidgets(){
    
}

pspParticleSystem* pspSystemsPropertiesComponent::getSystem(){
    return mySystem;
}

void pspSystemsPropertiesComponent::sliderChanged(Slider* s){
    
}

//===========================================


//===========================================
//NumParticlesSlider

pspNumParticlesSlider::pspNumParticlesSlider(const String& propertyName, pspParticleSystem* ms):SliderPropertyComponent(propertyName, 0, 2000, 1){
    
    mySystem = ms;
    
    //slider.setValue(1);
    setValue(mySystem->getNumParticles());
    slider.setSliderStyle(Slider::IncDecButtons);
    slider.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    slider.setIncDecButtonsMode (Slider::incDecButtonsDraggable_Vertical);
}

pspNumParticlesSlider::~pspNumParticlesSlider(){
    mySystem = nullptr;
}

void pspNumParticlesSlider::setValue (double newValue){
    slider.setValue (newValue);
    //cout<<endl<<"slider value = "<<newValue;
}

void pspNumParticlesSlider::sliderValueChanged(Slider* slider){
    mySystem->changeNumParticles(slider->getValue());
}

void pspNumParticlesSlider::sliderDragStarted(Slider*){
    
}

void pspNumParticlesSlider::sliderDragEnded(Slider*){
    
}
//===========================================



