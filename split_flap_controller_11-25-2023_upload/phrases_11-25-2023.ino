void phraseMenu()
{
// personal
terminal.println("@01 - ok ok ok"); 

// graphic
terminal.println("@11 - num alpha num then +40"); 
terminal.println("@12 - num alpha num then blank");
terminal.println("@13 - dash dot blank walk");

// quotes
terminal.println("@21 - art is anything"); 
terminal.println("@22 - you cant always get"); 
terminal.println("@23 - the wolf cares not"); 
terminal.println("@24 - when one tugs"); 
terminal.println("@25 - the snow is melting into"); 
terminal.println("@26 - every momment"); 
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
if (phrase_num == 40){
  char phrase_40[10][64] = {"This is a   Solari      split-flap  display.    ",
                            "I was told  the split-  flaps were  installed at",
                            "an airport  in the      1960s.      I purchased ",
                            "the split-  flaps on    ebay.  This represents  ",
                            "a small     portion of  the originaldisplay.    ",
                            "The         electronics that controlthe display ",
                            "are new and in the blackbox next to the time    ",
                            "display.    For more    information on these    ",
                            "devices and the         electonics  used see    ",
                            "www.github  .com/jpwolfe/solari-    split-flaps "};
  //                         |           |           |           |           |
  for (int p = 0; p < 11; p++){  
    strcpy(display_str, phrase_40[p]);
    displayPage();
    WDTimer.clear();  // refresh watch dog timer
    delay(4000);
    WDTimer.clear();  // refresh watch dog timer
    delay(3000);
    WDTimer.clear();  // refresh watch dog timer
    } 
  }

if (phrase_num == 22){
  char phrase_22[5][64] = {"you cant    always get  what you    want        ",
                          " you cant    always get  what you    want       ",
                          "but if you  try         sometimes               ",
                          "you just    might find                          ",
                          "you get     what you    need.....           -rs "};
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
                           "of the      world                           -jm "};
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
  char phrase_25[1][64] = {"the snow    is melting  into music          -jm "};
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
  char phrase_21[1][64] = {"art is      anything youcan get     away with-aw"};
  //                       |           |           |           |           |
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

if (phrase_num == 11)  {
  char phrase_11[1][64] = {"1234567890abcdefghijklmnopqrstuvwxyz1234567890  "};
  //                       |           |           |           |           |
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
  //                       |           |           |           |           |
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
  char phrase_23[1][64] = {"the wolf    cares not   how many thesheep be -p "};
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
  }
// end of if statements
}  
