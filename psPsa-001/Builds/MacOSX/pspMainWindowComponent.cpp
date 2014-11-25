//
//  pspMainWindowComponent.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 21/11/14.
//
//


#include "pspMainWindowComponent.h"

pspMainWindowComponent::pspMainWindowComponent(MainContentComponent& mcc, pspParticleSystemsManager* pm) : mainGLcomponent(mcc)
{
    
    
    addAndMakeVisible (quitButton = new TextButton (String::empty));
    quitButton->setButtonText ("Quit");
    quitButton->addListener (this);
    
    //main menu bar
    addAndMakeVisible (menuBar = new MenuBarComponent (this));
    
    
    //editor view stuff
    systemsList.setModel (this);
    systemsList.setColour (ListBox::backgroundColourId, Colour::greyLevel (0.3f));
    systemsList.selectRow (0);
    addChildComponent(systemsList);
    deletedSystem = false;
    
    
    
    //psp
    pspManager = pm;
    
    setSize (800, 600);
    
}

pspMainWindowComponent::~pspMainWindowComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]
    quitButton = nullptr;
    pspManager = nullptr;
    
    #if JUCE_MAC
        MenuBarModel::setMacMainMenu (nullptr);
    #endif
    
    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void pspMainWindowComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]
    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void pspMainWindowComponent::resized()
{
    
    Rectangle<int> area (getLocalBounds());
    
    
    menuBar->setBounds (area.removeFromTop(LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));
    
    quitButton->setBounds (getWidth() - 176, getHeight() - 60, 120, 32);
    
    if (area.getWidth() > 600){
        systemsList.setBounds (area.removeFromLeft(150));
        systemsList.setRowHeight (20);
    }
    else{
        systemsList.setBounds (area.removeFromLeft(130));
        systemsList.setRowHeight (30);
    }
    
    
    
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}


void pspMainWindowComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]
    
    if (buttonThatWasClicked == quitButton)
    {
        //[UserButtonCode_quitButton] -- add your button handler code here..
        
        JUCEApplication::quit();
        
        //[/UserButtonCode_quitButton]
    }
    
    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

//================================================
//MenuBarModel methods
StringArray pspMainWindowComponent::getMenuBarNames()
{
    const char* const names[] = { "File", "View", "Edit", nullptr };
    
    return StringArray (names);
}

PopupMenu pspMainWindowComponent::getMenuForIndex (int menuIndex, const String& /*menuName*/)
{
    PopupMenu menu;
    
    if (menuIndex == 0)
    {
        menu.addItem(1, "Save");
        menu.addItem(2, "Load");
    }
    else if(menuIndex == 1){
        menu.addItem(3, "Editor");
        menu.addItem(4, "Room config");
        menu.addItem(5, "Spatialization config");
        
    }
    
    
    return menu;
}
void pspMainWindowComponent::menuItemSelected (int menuItemID, int /*topLevelMenuIndex*/)
{
    std::cout<<std::endl<<menuItemID;
    
    if(menuItemID == 3){
        quitButton->setVisible(false);
        getNumRows();
        systemsList.setVisible(true);
        
    }
    else{
        systemsList.setVisible(false);
        quitButton->setVisible(true);
    }
}
//================================================

//================================================
//ListBoxModel methods
int pspMainWindowComponent::getNumRows(){
    
    if(pspManager != nullptr){
        return pspManager->getNumSystems();
    }
    else{
        return 0;
    }
}
void pspMainWindowComponent::paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected){
    if (rowIsSelected){
        g.fillAll (Colours::deepskyblue);
    }
    
    String name;
    String type;
    String separator;
    separator = " : ";
    AttributedString a;
    a.setJustification (Justification::centredLeft);
    
    name = pspManager->getSystemName(rowNumber);
    type = pspManager->getSystemType(rowNumber);
    
    a.append (type, Font (12.0f), Colour::greyLevel (0.5f));
    a.append(separator, Font (12.0f), Colour::greyLevel (0.5f));
    a.append (name, Font (14.0f), Colours::white.withAlpha (1.0f));
    
    a.draw (g, Rectangle<int> (width + 10, height).reduced (6, 0).toFloat());
}

void pspMainWindowComponent::listBoxItemClicked(int row, const MouseEvent &){
    pspManager->getSystem(row)->setFocus(true);
    lastSelectedPSystem = row;
}

void pspMainWindowComponent::selectedRowsChanged(int lastRowSelected){
    if(deletedSystem){
        //pspManager->getSystem(-1)->setFocus(false);
        deletedSystem = false;
    }
    else{
        pspManager->getSystem(lastRowSelected)->setFocus(false);
    }
    
}


void pspMainWindowComponent::deleteKeyPressed(int lastRowSelected){
    AlertWindow::showOkCancelBox (AlertWindow::QuestionIcon,
                                  "Delete Particle System:",
                                  pspManager->getSystemType(lastRowSelected) + ": " + pspManager->getSystemName(lastRowSelected),
                                  String::empty,
                                  String::empty,
                                  0,
                                  ModalCallbackFunction::forComponent(psItemDeleted, this));
}

void pspMainWindowComponent::psItemDeleted(int result, pspMainWindowComponent* p)
{
    if(result == 1){
        p->deletedSystem = true;
        p->getPspManager()->deleteSystem(p->lastSelectedPSystem);
        p->systemsList.removeChildComponent(p->systemsList.getComponentForRowNumber(p->lastSelectedPSystem));
        p->systemsList.updateContent();
        p->systemsList.deselectAllRows();
    }
}




/*
Component* pspMainWindowComponent::refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate){
    
}
void pspMainWindowComponent::listBoxItemClicked(int row, const MouseEvent &){
    
}
void pspMainWindowComponent::listBoxItemDoubleClicked(int row, const MouseEvent &){
    
}
void pspMainWindowComponent::backgroundClicked(const MouseEvent &){

}
void pspMainWindowComponent::selectedRowsChanged(int lastRowSelected){
    
}
void pspMainWindowComponent::returnKeyPressed(int lastRowSelected){
    
}
void pspMainWindowComponent::listWasScrolled(){
    
}
var pspMainWindowComponent::getDragSourceDescription(const SparseSet< int > &currentlySelectedRows){
    
}
String pspMainWindowComponent::getTooltipForRow(int row){
    
}
MouseCursor pspMainWindowComponent::getMouseCursorForRow(int row){
    
}
*/




//================================================

//================================================
//psp stuf
pspParticleSystemsManager* pspMainWindowComponent::getPspManager(){
    return pspManager;
}

//================================================
//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --
 
 This is where the Introjucer stores the metadata that describe this GUI layout, so
 make changes in here at your peril!
 
 BEGIN_JUCER_METADATA
 
 <JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
 parentClasses="public Component" constructorParams="" variableInitialisers=""
 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
 fixedSize="1" initialWidth="600" initialHeight="300">
 <BACKGROUND backgroundColour="ffc1d0ff">
 <PATH pos="0 0 100 100" fill="solid: ffffffff" hasStroke="1" stroke="5.19999981, mitered, butt"
 strokeColour="solid: ff6f6f6f" nonZeroWinding="1">s 136 80 q 176 24 328 32 q 472 40 472 104 q 472 192 232 176 l 184 216 l 200 168 q 96 136 136 80 x</PATH>
 </BACKGROUND>
 <LABEL name="" id="be4f6f2e5725a063" memberName="helloWorldLabel" virtualName=""
 explicitFocusOrder="0" pos="152 80 296 48" textCol="ff000000"
 edTextCol="ff000000" edBkgCol="0" labelText="Hello World!" editableSingleClick="0"
 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
 fontsize="40" bold="1" italic="0" justification="36"/>
 <TEXTBUTTON name="" id="bcf4f7b0888effe5" memberName="quitButton" virtualName=""
 explicitFocusOrder="0" pos="176R 60R 120 32" buttonText="Quit"
 connectedEdges="0" needsCallback="1" radioGroupId="0"/>
 </JUCER_COMPONENT>
 
 END_JUCER_METADATA
 */
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]