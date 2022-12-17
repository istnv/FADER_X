String headTemplate = "<!DOCTYPE HTML>\n"
"<html>\n"
"<head>\n"
"  <title>FADER_X Configuration</title>\n"
"  <style type='text/css'>\n"
"    body{font-family:sans-serif;font-size:16px;color:#aaa;margin:100px 0px;background-color:#262b30;}\n"
"    table{width:700px;margin:20px 20px 30px;border:#454b4f 1px solid;border-radius:5px;box-shadow: rgba(0, 0, 0, 0.05) 0px 1px 2px 0px;}\n"
"    th{text-align:left;font-size:14px;padding:7px 12px;background-color:#454b4f;color:white;}\n"
"    .block td:nth-child(1){width:160px;}\n"
"    .block td:nth-child(2){width:190px !important;}\n"
"    .block.mode{margin-left: 60px; width: 660px;}\n"
"    td{padding:5px 8px 5px 12px;}\n"
"    tbody tr:nth-child(odd){background-color: #21262b;}\n"
"    input,select{width:165px;background:transparent !important;font-size:16px;border:2px solid #33383d;border-radius:4px;font-family:monospace;padding:3px;color:white;}\n"
"    select{background-color: #f7f8f9;}\n"
"    em{padding: 2px;}\n"
"    input[type=number]{width:75px;}\n"
"    input[type=checkbox]{width:20px;height:20px;margin:3px 10px 3px 0px;float:left;}\n"
"    button{background-color:#81898e;color:white;border-radius:6px;font-size:16px;padding:6px 20px;border:none;font-size:15px;font-weight:bold;margin:0px 30px;cursor:pointer;}\n"
"    button:hover{opacity:0.9;}\n"
"    header{background-color:#34383d;color:white;padding:20px;font-weight:bold;position:fixed;width:100%;top:0;z-index:1000;border-bottom:#fdea0a 2px solid;}\n"
"    .note{font-size: 12px;}\n"
"    a{color: #aaa;margin-left: 40px;}\n"
"  </style>\n"
"</head>\n";

String bodyTemplate = "<body>"
"<header>FADER_X Configuration"
  "<button form='main' type='Submit'>Apply Settings</button>"
  "<a href='/reset'>Factory Reset</a><a href='https://github.com/stagehacks/FADER_X'>Readme</a><a>Version {v1}.{v2}.{v3}</a>"
"</header>"
"<form id='main' method='get' action='/apply'>"
"<input value='{tok1}{tok2}{tok3}{tok4}' name='sessionToken' type='hidden'>"
"<table>"
  "<tr><th colspan='65'>Fader Channels</th></tr>"
  "<tr><td style='width: 40px;'>Num</td><td style='width: 115px;'>Position</td><td>Page 1</td><td>Page 2</td><td>Page 3</td><td>Page 4</td></tr>"
  "<tr><td>1</td><td id='val1'></td>"
    "<td><input type='number' name='ch1A' value='{ch-1A}' min='0'></td>"
    "<td><input type='number' name='ch1B' value='{ch-1B}' min='0'></td>"
    "<td><input type='number' name='ch1C' value='{ch-1C}' min='0'></td>"
    "<td><input type='number' name='ch1D' value='{ch-1D}' min='0'></td></tr>"
  "<tr><td>2</td><td id='val2'></td>"
    "<td><input type='number' name='ch2A' value='{ch-2A}' min='0'></td>"
    "<td><input type='number' name='ch2B' value='{ch-2B}' min='0'></td>"
    "<td><input type='number' name='ch2C' value='{ch-2C}' min='0'></td>"
    "<td><input type='number' name='ch2D' value='{ch-2D}' min='0'></td></tr>"
  "<tr><td>3</td><td id='val3'></td>"
    "<td><input type='number' name='ch3A' value='{ch-3A}' min='0'></td>"
    "<td><input type='number' name='ch3B' value='{ch-3B}' min='0'></td>"
    "<td><input type='number' name='ch3C' value='{ch-3C}' min='0'></td>"
    "<td><input type='number' name='ch3D' value='{ch-3D}' min='0'></td></tr>"
  "<tr><td>4</td><td id='val4'></td>"
    "<td><input type='number' name='ch4A' value='{ch-4A}' min='0'></td>"
    "<td><input type='number' name='ch4B' value='{ch-4B}' min='0'></td>"
    "<td><input type='number' name='ch4C' value='{ch-4C}' min='0'></td>"
    "<td><input type='number' name='ch4D' value='{ch-4D}' min='0'></td></tr>"
  "<tr><td>5</td><td id='val5'></td>"
    "<td><input type='number' name='ch5A' value='{ch-5A}' min='0'></td>"
    "<td><input type='number' name='ch5B' value='{ch-5B}' min='0'></td>"
    "<td><input type='number' name='ch5C' value='{ch-5C}' min='0'></td>"
    "<td><input type='number' name='ch5D' value='{ch-5D}' min='0'></td></tr>"
  "<tr><td>6</td><td id='val6'></td>"
    "<td><input type='number' name='ch6A' value='{ch-6A}' min='0'></td>"
    "<td><input type='number' name='ch6B' value='{ch-6B}' min='0'></td>"
    "<td><input type='number' name='ch6C' value='{ch-6C}' min='0'></td>"
    "<td><input type='number' name='ch6D' value='{ch-6D}' min='0'></td></tr>"
  "<tr><td>7</td><td id='val7'></td>"
    "<td><input type='number' name='ch7A' value='{ch-7A}' min='0'></td>"
    "<td><input type='number' name='ch7B' value='{ch-7B}' min='0'></td>"
    "<td><input type='number' name='ch7C' value='{ch-7C}' min='0'></td>"
    "<td><input type='number' name='ch7D' value='{ch-7D}' min='0'></td></tr>"
  "<tr><td>8</td><td id='val8'></td>"
    "<td><input type='number' name='ch8A' value='{ch-8A}' min='0'></td>"
    "<td><input type='number' name='ch8B' value='{ch-8B}' min='0'></td>"
    "<td><input type='number' name='ch8C' value='{ch-8C}' min='0'></td>"
    "<td><input type='number' name='ch8D' value='{ch-8D}' min='0'></td></tr>"
 "</table>"
"<table class='block'>"
  "<tr><th colspan='3'>Networking</th></tr>"
  "<tr><td>Ethernet Mode</td><td>"
    "<select name='n1'>"
      "<option value='1' {net-1}>Static</option>"
      "<option value='2' {net-2}>DHCP</option></td>"
  "<td class='note'>DHCP mode switches to static values if DHCP is not found</td></tr>"
  "<tr><td>Static IP</td><td><input value='{net-staticIP}' name='n2' maxLength='15'></td><td></td></tr>"
  "<tr><td>Subnet Mask</td><td><input value='{net-subnet}' name='n3' maxLength='15'></td><td></td></tr>"
  "<tr><td>Gateway</td><td><input value='{net-gateway}' name='n4' maxLength='15'></td><td></td></tr>"
  "<tr><td>Receive Port</td><td><input value='{net-port}' type='number' name='n5' min='1' max='65535'></td><td class='note'>Ignored in operation modes that require a specific port number</td></tr>"
  "<tr><td>Destination IP</td><td><input value='{net-destIP}' name='n6' maxLength='15'></td><td></td></tr>"
  "<tr><td>Destination Port</td><td><input value='{net-destPort}' type='number' name='n7' min='1' max='65535'></td><td class='note'>Ignored in operation modes that require a specific port number</td></tr>"
  "<tr><td>MAC Address</td><td><em>{net-mac}</em></td><td></td></tr>"
"</table>"
"<table class='block'>"
  "<tr><th colspan='3'>Operation</th></tr>"
  "<tr><td>Mode</td><td><select name='op'>"
    "<option value='1' {op-1}>MIDI</option>"
    "<option value='2' {op-2}>MIDI (Motors disabled)</option>"
    "<option value='3' {op-3}>QLab</option>"
    "<option value='4' {op-4}>GrandMA2</option>"
    "<option value='6' {op-6}>ETC Eos</option>"
    "<option value='7' {op-7}>DiGiCo</option>"
    "<option value='8' {op-8}>X32/M32</option>"
    "<option value='10' {op-10}>Dance</option>"
  "</select></td><td></td></tr>"
"</table>"
"<table class='block mode'>"
  "<tr><th colspan='3'>&#11153;&nbsp;&nbsp; MIDI Mode</th></tr>"
  "<tr><td>Send Channel</td><td><input value='{midi-send-ch}' type='number' name='m92' min='1' max='16'></td><td></td></tr>"
  "<tr><td>Listen Channel</td><td><input value='{midi-listen-ch}' type='number' name='m91' min='1' max='16'></td><td></td></tr>"
"</table>"
"<table class='block mode'>"
  "<tr><th colspan='3'>&#11153;&nbsp;&nbsp; QLab Mode</th></tr>"
  "<tr><td>OSC Passcode</td><td><input value='{qlab-passcode}' type='text' name='q5' maxlength='8'></td><td></td></tr>"
  "<tr><td>Maximum Volume</td><td><input value='{qlab-max}' type='number' name='q1' min='0' max='24'><small>db</small></td><td></td></tr>"
  "<tr><td>Minimum Volume</td><td><input value='-{qlab-min}' type='number' name='q2' min='-127' max='0'><small>db</small></td><td></td></tr>"
  "<tr><td>MIDI</td><td><input type='checkbox' name='q3' {q3}></td><td><small>Pages 3/4 are MIDI controls for QLab Lighting</small></td></tr>"
  "<tr><td>Auto MIDI Switch</td><td><input type='checkbox' name='q4' {q4}></td><td><small>Switch to MIDI automatically depending on selected cue's type</small></td></tr>"
"</table>"
"<table class='block mode'>"
  "<tr><th colspan='3'>&#11153;&nbsp;&nbsp; ETC Eos Mode</th></tr>"
  "<tr><td>OSC Bank ID</td><td><input value='{eos-bank}' type='number' name='e1' min='1' max='16'></td><td><small>All OSC fader banks, including apps, must have a unique ID.</small></td></tr>"
  "<tr><td>Fader Count</td><td><input value='{eos-count}' type='number' name='e2' min='1' max='255'></td><td></td></tr>"
"</table>"
"<table class='block mode'>"
  "<tr><th colspan='3'>&#11153;&nbsp;&nbsp; X32/M32 Mode</th></tr>"
  "<tr><td>Target</td><td><select name='x1'>"
    "<option value='1' {x1-1}>Channel</option>"
    "<option value='2' {x1-2}>DCA</option>"
    "<option value='3' {x1-3}>Bus</option>"
    "<option value='4' {x1-4}>Aux In</option>"
    "<option value='5' {x1-5}>FX Return</option>"
    "<option value='6' {x1-6}>Matrix</option>"
  "</select></td><td></td></tr>"
"</table>"
"<table class='block mode'>"
  "<tr><th colspan='9'>&#11153;&nbsp;&nbsp; GrandMA2 MSC over Ethernet</th></tr>"
  "<tr><td colspan='1'></td><td>Device</td><td>Group</td><td>Format</td><td>Send To</td></tr>"
  "<tr><td>Listen</td>"
    "<td><input type='number' name='maindev' value='{main-dev}' min='0' max='111'></td>"
    "<td><input type='number' name='maingrp' value='{main-grp}' min='1' max='15'></td>"
    "<td><select name='mainfmt'>"
      "<option value='1' {main-f1}>General Light</option>"
      "<option value='2' {main-f2}>Moving Light</option>"
      "<option value='127' {main-f3}>All devices</option>"
    "</select></td>"
    "<td colspan='2'>&nbsp</td>"
  "</tr>"
  "<tr><td>Send</td>"
    "<td><input type='number' name='maoutdev' value='{maout-dev}' min='0' max='111'></td>"
    "<td><input type='number' name='maoutgrp' value='{maout-grp}' min='1' max='15'></td>"
    "<td><select name='maoutfmt'>"
      "<option value='1' {maout-f1}>General Light</option>"
      "<option value='2' {maout-f2}>Moving Light</option>"
      "<option value='127' {maout-f3}>All devices</option>"
    "</select></td>"
    "<td><select name='masendto'>"
      "<option value='1' {maout-s2}>Device</option>"
      "<option value='2' {maout-s2}>Group</option>"
      "<option value='127' {maout-s3}>All</option>"
    "</select></td>"
  "</tr>"
"</table><table class='block mode'>"
  "<tr><td colspan='1'></td><td colspan='2'>Page 1</td><td colspan='2'>Page 2</td><td colspan='2'>Page 3</td><td colspan='2'>Page 4</td></tr>"
  "<tr><td>#</td><td>Exec</td><td>Fader</td><td>Exec</td><td>Fader</td><td>Exec</td><td>Fader</td><td>Exec</td><td>Fader</td></tr>"
   "<tr><td>1</td>"
      "<td><input type='number' name='map11' value='{map-11}' min='1' max='45'></td>"
      "<td><input type='number' name='maf11' value='{maf-11}' min='1' max='127'></td>"
      "<td><input type='number' name='map21' value='{map-21}' min='1' max='45'></td>"
      "<td><input type='number' name='maf21' value='{maf-21}' min='1' max='127'></td>"
      "<td><input type='number' name='map31' value='{map-31}' min='1' max='45'></td>"
      "<td><input type='number' name='maf31' value='{maf-31}' min='1' max='127'></td>"
      "<td><input type='number' name='map41' value='{map-41}' min='1' max='45'></td>"
      "<td><input type='number' name='maf41' value='{maf-41}' min='1' max='127'></td>"
   "</tr>"
   "<tr><td>2</td>"
      "<td><input type='number' name='map12' value='{map-12}' min='1' max='45'></td>"
      "<td><input type='number' name='maf12' value='{maf-12}' min='1' max='127'></td>"
      "<td><input type='number' name='map22' value='{map-22}' min='1' max='45'></td>"
      "<td><input type='number' name='maf22' value='{maf-22}' min='1' max='127'></td>"
      "<td><input type='number' name='map32' value='{map-32}' min='1' max='45'></td>"
      "<td><input type='number' name='maf32' value='{maf-32}' min='1' max='127'></td>"
      "<td><input type='number' name='map42' value='{map-42}' min='1' max='45'></td>"
      "<td><input type='number' name='maf42' value='{maf-42}' min='1' max='127'></td>"
   "</tr>"
   "<tr><td>3</td>"
      "<td ><input type='number' name='map13' value='{map-13}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf13' value='{maf-13}' min='1' max='127'></td>"
      "<td ><input type='number' name='map23' value='{map-23}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf23' value='{maf-23}' min='1' max='127'></td>"
      "<td ><input type='number' name='map33' value='{map-33}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf33' value='{maf-33}' min='1' max='127'></td>"
      "<td ><input type='number' name='map43' value='{map-43}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf43' value='{maf-43}' min='1' max='127'></td>"
   "</tr>"
   "<tr><td>4</td>"
      "<td ><input type='number' name='map14' value='{map-14}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf14' value='{maf-14}' min='1' max='127'></td>"
      "<td ><input type='number' name='map24' value='{map-24}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf24' value='{maf-24}' min='1' max='127'></td>"
      "<td ><input type='number' name='map34' value='{map-34}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf34' value='{maf-34}' min='1' max='127'></td>"
      "<td ><input type='number' name='map44' value='{map-44}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf44' value='{maf-44}' min='1' max='127'></td>"
   "</tr>"
   "<tr><td>5</td>"
      "<td ><input type='number' name='map15' value='{map-15}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf15' value='{maf-15}' min='1' max='127'></td>"
      "<td ><input type='number' name='map25' value='{map-25}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf25' value='{maf-25}' min='1' max='127'></td>"
      "<td ><input type='number' name='map35' value='{map-35}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf35' value='{maf-35}' min='1' max='127'></td>"
      "<td ><input type='number' name='map45' value='{map-45}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf45' value='{maf-45}' min='1' max='127'></td>"
   "</tr>"
   "<tr><td>6</td>"
      "<td ><input type='number' name='map16' value='{map-16}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf16' value='{maf-16}' min='1' max='127'></td>"
      "<td ><input type='number' name='map26' value='{map-26}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf26' value='{maf-26}' min='1' max='127'></td>"
      "<td ><input type='number' name='map36' value='{map-36}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf36' value='{maf-36}' min='1' max='127'></td>"
      "<td ><input type='number' name='map46' value='{map-46}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf46' value='{maf-46}' min='1' max='127'></td>"
   "</tr>"
   "<tr><td>7</td>"
      "<td ><input type='number' name='map17' value='{map-17}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf17' value='{maf-17}' min='1' max='127'></td>"
      "<td ><input type='number' name='map27' value='{map-27}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf27' value='{maf-27}' min='1' max='127'></td>"
      "<td ><input type='number' name='map37' value='{map-37}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf37' value='{maf-37}' min='1' max='127'></td>"
      "<td ><input type='number' name='map47' value='{map-47}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf47' value='{maf-47}' min='1' max='127'></td>"
   "</tr>"
   "<tr><td>8</td>"
      "<td ><input type='number' name='map18' value='{map-18}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf18' value='{maf-18}' min='1' max='127'></td>"
      "<td ><input type='number' name='map28' value='{map-28}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf28' value='{maf-28}' min='1' max='127'></td>"
      "<td ><input type='number' name='map38' value='{map-38}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf38' value='{maf-38}' min='1' max='127'></td>"
      "<td ><input type='number' name='map48' value='{map-48}' min='1' max='45'></td>"
      "<td ><input type='number' name='maf48' value='{maf-48}' min='1' max='127'></td>"
   "</tr>"

"</table>""<table class='block'>"
  "<tr><th colspan='3'>Fader Tuning</th></tr>"
  "<tr><td>Touch Sensitivity</td><td><input value='{touch-sense}' type='number' name='t4' min='4' max='200'></td><td class='note'>Lower numbers mean more sensitivty and smoother slow fades, but potentially also phantom touches.</td></tr></tr>"
  "<tr><td>Message wait</td><td><input value='{msg-wait}' type='number' name='t0'</td><td class='note'>Milliseconds to wait between sending OSC or MIDI messages</td></tr></tr>"
  "<tr><td>Minimum Speed</td><td><input value='{min-speed}' type='number' name='t1'></td><td class='note'>Minimum PWM speed of motors</td></tr>"
  "<tr><td>Speed Scale</td><td><input value='{speed-scale}' type='number' name='t2'></td><td class='note'>Increases speed of motor by 1/scale as the distance to travel increases</td></tr>"
  "<tr><td>Drive Frequency</td><td><input value='{motor-frequency}' type='number' name='t3'></td><td class='note'>PWM frequency of microcontroller output</td></tr>"
  "<tr><td>Motherboard</td><td><select name='mb'>"
    "<option value='1' {mb-1}>V1.0 - 1.3</option>"
    "<option value='2' {mb-2}>V1.4 +</option>"
  "</select></td><td class='note'>Motherboard revision</td></tr>"
  "<tr><td>Rotated</td><td><input type='checkbox' name='rot' {rot}></td><td class='note'>For mounting the FADER_X upside-down</td></tr>"
"</table>"
"</form>"
"<script>"
"setInterval(function(){"
"fetch('/fader').then(function(response){return response.json()}).then(function(data){"
"for(i=0;i<8;i++){"
"document.getElementById('val'+(i+1)).innerHTML = '<em>'+data[i]+'</em>';"
"}"
"});"
"}, 100);"
"</script>"
"</body></html>";

char htmlBuf[14000];

char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void serveGET(EthernetClient client) {
  String clientBuf;
  //Serial.println("************************************");

  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      
      if(c=='\n' || c=='\r'){
        if(clientBuf.length()>1){

          char ipStr[36];
            sprintf(ipStr, "Location: http://%i.%i.%i.%i",
              net.IP_Static[0],
              net.IP_Static[1],
              net.IP_Static[2],
              net.IP_Static[3]);
              
          if(clientBuf.startsWith("GET")){
            //Serial.println(clientBuf);
          }
          
          if(clientBuf.startsWith("GET /apply")){
            applySettings(&client, &clientBuf);

            client.println("HTTP/1.1 301 Moved Permanently");
            client.println(ipStr);
            client.println("Connection: close");
            client.println("Content-Type: text/html");
            client.println();
            client.println("<h1>updated</h1>");
            client.flush();
            break;
            
          }else if(clientBuf.startsWith("GET /fader ")){
            
            client.println("HTTP/1.1 200 OK");
            client.println("Connection: close");
            client.println("Content-Type: text/html");
            client.println();

            char fd[128];
            sprintf(fd, "[\"%i@%i (%i)\",\"%i@%i (%i)\",\"%i@%i (%i)\",\"%i@%i (%i)\",\"%i@%i (%i)\",\"%i@%i (%i)\",\"%i@%i (%i)\",\"%i@%i (%i)\"]",
              fader1.getChannel(),
              fader1.getPositionTrimmed(),
              fader1.getMode(),
              fader2.getChannel(),
              fader2.getPositionTrimmed(),
              fader2.getMode(),
              fader3.getChannel(),
              fader3.getPositionTrimmed(),
              fader3.getMode(),
              fader4.getChannel(),
              fader4.getPositionTrimmed(),
              fader4.getMode(),
              fader5.getChannel(),
              fader5.getPositionTrimmed(),
              fader5.getMode(),
              fader6.getChannel(),
              fader6.getPositionTrimmed(),
              fader6.getMode(),
              fader7.getChannel(),
              fader7.getPositionTrimmed(),
              fader7.getMode(),
              fader8.getChannel(),
              fader8.getPositionTrimmed(),
              fader8.getMode());

            client.println(fd);
            client.flush();

            break;

          }else if(clientBuf.startsWith("GET /reset ")){

            client.println("HTTP/1.1 200 OK");
            client.println("Connection: open");
            client.println("Content-Type: text/html");
            client.println();
            client.println(headTemplate);
            client.println("<header>FADER_X Configuration</header>");
            client.writeFully("<h3 style='padding:20px;'>Are you sure you want to perform a factory reset?</h3>");
            client.writeFully("<p style='padding:20px;'><a href='/doReset'>Reset</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='./'>Cancel</a></p>");
            client.writeFully("<p style='padding:20px;'>Admin IP after factory reset will be <u>192.168.1.130</u></p>");
            //client.close();
            break;

          }else if(clientBuf.startsWith("GET /doReset ")){

            factoryReset();
            globalNewSettingsFlag = true;

            client.println("HTTP/1.1 303 See Other");
            client.println("Location: http://192.168.1.130");
            client.println("Connection: close");
            client.println("Content-Type: text/html");
            client.println();
            client.println("<h1>updated</h1>");
            client.flush();
            break;

          }else if(clientBuf.startsWith("GET / ")){
            generateIndex();
            
            client.println("HTTP/1.1 200 OK");
            client.println("Connection: open");
            client.println("Content-Type: text/html");
            client.println();
            client.println(headTemplate);
            client.writeFully(htmlBuf);
            client.close();
            break;
            
          }else if(clientBuf.startsWith("GET /")){
            Serial.println("disregard favicon");
            break;

          }
        }
        clientBuf = "";

      }else{
        clientBuf.concat(c);
      }

    }else{
      break;
    }
  }
  
}

void generateIndex(){

  String temp = bodyTemplate;

  temp.replace("{v1}", versionMajor);
  temp.replace("{v2}", versionMinor);
  temp.replace("{v3}", versionSub);

  temp.replace("{touch-sense}", globalTouchSensitivity);
  temp.replace("{msg-wait}", globalMessageWaitMillis);
  temp.replace("{min-speed}", globalMotorMinSpeed);
  temp.replace("{speed-scale}", globalMotorSpeedScale);
  temp.replace("{motor-frequency}", globalMotorFrequency);

  if(globalRotated){
    temp.replace("{rot}", "checked");
  }else{
    temp.replace("{rot}", "");
  }

  if(globalMotherboardRevision==1){
    temp.replace("{mb-1}", "selected");
    temp.replace("{mb-2}", "");
  }else if(globalMotherboardRevision==2){
    temp.replace("{mb-2}", "selected");
    temp.replace("{mb-1}", "");
  }

  char LocalIPBuf[15];
  char SubnetBuf[15];
  char GatewayBuf[15];
  char DestIPBuf[15];
  char MacBuf[17];
  
  sprintf(LocalIPBuf, "%i.%i.%i.%i", net.getIP_Static(0), net.getIP_Static(1), net.getIP_Static(2), net.getIP_Static(3));
  sprintf(SubnetBuf, "%i.%i.%i.%i", net.getIP_Subnet(0), net.getIP_Subnet(1), net.getIP_Subnet(2), net.getIP_Subnet(3));
  sprintf(GatewayBuf, "%i.%i.%i.%i", net.getIP_Gateway(0), net.getIP_Gateway(1), net.getIP_Gateway(2), net.getIP_Gateway(3));
  sprintf(DestIPBuf, "%i.%i.%i.%i", net.getIP_Destination(0), net.getIP_Destination(1), net.getIP_Destination(2), net.getIP_Destination(3));
  sprintf(MacBuf, "%02x:%02x:%02x:%02x:%02x:%02x\n", net.getMAC(0), net.getMAC(1), net.getMAC(2), net.getMAC(3), net.getMAC(4), net.getMAC(5));

  temp.replace("{ch-1A}", globalFaderChannels[0]);
  temp.replace("{ch-2A}", globalFaderChannels[1]);
  temp.replace("{ch-3A}", globalFaderChannels[2]);
  temp.replace("{ch-4A}", globalFaderChannels[3]);
  temp.replace("{ch-5A}", globalFaderChannels[4]);
  temp.replace("{ch-6A}", globalFaderChannels[5]);
  temp.replace("{ch-7A}", globalFaderChannels[6]);
  temp.replace("{ch-8A}", globalFaderChannels[7]);

  temp.replace("{ch-1B}", globalFaderChannels[8]);
  temp.replace("{ch-2B}", globalFaderChannels[9]);
  temp.replace("{ch-3B}", globalFaderChannels[10]);
  temp.replace("{ch-4B}", globalFaderChannels[11]);
  temp.replace("{ch-5B}", globalFaderChannels[12]);
  temp.replace("{ch-6B}", globalFaderChannels[13]);
  temp.replace("{ch-7B}", globalFaderChannels[14]);
  temp.replace("{ch-8B}", globalFaderChannels[15]);

  temp.replace("{ch-1C}", globalFaderChannels[16]);
  temp.replace("{ch-2C}", globalFaderChannels[17]);
  temp.replace("{ch-3C}", globalFaderChannels[18]);
  temp.replace("{ch-4C}", globalFaderChannels[19]);
  temp.replace("{ch-5C}", globalFaderChannels[20]);
  temp.replace("{ch-6C}", globalFaderChannels[21]);
  temp.replace("{ch-7C}", globalFaderChannels[22]);
  temp.replace("{ch-8C}", globalFaderChannels[23]);

  temp.replace("{ch-1D}", globalFaderChannels[24]);
  temp.replace("{ch-2D}", globalFaderChannels[25]);
  temp.replace("{ch-3D}", globalFaderChannels[26]);
  temp.replace("{ch-4D}", globalFaderChannels[27]);
  temp.replace("{ch-5D}", globalFaderChannels[28]);
  temp.replace("{ch-6D}", globalFaderChannels[29]);
  temp.replace("{ch-7D}", globalFaderChannels[30]);
  temp.replace("{ch-8D}", globalFaderChannels[31]);
  
  String ep;
  for(int i=0; i<32; i++) {
    ep = String((i/8+1)*10 + i%8+1);
    temp.replace("{map-"+ep+"}", ma2.maFaders[i*3]);
    temp.replace("{maf-"+ep+"}", ma2.maFaders[i*3+1]);
  }
  temp.replace("{main-dev}", ma2.listenDevice);
  temp.replace("{main-grp}", ma2.listenGroup);
  switch(ma2.listenFormat){
    case 1:temp.replace("{main-f1}", "selected");break;
    case 2:temp.replace("{main-f2}", "selected");break;
    case 0x7f:temp.replace("{main-f3}", "selected");break;
  }
  temp.replace("{maout-dev}", ma2.sendDevice);
  temp.replace("{maout-grp}", ma2.sendGroup);
  switch(ma2.sendFormat){
    case 1:temp.replace("{maout-f1}", "selected");break;
    case 2:temp.replace("{maout-f2}", "selected");break;
    case 0x7f:temp.replace("{maout-f3}", "selected");break;
  }
  switch(ma2.sendTo){
    case 1:temp.replace("{maout-s1}", "selected");break;
    case 2:temp.replace("{maout-s2}", "selected");break;
    case 0x7f:temp.replace("{maout-s3}", "selected");break;
  }






  switch(net.netMode){
    case 1:temp.replace("{net-1}", "selected");break;
    case 2:temp.replace("{net-2}", "selected");break;
  }
  temp.replace("{net-staticIP}", LocalIPBuf);
  temp.replace("{net-subnet}", SubnetBuf);
  temp.replace("{net-gateway}", GatewayBuf);
  temp.replace("{net-port}", net.getIP_SelfPort());
  temp.replace("{net-destIP}", DestIPBuf);
  temp.replace("{net-destPort}", net.getIP_DestinationPort());
  temp.replace("{net-mac}", MacBuf);

  temp.replace("{midi-send-ch}", midi.sendChannel);
  temp.replace("{midi-listen-ch}", midi.listenChannel);

  temp.replace("{qlab-max}", qlab.maximumVolume);
  temp.replace("{qlab-min}", qlab.minimumVolume);

  if(qlab.midiEnabled){
    temp.replace("{q3}", "checked");
  }else{
    temp.replace("{q3}", "");
  }

  if(qlab.autoMidi){
    temp.replace("{q4}", "checked");
  }else{
    temp.replace("{q4}", "");
  }

  temp.replace("{qlab-passcode}", qlab.passcode);

  temp.replace("{eos-bank}", eos.faderBank);
  temp.replace("{eos-count}", eos.faderCount);

  switch(EEPROM.read(150)){
    case 1:temp.replace("{x1-1}", "selected");break;
    case 2:temp.replace("{x1-2}", "selected");break;
    case 3:temp.replace("{x1-3}", "selected");break;
    case 4:temp.replace("{x1-4}", "selected");break;
    case 5:temp.replace("{x1-5}", "selected");break;
    case 6:temp.replace("{x1-6}", "selected");break;
  }

  switch(EEPROM.read(24)){
    case 1:temp.replace("{op-1}", "selected");break;
    case 2:temp.replace("{op-2}", "selected");break;
    case 3:temp.replace("{op-3}", "selected");break;
    case 4:temp.replace("{op-4}", "selected");break;
    case 6:temp.replace("{op-6}", "selected");break;
    case 7:temp.replace("{op-7}", "selected");break;
    case 8:temp.replace("{op-8}", "selected");break;
    case 10:temp.replace("{op-10}", "selected");break;
  }
  
  temp.replace("{op-1}", "");
  temp.replace("{op-2}", "");
  temp.replace("{op-3}", "");
  temp.replace("{op-4}", "");
  temp.replace("{op-6}", "");
  temp.replace("{op-7}", "");
  temp.replace("{op-8}", "");
  temp.replace("{op-10}", "");

  temp.replace("{tok1}", letters[random(0, 36)]);
  temp.replace("{tok2}", letters[random(0, 36)]);
  temp.replace("{tok3}", letters[random(0, 36)]);
  temp.replace("{tok4}", letters[random(0, 36)]);

  temp.toCharArray(htmlBuf, temp.length()+1);

}


String getParameter(String*buf, int start){
  int end = buf->indexOf("&", start);
  if(end==-1){
    end = buf->indexOf(" HTTP/1.1", start);
  }
  return buf->substring(start, end);
}
int containsParam(String*buf, String param){
  int i = buf->indexOf(param.concat("="));
  if(i>0){
    return i+param.length();
  }else{
    return 0;
  }
  
}
