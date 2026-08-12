# Smart Dustbin - Project Documentation

## 1. Project Title

Smart Dustbin - Industry-Oriented Embedded System

## 2. Project Objective

- To design an automated smart dustbin using ESP32.
- To automatically open and close the dustbin lid when an object or hand is detected.
- To monitor the waste level inside the dustbin.
- To provide an alert when the dustbin reaches the full level.

## 3. Project Overview

- The Smart Dustbin is an ESP32-based embedded system.
- Two HC-SR04 ultrasonic sensors are used.
- One sensor detects a nearby object or hand.
- The second sensor measures the waste level.
- A servo motor controls the dustbin lid.
- Green LED indicates normal operation.
- Red LED and buzzer indicate that the dustbin is full.

## 4. Technologies Used

- ESP32
- Wokwi Simulator
- C/C++ Arduino Programming
- HC-SR04 Ultrasonic Sensors
- Servo Motor
- Buzzer
- Green LED
- Red LED
- Resistors

## 5. Hardware Components

- ESP32 (1) -> Main microcontroller
- HC-SR04 Ultrasonic Sensor (2) -> Object and waste-level detection
- Servo Motor (1) -> Automatic lid control
- Buzzer (1) -> Full-bin alert
- Green LED (1) -> Normal status indication
- Red LED (1) -> Full-bin indication
- Resistor (2) -> LED current limiting

## 6. Circuit Connections

- Object HC-SR04 (TRIG) -> ESP32 GPIO 23
- Object HC-SR04 (ECHO) -> ESP32 GPIO 22
- Object HC-SR04 (VCC) -> ESP32 5V/VIN
- Object HC-SR04 (GND) -> ESP32 GND

- Waste HC-SR04 (TRIG) -> ESP32 GPIO 5
- Waste HC-SR04 (ECHO) -> ESP32 GPIO 18
- Waste HC-SR04 (VCC) -> ESP32 5V/VIN
- Waste HC-SR04 (GND) -> ESP32 GND

- Servo (PWM) -> ESP32 GPIO 19
- Servo (V+) -> 5V
- Servo (GND) -> GND

- Buzzer (+) -> ESP32 GPIO 21
- Buzzer (-) -> GND

- Green LED (Anode via resistor) -> ESP32 GPIO 25
- Green LED (Cathode) -> GND

- Red LED (Anode via resistor) -> ESP32 GPIO 26
- Red LED (Cathode) -> GND

## 7. Software

- Arduino C/C++
- ESP32Servo Library
- Wokwi ESP32 Simulator

## 8. Pin Configuration

- OBJECT_TRIG = GPIO 23
- OBJECT_ECHO = GPIO 22
- WASTE_TRIG = GPIO 5
- WASTE_ECHO = GPIO 18
- SERVO_PIN = GPIO 19
- BUZZER_PIN = GPIO 21
- GREEN_LED = GPIO 25
- RED_LED = GPIO 26

## 9. System Parameters

- Bin Height = 40 cm
- Hand Detection Distance = 20 cm
- Full Bin Threshold = 90%

## 10. Object Detection

- The first HC-SR04 sensor detects a nearby hand or object.
- If the detected distance is 20 cm or less, an object is considered detected.
- The servo motor opens the lid.
- After 3 seconds, the lid automatically closes.

## 11. Waste Level Detection

- The second HC-SR04 sensor measures the distance between the sensor and the waste.
- The bin height is considered as 40 cm.
- The waste fill percentage is calculated from the measured distance.

## 12. Fill Level Calculation

- Fill Level = ((Bin Height - Waste Distance) / Bin Height) x 100
- If the measured distance is equal to or greater than 40 cm, the fill level is considered 0%.
- The calculated value is limited between 0% and 100%.

## 13. Normal Condition

- If the fill level is below 90%, the system remains in normal condition.
- Green LED remains ON.
- Red LED remains OFF.
- Buzzer remains OFF.
- Serial Monitor displays STATUS: NORMAL.

## 14. Full Bin Condition

- If the fill level reaches 90% or more, the system detects a full bin.
- Green LED turns OFF.
- Red LED turns ON.
- Buzzer turns ON.
- Serial Monitor displays STATUS: BIN FULL.
- Serial Monitor displays ALERT: BUZZER ON.

## 15. Lid Control

- Initial servo position is 0 degrees.
- The lid starts in the closed position.
- When an object is detected within 20 cm, the servo moves to 90 degrees.
- The lid remains open for approximately 3 seconds.
- The servo then returns to 0 degrees.

## 16. Serial Monitor

- Serial communication is configured at 115200 baud.
- The Serial Monitor displays:
  - Object detection status
  - Lid status
  - Waste distance
  - Bin fill level
  - Current system status
  - Full-bin alert

## 17. Sensor Diagnostic Test

- The ultrasonic sensors can also be tested independently.
- The diagnostic program displays the distance measured by both sensors.
- INVALID is displayed when no valid echo is received.

## 18. Empty Bin Test

- Bin height is set to 40 cm.
- When the waste distance is approximately 40 cm or greater:
  - Fill Level = 0%
  - STATUS = NORMAL
  - Green LED = ON
  - Red LED = OFF
  - Buzzer = OFF

## 19. 50% Bin Test

- Bin height is 40 cm.
- Waste distance is approximately 20 cm.
- Fill Level = approximately 50%.
- STATUS = NORMAL.
- Green LED remains ON.
- Red LED remains OFF.
- Buzzer remains OFF.

## 20. Full Bin Test

- When the waste distance becomes approximately 4 cm:
  - Fill Level = approximately 90%.
  - STATUS = BIN FULL.
  - Green LED turns OFF.
  - Red LED turns ON.
  - Buzzer turns ON.

## 21. Lid Open Test

- Place an object or hand within approximately 20 cm of the object sensor.
- The system detects the object.
- Servo moves to the open position.
- Serial Monitor displays:
  - Object detected!
  - Lid: OPEN

## 22. Lid Closed Test

- Remove the object from the detection area.
- After the opening delay, the servo returns to the closed position.
- Serial Monitor displays:
  - Lid: CLOSED

## 23. Project Testing

- Test the object detection sensor.
- Test automatic lid opening.
- Test automatic lid closing.
- Test empty-bin condition.
- Test 50% waste level.
- Test full-bin condition.
- Test LED indicators.
- Test buzzer alert.
- Verify Serial Monitor output.

## 24. Project Files

- smart_dustbin.ino -> Main Arduino source code
- diagram.json -> Wokwi circuit diagram
- README.md -> Project overview and documentation
- screenshots/ -> Project testing screenshots
- docs/project-documentation.md -> Detailed project documentation

## 25. Screenshots

- 01_complete_circuit.png -> Complete circuit
- 02_serial_monitor.png -> Serial Monitor output
- 03_lid_open.png -> Lid open condition
- 04_lid_closed.png -> Lid closed condition
- 05_empty_bin.png -> Empty bin condition
- 06_50_percent.png -> 50% bin condition
- 07_full_bin.png -> Full bin condition
- 08_full_alert.png -> Full-bin alert condition

## 26. Expected Output

- Object detection automatically opens the lid.
- The lid automatically closes after the specified delay.
- Waste level is calculated in percentage.
- Green LED indicates normal operation.
- Red LED and buzzer indicate a full dustbin.
- Sensor readings and system status are displayed on the Serial Monitor.

## 27. Conclusion

- The Smart Dustbin demonstrates an automated waste-management system using ESP32 and ultrasonic sensors.
- The system reduces the need for manual lid operation.
- It continuously monitors the waste level.
- The alert system helps indicate when the dustbin requires emptying.
- The project can be further extended with IoT monitoring, mobile notifications, cloud data logging, and real-time dashboards.
