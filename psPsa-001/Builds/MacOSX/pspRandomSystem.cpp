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
    bounds = new CubeLimits(limits(-0.7, 0.7), limits(-0.7, 0.7), limits(-0.7, 0.7));
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


void pspRandomSystem::setBounds(CubeLimits cl){
    bounds->limits_x = cl.limits_x;
    bounds->limits_y = cl.limits_y;
    bounds->limits_z = cl.limits_z;
    lx = bounds->limits_x;
    ly = bounds->limits_y;
    lz = bounds->limits_z;
    
}

CubeLimits* pspRandomSystem::getBounds(){
    return bounds;
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
    
    mySystem = ms;
    
    myContent = new pspRandomSystemWGCC(mySystem);
    setContentComponent(myContent);
 
    setContentOwned(myContent, false);
    
    
    
    setBounds(getWidth()*0.5, 20, 400, 400);
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


void pspRandomSystemWindowGui::paint(Graphics& g){
    g.fillAll(Colour::greyLevel(0.5f));
}
void pspRandomSystemWindowGui::resized(){
    
}

pspRandomSystemWGCC::pspRandomSystemWGCC(pspRandomSystem* ms){
    
    mySystem = ms;
    
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
    
    
    //============
    //set bounds
    addAndMakeVisible (limitsXLabel = new Label (String::empty, "x limits"));
    limitsXLabel->setFont (Font (14.00f, Font::bold));
    limitsXLabel->setJustificationType(Justification::topLeft);
    limitsXLabel->setEditable(false, false, false);
    limitsXLabel->setColour(Label::textColourId, Colours::white);
    
    addAndMakeVisible(limitsX = new Slider());
    limitsX->setRange(-3., 3., 0.001);
    limitsX->setVelocityBasedMode(true);
    limitsX->setSkewFactor(0.9);
    limitsX->setSliderStyle(Slider::TwoValueHorizontal);
    limitsX->setTextBoxStyle(Slider::NoTextBox, false, 50, 20);
    limitsX->setMinValue(-0.5);
    limitsX->setMaxValue(0.5);
    limitsX->setPopupDisplayEnabled (true, this);
    limitsX->addListener(this);
    
    addAndMakeVisible(lxmin = new TextEditor());
    lxmin->addListener(this);
    lxmin->setText(String(limitsX->getMinValue()));
    addAndMakeVisible(lxmax = new TextEditor());
    lxmax->addListener(this);
    lxmax->setText(String(limitsX->getMaxValue()));
    
    addAndMakeVisible (limitsYLabel = new Label (String::empty, "y limits"));
    limitsYLabel->setFont (Font (14.00f, Font::bold));
    limitsYLabel->setJustificationType(Justification::topLeft);
    limitsYLabel->setEditable(false, false, false);
    limitsYLabel->setColour(Label::textColourId, Colours::white);
    
    addAndMakeVisible(limitsY = new Slider());
    limitsY->setRange(-3., 3., 0.001);
    limitsY->setVelocityBasedMode(true);
    limitsY->setSkewFactor(0.9);
    limitsY->setSliderStyle(Slider::TwoValueHorizontal);
    limitsY->setTextBoxStyle(Slider::NoTextBox, false, 50, 20);
    limitsY->setMinValue(-0.5);
    limitsY->setMaxValue(0.5);
    limitsY->setPopupDisplayEnabled (true, this);
    limitsY->addListener(this);
    
    addAndMakeVisible(lymin = new TextEditor());
    lymin->addListener(this);
    lymin->setText(String(limitsY->getMinValue()));
    addAndMakeVisible(lymax = new TextEditor());
    lymax->addListener(this);
    lymax->setText(String(limitsY->getMaxValue()));
    
    addAndMakeVisible (limitsZLabel = new Label (String::empty, "z limits"));
    limitsZLabel->setFont (Font (14.00f, Font::bold));
    limitsZLabel->setJustificationType(Justification::topLeft);
    limitsZLabel->setEditable(false, false, false);
    limitsZLabel->setColour(Label::textColourId, Colours::white);
    
    addAndMakeVisible(limitsZ = new Slider());
    limitsZ->setRange(-3., 3., 0.001);
    limitsZ->setVelocityBasedMode(true);
    limitsZ->setSkewFactor(0.9);
    limitsZ->setSliderStyle(Slider::TwoValueHorizontal);
    limitsZ->setTextBoxStyle(Slider::NoTextBox, false, 50, 20);
    limitsZ->setMinValue(-0.5);
    limitsZ->setMaxValue(0.5);
    limitsZ->setPopupDisplayEnabled (true, this);
    limitsZ->addListener(this);
    
    addAndMakeVisible(lzmin = new TextEditor());
    lzmin->addListener(this);
    lzmin->setText(String(limitsZ->getMinValue()));
    addAndMakeVisible(lzmax = new TextEditor());
    lzmax->addListener(this);
    lzmax->setText(String(limitsZ->getMaxValue()));
    //========================================
    
}
pspRandomSystemWGCC::~pspRandomSystemWGCC(){
    
}

void pspRandomSystemWGCC::paint(Graphics& g){
    
}
void pspRandomSystemWGCC::resized(){
    
    
    
    numParticlesLabel->setBounds(getLocalBounds().getX() + 4, getLocalBounds().getY() + 4, 120, 20);
    numParticles->setBounds(numParticlesLabel->getWidth() + 4, numParticlesLabel->getY(), 160, 20);
    
    limitsXLabel->setBounds(getLocalBounds().getX() + 4, numParticlesLabel->getBottom() + 16, 120, 20);
    lxmin->setBounds(limitsXLabel->getX() + limitsXLabel->getWidth() + 1, limitsXLabel->getY(), 50, 18);
    limitsX->setBounds(lxmin->getX() + lxmin->getWidth() + 1, limitsXLabel->getY(), 160, 20);
    lxmax->setBounds(limitsX->getX() + limitsX->getWidth() + 1, limitsXLabel->getY(), 50, 18);
    
    limitsYLabel->setBounds(getLocalBounds().getX() + 4, limitsX->getBottom() + 10, 120, 20);
    lymin->setBounds(limitsYLabel->getX() + limitsYLabel->getWidth() + 1, limitsYLabel->getY(), 50, 18);
    limitsY->setBounds(lymin->getX() + lymin->getWidth() + 1, limitsYLabel->getY(), 160, 20);
    lymax->setBounds(limitsY->getX() + limitsY->getWidth() + 1, limitsYLabel->getY(), 50, 18);
    
    limitsZLabel->setBounds(getLocalBounds().getX() + 4, limitsY->getBottom() + 10, 120, 20);
    lzmin->setBounds(limitsZLabel->getX() + limitsZLabel->getWidth() + 1, limitsZLabel->getY(), 50, 18);
    limitsZ->setBounds(lymin->getX() + lymin->getWidth() + 1, limitsZLabel->getY(), 160, 20);
    lzmax->setBounds(limitsZ->getX() + limitsZ->getWidth() + 1, limitsZLabel->getY(), 50, 18);
    
}

void pspRandomSystemWGCC::sliderValueChanged(Slider* slider){
    if(slider == numParticles){
        mySystem->changeNumParticles(slider->getValue());
    }
    else if(slider == limitsX){
        lxmin->setText(String(limitsX->getMinValue()));
        lxmax->setText(String(limitsX->getMaxValue()));
        mySystem->setBounds(CubeLimits(limits(limitsX->getMinValue(), limitsX->getMaxValue()),
                                       limits(limitsY->getMinValue(), limitsY->getMaxValue()),
                                       limits(limitsZ->getMinValue(), limitsZ->getMaxValue())));
    }
    else if(slider == limitsY){
        lymin->setText(String(limitsY->getMinValue()));
        lymax->setText(String(limitsY->getMaxValue()));
        mySystem->setBounds(CubeLimits(limits(limitsX->getMinValue(), limitsX->getMaxValue()),
                                       limits(limitsY->getMinValue(), limitsY->getMaxValue()),
                                       limits(limitsZ->getMinValue(), limitsZ->getMaxValue())));
    }
    else if(slider == limitsZ){
        lzmin->setText(String(limitsZ->getMinValue()));
        lzmax->setText(String(limitsZ->getMaxValue()));
        mySystem->setBounds(CubeLimits(limits(limitsX->getMinValue(), limitsX->getMaxValue()),
                                       limits(limitsY->getMinValue(), limitsY->getMaxValue()),
                                       limits(limitsZ->getMinValue(), limitsZ->getMaxValue())));
    }
}
void pspRandomSystemWGCC::sliderDragStarted(Slider*){
    
}
void pspRandomSystemWGCC::sliderDragEnded(Slider*){
    
}

void pspRandomSystemWGCC::buttonClicked (Button* buttonThatWasClicked)
{
    
}

void pspRandomSystemWGCC::textEditorTextChanged(TextEditor& t){
    if(&t == lxmin){
        limitsX->setMinValue(t.getText().getFloatValue());
    }
    else if(&t == lxmax){
        limitsX->setMaxValue(t.getText().getFloatValue());
    }
    else if(&t == lymin){
        limitsY->setMinValue(t.getText().getFloatValue());
    }
    else if(&t == lymax){
        limitsY->setMaxValue(t.getText().getFloatValue());
    }
    else if(&t == lzmin){
        limitsZ->setMinValue(t.getText().getFloatValue());
    }
    else if(&t == lzmax){
        limitsZ->setMaxValue(t.getText().getFloatValue());
    }
}
void pspRandomSystemWGCC::textEditorReturnKeyPressed(TextEditor& t){
    
    
    
}
void pspRandomSystemWGCC::textEditorEscapeKeyPressed(TextEditor& t){
    
}
void pspRandomSystemWGCC::textEditorFocusLost(TextEditor& t){
    
}


