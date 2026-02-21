# Robotic Vehicle with IR Collision Avoidance

## 📖 Overview
The project implements a small robotic vehicle that moves forward or backward and stops when an obstacle is detected ahead.An Arduino UNO microcontroller controls the vehicle's movement through programmed commands. 

## 🚀 Features & Logic
**Continuous Monitoring:** An infrared (IR) proximity sensor faces forward to sense obstacles.
**Automated Evasion Maneuvers:** If the IR sensor detects an object within its detection range, the Arduino UNO immediately stops the motors, moves backward, tilt 90 degrees and move again, preventing collisions.
**Embedded Firmware:** The Arduino UNO runs Arduino-based firmware to read the IR sensor and control the L298N motor driver accordingly.

## 🛠️ Hardware Components
**Arduino UNO:** Serves as the central processing unit (CPU) for controlling the car's motion, sensor input, and decision-making logic.
**L298N Motor Driver:** A dual H-bridge driver IC that accepts TTL logic inputs from the ARDUINO UNO and can drive two DC motors.
**DC Geared Motors:** Four 12V DC motors with metal gearboxes[cite: 170]. [cite_start]Each motor's leads connect to the L298N outputs.
**IR Obstacle Sensor:** An infrared emitter/detector pair with LM393 comparator]. The comparator's adjustable sensitivity allows tuning the detection threshold].
**Power Source:** A DC battery pack provides motor power.

## 🔌 Wiring & Pin Mapping
| Component | Pin | Arduino UNO Pin | Function |
| :--- | :--- | :--- | :--- |
| **L298N Motor Driver** | IN1 | Digital Pin 2 (D2) | Left motor - Forward |
| | IN2 | Digital Pin 3 (D3) | Left motor - Backward |
| | IN3 | Digital Pin 4 (D4) | Right motor - Forward  |
| | IN4 | Digital Pin 5 (D5) | Right motor - Backward  |
| **IR Sensor** | OUT | Digital Pin 6 (D6) | Obstacle detection signal  |


## 📄 License
*(See the LICENSE file for details. Usage, modification, or distribution of this code requires explicit prior permission from the authors.)*
