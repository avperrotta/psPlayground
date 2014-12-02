//
//  pspSystemEditorGUI.h
//  psPsa-001
//
//  Created by Andre Perrotta on 02/12/14.
//
//

#ifndef __psPsa_001__pspSystemEditorGUI__
#define __psPsa_001__pspSystemEditorGUI__

#include <iostream>
#include "../JuceLibraryCode/JuceHeader.h"
#include "pspParticleSystemsManager.h"


class pspSystemEditorGUI : public Component, private Button::Listener, public ListBoxModel{
    
    
public:
    
    pspSystemEditorGUI();
    pspSystemEditorGUI(pspParticleSystemsManager* psm);
    ~pspSystemEditorGUI();
    
    void paint(Graphics& g) override;
    void resized() override;
    
    void buttonClicked(Button* buttonThatWasClicked) override;
    int getNumRows() override;
    void paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected) override;
    void listBoxItemClicked(int row, const MouseEvent &mevent) override;
    void selectedRowsChanged(int lastRowSelected) override;
    void deleteKeyPressed(int lastRowSelected) override;
    
    pspParticleSystemsManager* getPsManager();
    
private:
    
    
    
    pspParticleSystemsManager* psManager;
    //static void psItemDeleted(int result, pspSystemEditorGUI* p);
    
    ListBox systemsList;
    int lastSelectedPSystem;
    bool deletedSystem;
    static void psItemDeleted(int result, pspSystemEditorGUI* p);
    
    ScopedPointer<TextButton> addSystemsMenuButton;
    ScopedPointer<PopupMenu> addSystemsMenu;
    void populateAddSystemsMenu();
    static void addSystemsMenuItemSelected(int result, pspSystemEditorGUI* p);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pspSystemEditorGUI);
};


#endif /* defined(__psPsa_001__pspSystemEditorGUI__) */
