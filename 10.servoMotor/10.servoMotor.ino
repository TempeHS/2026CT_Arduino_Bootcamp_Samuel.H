/*
  Author:

  Learning Intention:
  The students will learn how to connect and control a servo motor.

  Success Criteria:
    1.  I understand how to connect the servo motor
    2.  I can manually write different degrees of movement to the servo
    3.  I can map a potentiometer to a servo and control its movement
    4.  I understand that a 180deg servo angle of movement is set by a
        frequency signal sent from the microcontroller

  Student Notes: 

  Documentation:
    https://www.sparkfun.com/servos
    https://github.com/arduino-libraries/Servo <-- We are still using this library

  Schematic:
    https://www.tinkercad.com/things/lQ9RyYJRoLn?sharecode=MKlN0A7R0WGodkdTRKkPJO7I8PeI5L_GCR7pCclQ0qM
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/10.servoMotor/Bootcamp-servoMotor.png
*/

// OLED screen components
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

#include <Servo.h>
#include "Ultrasonic.h"

unsigned static int servoPIN = 6;
unsigned static int ussPIN = 5;
unsigned static int ledPin = 3;






int potPIN = A1;

Servo myservo;
Ultrasonic myUSS(ussPIN);

U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  myservo.attach(servoPIN);

  OLED.begin();
  OLED.setFont(u8g2_font_6x12_tf);
}

void loop() {
  OLED.clearBuffer();
  unsigned long range_in_cm;
  range_in_cm = myUSS.distanceRead();
  if (range_in_cm < 11) {
    digitalWrite(ledPin, HIGH);
    OLED.drawStr(0, 30, "On");
    } else {
    digitalWrite(ledPin, LOW);
    OLED.drawStr(0, 30, "Off");
  }
  String distanceString = String(range_in_cm);
  int servoAngle = map(range_in_cm, 0, 100, 0, 180);
  myservo.write(servoAngle);
  String servoString = String(servoAngle);
  OLED.setFont(u8g2_font_6x12_tf);
  OLED.drawStr(0, 10, distanceString.c_str());
  OLED.drawStr(0, 20, servoString.c_str());
  OLED.nextPage();
}