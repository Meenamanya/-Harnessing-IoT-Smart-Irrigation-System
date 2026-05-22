#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define BLYNK_AUTH_TOKEN = "gp3Enka6mQ1tKSGuURgudD1ZUPQnIKDY"
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "project";       
char pass[] = "project007";    

#define SOIL_SENSOR A0
#define RELAY D6
#define BUZZER D7

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(115200);

    lcd.init();
    lcd.backlight();
    
    lcd.setCursor(0, 0);
    lcd.print("Connecting to");
    lcd.setCursor(0, 1);
    lcd.print("WiFi...");

    Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

    pinMode(SOIL_SENSOR, INPUT);
    pinMode(RELAY, OUTPUT);
    pinMode(BUZZER, OUTPUT);
}

void loop() {
    Blynk.run(); 

    int soilValue = analogRead(SOIL_SENSOR);
    int moisturePercent = map(soilValue, 1023, 0, 0, 100); 
    String status = "";

    // Determine Soil Moisture Status
    if (moisturePercent < 30) {
        status = "Low";
        digitalWrite(RELAY, HIGH);  
        digitalWrite(BUZZER, HIGH); 
    } 
    else if (moisturePercent >= 30 && moisturePercent < 60) {
        status = "Medium";
        digitalWrite(RELAY, LOW);
        digitalWrite(BUZZER, LOW);
    } 
    else {
        status = "High";
        digitalWrite(RELAY, LOW);
        digitalWrite(BUZZER, LOW);
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Moisture: ");
    lcd.print(moisturePercent);
    lcd.print("%  ");
    
    lcd.setCursor(0, 1);
    lcd.print("Status: ");
    lcd.print(status);
    lcd.print("   ");

    Blynk.virtualWrite(V0, moisturePercent);  
    Blynk.virtualWrite(V1, status);         

    delay(2000);
}