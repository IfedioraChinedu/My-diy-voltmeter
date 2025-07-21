
/*
  Power Monitor by Imaxeuno
  Author: Chinedu Ifediora
  Website: www.imaxeuno.com
  Description: Reads voltage from A0 and current from A1 (ACS712), calculates power, and displays all values on a 20x4 LCD.
  Copyright (c) Chinedu Ifediora
*/

#include <LiquidCrystal.h>

// LCD pins: RS->7, E->6, D4->5, D5->4, D6->3, D7->2
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int voltagePin = A0;
const int currentPin = A1;

void setup() {
  lcd.begin(20, 4);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Power Monitor v1.0");
  lcd.setCursor(0, 1);
  lcd.print("by Chinedu Ifediora");
  delay(2000);
}

void loop() {
  // Read analog values
  int rawVoltage = analogRead(voltagePin);
  int rawCurrent = analogRead(currentPin);

  // Convert to real-world values
  float voltage = rawVoltage * (5.0 / 1023.0) * 10.0;  // Assume voltage divider
  float current = (rawCurrent - 512) * (5.0 / 1023.0) / 0.185; // ACS712 5A = 185mV/A

  float power = voltage * current;

  // Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(voltage, 2);
  lcd.print(" V");

  lcd.setCursor(0, 1);
  lcd.print("Current: ");
  lcd.print(current, 2);
  lcd.print(" A");

  lcd.setCursor(0, 2);
  lcd.print("Power: ");
  lcd.print(power, 2);
  lcd.print(" W");

  lcd.setCursor(0, 3);
  lcd.print("imaxeuno.com");

  delay(1000);
}
