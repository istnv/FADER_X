#include <Arduino.h>
#include <QNEthernet.h>
using namespace qindesign::network;

#ifndef Ma2MSC_H
#define Ma2MSC_H

#define MSC_TO_ALL 0x7F
#define MSC_TO_GROUP(g) (0x70 | ((g-1) & 0x0f))
#define MSC_TO_DEVICE(d) (d & 0x3f)

class MA2Message {
  private:
    boolean valid = false;
    
  public:
    byte data[49];
    byte dataLen = 0;
    byte buf[Ethernet.mtu() - 20 - 8];
    byte bufLen = 0;
    int lastLevel = -1;
    float faderPos = 0;
    byte toDevice;
    byte toCommand;
    byte toFormat;
    float toValue;
    int deviceID = MSC_TO_ALL;
    int execPage = 0;   
    int faderNum = 0;   
  
    MA2Message(byte devTo, byte page, byte exec, int lvl);
    MA2Message(char *buf, u_int size);
    boolean isValid();
    void writeUDP(EthernetUDP *udp);
};

#endif
