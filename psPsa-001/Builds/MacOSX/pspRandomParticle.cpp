//
//  pspRandomParticle.cpp
//  psPsa-001
//
//  Created by Andre Perrotta on 02/12/14.
//
//

#include "pspRandomParticle.h"

pspRandomParticle::pspRandomParticle(){
    
}
pspRandomParticle::pspRandomParticle(pspParticleSystem* ms, int ind){
    setup(ms, ind);
}
pspRandomParticle::~pspRandomParticle(){
    
}

void pspRandomParticle::specificSetup(){
    
    bounds = nullptr;
    
    size = 0.03;
    pos = ofVec3f(0., 0., 0.);
    vel = ofVec3f(rangedRandom(0.01, 0.3), rangedRandom(0.01, 0.3), rangedRandom(0.01, 0.3));
    posNext = ofVec3f(rangedRandom(-0.5, 0.5), rangedRandom(-0.5, 0.5), rangedRandom(-0.5, 0.5));
}

void pspRandomParticle::update(){
    bool reach = true;
    
    float dx = posNext.x - pos.x;
    if(fabs(dx) > 0.01) {
        pos.x += dx * vel.x;
        reach = false;
    }
    
    float dy = posNext.y - pos.y;
    if(fabs(dy) > 0.01) {
        pos.y += dy * vel.y;
        reach = false;
    }
    
    float dz = posNext.z - pos.z;
    if(fabs(dz) > 0.01) {
        pos.z += dz * vel.z;
        reach = false;
    }
    
    if(reach){
        vel = ofVec3f(rangedRandom(0.01, 0.3), rangedRandom(0.01, 0.3), rangedRandom(0.01, 0.3));
        
        /*
        if(bounds != nullptr){
        posNext = ofVec3f(rangedRandom(bounds->limits_x.min, bounds->limits_x.max), rangedRandom(bounds->limits_y.min, bounds->limits_y.max), rangedRandom(bounds->limits_z.min, bounds->limits_z.max));
        }
        
        else{
            posNext = ofVec3f(rangedRandom(-0.5, 0.5), rangedRandom(-0.5, 0.5), rangedRandom(-0.5, 0.5));
        }
        */
        posNext = ofVec3f(rangedRandom(-0.5, 0.5), rangedRandom(-0.5, 0.5), rangedRandom(-0.5, 0.5));
        //post("%lf %lf %lf", posCarNext.x, posCarNext.y, posCarNext.z);
    }
}
void pspRandomParticle::draw(){
    glPushMatrix();
    GLUquadricObj* Sphere;
    glTranslatef(pos.x, pos.y, pos.z);
    Sphere = gluNewQuadric();
    gluSphere(Sphere, size, 4, 4);
    gluDeleteQuadric(Sphere);
    glPopMatrix();
}

void pspRandomParticle::setBounds(CubeLimits *b){
    bounds = b;
}