

// Motor control pins
const int motorLeftForwardPin = 2;   // IN1
const int motorLeftBackwardPin = 3;  // IN2
const int motorRightForwardPin = 4;  // IN3
const int motorRightBackwardPin = 5; // IN4

// IR Sensor pin
const int irSensorPin = 6;

// Timing constants (milliseconds)
const unsigned long backwardDuration = 1000;  // Move backward for 1 second
const unsigned long turnDuration = 700;       // Turn duration to achieve 90 degrees (adjust as needed)
const unsigned long forwardDuration = 2000;   // Move forward for 2 seconds after turn

void setup() {
  // Initialize motor pins as outputs
  pinMode(motorLeftForwardPin, OUTPUT);
  pinMode(motorLeftBackwardPin, OUTPUT);
  pinMode(motorRightForwardPin, OUTPUT);
  pinMode(motorRightBackwardPin, OUTPUT);

  // Initialize IR sensor pin as input
  pinMode(irSensorPin, INPUT);

  // Stop motors at start
  stopMotors();

  // For debugging via serial
  Serial.begin(9600);
  Serial.println("DIY Car Controller Started");
}

void loop() {
  // Read IR sensor value
  int sensorValue = digitalRead(irSensorPin);

  if (sensorValue == LOW) {
    // IR sensor detected obstacle (assuming active LOW)
    Serial.println("Obstacle detected - executing maneuver");

    // Move backward
    moveBackward();
    delay(backwardDuration);

    // Stop briefly
    stopMotors();
    delay(300);

    // Turn 90 degrees to the right (clockwise)
    turnRight90();
    delay(turnDuration);

    // Stop briefly
    stopMotors();
    delay(300);

    // Move forward
    moveForward();
    delay(forwardDuration);

    // Stop briefly and then resume normal operation
    stopMotors();
    delay(300);
  } else {
    // No obstacle detected, move forward slowly
    moveForward();
  }
}

// Motor control functions
void moveForward() {
  digitalWrite(motorLeftForwardPin, HIGH);
  digitalWrite(motorLeftBackwardPin, LOW);
  digitalWrite(motorRightForwardPin, HIGH);
  digitalWrite(motorRightBackwardPin, LOW);
}

void moveBackward() {
  digitalWrite(motorLeftForwardPin, LOW);
  digitalWrite(motorLeftBackwardPin, HIGH);
  digitalWrite(motorRightForwardPin, LOW);
  digitalWrite(motorRightBackwardPin, HIGH);
}

void turnRight90() {
  // Left wheels forward, right wheels backward to turn right in place
  digitalWrite(motorLeftForwardPin, HIGH);
  digitalWrite(motorLeftBackwardPin, LOW);
  digitalWrite(motorRightForwardPin, LOW);
  digitalWrite(motorRightBackwardPin, HIGH);
}

void stopMotors() {
  digitalWrite(motorLeftForwardPin, LOW);
  digitalWrite(motorLeftBackwardPin, LOW);
  digitalWrite(motorRightForwardPin, LOW);
  digitalWrite(motorRightBackwardPin, LOW);
}