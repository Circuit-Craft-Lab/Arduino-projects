#define trigPin 6
#define echoPin 10

long duration;
float distance;

void setup() {
Serial.begin(9600);

pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop() {

// Clear trigger
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Send 10 microsecond pulse
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Read echo time
duration = pulseIn(echoPin, HIGH);

// Decode distance
distance = duration * 0.0343 / 2;

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

delay(500);
}
