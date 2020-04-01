#include "display.h"
#include "bitmaps.h"
#include "bitmapStorage.h"

Display_obj disp;
Bitmap waddle_map((double)24,(double)24, (int)6, (size_t)sizeof(waddle_dee_0),waddle_table);

void setup() {
  disp.setupDisplay();
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
  

