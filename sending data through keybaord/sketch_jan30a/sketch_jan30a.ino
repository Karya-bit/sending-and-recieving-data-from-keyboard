/*  PS2Keyboard library, International Keyboard Layout Example
    http://www.pjrc.com/teensy/td_libs_PS2Keyboard.html

    keyboard.begin() accepts an optional 3rd parameter to
    configure the PS2 keyboard layout.  Uncomment the line for
    your keyboard.  If it doesn't exist, you can create it in
    PS2Keyboard.cpp and email paul@pjrc.com to have it included
    in future versions of this library.
*/
   
#include <PS2Keyboard.h>
#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK rf_driver;

const int DataPin = 2;
const int IRQpin =  3;

PS2Keyboard keyboard;

void setup() {
  //keyboard.begin(DataPin, IRQpin, PS2Keymap_US);
  keyboard.begin(DataPin, IRQpin, PS2Keymap_German);
  //keyboard.begin(DataPin, IRQpin, PS2Keymap_French);
  //keyboard.begin(DataPin, IRQpin, PS2Keymap_Spanish);
  //keyboard.begin(DataPin, IRQpin, PS2Keymap_Italian);
  //keyboard.begin(DataPin, IRQpin, PS2Keymap_UK);

  rf_driver.init();
  
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
}

void loop() {
  if (keyboard.available()) {
    char c = keyboard.read();
    Serial.println(c);
    const char *msg = "longitude latitude altitude and time";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(10);
  }
}
