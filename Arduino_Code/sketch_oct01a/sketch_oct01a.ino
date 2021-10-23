#include <EEPROM.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10);
String voice;
int lamp=6;
int fan=7;
void setup() {
pinMode(lamp,OUTPUT);
pinMode(fan,OUTPUT);
}

void loop() {
while(mySerial.available()){
delay(3);
char c = mySerial.read();
voice+=c;}
if(voice.length() >0) {
Serial.println(voice);
if(voice=="light on")
{digitalWrite(lamp,HIGH);}
else if(voice=="light off")
{digitalWrite(lamp,LOW);}
else if(voice=="fan on")
{digitalWrite(fan,HIGH);}
else if(voice=="fan off")
{digitalWrite(fan,LOW);}
voice="";
}
}
