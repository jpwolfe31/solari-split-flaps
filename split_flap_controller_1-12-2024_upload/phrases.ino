

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
terminal.println("@40 - the art of the word (vert)");

// graphic
terminal.println("@71 - num alpha num then +40");
terminal.println("@72 - num alpha num then blank");
terminal.println("@73 - dash dot blank walk");
terminal.println("@74 - A to Z letter wipes");
terminal.println("@75 - 0 to blank angle letter wipes");

// Easy way to convert A to 0, B to 1, etc. or 10, 11, etc.
// char letter = 'E'; // could be any upper or lower case letter
// char str[2] = { letter }; // make a string out of the letter
// int num = strtol( str, NULL, 36 ) - 10;  // convert the letter to a number (a = 0)
// The reason this works can be found in the man page for strtol which states:
// (In bases above 10, the letter 'A' in either upper or lower case represents 10, 
// 'B' represents 11, and so forth, with 'Z' representing 35.)
// So passing 36 to strtol as the base tells strtol to convert 'A' or 'a' to 10, 
// 'B' or 'b' to 11, and so on.  






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
int phrase_lookup[21] = {1, 2, 21, 23, 25, 26, 27, 29, 
                           32, 33, 34, 36, 39};
int number_phrases = 13;
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
if (phrase_num == 40){
  char phrase[1][64] = {"  t a o t w   h r f h o   e t   e r           d "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  }
if (phrase_num == 39){
  char phrase[1][64] = {"we become   what we     contemplate             "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  }
if (phrase_num == 38){
  char phrase[2][64] = {"the art of  being wise  is knowing              ",
                        "what to     overlook                            "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  }
if (phrase_num == 37){
  char phrase[2][64] = {"we live in  an age when unnecessary things are  ",
                        "our only    necessities                         "};
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
  char phrase[1][64] = {"may you liveevery day ofyour life               "};
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
                        "quest       downward                            "};
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
  char phrase[1][64] = {"showing up  is 80       percent     of life     "};
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
  char phrase[1][64] = {"still       california  dreaming                "};
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
  char phrase[1][64] = {"appreciate  the moment                          "};
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
                        "one giant   leap for    mankind                 "};
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
                        "sophistica-  tion                               "};
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
  char phrase[1][64] = {"things are  not always  what they   seem        "};
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
                        "than the    right       answer                  "};
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
  char phrase[1][64] = {"is life     but a dream                         "};
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
  char phrase[1][64] = {"every momentis a fresh  beginning               "};
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
  char phrase[1][64] = {"the snow    is melting  into music              "};
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
                        "of the      world                               "};
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
  char phrase[1][64] = {"the wolf    cares not   how many thesheep be    "};
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
  char phrase[1][64] = {"art is      anything youcan get     away with   " };
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

if (phrase_num == 74)  {
  // A to Z letter wipes
  char s[4];
  // Start at blank
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  // Start at a
  strcpy(remote_command_str, "[000a]"); // set all to a
  send_remote_command();
  delay4s(); 
  
  // column wipes 2-12
  // 2-b
  strcpy (remote_command_str, "[020b]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[140b]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[260b]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[380b]");
  send_remote_command();
  delay (100);
  delay1s();
  // 3-c  
  strcpy (remote_command_str, "[030c]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[150c]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[270c]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[390c]");
  send_remote_command();
  delay (100);
  delay1s();
  // 4-d
  strcpy (remote_command_str, "[040d]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[160d]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[280d]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[400d]");
  send_remote_command();
  delay (100);
  delay1s();
  // 5-e  
  strcpy (remote_command_str, "[050e]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[170e]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[290e]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[410e]");
  send_remote_command();
  delay (100);
  delay1s();
  // 6-f  
  strcpy (remote_command_str, "[060f]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[180f]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[300f]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[420f]");
  send_remote_command();
  delay (100);
  delay1s();
  // 7-g  
  strcpy (remote_command_str, "[070g]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[190g]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[310g]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[430g]");
  send_remote_command();
  delay (100);
  delay1s();
  // 8-h  
  strcpy (remote_command_str, "[080h]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[200h]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[320h]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[440h]");
  send_remote_command();
  delay (100);
  delay1s();
  // 9-i
  strcpy (remote_command_str, "[090i]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[210i]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[330i]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[450i]");
  send_remote_command();
  delay (100);
  delay1s();
  // 10-f  
  strcpy (remote_command_str, "[100j]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[220j]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[340j]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[460j]");
  send_remote_command();
  delay (100);
  delay1s();
  // 11-k
  strcpy (remote_command_str, "[110k]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[230k]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[350k]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[470k]");
  send_remote_command();
  delay (100);
  delay1s();
  // 12-l  
  strcpy (remote_command_str, "[120l]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[240l]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[360l]");
  send_remote_command();
  delay (100);
  strcpy (remote_command_str, "[480l]");
  send_remote_command();
  delay (100);
  delay3s();
  // wipe left to right
  for (int p = 1; p <= 12; p++){ // row 1
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = 'm';  // letter displayed
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay2s();
  for (int p = 13; p <= 24; p++){ // row 2
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = 'n';  // letter displayed
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay2s();
  for (int p = 25; p <= 36; p++){ // row 3 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = 'o';  // leter displayed
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay2s();
  for (int p = 37; p <= 48; p++){ // row 4 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = 'p';  // letter dispalyed
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay3s();
  // blank
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay4s();
  // Diaganol
  // 1 down
  strcpy (remote_command_str, "[010q]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[140q]");  // +13
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[270q]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[400q]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[290q]"); // - 11
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[180q]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[070q]");  
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[200q]"); // +13
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[330q]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[460q]"); 
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[350q]"); // -11
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[240q]");
  send_remote_command();
  delay (50);
  delay4s();

  // 1 down
  strcpy (remote_command_str, "[010r]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[140r]");  // +13
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[270r]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[400r]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[290r]"); // - 11
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[180r]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[070r]");  
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[200r]"); // +13
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[330r]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[460r]"); 
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[350r]"); // -11
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[240r]");
  send_remote_command();
  delay (50);
  delay2s();

  // 1 down
  strcpy (remote_command_str, "[010s]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[140s]");  // +13
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[270s]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[400s]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[290s]"); // - 11
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[180s]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[070s]");  
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[200s]"); // +13
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[330s]");
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[460s]"); 
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[350s]"); // -11
  send_remote_command();
  delay (50);
  strcpy (remote_command_str, "[240s]");
  send_remote_command();
  delay (50);
  delay4s();
  
  /*// 2 down
  strcpy (remote_command_str, "[130o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[260o]"); // +13 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[390o]");
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[280o]"); // - 11
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[170o]");
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[060o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[190o]"); // +13
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[320o]");
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[450o]");  
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[340o]"); // -11
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[230o]");  
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[120o]");
  send_remote_command();
  delay (200);
  delay2s();
  // 3 up
  strcpy (remote_command_str, "[250o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[140o]"); // - 11
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[030o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[160o]"); // +13
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[290o]");
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[420o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[310o]"); // -11
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[200o]");
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[090o]");  
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[220o]"); // +13
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[350o]");  
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[480o]");
  send_remote_command();
  delay (200);
  delay2s();
  // 4 up
  strcpy (remote_command_str, "[370o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[260o]"); // - 11
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[150o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[040o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[170o]"); // +13
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[300o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[430o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[320o]"); // -11
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[210o]");  
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[100o]"); 
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[230o]");  // +13
  send_remote_command();
  delay (200);
  strcpy (remote_command_str, "[360o]");
  send_remote_command();
  delay (200);
  delay2s();
  */
  // wipe left to right
  for (int p = 1; p <= 12; p++){ // row 1
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = 't';  // letter displayed
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay5s();
  for (int p = 13; p <= 24; p++){ // row 2
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = 'u';  // letter displayed
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay5s();
  for (int p = 25; p <= 36; p++){ // row 3 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = 'v';  // leter displayed
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay5s();
  for (int p = 37; p <= 48; p++){ // row 4 /
    sprintf(s,"%02d", p); // zero indicates padding leading 0s
    remote_command_str[0] = '[';  // format should be "[aadd]\0"
    remote_command_str[1] = s[0];
    remote_command_str[2] = s[1];
    remote_command_str[3] = '0';  // 0 is letter display
    remote_command_str[4] = 'w';  // letter dispalyed
    remote_command_str[5] = ']';  // end character
    remote_command_str[6] = '\0';  // terminate string
    send_remote_command();
    }
  delay7s();
  // all x
  strcpy (remote_command_str, "[000x]"); 
  send_remote_command();
  delay2s();
  // all y
  strcpy (remote_command_str, "[000y]"); 
  send_remote_command();
  delay2s();
  // all z
  strcpy (remote_command_str, "[000z]"); 
  send_remote_command();
  delay4s();
  // all blank
  strcpy (remote_command_str, "[000 ]"); 
  send_remote_command();
  }

if (phrase_num == 75)  {
  // 0 to blank angle letter wipes
  char s[4];
  // Start at blank
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  //1 down to 2
  //2 up to 3  
  //3 up to 4
  //4 up to 3
  //2 down to 1
  //3 down to 2

  // 1 down to 2 angle
  for (int p = 1; p <= 40; p++){
    strcpy (remote_command_str, "[0131]");  // 31 is increment by one
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[1431]");  // +13
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[2731]");
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[4031]");
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[2931]"); // - 11
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[1831]");
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[0731]");  
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[2031]"); // +13
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[3331]");
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[4631]"); 
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[3531]"); // -11
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[2431]");
    send_remote_command();
    delay (20);
    delay500ms();
    }
  // 1 down to 2 angle
  for (int p = 1; p <= 40; p++){
    strcpy (remote_command_str, "[0131]");  // 31 is increment by one
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[1431]");  // +13
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[2731]");
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[4031]");
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[2931]"); // - 11
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[1831]");
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[0731]");  
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[2031]"); // +13
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[3331]");
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[4631]"); 
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[3531]"); // -11
    send_remote_command();
    delay (10);
    strcpy (remote_command_str, "[2431]");
    send_remote_command();
    delay (10);
    delay200ms();
    }
  
  // 3 up to 4 angle
  for (int p = 1; p <= 40; p++){
    strcpy (remote_command_str, "[2531]"); 
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[1431]"); // - 11
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[0331]"); 
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[1631]"); // +13
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[2931]");
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[4231]"); 
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[3131]"); // -11
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[2031]");
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[0931]");  
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[2231]"); // +13
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[3531]");  
    send_remote_command();
    delay (20);
    strcpy (remote_command_str, "[4831]");
    send_remote_command();
    delay (20);
    delay500ms();
    }
  // 3 up to 4 angle
  for (int p = 1; p <= 40; p++){  
    // issue of stopping at j due to 75ms delay instead of 200ms
    strcpy (remote_command_str, "[2531]"); 
    send_remote_command();
    delay (5);  // 5ms is not too fast 
    strcpy (remote_command_str, "[1431]"); // - 11
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[0331]"); 
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[1631]"); // +13
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[2931]");
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[4231]"); 
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[3131]"); // -11
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[2031]");
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[0931]");  
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[2231]"); // +13
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[3531]");  
    send_remote_command();
    delay (5);
    strcpy (remote_command_str, "[4831]");
    send_remote_command();
    delay (5);
    delay200ms(); // 75ms was too fast
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
