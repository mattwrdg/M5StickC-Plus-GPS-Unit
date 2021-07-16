#include <Arduino.h>
#include <M5StickCPlus.h>
#include <TinyGPS++.h>

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
HardwareSerial Uart = HardwareSerial(2);


static void smartDelay(unsigned long ms);

void setup() {

  M5.begin();
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextColor(TFT_WHITE,TFT_BLACK);
  M5.Lcd.setRotation(1);
  M5.Lcd.setTextSize(2);

  // Serial connection on baud rate 115200
  Serial.begin(115200);
  
  // GPS connection on baud rate 9600
  // PIN 33 = TX of AT6558 GPS 
  // PIN 32 = RX of AT6558 GPS
  Uart.begin(9600, SERIAL_8N1, 33, 32);
}

void loop() {

  // Display Data
  M5.Lcd.setCursor(80, 15);
  M5.Lcd.println("GPS TEST");

  M5.Lcd.setCursor(30, 50);
  M5.Lcd.printf("Lng: %5.5f", gps.location.lng());

  M5.Lcd.setCursor(30, 70); 
  M5.Lcd.printf("Lat: %5.5f",  gps.location.lat());

  M5.Lcd.setCursor(30, 90); 
  M5.Lcd.printf("Sat: %i", gps.satellites.value());


  // Send data to Serial Monitor
  Serial.printf("Lon: %5.8f ", gps.location.lng());
  Serial.printf("Lat: %5.8f ", gps.location.lat());
  smartDelay(1000);
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (Uart.available())
      gps.encode(Uart.read());

  } while (millis() - start < ms);
}
