// ensure this library description is only included once
#ifndef Display_obj_h
#define Display_obj_h

// library interface description
class Display_obj
{
  // user-accessible "public" interface
  public:
    Display_obj();
    void setupDisplay();
    void writeCommand(int binary);
    void writeData(int binary);
    void defaultDisplay();
    void drawCheckerboard();
    void wipeDisplay();
    void fillDisplay();
    void drawBitmap(int xPos, int yPos, double width, double height, const char *bitmap, size_t buffSize);
    void drawRect(int xPos, int yPos, double width, double height);
    uint8_t nibbleCombine(uint8_t highNibble, uint8_t lowNibble);

};
#endif

