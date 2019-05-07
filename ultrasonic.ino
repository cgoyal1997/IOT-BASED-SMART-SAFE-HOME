#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

float f=100.0;
int trigpin = D5;
int echopin = D6;
int flamedetect=D7;
int gasdetect=D8;
int irdetect=D0;
long duration;
int distance;

#define WIFI_SSID "NO"            //replace SSID with your wifi username
#define WIFI_PASSWORD "12345678"         //replace PWD with your wifi password                                   
#define FIREBASE_HOST "smarto-7050b.firebaseio.com"                       //link of api
#define FIREBASE_AUTH "xkKsh9QugSpT64ZrFSCj1m3droxVy0hcehipPV2H"
void setup() {
  
pinMode(trigpin, OUTPUT);

pinMode(echopin, INPUT);
Serial.begin(9600);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(flamedetect,INPUT);
pinMode(gasdetect,INPUT);
pinMode(irdetect,INPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  
  //connect to wifi
  while (WiFi.status() != WL_CONNECTED) {           
    delay(100);  
                    
    
  Serial.println("");
  Serial.println("WiFi connected");

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
//String sense=Firebase.getString("sensor");
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
duration = pulseIn(echopin, HIGH);
distance = duration * 0.034/2;

Serial.print("Distance : ");
Serial.print(distance);

Firebase.setFloat("waterlevel",distance);

String relay1=Firebase.getString("relay1");
delay(50);
String relay2=Firebase.getString("relay2");
delay(50);
String relay3=Firebase.getString("relay3");
delay(50);
String relay4=Firebase.getString("relay4");
delay(50);
Serial.print("Distance : ");
Serial.println(distance);
int flame=digitalRead(flamedetect);
int gas=digitalRead(gasdetect);
int ir=digitalRead(irdetect);
if(ir==HIGH)
Firebase.setString("ir","Intruder Detected");
else 
Firebase.setString("ir","Safe");
if(flame==HIGH)
Firebase.setString("flame","Flame Detected");
else 
Firebase.setString("flame","Flame Not Detected");
if(gas==HIGH)
Firebase.setString("gas","Gas Detected");
else 
Firebase.setString("gas","Gas Not Detected");

if(relay1=="ON") {  digitalWrite(D1,HIGH); }
  else { digitalWrite(D1,LOW);     }
if(relay2=="ON") {  digitalWrite(D2,HIGH); }
  else { digitalWrite(D2,LOW);     }
  if(relay3=="ON") {  digitalWrite(D3,HIGH); }
  else { digitalWrite(D3,LOW);     }
  if(relay4=="ON") {  digitalWrite(D4,HIGH); }
  else { digitalWrite(D4,LOW);     }

}

