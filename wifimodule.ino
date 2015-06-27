#include <SoftwareSerial.h>
#include <ESP8266wifi.h>
SoftwareSerial myTAH(10,11);  //RX,TX
void setup() {
  Serial.begin(9600);
  while(!Serial)
  {
      
  }
  myTAH.begin(9600);
  delay(3000);
  String ok = "AT";
  myTAH.println(ok);
  while(myTAH.available())
  {
    Serial.write(myTAH.read());
  }
  delay(3000);
  String cwmode = "AT+CWMODE=3";
  myTAH.println(cwmode);
  while(myTAH.available())
  {
    Serial.write(myTAH.read());
  }
  delay(3000);
    String rst = "AT+RST";
  myTAH.println(rst);
  while(myTAH.available())
  {
    Serial.write(myTAH.read());
  }
  delay(3000);
  String mux = "AT+CIPMUX=1";
  myTAH.println(mux);
  while(myTAH.available())
  {
    Serial.write(myTAH.read());
  }
  delay(3000);
  String conn = "AT+CWJAP=\"Ashwini\",\"12345678\"";
  myTAH.println(conn);
  while(myTAH.available())
  {
    Serial.write(myTAH.read());
  }
  delay(3000);
  String ip = "AT+CIFSR";
  myTAH.println(ip);
  while(myTAH.available())
  {
    Serial.write(myTAH.read());
  }
  delay(3000);
  String strt = "AT+CIPSTART=4,\"TCP\",\"";
  strt += "http://data.sparkfun.com/output/KJ1pL2jgjdfEOWp0XVWE";
  strt += "\",80";
  l1:
  myTAH.println(strt);
  if(myTAH.find("Error"))
  {
    Serial.println("AT+CIPSTART error");
    myTAH.println("AT+CIPMUX=1");
    goto l1;
  }
  String send_str = "AT+CIPSEND=4,18";
  myTAH.println(send_str);
  
  //String 
}
void loop() {

  if(myTAH.available())
  {
   Serial.write(myTAH.read()); 
  }
  if(Serial.available())
  {
    myTAH.write(Serial.read()); 
  }    
  //aread();
}
