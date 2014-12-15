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

#include "UdpSocket.h"

#include "pspGlobalVariables.h"
#include "pspParticleSystem.h"
#include "pspConcertRoom.h"

#include "pspRandomSystem.h"

#define MAX_NUM_PARTICLES 1000

using namespace  std;

class pspParticleSystemsManager{
    
public:
    
    pspParticleSystemsManager();
    ~pspParticleSystemsManager();
    
    
    void setup();
    void update();
    void draw();
    
    
    int getNumSystems();
    int getNumActiveSystems();
    vector<pspParticleSystem*>* getSystems();
    pspParticleSystem* getSystem(int s);
    void addSystem(String type, int np);
    void showPsystemGui(int ps);
    void deleteSystem(int s);
    
    String getSystemName(int s);
    String getSystemType(int s);
    
    ConcertRoom* getConcertRoom();
    int getNumSpeakers();
    
    
    UdpTransmitSocket* getOscSender();
    
    void debug();
    
private:
    
    vector<pspParticleSystem*>* pSystems;
    vector<pspParticleSystem*>* pSystemsToDelete;
    void moveSystemToDeleteQ();
    void clearDeleteQ();
    ConcertRoom* concertRoom;
    
    vector<Colour> colors;
    int colorIndex;
    void createColorVector();
    void incrementColorIndex();
    
    UdpTransmitSocket* oscSender;
};

#endif /* defined(__psPsa_001__pspParticleSystemsManager__) */
