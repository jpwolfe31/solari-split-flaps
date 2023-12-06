

void phraseMenu()
{
// personal
terminal.println("@01 - ok ok ok"); 
terminal.println("@02 - hello hello andrew et al");

// graphic
terminal.println("@11 - num alpha num then +40"); 
terminal.println("@12 - num alpha num then blank");
terminal.println("@13 - dash dot blank walk");

// quotes
terminal.println("@21 - art is anything - aw"); 
terminal.println("@22 - you cant always get - rs"); 
terminal.println("@23 - the wolf cares not - plato"); 
terminal.println("@24 - when one tugs - jm"); 
terminal.println("@25 - the snow is melting into -jm"); 
terminal.println("@26 - every momment - tse"); 
terminal.println("@27 - is life but a dream"); 

// description
terminal.println("@40 - youtube narration display");
terminal.println(); // add line feed
terminal.flush();
Blynk.run();
return;
}

void phraseDisplay()
{
if (phrase_num == 22){
  char phrase_22[5][64] = {"you cant    always get  what you    want        ",
                          " you cant    always get  what you    want       ",
                          "but if you  try         sometimes               ",
                          "you just    might find                          ",
                          "you get     what you    need.....               "};
  //                       |           |           |           |           |
  for (int p = 0; p < 5; p++){  
    strcpy(display_str, phrase_22[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 24){
  char phrase_24[3][64] = {"when one    tugs at a   single      string      ",
                           "in nature   he finds it attached to the rest    ",
                           "of the      world                               "};
  //                        |           |           |           |           |
  for (int p = 0; p < 3; p++){  
    strcpy(display_str, phrase_24[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 25)  {
  char phrase_25[1][64] = {"the snow    is melting  into music              "};
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_25[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 1)  {
  char phrase_1[2][64] = {"ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ",
                          " ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok ok"};
  //                       |           |           |           |           |
  for (int p = 0; p < 2; p++){  
    strcpy(display_str, phrase_1[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(5000); // a bit more for this one
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 21)  {
  char phrase_21[1][64] = {"art is      anything youcan get     away with   " };
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_21[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 2)  {
  char phrase_2[1][64] = {"hello hello andrew      austin cole kim and john"};
  //                       |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_2[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 11)  {
  char phrase_11[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_11[p]);
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

if (phrase_num == 12)  {
  char phrase_12[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_12[p]);
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

if (phrase_num == 23)  {
  char phrase_23[1][64] = {"the wolf    cares not   how many thesheep be    "};
   //                       |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_23[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 26)  {
  char phrase_26[1][64] = {"every momentis a fresh  beginning               "};
  //                       |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_26[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 27)  {
  char phrase_27[1][64] = {"is life     but a dream                         "};
  //                       |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_27[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 13)  {
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

if (phrase_num == 40){
  
  char phrase_12[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                        |           |           |           |           |
  for (int p = 0; p < 1; p++){  
    strcpy(display_str, phrase_12[p]);
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
  
  char phrase_40[12][64] = {"This is a   Solari      split-flap  display.    ",
                            "We were toldthe split-  flaps were  installed at",
                            "an airport  in the      1960s.                  ",
                            "We purchasedthe split-  flaps on    ebay.       ",
                            "These split-flaps       represent   a small     ",
                            "portion of  the originaldisplay.                ",
                            "The         electronics that controlthe display ",
                            "are new and contained   in the      black case  ",
                            "next to the time        display.                ",  
                            "For more    information on these    devices     ",
                            "and the codeand         electonics  used see    ",
                            "www.github  .com/jpwolfe31/solari-  split-flaps "};
  //                         |           |           |           |           |
  for (int p = 0; p < 12; p++){  
    strcpy(display_str, phrase_40[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    Blynk.run();  // prevent Blynk app timeout
    } 
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
  }
// end of if statements
}  


/*



ok ok ok ok
I have woken

hello andrew

aliens exist
- I saw some
yesterday…

a party without cake is just a meeting

I need ai

dare to begin

still california dreaming

you cant always get what you want
but if you try sometimes
you might just find
you get what you need

Happiness Is Choice

Appreciate the moment

Happiness is homemade

Seize the day.

Let it go.

is Life But a Dream

Simplicity is the ultimate sophistication leonardo da vinci

4. “Die with memories, not dreams.”
- Tiny Buddha
5. “Every moment’s a fresh beginning.”
- T.S. Eliot

Art is anything you can get away with.”
Andy Warhol

I am a deeply superficial person.” 
Andy Warhol

That is one of my favourite things to say. So what.”
Andy Warhol

In the future, everyone will be world-famous for 15 minutes.”

No one is more hated than he who speaks the truth.
Plato

The right question is usually more important than the right answer.
Plato

We become what we contemplate.
Plato

the stars are just beautiful.
Plato

The wolf cares not, how many the sheep be.
Plato

hello andrew, austin
cole
kim and john

march letters
march all characters

march letters accross blank screen
for i = 1i <= 48 shift
just shift string right this increments 1 and the fills with blanks

march letters down and up columns

This is a Solari split flap display. I was told they were installed at an airport 
in the 1960s. I purchased the split flaps on ebay. This represents a small portion 
of the original display. The electronics that control the display are new 
and in the black box next to the time display. For more information on these devices 
and the electronics used see www.github/jpwolfe/solari-split-flap.

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
the / each row down then blank maybe fill each row blank after display

//change to left to right dots at diff speeds? each row

take the last train to clarksville
Take the last train to Clarksville
And I'll meet you at the station
You can be here by 4:30
Cause I've made your reservation

Things are not always what they seem.

The first appearance deceives many; the intelligence of a few perceives what has been carefully hidden. - Phaerdrus

When one tugs at a single thing in nature, he finds it attached to the rest of the world. John Muir

The snow is melting into music.   John Muir

Water is relentless in its quest downward.   John Muir

May you live every day of your life. Jonathan Swift 

We live in an age when unnecessary things are our only necessities. Oscar Wilde

The art of being wise is knowing what to overlook.  William James


The more we do, the more we can do. William Hazlitt

Showing up is 80 percent of life. Woody Allen

one small step for man, one giant leap for mankind  neal armstrong

rock and roll might not solve your problems, but it does let you dance all over them. pete townsend

 */
