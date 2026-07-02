#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

// Define pins for sensors and outputs
#define DHTPIN D4              // Pin where the DHT11 is connected
#define DHTTYPE DHT11          // DHT11 sensor
#define BUZZER_PIN D2          // Pin for the buzzer
#define LED_PIN D5             // Pin for the LED
#define SMOKE_SENSOR_PIN A0    // Analog pin for the smoke sensor (MQ-2)
#define GAS_SENSOR_PIN A0      // Analog pin for the gas sensor (MQ-135) - same as smoke sensor for testing
#define IRSENSORPIN D6         // IR sensor pin

// Initialize the DHT11 sensor
DHT dht(DHTPIN, DHTTYPE);

// ThingSpeak API credentials
const char* writeAPIKey = "YOUR_THINGSPEAK_API_KEY";  // Replace with your ThingSpeak API key
const char* server = "api.thingspeak.com";

// WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";          // Your WiFi SSID
const char* password = "YOUR_WIFI_PASSWORD";  // Your WiFi Password

// Set threshold values
const float TEMP_THRESHOLD = 30.0;  // Temperature threshold in °C
const float HUMIDITY_THRESHOLD = 70.0; // Humidity threshold in %
const int MQ2_THRESHOLD = 300;       // MQ-2 gas/smoke threshold (adjust based on calibration)

WiFiClient client;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Initialize sensor and output pins
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(IRSENSORPIN, INPUT);  // Set IR sensor pin as input

  // Start DHT sensor
  dht.begin();
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Read temperature and humidity from DHT11 sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read values from smoke sensor (MQ-2)
  int smokeLevel = analogRead(SMOKE_SENSOR_PIN);
  
  // Read IR sensor for object detection
  int irValue = digitalRead(IRSENSORPIN);
  int objectDetected = (irValue == LOW) ? 1 : 0;  // 1 for detected, 0 for not detected

  // Print sensor data to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Smoke Level: ");
  Serial.println(smokeLevel);

  Serial.print("Object Detection: ");
  Serial.println(objectDetected ? "Object detected" : "No object detected");

  // Check thresholds and take action
  if (temperature > TEMP_THRESHOLD || humidity > HUMIDITY_THRESHOLD || smokeLevel > MQ2_THRESHOLD) {
    Serial.println("WARNING: Threshold exceeded!");
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);

    // Send data to ThingSpeak
    sendToThingSpeak(temperature, humidity, smokeLevel, objectDetected);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  // Wait for 2 seconds before the next reading
  delay(2000);
}

void sendToThingSpeak(float temperature, float humidity, int smokeLevel, int objectDetected) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Build URL for the GET request
    String url = "http://" + String(server) + "/update?api_key=" + String(writeAPIKey) +
                 "&field1=" + String(temperature) +
                 "&field2=" + String(humidity) +
                 "&field3=" + String(smokeLevel) +
                 "&field4=" + String(objectDetected);  // New field for object detection

    // Print URL to serial for debugging
    Serial.print("Sending data to URL: ");
    Serial.println(url);

    // Send the request to ThingSpeak
    http.begin(client, url);
    http.setTimeout(10000);  // Set timeout to 10 seconds
    int httpResponseCode = http.GET();

    // Check for HTTP errors
    if (httpResponseCode > 0) {
      Serial.print("ThingSpeak Response code: ");
      Serial.println(httpResponseCode);
      if (httpResponseCode == 200) {
        Serial.println("Data sent successfully to ThingSpeak!");
      } else {
        Serial.println("Error: Non-200 response from ThingSpeak.");
      }
    } else {
      Serial.print("Error sending data to ThingSpeak: ");
      Serial.println(http.errorToString(httpResponseCode));
    }
    http.end(); // Free resources
  } else {
    Serial.println("WiFi not connected.");
  }
}