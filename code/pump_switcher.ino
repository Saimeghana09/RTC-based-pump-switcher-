#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

int relayPin = 7;


int onHour = 6;
int onMinute = 0;

int offHour = 6;
int offMinute = 30;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);

  if (!rtc.begin()) {
    Serial.println("RTC not found");
    while (1);
  }

  Serial.println("RTC Based Pump Switcher Started");
}

void loop() {
  DateTime now = rtc.now();

  Serial.print("Current Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.println(now.minute());


  if (now.hour() == onHour && now.minute() == onMinute) {
    digitalWrite(relayPin, HIGH);
    Serial.println("Pump ON");
  }


  if (now.hour() == offHour && now.minute() == offMinute) {
    digitalWrite(relayPin, LOW);
    Serial.println("Pump OFF");
  }

  delay(1000);
}
