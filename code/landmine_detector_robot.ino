/*
  Project: Landmine Detection & Obstacle Avoidance Robot
  Author: Yash Mohite

  Description:
  - Bluetooth controlled robot car
  - Obstacle avoidance using ultrasonic sensor + servo scanning
  - Motor control using L298N / Motor Shield
  - Designed as a landmine detection robot platform
  - Can be extended with metal detector & buzzer alerts

  Platform: Arduino UNO
*/

/*
  Base reference: Obstacle avoiding, Bluetooth & voice control robot
  Source inspiration: https://srituhobby.com
*/

#include <Servo.h>
#include <AFMotor.h>

// ---------------- Pin Definitions ----------------
#define Echo A0          // Ultrasonic Echo pin
#define Trig A1          // Ultrasonic Trigger pin
#define motor 10         // Servo motor pin

// ---------------- Constants ----------------
#define Speed 170        // Motor speed
#define spoint 103       // Servo center position

// ---------------- Global Variables ----------------
char value;             // Bluetooth command value
int distance;           // Distance from ultrasonic sensor
int Left, Right;        // Distance values for scanning
int L = 0, R = 0;
int L1 = 0, R1 = 0;

// ---------------- Objects ----------------
Servo servo;

// Motor objects (Motor Shield)
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

// ---------------- Setup Function ----------------
void setup() {
  Serial.begin(9600);

  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  servo.attach(motor);

  // Set motor speed
  M1.setSpeed(Speed);
  M2.setSpeed(Speed);
  M3.setSpeed(Speed);
  M4.setSpeed(Speed);
}

// ---------------- Main Loop ----------------
void loop() {
  //Obstacle();          // Enable for autonomous obstacle mode
  Bluetoothcontrol();   // Bluetooth control mode
  //voicecontrol();     // Voice control (optional)
}

// ---------------- Bluetooth Control ----------------
void Bluetoothcontrol() {
  if (Serial.available() > 0) {
    value = Serial.read();
    Serial.println(value);
  }

  if (value == 'F') {
    forward();
  } else if (value == 'B') {
    backward();
  } else if (value == 'L') {
    left();
  } else if (value == 'R') {
    right();
  } else if (value == 'S') {
    Stop();
  }
}

// ---------------- Obstacle Avoidance Mode ----------------
void Obstacle() {
  distance = ultrasonic();

  if (distance <= 12) {
    Stop();
    backward();
    delay(100);
    Stop();

    // Scan left and right
    L = leftsee();
    servo.write(spoint);
    delay(800);

    R = rightsee();
    servo.write(spoint);

    // Decide direction
    if (L < R) {
      right();
      delay(500);
    } else if (L > R) {
      left();
      delay(500);
    }

    Stop();
    delay(200);
  } else {
    forward();
  }
}

// ---------------- Voice Control Mode ----------------
void voicecontrol() {
  if (Serial.available() > 0) {
    value = Serial.read();
    Serial.println(value);

    if (value == '^') {
      forward();
    } else if (value == '-') {
      backward();
    } else if (value == '<') {
      L = leftsee();
      servo.write(spoint);

      if (L >= 10) {
        left();
        delay(500);
      }
      Stop();
    } else if (value == '>') {
      R = rightsee();
      servo.write(spoint);

      if (R >= 10) {
        right();
        delay(500);
      }
      Stop();
    } else if (value == '*') {
      Stop();
    }
  }
}

// ---------------- Ultrasonic Distance Function ----------------
int ultrasonic() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  long t = pulseIn(Echo, HIGH);
  int cm = t / 29 / 2;   // Convert time to distance in cm

  return cm;
}

// ---------------- Motor Control Functions ----------------
void forward() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void backward() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void right() {
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
}

void left() {
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
}

void Stop() {
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
}

// ---------------- Servo Scanning Functions ----------------
int rightsee() {
  servo.write(20);
  delay(800);
  Left = ultrasonic();
  return Left;
}

int leftsee() {
  servo.write(180);
  delay(800);
  Right = ultrasonic();
  return Right;
}
