#include "LedControl.h"

// 32*8 LED Display DIN --> ESP-12F D7
// 32*8 LED Display CS  --> ESP-12F D6
// 32*8 LED Display CLK --> ESP-12F D5
int DIN = 41;
int CS =  40;
int CLK = 42;


LedControl  lc1 = LedControl ( DIN , CLK , CS , 1 ); 

void setup()
{
	 //初始化address 0-3的8*8点阵屏
    for(int i = 0; i < 4; i++)
    {
      	lc1.shutdown(i, false);       //启动时，关闭省电模式
      	lc1.setIntensity(i, 0);       //亮度设置
      	lc1.clearDisplay(i);         //清除显示
    }
}

// display four col
void Display_4col(byte character[][4],int device_num,int col,int point)
{
  for(int i = 0;i<4;i++)
  {
    lc1.setColumn(device_num,point+i,character[col][i]);
  }
}

//   0 0
//   - -
//   ● ●
byte eye_display[][4] = {
  {0x3C,0x42,0x42,0x3C},
  {0x3C,0x7E,0x7E,0x3C},
  {0x10,0x10,0x10,0x10},
};


void loop() {
  // put your main code here, to run repeatedly:
  // lc1.setRow(0,3, 0x7C);
  for(int i = 0; i < 2; i++)
  {
    Display_4col(eye_display, 2, 0, 2);
    Display_4col(eye_display, 1, 0, 2);
    delay(1350);
    Display_4col(eye_display, 2, 2, 2);
    Display_4col(eye_display, 1, 2, 2);
    delay(150);
  }

}
