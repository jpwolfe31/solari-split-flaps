void phraseMenu()
{
// personal
terminal.println("@01 - ok ok ok"); 
terminal.println("@02 - hello hello andrew et al");
terminal.println("@03 - lets play cars");
terminal.println("@04 - actually not 5 minutes");
terminal.println("@05 - all day long");
terminal.println("@06 - goodnight all day");
terminal.println("@07 - what are you talking about");
terminal.println("@08 - you are not listening");
terminal.println("@09 - i tell you");

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
terminal.println("@76 - A to Z letter rain");
terminal.println("@77 - A to Z block and outline");
terminal.println("@78 - A to Z block and outline - fast");
terminal.println("@79 - one rain");
terminal.println("@80 - forty rain");
terminal.println("@81 - one snake");  // error in column 1 - same as 2 sometimes
terminal.println("@82 - A to Z column wipe");
terminal.println("@83 - 1 to 9 angle wipe");
terminal.println("@84 - two snakes");
terminal.println("@85 - 1-9 alternate letters");
terminal.println("@86 - 1 and 2 are 3 column wipe");
terminal.println("@87 - 1 and 2 are 3 angle wipe");
terminal.println("@88 - 1 and 2 are 3 two angle wipe");
terminal.println("@89 - 1, 2 and 4, 5 column wipes");

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
int phrase_lookup[21] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 21, 23, 
                         25, 26, 27, 29, 32, 33, 34, 36, 39, 40};
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
// note - blank flag set by phrase selected
phrase_num_old = phrase_num;
}

void phraseBlank()
{
if (blankFlag == 1){
  return;
  }
else{
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  return;
  }
}

void phraseDisplay()
{
if (phrase_num == 40){
  char phrase[2][64] = {"  t a o t w   h r f h o   e t   e r           d ",
                        "t a o t w    h r f h o    e t   e r            d"};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 39){
  char phrase[1][64] = {"we become   what we     contemplate             "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    }
  blankFlag = 0;
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
  blankFlag = 0;
  }
if (phrase_num == 37){
  char phrase[2][64] = {"we live in  an age when unnecessary things are  ",
                        "our only    necessities                         "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }    
if (phrase_num == 36){
  char phrase[1][64] = {"may you liveevery day ofyour life               "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 35){
  char phrase[2][64] = {"water is    relentless  in its                  ",
                        "quest       downward                            "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 34){
  char phrase[1][64] = {"showing up  is 80       percent     of life     "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 33){
  char phrase[1][64] = {"still       california  dreaming                "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 32){
  char phrase[1][64] = {"appreciate  the moment                          "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 31){
  char phrase[2][64] = {"one small   step for    man                     ",
                        "one giant   leap for    mankind                 "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 30){
  char phrase[2][64] = {"simplicity  is the      ultimate                ",
                        "sophistica-  tion                               "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 29)  {
  char phrase[1][64] = {"things are  not always  what they   seem        "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 28)  {
  char phrase[2][64] = {"the right   question is usually moreimportant   ",
                        "than the    right       answer                  "};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 27)  {
  char phrase[1][64] = {"is life     but a dream                         "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 26)  {
  char phrase[1][64] = {"every momentis a fresh  beginning               "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 25)  {
  char phrase[1][64] = {"the snow    is melting  into music              "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 24){
  char phrase[3][64] = {"when one    tugs at a   single      string      ",
                        "in nature   he finds it attached to the rest    ",
                        "of the      world                               "};
  //                     |           |           |           |           |
  for (int p = 0; p < 3; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 23)  {
  char phrase[1][64] = {"the wolf    cares not   how many thesheep be    "};
   //                    |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
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
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 21){
  char phrase[1][64] = {"art is      anything youcan get     away with   " };
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 9){
  char phrase[1][64] = {"i tell you                                      "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 8){
  char phrase[1][64] = {"you are not listening                           "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 7){
  char phrase[1][64] = {"what are    you talking about                   "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 6){
  char phrase[1][64] = {"goodnight   all day                             "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 5){
  char phrase[1][64] = {"all day long                                    "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 4){
  char phrase[1][64] = {"actually not5 minutes   12 minutes              "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 3){
  char phrase[1][64] = {"lets          play          cars                "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 2){
  char phrase[1][64] = {"hello hello andrew      austin cole kim and john"};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    } 
  blankFlag = 0;
  }
if (phrase_num == 1){
  char phrase[2][64] = {"ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ",
                        " ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok"};
  //                     |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay8s();  // 1 secoond more for this one
    } 
  blankFlag = 0;
  }

// end of quote phrases ------------------------

if (phrase_num == 71)  {
  char phrase[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    strcpy(remote_command_str, "[0040]"); //advance flaps 40
    // send command
    send_remote_command();
    delay7s();
    send_remote_command();
    } 
  blankFlag = 0;
  }
if (phrase_num == 72)  {
  char phrase[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay7s();
    strcpy(remote_command_str, "[000 ]"); // advance flaps home
    // send command
    send_remote_command();
    } 
  delay5s();
  blankFlag = 1; // set blank flag
  }
if (phrase_num == 73)  {
  // dash, dot blank walk
  char s[4];
  phraseBlank();
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
  blankFlag = 0; // clear blank flag
  }
if (phrase_num == 91){
  char phrase_a[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_a[p]);
    displayPage();
    delay7s();
    strcpy(remote_command_str, "[000 ]"); // advance flaps home
    // send command
    send_remote_command();
    delay5s();
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
    delay7s();
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
    delay7s();
    }
  strcpy(remote_command_str, "[000 ]"); // advance flaps home
  // send command
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 74)  {
  // A to Z letter wipes
  char s[4];
  // Start at blank


  
  // Start at a
  strcpy(remote_command_str, "[000a]"); // set all to a
  send_remote_command();
  delay4s(); 
  // column wipes 2-12
  // 2-b
  strcpy (remote_command_str, "[020b]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[140b]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[260b]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[380b]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 3-c  
  strcpy (remote_command_str, "[030c]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[150c]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[270c]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[390c]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 4-d
  strcpy (remote_command_str, "[040d]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[160d]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[280d]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[400d]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 5-e  
  strcpy (remote_command_str, "[050e]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[170e]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[290e]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[410e]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 6-f  
  strcpy (remote_command_str, "[060f]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[180f]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[300f]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[420f]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 7-g  
  strcpy (remote_command_str, "[070g]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[190g]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[310g]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[430g]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 8-h  
  strcpy (remote_command_str, "[080h]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[200h]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[320h]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[440h]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 9-i
  strcpy (remote_command_str, "[090i]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[210i]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[330i]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[450i]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 10-f  
  strcpy (remote_command_str, "[100j]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[220j]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[340j]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[460j]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 11-k
  strcpy (remote_command_str, "[110k]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[230k]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[350k]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[470k]");
  send_remote_command();
  delay100ms();
  delay1s();
  // 12-l  
  strcpy (remote_command_str, "[120l]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[240l]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[360l]");
  send_remote_command();
  delay100ms();
  strcpy (remote_command_str, "[480l]");
  send_remote_command();
  delay100ms();
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
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 75)  {
  // 0 to blank angle letter wipes
  char s[4];
  phraseBlank();
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
  blankFlag = 0;
  }

if (phrase_num == 76) {
  // A to Z letter rain
  // uses n1 to nq graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  for (int y = 1; y <= 26; y++){
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[y+9];
    s[3] = '\0';
    strcpy(remote_command_str, "[n"); // e.g [n10A]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay4s();
    if (y > 10) delay1s();
    if (y > 20) delay1s();
    }
  delay5s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 77) {
  // A to Z block and outline
  // uses m3 and m4 graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  strcpy(remote_command_str, "[m30a]");
  send_remote_command();
  delay4s();
  strcpy(remote_command_str, "[m40b]");
  send_remote_command();
  delay4s();
    for (int y = 3; y <= 26; y++){
    s[0] = '3';
    s[1] = '0';
    s[2] = lookup[y+9];
    s[3] = '\0';
    strcpy(remote_command_str, "[m"); // e.g [m30c]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay1s();
    y++;
    s[0] = '4';
    s[1] = '0';
    s[2] = lookup[y+9];
    s[3] = '\0';
    strcpy(remote_command_str, "[m"); // e.g [m40B]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay1s();
    }
  strcpy(remote_command_str, "[000z]"); // set all to z
  send_remote_command();
  delay3s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 78) {
  // A to Z block and outline fast
  // uses m3 and m4 graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  strcpy(remote_command_str, "[m30a]");
  send_remote_command();
  delay2s();
  strcpy(remote_command_str, "[m40b]");
  send_remote_command();
  delay2s();
    for (int y = 3; y <= 26; y++){
    s[0] = '3';
    s[1] = '0';
    s[2] = lookup[y+9];
    s[3] = '\0';
    strcpy(remote_command_str, "[m"); // e.g [m30c]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay200ms();
    y++;
    s[0] = '4';
    s[1] = '0';
    s[2] = lookup[y+9];
    s[3] = '\0';
    strcpy(remote_command_str, "[m"); // e.g [m40B]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay250ms();
    }
  strcpy(remote_command_str, "[000z]"); // set all to z
  send_remote_command();
  delay1s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 79) {
  // 1 rain
  // uses n1 to nq graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  char phrase[1][64] = {"                one         rain                "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay5s();
    } 
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay4s();
  for (int y = 1; y <= 26; y++){
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = '1';
    s[3] = '\0';
    strcpy(remote_command_str, "[n"); // e.g [n10A]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    //if (y > 10) delay1s();
    //if (y > 20) delay1s();
    }
  delay2s();
  strcpy(remote_command_str, "[000m]"); // set all to m
  send_remote_command();
  delay3s();
  strcpy(remote_command_str, "[000w]"); // set all to w
  send_remote_command();
  delay3s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 80) {
  // forty rain
  // uses n1 to nq graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  char phrase[1][64] = {"                forty       rain                "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay5s();
    } 
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay4s();
  for (int y = 1; y <= 26; y++){
    s[0] = lookup[y];
    s[1] = '4';  // advance 40
    s[2] = '0';
    s[3] = '\0';
    strcpy(remote_command_str, "[n"); // e.g [n10A]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    //if (y > 10) delay1s();
    //if (y > 20) delay1s();
    }
  delay2s();
  strcpy(remote_command_str, "[000m]"); // set all to m
  send_remote_command();
  delay3s();
  strcpy(remote_command_str, "[000w]"); // set all to w
  send_remote_command();
  delay3s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 81) {
  // one snake
  char s[4];
  char lookup[64] = " 1234567890abcdefghijklmnopqrstuvwxyz-./";  
  char selected[12][4] = {"01", "14", "27", "40", "29", "18", "07", "20", "33", "46", "35", "24"};  // up 13 down 11
  phraseBlank();
  char phrase[1][64] = {"                one        snake                "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay5s();
    } 
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay4s();
  
  // increment all by 12 times to fill across 
  int x = 0;
  for (int z = 1; z <= 12; z++){
    x++;   
    for (int y = 0; y < x; y++){
      strcpy(remote_command_str, "["); 
      strcat(remote_command_str, selected[y]); 
      strcat(remote_command_str, "31");  // increment by 1
      strcat(remote_command_str, "]");
      send_remote_command();
      delay150ms(); 
      }
    }
    
  // then increment all by 40  
  for (int z = 1; z <= 40; z++){
    for (int y = 0; y <= 11; y++){
      strcpy(remote_command_str, "["); 
      strcat(remote_command_str, selected[y]); 
      if (((12-y) + z) < 40){
        strcat(remote_command_str, "31");  // increment by 1
        strcat(remote_command_str, "]");
        send_remote_command();
        delay150ms();
        }
      if (((12-y) + z) == 40){
        strcat(remote_command_str, "0 "); // set blank
        strcat(remote_command_str, "]");
        send_remote_command();
        delay150ms();
        }
      // if over 40 do nothing as already blank
      }
    }
  // should all be blank
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 82) {
  // A to Z column wipe
  // uses e1 to e4 graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  for (int y = 1; y <= 24;){
    for (int z = 1; z <= 4; z++){
      s[0] = lookup[z];
      s[1] = '0';
      s[2] = lookup[y+9];
      s[3] = '\0';
      strcpy(remote_command_str, "[e"); // e.g [e10A]
      strcat(remote_command_str, s);  
      strcat(remote_command_str, "]");
      send_remote_command();
      if (y <= 4) delay3s();
      else delay1s();
      y++;
      }
    }
  // last two y and z
  strcpy(remote_command_str, "[e10y]");
  send_remote_command();
  strcpy(remote_command_str, "[e20y]");
  send_remote_command();
  delay1s();
  strcpy(remote_command_str, "[e30z]");
  send_remote_command();
  strcpy(remote_command_str, "[e40z]");
  send_remote_command();

  //  then all blank
  delay5s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 83) {
  // 1 to 9 angle wipe
  // uses x1 to xf - no x0 - 15 positons
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  for (int y = 1; y <= 9; y++){
    if (y % 2){ // if y is odd
      delay150ms(); // need extra delay when repeating device address
      for (int z = 1; z <= 15; z++){
        if (z == 1) delay150ms(); 
        s[0] = lookup[z];
        s[1] = '0';
        s[2] = lookup[y];
        s[3] = '\0';
        strcpy(remote_command_str, "[x"); // e.g [x101]
        strcat(remote_command_str, s);  
        strcat(remote_command_str, "]");
        send_remote_command();
        delay150ms();
        }
      }
    else{ // y is even
      delay150ms(); // need extra delay when repeating device address
      for (int w = 15; w >= 1; w--){ // reverse e.g. [xf02]
        s[0] = lookup[w];
        s[1] = '0';
        s[2] = lookup[y];
        s[3] = '\0';
        strcpy(remote_command_str, "[x"); // e.g [xf01]
        strcat(remote_command_str, s);  
        strcat(remote_command_str, "]");
        send_remote_command();
        delay150ms();
        }
      }    
    }
  //  then all blank
  delay3s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 84) {
  // two snakes
  char s[4];
  char lookup[64] = " 1234567890abcdefghijklmnopqrstuvwxyz-./";  
  char selected1[12][4] = {"01", "14", "03", "16", "05", "18", "07", "20", "09", "22", "11", "24"};  // up 13 down 11
  char selected2[12][4] = {"25", "38", "27", "40", "29", "42", "31", "44", "33", "46", "35", "48"};  // up 13 down 11
  phraseBlank();
  char phrase[1][64] = {"                two        snakes               "};
  //                     |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase[p]);
    displayPage();
    delay5s();
    } 
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  blankFlag = 1; // set blank flag
  delay4s();
  
  // fill 1s then blanks across 
  for (int y = 0; y < 29; y++){ // 12 plus 12 plus 5 or 5 plus 12 plus 12
    // snake 1
    if (y <= 11){ // 0 to 11 1s
      strcpy(remote_command_str, "["); 
      strcat(remote_command_str, selected1[y]);  // fill with 1s
      strcat(remote_command_str, "01]");
      }
    if (y >= 12){ // 12 to 23 spaces
      strcpy(remote_command_str, "["); 
      strcat(remote_command_str, selected1[y-12]);  // fill with spaces
      strcat(remote_command_str, "0 ]");
      }
    if (y >= 24){ // 24 to 28 waits
      strcpy(remote_command_str, "[990 ]");
      }
    send_remote_command();
    delay150ms();
    // snake 2
    if (y <= 4){ // 0 to 4 waits
      strcpy(remote_command_str, "[990 ]");
      }
    if (y >= 5){ // 5 to 16 2s
      strcpy(remote_command_str, "["); 
      strcat(remote_command_str, selected2[y-5]);  // fill with 2s
      strcat(remote_command_str, "02]");
      }
    if (y >= 17){ // 17 to 28 spaces
      strcpy(remote_command_str, "["); 
      strcat(remote_command_str, selected2[y-17]);  // fill with spaces
      strcat(remote_command_str, "0 ]");
      }
    send_remote_command();
    delay150ms(); 
    }
  // should all be blank
  blankFlag = 1; // set blank flag
  }
if (phrase_num == 85) {
  // 1-9 alternate letters
  // uses m1 and m2 graphic decode
  char s[4];
  char lookup[64] = " 1234567890abcdefghijklmnopqrstuvwxyz-./";
  phraseBlank();
  for (int y = 1; y <= 9; y++){
    if (y % 2){ // if y is odd
      delay150ms(); // need extra delay when repeating device address
      s[0] = '0';
      s[1] = lookup[y];
      s[2] = '\0';
      strcpy(remote_command_str, "[m1"); // e.g [m101]
      strcat(remote_command_str, s);  
      strcat(remote_command_str, "]");
      send_remote_command();
      delay150ms();
      }
    else{ // y is even
      delay150ms(); // need extra delay when repeating device address
      s[0] = '0';
      s[1] = lookup[y];
      s[2] = '\0';
      strcpy(remote_command_str, "[m2"); // e.g [m202]
      strcat(remote_command_str, s);  
      strcat(remote_command_str, "]");
      send_remote_command();
      delay150ms();
      }
    }
  //  then all blank
  delay3s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
}

if (phrase_num == 86) {
  // 1 and 2 are 3 column wipe
  // uses c1 to cc graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  for (int y = 1; y <= 6; y++){
    // display 1
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[1];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [c101]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    // display 2
    s[0] = lookup[13-y];
    s[1] = '0';
    s[2] = lookup[2];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [cc02]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    }
    for (int y = 6; y >= 1; y--){
    // display 3 left
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[3];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [c603]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    // display 3 right
    s[0] = lookup[13-y];
    s[1] = '0';
    s[2] = lookup[3];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [c703]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    }
  //then to o
  delay5s();
  strcpy(remote_command_str, "[000o]");  // set ll to o
  send_remote_command();
  //  then all blank
  delay4s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 87) {
  // 1 and 2 are 3 angle wipe
  // uses x1 to xf graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  for (int y = 1; y <= 7; y++){
    // display 1
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[1];
    s[3] = '\0';
    strcpy(remote_command_str, "[x"); // e.g [x101]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    //delay500ms();
    // display 2
    s[0] = lookup[16-y];
    s[1] = '0';
    s[2] = lookup[2];
    s[3] = '\0';
    strcpy(remote_command_str, "[x"); // e.g [xf02]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    }
    // display middle 3 (at position 8)
    s[0] = lookup[8];
    s[1] = '0';
    s[2] = lookup[3];
    s[3] = '\0';
    strcpy(remote_command_str, "[x"); // e.g [x803]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    // disply balance of 3s
    // isplay 3 left
    for (int y = 7; y >= 1; y--){
    // display 3 left
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[3];
    s[3] = '\0';
    strcpy(remote_command_str, "[x"); // e.g [x703]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    //delay500ms();
    // display 3 right
    s[0] = lookup[16-y];
    s[1] = '0';
    s[2] = lookup[3];
    s[3] = '\0';
    strcpy(remote_command_str, "[x"); // e.g [x903]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    }
  //then to 0
  delay5s();
  strcpy(remote_command_str, "[000o]");  // set to o
  send_remote_command();
  //  then all blank
  delay4s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 88) {
  // 1 and 2 are 3 two angle wipe
  // uses x1 to xf and yf to y1 graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  // first phase until meet
  for (int y = 1; y <= 6; y++){
    // display 1
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[1];
    s[3] = '\0';
    strcpy(remote_command_str, "[x"); // e.g [x101]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    // display 2
    s[0] = lookup[16-y];
    s[1] = '0';
    s[2] = lookup[2];
    s[3] = '\0';
    strcpy(remote_command_str, "[y"); // e.g [yf02]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay750ms(); // 750ms is min due to quick device address repeats
    }
    // position 7 (first meet)
    // from left
    strcpy(remote_command_str, "[0773]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[1871]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[2971]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[4071]"); // requires later commit
    send_remote_command();
    // from right
    strcpy(remote_command_str, "[0673]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[1972]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[3272]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[4572]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[0089]"); // commit
    send_remote_command();
    delay750ms();
    // position 8
    // from left
    strcpy(remote_command_str, "[0873]"); // requires later commit
    send_remote_command();
    // need delay for prior 19 to allow for flapping
    strcpy(remote_command_str, "[1973]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[3071]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[4171]"); // requires later commit
    send_remote_command();
    // from right
    strcpy(remote_command_str, "[0573]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[1873]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[3172]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[4472]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[0089]"); // commit
    send_remote_command();
    delay750ms();
    // position 9
    // from left
    strcpy(remote_command_str, "[0973]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[2073]"); // requires later commit
    send_remote_command();
    // need delay for prior 31 to allow for flapping
    strcpy(remote_command_str, "[3173]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[4271]"); // requires later commit
    send_remote_command();
    // from right
    strcpy(remote_command_str, "[0473]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[1773]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[3073]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[4372]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[0089]"); // commit
    send_remote_command();
    delay750ms();
    // position 10 (last meet)
    // from left
    strcpy(remote_command_str, "[1073]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[2173]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[3273]"); // requires later commit
    send_remote_command();
    // need delay for prior 19 to allow for flapping
    strcpy(remote_command_str, "[4373]"); // requires later commit
    send_remote_command();
    // from right
    strcpy(remote_command_str, "[0373]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[1673]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[2973]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[4273]"); // requires later commit
    send_remote_command();
    strcpy(remote_command_str, "[0089]"); // commit
    send_remote_command();
    delay750ms();
    // disply balance of 3s
    // display 3 left
    for (int y = 11; y <= 15; y++){
      // display 3 left
      s[0] = lookup[y];
      s[1] = '0';
      s[2] = lookup[3];
      s[3] = '\0';
      strcpy(remote_command_str, "[x"); // e.g [xb03]
      strcat(remote_command_str, s);  
      strcat(remote_command_str, "]");
      send_remote_command();
      // display 3 right
      s[0] = lookup[16-y];
      s[1] = '0';
      s[2] = lookup[3];
      s[3] = '\0';
      strcpy(remote_command_str, "[y"); // e.g [y503]
      strcat(remote_command_str, s);  
      strcat(remote_command_str, "]");
      send_remote_command();
      delay750ms();
    }
  //then to 0
  delay5s();
  strcpy(remote_command_str, "[000o]");  // set to o
  send_remote_command();
  //  then all blank
  delay4s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

if (phrase_num == 89) {
  // 1,2 and 4, 5 column wipe
  // uses c1 to cc graphic decode
  char s[4];
  char lookup[64] = "0123456789abcdefghijklmnopqrstuvwxyz-./ ";
  phraseBlank();
  for (int y = 1; y <= 6; y++){
    // display 1
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[1];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [c101]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    // display 2
    s[0] = lookup[13-y];
    s[1] = '0';
    s[2] = lookup[2];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [cc02]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    }
    for (int y = 6; y >= 1; y--){
    // display 3 left
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[3];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [c603]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    // display 3 right
    s[0] = lookup[13-y];
    s[1] = '0';
    s[2] = lookup[3];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [c703]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    }
  // 4 and 5 are 9 column wipe
  for (int y = 1; y <= 6; y++){
    // display 1
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[4];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [c104]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    // display 2
    s[0] = lookup[13-y];
    s[1] = '0';
    s[2] = lookup[5];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [cc05]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    }
    for (int y = 6; y >= 1; y--){
    // display 9 left
    s[0] = lookup[y];
    s[1] = '0';
    s[2] = lookup[9];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [c609]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    // display 9 right
    s[0] = lookup[13-y];
    s[1] = '0';
    s[2] = lookup[9];
    s[3] = '\0';
    strcpy(remote_command_str, "[c"); // e.g [c709]
    strcat(remote_command_str, s);  
    strcat(remote_command_str, "]");
    send_remote_command();
    delay500ms();
    }
  //then to o
  delay5s();
  strcpy(remote_command_str, "[000o]");  // set ll to o
  send_remote_command();
  //  then all blank
  delay4s();
  strcpy(remote_command_str, "[000 ]"); // set all to blank
  send_remote_command();
  delay5s();
  blankFlag = 1; // set blank flag
  }

// end of if statements --------------------------

}  // end of void phraseDisplay()


// possible future use??
// Easy way to convert A to 0, B to 1, etc. or 10, 11, etc.
// char letter = 'E'; // could be any upper or lower case letter
// char str[2] = { letter }; // make a string out of the letter
// int num = strtol( str, NULL, 36 ) - 10;  // convert the letter to a number (a = 0)
// The reason this works can be found in the man page for strtol which states:
// (In bases above 10, the letter 'A' in either upper or lower case represents 10, 
// 'B' represents 11, and so forth, with 'Z' representing 35.)
// So passing 36 to strtol as the base tells strtol to convert 'A' or 'a' to 10, 
// 'B' or 'b' to 11, and so on.  

/*
split flap ideas

1 and 2 converge to 3
then by row do 4 5 etc and the go to blank for the letters to go off to the side

converge columns to start then angles?? more difficult may not be able to use remote graphics
but have set and commit

rain down 40 advance
corner to corner 40 advance then opposite corner back

columns letters right left and growing column sizes tuntil xy then blank

more art of the word play

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
