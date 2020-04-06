#include "display.h"
#include "bitmaps.h"
#include "bitmapStorage.h"
#include "bitmapLetter.h"


Display_obj disp;
Bitmap waddle_map((double)24,(double)24, (int)6, (size_t)sizeof(waddle_dee_0),waddle_table);

char testStr[] = "Comfortably Numb";
char testStr2[] = "Pink Floyd";
bitmapLetter zeld_fnt(0,0,0x00,0,0);
bitmapLetter alphabet[0x7F];



void setup() {
  disp.setupDisplay();
  zeld_fnt.createDictionary(alphabet,8,16);
  delay(100);
}

void loop() {
disp.wipeDisplay();
delay(1000);
disp.fillDisplay();
delay(1000);
disp.wipeDisplay();
disp.drawCheckerboard();
delay(1000);
disp.drawBitmap(0,0,24,24,waddle_dee_0,sizeof(waddle_dee_0));
delay(1000);
disp.drawAnimatedBitmap(0,0,waddle_map,75);
disp.drawAnimatedBitmap(0,0,waddle_map,75);
delay(1000);
disp.drawText(184,0,alphabet,testStr,sizeof(testStr));
delay(10);
disp.drawText(184,16,alphabet,testStr2,sizeof(testStr2));
delay(10);

delay(1000);
  

