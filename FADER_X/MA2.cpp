#include "MA2.h"
#include "Net.h"
#include "Fader.h"

extern Net net;
extern void setFaderTarget(byte index, int value);
extern Fader fader1;
extern byte globalFaderChannels[32];

int lastTarget[32];

void dump(char *t) {
  byte c;
  int l = strlen(t);
  for (int i = 0; l; i++) {
    c = t[i];
    if (c<16) {
      Serial.print("0");
    }
    Serial.print(c,HEX);
     if (!((i+1) % 3)) {
      if (!((i+1) % 30)) {
        Serial.println("");
      } else {
        Serial.print(" ");
      }
    }
  }
  if (l>0) {
    Serial.println();
  }
}

void dump(char *t, unsigned int l) {
  byte c;
  for (unsigned int i = 0; i<l; i++) {
    c = t[i];
    if (c<16) {
      Serial.print("0");
    }
    Serial.print(c,HEX);
    if (!((i+1) % 3)) {
      if (!((i+1) % 30)) {
        Serial.println("");
      } else {
        Serial.print(" ");
      }
    }
  }
  if (l>0) {
    Serial.println();
  }
}

void MA2::setup(){
  Serial.println("MA2 setup");
  udp.begin(net.IP_DestinationPort);
  // global Channels/Targets need to be 1 to 1
  for (int i=0; i<32; i++) {
    globalFaderChannels[i] = i;
    lastTarget[i] = globalFaderTargets[i];
  }
//  dump (maFaders,99);
}

void MA2::loop(){
  u_int size = udp.parsePacket();
  byte whichFader[] = {0, 0, 0x90, 0};
  byte *foundAt;
  int thisFader = 0;

  if (size > 0 && size <= sizeof(buf)) {
    udp.read(buf, size);
    MA2Message msgIn(buf, size);

    if (!msgIn.isValid()) {
      return;
    }

    byte dev = msgIn.toDevice;
    byte cmd = msgIn.toCommand;
   
    if(cmd == 6 
      && (msgIn.toFormat == listenFormat 
        || msgIn.toFormat == MSC_TO_ALL)
      && (dev == MSC_TO_ALL 
        || (dev == (MSC_TO_GROUP(listenGroup)) 
        || (dev == listenDevice)))
      ) {

      whichFader[0] = msgIn.execPage;
      whichFader[1] = msgIn.faderNum;
      byte *look = maFaders;

      // locate all matches
      // a console fader may be on more than one page
      while ((foundAt = (byte *)strstr((char *)look,(char *)whichFader)) != NULL) {
        if ((thisFader = (foundAt - maFaders)/3) < 32) {
          processMA2(msgIn, thisFader);
        }
        look += 3;
      }
    }
  }
}

void MA2::touchEvent(int channel, Fader *fader){
  byte deskExec = maFaders[(channel)*3];
  byte deskFader = maFaders[(channel)*3 + 1];
  // Serial.print("touch fader, channel "); Serial.print(fader->index); 
  // Serial.print(", "); Serial.println(deskFader);
  MA2Message msg(sendTo, deskFader - 1, deskExec, fader->getPositionTrimmed());
  udp.beginPacket(net.IP_Destination, net.IP_DestinationPort);
  msg.writeUDP(&udp);
  udp.endPacket();
}

void MA2::processMA2(MA2Message msg, int channel){

  float lvl = msg.toValue; //  (100,max(0,msg.data[2] / 1.28 /100 + msg.data[3] / 1.28));
  int newTarget = min(1023,max(0,lvl * 1023 / 100));
  int oldTarget = min(1023,max(0,globalFaderTargets[channel]));
  
  if ( oldTarget != newTarget && newTarget != lastTarget[channel] ) {    
  //  Serial.print("motoring to "); Serial.println(newTarget);
    lastTarget[channel] = newTarget;
    setFaderTarget(channel, newTarget);
  }
}
