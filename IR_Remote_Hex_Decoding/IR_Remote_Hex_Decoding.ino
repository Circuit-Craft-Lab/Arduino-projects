#include <IRremote.hpp>

#define IR_PIN 5

void setup() {
  Serial.begin(9600);

  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("IR HEX Reader Ready");
}

void loop() {

  if (IrReceiver.decode()) {

    // Print HEX code of button
    Serial.print("HEX Code: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    IrReceiver.resume(); // ready for next signal
  }
}
