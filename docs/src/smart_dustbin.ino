#include <ESP32Servo.h>

// ==================================================
//                 SMART DUSTBIN
// ==================================================

// ---------- OBJECT / HAND SENSOR ----------
#define OBJECT_TRIG 23
#define OBJECT_ECHO 22

// ---------- WASTE LEVEL SENSOR ----------
#define WASTE_TRIG 5
#define WASTE_ECHO 18

// ---------- OUTPUTS ----------
#define SERVO_PIN 19
#define BUZZER_PIN 21
#define GREEN_LED 25
#define RED_LED 26

// ---------- SETTINGS ----------
#define BIN_HEIGHT 40.0
#define HAND_DISTANCE 20.0
#define FULL_LEVEL 90.0

// ---------- SERVO ----------
Servo lidServo;


// ==================================================
//              READ ULTRASONIC DISTANCE
// ==================================================

float readDistance(int trigPin, int echoPin) {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  float distance = duration * 0.0343 / 2;

  return distance;
}


// ==================================================
//                     SETUP
// ==================================================

void setup() {

  Serial.begin(115200);

  // Object Sensor
  pinMode(OBJECT_TRIG, OUTPUT);
  pinMode(OBJECT_ECHO, INPUT);

  // Waste Sensor
  pinMode(WASTE_TRIG, OUTPUT);
  pinMode(WASTE_ECHO, INPUT);

  // Outputs
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Servo
  lidServo.attach(SERVO_PIN);

  // Lid initially closed
  lidServo.write(0);

  // Initial status
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  // Startup message
  Serial.println();
  Serial.println("================================");
  Serial.println("     SMART DUSTBIN STARTED");
  Serial.println("================================");
  Serial.println();
}


// ==================================================
//                      LOOP
// ==================================================

void loop() {

  // ==================================================
  //              OBJECT SENSOR READING
  // ==================================================

  float objectDistance =
    readDistance(OBJECT_TRIG, OBJECT_ECHO);

  // Small gap between ultrasonic sensors
  delay(100);


  // ==================================================
  //              WASTE SENSOR READING
  // ==================================================

  float wasteDistance =
    readDistance(WASTE_TRIG, WASTE_ECHO);


  // ==================================================
  //             OBJECT / HAND DETECTION
  // ==================================================

  if (objectDistance > 0 &&
      objectDistance <= HAND_DISTANCE) {

    Serial.println("Object detected!");
    Serial.println("Lid: OPEN");

    // Open lid
    lidServo.write(90);

    // Keep lid open for 3 seconds
    delay(3000);

    // Close lid
    lidServo.write(0);

    Serial.println("Lid: CLOSED");
  }


  // ==================================================
  //                 WASTE LEVEL
  // ==================================================

  if (wasteDistance > 0) {

    float fillPercentage;


    // --------------------------------------------------
    // If sensor sees something farther than bin height,
    // treat bin as empty (0%)
    // --------------------------------------------------

    if (wasteDistance >= BIN_HEIGHT) {

      fillPercentage = 0;

    }

    else {

      // Calculate fill percentage
      fillPercentage =
        ((BIN_HEIGHT - wasteDistance) / BIN_HEIGHT) * 100.0;
    }


    // Keep percentage between 0 and 100

    if (fillPercentage < 0) {
      fillPercentage = 0;
    }

    if (fillPercentage > 100) {
      fillPercentage = 100;
    }


    // ==================================================
    //              SERIAL MONITOR
    // ==================================================

    Serial.print("Waste Distance: ");
    Serial.print(wasteDistance);
    Serial.println(" cm");

    Serial.print("Bin Fill Level: ");
    Serial.print(fillPercentage);
    Serial.println("%");


    // ==================================================
    //                  BIN FULL ALERT
    // ==================================================

    if (fillPercentage >= FULL_LEVEL) {

      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);

      Serial.println("STATUS: BIN FULL");
      Serial.println("ALERT: BUZZER ON");
    }


    // ==================================================
    //                  NORMAL STATUS
    // ==================================================

    else {

      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      digitalWrite(BUZZER_PIN, LOW);

      Serial.println("STATUS: NORMAL");
    }
  }


  // ==================================================
  //             SENSOR INVALID / NO ECHO
  // ==================================================

  else {

    Serial.println("Waste Sensor: No Echo");
  }


  Serial.println("--------------------------------");

  delay(1000);
}
