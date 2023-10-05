#include <mcp_can.h> // CAN BUS AĞI haberleşme kütüphanesi
#include <SPI.h>. // protokol kütüphanesi
#define buton 8
#define SPI_CS_PIN 9 // Can bus ağı pin numarası atama 

const int ledHIGH =1;
const int ledLOW=0;
unsigned char Led_Yak[8]={ledHIGH,1,2,3,4,5,6,7}; //unsigned pozitik sıfır olmayan bir değişken atama operatörüdür.
unsigned char Led_Sondur[8]={ledLOW,1,2,3,4,5,6,7};
MCP_CAN CAN(SPI_CS_PIN);

void setup() {
    Serial.begin(9600);
    pinMode(buton,INPUT);
    while (CAN_OK!= CAN.begin(CAN_500KBPS)){ // can bus: baudrate=500k baud oranı
     Serial.println("CAN BUS Shield Başlatma Hatası!!!");
     Serial.println("CAN BUS Shhield Tekrar Başlatılıyor...");
     delay(100);
    } 
    Serial.println("CAN BUS Shield Başlatması Başarılı:))");
}
void loop() {
  Serial.println("In loop"); // send data: id = 0x70, standart frame, data len=8, stmp: data buf, yani gönderilen veriyi açıklar ve görevini belirtir.
   int buton_1=digitalRead(buton);
   if(buton_1==HIGH){
     CAN.sendMsgBuf(0x70,0,8, Led_Yak); // Can protokolü için mesaj gönderimini sağlar.
   }
   else if(buton_1==LOW){
     CAN.sendMsgBuf(0x70,0,8 Led_Sondur);
   }
   delay(1000);
}
