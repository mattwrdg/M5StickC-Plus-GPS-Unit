# M5StickC-Plus-GPS-Unit
Simple Example how to connect a GPS Unit to a M5StickC Plus

![M5StickC Plus GPS Unit](/img/M5StickC-Plus-GPS-Unit_1.jpg)

Simple Example how to make use of the TinyGPS++ Library and get a proper connection of the new M5StickC Plus Device with the GPS Unit: AT6558

## Code example

* Create a HardwareSerial
```c++
// The serial connection to the GPS device
HardwareSerial Uart = HardwareSerial(2);
```

* Setup the Serial Connection with the GPS Module on the Pins 33 & 32
```c++
  // GPS connection on baud rate 9600
  // PIN 33 = TX of AT6558 GPS 
  // PIN 32 = RX of AT6558 GPS
  Uart.begin(9600, SERIAL_8N1, 33, 32);
```


* Read the Serial connection named Uart
```c++
  gps.encode(Uart.read());
```

* Print the results to the M5 Lcd Display
```c++
  M5.Lcd.setCursor(30, 50);
  M5.Lcd.printf("Lng: %5.5f", gps.location.lng());

  M5.Lcd.setCursor(30, 70); 
  M5.Lcd.printf("Lat: %5.5f",  gps.location.lat());

  M5.Lcd.setCursor(30, 90); 
  M5.Lcd.printf("Sat: %i", gps.satellites.value());
```

* Have fun & enjoy :)