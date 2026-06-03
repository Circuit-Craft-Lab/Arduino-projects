#define MQ2_PIN A0
#define MQ2_DO 7

#define GREEN_LED 9
#define BLUE_LED 10
#define RED_LED 11

void setup() {
  Serial.begin(9600);

  pinMode(MQ2_DO, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.println("MQ2 Smart Air Monitoring System Started");
}

void loop() {

  int ao = analogRead(MQ2_PIN);
  int doValue = digitalRead(MQ2_DO);

  Serial.print("AO: ");
  Serial.print(ao);

  Serial.print(" | DO: ");

  if (doValue == LOW) {
    Serial.print("GAS DETECTED");
  } else {
    Serial.print("NO GAS DETECTED");
  }

  Serial.print(" | ");

  // Turn OFF all LEDs first
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);

  // AO-based smart decision
  if (ao < 30) {
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("CLEAN AIR ");
  }

  else if (ao >= 30 && ao < 300) {
    digitalWrite(BLUE_LED, HIGH);
    Serial.println("SMOKE DETECTED ");
  }

  else {
    digitalWrite(RED_LED, HIGH);
    Serial.println("GAS LEAK RISK ");
  }

  delay(3000);
}
