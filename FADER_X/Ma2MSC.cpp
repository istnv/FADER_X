#include "Ma2MSC.h"
#include "MA2.h"
#include "Net.h"

extern int globalFaderTargets[255];
extern Net net;
extern MA2 ma2;
extern void setFaderTarget(byte index, int value);

byte MA2_SIG[] = { 'G','M','A','\0','M','S','C','\0'};
byte MSC_PRE[] = { 0xf0, 0x7f };
byte MSC_SFX = 0xf7;

int ma2FaderTargets[255];

MA2Message::MA2Message(char *buf, u_int size) {
	valid = false;
	u_long msgLen = 0;
	if(size<20){	// not enough characters
		return;
	}
	if(memcmp(&buf[0],MA2_SIG,8)==0){	// ma2 sig matches
		msgLen = *(u_long *)&buf[8];
		// Serial.print("MA Msg length is ");
		// Serial.print(msgLen);
		// Serial.print(" size is ");
		// Serial.println(size);

		// for(int i=14; i<size; i++) {
		// 	// Serial.print(i);
		// 	// Serial.print(": ");
		// 	if (buf[i]<10) {
		// 		Serial.print("0");
		// 	}
		// 	Serial.print(buf[i], HEX);
		// 	Serial.print("(");
		// 	if(isPrintable(buf[i])) {
		// 		Serial.print(buf[i]);
		// 	} else {
		// 		Serial.print(".");
		// 	}
		// 	Serial.print(") ");
		// 	if ((i+1 % 10)==0) Serial.println();
		// }	
		// Serial.println();

		if(msgLen!=size) {				// packet length does not match
			return;
		}

		// Serial.println("Checking...");
		// 47 4D 41 0 4D 53 43 0 17 0 0 0 F0 7F 7F 2 7F 6 D 2B 7 4F F7

		// check for MA MSC message
		if(memcmp(&buf[12],MSC_PRE,2)==0 && (buf[15]==2) && buf[size-1]==MSC_SFX) {  // MSC prefix/suffix
			// extract message details
			toDevice = buf[14];
			toFormat = buf[16];
			toCommand = buf[17];
			u_int l = 0;
		//	char bug[48] = {0};
			for(u_int i=18; i<size && l<48; i++, l++) {
				data[l] = buf[i];
			}
			data[l] = 0;
			dataLen = l;
		//	Serial.print("cmd="); Serial.println(toCommand);
			switch (toCommand) {
			case 6: // set fader
				toValue = min(100,max(0,data[2] / 1.28 /100 + data[3] / 1.28));
				faderNum = data[0] + 1;
				execPage = data[1];
			//	sprintf(bug, "Set %d.%d to %f", execPage, faderNum, toValue);
			//	Serial.println(bug);
				valid = true;
				break;
			case 0xa: // go_off (set to 0)
				this->toValue = 0;
				data[5]='.';
				char *which = (char *)&data[6];
				which = strtok(which,".");
				faderNum = atoi(which);
				which = strtok(NULL, ".");
				execPage = atoi(which);
			//	sprintf(bug, "Off %d.%d to %f", execPage, faderNum, toValue);
			//	Serial.println(bug);
				valid = true;
				break;
			}

	
			// Serial.println("=======");
			// Serial.print("toDevice="); Serial.println(this->toDevice);
			// Serial.print("toFormat="); Serial.println(this->toFormat);
			// Serial.print("toCommand="); Serial.println(this->toCommand);
		
			// Serial.print("dataLen="); Serial.println(this->dataLen);
			// Serial.print("faderNum="); Serial.println(this->faderNum);
			// Serial.print("execPage="); Serial.println(this->execPage);
			
		}
	}

}

MA2Message::MA2Message(byte devTo, byte fdr, byte exec, int lvl) {
	float fp = lvl * 100 / 1023.0 ;
	// Serial.print("lvl=");
	// Serial.println(lvl);
	// Serial.print("fp=");
	// Serial.println(fp);
	byte op[4] = { fdr, exec, (byte)min(127, ( fp - floor(fp) * 1.27)), (byte)min(127, (fp * 1.28))};
	if (fp==100.0) { // force 100% to max
		op[2] = 0x7f;
		op[3] = 0x7f;
	}
	//Serial.println(op);
	// byte b;
	// for(int i=0; i<4; i++) {
	// 	b = op[i];
	// 	if (b<16) Serial.print("0");
	// 	Serial.print(b, HEX);
	// 	if ((i+1 % 10)==0) Serial.println();
	// }	
	// Serial.print(" ");
	byte buf[Ethernet.mtu() - 20 - 8];
	u_int size = 23;
	memcpy((char *)this->data, (char *)op, 4);
	this->dataLen = 4;
	this->toDevice = devTo;
	this->toFormat = ma2.sendFormat;
	this->toCommand = 0x06;
	this->faderPos = lvl;
	memcpy(&buf[0], MA2_SIG, 8);
	buf[8] = size;
	buf[9] = 0;
	buf[10] = 0;
	buf[11] = 0;
	memcpy(&buf[12],MSC_PRE,2);
	buf[14] = devTo;
	buf[15] = 2;
	buf[16] = this->toFormat;
	buf[17] = 6;
	memcpy(&buf[18],(char *)op,4);
	buf[size-1] = MSC_SFX;
	
	memcpy(this->buf, buf, size);
	this->bufLen = size;
	this->valid = true;
}


void MA2Message::writeUDP(EthernetUDP *udp) {
	if (this->valid) {
		// Serial.print("Sending UDP...");
		// byte b;
		// for(int i=0; i<this->bufLen; i++) {
		// 	Serial.print(i);
		// 	Serial.print(": ");
		// 	b = this->buf[i];
		// 	if (b<16) Serial.print("0");
		// 	Serial.print(b, HEX);
		// 	Serial.print("(");
		// 	if(isPrintable(b)) {
		// 		Serial.print(b);
		// 	} else {
		// 		Serial.print(".");
		// 	}
		// 	Serial.println(") ");
		// 	if ((i+1 % 10)==0) Serial.println();
		// }
		int nextLevel = this->faderPos * 100 / 1023;
		// if (nextLevel != ma2FaderTargets[1]) {
			udp->write(this->buf,this->bufLen);
			ma2FaderTargets[1] = nextLevel;
		// }
		// send it.
	}
}

boolean MA2Message::isValid(){
  return this->valid;
}
