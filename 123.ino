#include<EEPROM.h>
uint8_t uidbuffer0[16]={0};
uint8_t uidbuffer1[16]={0};
uint8_t uidbuffer2[16]={0};
uint8_t uidbuffer3[16]={0};
void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Start read");
  EEPROM.begin(4096);//操作地址不確定
  for(int addr=0;addr<4096;addr++)//write
  {
    int data=uidbuffer0[16];//將讀卡完成的資料輸入進EEPROM
    EEPROM.write(addr,data);
  }
  EEPROM.commit();//儲存
  Serial.println("End write");
   for(int addr=0;addr<4096;addr++)//read
  {
    int data=EEPROM.read(addr);
    if(addr==4095)
    {
    for(int a=0;a<=16;a++)
    {
     EEPROM.write(uidbuffer0[a],data);//將儲存在EEPROM的資料輸入到buffer
    }
    }
  }
  
 Serial.print(uidbuffer0[16]);
 Serial.println("end read");
}

void loop() {
  // put your main code here, to run repeatedly:

}
