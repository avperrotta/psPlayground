/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#include "MainComponent.h"


MainContentComponent::MainContentComponent(){
    
    
    
    //psp
    pspManager = new pspParticleSystemsManager();
    
    createViewWidgets();
    
    setSize (800, 600);
    
    currentFrameTime = juce::Time::currentTimeMillis();
    previousFrameRate = 0.;
   
}

MainContentComponent::~MainContentComponent(){
    shutdownOpenGL();
    delete pspManager;
    
}

void MainContentComponent::initialise(){
    xOffset = 0;
    
}

void MainContentComponent::shutdown(){
}

void MainContentComponent::render(){
    
    previousFrameTime = currentFrameTime;
    currentFrameTime = juce::Time::currentTimeMillis();
    frameRate = 1000.0/(currentFrameTime - previousFrameTime);
    frameRate = 0.1*frameRate + 0.9*previousFrameRate;
    previousFrameRate = frameRate;
    frameRateLabel->setText(String(frameRate) + " fps", dontSendNotification);
    
    
    pspManager->update();
    jassert (OpenGLHelpers::isContextActive());
    //OpenGLHelpers::clear(Colour::greyLevel(0.9));
    OpenGLHelpers::clear(Colour::fromFloatRGBA(0.9, 0.9, 0.9, 0.1));

    const float desktopScale = (float) openGLContext.getRenderingScale();
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_SCALE);
    glEnable(GL_DEPTH_TEST);
    
    glViewport(xOffset, 0, getWidth() - xOffset, roundToInt(desktopScale * getHeight()));
    
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(zoomSlider->getValue(), (getWidth() - xOffset)/(double)getHeight(), 3.0, 70.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT,  GL_NICEST);
    
    glEnable (GL_BLEND);
    glPushMatrix();
    glTranslated(0., 0., 0.);
    glRotated(rollSlider->getValue(), 1, 0, 0);
    glRotated(pitchSlider->getValue(), 0, 1, 0);
    glRotated(yawSlider->getValue(), 0, 0, 1);
    pspManager->draw();
    glPopMatrix();
    glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);
    
    
    
    /*
    UdpTransmitSocket transmitSocket( IpEndpointName( "127.0.0.1", 7000 ) );
    
    char buffer[1024];
    osc::OutboundPacketStream p( buffer, 1024 );
    
    p << osc::BeginBundleImmediate;
    p << osc::BeginMessage( "/test1" )
    << true << 23 << (float)3.1415 << "hello" << osc::EndMessage
    << osc::BeginMessage( "/test2" )
    << true << 24 << (float)10.8 << "world" << osc::EndMessage
    << osc::EndBundle;
    transmitSocket.Send( p.Data(), p.Size() );
    */
    juce::Thread::sleep(1000/30);
}

void MainContentComponent::paint (Graphics& g){
    // You can add your component specific drawing code here!
    // This will draw over the top of the openGL background.
}

void MainContentComponent::resized(){
    
    
    Rectangle<int> area (getLocalBounds());
    menuBar->setBounds(area.removeFromTop(LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));
    
    frameRateLabel->setBounds(getWidth() - 105, view1->getY() + 2, 100, 45);
    
    zoomSlider->setBounds(getWidth() - 105, 28, 100, 15);
    rollSlider->setBounds(getWidth() - 105, 45, 100, 15);
    pitchSlider->setBounds(getWidth() - 105, 62, 100, 15);
    yawSlider->setBounds(getWidth() - 105, 79, 100, 15);
    view1->setBounds(getWidth() - 105, 96, 25, 15);
    view2->setBounds(getWidth() - 105 + 25, 96, 25, 15);
    view3->setBounds(getWidth() - 105 + 50, 96, 25, 15);
    view4->setBounds(getWidth() - 105 + 75, 96, 25, 15);
    
    roomConfigGui->setBounds(0, menuBar->getBottom(), 180, getHeight() - menuBar->getBottom());
    
    systemEditorGui->setBounds(0, menuBar->getBottom(), 180, getHeight() - menuBar->getBottom());
    
    
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
void MainContentComponent::setXOffset(double xo){
    xOffset = xo;
}

void MainContentComponent::sliderValueChanged(Slider* slider){
    
}
void MainContentComponent::sliderDragStarted(Slider*){
    
}
void MainContentComponent::sliderDragEnded(Slider*){
    
}
void MainContentComponent::buttonClicked(Button* buttonThatWasClicked){
    
    if(buttonThatWasClicked == view1){
        rollSlider->setValue(0.);
        pitchSlider->setValue(0.);
        yawSlider->setValue(0.);
    }
    else if(buttonThatWasClicked == view2){
        rollSlider->setValue(90.);
        pitchSlider->setValue(0.);
        yawSlider->setValue(0.);
    }
    else if(buttonThatWasClicked == view3){
        rollSlider->setValue(15.);
        pitchSlider->setValue(330.);
        yawSlider->setValue(0.);
    }
    else if(buttonThatWasClicked == view4){
        rollSlider->setValue(15.);
        pitchSlider->setValue(30.);
        yawSlider->setValue(0.);
    }
}

StringArray MainContentComponent::getMenuBarNames(){
    const char* const names[] = { "File", "View", "Edit", nullptr };
    
    return StringArray (names);
}

PopupMenu MainContentComponent::getMenuForIndex (int topLevelMenuIndex, const String &menuName){
    PopupMenu menu;
    
    if (topLevelMenuIndex == 0)
    {
        menu.addItem(1, "Save");
        menu.addItem(2, "Load");
    }
    else if(topLevelMenuIndex == 1){
        menu.addItem(3, "clean view");
        menu.addItem(4, "Systems Editor");
        menu.addItem(5, "Room config");
        menu.addItem(6, "Spatialization config");
    }
    
    
    return menu;
}


void MainContentComponent::menuItemSelected (int menuItemID, int /*topLevelMenuIndex*/){
    std::cout<<std::endl<<menuItemID;
    
    
    switch (menuItemID){
        case 1:
            //xOffset = 0.;
            //roomConfigGui->setVisible(false);
            break;
            
        case 2:
            //xOffset = 0.;
            //roomConfigGui->setVisible(false);
            break;
        case 3:
            xOffset = 0.;
            roomConfigGui->setVisible(false);
            systemEditorGui->setVisible(false);
            break;
        case 4:
            roomConfigGui->setVisible(false);
            systemEditorGui->setVisible(true);
            xOffset = systemEditorGui->getWidth();
            break;
        case 5:
            roomConfigGui->setVisible(true);
            systemEditorGui->setVisible(false);
            xOffset = roomConfigGui->getWidth();
            
            break;
        case 6:
            xOffset = 0.;
            roomConfigGui->setVisible(false);
            systemEditorGui->setVisible(false);
            break;
            
    }
    
    
}

void MainContentComponent::createViewWidgets(){
    
    //look and feel
    lookAndFeelV3.setColour (Label::textColourId, Colours::white);
    lookAndFeelV3.setColour (Label::textColourId, Colours::white);
    lookAndFeelV3.setColour (ToggleButton::textColourId, Colours::white);
    LookAndFeel::setDefaultLookAndFeel (&lookAndFeelV3);
    
    
    //openGl view widgets
    addAndMakeVisible (frameRateLabel = new Label (String::empty, "FrameRate !"));
    frameRateLabel->setFont (Font (10.00f, Font::bold));
    frameRateLabel->setJustificationType (Justification::centred);
    frameRateLabel->setEditable (false, false, false);
    frameRateLabel->setColour (Label::textColourId, Colours::black);
    frameRateLabel->setColour (TextEditor::textColourId, Colours::black);
    frameRateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    zoomSlider = new Slider();
    zoomSlider->setRange(5., 100.);
    zoomSlider->setValue(20.);
    zoomSlider->setPopupMenuEnabled (true);
    zoomSlider->setSliderStyle (Slider::LinearBar);
    zoomSlider->setBounds(getWidth() - 105, 28, 100, 15);
    zoomSlider->setTextValueSuffix (" zoom");
    zoomSlider->setVelocityBasedMode(true);
    zoomSlider->setSkewFactor(0.7);
    addAndMakeVisible(zoomSlider);
    
    rollSlider = new Slider();
    rollSlider->setRange(0., 360.);
    rollSlider->setValue(0.);
    rollSlider->setPopupMenuEnabled (true);
    rollSlider->setSliderStyle (Slider::LinearBar);
    rollSlider->setBounds(getWidth() - 105, 45, 100, 15);
    rollSlider->setTextValueSuffix (" roll");
    rollSlider->setVelocityBasedMode(true);
    rollSlider->setSkewFactor (0.5);
    addAndMakeVisible(rollSlider);
    
    pitchSlider = new Slider();
    pitchSlider->setRange(0., 360.);
    pitchSlider->setValue(0.);
    pitchSlider->setPopupMenuEnabled (true);
    pitchSlider->setSliderStyle (Slider::LinearBar);
    pitchSlider->setBounds(getWidth() - 105, 62, 100, 15);
    pitchSlider->setTextValueSuffix (" pitch");
    pitchSlider->setVelocityBasedMode(true);
    pitchSlider->setSkewFactor (0.5);
    addAndMakeVisible(pitchSlider);
    
    yawSlider = new Slider();
    yawSlider->setRange(0., 360.);
    yawSlider->setValue(0.);
    yawSlider->setPopupMenuEnabled (true);
    yawSlider->setSliderStyle (Slider::LinearBar);
    yawSlider->setBounds(getWidth() - 105, 79, 100, 15);
    yawSlider->setTextValueSuffix (" yaw");
    yawSlider->setVelocityBasedMode(true);
    yawSlider->setSkewFactor (0.5);
    addAndMakeVisible(yawSlider);
    
    
    addAndMakeVisible(view1 = new TextButton("view 1"));
    view1->setClickingTogglesState(true);
    view1->setRadioGroupId(1111);
    view1->setBounds(getWidth() - 105, 96, 25, 15);
    view1->setConnectedEdges(Button::ConnectedOnRight | 0);
    view1->setColour(TextButton::buttonOnColourId, Colours::skyblue.brighter());
    view1->addListener(this);
    
    
    addAndMakeVisible(view2 = new TextButton("view 2"));
    view2->setClickingTogglesState(true);
    view2->setRadioGroupId(1111);
    view2->setBounds(getWidth() - 105 + 25, 96, 25, 15);
    view2->setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    view2->setColour(TextButton::buttonOnColourId, Colours::skyblue.brighter());
    view2->addListener(this);
    
    addAndMakeVisible(view3 = new TextButton("view 3"));
    view3->setClickingTogglesState(true);
    view3->setRadioGroupId(1111);
    view3->setBounds(getWidth() - 105 + 50, 96, 25, 15);
    view3->setConnectedEdges(Button::ConnectedOnLeft | Button::ConnectedOnRight);
    view3->setColour(TextButton::buttonOnColourId, Colours::skyblue.brighter());
    view3->addListener(this);
    
    addAndMakeVisible(view4 = new TextButton("view 4"));
    view4->setClickingTogglesState(true);
    view4->setRadioGroupId(1111);
    view4->setBounds(getWidth() - 105 + 75, 96, 25, 15);
    view4->setConnectedEdges(Button::ConnectedOnLeft | 0);
    view4->setColour(TextButton::buttonOnColourId, Colours::skyblue.brighter());
    view4->addListener(this);
    
    //main menu bar
    addAndMakeVisible (menuBar = new MenuBarComponent (this));
    
    //room config
    addChildComponent(roomConfigGui = new pspRoomConfigGUI(pspManager));
    
    //system editor
    addChildComponent(systemEditorGui = new pspSystemEditorGUI(pspManager));
    
}

