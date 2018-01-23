#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

  union first_union{
    float f;
    byte b[4];}
  data;

  byte b1;
  byte b2[4];
  
void loop() {
  // receive 4bytes from slave
  Wire.requestFrom(0,4);// request 4 bytes from Slave ID #0
  int jj=0;
  while (Wire.available()) {
    b1 = Wire.read();
    data.b[jj]=b1;
    jj=jj+1;
    if(jj>3) jj=0;  
    }
  
   Serial.print("data.f=");
   Serial.println(data.f);
  
   data.f=random(1024);
   Serial.print("2:data.f=");
   Serial.println(data.f);
   
   b2[0]=data.b[0];   // divite integer to one byte
   b2[1]=data.b[1];   // divite integer to one byte
   b2[2]=data.b[2];   // divite integer to one byte
   b2[3]=data.b[3];   // divite integer to one byte
// send 4 bytes to slave
   Wire.beginTransmission(0); // transmit to device #0
   Wire.write(b2[0]);    // send one byte
   Wire.write(b2[1]);    // send one byte 
   Wire.write(b2[2]);    // send one byte 
   Wire.write(b2[3]);    // send one byte 
   Wire.endTransmission();    // stop transmitting
   delay(500);
}
