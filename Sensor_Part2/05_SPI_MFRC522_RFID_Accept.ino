#include "SPI.h"
#include "MFRC522.h"

#define RST_PIN 0 //D3
#define SS_PIN 2 // D4

MFRC522 mfrc522(SS_PIN, RST_PIN); //Create MFRC522 instance
int status = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //Initiate a serial communication
  SPI.begin(); //Initiate SPI bus
  mfrc522.PCD_Init(); // Initiate MFRC522

  Serial.println("카드를 리더기에 가까이 대 주세요");
  Serial.println();
  
}

void loop() {
  //Look for new cards
  if(!mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  //Select one of cards
  if(!mfrc522.PICC_ReadCardSerial()){
    return;
  }

  //Show UID on Serial monitor
  Serial.print("UID tag : ");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();

  if(content.substring(1) == "40 A5 C3 80") {
    Serial.println("승인된 카드입니다.");
    status =1;
    delay(3000);
  } else {
    Serial.println("승인되지 않은 카드입니다.");
    delay(3000);
  }
}
