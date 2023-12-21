/*
// to dos
clean up code - test questionable parts too?
decrease delay between letters for faster pages?>
add indent hyphen 2d part one space?
add no hyphen accross pages
add motionenable flag? add to eeprom too? oe just unplug motion sensor?
add remote commands for colums and rows cnxx, cnxx??
//

This sketch uses an Arduino MKR1010 and Bylnk program to control the 
remote split flap controllers.

Controllers have numbered addresses from 01-99.
00 is used to address all remote controllers at the same time.

Command structure for remotes is:
  device address 01-99, command type y, command z, end \n
  xxyz\n
  xx is address 01-99, 00 is for all addresses
  y is 0 for letter commands
  z letters 0-9, A-Z, a-z -./" "
  y is 1 to 9 for other commands
  91 and 92, 93 and 94 are for clocks

Command sutructure for mkr1010 is through Blynk terminal input.  
,aaaa for "aaaa" string to be output (e.g. " flap this...").
Also has remote pass through commands if command starts with a number
(e.g. "0105" or "011s").

MKR1010
    
     Yellow LED 15  6                     5 14  
            RE! 16  7                     4 13  
             DE 17  8                     3 12  
      resetPin! 18  9                     2 11  
    requestPin! 19  10                    1 10 fan
       see note 20  11                     0 9 relay
       see note 21  12                    A6 8 
             RX 22  13 RX                 A5 7 thermistor
             TX 23  14 TX                 A4 6 motion
                24  RESET                 A3 5 switchLed!
            GND 25  GND                   A2 4 blueLed!
                26  VCC                   A1 3 greenLed!
                27  VIN                   A0 2 redLed!
             +5 28  5v                  AREF 1 

    Note - RE! on 11 had an unknown issue that caused Blynk not to start.
    11 and 12 (SDA and SCL) have external series and pull up resistors to 3.3V
    these appear to be dedicated i2c lines connected to the mkr power module

    redLed! connected to red led, then 3k resistor then 3.3V
    greenLed! connected to green led, then 510 resistor then 3.3V
    blueLed! connected to blue led, then 3k resistor then 3.3V
    switchLed! connected to switch led pin then 5V
    thermistor connected between to 10k ntc thermistor (to gnd )
      and 10k resistor (to 3.3V). 
    motion connected to output of a three pin motion sensor 
      that is powered by 3.3V
    relay connected to TIP120 base with 10k resistor with
      TIP120 collector connected to relay coil then to 15V with 
      protection diode IIN4007 between TIP120 collector and 15V
    fan connected to TIP120 base with 10k resistor with 
      TIP120 collector connected to 220 resistor then 
      to fan then to 15V (voltage to fan approx 7.5V)
    
  TXS0108E directionless voltage level translator
    
      resetPin!(active low), requestPin!(active low input), RE!(active low), 
      DE, RO, DI (input) all travel through a 
      3.3V to 5V bidirectional level shifter
    
                                     MKR inputs 
    
           GND  11  GND              OE! 10  +3.3 
                12  B8               A8  9  
                13  B7               A7  8  
   requestPin!  14  B6               A6  7  requestPin!
     resetPin!  15  B5               A5  6  resetPin!
         dePin  16  B4               A4  5  dePin
        rePin!  17  B3               A3  4  rePin!
            RX  18  B2               A2  3  RX
            TX  19  B1               A1  2  TX
            +5  10  VB               VA  1  +3.3
     
MAX487 Serial Bus Transceiver

            GND  5  GND              DI  4  TX
              A  2  A                DE  3  dePin
              B  7  B               RE!  2  rePin!
             +5  8  VCC              RO  1  RX

    120 ohm resistor between A and B
    10k pullup on RE! and 10k pulldown on DE.
  
74HC125

  resestPin! output and Request! input is buffered through a 74HC125 buffer driver
    
                 8  3Y               GND 7  GND
                 9  3A               2Y  6  requestPin!
                10  3OE!             2A  5  Request! (CN1 pin2)
                11  4Y              2OE! 4  GND
                12  4A               1Y  3  Reset! (CN1 pin1)
                13  4OE!             1A  2  resetPin!
            +5  14  VCC            1OE!  1  GND

    1k pullup between Request! and +5

20 pin connection (CN1)

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

    Note - have not added 120 ohm output resistor between A and B.
    
LM7805 
  
  Provides 5V from the 15V.
  0.33uF on input and 0.1uF on output.

  Power draw when programming through USB measures 160-200 200 ma.

MAX478 timing
    MKR starts as a transmitter at 9600 (may increase to 19200 at least)
    Remotes start as receivers
    When a remote receives a transmission command, remote has 25ms to transmit
    Remote must then move back to receive mode
    MKR returns to transmit mode after 25ms
    Note - multiple transmitters can damage the MAX487

  if (strcmp(cmd_str, "cmd") == 0) { // list commands
    terminal.println(",__   - display letter string"); 
    terminal.println(";__   - display letter string split"); 
    terminal.println("@     - list phrases"); 
    terminal.println("@nn   - display phrase nn"); 
    terminal.println("+     - increment all by one");
    terminal.println("aacc  - remote command");
    terminal.println("lrc   - list remote commands");
    terminal.println("arst  - hard reset for all devices");
    terminal.println("rst   - reset controller");
    terminal.println("sig   - report WiFi signal strength"); 
    terminal.println("v     - report version of code");
    terminal.println("rpt   - report all remotes");
    terminal.println("rptv  - report all remote versions");
    terminal.println("rtc   - report rtc time");
    terminal.println("c     - Blynk terminal clear");
    terminal.println("clr   - local terminal clear");
    terminal.println("cmd   - list available commands");
    terminal.println("cmdm  - list more commands");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "lrc") == 0) { // list remote commands
    terminal.println("0L letter");
    terminal.println("10 reset");
    terminal.println("11 test set request (active low)");
    terminal.println("12 test clear request (active high)");
    terminal.println("20 set gLed function to power");
    terminal.println("21 set gLed function to index");
    terminal.println("22 set rLed function to home");
    terminal.println("23 set rLed function to home and index");
    terminal.println("24 increase drive time by 5ms (default 75ms)");
    terminal.println("25 reduce drive time by 5ms");
    terminal.println("26 increase pause time by 5ms (default 50ms)");
    terminal.println("27 reduce pause time by 5ms");
    terminal.println("3x... increment by 10, 1, 2, etc");
    terminal.println("40 conduct motor test - 40 advanes, unless error");
    terminal.println("60 rpt position, home, index, error");
    terminal.println("61 rpt version of code");
    terminal.println("62 rpt length test - send back 01 - a...z");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cmdm") == 0) { // list more commands
    terminal.println("mtr   - motor test and report");
    terminal.println("rtc   - report rtc time");
    terminal.println("trs   - report/syncs rtc/WiFi times");
    terminal.println("tdon  - time display on");
    terminal.println("tdoff - time display off");
    terminal.println("tdclr - clear time display");
    terminal.println("tdset - set time display");
    terminal.println("cdt   - change date and time");  // second page flag 1
    terminal.println("rms   - report motion state (15s)");
    terminal.println("rth   - report thermistor value");
    terminal.println("cat  -  cancel active time");
    terminal.println("stat  - report op status");
    terminal.println("rst   - reset controller");
    terminal.println("cssid - change Wifi SSID");  // second page flag 2
    terminal.println("cpass - change Wifi password");   // second page flag 3
    terminal.println("cgmto - change GMT offset");  // second page flag 4
    terminal.println("csthr - change enable start hour");  // second page flag 5
    terminal.println("cenhr - change enable end hour");  // second page flag 6
    terminal.println("cactm - change active time(minutes)");  // second page flag 7
    terminal.println("crpf  - change random phrase flag");  // second page flag 8
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
*/

// comment out line for different deployments
//#define test 
#define production

#ifdef test
// test 
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "XXX"
#define BLYNK_TEMPLATE_NAME "Split Flap"
#define BLYNK_AUTH_TOKEN "XXX"
#define BLYNK_FIRMWARE_VERSION "1.0.1"
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[20] = "XXX";
char pass[20] = "XXX";
char k_GMT_str[20] = "-8"; //-8 for California ST and -7 for California DST
char activeTime_str[20] = "2";  // 2 minutes for testing
char enableStartHours_str[20] = "7";  // start motion function at 7 am
char enableEndHours_str[20] = "20";  // end motion function at 8 pm
char randomPhraseDisplayFlag_str[20] = "0";  // off in test
int randomPhraseDisplayFlag;
int k_GMT;
unsigned long activeTime;
int enableStartHours;
int enableEndHours;
int motionEnable = 1;

#endif

#ifdef production
// production 
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "XXX"
#define BLYNK_TEMPLATE_NAME "Split Flap"
#define BLYNK_AUTH_TOKEN "XXX"
#define BLYNK_FIRMWARE_VERSION "1.0.1"
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[20] = "XXX";
char pass[20] = "XXX";
char k_GMT_str[20] = "-8"; //-8 for California ST and -7 for California DST
char activeTime_str[20] = "10";  // 10 minutes for production
char enableStartHours_str[20] = "7";  // start motion function at 7 am
char enableEndHours_str[20] = "20";  // end motion function at 8 pm
char randomPhraseDisplayFlag_str[20] = "1";  // on in production
int randomPhraseDisplayFlag;
int k_GMT;
unsigned long activeTime;
int enableStartHours;
int enableEndHours;
int motionEnable = 1;
#endif

char version_str[32] = "V.121923";

// for eeprom emulation in mkr program memory
#define FLASH_DEBUG       0  // Use 0-2. Larger for more debugging messages
#include <FlashStorage_SAMD.h>
const int WRITTEN_SIGNATURE = 0xabcdabcd;
// eeprom data for refernece
  //char ssid[20] = "XXX";
  //char pass[20] = "XXX";
  //int k_GMT = -7; //-8 for California ST and -7 for California DST
  //unsigned long activeTime = 2;  // 2 minutes for testing
  //int enableStartHours = 7;  // start motion function at 7 am
  //int enableEndHours = 20; // end motion function at 8 pm
  //int randomPhraseDisplayFlag = 1;  / on in production
typedef struct
{
  char eeprom_ssid[20];
  char eeprom_pass[20]; 
  char eeprom_k_GMT[20];
  char eeprom_enableStartHours[20];
  char eeprom_enableEndHours[20];
  char eeprom_activeTime[20];
  char eeprom_randomPhraseDisplayFlag[20];
} Device;
// define controller as a "Device"
Device controller;
// If the EEPROM is written, then there is a written signature 
// at address 0
uint16_t storedAddress = 0;
int signature;

// for wifi, Blynk and rtc
#include <SPI.h>
#include <WiFiNINA.h> // for mkr 1010
#include <BlynkSimpleWiFiNINA.h>  // for Blynk

// for real time clock
#include <RTCZero.h>
RTCZero rtc;
//#include "arduino_secrets.h" // for putting the ssid and pwd on a separate tab
//  can enter sensitive data in the Secret tab/arduino_secrets.h
// cont char ssid = ; // network SSID (name)
// const char pass = ; // network password (use for WPA, or use as key for WEP)
//int key_index = 0; // your network key Index number (needed only for WEP)
int status = WL_IDLE_STATUS;
unsigned long epoch = 0;

long rssi;
char rssi_str[16];

// for date and time functions
char seconds_str[8];
int seconds_int;
char minutes_str[8];
int minutes_int;
char hours_str[8];
int hours_int;
char days_str[8];
int days_int;
char months_str[8];
int months_int;
char years_str[8];
int years_int;
char date_str[16]; // date string
char time_str[16]; // time string
int prior_days_int = 0;

// for error logging and resets
char error_type_str[32];
char error_type_display_str[32];
// set the reset flag on error and clear the reset flag when restarting
int mkr_reset_flag_int = 0;

// for watch dog timer
// Note - for below, must delete lines 58 to 66 of WDTZero.cpp 
// to avoid clock configuation conflict with RTCZero that 
// uses external crystal for accuracy, not internal oscillator
#include <WDTZero.h>  
WDTZero WDTimer; // Define watch dog timer

//for Blynk
// BlynkTimer timer; // Do not use BlynkTimer (based on SimpleTimer) as it may have been causing resets
// led V1 is the blue LED on the phone attached to Virtual Pin 1
WidgetLED led1(V1);

// Attach virtual serial terminal to Virtual Pin V3
WidgetTerminal terminal(V3);
// for reading a second input line in the Blynk terminal
int terminal_second_line_flag_int = 0;

// for manual timers
unsigned long currentMillis;
unsigned long previousMillis_Blynk = 0;
unsigned long previousMillis_blinkLedWidget = 0; 
unsigned long previousMillis_mkrReset = 0; 
unsigned long previousMillis_updateTimeDisplay = 0;
unsigned long previousMillis_swWidget = 0; 
unsigned long previousMillis_updateLeds = 0;
unsigned long previousMillis_updateFan = 0;
unsigned long previousMillis_displayActive = 0;
unsigned long previousMillis_updateMotion = 0;
unsigned long lastCommandMillis = 0;
unsigned long lastMotionMillis = 0;

// for push buttons and mkr led (if top shield used)
#include <utility/wifi_drv.h>
int value_sw0_int = 0;
int value_prior_sw0_int = 0;
int state_sw0_int = 0;
int state_prior_sw0_int = 0;

int value_sw1_int = 0;
int value_prior_sw1_int = 0;
int state_sw1_int = 0;
int state_prior_sw1_int = 0;

// for possible future syncing
// get button state and sync
//BLYNK_CONNECTED() {
  //Blynk.syncVirtual(v0)
//}
//BLYNK_WRITE(V0) {
 // value_sw0_int = param.asInt();
//}

// for notifications
char notification_str[256]; 

// for Max487 transceiver
int rePin = 7; // - active low
int dePin = 8; // - active high

// for USB Serial commands
char cmd_str[640];
int cmd_length_int = 0;
int cmd_flag_int = 0;
int serial_second_line_flag_int = 0;

// for remote Serial1 commands
char remote_command_str[128] = "";
char remote_transmission_str[128] = "";
int remote_trans_length_int = 0;
// int remote_trans_complete = 0; // whether the string is complete // not used
unsigned long serialStartMillis;

int resetPin = 9; // active low (D9)
int requestPin = 10;  // active low (D10)

// for splitflap display commands
int currentDisplayHours_int = 999; // will cause time to be set
int currentDisplayMinutes_int = 999;
//char flipCharsDisplay_str[128] = " 1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ-./"; // for reference normal characters
char flipCharsHoursDisplay_str[128] = "U1234567890ABCDEFGHIJKLM";  // U is 0 - time characters
char flipCharsMinutesDisplay_str[128] = " 601A2B3C4D5E";  // 6 is 0, E is 55 - time characters
char hours_address_str[4] = "91";
char minutes_address_str[4] = "92";
char currentCharacter_str[4] = "?"; // with single character, [1] is always '\0'
int timeDisplayFlag = 1;  // default is time display is on
// command in last 5 minutes or motion on last 5 minutes
int displayActiveFlag = 1; 
int phrase_num_old = 0; // to avoid random repeating of phrases

// for leds
// configure leds
// led state 0-off, 1-on, 2-blinking(1s)
int redLedPin = A0; // active low (D15)
int redLedState;
int greenLedPin = A1;  // active low (D16)
int greenLedState;
int blueLedPin = A2;  // active low (D17)
int blueLedState;
int switchLedPin = A3;  // active low (D18)
int switchLedState;

// for thermistor, motion, relay and fan controls
// configure led, thermistor, motion, relay and fan controls
int motionPin = A4; // active high (D19)
int motionState; // state 0-off, 1-on
int prior_motionState;
int thermistorPin = A5; 
int thermistorValue; // 0-4096 - 12 bit
int thermistorTemp;
int rthFlag = 0; // for terminal print out thermistor values 
int relayPin = 0; // active high (D0)
int relayState; // state 0-off, 1-on
int prior_relayState;
int fanPin = 1; // active high (D1)
int fanState; // state 0-off, 1-on
int prior_fanState;

// for display dimensions
//int rowLength[8] = {12, 12, 12, 12, 0, 0, 0, 0};
// above is start to allow you to have variable row lengths
int row_length = 12; 
//int row_address[8][12] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},            // row 0 
//                          {13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}};  // row 1
// above is start to allow you to reorder remote addresses
int numSplitFlaps = 48;  // note - changes based on setup - no 00 flap
char input_str[640];
char input_str2[640];
int row_display_number = 0;
char row_display_array[32][20];
char word_str[128][20];  // up to 128 words of 19 characters each with '\0'
int word_str_length[40];
int word_cnt = 0;
int row_number = 0;
char display_str[640];
int phrase_num = 0;

void setup()
{
// immediately configure serial transceiver MAX487
//   to avoid bus conflicts
// de is active high with external 10k pull-down to ground
// re is active low with external 10k pull-up to +5
// these resistors keep these off on power startup
pinMode(dePin, OUTPUT);  
digitalWrite(dePin, HIGH); // turn on at startup
delay(2);
pinMode(rePin, OUTPUT);
digitalWrite(rePin, HIGH); // turn off at startup

Serial.begin(9600); // for serial monitor
//while (!Serial) {}; // wait for serial port to connect.

// Program would not compile when code below was dropped into a function
// write eeprom data or if reset, obtain eeprom data
// Check signature at address 0
EEPROM.get(storedAddress, signature);
// If the EEPROM is written, then there is a written signature
if (signature == WRITTEN_SIGNATURE){
  EEPROM.get(storedAddress + sizeof(signature), controller);
  /*Serial.println("Returning data previsouly written");
  Serial.println(controller.eeprom_ssid); 
  Serial.println(controller.eeprom_pass); 
  Serial.println(controller.eeprom_k_GMT);
  Serial.println(controller.eeprom_enableStartHours);
  Serial.println(controller.eeprom_enableEndHours);
  Serial.println(controller.eeprom_activeTime);
  Serial.println(controller.eeprom_randomPhraseDisplayFlag);*/
  }
else { // eeprom is not written and needs to be written
  //Serial.println("EEPROM not written.  Writing data to EEPROM");
  // EPROMWrite();  // Does not work here
  EEPROM.put(storedAddress, WRITTEN_SIGNATURE);
  strcpy(controller.eeprom_ssid, ssid);
  strcpy(controller.eeprom_pass, pass);
  strcpy(controller.eeprom_k_GMT, k_GMT_str);
  strcpy(controller.eeprom_enableStartHours, enableStartHours_str);
  strcpy(controller.eeprom_enableEndHours, enableEndHours_str);
  strcpy(controller.eeprom_activeTime, activeTime_str);
  strcpy(controller.eeprom_randomPhraseDisplayFlag, randomPhraseDisplayFlag_str);
  // Save everything into EEPROM
  EEPROM.put(storedAddress + sizeof(signature), controller);
  if (!EEPROM.getCommitASAP()){
    //Serial.println("CommitASAP not set. Need commit()");
    EEPROM.commit();
    }
  }
  // in each case convert data to strings and numbers used in the program
  strcpy(ssid, controller.eeprom_ssid);
  strcpy(pass, controller.eeprom_pass);
  k_GMT = atoi(controller.eeprom_k_GMT);
  enableStartHours = atoi(controller.eeprom_enableStartHours);
  enableEndHours = atoi(controller.eeprom_enableEndHours);
  int activeTime_int = atoi(controller.eeprom_activeTime); // convert string to integer 
  activeTime = (long)activeTime_int; // and then to unsigned long
  randomPhraseDisplayFlag = atoi(controller.eeprom_randomPhraseDisplayFlag); // convert string to integer 
// for remote master reset
pinMode(resetPin, OUTPUT); // reset for all remote devices - active low
digitalWrite(resetPin, HIGH);

// for remote request pin
pinMode(requestPin, INPUT); // remote request pin without pull up - active low

//  for real time clock 
//  Note - This selects the external crystal and confiures the clock.
//  This must be in front of the wdt setup as the modified version
//  of the wdt code has the clock configuration deleted.
rtc.begin();
// for watch dog timer
// Note - Modified WDTZero header file.  16 seconds avail too.
WDTimer.setup(WDT_HARDCYCLE8S);  // initialize WDT counter refesh cycle on 8 sec
// when time runs out, processor does a hardware reset
// for serial monitor

// attempt to connect to WiFi networks :
int number_of_tries_ssid = 0;
char number_of_tries_ssid_str[4]; 
while ( status != WL_CONNECTED) {
  // update display for connection attempts
  WDTimer.clear();  // refresh watch dog timer
  number_of_tries_ssid++;
  Serial.print("Attempting to connect to SSID: ");
  Serial.print(ssid);
  Serial.print("  ");
  Serial.println(number_of_tries_ssid);
  sprintf(number_of_tries_ssid_str, "%i", number_of_tries_ssid);
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  status = WiFi.begin(ssid, pass);
  // wait 10 seconds for connection:
  WDTimer.clear();  // refresh watch dog timer
  delay(5000);
  WDTimer.clear();  // refresh watch dog timer
  delay(5000);
  }
WDTimer.clear();
// you're connected now, so print out the status on the serial port
Serial.print("SSID: ");
Serial.println(WiFi.SSID());
// print your WiFi shield's IP address:
IPAddress ip = WiFi.localIP();
Serial.print("IP Address: ");
Serial.println(ip);
// print and display the received signal strength
rssi = WiFi.RSSI();
Serial.print("Signal strength (RSSI):");
Serial.print(rssi);
Serial.println(" dBm");

// for obtaining epoch and starting rtc
int number_of_tries_NTP = 0;
do {
  WDTimer.clear();  // refresh watch dog timer
  epoch = WiFi.getTime();
  number_of_tries_NTP++;
  Serial.print("NTP tries:  ");
  Serial.println(number_of_tries_NTP);
  delay(1000);
  }
while ((epoch == 0) && (number_of_tries_NTP < 10));
if (number_of_tries_NTP >= 10) {
  strcpy(error_type_str, "NTP-0");
  mkrError();
  }
else {
  WDTimer.clear();  // refresh watch dog timer
  Serial.print("Epoch received: ");
  // print out epoch on serial port
  Serial.println(epoch);
  epoch = epoch + (k_GMT * 60 * 60);  // adjsut for GMT standard time
  rtc.setEpoch(epoch);
  Serial.println();
  }
delay(500);

// attempt to connect to Blynk
Blynk.begin(auth, ssid, pass);
// Note - Blynk.begin is blocking
WDTimer.clear();  // refresh watch dog timer
updateDate();
updateTime();
Serial.println();
Serial.print(date_str);
Serial.print("  ");
Serial.println(time_str);
Serial.println("Split Flap Controller is online.");
Serial.print(ssid);
Serial.print("  ");
rssi = WiFi.RSSI();
Serial.print(rssi);
Serial.println(" dBm");
Serial.println(); // add line feed
Serial.println("Type cmd in Blynk App for list of commands.");
Serial.println(); // add line feed
terminal.clear();
terminal.print(date_str);
terminal.print("  ");
terminal.println(time_str);
terminal.println("Split flap controller is online.");
terminal.print(ssid);
terminal.print("  ");
terminal.print(rssi);
terminal.println(" dBm");
terminal.println();  // add line feed
terminal.println("Type cmd for list of commands.");
terminal.println(); // add line feed
terminal.flush();

WDTimer.clear();  // refresh watch dog timer
Blynk.logEvent("SPC_restarted"); // log event to timeline
// create visual indicator for push buttons
WiFiDrv::pinMode(25, OUTPUT); //GREEN
WiFiDrv::pinMode(26, OUTPUT); //RED
WiFiDrv::pinMode(27, OUTPUT); //BLUE
  
pinMode(LED_BUILTIN, OUTPUT); // built in yellow LED  Note - this is controlled by pin 6
digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

// configure leds
pinMode(redLedPin, OUTPUT); // indicates motion sensor output
redLedState = 0;
digitalWrite(redLedPin, HIGH); // turn led off - active low

pinMode(greenLedPin, OUTPUT); // indicate relay on-off 
greenLedState = 1;
digitalWrite(greenLedPin, LOW); // turn led on - active low
pinMode(blueLedPin, OUTPUT);  
blueLedState = 1; // indicates if power on and wifi connected
                  // flashes when relay is off 
digitalWrite(blueLedPin, LOW); // turn led on - active low
pinMode(switchLedPin, OUTPUT);  // indicates same as blue led
switchLedState = 1;
digitalWrite(switchLedPin, LOW); // turn led on - active low

// configure thermistor, motion, relay and fan controls
pinMode(motionPin, INPUT_PULLDOWN);  // remains low or off when not connected
motionState = digitalRead(motionPin);
prior_motionState = motionState;
if (motionState == HIGH){
  redLedState = 1;
  digitalWrite(redLedPin, LOW); // turn led on - active low
  }
else{
  redLedState = 0;
  digitalWrite(redLedPin, HIGH); // turn led off - active low
  }
analogReadResolution(12); // set analog read resolution to 12 bits 0-4096
thermistorValue = analogRead(thermistorPin);   
pinMode(relayPin, OUTPUT);  
// at start turn on relay
relayOn();
// at start turn fan off
pinMode(fanPin, OUTPUT);  
fanState = 0;
prior_fanState = fanState;
digitalWrite(fanPin, LOW); // turn fan off - active high

// reset all remote devices
digitalWrite(resetPin, LOW);
delay(250);
digitalWrite(resetPin, HIGH);
delay(100);

// begin remote device serial1
Serial1.begin(9600);

// Print a confirmation of the EEPROM data
/*terminal.println("Saved Data: ");
terminal.println(controller.eeprom_ssid); 
terminal.println(controller.eeprom_pass); 
terminal.println(controller.eeprom_k_GMT);
terminal.println(controller.eeprom_enableStartHours);
terminal.println(controller.eeprom_enableEndHours);
terminal.println(controller.eeprom_activeTime);
terminal.println(controller.eeprom_randomPhraseDisplayFlag);
terminal.flush();*/

// end setup
}

void loop()
{
WDTimer.clear();  // refresh watch dog timer
// clean out Serial1 from random data on startup
// Note - need to reexamine if random data is actually a problem
serial1Clear();

currentMillis = millis();

// Check for Blynk command every 0.5 second
if (currentMillis - previousMillis_Blynk >= 500) { 
  previousMillis_Blynk = currentMillis;  // Remember the time
  Blynk.run();
  }
// Check for motion every 0.5 seconds
if (currentMillis - previousMillis_updateMotion >= 500) { 
  previousMillis_updateMotion = currentMillis;  // Remember the time
  motionState = digitalRead(motionPin);  // active high
  if (motionState == HIGH){
    redLedState = 1; // led on
    lastMotionMillis = currentMillis;  // Remember the time
    }
  else{
    redLedState = 0; // led off
    }
  if (motionState != prior_motionState){
    if (motionState == HIGH){
      terminal.println("motion detected");
      }
    else{
      terminal.println("no motion");
      }
    terminal.flush();
    Blynk.run();
    prior_motionState = motionState; 
    }
  }
// check if display active every 0.5 seconds
if (currentMillis - previousMillis_displayActive >= 500) { 
  previousMillis_displayActive = currentMillis;  // Remember the time
  // check if motion is in enabled time
  updateTime();
  if (hours_int >= enableStartHours && hours_int < enableEndHours) motionEnable = 1; 
  else motionEnable = 0;
  // check if motion in enabled time in last 5 minutes or command in last 5 minutes
  // activeTime is in minutes
  if ( ((((currentMillis - lastMotionMillis) <= (activeTime * 60000)) && (motionEnable == 1)) && (lastMotionMillis != 0)) ||
    ((currentMillis - lastCommandMillis) <= (activeTime * 60000)) ){     
    displayActiveFlag = 1;
    relayOn();
    }
  else {
    displayActiveFlag = 0;
    relayOff();
    } 
  }   
// Leds updated every 0.5 seconds
if (currentMillis - previousMillis_updateLeds >= 500) { 
  previousMillis_updateLeds = currentMillis;  // Remember the time
  updateLeds();
  }
// Time display and random phrase display updated every second
if (currentMillis - previousMillis_updateTimeDisplay >= 1000) {
  previousMillis_updateTimeDisplay = currentMillis;  // Remember the time
  // update the time display if time is turned on and display active
  if ((timeDisplayFlag == 1) && (displayActiveFlag == 1)){
    updateTimeDisplay();
    }
  if ((randomPhraseDisplayFlag == 1) && (displayActiveFlag == 1)){
    // check if new day
    days_int = rtc.getDay(); // update day
    if (prior_days_int != days_int){
      delay3s();
      // WDTimer.clear();  // refresh watch dog timer
      randomPhraseDisplay();
      prior_days_int = days_int; // only one display per day
      }
    }  
}  
// Fan updated every 5 seconds
if (currentMillis - previousMillis_updateFan >= 5000) { 
  previousMillis_updateFan = currentMillis;  // Remember the time
  updateFan();
  }
// Uptime and led toggle sent every second
if(currentMillis - previousMillis_blinkLedWidget >= 1000) {
  previousMillis_blinkLedWidget = currentMillis;  // Remember the time
  blinkLedWidget();
  Blynk.virtualWrite(V2, millis() / 60000); // send the uptime
  Blynk.run();
  }
// Error after 5 seconds
// error routine sets previousMillis_mkrReset
if((mkr_reset_flag_int == 1) && (currentMillis - previousMillis_mkrReset >= 5000)) {  
  mkrReset();
  }
}  // end of loop
  
void relayOn()
{
relayState = 1; // relay on
greenLedState = 1; // led on
digitalWrite(relayPin, HIGH); // turn relay on - active high
blueLedState = 1; // led on
switchLedState = 1; // led on
delay1s();  // add delay for relay time and remote startup time
if (relayState != prior_relayState){
  terminal.println("relay on");
  terminal.flush();
  Blynk.run();
  prior_relayState = relayState; 
  }
}
  
void relayOff()
{  
relayState = 0; // relay off
greenLedState = 0; // led off
digitalWrite(relayPin, LOW);  // active high
blueLedState = 2; // blink led
switchLedState = 2; // blink led
if (relayState != prior_relayState){
  terminal.println("relay off");
  terminal.flush();
  Blynk.run();
  prior_relayState = relayState;
  }
}

void updateFan()
{
// analog read resolution set earlier to 12 bits 0-4096
thermistorValue = analogRead(thermistorPin); // 1700 = 100deg , 1800 = 90deg, 1900 = 80deg  approx
thermistorTemp = 80 + ((1900 - thermistorValue) / 10); // approx
if (rthFlag == 1){
  terminal.print(thermistorValue); // for testing
  terminal.print("  ");
  terminal.print(thermistorTemp);
  terminal.println(" deg");
  terminal.flush();  // output to terminal immediately
  Blynk.run(); 
  }
if (thermistorValue >= 1800){
  fanOff();
  }
if (thermistorValue <= 1700){
  fanOn();
  }
if (thermistorValue <= 1650){ // if high temp, turn off relay
  relayOff();
  terminal.println("high temp - fan on and relay off");
  terminal.flush();
  Blynk.run();
  }
}

void fanOn()
{
fanState = 1;  
digitalWrite(fanPin, HIGH);  // active high
if (fanState != prior_fanState){
  terminal.println("fan on");
  terminal.flush();
  Blynk.run();
  prior_fanState = fanState; 
  } 
}

void fanOff()
{
fanState = 0;  
digitalWrite(fanPin, LOW);  // active high
if (fanState != prior_fanState){
  terminal.println("fan off");
  terminal.flush();
  Blynk.run();
  prior_fanState = fanState; 
  } 
}

void updateLeds()
{
  // red led control
  switch (redLedState)
  {
    case 0:
      // turn off led
      digitalWrite(redLedPin, HIGH); // active low
      break;
    case 1:
      // turn on led
      digitalWrite(redLedPin, LOW);
      break;
    case 2:
      // blink led
      digitalWrite(redLedPin, !digitalRead(redLedPin));
      break;
    default:
      // default - turn off led
      digitalWrite(redLedPin, HIGH);
      break; 
  } 
  // green led control
  switch (greenLedState)
  {
    case 0:
      // turn off led
      digitalWrite(greenLedPin, HIGH); // active low
      break;
    case 1:
      // turn on led
      digitalWrite(greenLedPin, LOW);
      break;
    case 2:
      // blink led
      digitalWrite(greenLedPin, !digitalRead(greenLedPin));
      break;
    default:
      // default - turn off led
      digitalWrite(greenLedPin, HIGH);
      break; 
  } 
  // blue led control
  switch (blueLedState)
  {
    case 0:
      // turn off led
      digitalWrite(blueLedPin, HIGH); // active low
      break;
    case 1:
      // turn on led
      digitalWrite(blueLedPin, LOW);
      break;
    case 2:
      // blink led
      digitalWrite(blueLedPin, !digitalRead(blueLedPin));
      break;
    default:
      // default - turn off led
      digitalWrite(blueLedPin, HIGH);
      break; 
  } 
  // switch led control
  switch (switchLedState)
  {
    case 0:
      // turn off led
      digitalWrite(switchLedPin, HIGH); // active low
      break;
    case 1:
      // turn on led
      digitalWrite(switchLedPin, LOW);
      break;
    case 2:
      // blink led
      digitalWrite(switchLedPin, !digitalRead(switchLedPin));
      break;
    default:
      // default - turn off led
      digitalWrite(switchLedPin, HIGH);
      break; 
  } 
}

void updateRTC()
{
// get epoch and update RTC
int number_of_tries_NTP = 0;
do {
  epoch = WiFi.getTime();
  number_of_tries_NTP++;
  delay500ms();
  }
while ((epoch == 0) && (number_of_tries_NTP < 6));
  if (number_of_tries_NTP >= 6) {
    strcpy(error_type_str, "NTP-1");
    mkrError();
    }
  else {
    epoch = epoch + (k_GMT * 60 * 60);  // adjsut for GMT standard time
    rtc.setEpoch(epoch);
    } 
}

void updateDate()
{
  // get date data
  years_int = rtc.getYear(); // Note - year is just two digits - 00 to 99
  sprintf(years_str, "%02d", years_int); //  converts to 2 character decimal base - pads leading 0s by adding the 0
  months_int = rtc.getMonth();
  sprintf(months_str, "%02d", months_int);
  days_int = rtc.getDay();
  sprintf(days_str, "%02d", days_int);
  strcpy(date_str, years_str);
  strcat(date_str, "-");
  strcat(date_str, months_str);
  strcat(date_str, "-");
  strcat(date_str, days_str);
}  

void updateTime()
{
  //get time data
  hours_int = rtc.getHours();
  sprintf(hours_str, "%02d", hours_int); // converts to 2 character decimal base - pads leading 0s by adding the 0
  minutes_int = rtc.getMinutes();
  sprintf(minutes_str, "%02d", minutes_int); 
  seconds_int = rtc.getSeconds();
  sprintf(seconds_str, "%02d", seconds_int); 
  strcpy(time_str, hours_str);
  strcat(time_str, ":");
  strcat(time_str, minutes_str);
  strcat(time_str, ":");
  strcat(time_str, seconds_str);
}  

void mkrError()
{
  // do not log new errors if one has been reported 
  //   and now in prcess of logging and resetting
  if (mkr_reset_flag_int == 1) {return;}
  // general case errors
  strcpy(error_type_display_str, error_type_str);
  strcat(error_type_display_str, " Error");
  // special case error
  if (strcmp(error_type_str, "BT") == 0) {
    strcpy(error_type_display_str, "BT restart");
    }  
  if (strcmp(error_type_str, "ST") == 0) {
    strcpy(error_type_display_str, "ST restart");
    }  
  // set flag for error reporting and shutdown
  mkr_reset_flag_int = 1;
}

// processor software reset 
void mkrReset()  // runs at end of 5 second mkrReset timer
{
  // send notification
  strcpy(notification_str, error_type_display_str);
  Blynk.logEvent("split-flap restarted", String(notification_str)); // log restart in timeline nnnnn
  Serial.println(notification_str);
  NVIC_SystemReset();
}

void send_remote_command()
{ 
  digitalWrite(rePin, HIGH); // disable read
  delay(1);
  digitalWrite(dePin, HIGH); // enable transmission     
  delay(1);
  Serial1.write(remote_command_str);  // just nl is the term character
  Serial1.flush();// wait until command is sent
  delay(1);
  digitalWrite(dePin, LOW); // disable transmission   // for testing
  delay(1);
}

void receive_remote_transmission()  // blocking serial read - up to 29 characters read
{
// reset remote transmission str
remote_trans_length_int = 0;  // set count to 0
strcpy(remote_transmission_str, "");  // clear string
digitalWrite(dePin, LOW); // disable transmission     
delay(1);
digitalWrite(rePin, LOW); // enable read
// read serial data for 30ms
delay(30);  // wait for all serial data to buffer
while (Serial1.available()){
  char data = (char)Serial1.read();  // note - return type default is int
  //terminal.println(data);
  remote_transmission_str[remote_trans_length_int] = data;
  // terminate string
  if (data == '\n') {// last character of command -- also for println need - data == '\r' || 
    remote_transmission_str[remote_trans_length_int] = '\0'; // terminate string
    //terminal.println("cr or nl found - string terminated with eos");
    //terminal.print("string length is:");
    //terminal.println(remote_trans_length_int);
    }
  remote_trans_length_int++;
  }
// output transmission // for testing
//terminal.println("final remote transmission string");
//terminal.println(remote_transmission_str);  // changed write to println
//terminal.print("string length is:");
//terminal.println(remote_trans_length_int);
//terminal.flush();
//Blynk.run();
digitalWrite(rePin, HIGH);  // disable read
delay(1);
}

void serial1Clear()
{
  while(Serial1.available() > 0) {
  char t = (char)
  Serial1.read();
  }
}

// For Blynk terminal commands
BLYNK_WRITE(V3)
{
  strcpy(cmd_str, param.asStr());  
  cmd_length_int = strlen(cmd_str);  // note - does not include '\0'.
  //terminal.println(cmd_str); // for testing
  //terminal.flush();
  //Blynk.run();
  
  // page two commands start first
  // for second line date and time
  if ((terminal_second_line_flag_int == 1) && (strcmp(param.asStr(), "") != 0)) { // returns 0 if equal
     int c_day_int; 
     int c_month_int; 
     int c_year_int; 
     int c_hours_int; 
     int c_minutes_int; 
     int c_seconds_int;
     char c_day_str[4]; 
     char c_month_str[4]; 
     char c_year_str[4]; 
     char c_hours_str[4]; 
     char c_minutes_str[4]; 
     char c_seconds_str[4];
     if (strlen(param.asStr()) != 17) { // note- null character ‘\0’ not counted
       terminal.println();  // add line feed
       terminal.println ("Invalid entry");
       terminal.println();  // add line feed
       terminal_second_line_flag_int = 0; // reset file read flag 
       terminal.flush();
       return;
       }
     sscanf(param.asStr(), "%d%*c%d%*c%d%*c%d%*c%d%*c%d", &c_year_int, &c_month_int, 
       &c_day_int, &c_hours_int, &c_minutes_int, &c_seconds_int);
     sscanf(param.asStr(), "%2s%*c%2s%*c%2s%*c%2s%*c%2s%*c%2s", c_year_str, c_month_str, 
       c_day_str, c_hours_str, c_minutes_str, c_seconds_str);
     terminal.println();  // add line feed
     terminal.print("Date and time changed to: ");
     terminal.print(c_year_str);
     terminal.print("/");
     terminal.print(c_month_str);
     terminal.print("/");
     terminal.print(c_day_str);
     terminal.print(" ");
     terminal.print(c_hours_str);
     terminal.print(":");
     terminal.print(c_minutes_str);
     terminal.print(":");
     terminal.println(c_seconds_str);
     terminal_second_line_flag_int = 0; // reset file read flag 
     // format rtc.setDate(byte day, byte month, byte year)
     // format rtc.setTime(byte hours, byte minutes, byte seconds)
     rtc.setDate(c_day_int, c_month_int, c_year_int);
     rtc.setTime(c_hours_int, c_minutes_int, c_seconds_int);
     //sscanf(param.asStr(), "%2s%*c%2s%*c%2s", prior_years_str, prior_months_str, prior_days_str);    
     //terminal.print("prior years: ");  // for testing
     //terminal.println(prior_years_str);
     //terminal.print("prior months: ");
     //terminal.println(prior_months_str);
     //terminal.print("prior days: ");
     //terminal.println(prior_days_str);    
     terminal.println();  // add line feed
     // Ensure everything is sent
     terminal.flush();
     Blynk.run();
     return;
  }
  // for second line Wifi ssid
    if ((serial_second_line_flag_int == 2) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
     if (strlen(cmd_str) > 15) { // note- null character ‘\0’ not counted
       terminal.println ("Invalid entry");
       terminal.println();  // add line feed
       terminal.flush();
       Blynk.run();
       serial_second_line_flag_int = 0; // reset file read flag 
       return;
       }
     strcpy(ssid, cmd_str);
     terminal.print("Wifi SSID changed to: ");
     terminal.println(ssid); 
     terminal.println();  // add line feed
     terminal.flush();
     Blynk.run();
     EEPROMWrite();
     serial_second_line_flag_int = 0; // reset file read flag 
     return;
     }
  // for second line Wifi password
    if ((serial_second_line_flag_int == 3) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
     if (strlen(cmd_str) > 15) { // note- null character ‘\0’ not counted
       terminal.println ("Invalid entry");
       terminal.println();  // add line feed
       terminal.flush();
       Blynk.run();
       serial_second_line_flag_int = 0; // reset file read flag 
       return;
       }
     strcpy(pass, cmd_str);
     terminal.print("Wifi password changed to: ");
     terminal.println(pass); 
     terminal.println();  // add line feed
     terminal.flush();
     Blynk.run();
     EEPROMWrite();
     serial_second_line_flag_int = 0; // reset file read flag 
     return;
     }
  // for second line GMT offset
    if ((serial_second_line_flag_int == 4) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l > 12) || (l < -12)) {
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        terminal.flush();
        Blynk.run();
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(k_GMT_str, cmd_str);
      k_GMT = atoi(k_GMT_str);
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      updateRTC();
      // read new time
      updateTime();
      terminal.print("GMT offset changed to: ");
      terminal.println(k_GMT_str); 
      terminal.println("Real time clock updated"); 
      terminal.println(); // add line feed
      terminal.flush();
      Blynk.run();
      return;
      }
  // for second line enable start hours
    if ((serial_second_line_flag_int == 5) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l < 0) || (l > 24)) {
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        terminal.flush();
        Blynk.run();
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(enableStartHours_str, cmd_str);
      terminal.print("Enable start hour changed to: ");
      terminal.println(enableStartHours_str); 
      enableStartHours = atoi(enableStartHours_str);
      terminal.print("Integer is: ");
      terminal.println(enableStartHours);  
      terminal.println();  // add line feed
      terminal.flush();
      Blynk.run();
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      return;
      }
  // for second line enable end hours
    if ((serial_second_line_flag_int == 6) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l < 0) || (l > 24)) {
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(enableEndHours_str, cmd_str);
      terminal.print("Enable end hour changed to: ");
      terminal.println(enableEndHours_str); 
      enableEndHours = atoi(enableEndHours_str);
      terminal.print("Integer is: ");
      terminal.println(enableEndHours);  
      terminal.println();  // add line feed
      terminal.flush();
      Blynk.run();
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      return;
      }  
  // for second line active time
    if ((serial_second_line_flag_int == 7) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l < 1) || (l > 1440)) {  // time is in minutes
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(activeTime_str, cmd_str);
      terminal.print("Active time (minutes) changed to: ");
      terminal.println(activeTime_str); 
      int activeTime_int = atoi(activeTime_str); // convert string to integer 
      activeTime = (long)activeTime_int; // and then to unsigned long
      // activeTime = (long)atoi(read_activeTime);
      terminal.print("Integer is: ");
      terminal.println(activeTime);  
      terminal.println();  // add line feed
      terminal.flush();
      Blynk.run();
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      return;
      }
  // for second line random phrase display
    if ((serial_second_line_flag_int == 8) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l != 0) && (l != 1)) {  // flag is 0 off or 1 on
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(randomPhraseDisplayFlag_str, cmd_str);
      randomPhraseDisplayFlag = atoi(randomPhraseDisplayFlag_str);
      terminal.print("Random phrase display flag set to: ");
      terminal.print(randomPhraseDisplayFlag_str); 
      if (randomPhraseDisplayFlag == 1) {terminal.println (" on");}
      else {terminal.println(" off");}  
      terminal.print("Integer is: ");
      terminal.println(randomPhraseDisplayFlag);  
      terminal.println();  // add line feed
      terminal.flush();
      Blynk.run();
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      return;
      }  
  
  // end page two commands 
    
  if (strcmp(cmd_str, "cmd") == 0) { // list commands
    terminal.println(",__   - display letter string"); 
    terminal.println(";__   - display letter string split"); 
    terminal.println("@     - list phrases"); 
    terminal.println("@nn   - display phrase nn"); 
    terminal.println("+     - increment all by one");
    terminal.println("aacc  - remote command");
    terminal.println("lrc   - list remote commands");
    terminal.println("arst  - hard reset for all devices");
    terminal.println("rst   - reset controller");
    terminal.println("sig   - report WiFi signal strength"); 
    terminal.println("v     - report version of code");
    terminal.println("rpt   - report all remotes");
    terminal.println("rptv  - report all remote versions");
    terminal.println("rtc   - report rtc time");
    terminal.println("c     - Blynk terminal clear");
    terminal.println("clr   - local terminal clear");
    terminal.println("cmd   - list available commands");
    terminal.println("cmdm  - list more commands");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "lrc") == 0) { // list remote commands
    terminal.println("0L letter");
    terminal.println("10 reset");
    terminal.println("11 test set request (active low)");
    terminal.println("12 test clear request (active high)");
    terminal.println("20 set gLed function to power");
    terminal.println("21 set gLed function to index");
    terminal.println("22 set rLed function to home");
    terminal.println("23 set rLed function to home and index");
    terminal.println("24 increase drive time by 5ms (default 75ms)");
    terminal.println("25 reduce drive time by 5ms");
    terminal.println("26 increase pause time by 5ms (default 50ms)");
    terminal.println("27 reduce pause time by 5ms");
    terminal.println("3x... increment by 10, 1, 2, etc");
    terminal.println("40 conduct motor test - 40 advanes, unless error");
    terminal.println("60 rpt position, home, index, error");
    terminal.println("61 rpt version of code");
    terminal.println("62 rpt length test - send back 01 - a...z");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cmdm") == 0) { // list more commands
    terminal.println("mtr   - motor test and report");
    terminal.println("rtc   - report rtc time");
    terminal.println("trs   - report/syncs rtc/WiFi times");
    terminal.println("tdon  - time display on");
    terminal.println("tdoff - time display off");
    terminal.println("tdclr - clear time display");
    terminal.println("tdset - set time display");
    terminal.println("cdt   - change date and time");  // second page flag 1
    terminal.println("rms   - report motion state (15s)");
    terminal.println("rth   - report thermistor value");
    terminal.println("cat  -  cancel active time");
    terminal.println("stat  - report op status");
    terminal.println("rst   - reset controller");
    terminal.println("cssid - change Wifi SSID");  // second page flag 2
    terminal.println("cpass - change Wifi password");   // second page flag 3
    terminal.println("cgmto - change GMT offset");  // second page flag 4
    terminal.println("csthr - change enable start hour");  // second page flag 5
    terminal.println("cenhr - change enable end hour");  // second page flag 6
    terminal.println("cactm - change active time(minutes)");  // second page flag 7
    terminal.println("crpf  - change random phrase flag");  // second page flag 8
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
    if (strcmp(cmd_str, "rst") == 0) {  // reset mkr
    terminal.println(); // add line feed
    terminal.println("device reset through Blynk terminal");
    // report type of error
    strcpy(error_type_str, "BT");
    mkrError();
    return;
    }
  if (strcmp(cmd_str, "arst") == 0) {  // reset all remote devices
    lastCommandMillis = currentMillis; // update time out
    relayOn(); // turn on relay
    digitalWrite(resetPin, LOW);
    delay200ms();
    digitalWrite(resetPin, HIGH);
    terminal.println(); // add line feed
    terminal.println("all remote devices reset through Blynk terminal");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }  
  if (strcmp(cmd_str, "tdon") == 0) { // time display on
    timeDisplayFlag = 1;
    terminal.println("time display on");
    setTimeDisplay();
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "tdoff") == 0) { // time display off
    timeDisplayFlag = 0;
    terminal.println("time display off");
    clearTimeDisplay();
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
    } 
  if (strcmp(cmd_str, "tdset") == 0) { // set time display - note - likely not neded by itself
    setTimeDisplay();
    delay500ms();
    return;
    } 
  if (strcmp(cmd_str, "tdclr") == 0) { // clear time display - note - likely not needed by itself
    clearTimeDisplay();
    delay500ms();
    return;
    } 
  if (strcmp(cmd_str, "rpt") == 0){  // if rpt, get reports of position and errors from all remotes
    lastCommandMillis = currentMillis; // update time out
    relayOn(); // turn on relay
    char s[4];
    for (int m = 1; m <= (numSplitFlaps + 2); m++){
      remote_command_str[0] = '[';  // format should be "[aadd]\0"
      sprintf(s,"%02d", m); // zero indicates padding leading 0s
      if (m == (numSplitFlaps + 1)){strcpy(s, hours_address_str);} // last two are for time
      if (m == (numSplitFlaps + 2)){strcpy(s, minutes_address_str);}
      remote_command_str[1] = s[0];
      remote_command_str[2] = s[1];
      remote_command_str[3] = '6';  // 60 is position and errors
      remote_command_str[4] = '0';
      remote_command_str[5] = ']';  // end character
      remote_command_str[6] = '\0';  // terminate string
      send_remote_command();
      serial1Clear();  // clear any serial remnants
      receive_remote_transmission();
      if (m == (numSplitFlaps + 1)){terminal.println();} 
      terminal.println(remote_transmission_str); 
      delay (10);  // note - consider reducing delay time or eliminating
      }
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
    }  
  if (strcmp(cmd_str, "rptv") == 0){  // if rpt, get report of version from all remotes
    lastCommandMillis = currentMillis; // update time out
    relayOn(); // turn on relay
    char s[4];
    for (int m = 1; m <= (numSplitFlaps + 2); m++){  // note update based on remote number
      remote_command_str[0] = '[';  // format should be "[aadd]\0"
      sprintf(s,"%02d", m); // zero indicates padding leading 0s
      if (m == (numSplitFlaps + 1)){strcpy(s, hours_address_str);} // last two are for time
      if (m == (numSplitFlaps + 2)){strcpy(s, minutes_address_str);}
      remote_command_str[1] = s[0];
      remote_command_str[2] = s[1];
      remote_command_str[3] = '6'; // 61 is version
      remote_command_str[4] = '1';
      remote_command_str[5] = ']';  // end character
      remote_command_str[6] = '\0';  // terminate string
      send_remote_command();
      serial1Clear();  // clear any serial remnants
      receive_remote_transmission();
      if (m == (numSplitFlaps + 1)){terminal.println();} 
      terminal.println(remote_transmission_str); 
      delay (10);  // // gote - consider reducing delay time or eliminating
      }
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
    }  
  if (cmd_str[0] == ','){  // if comma, letter string command
    lastCommandMillis = currentMillis; // update time out
    relayOn(); // turn on relay
    int m;
    char s[4];
    WDTimer.clear();  // refresh watch dog timer
    for (int m = 1; m <= numSplitFlaps; m++){
      remote_command_str[0] = '[';  // format should be "[aadd]\0"
      sprintf(s,"%02d", m); // zero indicates padding leading 0s
      remote_command_str[1] = s[0];
      remote_command_str[2] = s[1];
      remote_command_str[3] = '0';
      remote_command_str[4] = cmd_str[m];  // 0 is ','
      // pad with spaces
      if (m > cmd_length_int) remote_command_str[4] = ' '; 
      remote_command_str[5] = ']';  // end character
      remote_command_str[6] = '\0';  // terminate string
      send_remote_command();
      delay75ms();  // was 500, then 250, then 100 in the beginning
      //WDTimer.clear();  // refresh watch dog timer
      }
    return;
    }  
  if (cmd_str[0] == ';'){  // if semicolon, letter string command 
    lastCommandMillis = currentMillis; // update time out
    relayOn(); // turn on relay
    createDisplayStrings(); // split words into lines and display
    return;
    }  
  if (cmd_str[0] == '@'){  // if @ "at sign," stored string display command
    char sp[4];
    WDTimer.clear();  // refresh watch dog timer
    lastCommandMillis = currentMillis; // update time out
    relayOn(); // turn on relay
    if(strlen(cmd_str) >= 3){ //test to make sure number sent as well
      // note strlen does not count '\0'
      sp[0] = cmd_str[1];
      sp[1] = cmd_str[2];
      sp[2] = '\0';
      phrase_num = atoi(sp); // convert string to integer
      phraseDisplay();
      }
    else {
      phraseMenu(); // list avail phrases
      }
    return;
    } 
  if (strcmp(param.asStr(), "cdt") == 0) { // change date and time
     terminal.println(); // add line feed
     terminal.println("Enter date and time (yy/mm/dd hh:mm:ss)");
     terminal_second_line_flag_int = 1;  // set flag for next line read
     terminal.println(); // add line feed
     terminal.flush();
     Blynk.run();
     return;
    }
  if (strcmp(cmd_str, "rtc") == 0) {  // report rtc time
    //get time data
    updateTime();
    terminal.println(); // add line feed
    terminal.print("RTC time: ");
    terminal.println(time_str);
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "c") == 0) { // Clear the terminal content    // note - returns 0 if equal
    terminal.clear();  // this is the remote clear.  type clr for a local clear.
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cssid") == 0) { // change Wifi SSID
    terminal.println("Enter new Wifi SSID: ");
    serial_second_line_flag_int = 2;  // set flag for next WifI SSID line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cpass") == 0) { // change Wifi password
    terminal.println("Enter new Wifi password: ");
    serial_second_line_flag_int = 3;  // set flag for next WifI password line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cgmto") == 0) { // change GMT offset
    terminal.println("Enter new GMT offset: ");
    serial_second_line_flag_int = 4;  // set flag for next GMT offset line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "csthr") == 0) { // change enable start hour
    terminal.println("Enter new enable start hour: ");
    serial_second_line_flag_int = 5;  // set flag for next enable start hour line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cenhr") == 0) { // change enable end hour
    terminal.println("Enter new enable end hour: ");
    serial_second_line_flag_int = 6;  // set flag for next enable end hour line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
 if (strcmp(cmd_str, "cactm") == 0) { // change active time
    terminal.println("Enter new active time (minutes): ");
    serial_second_line_flag_int = 7;  // set flag for next active time line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
 if (strcmp(cmd_str, "crpf") == 0) { // change random phrase display flag
    terminal.println("Set random phrase flag - 0 off 1 on: ");
    serial_second_line_flag_int = 8;  // set flag for next active time line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "v") == 0) {  // report version
    terminal.println(); // add line feed
    terminal.print("Version of Controller Code is: ");
    terminal.println(version_str);
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "sig") == 0) {  // report wifi signal strength
    rssi = WiFi.RSSI();
    terminal.println(); // add line feed
    terminal.print("Signal strength (RSSI) is ");
    terminal.print(rssi);
    terminal.println(" dBm");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "trs") == 0) {  // report and sync rtc and current wifi times
    //get time data
    terminal.println(); // add line feed
    updateTime();
    terminal.print("RTC time is ");
    terminal.println(time_str);
    // update RTC
    updateRTC();
    // read new time
    updateTime();
    terminal.print("WiFi time is ");
    terminal.println(time_str);
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "wdt") == 0) {  // check wdt function
    unsigned int t;
    terminal.println("\nWatchdog Test - run 18 seconds with a WDTimer.clear()\n");
    Serial.println("\nWatchdog Test - run 18 seconds with a WDT.clear()\n");
    for (t = 1; t <= 18; ++t) {
      WDTimer.clear();  // refresh wdt - before it loops
      delay(950);
      terminal.print(t);
      terminal.print(".");
      terminal.flush();
      Blynk.run(); 
      }
    terminal.println("\n\nWatchdog Test - free run wait for reset at 8 seconds\n");
    for (t = 1; t >= 1; ++t) {
      delay(950);
      terminal.print(t);
      terminal.print(".");
      terminal.flush();
      Blynk.run();
      }
    return;
    }   
// for testing
  if (strcmp(cmd_str, "cat") == 0) {  //  cancel active time in 10 seconds
    lastMotionMillis = currentMillis - (activeTime * 60000) + 10000;
    lastCommandMillis = currentMillis - (activeTime * 60000) + 10000;
    return;
    }
  if (strcmp(cmd_str, "rpd0") == 0) {  //  randomPhraseDisplay off
    randomPhraseDisplayFlag = 0;
    return;
    }
  if (strcmp(cmd_str, "rpd1") == 0) {  //  randomPhraseDisplay on
    randomPhraseDisplayFlag = 1;
    return;
    }
 /* For testing
  if (strcmp(cmd_str, "tr0") == 0) {  //  led off
    redLedState = 0;
    return;
    }
  if (strcmp(cmd_str, "tr1") == 0) {  //  led on
    redLedState = 1;
    return;
    }
  if (strcmp(cmd_str, "tr2") == 0) {  //  led blink
    redLedState = 2;
    return;
    }
  if (strcmp(cmd_str, "tg0") == 0) {  //  led off
    greenLedState = 0;
    return;
    }
  if (strcmp(cmd_str, "tg1") == 0) {  //  led on
    greenLedState = 1;
    return;
    }
  if (strcmp(cmd_str, "tg2") == 0) {  //  led blink
    greenLedState = 2;
    return;
    }  
  if (strcmp(cmd_str, "tb0") == 0) {  //  led off
    blueLedState = 0;
    return;
    }
  if (strcmp(cmd_str, "tb1") == 0) {  //  led on
    blueLedState = 1;
    return;
    }
  if (strcmp(cmd_str, "tb2") == 0) {  //  led blink
    blueLedState = 2;
    return;
    }   
  if (strcmp(cmd_str, "tsw0") == 0) {  //  led off
    switchLedState = 0;
    return;
    }
  if (strcmp(cmd_str, "tsw1") == 0) {  //  led on
    switchLedState = 1;
    return;
    }
  if (strcmp(cmd_str, "tsw2") == 0) {  //  led blink
    switchLedState = 2;
    return;
    }   
  if (strcmp(cmd_str, "reon") == 0) {  //  relay on
    relayOn();
    return;
    }
  if (strcmp(cmd_str, "reoff") == 0) {  //  relay off
    relayOff();
    return;
    }
  if (strcmp(cmd_str, "faon") == 0) {  //  fan on
    fanOn();
    return;
    }
  if (strcmp(cmd_str, "faoff") == 0) {  //  fan off
    fanOff();
    return;
    }
    */
  if (strcmp(cmd_str, "rms") == 0) {  //  report motion state (15s)
    terminal.println("Motion State for 15 seconds:");
    for (int j = 0; j < 15; j++){
      motionState = digitalRead(motionPin);  // active high
      terminal.print("  ");
      terminal.println(motionState);
      terminal.flush();  // output to terminal immediately
      //Blynk.run();      
      delay1s();
      //WDTimer.clear();  // refresh watch dog timer
      }
    return;
    }
  if (strcmp(cmd_str, "rth") == 0) {  //  report thermistor value
    if (rthFlag == 0){rthFlag = 1;}
    else rthFlag = 0;
    return;
    }
 
  if (strcmp(cmd_str, "stat") == 0) {
    terminal.print("motionState = ");
    terminal.println(motionState);
    terminal.print("motionEnable = ");
    terminal.println(motionEnable);
    terminal.print("redLedState = ");
    terminal.println(redLedState);
    terminal.print("relayState = ");
    terminal.println(relayState);
    terminal.print("greenLedState = ");
    terminal.println(greenLedState);
    terminal.print("switchLedState = ");
    terminal.println(switchLedState);
    terminal.print("blueLedState = ");
    terminal.println(blueLedState);
    terminal.print("fanState = ");
    terminal.println(fanState);
    terminal.print("thermistorValue = ");
    terminal.print(thermistorValue); // for testing
    terminal.print("   ");
    terminal.print(thermistorTemp);
    terminal.println(" deg F");
    terminal.flush();  // output to terminal immediately
    terminal.print("hours_int = ");
    terminal.println(hours_int);
    terminal.print("minutes_int = ");
    terminal.println(minutes_int);
    terminal.print("ssid = ");
    terminal.println(ssid);
    terminal.print("pass = ");
    terminal.println(pass);
    terminal.print("GMT offset = ");
    terminal.println(k_GMT);
    terminal.print("enableStartHours = ");
    terminal.println(enableStartHours);
    terminal.print("enableEndHours = ");
    terminal.println(enableEndHours);
    terminal.print("activeTime = ");
    terminal.print(activeTime);
    terminal.println(" minutes");
    currentMillis = millis();
    terminal.print("remaining time motion(sec) = ");
    // activeTime is in minutes
    if (lastMotionMillis != 0){ // note - if no motion, then lastMotionMillis will be 0
      // Note - min used to avoid negative number
      terminal.println(((activeTime * 60000)- min((currentMillis - lastMotionMillis), (activeTime * 60000)))/1000);
      }
    else {terminal.println(0);}
    terminal.print("remaining time command(sec) = "); // above calcuation returns seconds due to /1000
    terminal.println(((activeTime * 60000)- min((currentMillis - lastCommandMillis), (activeTime * 60000)))/1000);
    terminal.print("timeDisplayFlag = ");
    terminal.println(timeDisplayFlag);
    terminal.print("randomPhraseDisplayFlag = ");
    terminal.println(randomPhraseDisplayFlag);
    terminal.println(); // add line
    terminal.flush();
    Blynk.run();
    return;
    }
   if (strcmp(cmd_str, "mtr") == 0) {
    lastCommandMillis = currentMillis; // update time out
    relayOn(); // turn on relay
    strcpy(remote_command_str, "[0040]");
    // send command
    send_remote_command();
    delay8s();
    // get reports of position and errors from all remotes
    char s[4];
    for (int m = 1; m <= (numSplitFlaps + 2); m++){
      remote_command_str[0] = '[';  // format should be "[aadd]\0"
      sprintf(s,"%02d", m); // zero indicates padding leading 0s
      if (m == (numSplitFlaps + 1)){strcpy(s, hours_address_str);} // last two are for time
      if (m == (numSplitFlaps + 2)){strcpy(s, minutes_address_str);}
      remote_command_str[1] = s[0];
      remote_command_str[2] = s[1];
      remote_command_str[3] = '6';  // 60 is position and errors
      remote_command_str[4] = '0';
      remote_command_str[5] = ']';  // end character
      remote_command_str[6] = '\0';  // terminate string
      send_remote_command();
      serial1Clear();  // clear any serial remnants
      receive_remote_transmission();
      if (m == (numSplitFlaps + 1)){terminal.println();} 
      terminal.println(remote_transmission_str); 
      delay(10);  // Note - consider reducing delay time or eliminating
      }
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
    }  
  if (cmd_str[0] == '+'){  // check if incremnt all by one command
    lastCommandMillis = currentMillis; // update time out
    relayOn(); // turn on relay
    strcpy(remote_command_str, "[0031]");
    // send command
    send_remote_command();
    return;
    }
  // check if cmd_str[0] is a number for remote device direct command
  int p = cmd_str[0] - '0';  // convert to integer
  if (p >= 0 && p <= 9){ 
    lastCommandMillis = currentMillis; // update time out
    relayOn(); // turn on relay
    strcpy(remote_command_str, "[");
    strcat(remote_command_str, cmd_str);
    strcat(remote_command_str, "]");
    // send command
    send_remote_command();
    if (remote_command_str[3] == '6' && remote_command_str[4] == '0'){  // position, home, index, status back
      //read staus back      
      serial1Clear();  // clear any serial remnants
      receive_remote_transmission();
      terminal.println(remote_transmission_str); 
      }
    if (remote_command_str[3] == '6' && remote_command_str[4] == '1'){  // version back
      serial1Clear();  // clear any serial remnants
      receive_remote_transmission();
      terminal.println(remote_transmission_str); 
      }
    if (remote_command_str[3] == '6' && remote_command_str[4] == '2'){  // count 1-30 back
      serial1Clear();  // clear any serial remnants
      receive_remote_transmission();  // right now this prints return str as well
      terminal.println(remote_transmission_str); 
      }
    if (remote_command_str[3] == '1' && remote_command_str[4] == '1'){ // read request back
      //read request staus if request was on - active low
      delay(20);
      if (digitalRead(requestPin) == LOW){
        terminal.println("request pin is low, or on.");
        }
      else{
        terminal.println("request pin is high, or off.");
        }
      }
    if (remote_command_str[3] == '1' && remote_command_str[4] == '2'){ // read request back
      //read request staus if request was off - active low
      delay(20);
      if (digitalRead(requestPin) == HIGH){
        terminal.println("request pin is high, or off.");
        }
      else{
        terminal.println("request pin is low, or on.");
        }
      }
    terminal.flush();
    Blynk.run();
    return;
    }  
// end of command waterfall
}

// for phone's blinking link green LED - runs every second
// also for blinking MKR1010 built in LED indicating link
void blinkLedWidget() 
{
if (led1.getValue()) {
  led1.off();
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //Serial.println("LED on V1: off");  // Note - built in LED controlled by pin 6
  } else {
    led1.on();
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    //Serial.println("LED on V1: on");
  }
}

// This function will be called every time Switch Widget 
// in Blynk app writes values to the Virtual Pin V0
// Note - not used at the moment
BLYNK_WRITE(V0)
{
value_sw0_int = param.asInt(); // assigning incoming value from pin V0 to a variable
if (value_sw0_int == 1){
  state_sw0_int ++;
  if (state_sw0_int > 6) {state_sw0_int = 0;}
  }
}

void updateTimeDisplay()
{
// updates time display only if hours or minutes has changed
hours_int = rtc.getHours();
minutes_int = rtc.getMinutes();
// check if new hour or mintues and update if so
if ((currentDisplayHours_int != hours_int) ||
    (currentDisplayMinutes_int != minutes_int/5)){
  // update hours
  currentDisplayHours_int = hours_int;
  strcpy(remote_command_str, "[");
  strcat(remote_command_str, hours_address_str);
  strcat(remote_command_str, "0");
  currentCharacter_str[0] = flipCharsHoursDisplay_str[currentDisplayHours_int];
  strcat(remote_command_str, currentCharacter_str);
  strcat(remote_command_str, "]");
  // send hour command
  send_remote_command();
  // update minutes
  currentDisplayMinutes_int = minutes_int/5; // blank is position 0
  strcpy(remote_command_str, "[");
  strcat(remote_command_str, minutes_address_str);
  strcat(remote_command_str, "0");
  currentCharacter_str[0] = flipCharsMinutesDisplay_str[currentDisplayMinutes_int + 1];
  strcat(remote_command_str, currentCharacter_str);
  strcat(remote_command_str, "]");
  // send minutes command
  send_remote_command();
  }
}

void setTimeDisplay()
{
// updates time display to current time and turns time display on
currentDisplayHours_int = 999;  // cause update by using incorrect time 
currentDisplayMinutes_int = 999; 
timeDisplayFlag = 1; // turn on time display if not already on
updateTimeDisplay();
}

void clearTimeDisplay()
{
// clears time display and turns time dispaly off
strcpy(remote_command_str, "[");
strcat(remote_command_str, hours_address_str);
strcat(remote_command_str, "0 ]"); // format should be "[aadd]\0"
send_remote_command();
delay(5);
strcpy(remote_command_str, "[");
strcat(remote_command_str, minutes_address_str);
strcat(remote_command_str, "0 ]"); // format should be "[aadd]\0"
send_remote_command();
delay(5);
timeDisplayFlag = 0; // turn off time display to keep clear
}

void createDisplayStrings()
{
// set up and initialize variables
char *pch; 
word_cnt = 0;
char* cmd_chopped = cmd_str + 1; // eliminate leading ';' 
strcpy(input_str, cmd_chopped); 
//"0123t 4567t 890t 1234t 567890123t 45678t 901234t"); // for testing
// split the string on these delimiters into "tokens"
strcpy(input_str2, input_str); // new string needed as strtok is destructive
pch = strtok (input_str2," ,");
sprintf(word_str[word_cnt], "%s", pch);
//Serial.println(word_str[word_cnt]);  // for testing
while (1)
  {
  pch = strtok (NULL, " ,"); // continue to split the string on these delimiters
  if (pch == NULL) {break;}  // this configuration was needed for while loop to work
  word_cnt++;
  sprintf(word_str[word_cnt], "%s", pch);
  }
// print out words  for testing
//Serial.println(input_str);
//Serial.println(word_cnt+1);
//Serial.println();
for (int i = 0; i <= word_cnt; i++) {  // note - first word is [0]
  word_str_length[i] = strlen(word_str[i]);
  if (word_str_length[i] >= row_length - 2) { 
    // above subtract two to add '-' and due to starting row posiiton at 0 not 1
    // make room for additional word
    for (int j = word_cnt; j > i; j--) {
      strcpy(word_str[j+1], word_str[j]);
      }
    // trim end and hyphenate first part
    strcpy(word_str[i+1], word_str[i]);
    word_str[i][11] = '-';
    word_str[i][12] = '\0';
    // copy and trim front of second part 
    for (int m = 0; m <= (word_str_length[i] - (row_length - 1)); m++){
      word_str[i+1][m] = word_str[i+1][m + (row_length - 1)]; // capture null character
      //Serial.println(word_str[i+1][m]);
      }
    // update new string lengths
    word_str_length[i] = strlen(word_str[i]);
    word_str_length[i+1] = strlen(word_str[i+1]);
    // update loop variables for added word
    i++;;
    word_cnt++;
    //Serial.println(word_str_length[i]);
    }
  }
// for testing
//for (int i = 0; i <= word_cnt; i++) { 
//  Serial.print(word_str[i]);
//  Serial.print("  ");
//  Serial.println(word_str_length[i]);
//  }
//Serial.println();
// assemble row lines
int new_row_flag = 1;
row_number = 0;
for (int i = 0; i <= word_cnt; i++) {
  if (new_row_flag == 1){
    strcpy(row_display_array[row_number], word_str[i]);
    //Serial.println(row_display_array[row_number]);
    new_row_flag = 0;
    }
  else { 
    if ((strlen(row_display_array[row_number]) + word_str_length[i]) <= (row_length - 1)) { // row length includes '\0'
      // two '\0' make up for space and last '\0'
      strcat(row_display_array[row_number], " ");  // add space between words
      strcat(row_display_array[row_number], word_str[i]);
      //Serial.println(row_display_array[row_number]);
      }
    else {  // make new row
      row_number++; 
      strcpy(row_display_array[row_number], word_str[i]);
      //Serial.println(row_display_array[row_number]);
      new_row_flag = 0;
      }
    }
  }
// add spaces to fill each row
for (int i = 0; i <= row_number; i++){
  int k;
  int j = row_length - 1 - strlen(row_display_array[i]);
  for (k = 0; k <= j; k++) {
    strcat(row_display_array[i], " ");  // add space after word(s)
    }
//  Serial.print(row_display_array[i]);
//  Serial.println("end");
  }
//Serial.println();
//Serial.print("0-");
//Serial.println(row_number); 
// assemble single string for each page display
// add completed rows for first page
// note- can have up to 8 pages of 4 rows each for 32 total rows 
// note - 64 words max
int num_pages = (row_number + 4) / 4; // round up - not that row 1 is [0]
// Serial.println();
//Serial.print("pages = ");
//Serial.println(num_pages);
for (int p = 0; p < num_pages; p++){
  if (row_number >= p*4) strcpy (display_str, row_display_array[(p*4)+0]);
  //Serial.println(display_str);
  if (row_number >= ((p*4)+1)) strcat (display_str, row_display_array[(p*4)+1]);
  else strcat (display_str, "            ");
  //Serial.println(display_str);
  if (row_number >= ((p*4)+2)) strcat (display_str, row_display_array[(p*4)+2]);
  else strcat (display_str, "            ");
  //Serial.println(display_str);
  if (row_number >= ((p*4)+3)) strcat (display_str, row_display_array[(p*4)+3]);
  else strcat (display_str, "            ");
  //Serial.println(display_str);
  //Serial.println("above sent to display page");  // for testing
  WDTimer.clear();  // refresh watch dog timer
  displayPage(); 
  delay7s();
  }
}

void EEPROMWrite()
{
EEPROM.put(storedAddress, WRITTEN_SIGNATURE);
strcpy(controller.eeprom_ssid, ssid);
strcpy(controller.eeprom_pass, pass);
strcpy(controller.eeprom_k_GMT, k_GMT_str);
strcpy(controller.eeprom_enableStartHours, enableStartHours_str);
strcpy(controller.eeprom_enableEndHours, enableEndHours_str);
strcpy(controller.eeprom_activeTime, activeTime_str);
strcpy(controller.eeprom_randomPhraseDisplayFlag, randomPhraseDisplayFlag_str);
// Save everything into EEPROM
EEPROM.put(storedAddress + sizeof(signature), controller);
if (!EEPROM.getCommitASAP()){
  //Serial.println("CommitASAP not set. Need commit()");
  EEPROM.commit();
  }
// Print a confirmation of the data written.
terminal.println("Updated Data: ");
terminal.print("ssid ");
terminal.println(controller.eeprom_ssid); 
terminal.print("pass: ");
terminal.println(controller.eeprom_pass); 
terminal.print("k_GMT: ");
terminal.println(controller.eeprom_k_GMT);
terminal.print("enableStartHours: ");
terminal.println(controller.eeprom_enableStartHours);
terminal.print("enableEndHours: ");
terminal.println(controller.eeprom_enableEndHours);
terminal.print("activeTime: ");
terminal.println(controller.eeprom_activeTime);
terminal.print("randomPhraseDisplayFlag: ");
terminal.println(controller.eeprom_randomPhraseDisplayFlag);
terminal.println();
terminal.flush();
Blynk.run();
}

void displayPage()
{
char s[4];
for (int m = 1; m <= numSplitFlaps; m++){ // note split flaps stata at address 01
  remote_command_str[0] = '[';  // format should be "[aadd]\0"
  sprintf(s,"%02d", m); // zero indicates padding leading 0s
  remote_command_str[1] = s[0];
  remote_command_str[2] = s[1];
  remote_command_str[3] = '0';
  remote_command_str[4] = display_str[m-1];  // 0 is ','
  remote_command_str[5] = ']';  // end character
  remote_command_str[6] = '\0';  // terminate string
  send_remote_command();
  //Serial.print(display_str[m-1]); // for testing
  //if (m == row_length) Serial.println();  // break after each row of 12
  //if (m == row_length*2) Serial.println();
  //if (m == row_length*3) Serial.println();
  delay75ms();  // was 500, then 250, then 100 in the beginning
  // WDTimer.clear();  // refresh watch dog timer
  }
//Serial.println();  // for testing
//Serial.println("end of page display");  // for testing
//Serial.println();  // for testing
}

// longer delays that maintain Blynk uptime and led connection 
//   and WDT clearing
void delay75ms(){ 
  currentMillis = millis();
  if(currentMillis - previousMillis_blinkLedWidget >= 1000) {
    previousMillis_blinkLedWidget = currentMillis;  // Remember the time
    blinkLedWidget();
    Blynk.virtualWrite(V2, millis() / 60000); // send the uptime
    Blynk.run();
    delay(50); // shorter to allow for Blynk functions
    }
  else{
    delay(75);
    } 
  WDTimer.clear();
  }
void delay200ms(){ // incorporate 75ms??
  currentMillis = millis();
  if(currentMillis - previousMillis_blinkLedWidget >= 1000) {
    previousMillis_blinkLedWidget = currentMillis;  // Remember the time
    blinkLedWidget();
    Blynk.virtualWrite(V2, millis() / 60000); // send the uptime
    Blynk.run();
    delay(175); // shorter to allow for Blynk functions
    }
  else{
    delay(200);
    } 
  WDTimer.clear();
  }
void delay500ms(){delay(300); delay200ms();}
void delay1s(){delay500ms(); delay500ms();}
void delay2s(){delay1s(); delay1s();}
void delay3s(){delay2s(); delay1s();}
void delay4s(){delay2s(); delay2s();}
void delay5s(){delay3s(); delay2s();}
void delay6s(){delay4s(); delay2s();}
void delay7s(){delay4s(); delay3s();}
void delay8s(){delay4s(); delay4s();}
