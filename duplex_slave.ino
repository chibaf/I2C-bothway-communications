#include <Wire.h>

// byte b1=0;

void setup() {
  Serial.begin(9600);
  Wire.begin(0);// Slave ID #0
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
}

  union first_union{
    float f;
    byte b[4];}
  data;
  int jj=0;
  byte b2[4];
  byte b1;

void loop() {
}

void requestEvent() {
  data.f=random(1024);  // generate data which is sent to master
  b2[0]=data.b[0];
  b2[1]=data.b[1];
  b2[2]=data.b[2];
  b2[3]=data.b[3];
  Serial.print("data.f=");
  Serial.println(data.f);
  Wire.write(b2,4);  // send 4bytes data to master
}

  void receiveEvent(int howMany) // receive 4bytes data from master
{
    int jj=0;
  while (Wire.available()) {
    b1 = Wire.read();
    data.b[jj]=b1;
    jj=jj+1;
    if(jj>3) jj=0;
  }
    Serial.print("2: data.f=");
    Serial.println(data.f);
  delay(500);
}
