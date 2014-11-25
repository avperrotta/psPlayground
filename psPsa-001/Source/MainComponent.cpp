/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#include "MainComponent.h"

MainContentComponent::MainContentComponent(){
    
    //psp
    pspManager = new pspParticleSystemsManager();
    
    
    addAndMakeVisible (mainWidgets = new pspMainWindowComponent(*this, pspManager));
    setSize (800, 600);
}

MainContentComponent::~MainContentComponent(){
    shutdownOpenGL();
    mainWidgets = nullptr;
    delete pspManager;
    
}

void MainContentComponent::initialise(){
}

void MainContentComponent::shutdown(){
}

void MainContentComponent::render(){
    
    pspManager->update();
    pspManager->draw();
    
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0, 0);
    glEnd();
    glPopMatrix();
    
    
    
    
    UdpTransmitSocket transmitSocket( IpEndpointName( "127.0.0.1", 7000 ) );
    
    char buffer[1024];
    osc::OutboundPacketStream p( buffer, 1024 );
    
    p << osc::BeginBundleImmediate
    << osc::BeginMessage( "/test1" )
    << true << 23 << (float)3.1415 << "hello" << osc::EndMessage
    << osc::BeginMessage( "/test2" )
    << true << 24 << (float)10.8 << "world" << osc::EndMessage
    << osc::EndBundle;
    transmitSocket.Send( p.Data(), p.Size() );
    
    juce::Thread::sleep(1000/30);
}

void MainContentComponent::paint (Graphics& g){
    // You can add your component specific drawing code here!
    // This will draw over the top of the openGL background.
}

void MainContentComponent::resized(){
    
    Rectangle<int> r (getLocalBounds());
    
    if (mainWidgets != nullptr)
        mainWidgets->setBounds (r);
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

//==================================================
//psp
pspParticleSystemsManager* MainContentComponent::getPspManager(){
    if(pspManager == nullptr){
        pspManager = new pspParticleSystemsManager();
    }
    return pspManager;
    
}



