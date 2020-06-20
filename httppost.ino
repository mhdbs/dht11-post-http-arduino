/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 * Based on the Arduino Ethernet Web Client Example
 * and on the sketch "Sample Arduino Json Web Client" of the Arduino JSON library by Benoit Blanchon (bblanchon.github.io/ArduinoJson)
 */
#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11  
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 
 const char* ssid = "Bilal"; /*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 * Based on the Arduino Ethernet Web Client Example
 * and on the sketch "Sample Arduino Json Web Client" of the Arduino JSON library by Benoit Blanchon (bblanchon.github.io/ArduinoJson)
 */
#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11  
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 
 const char* ssid = "<SSID>"; 
const char* password = "<Password>";

// ARDUINO entry point #1: runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  delay(10);
  SPI.begin();

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
  
}

// ARDUINO entry point #2: runs over and over again forever
void loop() {
    if(sendRequest()) {
      Serial.print("HTTP POST request finished.");
    }
//  disconnect();
  wait();
}


// Send the HTTP POST request to the server
bool sendRequest() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();   
    String temstring;
    String humiditystring;
    temstring = String(t);
    humiditystring = String(h) ;
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
    
DynamicJsonDocument data(2048);
data["temperature"] = temstring;
data["humidity"] = humiditystring;

// Serialize JSON document
String json;
serializeJson(data, json);
HTTPClient http;

http.begin("http://URL:PORT/<PATH>");
http.POST(json);

// Read response
Serial.print(http.getString());

// Disconnect
http.end();
  return true;
}

// Pause for a 1 minute
void wait() {
  Serial.println("Wait 1 second");
  delay(1000);
}

// ARDUINO entry point #1: runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  delay(10);
  SPI.begin();

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
  
}

// ARDUINO entry point #2: runs over and over again forever
void loop() {
    if(sendRequest()) {
      Serial.print("HTTP POST request finished.");
    }
//  disconnect();
  wait();
}


// Send the HTTP POST request to the server
bool sendRequest() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();   
    String temstring;
    String humiditystring;
    temstring = String(t);
    humiditystring = String(h) ;
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");

DynamicJsonDocument data(2048);
data["temperature"] = temstring;
data["humidity"] = humiditystring;

// Serialize JSON document
String json;
serializeJson(data, json);
HTTPClient http;

http.begin("http://192.168.0.103:8080");
http.POST(json);

// Read response
Serial.print(http.getString());

// Disconnect
http.end();
  return true;
}

// Pause for a 1 minute
void wait() {
  Serial.println("Wait 1 second");
  delay(1000);
}