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
#include "pspMainWindowComponent.h"
#include "pspParticleSystemsManager.h"
#include "OscOutboundPacketStream.h"
#include "UdpSocket.h"
#include <OpenGL/OpenGL.h>
#include <OpenGl/gl.h>
#include <OpenGL/glu.h>
#include "WavefrontObjParser.h"
#include "BinaryData.h"


//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */
class MainContentComponent   : public OpenGLAppComponent
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
    
    
    //openGl
    
    
    
private:
    //==============================================================================
    
    // private member variables
    
    ScopedPointer<pspMainWindowComponent> mainWidgets;
    
    
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
