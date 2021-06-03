
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
                          
#define WIFI_SSID "VP" //Enter Your ssid/ Wifi name
#define WIFI_PASSWORD "22222233" //Password for it
#define FIREBASE_HOST "*************" //Add your Host Key from Firebase app, Remove https
#define FIREBASE_AUTH "****************" //Add Auth from Real time data base

// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;

// Declare global variable to store value
int val=0;
int n=0;

void setup() {
   pinMode(D0,OUTPUT);
  Serial.begin(115200);                                                      // Select the same baud rate if you want to see the datas on Serial Monitor

  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);


  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
}

void loop() {


// Firebase Error Handling And Reading Data From Specified Path ************************************************
//value = Firebase.getInt(firebaseData, "/users/BUZZER"); 
//Serial.print(value);

if (Firebase.getInt(firebaseData, "/users/BUZZER")) { // On successful Read operation, function returns 1  
    Serial.println("IM IN");
    if (firebaseData.dataType() == "int") {                            // print read data if it is integer
      
      val = firebaseData.intData();
      Serial.println(val);
     Serial.println("\n Change value at firebase console to see changes here."); 
      delay(1000);
      
 if (val==1) {  
      Serial.print("BUZZER is ON");  
      digitalWrite(D0,HIGH);       
       delay(5000); 
       Firebase.setInt(firebaseData, "/users/BUZZER",0);  
       digitalWrite(D0,LOW);
  }  
 else{  
   Serial.print("BUZZER is OFF");  
   digitalWrite(D0,LOW);  
 }  
    }

} else {
    Serial.println("ERROR");
  }
 
 }
