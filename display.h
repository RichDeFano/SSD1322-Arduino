#include "bitmaps.h"
#include "bitmapLetter.h"

#ifndef Display_obj_h
#define Display_obj_h

class Bitmap;

class Display_obj
{
  public:
    Display_obj(){};
    ~Display_obj(){};
    void setupDisplay();
    void wipeDisplay();
    void fillDisplay();
    void drawCheckerboard();
    void drawRect(double xPos, double yPos, double width, double height, bool fill=false, uint8_t fillShade=0x00);
    void drawBitmap(double xPos, double yPos, double width, double height, unsigned char *bitmap, size_t buffSize);
    void drawSegmentedBitmap(double xPos, double yPos, Bitmap& b, int ms);
    void drawAnimatedBitmap(double xPos, double yPos, Bitmap& b, int ms);
    void drawText(double xPos, double yPos, bitmapLetter alph[],char str[],int stringSize,uint8_t asciiBuff);
    
private:
    void writeCommand(int binary);
    void writeData(int binary);
    void sendTwoBytes(uint8_t highNib, uint8_t lowNib, uint8_t highNib2, uint8_t lowNib2);
    uint8_t Display_obj::getNibble(unsigned char* bitmap, double index);
    void defaultDisplay();
    uint8_t nibbleCombine(uint8_t highNibble, uint8_t lowNibble);
    
};
#endif

