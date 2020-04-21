#include <SPI.h>

#include "display.h"
#include "bitmaps.h"
#include "bitmapStorage.h"
#include "bitmapLetter.h"
#include "textStorage.h"

Display_obj disp;
Bitmap waddle_map((double)24,(double)24, (int)6, (size_t)sizeof(waddle_dee_0),waddle_table);

bitmapLetter fnt_controller(0,0,0x00,0,0);
bitmapLetter zelda_alph[0x7F];
bitmapLetter small_numbs[0xA];

char testStr[] = "Comfortably Numb";
char testStr2[] = "Pink Floyd";

char testStr3[] = "00:00";
char testStr4[] = "06:22";

void setup() {
  
  delay(1000);
  Serial.begin(115200); 
  disp.setupDisplay();
  delay(100);

  fnt_controller.createDictionary(zelda_alph,8,16);
  fnt_controller.createSmallDictionary(small_numbs,8,7);


  disp.drawText(180,0,zelda_alph,testStr,sizeof(testStr),0x00);
  delay(10);
  disp.drawText(180,16,zelda_alph,testStr2,sizeof(testStr2),0x00);
  delay(10);
  disp.drawText(180,45,small_numbs,testStr3,sizeof(testStr3),0x30);
  delay(10);
  disp.drawText(36,45,small_numbs,testStr4,sizeof(testStr4),0x30);
  delay(10);
  
  disp.drawRect(0,55,180,4,true,(uint8_t)0x0);
  delay(10);
  disp.drawBitmap(106,35,16,16,shuffle_bits,sizeof(shuffle_bits));
  delay(10);
  disp.drawBitmap(70,35,16,16,repeat_bits,sizeof(repeat_bits));
  delay(10);
  disp.drawBitmap(192,0,64,64,wall_bits1,sizeof(wall_bits1));
  delay(10);
  
  
  delay(1000);
  
}

void loop() {
disp.drawRect(0,55,180,4,true,(uint8_t)0x0);
  for (int w=180; w>0; w--)
  {
    disp.drawRect(0,55,w,4,true,(uint8_t)0x0);
    disp.drawRect(w,55,180-(w-1),4,true,(uint8_t)0xF);
    delay(100);
  }
  
}
