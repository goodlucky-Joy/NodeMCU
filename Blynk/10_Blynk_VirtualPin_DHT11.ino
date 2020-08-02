//#include<ESP8266WiFi.h>
//#include<BlynkSimpleEsp8266.h>

#include<Wire.h>
#include<BH1750.h>
BH1750 lightMeter;

char auth[]="";
char ssid[]="";
char pass[]="";

void setup(){
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin(BH1750::ONE_TIME_HIGH_RES_MODE,0x5C);
//  Blynk.begin(auth,ssid,pass);
}


void loop()
{
  float lux=lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
//  Blynk.virtualWrite(V2,lux);
  delay(1000);
//  Blynk.run();
  
}
