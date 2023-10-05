#include <SPI.h>
#include <mcp_can.h>
#define SPI_CS_PIN 9
#define LED 8

MCP_CAN CAN(SPI_CS_PIN);
void setup() {
    Serial.begin(9600);
    pinMode(LED,OUTPUT);
    while(CAN_OK!=CAN.begin(CAN_500KBPS){
       Serial.println("CAN BUS Shield Başlatma Hatası!!!");
       Serial.println("CAN BUS Shield Tekrar Başlatılıyor...");
       delay(100);
    }
    Serial.println("CAN BUS Shield Başlatması Başarılı:)");
}

void loop() {
  unsigned char len=0;
  unsigned char buf[8]={0,0,0,0,0,0,0,0}; //Buf: alınan mesajın verilerini saklamak için bellek tamponunu sağlar.
  if(CAN_MSGAVAIL==CAN.checkReceive()){
    CAN.readMsgBuf(&len,buf); // &len ifadesi alınan veri uzunluğunu saklamak için değişken adresidir.bu kod satırı ise mesajı okumak için işlev çağrısını temsil eder.
    unsigned long canId=CAN.getCnId();
    Serial.println("---------------");
    Serial.print("Verici ID: 0x");
    Serial.print(canId,HEX); // HEX: işlemin hangi sayısal tabanda kullanrak veriyi yazdırır. Veri hexadecimal(16 tabanında) formtta yazdırılır.
    for(int i=0;i<len;i++){
      Serial.print(buf[i]);
      Serial.print("\t");
      digitalWrite(LED,buf[0]);
      delay(100);
    }
    Serial.println();
  }
}
