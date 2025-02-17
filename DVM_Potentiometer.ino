#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD I2C address and size (16x2)

const int potPin = A0;  // Analog input pin for potentiometer

void setup() {
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.clear();                     // Clear the LCD screen
  lcd.setCursor(0, 0);            // Set cursor to the first row
  lcd.print("Voltage:");          // Display "Voltage:" on the first row

  pinMode(potPin, INPUT);          // Set the potPin as an input
  Serial.begin(9600);              // Initialize the serial communication
}

void loop() {
  //float voltage;

  int rawValue = analogRead(potPin);  // Read analog value from potentiometer
  float voltage = map(rawValue, 0, 1023.0, 0, 12.0);  // Map the raw value to voltage range
  
  lcd.setCursor(9, 1);            // Set cursor to the second row, column 9
  lcd.print("      ");            // Clear the previous reading
  lcd.setCursor(9, 1);            // Set cursor to the second row, column 9
  lcd.print(voltage, 2);          // Display the voltage with 2 decimal places
  lcd.print(" V");                // Display the voltage unit

  delay(100);                      // Delay for a short time to reduce display flicker
}