// This code is designed to monitor a cricket habitat. Using a DHT22 temperature and humidity reader, this code reads in the temperature and humidity of the environment. These values are then printed to the serial monitor. In additon, based on these values a heating pad or humidifier are either turned on or off to set values. 

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to
int Humidify = 8;    // This pin is connected to a relay that turns on and off a humidifier
int Heating = 12;    // This pin goes out to relay which turns on and off a heating pad

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); //starts serial monitor and sets baud rate
  Serial.println("DHT22 Up and Running!"); //send message to serial monitor that the sensor isd beginging
  pinMode(8, OUTPUT);  // creates out humidity pin as an output
  pinMode(12, OUTPUT); // creates out heating pin as an output
  dht.begin(); //starts DHT sensor reading
}

void loop() {
  // Wait a few seconds between measurements.
  delay(5000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  
// output these readings to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  
// creates a range of read humidity in which the humidfier is placed on or off
  if (h < 60) {
    digitalWrite(8, HIGH);}
  if (h > 70) {  
      digitalWrite(8, LOW);
    }

// creates a range of read humidity in which the humidfier is placed on or off
  if (t < 30){
    digitalWrite(12, HIGH);}
  if(t > 31) {
      digitalWrite(12, LOW);}
  }

// end code
