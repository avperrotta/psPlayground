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
    
    angle = -10.;
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
    jassert (OpenGLHelpers::isContextActive());
    OpenGLHelpers::clear (Colour::greyLevel(0.9));
    
    const float desktopScale = (float) openGLContext.getRenderingScale();
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_SCALE);
    glEnable(GL_DEPTH_TEST);
    
    glViewport (0, 0, roundToInt (desktopScale * getWidth()), roundToInt (desktopScale * getHeight()));
    
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30., 1.0, 3.0, 70.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    
    
    
    
    //glMatrixMode (GL_MODELVIEW);
    
    glEnable (GL_BLEND);
    glPushMatrix();
    glTranslated(0., 0., 0.);
    glRotated(0., 0, 1, 0);
    glRotated(0, 1, 0, 0);
    pspManager->draw();
    glPopMatrix();
    glDisable(GL_BLEND);
    
    
    
    angle += 0.01;
    cout<<endl<<angle;
    
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
//==================================================
//==================================================
//openGl
Matrix3D<float> MainContentComponent::getProjectionMatrix() const
{
    float w = 1.0f / (0.5 + 0.1f);
    float h = w * getLocalBounds().toFloat().getAspectRatio (false);
    return Matrix3D<float>::fromFrustum (-w, w, -h, h, 4.0f, 30.0f);
}

Matrix3D<float> MainContentComponent::getViewMatrix() const
{
    Matrix3D<float> viewMatrix (Vector3D<float> (0.0f, 0.0f, -10.0f));
    Matrix3D<float> rotationMatrix = viewMatrix.rotated (Vector3D<float> (-0.3f, 5.0f*sin(getFrameCounter()*0.01f), 0.0f));
    
    return viewMatrix * rotationMatrix;
}

