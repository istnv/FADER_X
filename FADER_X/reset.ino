void newSettings(){
  Serial.println("===============================");

  versionMajor = EEPROM.read(8);
  versionMinor = EEPROM.read(9);
  versionSub = EEPROM.read(10);

  EEPROM.get(14, globalMessageWaitMillis);
  globalTouchSensitivity = EEPROM.read(22);
  globalMode = EEPROM.read(24);
  globalMotorMinSpeed = EEPROM.read(16);
  globalMotorSpeedScale = EEPROM.read(17);
  EEPROM.get(18, globalMotorFrequency);
  globalMotherboardRevision = EEPROM.read(21);

  for(byte i=0; i<32; i++){
    globalFaderChannels[i] = EEPROM.read(66+i);
    ma2.maFaders[i*3] = EEPROM.read(160+i*2);
    ma2.maFaders[i*3+1] = EEPROM.read(161+i*2);
    ma2.maFaders[i*3+2] = 0x90;
  }
  
  ma2.listenDevice = EEPROM.read(153);
  ma2.listenGroup = EEPROM.read(154);
  ma2.listenFormat = EEPROM.read(155);
  ma2.sendDevice = EEPROM.read(156);
  ma2.sendGroup  = EEPROM.read(157);
  ma2.sendFormat = EEPROM.read(158);
  ma2.sendTo = EEPROM.read(159);

  for(byte i=0; i<255; i++){
    globalFaderTargets[i] = 0;
  }
  
  globalRotated = EEPROM.read(20)==1;
  if(globalRotated){
    fader1.setup(7);
    fader2.setup(6);
    fader3.setup(5);
    fader4.setup(4);
    fader5.setup(3);
    fader6.setup(2);
    fader7.setup(1);
    fader8.setup(0);
  }else{
    fader1.setup(0);
    fader2.setup(1);
    fader3.setup(2);
    fader4.setup(3);
    fader5.setup(4);
    fader6.setup(5);
    fader7.setup(6);
    fader8.setup(7);
  }

  delay(50);

  fader1.setTargetToCurrentPosition();
  fader2.setTargetToCurrentPosition();
  fader3.setTargetToCurrentPosition();
  fader4.setTargetToCurrentPosition();
  fader5.setTargetToCurrentPosition();
  fader6.setTargetToCurrentPosition();
  fader7.setTargetToCurrentPosition();
  fader8.setTargetToCurrentPosition();
  

  // MIDI
  midi.listenChannel = EEPROM.read(62);
  midi.sendChannel = EEPROM.read(63);

  // QLab
  qlab.maximumVolume = EEPROM.read(128);
  qlab.minimumVolume = EEPROM.read(129);
  
  if(EEPROM.read(130)==0){
    qlab.midiEnabled = false;
  }else{
    qlab.midiEnabled = true;
  }
  
  if(EEPROM.read(131)==0){
    qlab.autoMidi = false;
  }else{
    qlab.autoMidi = true;
  }

  qlab.passcode[0] = EEPROM.read(132);
  qlab.passcode[1] = EEPROM.read(133);
  qlab.passcode[2] = EEPROM.read(134);
  qlab.passcode[3] = EEPROM.read(135);
  qlab.passcode[4] = EEPROM.read(136);
  qlab.passcode[5] = EEPROM.read(137);
  qlab.passcode[6] = EEPROM.read(138);
  qlab.passcode[7] = EEPROM.read(139);

  // Eos
  if(eos.connected){
    eos.eosClient.close();
  }
  eos.connected = false;
  eos.faderBank = EEPROM.read(140);
  eos.faderCount = EEPROM.read(141);

  x32.xTarget = EEPROM.read(150);

  // Net
  net.loadEEPROM();
  net.setup();

  globalUDP.begin(29979);
  Serial.println("Started OSC Server :29979");
  
  if(globalMode==OP_Midi || globalMode==OP_Midi_NoMotor){
    midi.setup();
    
  }else if(globalMode==OP_QLab){
    qlab.setup();
    
  }else if(globalMode==OP_Eos){
    eos.setup();
    
  }else if(globalMode==OP_X32){
    x32.setup();
    
  }else if(globalMode==OP_DiGiCo){
    digico.setup();
    
  }else if(globalMode==OP_MA2) {
    ma2.setup();
  }
  
  if(globalFirstBoot){
    globalMode = EEPROM.read(24);
  }else{
    globalMode = 11;
  }
  globalFirstBoot = false;
  unpauseAllFaders();
  globalLastBoot = millis();
  
  Serial.println("===============================");

}

void resetNetStatic(){
  EEPROM.write(32, 1); // Ethernet Mode
  
  EEPROM.write(34, 192); // Static IP
  EEPROM.write(35, 168); // Static IP
  EEPROM.write(36, 1);   // Static IP
  EEPROM.write(37, 130); // Static IP

  EEPROM.write(38, 255); // Subnet Mask
  EEPROM.write(39, 255); // Subnet Mask
  EEPROM.write(40, 255); // Subnet Mask
  EEPROM.write(41, 0);   // Subnet Mask

  EEPROM.write(42, 192); // Gateway
  EEPROM.write(43, 168); // Gateway
  EEPROM.write(44, 1);   // Gateway
  EEPROM.write(45, 1);   // Gateway
}
void resetNetDHCP(){
  EEPROM.write(32, 2); // Ethernet Mode
}



void factoryReset(){
  EEPROM.write(0, 'F');
  EEPROM.write(1, 'A');
  EEPROM.write(2, 'D');
  EEPROM.write(3, 'E');
  EEPROM.write(4, 'R');
  EEPROM.write(5, '_');
  EEPROM.write(6, '8');
  EEPROM.write(7, 0);

  EEPROM.write(8, MAJOR);
  EEPROM.write(9, SUBVERSION);
  EEPROM.write(10, PATCH);

  EEPROM.put(14, defaultMessageWaitMillis); // Message wait (16 bit)
  EEPROM.write(16, defaultMotorMinSpeed); // Motor Min Speed
  EEPROM.write(17, defaultMotorScaleFactor); // Motor Scale Factor
  EEPROM.put(18, defaultMotorFrequency); // Motor Drive Frequency
  EEPROM.write(20, 0); // Rotated
  
  byte mb = EEPROM.read(21);
  
  if(mb==2){
    EEPROM.write(22, 10); // Touch Sensitivity
  }else{
    EEPROM.write(22, 128); // Touch Sensitivity
  }
  
  if(mb!=1 && mb!=2){
    EEPROM.write(21, 2); // Motherboard Revision
  }

  

  EEPROM.write(24, 1); // Op Mode

  resetNetStatic();

  EEPROM.put(46, 53001); // Port (16 bit)

  EEPROM.write(48, 192); // Destination IP
  EEPROM.write(49, 168); // Destination IP
  EEPROM.write(50, 1);   // Destination IP
  EEPROM.write(51, 120); // Destination IP

  EEPROM.put(52, 53000); // Destination Port (16 bit)

  EEPROM.write(54, 0);   // LED Enable
  EEPROM.write(55, 0);   // Page 1 LED Hue
  EEPROM.write(56, 85);  // Page 2 LED Hue
  EEPROM.write(57, 170); // Page 3 LED Hue
  EEPROM.write(58, 200); // Page 4 LED Hue
  EEPROM.write(59, 200); // LED Brightness

  EEPROM.write(62, 1); // MIDI Listen
  EEPROM.write(63, 1); // MIDI Send

  for(byte i=0; i<32; i++){
    EEPROM.write(66+i, i+1);
    EEPROM.write(160+i*2,45); //MA Page
    EEPROM.write(161+i*2,i+1); //MA Fader
  }

  EEPROM.write(128, 12); // QLab Max Volume
  EEPROM.write(129, 60); // QLab Min Volume
  EEPROM.write(130, 0); // QLab MIDI Enable
  EEPROM.write(131, 0); // QLab MIDI Switch
  EEPROM.write(132, '5'); // QLab Passcode Char 1
  EEPROM.write(133, '3'); // QLab Passcode Char 2
  EEPROM.write(134, '5'); // QLab Passcode Char 3
  EEPROM.write(135, '3'); // QLab Passcode Char 4
  EEPROM.write(136, 0); // QLab Passcode Char 5
  EEPROM.write(137, 0); // QLab Passcode Char 6
  EEPROM.write(138, 0); // QLab Passcode Char 7
  EEPROM.write(139, 0); // QLab Passcode Char 8

  EEPROM.write(140, 1); // ETC Eos Fader Bank
  EEPROM.write(141, 40); // ETC Eos Fader Count

  EEPROM.write(153, 0); // MA2 Listen Device
  EEPROM.write(154, 1); // MA2 Listen Group
  EEPROM.write(155, 0x7f); // MA2 Listen MSC Format (default=ALL)
  
  EEPROM.write(156, 0); // MA2 Send Device
  EEPROM.write(157, 1); // MA2 Send Group
  EEPROM.write(158, 0x7f); // MA2 Send MSC Format (default=ALL)
  
  EEPROM.write(159, 0x7f); // MA2 Send To (dev/group/ALL)
  
  Serial.println("Reset to Factory settings");
}
