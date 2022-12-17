#include <Arduino.h>
#include <QNEthernet.h>
#include "Fader.h"
#include "Ma2MSC.h"
using namespace qindesign::network;

#ifndef MA2_H
#define MA2_H

#define MAX_PAGES 45
#define MAX_FADERS 127

class MA2 {
  private:
    EthernetUDP udp;
    char buf[Ethernet.mtu() - 20 - 8];
    
  public:
    void setup();
    void loop();

    EthernetClient mscClient;
    void touchEvent(int channel, Fader *fader);
    void processMA2(MA2Message msg, int channel);

    byte maFaders[99];
    
    byte listenDevice = 0;
    byte listenGroup = 1;
    byte listenFormat = MSC_TO_ALL;
    byte sendDevice = 0;
    byte sendGroup = 1;
    byte sendFormat = MSC_TO_ALL;
    int sendTo = MSC_TO_ALL;

};

#endif
