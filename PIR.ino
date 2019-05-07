int flameA0 = A0;
int sensorThresflame = 900;
int flameoutput=2;
int smokeA0 = A1;
int sensorThresgas = 250;
int gasout=3;
int IRA4 = A4;
int iroutput=4;
int sensorThresir = 100; // 15-20 range of threshold
void setup() {
  Serial.begin(9600);
   pinMode(smokeA0, INPUT);
  pinMode(gasout,OUTPUT);
   pinMode(flameA0, INPUT);
  pinMode(flameoutput,OUTPUT);
   pinMode(IRA4, INPUT);
 pinMode(iroutput,OUTPUT);
 pinMode(13,OUTPUT); pinMode(12,OUTPUT); pinMode(11,OUTPUT); pinMode(10,OUTPUT); 
 pinMode(9,OUTPUT); pinMode(8,OUTPUT); pinMode(7,OUTPUT); pinMode(6,OUTPUT);
 digitalWrite(13,HIGH); digitalWrite(12,HIGH); digitalWrite(11,HIGH); digitalWrite(10,HIGH);
 digitalWrite(9,LOW); digitalWrite(8,LOW); digitalWrite(7,LOW); digitalWrite(6,LOW);
  Serial.begin(9600);
}

void loop() {
  int analogSensorflame = analogRead(flameA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensorflame);
  // Checks if it has reached the threshold value
  if (analogSensorflame < sensorThresflame)
  {
    Serial.println("FLAME DETECTED");
    digitalWrite(flameoutput,HIGH);
  }
  else
  {
   digitalWrite(flameoutput,LOW);
   Serial.println("NO FLAME");
  }

  int analogSensorgas = analogRead(smokeA0);

  Serial.print("Pin A1: ");
  Serial.println(analogSensorgas);
  // Checks if it has reached the threshold value
  if (analogSensorgas > sensorThresgas)
  {
    digitalWrite(gasout, HIGH);
    Serial.println("SMOKE DETECTED");
  }
  else
  {
   digitalWrite(gasout, LOW);
   Serial.println("NO SMOKE");
  }

  int analogSensorir = analogRead(IRA4);
  Serial.print("Pin A4: ");
  Serial.println(analogSensorir);
  // Checks if it has reached the threshold value
  if (analogSensorir > sensorThresir)  {
    Serial.println("INTRUDER DETECTED");
    digitalWrite(iroutput,HIGH);
  }
  else {   
  Serial.println("FINE===");  
  digitalWrite(iroutput,LOW);
  }
  
  delay(1600);
}
