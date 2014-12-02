//
//  pspSystemEditorGUI.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 02/12/14.
//
//

#include "pspSystemEditorGUI.h"


pspSystemEditorGUI::pspSystemEditorGUI(){
    
}
pspSystemEditorGUI::pspSystemEditorGUI(pspParticleSystemsManager* psm){
    psManager = psm;
    
    systemsList.setModel (this);
    systemsList.setColour (ListBox::backgroundColourId, Colour::greyLevel(0.4f));
    addAndMakeVisible(systemsList);
    
}
pspSystemEditorGUI::~pspSystemEditorGUI(){
    
}

void pspSystemEditorGUI::paint (Graphics& g){
    
}
void pspSystemEditorGUI::resized(){
    systemsList.setBounds(getLocalBounds().reduced(4));
}

void pspSystemEditorGUI::buttonClicked (Button* buttonThatWasClicked){
    
}
int pspSystemEditorGUI::getNumRows(){
    if(psManager != nullptr){
        return psManager->getNumSystems();
    }
    else{
        return 0;
    }
}

void pspSystemEditorGUI::paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected){
    if (rowIsSelected){
        g.fillAll (Colours::midnightblue.brighter());
    }
    
    String name;
    String type;
    String separator;
    separator = " : ";
    AttributedString a;
    a.setJustification (Justification::centredLeft);
    
    name = psManager->getSystemName(rowNumber);
    type = psManager->getSystemType(rowNumber);

    a.append (type, Font (12.0f), Colour::greyLevel (0.7f));
    a.append(separator, Font (12.0f), Colour::greyLevel (0.7f));
    a.append (name, Font (14.0f), Colours::white.withAlpha (1.0f));
    
    a.draw (g, Rectangle<int> (width + 10, height).reduced (6, 0).toFloat());
}
void pspSystemEditorGUI::listBoxItemClicked(int row, const MouseEvent &){
    psManager->getSystem(row)->setFocus(true);
    lastSelectedPSystem = row;
}

void pspSystemEditorGUI::selectedRowsChanged(int lastRowSelected){
    if(deletedSystem){
        //pspManager->getSystem(-1)->setFocus(false);
        deletedSystem = false;
    }
    else{
        psManager->getSystem(lastRowSelected)->setFocus(false);
    }
}

void pspSystemEditorGUI::deleteKeyPressed(int lastRowSelected){
    AlertWindow::showOkCancelBox (AlertWindow::QuestionIcon,
                                  "Delete Particle System:",
                                  psManager->getSystemType(lastRowSelected) + ": " + psManager->getSystemName(lastRowSelected),
                                  String::empty,
                                  String::empty,
                                  0,
                                  ModalCallbackFunction::forComponent(psItemDeleted, this));
}

void pspSystemEditorGUI::psItemDeleted(int result, pspSystemEditorGUI* p)
{
    if(result == 1){
        p->deletedSystem = true;
        p->getPsManager()->deleteSystem(p->lastSelectedPSystem);
        p->systemsList.removeChildComponent(p->systemsList.getComponentForRowNumber(p->lastSelectedPSystem));
        p->systemsList.updateContent();
        p->systemsList.deselectAllRows();
    }
}

pspParticleSystemsManager* pspSystemEditorGUI::getPsManager(){
    return psManager;
}