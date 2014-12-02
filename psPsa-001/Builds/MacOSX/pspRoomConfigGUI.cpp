//
//  pspRoomConfigGUI.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 01/12/14.
//
//

#include "pspRoomConfigGUI.h"
#include "juce_PropertyPanel.h"


//==========================================
//main GUI
pspRoomConfigGUI::pspRoomConfigGUI(){
    pspRoomConfigGUI(NULL);
}


pspRoomConfigGUI::pspRoomConfigGUI(pspParticleSystemsManager* psm){
    myPsm = psm;
    if(myPsm != NULL){
        myCr = psm->getConcertRoom();
        numSpeakers = myCr->getNumSpeakers();
    }
    
    setup();
    
}

pspRoomConfigGUI::~pspRoomConfigGUI(){
    comps.clear();
}

void pspRoomConfigGUI::setup(){
    
    setOpaque(true);
    setBounds(0, 0, 100, 100);
    addAndMakeVisible(panel);
    createWidgets();
    
    
}

void pspRoomConfigGUI::paint (Graphics& g){
    
    g.fillAll (Colour::greyLevel (0.8f));

}

void pspRoomConfigGUI::resized(){
    
    panel.setBounds(getLocalBounds().reduced(4));
}

void pspRoomConfigGUI::createWidgets(){
    comps.clear();
    comps.add(new loadSpeakersSetupButton("speakers setup", this));
    comps.add(new saveSpeakersSetupButton("speakers setup", this));
    comps.add(new numSpeakersSlider("num speakers ", this));
    comps.add(new roomConfigSlider("width", this));
    comps.add(new roomConfigSlider("lenght", this));
    comps.add(new roomConfigSlider("height", this));
    panel.addSection("Config", comps);
    
    
    for(int i=0; i<myCr->getNumSpeakers(); i++){
        comps.clear();
        comps.add(new speakerPositionSlider("x", this));
        comps[0]->setComponentID("xSpeaker:" + String(i+1));
        comps.add(new speakerPositionSlider("y", this));
        comps[1]->setComponentID("ySpeaker:" + String(i+1));
        comps.add(new speakerPositionSlider("z", this));
        comps[1]->setComponentID("zSpeaker:" + String(i+1));
        panel.addSection("Speaker: " + String(i + 1), comps);
    }
    //cout<<endl<<"panel size = "<<panel.getNumSections();
}

ConcertRoom* pspRoomConfigGUI::getConcertRoom(){
    return myCr;
}

void pspRoomConfigGUI::setNumSpeakers(int n){
    
    int currentNumSpeakers = myCr->getNumSpeakers();
    
    myCr->setNumSpeakers(n);
    
    
    if(n != currentNumSpeakers){
        //panel.clear();
        //createWidgets();
    }
    
    
    if(n > currentNumSpeakers){
        for(int i=currentNumSpeakers; i<n; i++){
            comps.clear();
            comps.add(new speakerPositionSlider("x", this));
            comps[0]->setComponentID("xSpeaker:" + String(i+1));
            comps.add(new speakerPositionSlider("y", this));
            comps[1]->setComponentID("ySpeaker:" + String(i+1));
            comps.add(new speakerPositionSlider("z", this));
            comps[1]->setComponentID("zSpeaker:" + String(i+1));
            panel.addSection("Speaker: " + String(i + 1), comps);
        }
    }
    else if(n < currentNumSpeakers){
        panel.removeLast(currentNumSpeakers - n);
        
    }
    
    //cout<<endl<<"panel size = "<<panel.getNumSections();
}

void pspRoomConfigGUI::setSpeakerPosition(Slider* s){
    
    int speakerIndex;
    String aux;
    aux = s->getParentComponent()->getParentComponent()->getName();
    speakerIndex = aux.substring(aux.lastIndexOf(":") + 1).getIntValue();
    
    int coor;
    
    if(s->getParentComponent()->getName() == "x"){
        coor = 1;
    }
    else if(s->getParentComponent()->getName() == "y"){
        coor = 2;
    }
    else if(s->getParentComponent()->getName() == "z"){
        coor = 3;
    }
    
    myCr->setSpeakerPosition(speakerIndex, coor, s->getValue());
}

void pspRoomConfigGUI::setRoomSize(Slider* s){
    
    int coor;
    
    if(s->getParentComponent()->getName() == "width"){
        coor = 1;
    }
    else if(s->getParentComponent()->getName() == "height"){
        coor = 2;
    }
    else if(s->getParentComponent()->getName() == "lenght"){
        coor = 3;
    }
    
    myCr->setBounds(coor, s->getValue());
}

//=============================================
