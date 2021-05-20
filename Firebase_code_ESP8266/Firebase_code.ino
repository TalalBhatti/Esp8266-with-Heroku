#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
 
// Set these to run example.
#define FIREBASE_HOST “nodemcubuzzer-5390a-default-rtdb.firebaseio.com”
#define FIREBASE_AUTH “If2dlSitkRyp7s9FwTm24FSubIfKRTtSxOjJHf0x”
#define WIFI_SSID “Cyber Talal” //provide ssid (wifi name)
#define WIFI_PASSWORD “talalalam100” //wifi password
int n = 0;  
void setup()
{ 
 
 // Debug console
 Serial.begin(9600);
// connect to wifi.
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 Serial.print(“connecting”);
 while (WiFi.status() != WL_CONNECTED)
 {
 Serial.print(“.”);
 delay(500);
 }
 Serial.println();
 Serial.print(“connected: “);
 Serial.println(WiFi.localIP());
 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
if(Firebase.failed())
 {
 Serial.print(Firebase.error());
 }
 else{
 
 Serial.print(“Firebase Connected”);
 Firebase.setString(“Senura/Value”,”0");
 }
 pinMode(D1,OUTPUT);  
// Firebase.set("BUZZER_STATUS",0);  
}
 
void loop()
{
for(int i = 0; i <= 100; i++)
 { 
    Firebase.setInt(“/Senura/Value”,i);
    delay(1000);
 }
 n=Firebase.getInt("BUZZER_STATUS");  
 if (n==1) {  
      Serial.print("BUZZER is ON");  
      digitalWrite(D1,HIGH);  
      Serial.println(Firebase.error());    
      return;  
       delay(5000); 
       Firebase.set("BUZZER_STATUS",0); 
  }  
 else{  
   Serial.print("BUZZER is OFF");  
   digitalWrite(D1,LOW);  
 }  
}
