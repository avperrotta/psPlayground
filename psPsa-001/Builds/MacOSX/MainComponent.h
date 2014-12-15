//
//  MainComponent.h
//  psPsa-001
//
//  Created by Andre Perrotta on 22/11/14.
//
//

#ifndef psPsa_001_MainComponent_h
#define psPsa_001_MainComponent_h
#include "../JuceLibraryCode/JuceHeader.h"
#include "pspParticleSystemsManager.h"
#include "OscOutboundPacketStream.h"
#include "UdpSocket.h"
#include <OpenGL/OpenGL.h>
#include <OpenGl/gl.h>
#include <OpenGL/glu.h>
#include "WavefrontObjParser.h"
#include "BinaryData.h"
#include "pspRoomConfigGUI.h"
#include "pspSystemEditorGUI.h"

//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */
class MainContentComponent : public OpenGLAppComponent, public Slider::Listener, public ButtonListener, public MenuBarModel
{
public:
    //==============================================================================
    MainContentComponent();
    
    ~MainContentComponent();
    
    void initialise() override;
    void shutdown();
    void render() override;
    
    void paint (Graphics& g) override;
    void resized() override;
    
    //psp
    pspParticleSystemsManager* getPspManager();
    
    
    //widgets
    double zoom;
    double xOffset;
    void setXOffset(double xo);
    
    double roll;
    double pitch;
    double yaw;
    
    void sliderValueChanged(Slider* slider) override;
    void sliderDragStarted(Slider*) override;
    void sliderDragEnded(Slider*) override;
    void buttonClicked(Button* buttonThatWasClicked) override;
    
    StringArray getMenuBarNames() override;
    PopupMenu getMenuForIndex (int topLevelMenuIndex, const String &menuName) override;
    void menuItemSelected (int menuItemID, int /*topLevelMenuIndex*/) override;


private:
    //==============================================================================
    
    // private member variables
    
    //look and feel
    LookAndFeel_V1 lookAndFeelV1;
    LookAndFeel_V2 lookAndFeelV2;
    LookAndFeel_V3 lookAndFeelV3;
    
    //openGl view
    double currentFrameTime;
    double previousFrameTime;
    double frameRate;
    double previousFrameRate;
    ScopedPointer<Label> frameRateLabel;
    ScopedPointer<Slider> zoomSlider;
    ScopedPointer<Slider> rollSlider;
    ScopedPointer<Slider> pitchSlider;
    ScopedPointer<Slider> yawSlider;
    ScopedPointer<TextButton> view1;
    ScopedPointer<TextButton> view2;
    ScopedPointer<TextButton> view3;
    ScopedPointer<TextButton> view4;
    
    //menuBar
    ScopedPointer<MenuBarComponent> menuBar;
    
    //room config
    ScopedPointer<pspRoomConfigGUI> roomConfigGui;
    Array<PropertyComponent*> comps;
    
    //System editor
    ScopedPointer<pspSystemEditorGUI> systemEditorGui;
    
    void createViewWidgets();
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
    
    
    //psp
    pspParticleSystemsManager* pspManager;
    
    bool firstSetting;
    
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent(){
    return new MainContentComponent();
}





#endif
