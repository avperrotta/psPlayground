//
//  pspRandomSystem.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 02/12/14.
//
//

#include "pspRandomSystem.h"
#include "pspParticleSystemsManager.h"

pspRandomSystem::pspRandomSystem(pspParticleSystemsManager* sm, String n, int np){
    setup(sm, n, np);
}

pspRandomSystem::~pspRandomSystem(){
    delete bounds;
    
    myGuiWindowRef.getReference(0).deleteAndZero();
    myGuiWindowRef.clear();
}

void pspRandomSystem::specificSetup(){
    
    myGuiWindow = new pspRandomSystemWindowGui(this, "random: " + name, Colour::greyLevel(0.5f), DocumentWindow::allButtons);
    myGuiWindow->setResizable(true, true);
    myGuiWindow->setUsingNativeTitleBar(true);
    myGuiWindowRef.add(myGuiWindow);
    //myGuiWindow->setVisible(true);
    
    type = "random";
    
    bounds = new CubeLimits(limits(-0.7, 0.7), limits(-0.7, 0.7), limits(-0.7, 0.7));
    lx = bounds->limits_x;
    ly = bounds->limits_y;
    lz = bounds->limits_z;
}

void pspRandomSystem::addParticleSpecific(int np){
    int indexStart = particles->size();
    for(int i=0; i<np; i++){
        particles->push_back(new pspRandomParticle(this, i + indexStart));
        if(bounds != nullptr){
            static_cast<pspRandomParticle*>(particles->back())->setBounds(bounds);
        }
        
    }
}

void pspRandomSystem::update(){
    pspParticleSystem::update();
}

void pspRandomSystem::drawParticles(){
    pspParticleSystem::drawParticles();
}

void pspRandomSystem::drawSystem(){
    glPushMatrix();
    //floor
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.min, lz.max);
    glVertex3f(lx.max, ly.min, lz.max);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.min, lz.max);
    glVertex3f(lx.max, ly.min, lz.min);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.min, lz.min);
    glVertex3f(lx.min, ly.min, lz.min);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.min, lz.min);
    glVertex3f(lx.min, ly.min, lz.max);
    glEnd();
    
    //ceiling
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.max, lz.max);
    glVertex3f(lx.max, ly.max, lz.max);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.max, lz.max);
    glVertex3f(lx.max, ly.max, lz.min);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.max, lz.min);
    glVertex3f(lx.min, ly.max, lz.min);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.max, lz.min);
    glVertex3f(lx.min, ly.max, lz.max);
    glEnd();
    
    //walls
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.max, lz.max);
    glVertex3f(lx.min, ly.min, lz.max);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.max, lz.max);
    glVertex3f(lx.max, ly.min, lz.max);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(lx.max, ly.max, lz.min);
    glVertex3f(lx.max, ly.min, lz.min);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(lx.min, ly.max, lz.min);
    glVertex3f(lx.min, ly.min, lz.min);
    glEnd();
    
    glPopMatrix();
}



//=======================
//window gui

void pspRandomSystem::showGui(){
    myGuiWindow->setVisible(true);
}

pspRandomSystemWindowGui::pspRandomSystemWindowGui(pspRandomSystem* ms, const String& name, Colour backgroundColour, int buttonsNeeded) : DocumentWindow(name, backgroundColour, buttonsNeeded){
    
    myContent = new pspRandomSystemWGCC();
    setContentComponent(myContent);
    
    //myContent->addChangeListener (this);
    setContentOwned(myContent, false);
    
    //setContentOwned(numParticles, false);
    
    setBounds(getWidth()*0.5, 20, 300, 400);
    myContent->setBounds(getLocalBounds());
}

pspRandomSystemWindowGui::~pspRandomSystemWindowGui(){
    //delete numParticles;
    //delete this;
}

void pspRandomSystemWindowGui::closeButtonPressed(){
    //this->getComponent().deleteAndZero();
    //delete this;
    
    setVisible(false);
}


void pspRandomSystemWindowGui::changeListenerCallback(ChangeBroadcaster* source){
    
}

void pspRandomSystemWindowGui::paint(Graphics& g){
    g.fillAll(Colour::greyLevel(0.5f));
}
void pspRandomSystemWindowGui::resized(){
    
}



pspRandomSystemWGCC::pspRandomSystemWGCC(){
    
    
    addAndMakeVisible (numParticlesLabel = new Label (String::empty, "Number of particles"));
    numParticlesLabel->setFont (Font (14.00f, Font::bold));
    numParticlesLabel->setJustificationType(Justification::topLeft);
    numParticlesLabel->setEditable(false, false, false);
    numParticlesLabel->setColour(Label::textColourId, Colours::white);
    
    addAndMakeVisible(numParticles = new Slider());
    numParticles->setRange(0, MAX_NUM_PARTICLES, 1);
    numParticles->setValue(1);
    numParticles->setSliderStyle(Slider::IncDecButtons);
    numParticles->setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    //numParticles->setSliderStyle (Slider::LinearHorizontal);
    numParticles->setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);
    numParticles->setBounds(getLocalBounds().getX() + 4, getLocalBounds().getY() + 4, 100, 20);
    numParticles->addListener(this);
    
    addAndMakeVisible (tester = new TextButton (String::empty));
    tester->setButtonText ("Quit");
    tester->addListener (this);
}
pspRandomSystemWGCC::~pspRandomSystemWGCC(){
    
}

void pspRandomSystemWGCC::paint(Graphics& g){
    
}
void pspRandomSystemWGCC::resized(){
    numParticlesLabel->setBounds(getLocalBounds().getX() + 4, getLocalBounds().getY() + 4, 200, 20);
    numParticles->setBounds(numParticlesLabel->getX(), numParticlesLabel->getBottom() + 4, 200, 20);
    tester->setBounds(numParticles->getX(), numParticles->getBottom() + 5, 100, 20);
}

void pspRandomSystemWGCC::sliderValueChanged(Slider* slider){
    cout<<endl<<"entrei";
}
void pspRandomSystemWGCC::sliderDragStarted(Slider*){
    
}
void pspRandomSystemWGCC::sliderDragEnded(Slider*){
    
}

void pspRandomSystemWGCC::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]
    
    if (buttonThatWasClicked == tester)
    {
        //[UserButtonCode_quitButton] -- add your button handler code here..
        
        cout<<endl<<"entrei";
        //JUCEApplication::quit();
        
        //[/UserButtonCode_quitButton]
    }
    
    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



