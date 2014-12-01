//
//  pspParticleSystemsManager.h
//  psPsa-001
//
//  Created by Andre Perrotta on 22/11/14.
//
//

#ifndef __psPsa_001__pspParticleSystemsManager__
#define __psPsa_001__pspParticleSystemsManager__

#include <iostream>
#include "../JuceLibraryCode/JuceHeader.h"
#include "pspParticleSystem.h"
#include "pspConcertRoom.h"


using namespace  std;

class pspParticleSystemsManager{
    
public:
    
    pspParticleSystemsManager();
    ~pspParticleSystemsManager();
    
    
    void setup();
    void update();
    void draw();
    
    
    int getNumSystems();
    vector<pspParticleSystem*>* getSystems();
    pspParticleSystem* getSystem(int s);
    void addSystem(String type, String name);
    void deleteSystem(int s);
    
    String getSystemName(int s);
    String getSystemType(int s);
    
    ConcertRoom* getConcertRoom();
    int getNumSpeakers();
    
    void debug();
    
private:
    
    vector<pspParticleSystem*>* pSystems;
    ConcertRoom* concertRoom;
    
};

#endif /* defined(__psPsa_001__pspParticleSystemsManager__) */
