void cmd_decode()
{
// check for remote selection
int selectDevice = 0;
int selectAll = 0;
int selectGraphic = 0;
if ((cmd_str[1] == address_str[0]) && (cmd_str[2] == address_str[1])){
  selectDevice = 1;
  } 
if ((cmd_str[1] == '0') && (cmd_str[2] == '0') && (address_str[0] != '9')){
  selectAll = 1;  // does not apply to a time clock device
  }
// only check graphics if device not already selected 
// and not a time clock device
if ((selectDevice == 0) && (selectAll == 0) && (address_str[0] != '9')){ 
  selectGraphic = checkGraphicSelect(); 
  // returns int 1 if device selected, int 0 otherwise
  }
// for testing on Serial monitor with Arduino Uno 
// note - now use 3840 baud rate
//Serial.println(selectDevice);
//Serial.println(selectAll);
//Serial.println(selectGraphic);

if ((selectDevice == 0) && (selectAll == 0) && (selectGraphic == 0)){ 
  return;  // no device selected
  }

  // 0L command - set letter
  if (cmd_str[3] == '0')
    {
    gLedBlink();
    letterCommand();
    }
  // 10 command - reset command
  if ((cmd_str[3] == '1') && (cmd_str[4] == '0'))
    { 
    gLedBlink();
    while(1); // watchdog timer should get triggered here - cleanest way to reset
    }
  // 11 command - turn on Request! command (active low)
  if ((cmd_str[3] == '1') && (cmd_str[4] == '1'))
    { 
    digitalWrite(requestPin, HIGH); // active high turns on Request! command (active low)
    gLedBlink();
    }
  // 12 command - turn off Request! command
  if ((cmd_str[3] == '1') && (cmd_str[4] == '2'))   
    { 
    digitalWrite(requestPin, LOW); // active high turns on Request! command (active low)
    gLedBlink();
    }
  // 20 command - set gLed for power
  if ((cmd_str[3] == '2') && (cmd_str[4] == '0'))   
    { 
    gLedFunction = 0;
    updateHomeIndexStates();
    digitalWrite(gLedPin, LOW); // turn on green led
    gLedBlink();
    }
  // 21 command - set gLed for index
  if ((cmd_str[3] == '2') && (cmd_str[4] == '1'))   
    { 
    gLedFunction = 1;
    updateHomeIndexStates();
    gLedBlink();
    }
  // 22 command - set rLed for home
  if ((cmd_str[3] == '2') && (cmd_str[4] == '2'))   
    { 
    rLedFunction = 0;
    updateHomeIndexStates();
    gLedBlink();
    }
  // 23 command - set rLed for index and home 
  if ((cmd_str[3] == '2') && (cmd_str[4] == '3'))   
    { 
    rLedFunction = 1;
    updateHomeIndexStates();
    gLedBlink();
    }
  // 24 command - set gLed on (default on)
  if ((cmd_str[3] == '2') && (cmd_str[4] == '4'))   
    { 
    gLedEnable = 1;
    updateHomeIndexStates();
    gLedBlink();
    }
  // 25 command - set gLed off
  if ((cmd_str[3] == '2') && (cmd_str[4] == '5'))   
    { 
    gLedEnable = 0;
    updateHomeIndexStates();
    gLedBlink();
    }
  // 26 command - set rLed on (default on)
  if ((cmd_str[3] == '2') && (cmd_str[4] == '6'))   
    { 
    rLedEnable = 1;
    updateHomeIndexStates();
    gLedBlink();
    }
  // 27 command - set rLed off
  if ((cmd_str[3] == '2') && (cmd_str[4] == '7'))   
    { 
    rLedEnable = 0;
    updateHomeIndexStates();
    gLedBlink();
    }
  // 30 to 39 commands - flapAdvance 1 to 10 flaps
  if ((cmd_str[3] == '3'))   
    {
    gLedBlink();
    int k = cmd_str[4] - '0';  // convert to integer
    if (k > 9 || k < 0) {k = 1;} // boundary check
    if (k == 0) {k = 10;}  // boundary condition
    for (int j = 1; j <= k; j++){
      flapAdvance(1); //one flap
      }
    }
  // 40 command - flapAdvance 40 flaps
  if ((cmd_str[3] == '4') && (cmd_str[4] == '0'))
    {
    gLedBlink();
    flapAdvance(40);
    }
  // 41 command - flapAdvance 80 flaps
  if ((cmd_str[3] == '4') && (cmd_str[4] == '1'))
    {
    gLedBlink();
    flapAdvance(80);
    }
  // 42 command - motor test 
  if ((cmd_str[3] == '4') && (cmd_str[4] == '2'))
    {
    gLedBlink();
    mTest();
    }
  // 43 command - clear index or motor error count
  if ((cmd_str[3] == '4') && (cmd_str[4] == '3'))
    {
    gLedBlink();
    indexErrorCount = 0;
    }
  // 44 command - clear home error count
  if ((cmd_str[3] == '4') && (cmd_str[4] == '4'))
    {
    gLedBlink();
    homeErrorCount = 0;
    }
  // 50 command - increase drive time by 5 ms - 75 ms is default
  if ((cmd_str[3] == '5') && (cmd_str[4] == '0'))   
    { 
    driveTime = driveTime + 5;
    gLedBlink();
    }
  // 51 command - reduce drive time by 5 ms - note 55 ms appears to be the minimum
  if ((cmd_str[3] == '5') && (cmd_str[4] == '1'))   
    { 
    driveTime = driveTime - 5;
    gLedBlink();
    }
  // 52 command - increase pause time by 5 ms - 50ms is default
  if ((cmd_str[3] == '5') && (cmd_str[4] == '2'))   
    { 
    pauseTime = pauseTime + 5;
    gLedBlink();
    }
  // 53 command - reduce pause time by 5 ms - note 45 appears to be the minimum
  if ((cmd_str[3] == '5') && (cmd_str[4] == '3'))   
    { 
    pauseTime = pauseTime - 5;
    gLedBlink();
    }
  // 6L command - set position at L 
  // may be used on power up (relay on)to restore position
  if (cmd_str[3] == '6')
    {
    // find index for char in split flap array
    // see letterCommand() code for reference
    char *e;
    e = strchr(flipChars_str, cmd_str[4]);
    charToIdx = (int)(e - flipChars_str);
    if (e) // valid character found
      {
      // use table to determine flip position
      flipAtIdx = charLookup[charToIdx];
      flipToIdx = flipAtIdx;
      homeFound = true; 
      currentCharacter_str[0] = cmd_str[4];
      updateHomeIndexStates(); 
      }
    gLedBlink();
    }   
  // hold commands - primarily for graphics
  // holdFlag is 1 for letter, 2 for advance 40, 3 for advance 80
  //  and 4 for if non space, advance by 1 on later commit
  
  // 7L command - set letter for later commit
  if (cmd_str[3] == '7')
    { 
    holdLetter = cmd_str[4];
    holdFlag = 1; 
    gLedBlink();
    }
  // 80 command - 40 advance on later commit
  if ((cmd_str[3] == '8') && (cmd_str[4] == '0'))
    { 
    holdFlag = 2; // 2 for advance 40
    gLedBlink();
    }
  // 81 command - 80 advance on later commit
  if ((cmd_str[3] == '8') && (cmd_str[4] == '1'))
    { 
    holdFlag = 3; // 3 for advance 80
    gLedBlink();
    }
  // 82 command - if non space, advance by 1 on later commit
  if ((cmd_str[3] == '8') && (cmd_str[4] == '2'))
    { 
    holdFlag = 4; // 4 for if non space advance by 1 on later commit
    gLedBlink();
    }
  // commit command
  if ((cmd_str[3] == '8') && (cmd_str[4] == '9')) // commit earlier hold
    { 
    gLedBlink();
    if (holdFlag == 1)
      {
      cmd_str[4] = holdLetter;
      letterCommand();
      }
    if (holdFlag == 2)
      {
      gLedBlink();
      flapAdvance(40);
      }
    if (holdFlag == 3)
      {
      gLedBlink();
      flapAdvance(80);
      }
    if (holdFlag == 4)
      {
      gLedBlink();
      if ((currentCharacter_str[0] != '?') && (currentCharacter_str[0] != ' ')){
        flapAdvance(1);
        }
      }
    holdFlag = 0; // reset holdFlag and hold Letter
    holdLetter = '!';
    }
  
// end of non-reporting commands

if (selectDevice == 1){ // transmit back limited to one device at a time
  // 90 command - report position, home, index and motor error
  if ((cmd_str[3] == '9') && (cmd_str[4] == '0'))
    {
    updateHomeIndexStates(); // update current home and index positions
    strcpy(transmit_str, address_str);
    strcat(transmit_str, " - ");
    strcat(transmit_str, currentCharacter_str); 
    if (homeState == LOW) {strcat(transmit_str, ", 1");}
    else {strcat(transmit_str, ", 0");}
    if (indexState == LOW) {strcat(transmit_str, ", 1");}
    else {strcat(transmit_str, ", 0");}
    if ((indexErrorCount >= 1) || (homeErrorCount >= 1)) {
      sprintf(indexErrorCount_str, "%i", indexErrorCount);
      strcat(transmit_str, ", ");
      strcat(transmit_str, indexErrorCount_str);
      strcat(transmit_str, " ie");
      sprintf(homeErrorCount_str, "%i", homeErrorCount);
      strcat(transmit_str, ", ");
      strcat(transmit_str, homeErrorCount_str);
      strcat(transmit_str, " he");
      }
    else {
      strcat(transmit_str, ", ok");
      }
    strcat(transmit_str, "\n");
    transmitBack();
    gLedBlink(); // cannot be earlier as short window for transmission back
    }
  // 91 command - report version of code
  if ((cmd_str[3] == '9') && (cmd_str[4] == '1'))
    {
    strcpy(transmit_str, address_str);
    strcat(transmit_str, " - ");
    strcat(transmit_str, version_str);
    strcat(transmit_str, "\n");
    transmitBack(); 
    gLedBlink(); // cannot be earlier as short window for transmission back
    }
  // 92 command - report length test - send back 01 - a...z1...3
  // at 38400 baud rate and after 8ms delay received transmission through letter y
  if ((cmd_str[3] == '9') && (cmd_str[4] == '2'))
    {
    strcpy(transmit_str, address_str);
    strcat(transmit_str, " - ");
    strcat(transmit_str, "abcdefghijklmnopqrstuvwxyz123");
    strcat(transmit_str, "\n");
    transmitBack();
    gLedBlink(); // cannot be earlier as short window for transmission back
    }     
  }
} 

int checkGraphicSelect()
{
// check for graphics command
// remote device performs its own selection decode
// convert string to integer for decoding with array
int address_int = atoi(address_str); 
if (address_int > 48) {return 0;}

//columns
if ((cmd_str[1] == 'c') && (cmd_str[2] == '1')){
  const static int c1[48] PROGMEM = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&c1[address_int-1]) == 1){return 1;}
  }             
if ((cmd_str[1] == 'c') && (cmd_str[2] == '2')){
  const static int c2[48] PROGMEM = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&c2[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == '3')){
  const static int c3[48] PROGMEM = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&c3[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == '4')){
  const static int c4[48] PROGMEM = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&c4[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == '5')){
  const static int c5[48] PROGMEM = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&c5[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == '6')){
  const static int c6[48] PROGMEM = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&c6[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == '7')){
  const static int c7[48] PROGMEM = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&c7[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == '8')){
  const static int c8[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}; 
  if (pgm_read_byte(&c8[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == '9')){
  const static int c9[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}; 
  if (pgm_read_byte(&c9[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == 'a')){       
  const static int ca[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}; 
  if (pgm_read_byte(&ca[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == 'b')){
  const static byte cb[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}; 
  if (pgm_read_byte(&cb[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'c') && (cmd_str[2] == 'c')){
  const static int cc[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}; 
  // for testing on Serial monitor with Arduino Uno
  // note - now use 38400 baud rate
  // can use pgm_read_byte, pgm_read_word, or pgm_read_dword
  // for 1, 2 and 4 bytes respectively 
  // characters are stored as their ascii number in a byte
  // integers might be stored in a dword, or if small, a byte 
  // this is working for our 0s and 1s here
  //Serial.println(pgm_read_byte(&cc[address_int-1]));
  //Serial.println(address_int-1);
  //for (int k = 0; k<48; k++){
  //  Serial.print(pgm_read_byte(&cc[k]));
  //  Serial.print("  ");
  //  }
  //Serial.println();
  if (pgm_read_byte(&cc[address_int-1]) == 1){return 1;}
  }    
if ((cmd_str[1] == 'd') && (cmd_str[2] == '1')){
  const static int d1[48] PROGMEM = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  // for testing on Serial monitor with Arduino Uno
  //Serial.println(pgm_read_byte(&d1[address_int-1]));
  //Serial.println(address_int-1);
  //for (int k = 0; k<48; k++){
  //  Serial.print(pgm_read_byte(&d1[k]));
  //  Serial.print("  ");
  //  }
  //Serial.println();
  if (pgm_read_byte(&d1[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'd') && (cmd_str[2] == '2')){
  const static int d2[48] PROGMEM = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&d2[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'd') && (cmd_str[2] == '3')){
  const static int d3[48] PROGMEM = {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&d3[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'd') && (cmd_str[2] == '4')){
  const static int d4[48] PROGMEM = {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 
                0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}; 
  if (pgm_read_byte(&d4[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'd') && (cmd_str[2] == '5')){
  const static int d5[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}; 
  if (pgm_read_byte(&d5[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'd') && (cmd_str[2] == '6')){
  const static int d6[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}; 
  if (pgm_read_byte(&d6[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'e') && (cmd_str[2] == '1')){
  const static int e1[48] PROGMEM = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&e1[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'e') && (cmd_str[2] == '2')){
  const static int e2[48] PROGMEM = {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&e2[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'e') && (cmd_str[2] == '3')){
  const static int e3[48] PROGMEM = {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}; 
  if (pgm_read_byte(&e3[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'e') && (cmd_str[2] == '4')){
  const static int e4[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1}; 
  if (pgm_read_byte(&e4[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'e') && (cmd_str[2] == '5')){
  const static int e5[48] PROGMEM = {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 
                                     1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1,
                                     1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 
                                     1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1}; 
  if (pgm_read_byte(&e5[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'e') && (cmd_str[2] == '6')){
  const static int e6[48] PROGMEM = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}; 
  if (pgm_read_byte(&e6[address_int-1]) == 1){return 1;}
  } 

// rows
if ((cmd_str[1] == 'r') && (cmd_str[2] == '1')){
  const static int r1[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&r1[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'r') && (cmd_str[2] == '2')){
  const static int r2[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&r2[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'r') && (cmd_str[2] == '3')){
  const static int r3[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&r3[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'r') && (cmd_str[2] == '4')){
  const static int r4[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&r4[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'r') && (cmd_str[2] == '5')){
  const static int r5[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&r5[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'r') && (cmd_str[2] == '6')){
  const static int r6[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&r6[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'r') && (cmd_str[2] == '7')){
  const static int r7[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&r7[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'r') && (cmd_str[2] == '8')){
  const static int r8[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&r8[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'r') && (cmd_str[2] == '9')){
  const static int r9[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&r9[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'r') && (cmd_str[2] == 'a')){
  const static int ra[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&ra[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'r') && (cmd_str[2] == 'b')){
  const static int rb[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&rb[address_int-1]) == 1){return 1;}
  }  
if ((cmd_str[1] == 'r') && (cmd_str[2] == 'c')){
  const static int rc[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&rc[address_int-1]) == 1){return 1;}
  }  
  
// angles
if ((cmd_str[1] == 'w') && (cmd_str[2] == '1')){
  const static int w1[48] PROGMEM = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 
                                     0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0}; 
  if (pgm_read_byte(&w1[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'w') && (cmd_str[2] == '2')){
  const static int w2[48] PROGMEM = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
                                     1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 
                                     0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 
                                     0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}; 
  if (pgm_read_byte(&w2[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'w') && (cmd_str[2] == '3')){
  const static int w3[48] PROGMEM = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 
                                     1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}; 
  if (pgm_read_byte(&w3[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'w') && (cmd_str[2] == '4')){
  const static int w4[48] PROGMEM = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 
                                     0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 
                                     0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 
                                     1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&w4[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'w') && (cmd_str[2] == '5')){
  const static int w5[48] PROGMEM = {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                                     0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 
                                     1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1}; 
  if (pgm_read_byte(&w5[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'w') && (cmd_str[2] == '6')){
  const static int w6[48] PROGMEM = {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
                                     1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 
                                     0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0}; 
  if (pgm_read_byte(&w6[address_int-1]) == 1){return 1;}
  } 

if ((cmd_str[1] == 'x') && (cmd_str[2] == '1')){
  const static int x1[48] PROGMEM = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&x1[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == '2')){
  const static int x2[48] PROGMEM = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&x2[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == '3')){
  const static int x3[48] PROGMEM = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&x3[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == '4')){
  const static int x4[48] PROGMEM = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&x4[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == '5')){
  const static int x5[48] PROGMEM = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&x5[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == '6')){
  const static int x6[48] PROGMEM = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&x6[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == '7')){
  const static int x7[48] PROGMEM = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&x7[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == '8')){
  const static int x8[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&x8[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == '9')){
  const static int x9[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&x9[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == 'a')){
  const static int xa[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&xa[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == 'b')){
  const static int xb[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}; 
  if (pgm_read_byte(&xb[address_int-1]) == 1){return 1;}
  } 

if ((cmd_str[1] == 'x') && (cmd_str[2] == 'c')){
  const static int xc[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}; 
  if (pgm_read_byte(&xc[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == 'd')){
  const static int xd[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}; 
  if (pgm_read_byte(&xd[address_int-1]) == 1){return 1;}
  } 

if ((cmd_str[1] == 'x') && (cmd_str[2] == 'e')){
  const static int xe[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}; 
  if (pgm_read_byte(&xe[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'x') && (cmd_str[2] == 'f')){
  const static int xf[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}; 
  if (pgm_read_byte(&xf[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == '1')){
  const static int y1[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&y1[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == '2')){
  const static int y2[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&y2[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == '3')){
  const static int y3[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&y3[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == '4')){
  const static int y4[48] PROGMEM = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&y4[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == '5')){
  const static int y5[48] PROGMEM = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&y5[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == '6')){
  const static int y6[48] PROGMEM = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&y6[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == '7')){
  const static int y7[48] PROGMEM = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&y7[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == '8')){
  const static int y8[48] PROGMEM = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}; 
  if (pgm_read_byte(&y8[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == '9')){
  const static int y9[48] PROGMEM = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}; 
  if (pgm_read_byte(&y9[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == 'a')){
  const static int ya[48] PROGMEM = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}; 
  if (pgm_read_byte(&ya[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == 'b')){
  const static int yb[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}; 
  if (pgm_read_byte(&yb[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == 'c')){
  const static int yc[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}; 
  if (pgm_read_byte(&yc[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == 'd')){
  const static int yd[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&yd[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == 'e')){
  const static int ye[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&ye[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'y') && (cmd_str[2] == 'f')){
  const static int yf[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&yf[address_int-1]) == 1){return 1;}
  } 
    
// misc alt
if ((cmd_str[1] == 'm') && (cmd_str[2] == '1')){
  const static int m1[48] PROGMEM = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
                                     0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
                                     1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
                                     0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}; 
  if (pgm_read_byte(&m1[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'm') && (cmd_str[2] == '2')){
  const static int m2[48] PROGMEM = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 
                                     1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
                                     0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 
                                     1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0}; 
  if (pgm_read_byte(&m2[address_int-1]) == 1){return 1;}
  } 
// misc box
if ((cmd_str[1] == 'm') && (cmd_str[2] == '3')){
  const static int m3[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                     1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&m3[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'm') && (cmd_str[2] == '4')){
  const static int m4[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&m4[address_int-1]) == 1){return 1;}
  } 

// misc rain down  1-9 e = 5, j = 10, o = 15, q = 17 (for total 26)
if ((cmd_str[1] == 'n') && (cmd_str[2] == '1')){
  const static int n1[48] PROGMEM = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&n1[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'n') && (cmd_str[2] == '2')){
  const static int n2[48] PROGMEM = {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&n2[address_int-1]) == 1){return 1;}
  }     
if ((cmd_str[1] == 'n') && (cmd_str[2] == '3')){
  const static int n3[48] PROGMEM = {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&n3[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == '4')){
  const static int n4[48] PROGMEM = {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&n4[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == '5')){
  const static int n5[48] PROGMEM = {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&n5[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == '6')){
  const static int n6[48] PROGMEM = {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&n6[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == '7')){
  const static int n7[48] PROGMEM = {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&n7[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == '8')){
  const static int n8[48] PROGMEM = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&n8[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == '9')){
  const static int n9[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&n9[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'a')){
  const static int na[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&na[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'b')){
  const static int nb[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&nb[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'c')){
  const static int nc[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&nc[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'd')){
  const static int nd[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&nd[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'e')){
  const static int ne[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&ne[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'f')){
  const static int nf[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&nf[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'g')){
  const static int ng[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
                                     1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&ng[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'h')){
  const static int nh[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&nh[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'i')){
  const static int ni[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&ni[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'j')){
  const static int nj[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 
                                     0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&nj[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'k')){
  const static int nk[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 
                                     1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&nk[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'l')){  // lowercase L
  const static int nl[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 
                                     1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1}; 
  if (pgm_read_byte(&nl[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'm')){
  const static int nm[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 
                                     1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1}; 
  if (pgm_read_byte(&nm[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'n')){
  const static int nn[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 
                                     1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1}; 
  if (pgm_read_byte(&nn[address_int-1]) == 1){return 1;}
  }

if ((cmd_str[1] == 'n') && (cmd_str[2] == 'o')){
  const static int no[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1}; 
  if (pgm_read_byte(&no[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'p')){
  const static int np[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1}; 
  if (pgm_read_byte(&np[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'n') && (cmd_str[2] == 'q')){
  const static int nq[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&nq[address_int-1]) == 1){return 1;}
  }

// misc build up  1-9 e = 5, j = 10, o = 15, q = 17 (for total 26)
if ((cmd_str[1] == 'o') && (cmd_str[2] == '1')){
  const static int o1[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&o1[address_int-1]) == 1){return 1;}
  } 
if ((cmd_str[1] == 'o') && (cmd_str[2] == '2')){
  const static int o2[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&o2[address_int-1]) == 1){return 1;}
  }     
if ((cmd_str[1] == 'o') && (cmd_str[2] == '3')){
  const static int o3[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}; 
  if (pgm_read_byte(&o3[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == '4')){
  const static int o4[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}; 
  if (pgm_read_byte(&o4[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == '5')){
  const static int o5[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}; 
  if (pgm_read_byte(&o5[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == '6')){
  const static int o6[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}; 
  if (pgm_read_byte(&o6[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == '7')){
  const static int o7[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}; 
  if (pgm_read_byte(&o7[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == '8')){
  const static int o8[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}; 
  if (pgm_read_byte(&o8[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == '9')){
  const static int o9[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}; 
  if (pgm_read_byte(&o9[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'a')){
  const static int oa[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}; 
  if (pgm_read_byte(&oa[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'b')){
  const static int ob[48] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}; 
  if (pgm_read_byte(&ob[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'c')){
  const static int oc[48] PROGMEM = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}; 
  if (pgm_read_byte(&oc[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'd')){
  const static int od[48] PROGMEM = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}; 
  if (pgm_read_byte(&od[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'e')){
  const static int oe[48] PROGMEM = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}; 
  if (pgm_read_byte(&oe[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'f')){
  const static int of[48] PROGMEM = {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}; 
  if (pgm_read_byte(&of[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'g')){
  const static int og[48] PROGMEM = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}; 
  if (pgm_read_byte(&og[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'h')){
  const static int oh[48] PROGMEM = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&oh[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'i')){
  const static int oi[48] PROGMEM = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&oi[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'j')){
  const static int oj[48] PROGMEM = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&oj[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'k')){
  const static int ok[48] PROGMEM = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&ok[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'l')){  // lowercase L
  const static int ol[48] PROGMEM = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&ol[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'm')){
  const static int om[48] PROGMEM = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&om[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'n')){
  const static int on[48] PROGMEM = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&on[address_int-1]) == 1){return 1;}
  }

if ((cmd_str[1] == 'o') && (cmd_str[2] == 'o')){
  const static int oo[48] PROGMEM = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&oo[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'p')){
  const static int op[48] PROGMEM = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&op[address_int-1]) == 1){return 1;}
  }
if ((cmd_str[1] == 'o') && (cmd_str[2] == 'q')){
  const static int oq[48] PROGMEM = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
  if (pgm_read_byte(&oq[address_int-1]) == 1){return 1;}
  }

return 0; // return 0 if command not found
}
