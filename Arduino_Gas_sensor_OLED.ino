//kitkraft.in
//In this project, we’ll show you how to build an Arduino-based gas detection system using a 
//gas sensor and a 0.96" OLED display. This beginner-friendly DIY project demonstrates how to 
//monitor air quality in real-time, displaying gas levels with an Arduino Nano.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_WIDTH 128 // OLED display width,  in pixels
#define OLED_HEIGHT 64 // OLED display height, in pixels

const int AO_Pin=0; // Connect the AO of MQ-4 sensor with analog channel 0 pin (A0) of Arduino
int AO_Out; // Create a variable to store the analog output of the MQ-4 sensor

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

// Set up
void setup() {
  Serial.begin(115200);  // Initialize serial monitor using a baud rate of 115200

  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);         // wait for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(1);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(0, 10);        // position to display
  oled.println("Gas Sensor"); // text to display
  oled.display();
  oled.clearDisplay(); // clear display
}

// Main loop
void loop()
{
  AO_Out= analogRead(AO_Pin); // Read the analog output measurement sample from the MQ4 sensor's AO pin
  Serial.print(", "); // print a comma and space

  Serial.print("Methane Conentration: "); // Print out the text "Methane Concentration: "
  Serial.println(AO_Out); // Print out the methane value - the analog output - beteewn 0 and 1023

  oled.clearDisplay(); // clear display
  oled.setTextSize(3); 
  oled.setCursor(0, 20);
  oled.println(AO_Out); // text to display
  oled.display();

  delay(1000); // Set a 10 second delay
}