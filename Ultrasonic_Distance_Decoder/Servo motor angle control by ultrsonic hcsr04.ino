#include <Servo.h>

Servo servo;

int trig = 6;
int echo = 10;

long time;
int distance;
int angle;

void setup() {

servo.attach(8);

pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

Serial.begin(9600);
}

void loop() {

// Send ultrasonic wave
digitalWrite(trig, LOW);
delayMicroseconds(2);

digitalWrite(trig, HIGH);
delayMicroseconds(10);

digitalWrite(trig, LOW);

// Receive reflected wave time
time = pulseIn(echo, HIGH);

// Convert time into distance
distance = time / 58;

// Convert distance into servo angle

if(distance < 10) angle = 180;
else if(distance < 20) angle = 120;
else if(distance < 30) angle = 60;
else if(distance > 30) angle = 0;
// Move servo
servo.write(angle);

// Show values
Serial.print("Distance = ");
Serial.print(distance);

Serial.print(" Angle = ");
Serial.println(angle);

delay(100);
}




EXPLANATION 
#include <Servo.h>

Servo servo;

int trig = 9;
int echo = 10;

long time;
int distance;
int angle;

void setup() {

servo.attach(6);

pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

Serial.begin(9600);
}

void loop() {

// Send ultrasonic wave
digitalWrite(trig, LOW);
delayMicroseconds(2);

digitalWrite(trig, HIGH);
delayMicroseconds(10);

digitalWrite(trig, LOW);

// Receive reflected wave time
time = pulseIn(echo, HIGH);

// Convert time into distance
distance = time / 58;

// Convert distance into servo angle
angle = map(distance, 5, 40, 180, 0);

// Move servo
servo.write(angle);

// Show values
Serial.print("Distance = ");
Serial.print(distance);

Serial.print(" Angle = ");
Serial.println(angle);

delay(100);
}













This line:
C++
angle = map(distance, 5, 40, 180, 0);
means:
Convert the sensor distance value into a servo motor angle.
Understanding map()
Arduino map() function changes one range into another range.
General format:
C++
map(value, fromLow, fromHigh, toLow, toHigh)
Your Code Meaning
C++
map(distance, 5, 40, 180, 0)
means:
Part
Meaning
distance
Input value from sensor
5
Minimum distance
40
Maximum distance
180
Servo angle when object is near
0
Servo angle when object is far
Simple Logic
Distance
Servo Angle
5 cm
180°
10 cm
about 154°
20 cm
about 103°
30 cm
about 51°
40 cm
0°
So:
Plain text
Object Near → Servo rotates more
Object Far → Servo rotates less
Visual Understanding
Plain text
Distance Range:
5 cm -------------------- 40 cm

Angle Range:
180° -------------------- 0°
As distance increases, angle decreases.
Internally Arduino Calculates Like This
�
But Arduino does this automatically using map().
Example Calculation
Suppose:
C++
distance = 20;
Then Arduino converts it approximately to:
C++
angle ≈ 103°
Then:
C++
servo.write(angle);
moves servo to 103°.
Why We Use map()
Without map(), you would need many if conditions:
C++
if(distance < 10) angle = 180;
else if(distance < 20) angle = 120;
else if(distance < 30) angle = 60;
map() makes it smooth and automatic.



