
#include <SoftwareSerial.h>
#include <ESP8266wifi.h>
SoftwareSerial myTAH(10,11);  //RX,TX
void setup() {
  Serial.begin(9600);
  while(!Serial)
  {
      
  }
  myTAH.begin(9600);
  delay(1000);
  String ok = "AT";
  myTAH.println(ok);
  delay(1000);
  String cwmode = "AT+CWMODE=3";
  myTAH.println(cwmode);
  delay(1000);
  String rst = "AT+RST";
  myTAH.println(rst);
  delay(1000);
  String mux = "AT+CIPMUX=1";
  myTAH.println(mux);
  delay(1000);
  String conn = "AT+CWJAP=\"Ashwini\",\"12345678\"";
  myTAH.println(conn);
  delay(1000);
  String ip = "AT+CIFSR";
  myTAH.println(ip);
  delay(1000);
  String strt = "AT+CIPSTART=4,\"TCP\",\"";
  strt += "54.86.132.254";
  strt += "\",80";
  l1:
  myTAH.println(strt);
  if(myTAH.find("Error"))
  {
    Serial.println("AT+CIPSTART error");
    myTAH.println("AT+CIPMUX=1");
    goto l1;
  }
  //String sent="AT+CIPSEND=4,40";
  //myTAH.println(strt);
  Serial.write("Success!!!");
  
  
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
