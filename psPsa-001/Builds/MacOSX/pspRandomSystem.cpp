
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
    
    
    delete myGuiWindow;
    
    delete bounds;
    
}

void pspRandomSystem::specificSetup(){
    
    myGuiWindow = new pspRandomSystemWindowGui(this, "random: " + name, Colour::greyLevel(0.5f), DocumentWindow::allButtons);
    myGuiWindow->setResizable(true, true);
    myGuiWindow->setUsingNativeTitleBar(true);
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

void pspRandomSystem::specificUpdate(){
    
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
    
    
    myContent = new pspRandomSystemPropertiesComponent(mySystem);
    setContentComponent(myContent);
    setContentOwned(myContent, false);
 
    setBounds(getWidth()*0.5, 20, 400, 400);
    myContent->setBounds(getLocalBounds());
    
}


pspRandomSystemWindowGui::~pspRandomSystemWindowGui(){
    
}


void pspRandomSystemWindowGui::closeButtonPressed(){
    
    
    setVisible(false);
}


void pspRandomSystemWindowGui::paint(Graphics& g){
    g.fillAll(Colour::greyLevel(0.5f));
}
void pspRandomSystemWindowGui::resized(){
    myContent->setBounds(getLocalBounds());
}


pspRandomSystemPropertiesComponent::pspRandomSystemPropertiesComponent(pspRandomSystem* ms){
    
    mySystem = ms;
    setup();
    
}


pspRandomSystemPropertiesComponent::~pspRandomSystemPropertiesComponent(){
    

}

 
void pspRandomSystemPropertiesComponent::createSpecificWidgets(){
    comps.clear();
    comps.add(minlx = new pspLimitSlider(this, "min limits x", -3., 3., 0.005));
    comps.add(maxlx = new pspLimitSlider(this, "max limits x", -3., 3., 0.005));
    
    comps.add(minly = new pspLimitSlider(this, "min limits y", -3., 3., 0.005));
    comps.add(maxly = new pspLimitSlider(this, "max limits y", -3., 3., 0.005));
    
    comps.add(minlz = new pspLimitSlider(this, "min limits z", -3., 3., 0.005));
    comps.add(maxlz = new pspLimitSlider(this, "max limits z", -3., 3., 0.005));
    panel.addSection("Specific attributes", comps);
    comps.clear();
}

void pspRandomSystemPropertiesComponent::sliderChanged(Slider* s){
    if(s == minlx->getSlider() ||
       s == maxlx->getSlider() ||
       s == minly->getSlider() ||
       s == maxly->getSlider() ||
       s == minlz->getSlider() ||
       s == maxlz->getSlider()){
        
        mySystem->setBounds(CubeLimits(limits(minlx->getValue(), maxlx->getValue()),
                                       limits(minly->getValue(), maxly->getValue()),
                                       limits(minlz->getValue(), maxlz->getValue())));
        
    }
}



