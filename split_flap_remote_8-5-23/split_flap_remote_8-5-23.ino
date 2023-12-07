/*
Program for remote boards installed on Solari split flap DIN-6 connector

[[
improvements to consider
add commands 28 and 29 to turn off/on each led
consider upping baud rate from 9600
add check for motor advance in every flapAdvance 
  and log and report errors (without stopping motor)
add 41 for 40 advance without motor advance checking (which stops motor if error) 
  and 42 for 80 advance without motor advance checking
  then keep 40 to still advance 40 with motor test
add command 13 to set remote index position to restore 
  remote position when relay power restored
]]

Pinouts

Atmega328P  

  gLedPin!      15  PB1 (9)         PB0 (8) 14  
  rLedPin!      16  PB2 (10)        PD7 (7) 13  driveEnablePin
  MOSI (ICSP4)  17  PB3 (11)        PD6 (6) 12  drive2Pin  
  MISO (ICSP1)  18  PB4 (12)        PD5 (5) 11  drive1Pin
  SCK (ICSP3)   19  PB5 (13)          XTAL2 10  XTAL2
  +5 (ICSP2)    20  VCC +5            XTAL1  9  XTAL1
                21  AREF                GND  8  GND
  (ICSP6)       22  GND                 VCC  7  +5
  readPin!     23  A0 (14)           PD4 (4) 6  requestPin!
  flapEnablePin 24  A1 (15)          PD3 (3) 5  dePin
  homeEnablePin 25  A2 (16)          PD2 (2) 4  rePin!
                26  A3 (17)          TX  (1) 3  TX (DI)
                27  A4 (18)          RX  (0) 2  RX (RO)
                28  A5 (19)           RESET  1  reset! (ICSP5) 

    readPin tied to DIN 3
    readPin has 328P internal 10k pullup  
    flapEnablePin tied to DIN 6
    homeEnablePin tied to DIN 4
    gLedPin is active low and connected to green led connected to 510 ohm 
      resistor to +5
    rLedPin is active low and connected to red led connected to 3k ohm 
      resistor to +5
    green is flap index indicator and status
    red is home index indicator
    dePin has 10k pulldown to ground (needed to program through icsp and 
      to save bus)
    roPin has 10k pullup to +5 (needed to program through icsp)
    RESET tied to +5 with 10k resistor
    XTAL each have cap to ground

L293D driver (D version has internal clamp diodes)

   requestPin!1  9  ENABLE 2        VS   8  +15
           GND  10  INPUT 3    INPUT 2   7  drive2Pin
      Request!  11  OUTPUT 3  OUTPUT 2   6  DIN Pin 2
           GND  12  GND            GND   5  GND
           GND  13  GND            GND   4  GND
                14  OUTPUT 4  OUTPUT 1   3  DIN Pin 1 
           GND  15  INPUT 4    INPUT 1   2  drive1Pin
           +5   16  VSS       ENABLE 1   1  driveEnablePin

MAX487 Transceiver

            GND  5  GND              DI  4  TX
              A  2  A                DE  3  dePin
              B  7  B               RE!  2  rePin!
             +5  8  VCC              RO  1  RX

    120 ohm resistor between A and B at source and on last remote
    (note - not being used at present.  Does not appear needed)
    As noted above, 10k pullup/pulldown needed on RE! and DE

6 pin ICSP (with 328P pins)

                 GND 6           5  RESET! (1) 
           MOSI (17) 4           3  SCK (19)
                  +5 2           1  MISO (18)
    
20 pin connection

                +15  20          19  +15
                +15  18          17  +15
                +15  16          15  +15
                     14          13 
                GND  12          11  GND
                GND  10           9  GND
                GND   8           7  GND
                      6           5   
                  B   4           3  A  
           Request!   2           1  Reset!

    looking at ribbon connector holes tab up
    pin 1 upper left
              ____
      ________    _______
      
      1 0 0 0 0 0 0 0 0 0
      2 0 0 0 0 0 0 0 0 0
      ___________________
   
    looking at board socket pins tab space down
    pin 1 lower left
      ___________________
      
      2 . . . . . . . . .
      1 . . . . . . . . .
      _______    ________
   
  
  DIN 6 Connector

                      6  flapEnablePin
                      5  GND
                      4  homeEnablePin
                      3  readPin!
                      2  Motor  L293 pin 6
                      1  Motor  L293 pin 3

    Note - +5 into pin 3 instead of pin 4 causes the internal Hall sensor to 
    output an index on pin 6 once for each flap position.  Possible to switch 
    between the two or use both on an "or" basis.

Commands
0L letter
10 reset
11 test set request (active low)
12 test clear request (active high)
20 set gLed function to power
21 set gLed function to index
22 set rLed function to home
23 set rLed function to home and index
24 increase drive time by 5ms (default 75ms)
25 reduce drive time by 5ms
26 increase pause time by 5ms (default 50ms)
27 reduce pause time by 5ms
3x... increment by 10, 1, 2, etc
40 conduct motor test - 40 advanes, unless earlier error 
60 rpt position, home, index, error (ok, me)  01-?,0,1,ok  
61 rpt version of code
62 rpt length test - send back 01 - a...z

Note - rpt string length test max with controller 30 ms wait 
  at 9600 baud is 29 char including \n
Note - motor test stops advancing if there is an error.

addresses
address 00 is for all non-time split flaps to follow 
  with non-reporting command types 0x, 1x, 2x, 3x and 40
addresses 01-89 are for std split flaps
address 91, 92 and 93, 94, etc are for time - hours, minutes
*/
  
char address_str[4] = "48"; 
// note - str functions do not work with const char
char version_str[32] = "V.080523";

#include<avr/wdt.h>

// for L293
int drive1Pin = 5;
int drive2Pin = 6;
int driveEnablePin = 7;
int requestPin = 4; // active high - pulls the Request! line low

// For split flap index
int readPin = 14; // note - A0 pin with internal pullup - active low
int flapEnablePin = 15; // note - A1 pin - when high, readPin low every other 
                        //   flap position (inc home)
int homeEnablePin = 16; // note - A2 pin - when high, readPin low at home

// for Max487 transceiver
int rePin = 2; // - active low
int dePin = 3; // - active high

// for LEDs
int gLedPin = 9; // connection indicator - active low
int rLedPin = 10; // home indicator - active low
int gLedFunction = 0; // 0 for power, 1 of index indicator
int rLedFunction = 0; // 0 for home indicator, 1 for both home and index

bool homeFound = false;  // used to indicating home not found after reset
int driveTime = 75; // need 50ms min to drive properly - 65ms works well too
int pauseTime = 50; // need 50ms min
 
// motor works by inverting polarity each cycle
// LOW is 0, HIGH is anything other than 0, such as 1
// prior to advance, update indexState
// motor will advance when motorState is not the same as indexState
int motorState; 
int homeState; 
int indexState;

char cmd_str[128] = ""; // a string to hold incoming data
int cmd_str_length = 0;
bool cmd_complete = false; // whether the command is complete
bool cmd_entry = false; //  whether reading a comamnd

char flipCharsDisplay_str[128] = " 1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ-./";
char flipChars_str[128] = " 1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ-./abcdefghijklmnopqrstuvwxyz";
int flipToIdx = 0;
int flipAtIdx = 0;
int charToIdx = 0;  // used for character look up
const int charLookup[] = { // look-up table for flap position and characters
0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
30, 31, 32, 33, 34, 35, 36, 37, 38, 39,  // first 40 characters
11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
31, 32, 33, 34, 35, 36};  // lower case letters

// set characher to '?' since home has not been found
char currentCharacter_str[4] = "?"; // with single character, [1] is always '\0'

char transmit_str[128] = "";

// for motor monitoring
int mCurrentIndex;
int mPriorIndex;
int mIndexCount; // not used yet 
int mIndexError; // not used yet
int mHomeError; // not used yet

void setup()
{
//wdt_disable(); //Disable WDT to prevent issues on code uploading
wdt_enable(WDTO_2S); //Enable WDT with a timeout of 2 seconds
// wdt_disable did not work properly and allowed the wdt to reset 
//   after 16ms before completing setup 
// may be an issue with the various fuse settings in the chips purchased.
// uploading bootloader to the chips sets the fuses, but these settings 
//   not easily read and currently unknown (future project perhaps).

// configure serial transceiver MAX487
// immediately set to avoid bus conflicts
// de is active high with external 10k pull-down to ground
// re is active low with external 10k pull-up to +5
// these resistors keep these disabled on power startup
pinMode(dePin, OUTPUT);  
digitalWrite(dePin, LOW); // turn transmit off - active high    
pinMode(rePin, OUTPUT);
digitalWrite(rePin, LOW); // turn receive on at startup - active low

// for L293D bridge driver
pinMode(driveEnablePin, OUTPUT);
digitalWrite(driveEnablePin, LOW);  // turn drives off at startup
pinMode(drive1Pin, OUTPUT);
pinMode(drive2Pin, OUTPUT);
pinMode(requestPin, OUTPUT);
digitalWrite(requestPin, LOW);  // turn Request! off at startup

Serial.begin(9600); // open the serial port at 9600 bps
// note - input needs to terminated with '/n' only
// while (!Serial){};  // wait for serial port to connect. Needed for native USB port only
delay(200);  ;; // consider delay length in light of use of power on relay
// select index to use - flap or home
// if both enabled, then they will "or" results on readPin
// select only home on startup
pinMode(readPin, INPUT_PULLUP); // active low
pinMode(flapEnablePin, OUTPUT);
digitalWrite(flapEnablePin, LOW); // active high
pinMode(homeEnablePin, OUTPUT);
digitalWrite(homeEnablePin, HIGH); // active high

// for LEDs
pinMode(gLedPin, OUTPUT); // active low
pinMode(rLedPin, OUTPUT); // active low
digitalWrite(gLedPin, LOW); // green power or flap index indicator and status
digitalWrite(rLedPin, HIGH); // red is home index indicator or home and index indicator

updateHomeIndexStates();  // get initial states

wdt_reset(); // reset wdt at end of set-up
}

void loop()
{
// wait for command
// note - serialEvent() is automatically called after each loop
// and per Arduino Reference, only works with some boards e.g. UNO/Atmega328
wdt_reset(); // reset wdt
if (cmd_complete) 
  {
  if (strlen(cmd_str) <= 6)  // check errant stings - max 6 letters
    {
    
  // check single remote address
    if ((cmd_str[1] == address_str[0]) && (cmd_str[2] == address_str[1]))
      {
      // 0L letter command
      if (cmd_str[3] == '0')
        {
        gLedFlash();
        letterCommand();
        }
      // 10 - reset command
      if ((cmd_str[3] == '1') && (cmd_str[4] == '0'))
        { 
        gLedFlash();
        while(1); // watchdog timer should get triggered here - cleanest way to reset
        }
      // 11 - turn on Request! command
      if ((cmd_str[3] == '1') && (cmd_str[4] == '1'))
        { 
        digitalWrite(requestPin, HIGH); // active high
        gLedFlash();
        }
      // 12 - turn off Request! command
      if ((cmd_str[3] == '1') && (cmd_str[4] == '2'))   
        { 
        digitalWrite(requestPin, LOW); // active high
        gLedFlash();
        }
      // 20 - set gLed for power
      if ((cmd_str[3] == '2') && (cmd_str[4] == '0'))   
        { 
        gLedFunction = 0;
        updateHomeIndexStates();
        digitalWrite(gLedPin, LOW); // turn on green led
        gLedFlash();
        }
      // 21- set gLed for index
      if ((cmd_str[3] == '2') && (cmd_str[4] == '1'))   
        { 
        gLedFunction = 1;
        updateHomeIndexStates();
        gLedFlash();
        }
      // 22 - set rLed for home
      if ((cmd_str[3] == '2') && (cmd_str[4] == '2'))   
        { 
        rLedFunction = 0;
        updateHomeIndexStates();
        gLedFlash();
        }
      // 23 - set rLed for index and home 
      if ((cmd_str[3] == '2') && (cmd_str[4] == '3'))   
        { 
        rLedFunction = 1;
        updateHomeIndexStates();
        gLedFlash();
        }
      // 24 - increase drive time by 5 ms - 75 ms is default
      if ((cmd_str[3] == '2') && (cmd_str[4] == '4'))   
        { 
        driveTime = driveTime + 5;
        gLedFlash();
        }
      // 25 - reduce drive time by 5 ms - note 55 ms appears to be the minimum
      if ((cmd_str[3] == '2') && (cmd_str[4] == '5'))   
        { 
        driveTime = driveTime - 5;
        gLedFlash();
        }
      // 26 - increase pause time by 5 ms - 50ms is default
      if ((cmd_str[3] == '2') && (cmd_str[4] == '6'))   
        { 
        pauseTime = pauseTime + 5;
        gLedFlash();
        }
      // 27 - reduce pause time by 5 ms - note 45 appears to be the minimum
      if ((cmd_str[3] == '2') && (cmd_str[4] == '7'))   
        { 
        pauseTime = pauseTime - 5;
        gLedFlash();
        }
      // 30 to 39 - flapAdvance one flap
      if ((cmd_str[3] == '3'))   
        {
        gLedFlash();
        int k = cmd_str[4] - '0';  // convert to integer
        if (k > 9 || k < 0) {k = 1;} // boundary check
        if (k == 0) {k = 10;}  // boundary condition
        for (int j = 1; j <= k; j++){
          flapAdvance(1); //one flap
          }
        }
      // 40 - motor test 
      if ((cmd_str[3] == '4') && (cmd_str[4] == '0'))   
        { 
        gLedFlash();
        mTest();
        }
      // 60 - report position, home, index and motor error
      if ((cmd_str[3] == '6') && (cmd_str[4] == '0'))
        {
        updateHomeIndexStates(); // update current home and index positions
        strcpy(transmit_str, address_str);
        strcat(transmit_str, " - ");
        strcat(transmit_str, currentCharacter_str); 
        if (homeState == LOW) {strcat(transmit_str, ", 1");}
        else {strcat(transmit_str, ", 0");}
        if (indexState == LOW) {strcat(transmit_str, ", 1");}
        else {strcat(transmit_str, ", 0");}
        if (mIndexError == 1) {strcat(transmit_str, ", me");}
        else {strcat(transmit_str, ", ok");}
        strcat(transmit_str, "\n");
        transmitBack();
        gLedFlash();
        }
      // 61 - report version of code
      if ((cmd_str[3] == '6') && (cmd_str[4] == '1'))
        {
        strcpy(transmit_str, address_str);
        strcat(transmit_str, " - ");
        strcat(transmit_str, version_str);
        strcat(transmit_str, "\n");
        transmitBack();
        gLedFlash();
        }
      // 62 - length test
      if ((cmd_str[3] == '6') && (cmd_str[4] == '2'))
        {
        strcpy(transmit_str, address_str);
        strcat(transmit_str, " - ");
        strcat(transmit_str, "abcdefghijklmnopqrstuvwxyz");
        strcat(transmit_str, "\n");
        transmitBack();
        gLedFlash(); 
        }     
    }
    // end of command single address if statements
    
  // check if address for "all remotes" commands - "00"
  // exclude clocks at address 9x
    if ((cmd_str[1] == '0') && (cmd_str[2] == '0') && (address_str[0] != '9'))
      {
      // 0L letter command
      if (cmd_str[3] == '0') // 
        {
        gLedFlash();
        letterCommand();
        }
      // 10 - reset command
      if ((cmd_str[3] == '1') && (cmd_str[4] == '0'))
        { 
        gLedFlash();
        while(1); // Watchdog timer should get triggered here - cleanest way to reset
        }
      // 11 - turn on Request! command
      if ((cmd_str[3] == '1') && (cmd_str[4] == '1'))
        { 
        digitalWrite(requestPin, HIGH); // active high
        gLedFlash();
        }
      // 12 - turn off Request! command
      if ((cmd_str[3] == '1') && (cmd_str[4] == '2'))   
        { 
        digitalWrite(requestPin, LOW); // active high
        gLedFlash();
        }
      // 20 - set gLed for power
      if ((cmd_str[3] == '2') && (cmd_str[4] == '0'))   
        { 
        gLedFunction = 0;
        updateHomeIndexStates();
        digitalWrite(gLedPin, LOW); // turn on green led
        gLedFlash();
        }
      // 21- set gLed for index
      if ((cmd_str[3] == '2') && (cmd_str[4] == '1'))   
        { 
        gLedFunction = 1;
        updateHomeIndexStates();
        gLedFlash();
        }
      // 22 - set rLed for home
      if ((cmd_str[3] == '2') && (cmd_str[4] == '2'))   
        { 
        rLedFunction = 0;
        updateHomeIndexStates();
        gLedFlash();
        }
      // 23 - set rLed for index and home 
      if ((cmd_str[3] == '2') && (cmd_str[4] == '3'))   
        { 
        rLedFunction = 1;
        updateHomeIndexStates();
        gLedFlash();
        }
      // 24 - increase drive time by 5 ms
      if ((cmd_str[3] == '2') && (cmd_str[4] == '4'))   
        { 
        driveTime = driveTime + 5;
        gLedFlash();
        }
      // 25 - reduce drive time by 5 ms
      if ((cmd_str[3] == '2') && (cmd_str[4] == '5'))   
        { 
        driveTime = driveTime - 5;
        gLedFlash();
        }
      // 26 - increase pause time by 5 ms
      if ((cmd_str[3] == '2') && (cmd_str[4] == '6'))   
        { 
        pauseTime = pauseTime + 5;
        gLedFlash();
        }
      // 27 - reduce pause time by 5 ms
      if ((cmd_str[3] == '2') && (cmd_str[4] == '7'))   
        { 
        pauseTime = pauseTime - 5;
        gLedFlash();
        }
      // 31 to 39 - flapAdvance one flap
      if ((cmd_str[3] == '3'))   
        {
        gLedFlash();
        int k = cmd_str[4] - '0';  // convert to integer
        if (k > 9 || k < 0) {k = 1;} // boundary check
        if (k == 0) {k = 10;}  // boundary condition
        for (int j = 1; j <= k; j++){
          flapAdvance(1); //one flap
          }
        }
      // 40 - motor test 
      if ((cmd_str[3] == '4') && (cmd_str[4] == '0'))   
        { 
        gLedFlash();
        mTest();
        }
      // end of "all remotes" command if statements
      }
    }
  cmd_complete = false;
  }
// end of loop function
// note - serialEvent() is automatically called after each loop
}

void letterCommand()
{
// find index for char in split flap array
char *e;
e = strchr(flipChars_str, cmd_str[4]);
charToIdx = (int)(e - flipChars_str);
if (e) // valid character found
  {
  // use table to determine flip position
  flipToIdx = charLookup[charToIdx];
  if (homeFound == false) // home not yet found so reset occurred
    {
    goHome();
    } 
  if (flipToIdx < flipAtIdx) // go home first
    {
    goHome();
    flapAdvance(flipToIdx);
    } 
  if (flipToIdx > flipAtIdx)
    {
    flapAdvance(flipToIdx-flipAtIdx);
    }
    // done flipping, set curent character
  updateHomeIndexStates(); 
  }   
}  

void mTest()
{
// mTest takes 4 seconds for 40 flaps
// initialize test
wdt_reset(); // reset wdt
mIndexError = 0;
updateHomeIndexStates();
motorState = indexState; // will advance when states are the same
mCurrentIndex = indexState;
int flap_count = 40;
// cycle until error
for (int j = 0; j < flap_count; j++){
  mPriorIndex = mCurrentIndex;
  flapAdvance(1);
  mCurrentIndex = indexState;
  if (mCurrentIndex == mPriorIndex) {
    mIndexError = 1;
    // turn on Request! command
    digitalWrite(requestPin, HIGH); // active high
    digitalWrite(gLedPin, HIGH); // acknowledge command - active low
    delay(250);
    digitalWrite(gLedPin, LOW); // active low
    rLedFlash();
    updateHomeIndexStates();
    currentCharacter_str[0] = '?';
    homeFound = false;
    return;
    }
  }
}

void transmitBack() 
{  
  // note - controller set up to wait 30 ms which allows
  //   controller to receive up to 29 characters back inclluding \n
  delay(1);  // wait for controller to release
  digitalWrite(rePin, HIGH);  // disable read
  delay(1);
  digitalWrite(dePin, HIGH);  // enable transmission     
  delay(1);
  Serial.print(transmit_str);  // changed from write - print works better with char
  // note - print has no additiona characters.  println has \r \n
  // note - must terminate only with \n
  Serial.flush(); // wait for transmission to complete
  delay(1); 
  digitalWrite(dePin, LOW);  // disable transmission  
  delay(1);
  digitalWrite(rePin, LOW);  // enable read
  strcpy(transmit_str, "");  // clear transmit str 
}

void gLedFlash()
{ 
// flash green led
if (gLedFunction == 0){ // only used if gLed set to indicate power
  digitalWrite(gLedPin, HIGH); // turn off led
  delay(250);
  digitalWrite(gLedPin, LOW); // turn on led
  }
}

void rLedFlash()
{
// flash red led
if (rLedFunction == 0){ // only use dif rLed set to indicate home
  digitalWrite(rLedPin, LOW); // turn on led
  delay(250);
  digitalWrite(rLedPin, HIGH); // turn off led
  }
}

void serialClear()  // not needed or used for now
{  // adding brackets on command format solved this issue
while(Serial.available() > 0) {
  char t = (char)Serial.read();
  }
}

void goHome()
{
// check if already at home
updateHomeIndexStates();
if (homeState == LOW){ // active low
  homeFound = true;
  flipAtIdx = 0;
  currentCharacter_str[0] = flipCharsDisplay_str[flipAtIdx];
  return;
  } 
homeFound = false;
for (int i=0; i<80; i++){ // this will cycle two times
  wdt_reset();
  flapAdvance(1);
  if (homeFound == true){ 
    // homeFound only chages above, in flipAdvance and in mTest
    return;
    }
  }
}

void flapAdvance(int flapsToDo)
{
for (int i=0; i < flapsToDo; i++)
  {
  wdt_reset();
  // prior to advance update index state
  // motor advances when motorState not equal to indexState
  updateHomeIndexStates();
  motorState = indexState; // will advance when states are the same
  // alternate motor state to advance motor
  if (motorState == LOW){
    motorState = HIGH;
    }
  else {
    motorState = LOW;
    }
  // Write Data to the L293
  digitalWrite(drive1Pin, motorState);
  digitalWrite(drive2Pin, !motorState);
  digitalWrite(driveEnablePin, HIGH);
  delay(driveTime);
  digitalWrite(driveEnablePin, LOW);
  delay(pauseTime);
  // update flipAtIdx
  updateHomeIndexStates();
  // check if at home found after flap
  if (homeState == LOW){ // active low
    homeFound = true;
    flipAtIdx = 0;
    currentCharacter_str[0] = flipCharsDisplay_str[flipAtIdx];
    }
  else {
    if (homeFound == true){
      flipAtIdx++;
      currentCharacter_str[0] = flipCharsDisplay_str[flipAtIdx];
      }
    else{  // if home not yet found, set char to ?
      currentCharacter_str[0] = '?';
      }
    }
  }
}

void updateHomeIndexStates()
{
// Read home and index states
// select index to use
// If both enabled, then they will "or" results on readPin
// read home first
digitalWrite(flapEnablePin, LOW); // active high
digitalWrite(homeEnablePin, HIGH); // active high
delay(1);
homeState = digitalRead(readPin); // active low
//then read flap state
digitalWrite(homeEnablePin, LOW); // active high
digitalWrite(flapEnablePin, HIGH); // active high
delay(1);
indexState = digitalRead(readPin); // active low
// set leds
if (gLedFunction == 0){ // i.e. used for power, not index display
  digitalWrite(gLedPin, LOW); // turn on green LED
  }
if (rLedFunction == 0){
  if (homeState == LOW){
    digitalWrite(rLedPin, LOW); // turn on red LED
    }
    else {
      digitalWrite(rLedPin, HIGH);
      }
  }    
if (gLedFunction == 1){
  if (indexState == LOW){ // i.e. used for index display
    digitalWrite(gLedPin, LOW); // turn on green LED
    }
    else {
      digitalWrite(gLedPin, HIGH);
      } 
  }
if (rLedFunction == 1){  // i.e. used for both home and index display
  if((homeState == LOW || indexState == LOW)){
    digitalWrite(rLedPin, LOW); // turn on red LED
    }
    else {
      digitalWrite(rLedPin, HIGH);
      }
  }
}

/*
SerialEvent occurs whenever a new data comes in the
hardware serial RX. This routine is run each
time loop() runs, so using delay inside loop can delay
response. Multiple bytes of data may be available.
*/
void serialEvent() 
{
  while (Serial.available())
  {
  // get the new byte:
  char data = (char)Serial.read();
  // check if command sent - begins with a '['
  if (data == '[') 
    {
    strcpy(cmd_str, ""); // clear command  
    cmd_entry = true;
    cmd_str_length = 0;
    }
  // check if command over - ends with a ']'
  if (cmd_entry == true && data == ']') 
    {
    cmd_entry = false;
    // format cmd_str
    cmd_str[cmd_str_length] = data;
    cmd_str[cmd_str_length + 1] = '\0';
    cmd_complete = true;  // format should be "[aadd]\0"
    }
  if (cmd_entry == true)
    {
    cmd_str[cmd_str_length] = data;
    cmd_str_length++;
    }
  // for testing on Serial monitor
  //Serial.print(data);
  //Serial.print("   ");
  //Serial.print(cmd_str_length);
  //Serial.print("   ");
  //Serial.println(cmd_complete);
  }
}
