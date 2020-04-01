#include "bitmaps.h"

#ifndef Display_obj_h
#define Display_obj_h

class Bitmap;

class Display_obj
{
  public:
    Display_obj();
    ~Display_obj
    void setupDisplay();
    void wipeDisplay();
    void fillDisplay();
    void drawCheckerboard();
    void drawRect(int xPos, int yPos, double width, double height);
    void drawBitmap(int xPos, int yPos, double width, double height, unsigned char *bitmap, size_t buffSize);
    void drawAnimatedBitmap(int xPos, int yPos, Bitmap& b, int ms);

private:
    void writeCommand(int binary);
    void writeData(int binary);
    void defaultDisplay();
    uint8_t nibbleCombine(uint8_t highNibble, uint8_t lowNibble);
    
};
#endif

