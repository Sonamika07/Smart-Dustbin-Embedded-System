# Smart Dustbin - Industry-Oriented Embedded System

## 1. Project Overview

- Smart Dustbin is an ESP32-based embedded systems project designed to automate dustbin operation and monitor waste levels.
- The project uses two HC-SR04 ultrasonic sensors.
  - The first ultrasonic sensor detects a nearby hand or object.
  - The second ultrasonic sensor detects the waste level inside the dustbin.
- A servo motor automatically opens and closes the dustbin lid.
- A green LED indicates normal operation.
- A red LED and buzzer indicate that the dustbin is full.
- The project is developed and tested using the Wokwi virtual simulation platform.

## 2. Project Objectives

- Automatic touchless lid opening.
- Automatic lid closing.
- Object or hand detection.
- Waste-level monitoring.
- Bin fill percentage calculation.
- Full-bin detection.
- LED-based status indication.
- Buzzer-based full-bin alert.
- Serial Monitor monitoring.
- Demonstration of ESP32 GPIO programming.
- Demonstration of ultrasonic sensor interfacing.
- Demonstration of servo motor control.
- Demonstration of embedded C/C++ programming.
- Virtual hardware simulation using Wokwi.

## 3. Features

- Touchless dustbin operation.
- Automatic lid opening using a servo motor.
- Automatic lid closing after a fixed delay.
- Object detection using an ultrasonic sensor.
- Waste-level detection using a second ultrasonic sensor.
- Fill percentage calculation.
- 90% full-bin threshold.
- Green LED for normal status.
- Red LED for full-bin status.
- Buzzer alert when the bin is full.
- Serial Monitor output.
- Invalid sensor reading detection.
- Wokwi virtual simulation.

## 4. Hardware Components

- 1. ESP32 (1) -> Main microcontroller
- 2. HC-SR04 Ultrasonic Sensor (2) -> Object detection and waste-level detection
- 3. Servo Motor (1) -> Automatic dustbin lid control
- 4. Buzzer (1) -> Full-bin audio alert
- 5. Green LED (1) -> Normal status indication
- 6. Red LED (1) -> Full-bin status indication
- 7. Resistor (2) -> LED current limiting
- 8. Breadboard (1) -> Circuit prototyping
- 9. Jumper Wires -> Component connections

## 5. Software and Technologies Used

- ESP32
- Wokwi Simulator
- C/C++ Arduino Programming
- Arduino Framework
- ESP32Servo Library
- HC-SR04 Ultrasonic Sensors
- Servo Motor
- Buzzer
- Green LED
- Red LED
- Serial Monitor

## 6. Circuit Connections

- Object HC-SR04 (TRIG) -> ESP32 GPIO 23
- Object HC-SR04 (ECHO) -> ESP32 GPIO 22
- Object HC-SR04 (VCC) -> ESP32 5V/VIN
- Object HC-SR04 (GND) -> ESP32 GND

- Waste HC-SR04 (TRIG) -> ESP32 GPIO 5
- Waste HC-SR04 (ECHO) -> ESP32 GPIO 18
- Waste HC-SR04 (VCC) -> ESP32 5V/VIN
- Waste HC-SR04 (GND) -> ESP32 GND

- Servo (PWM/Signal) -> ESP32 GPIO 19
- Servo (V+) -> 5V
- Servo (GND) -> ESP32 GND

- Buzzer (+) -> ESP32 GPIO 21
- Buzzer (-) -> ESP32 GND

- Green LED (Anode) -> Resistor -> ESP32 GPIO 25
- Green LED (Cathode) -> ESP32 GND

- Red LED (Anode) -> Resistor -> ESP32 GPIO 26
- Red LED (Cathode) -> ESP32 GND

## 7. Embedded System Concepts Used

- Microcontroller
  - ESP32 acts as the main controller.
  - It processes sensor readings and controls the output devices.

- GPIO
  - GPIO pins are used for sensor input and output device control.

- Ultrasonic Sensor
  - HC-SR04 sensors are used for distance measurement.

- Servo Motor
  - The servo motor controls the physical position of the dustbin lid.

- PWM
  - The servo receives a control signal through GPIO 19.

- Buzzer
  - The buzzer provides an audio alert when the bin is full.

- LED
  - Green LED indicates normal status.
  - Red LED indicates full-bin status.

- Threshold Logic
  - Predefined distance and fill-level thresholds are used for decision making.

- Serial Communication
  - Serial Monitor displays sensor readings and system status.

- Embedded C/C++
  - The complete control logic is implemented using Arduino C/C++.

## 8. System Architecture

- Input
  - Object or hand distance
  - Waste distance

- Processing
  - ESP32
  - Distance calculation
  - Object detection
  - Fill percentage calculation
  - Threshold comparison

- Output
  - Servo motor
  - Green LED
  - Red LED
  - Buzzer
  - Serial Monitor

## 9. Working Principle

- Object Detection
  - The object HC-SR04 continuously measures the distance of an approaching hand or object.
  - If the object is detected within 20 cm, the ESP32 opens the lid.

- Automatic Lid Opening
  - The servo motor is connected to GPIO 19.
  - The servo moves to 90 degrees when an object is detected.
  - The lid remains open for approximately 3 seconds.
  - The servo then returns to 0 degrees and closes the lid.

- Waste-Level Detection
  - The second HC-SR04 sensor measures the distance between the top of the dustbin and the waste surface.
  - As the amount of waste increases, the measured distance decreases.

- Full-Bin Detection
  - The ESP32 calculates the approximate fill percentage.
  - If the fill percentage reaches 90% or more, the full-bin alert is activated.

## 10. Sensor Configuration

- Object Sensor
  - TRIG -> GPIO 23
  - ECHO -> GPIO 22
  - Detection distance -> 20 cm

- Waste Sensor
  - TRIG -> GPIO 5
  - ECHO -> GPIO 18
  - Bin height -> 40 cm

- Full-bin threshold
  - 90%

## 11. Bin Fill Percentage Calculation

- Bin height used in the project:
  - 40 cm

- Formula:

text
Fill Percentage =
((Bin Height - Waste Distance) / Bin Height) x 100

12. Example Fill Levels
Empty Bin
Waste Distance = 40 cm
Fill Level = 0%
Status = NORMAL
25% Full
Waste Distance = 30 cm
Fill Level = 25%
Status = NORMAL
50% Full
Waste Distance = 20 cm
Fill Level = 50%
Status = NORMAL
75% Full
Waste Distance = 10 cm
Fill Level = 75%
Status = NORMAL
90% Full
Waste Distance = 4 cm
Fill Level = 90%
Status = BIN FULL
13. LED and Buzzer Logic
Normal condition
Green LED -> ON
Red LED -> OFF
Buzzer -> OFF
Serial Monitor -> STATUS: NORMAL
Full-bin condition
Green LED -> OFF
Red LED -> ON
Buzzer -> ON
Serial Monitor -> STATUS: BIN FULL
Serial Monitor -> ALERT: BUZZER ON
14. Serial Monitor
Baud Rate:
115200
Startup output:
================================
     SMART DUSTBIN STARTED
================================
Normal example:
Waste Distance: 20.00 cm
Bin Fill Level: 50.00%
STATUS: NORMAL
Object detection example:
Object detected!
Lid: OPEN
Lid: CLOSED
Full-bin example:
Waste Distance: 4.00 cm
Bin Fill Level: 90.00%
STATUS: BIN FULL
ALERT: BUZZER ON
15. Project Code
Main source code:
src/smart_dustbin.ino
Main functions used:
readDistance()
setup()
loop()
readDistance()
Sends a trigger signal to the ultrasonic sensor.
Reads the echo signal.
Calculates the distance in centimeters.
Returns -1 if no valid echo is received.
setup()
Initializes Serial communication.
Configures sensor pins.
Configures LED and buzzer pins.
Attaches the servo.
Sets the initial lid position to closed.
loop()
Reads the object sensor.
Reads the waste sensor.
Detects an approaching object.
Controls the servo.
Calculates bin fill percentage.
Controls LEDs and buzzer.
Displays system information on Serial Monitor.
16. Virtual Simulation
Simulation Platform:
Wokwi
Simulation components:
ESP32
Two HC-SR04 ultrasonic sensors
Servo motor
Buzzer
Green LED
Red LED
Resistors
Simulation process:
Create an ESP32 project in Wokwi.
Add all required components.
Connect the components according to the circuit connections.
Add the ESP32Servo library.
Paste the source code.
Start the simulation.
Open the Serial Monitor.
Change the object sensor distance.
Verify lid opening and closing.
Change the waste sensor distance.
Verify different fill levels.
Test the 90% full condition.
Verify red LED and buzzer activation.
17. Testing Strategy
Test 1: No Object
Input -> No nearby object
Expected -> Lid remains closed
Result -> Pass
Test 2: Object Detection
Input -> Object within 20 cm
Expected -> Lid opens
Result -> Pass
Test 3: Lid Closing
Input -> Object removed
Expected -> Lid closes after delay
Result -> Pass
Test 4: Empty Bin
Input -> Waste distance approximately 40 cm
Expected -> Fill level approximately 0%
Result -> Pass
Test 5: 50% Bin
Input -> Waste distance approximately 20 cm
Expected -> Fill level approximately 50%
Result -> Pass
Test 6: Full Bin
Input -> Fill level 90% or more
Expected -> Red LED and buzzer ON
Result -> Pass
Test 7: Invalid Sensor Reading
Input -> No echo from sensor
Expected -> Invalid/no echo message
Result -> Pass
18. Screenshots and Proof
01_complete_circuit.png
Complete Wokwi circuit.
02_serial_monitor.png
Serial Monitor output.
03_lid_open.png
Object detected and lid open.
04_lid_closed.png
Lid closed condition.
05_empty_bin.png
Empty-bin condition.
06_50_percent.png
Approximately 50% bin fill condition.
07_full_bin.png
Approximately 90% bin fill condition.
08_full_alert.png
Red LED and buzzer alert condition.

19. Project Folder Structure

Smart-Dustbin-Embedded-System/
│
├── src/
│   └── smart_dustbin.ino
│
├── simulation/
│   └── diagram.json
│
├── screenshots/
│   ├── 01_complete_circuit.png
│   ├── 02_serial_monitor.png
│   ├── 03_lid_open.png
│   ├── 04_lid_closed.png
│   ├── 05_empty_bin.png
│   ├── 06_50_percent.png
│   ├── 07_full_bin.png
│   └── 08_full_alert.png
│
├── docs/
│   └── testing.md
│
└── README.md

20. Industry Relevance

Smart Cities
Real-time waste monitoring can help improve waste collection planning.
Hospitals
Touchless operation can support better hygiene.
Airports
Automated bins can be useful in high-footfall areas.
Railway Stations
Smart monitoring can help reduce overflowing bins.
Shopping Malls
Touchless operation can improve user convenience.
Offices
Automated monitoring can reduce manual checking.
Educational Campuses
Smart bins can support cleaner campus environments.
Industrial Facilities
Waste-level monitoring can improve maintenance efficiency.

21. Business Value

Touchless operation.
Better hygiene.
Reduced manual monitoring.
Early full-bin alerts.
Reduced risk of overflowing waste.
Better maintenance planning.
Potentially more efficient waste collection.

22. Future Improvements

Blynk IoT integration.
Wi-Fi-based remote monitoring.
Mobile notifications.
Cloud data logging.
Multiple smart-bin monitoring.
GPS-based bin tracking.
Waste collection route optimization.
Solar-powered operation.
Waste classification using machine learning.
Historical waste-level analytics.

23. Learning Outcomes

ESP32 programming.
Arduino C/C++ programming.
GPIO configuration.
Ultrasonic sensor interfacing.
Distance measurement.
Servo motor control.
PWM-based actuator control.
LED and buzzer control.
Threshold-based decision making.
Sensor calibration.
Serial communication.
Embedded system testing.
Virtual hardware simulation.
GitHub project documentation.

24. Project Status

Status:
Completed
Platform:
ESP32
Programming Language:
C/C++ Arduino
Simulation Platform:
Wokwi
Version:
1.0

25. Hardware Safety Note

For real hardware implementation, HC-SR04 ECHO output should be checked for logic-level compatibility with ESP32 GPIO.
ESP32 GPIO uses 3.3V logic.
A suitable voltage divider or level shifter may be required for the HC-SR04 ECHO signal.
The servo should preferably use a stable 5V supply when required by its current demand.
ESP32 and external servo power supply should have a common GND.

26. Author

Name: Sonamika Anand Samrat
Project: Smart Dustbin - Industry-Oriented Embedded System
Domain: Embedded Systems / IoT / Automation

27. License

This project is created for educational and academic purposes.
