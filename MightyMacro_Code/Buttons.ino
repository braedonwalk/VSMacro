// Functions for Button Control

int d = 50; // Amount of time between keypresses to avoid key buffer overflows

// initButtons loops through the array of Bounce2 buttons and attaches them as inputs.
// It also sets an interval of 50ms for responsiveness
void initButtons() {

  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(50);
  }
  
}

// readButtons loops through the array of Bounce2 buttons and updates each of them.
// It then checks to see if any button has risen and calls sendKey() if it has.
void readButtons() {

  for (int i = 0; i < numButtons; i++)  {
    buttons[i].update();
    if(buttons[i].rose()){
      Serial.println("Button: " + String(i));
      sendKey(i);
    }
  }
  
}

void sendKey(int k) {

  switch (k) {
    case 0:
      newFile();
      break;
    case 1:
      openFolder();
      break;
    case 2:
      newWindow();
      break;
    case 3:
      colorTheme();
      break;
    case 4:
      settings();
      break;
    case 5:
      goToFile();
      break;
    case 6:
      ifStatement();
      break;
    case 7:
      forLoop();
      break;
    case 8:
      serializeField();
      break;
  }

  delay(1000);

}

// SHORTCUTS ~~~~~~~~~~~~~~~~~~

void newFile() {
  //  CTRL + N
  bleKeyboard.press(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.press('n');
  delay(d);
  bleKeyboard.release(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.release('n');
  delay(100);
  bleKeyboard.releaseAll();
}

void openFolder() {
  //  CTRL + K, CTRL + O
  bleKeyboard.press(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.press('k');
  delay(d);
  bleKeyboard.press('o');
  delay(d);
  bleKeyboard.release(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.release('k');
  delay(d);
  bleKeyboard.release('o');
  delay(100);
  bleKeyboard.releaseAll();
}

void newWindow(){
  //  CTRL + SHIFT + N
  bleKeyboard.press(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.press(KEY_LEFT_SHIFT);
  delay(d);
  bleKeyboard.press('n');
  delay(d);
  bleKeyboard.release(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.release(KEY_LEFT_SHIFT);
  delay(d);
  bleKeyboard.release('n');
  delay(100);
  bleKeyboard.releaseAll();
}

void colorTheme(){
  //  CTRL + K, CTRL + T
  bleKeyboard.press(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.press('k');
  delay(d);
  bleKeyboard.press('t');
  delay(d);
  bleKeyboard.release(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.release('k');
  delay(d);
  bleKeyboard.release('t');
  delay(100);
  bleKeyboard.releaseAll();
}

void settings(){
  //  CTRL + ,
  bleKeyboard.press(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.print(',');
  delay(d);
  bleKeyboard.release(KEY_LEFT_CTRL);
  delay(100);
  bleKeyboard.releaseAll();
}

void goToFile(){
  // CTRL + E
  bleKeyboard.press(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.press('e');
  delay(d);
  bleKeyboard.release(KEY_LEFT_CTRL);
  delay(d);
  bleKeyboard.release('e');
  delay(100);
  bleKeyboard.releaseAll();
}

// MACROS ~~~~~~~~~~~~~~~~

void ifStatement(){
//  bleKeyboard.print("if ( var ){");
  sendMacro("if ( var ){", d);
  delay(d);
  bleKeyboard.press(KEY_RETURN);
  delay(d);
  bleKeyboard.release(KEY_RETURN);
  delay(100);
  bleKeyboard.releaseAll();
}

void forLoop(){
  sendMacro("for ( var ){", d);
  delay(d);
  bleKeyboard.press(KEY_RETURN);
  delay(d);
  bleKeyboard.release(KEY_RETURN);
  delay(100);
  bleKeyboard.releaseAll();
}

void serializeField(){
  sendMacro("[SerializeField] ", d);
  delay(100);
  bleKeyboard.releaseAll();
}

// sends the string one character at a time.
void sendMacro(String s, int d) {
  int l = s.length() + 1;           // Determine length of string
  char c[l];                        // Create array for characters
  s.toCharArray(c, l);              // Copy characters to array
  for (int i = 0; i < l - 1; i++) { // Loop through character array
    char p = c[i];                  // Get the current character
    bleKeyboard.press(p); delay(d); // Press/Release the key w/ delay
    bleKeyboard.release(p); delay(d);
  }
  bleKeyboard.releaseAll();
}
