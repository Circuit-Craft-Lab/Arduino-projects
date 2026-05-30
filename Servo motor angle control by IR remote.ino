#include <IRremote.hpp>
#include <Servo.h>

#define IR_PIN 5

Servo myservo;

void setup() {
  Serial.begin(9600);

  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

  myservo.attach(9);
  myservo.write(90);   // start center position
}

void loop() {

  if (IrReceiver.decode()) {

    unsigned long value = IrReceiver.decodedIRData.decodedRawData;

    Serial.println(value, HEX);

    // ====== BUTTON 1 ======
    if (value == 0xFD02BF00) {   // replace with your HEX
      myservo.write(0);
    }
        // ====== BUTTON 7 ======
    if (value == 0xF708BF00) {   // replace with your HEX
      myservo.write(180);
     }
    IrReceiver.resume();
  }
}
