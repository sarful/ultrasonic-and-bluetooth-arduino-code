#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX | TX
int channel1 =4;
int channel2 = 5;
int channel3 =6;
int channel4 = 7;
int channel5 = 8;

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup()
{
 
  mySerial.begin(9600);
  Serial.begin(9600);
   //Serial.begin(38400);
   delay(200);
   pinMode(channel1, OUTPUT); 
    pinMode(channel2, OUTPUT); 
     pinMode(channel3, OUTPUT); 
      pinMode(channel4, OUTPUT);
       pinMode(channel5, OUTPUT);
       
  digitalWrite(channel1, LOW);
   digitalWrite(channel2, LOW);
    digitalWrite(channel3, LOW);
     digitalWrite(channel4, LOW);
       digitalWrite(channel5, LOW); 

          pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
}

void loop()
{    
char Char_string = mySerial.read();

if(Char_string =='1'){ 
  digitalWrite(channel1, HIGH);
  delay(400);  
}
if(Char_string =='A'){ 
  digitalWrite(channel1,LOW);
  delay(400);     
}
if(Char_string =='2'){ 
  digitalWrite(channel2,HIGH);
  delay(400);     
}
if(Char_string =='B'){ 
  digitalWrite(channel2,LOW);
  delay(400);     
}
if(Char_string =='3'){ 
  digitalWrite(channel3,HIGH);
  delay(400);     
}
if(Char_string =='C'){ 
  digitalWrite(channel3,LOW);
  delay(400);     
}
if(Char_string =='4'){ 
  digitalWrite(channel4,HIGH);
  delay(400);     
}
if(Char_string =='D'){ 
  digitalWrite(channel4,LOW);
  delay(400);     
}

// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance<=10)
{
  digitalWrite(channel5,HIGH);
  Serial.print("Water Supply On ");
  }
  else{
    digitalWrite(channel5,LOW);
  Serial.print("Water Supply Off ");
    }
}

