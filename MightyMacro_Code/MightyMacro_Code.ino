// MightyMacro Code
// ESP32-Enabled Macro Keyboard
// Braedon Walkenhorst || Sept 2022

// Buttons
#include <Bounce2.h>
//const uint8_t buttonPins[9] = {4, 5, 16, 17, 18, 19, 21, 22, 23};
const uint8_t buttonPins[9] = {21, 5, 4, 22, 18, 16, 23, 19, 17};
Bounce * buttons = new Bounce[9];
int numButtons = 9;

// Bluetooth
// Additional documentation available here:  https://github.com/T-vK/ESP32-BLE-Keyboard
#include <BleKeyboard.h>
BleKeyboard bleKeyboard("VS Macro", "Braedon W", 100);  

void setup() {
  initButtons();                      // Initialize Buttons on Startup
  initBattery();                      // Initialize Battery on Startup
  bleKeyboard.begin();                // Begin Bluetooth Connection
  Serial.begin(115200);
}

void loop() {
  if(bleKeyboard.isConnected()){      // If Bluetooth is Connected
    readButtons();                    // Read State of Buttons and Perform Functions
    updateBattery();                  // Update Battery Status if Needed
  }
}
