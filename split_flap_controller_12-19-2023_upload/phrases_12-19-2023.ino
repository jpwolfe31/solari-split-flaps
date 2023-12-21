

void phraseMenu()
{
// personal
terminal.println("@01 - ok ok ok"); 
terminal.println("@02 - hello hello andrew et al");


// quotes
terminal.println("@21 - art is anything -andy warhol"); 
terminal.println("@22 - you cant always get -rolling stones"); 
terminal.println("@23 - the wolf cares not - plato"); 
terminal.println("@24 - when one tugs - john muir"); 
terminal.println("@25 - the snow is melting into -john muir"); 
terminal.println("@26 - every momment -ts elliot"); 
terminal.println("@27 - is life but a dream."); 
terminal.println("@28 - the right question -plato");
terminal.println("@29 - things are not always what they seem.");
terminal.println("@30 - simplicity is the ultimate -de vinci");
terminal.println("@31 - one small step for man -neil armstrong");
terminal.println("@32 - appreciate the moment.");
terminal.println("@33 - still california dreaming.");
terminal.println("@34 - showing up is 80 percent of -andy warhol");
terminal.println("@35 - water is relentless -john muir");
terminal.println("@36 - may you live every day -jonathan swift"); 
terminal.println("@37 - we live in an age when -oscar wilde");
terminal.println("@38 - the art of being wise is -william james");
terminal.println("@39 - we become what we contemplate -plato");

// graphic
terminal.println("@71 - num alpha num then +40");
terminal.println("@72 - num alpha num then blank");
terminal.println("@73 - dash dot blank walk");

// description
terminal.println("@91 - youtube narration display");
terminal.println(); // add line feed
terminal.flush();
Blynk.run();
return;
}

void randomPhraseDisplay()
{
// select and display random phrase
int phrase_lookup[21] = {1, 2, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
                           30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
int number_phrases = 21;
updateTime();
int seed = (minutes_int * 60) + seconds_int;
srand(seed); // seed random number gernerator with somewhat random number
int j = rand() % number_phrases;
phrase_num = phrase_lookup[j];
while(phrase_num == phrase_num_old) {  // avoid randomly repeating same phrase
  seed = (minutes_int * 60) + seconds_int + 2500;
  srand(seed); // seed random number gernerator with somewhat random number
  j = rand() % number_phrases;
  phrase_num = phrase_lookup[j];
  }  
phraseDisplay();  // phraseDisplay uses phrase_num integer to decode
phrase_num_old = phrase_num;
}

void phraseDisplay()
{
if (phrase_num == 39){
  char phrase[1][64] = {"we become   what we     contemplate.            "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  }
if (phrase_num == 38){
  char phrase[2][64] = {"the art of  being wise  is knowing              ",
                        "what to     overlook.                           "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  }
if (phrase_num == 37){
  char phrase[2][64] = {"we live in  an age when unnecessary things are  ",
                        "our only    necessities.                        "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }    
if (phrase_num == 36){
  char phrase[1][64] = {"may you liveevery day ofyour life.              "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 35){
  char phrase[2][64] = {"water is    relentless  in its                  ",
                        "quest       downward.                           "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 34){
  char phrase[1][64] = {"showing up  is 80       percent     of life.    "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 33){
  char phrase[1][64] = {"still       california  dreaming.               "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 32){
  char phrase[1][64] = {"appreciate  the moment.                         "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 31){
  char phrase[2][64] = {"one small   step for    man                     ",
                        "one giant   leap for    mankind.                "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 30){
  char phrase[2][64] = {"simplicity  is the      ultimate                ",
                        "sophistica-  tion.                              "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 29)  {
  char phrase[1][64] = {"things are  not always  what they   seem.       "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 28)  {
  char phrase[2][64] = {"the right   question is usually moreimportant   ",
                        "than the    right       answer.                 "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 27)  {
  char phrase[1][64] = {"is life     but a dream.                        "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 26)  {
  char phrase[1][64] = {"every momentis a fresh  beginning.              "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 25)  {
  char phrase[1][64] = {"the snow    is melting  into music.             "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 24){
  char phrase[3][64] = {"when one    tugs at a   single      string      ",
                        "in nature   he finds it attached to the rest    ",
                        "of the      world.                              "};
  //                     |           |           |           |           |
  for (int p = 0; p < 3; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 23)  {
  char phrase[1][64] = {"the wolf    cares not   how many thesheep be.   "};
   //                    |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 22){
  char phrase[5][64] = {"you cant    always get  what you    want        ",
                        " you cant    always get  what you    want       ",
                        "but if you  try         sometimes               ",
                        "you just    might find                          ",
                        "you get     what you    need.....               "};
  //                     |           |           |           |           |
  for (int p = 0; p < 5; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 21)  {
  char phrase[1][64] = {"art is      anything youcan get     away with.  " };
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 2)  {
  char phrase[1][64] = {"hello hello andrew      austin cole kim and john"};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 1)  {
  char phrase[2][64] = {"ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ",
                        " ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok"};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(5000); // a bit more for this one
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

// end of quote phrases ------------------------

if (phrase_num == 71)  {
  char phrase[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    relayOn(); // turn on relay
    strcpy(remote_command_str, "[0040]"); //advance flaps 40
    // send command
    send_remote_command();
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    send_remote_command();
    } 
  }
if (phrase_num == 72)  {
  char phrase[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    relayOn(); // turn on relay
    strcpy(remote_command_str, "[000 ]"); // advance flaps home
    // send command
    send_remote_command();
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }
if (phrase_num == 73)  {
  // dash, dot blank walk
  char s[4];
  // clear display
  strcpy(remote_command_str, "[000 ]"); // clear screen - advance flaps home
  send_remote_command();
  WDTimer.clear();  // refresh watch dog timer
  delay(6000); 
  // dash walk first
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 1; p <= 12; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '-';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay (200);
    }
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 24; p >= 13; p--){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '-';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay (200);
    }
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 25; p <= 36; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '-';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay (200);
    }
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 48; p >= 37; p--){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '-';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay (200);
    }
  // pause
  WDTimer.clear();  // refresh watch dog timer
  delay(6000); 
  // dot walk second
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 1; p <= 12; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '.';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay (200);
    }
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 24; p >= 13; p--){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '.';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay (200);
    }
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 25; p <= 36; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '.';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay (200);
    }
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 48; p >= 37; p--){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '.';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay (200);
    }
  // pause
  WDTimer.clear();  // refresh watch dog timer
  delay(3000);
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 1; p <= 12; p++){ // row one /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '/';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay(1000);
  for (int p = 1; p <= 12; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = ' ';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
  }
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 13; p <= 24; p++){ // row 2 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '/';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay(1000);
  for (int p = 13; p <= 24; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = ' ';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
  }
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 25; p <= 36; p++){ // row 3 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '/';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay(1000);
  for (int p = 25; p <= 36; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = ' ';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
  }
  WDTimer.clear();  // refresh watch dog timer
  for (int p = 37; p <= 48; p++){ // row 4 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '/';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay(1000);
  for (int p = 37; p <= 48; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = ' ';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  // older end below after all dots, all /, then blank   
  //WDTimer.clear();  // refresh watch dog timer
  //delay(5000);
  // clear display third
  //strcpy(remote_command_str, "[000 ]"); // clear screen - advance flaps home
  //send_remote_command();
  //}
  }

if (phrase_num == 91){
  char phrase_a[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_a[p]);
    displayPage();
    delay4s();
    delay3s();
    relayOn(); // turn on relay
    strcpy(remote_command_str, "[000 ]"); // advance flaps home
    // send command
    send_remote_command();
    delay4s();
    delay2s();
    } 
  //  Note must use differenct array names when in same for stmt
  char phrase_b[12][64] =  {"This is a   Solari      split-flap  display.    ",  
                            "We were toldthe split-  flaps were  installed at",
                            "an airport  in the      1960s.                  ",
                            "We purchasedthe split-  flaps on    ebay.       ",
                            "These split-flaps       represent   a small     ",
                            "portion of  the originaldisplay.                ",
                            "The         electronics that controlthe display ",
                            "are new and contained   in the      black case  ",
                            "next to the time        display.                ",  
                            "For more    information on these    devices     ",
                            "and the codeand         electronics used see    ",
                            "www.github  .com/jpwolfe31/solari-  split-flaps "};
  //                         |           |           |           |           |
  for (int p = 0; p < 12; p++){  
    strcpy(display_str, phrase_b[p]);
    displayPage();
    delay4s();
    delay3s();
    } 
  // dash, dot blank walk
  char s[4];
  // clear display
  strcpy(remote_command_str, "[000 ]"); // clear screen - advance flaps home
  send_remote_command();
  delay6s(); 
  // dash walk first
  for (int p = 1; p <= 12; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '-';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay200ms();
    }
  for (int p = 24; p >= 13; p--){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '-';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay200ms();
    }
  for (int p = 25; p <= 36; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '-';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay200ms();
    }
  for (int p = 48; p >= 37; p--){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '-';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay200ms();
    }
  // pause
  delay6s(); 
  // dot walk second
  for (int p = 1; p <= 12; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '.';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay200ms();
    }
  for (int p = 24; p >= 13; p--){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '.';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay200ms();
    }
  for (int p = 25; p <= 36; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '.';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay200ms();
    }
  for (int p = 48; p >= 37; p--){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '.';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    delay200ms();
    }
  // pause
  delay3s();
  for (int p = 1; p <= 12; p++){ // row one /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '/';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay1s();
  for (int p = 1; p <= 12; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = ' ';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
  }
  for (int p = 13; p <= 24; p++){ // row 2 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '/';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay1s();
  for (int p = 13; p <= 24; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = ' ';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
  }
  for (int p = 25; p <= 36; p++){ // row 3 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '/';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay1s();
  for (int p = 25; p <= 36; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = ' ';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
  }
  for (int p = 37; p <= 48; p++){ // row 4 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = '/';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay1s();
  for (int p = 37; p <= 48; p++){ 
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = ' ';
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  }
// end of if statements --------------------------
}  


/*

march letters down and up columns

alphabet wipe by row column
a down
b across
c down
d across

march in circles disappear in middle

march words down rows with row offsets

slower single flap walk based on input address

use only letters
speed up dot rows

change to left to right dots at diff speeds? each row

dots run into each other from top and bottom opposite sides and then turn to slashes then blank
 */
