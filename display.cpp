#include <SPI.h>
#include "Arduino.h"
#include "display.h"
#include <stdint.h>
#define CS A0
#define RST A1
#define DC A2

void Display_obj::setupDisplay()
{
  //Setup pinmodes for the various pins
  pinMode(DC, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(RST, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(SS, OUTPUT);
  pinMode(MISO, INPUT);

  //Itinialize values for pins
  digitalWrite(DC, LOW);  //Command vs Data
  digitalWrite(CS, LOW);  //Chip Select
  digitalWrite(MOSI, LOW);  //Master Out Slave In
  digitalWrite(SCK, LOW); //Clock
  digitalWrite(SS, HIGH); //Slave Select
  digitalWrite(MISO, LOW);  //Master In Slave Out

  digitalWrite(RST, LOW); //pull /RES (pin #16) low
  delay(0.2); //keep /RES low for minimum 200μs
  digitalWrite(RST, HIGH);  //pull /RES high
  delay(0.2); //wait minimum 200μs before sending commands

  SPI.begin();  //Open SPI Connection
  defaultDisplay(); //Set Default Settings
  writeCommand(0xA5); //Turn on Display
  wipeDisplay();  //Clear all pixels possibly stored in GDDRAM of display
  Serial.println("Display Initialized.");
  delay(100);

}

/*
  Function Name: writeCommand
  Function Parameters: (int)binary
  Function Description: Write one byte of data to the display. As the data written should
    be classified as a command, DC is written low for the duration of the transfer.
*/
void Display_obj::writeCommand(int binary)
{
  digitalWrite(DC, LOW);
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
  SPI.transfer(binary);
  SPI.endTransaction();
}

/*
  Function Name: writeData
  Function Parameters: (int)binary
  Function Description: Write one byte of data to the display. As the data written should
    be classified as data, DC is written high for the duration of the transfer.
*/
void Display_obj::writeData(int binary)
{
  digitalWrite(DC, HIGH);
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
  SPI.transfer(binary);
  SPI.endTransaction();
}

/*
  Function Name: defualtDisplay
  Function Parameters: N/A
  Function Description: Write the initialization sequence of commands to the display. The
    default display was made to function with an NHD-3.12 Display(SSD1322 Controller)
    Different displays may require tweaking of data sent.
    Please visit http://www.newhavendisplay.com/app_notes/SSD1322.pdf for an in depth 
    explination of each command.
*/
void Display_obj::defaultDisplay()
{

  //---Set Command Lock
  writeCommand(0xFD);
  writeData(0x12);

  //---Set Display Off
  writeCommand(0xAE);

  //---Set Row Address
  writeCommand(0x75);
  writeData(0x00);
  writeData(0x3F);

  //---Set Column Address
  writeCommand(0x15);
  writeData(0x1C);
  writeData(0x5B);

  //---Set Display Clock **
  writeCommand(0xB3);
  writeData(0x52);  //91

  //---Set Multiplex Ratio
  writeCommand(0xCA);
  writeData(0x3F);

  //---Set Display Offsett
  writeCommand(0xA2);
  writeData(0x00);

  //---Set Start Line
  writeCommand(0xA1);
  writeData(0x00);

  //---Set Remap Format **
  writeCommand(0xA0);
  writeData(0x00);  //16
  writeData(0x01);  //01
  //0x14?

  //---Set GPIO
  writeCommand(0xB5);
  writeData(0x00);

  //---Set Function Selection
  writeCommand(0xAB);
  writeData(0x01);

  //---Set Display Enhancement A 
  writeCommand(0xB4);
  writeData(0xA0);
  writeData(0xFD);

  //---Set Constrast Current
  writeCommand(0xC1);
  writeData(0x9F);

  //---Set Master Current
  writeCommand(0xC7);
  writeData(0x0F);

  //---Set Gray Scale Table Linear
  writeCommand(0xB9);
  writeCommand(0x00);

  //---Set Phase Length **
  writeCommand(0xB1);
  writeData(0xE2);  //E2

  //--Display Enhancement B
  //writeCommand(0xD1)
  //writeData(0x20);

  //---Set Precharge Voltage 
  writeCommand(0xBB);
  writeData(0x1F);

  //---Set Precharge Period
  writeCommand(0xB6);
  writeData(0x08);

  //---Set VCHOMH **
  writeCommand(0xBE);
  writeData(0x07);  //07

  //---Set Display Mode 
  writeCommand(0xA6);

  //---Disable Partial Display

  //---Turn On Display 
  writeCommand(0xAF);
}

/*
  Function Name: drawCheckerboard
  Function Parameters: N/A
  Function Description: Writes a checkerboard to the display.
*/
void Display_obj::drawCheckerboard()
{
  unsigned int i, j;

  writeCommand(0x15); //Set Column Address
  writeData(0x00);
  writeData(0x77);

  writeCommand(0x75); //Set Row Address
  writeData(0x00);
  writeData(0x7F);

  writeCommand(0x5C); //Set Write Ram

  for (i = 0; i < 64; i++)
  {
    for (j = 0; j < 240; j++)
    {
      writeData(0xF0);
    }

    for (j = 0; j < 240; j++)
    {
      writeData(0x0F);
    }
  }
}

/*
  Function Name: wipeDisplay
  Function Parameters: N/A
  Function Description: Clears the display of any pixels.
*/
void Display_obj::wipeDisplay()
{
  unsigned int i, j;

  writeCommand(0xA4); //Display Off

  writeCommand(0x15); //Set Column Address
  writeData(0x00);
  writeData(0x77);

  writeCommand(0x75); //Set Row Address
  writeData(0x00);
  writeData(0x7F);

  writeCommand(0x5C); //Set Write Ram

  for (i = 0; i < 64; i++)
  {
    for (j = 0; j < 240; j++)
    {
      writeData(0x00);
      writeData(0x00);
    }
  }
  writeCommand(0xA6); //Display On
}

/*
  Function Name: fillDisplay
  Function Parameters: N/A
  Function Description: Fills the display with all pixels at full brightness.
*/
void Display_obj::fillDisplay()
{
  unsigned int i, j;

  writeCommand(0x15); //Set Column Address
  writeData(0x00);
  writeData(0x77);

  writeCommand(0x75); //Set Row Address
  writeData(0x00);
  writeData(0x7F);

  writeCommand(0x5C); //Set Write Ram

  for (i = 0; i < 64; i++)
  {
    for (j = 0; j < 240; j++)
    {
      writeData(0xFF);
      writeData(0xFF);
    }
  }
}

/*
  Function Name: drawBitmap
  Function Parameters: (int) xPos - X Position of image
                      (int) yPos - Y position of image
                      (double) width - width of image in pixels
                      (double) height - height of image in pixels
                      (const char *) bitmap - pointer to the bitmap in PROGMEM
                      (size_t) buffSize - Size of incoming bitmap.
  Function Description: Draw a bitmap converted C array that is stored in PROGMEM into the correct pixels on the display.
  The bitmap has been made for a 4bpp Grayscale. There are 4 bits of information for each pixel, ranging 0-F. The display has
  a very customizable way to write pixels, and row/column settings can be changed. This WILL mess up the function, and may
  not read the values in the correct order.
*/
void Display_obj::drawBitmap(double xPos, double yPos, double width, double height, unsigned char *bitmap, size_t buffSize)
{
  unsigned int i, j, h, w;
  double col, loopWidth, columnNums;
  int fillWithBlank, mapSize, mapCount, padBeginning, paddedColsAdded;
  uint8_t zeroNib, fNib, lowBinMask, highBinMask;
  bool onLowNibble;

  lowBinMask = B00001111;
  highBinMask = B11110000;
  onLowNibble = false;
  //////////////////////////////////////////////////////////////////////////////
  //This section will read the incoming bitmap and save it to a buffer
  //to be used later to fetch data from the array, one nibble at a time.
  //////////////////////////////////////////////////////////////////////////////
  uint8_t tempBuffer[buffSize]; //Initialize a buffer of the same size
  uint8_t nibbleBuffer[buffSize *2];  //Initialize a buffer of double the size(as each nibble is seperated)

  int nibCount = 0;
  for (int q = 0; q < buffSize; q++)  //For each entry in the bitmap, copy the high and low nibbles to a new buffer.
  {
    tempBuffer[q] = pgm_read_byte(&bitmap[q]);
    uint8_t highNib = (tempBuffer[q] &highBinMask);
    uint8_t lowNib = (tempBuffer[q] &lowBinMask);
    highNib = highNib >> 4;
    nibbleBuffer[nibCount] = highNib;
    nibCount++;
    nibbleBuffer[nibCount] = lowNib;
    nibCount++;
  }
  //////////////////////////////////////////////////////////////////////////////
  //This section checks to see if the image needs any padding.
  //If an image is offset anything other than a factor of 4, it will need 
  //padding as a column address points to a group of four colums.
  //If an images width then needs padding at the end of the column to contain
  //The proper image, this is also calculated.
  //////////////////////////////////////////////////////////////////////////////
  if ((int) xPos % 4 != 0)
  {
    padBeginning = ((int) xPos % 4);
  }
  else
  {
    padBeginning = 0;
  }

  if ((int)(width + padBeginning) % 4 != 0)
  {
    fillWithBlank = 4 - ((int)(width + padBeginning) % 4);
  }
  else
  {
    fillWithBlank = 0;
  }

  if (fillWithBlank == 4)
  {
    fillWithBlank = 0;
  }

  if (fillWithBlank + padBeginning >= 4)
  {
    paddedColsAdded = 1;
  }
  else
  {
    paddedColsAdded = 0;
  }

  loopWidth = ceil((width / 4));
  columnNums = floor(xPos / 4);

  if (width <= 4)
  {
    col = 0x1C;
  }
  else
  {
    col = ceil((width / 4)) - 1 + 0x1C + columnNums + paddedColsAdded;
  }

  //////////////////////////////////////////////////////////////////////////////
  //This section will create a new bitmap, by writing each nibble to a new buffer, mapToDraw.
  //Zeroes will be added to the bitmap order without breaking the image contained within
  //the padding.
  //////////////////////////////////////////////////////////////////////////////
  mapSize = (width + fillWithBlank + padBeginning) *(height);
  mapCount = 0;
  zeroNib = 0x0;
  fNib = 0xF;
  uint8_t mapToDraw[mapSize *2];
  nibCount = 0;
  //Nibbles are added in the order of High_Byte(lowNibble,HighNibble), Low_Byte(lowNibble,HighNibble)
  for (h = 0; h < height; h++)
  {
    //Serial.println(" ");
    if (padBeginning == 1)
    {
      //Serial.print("1 F F F");

      mapToDraw[mapCount] = nibbleBuffer[nibCount];
      mapCount++;
      nibCount++;
      mapToDraw[mapCount] = zeroNib;
      mapCount++;
      mapToDraw[mapCount] = nibbleBuffer[nibCount];
      mapCount++;
      nibCount++;
      mapToDraw[mapCount] = nibbleBuffer[nibCount];
      mapCount++;
      nibCount++;
    }
    if (padBeginning == 2)
    {
      //Serial.print("1 1 F F");
      mapToDraw[mapCount] = zeroNib;
      mapCount++;
      mapToDraw[mapCount] = zeroNib;
      mapCount++;
      mapToDraw[mapCount] = nibbleBuffer[nibCount];
      mapCount++;
      nibCount++;
      mapToDraw[mapCount] = nibbleBuffer[nibCount];
      mapCount++;
      nibCount++;
    }
    if (padBeginning == 3)
    {
      //Serial.print("1 1 1 F");
      mapToDraw[mapCount] = zeroNib;
      mapCount++;
      mapToDraw[mapCount] = zeroNib;
      mapCount++;
      mapToDraw[mapCount] = nibbleBuffer[nibCount];
      mapCount++;
      nibCount++;
      mapToDraw[mapCount] = zeroNib;
      mapCount++;
    }
    if (padBeginning == 0)
    {
      //Serial.print("F F F F");
      mapToDraw[mapCount] = nibbleBuffer[nibCount + 1];
      mapToDraw[mapCount + 1] = nibbleBuffer[nibCount];
      mapToDraw[mapCount + 2] = nibbleBuffer[nibCount + 3];
      mapToDraw[mapCount + 3] = nibbleBuffer[nibCount + 2];

      mapCount = mapCount + 4;
      nibCount = nibCount + 4;
    }

    for (w = 1; w < (loopWidth + paddedColsAdded); w++) //Col
    {

      if (w == (loopWidth + paddedColsAdded) - 1)
      {

        if (fillWithBlank == 3)
        {
            //Serial.print(" F 0 0 0");
          mapToDraw[mapCount] = zeroNib;
          mapCount++;
          mapToDraw[mapCount] = nibbleBuffer[nibCount];
          nibCount++;
          mapToDraw[mapCount] = zeroNib;
          mapCount++;
          mapToDraw[mapCount] = zeroNib;
          mapCount++;
        }
        else if (fillWithBlank == 2)
        {
            //Serial.print(" F F 0 0");
          mapToDraw[mapCount] = nibbleBuffer[nibCount];
          mapCount++;
          nibCount++;
          mapToDraw[mapCount] = nibbleBuffer[nibCount];
          mapCount++;
          nibCount++;
          mapToDraw[mapCount] = zeroNib;
          mapCount++;
          mapToDraw[mapCount] = zeroNib;
          mapCount++;
        }
        else if (fillWithBlank == 1)
        {
            //Serial.print(" F F F 0");
          mapToDraw[mapCount] = nibbleBuffer[nibCount];
          mapCount++;
          nibCount++;
          mapToDraw[mapCount] = nibbleBuffer[nibCount];
          mapCount++;
          nibCount++;
          mapToDraw[mapCount] = zeroNib;
          mapCount++;
          mapToDraw[mapCount] = nibbleBuffer[nibCount];
          mapCount++;
          nibCount++;
        }
        else if (fillWithBlank == 0)
        {
            //Serial.print(" F F F F");
          mapToDraw[mapCount] = nibbleBuffer[nibCount + 1];
          mapToDraw[mapCount + 1] = nibbleBuffer[nibCount];
          mapToDraw[mapCount + 2] = nibbleBuffer[nibCount + 3];
          mapToDraw[mapCount + 3] = nibbleBuffer[nibCount + 2];

          mapCount = mapCount + 4;
          nibCount = nibCount + 4;
        }
      }
      else
      {
        //Serial.print(" F F F F");
        mapToDraw[mapCount] = nibbleBuffer[nibCount + 1];
        mapToDraw[mapCount + 1] = nibbleBuffer[nibCount];
        mapToDraw[mapCount + 2] = nibbleBuffer[nibCount + 3];
        mapToDraw[mapCount + 3] = nibbleBuffer[nibCount + 2];

        mapCount = mapCount + 4;
        nibCount = nibCount + 4;
      } //Else not on edge
    } //Col Loop 
  } //Height Loop
  //////////////////////////////////////////////////////////////////////////////
  //The display is ready to recieve the array to be drawn to the screen.
  //The column and row addresses are set, which tells the display what portion
  //of the screen is being written.
  //////////////////////////////////////////////////////////////////////////////
  writeCommand(0x15); //Set Column Address
  writeData(0x1C + columnNums); // + ceil(xPos/4));
  writeData(col);

  writeCommand(0x75); //Set Row Address
  writeData(yPos);
  if (height != 1)
  {
    writeData((height - 1) + yPos);
  }
  else
  {
    writeData(height + yPos);
  }

  writeCommand(0x5C); //Set Write Ram

  int count = 0;
  for (i = 0; i < height; i++)  //Row
  {
    //Serial.println(" ");
    for (j = 0; j < (loopWidth + paddedColsAdded); j++) //Col
    {
      uint8_t highNib = (uint8_t)(mapToDraw[count]);
      uint8_t lowNib = (uint8_t)(mapToDraw[count + 1]);
      uint8_t highNib2 = (uint8_t)(mapToDraw[count + 2]);
      uint8_t lowNib2 = (uint8_t)(mapToDraw[count + 3]);
      uint8_t byteToSend = nibbleCombine(highNib, lowNib);
      uint8_t byteToSend2 = nibbleCombine(highNib2, lowNib2);

      writeData(byteToSend2);
      writeData(byteToSend);

      count = count + 4;
    }
  }
}

/*
  Function Name: drawRect
  Function Parameters: (int) xPos - X Position of image
                      (int) yPos - Y position of image
                      (double) width - width of image in pixels
                      (double) height - height of image in pixels
  Function Description: Draw a rectangle covering the width and height inputted. This function
    is a simplified version of the draw bitmap function, where each pixel is hardcoded to maximum brightness.
*/
void Display_obj::drawRect(double xPos, double yPos, double width, double height, bool fill, uint8_t fillShade)
{
  unsigned int i, j, h, w;
  double col, loopWidth, columnNums;
  int fillWithBlank, mapSize, mapCount, padBeginning, paddedColsAdded;
  uint8_t zeroNib, fNib;
  //////////////////////////////////////////////////////////////////////////////
  //This section checks to see if the image needs any padding.
  //If an image is offset anything other than a factor of 4, it will need 
  //padding as a column address points to a group of four colums.
  //If an images width then needs padding at the end of the column to contain
  //The proper image, this is also calculated.
  //////////////////////////////////////////////////////////////////////////////
  if ((int) xPos % 4 != 0)
  {
    padBeginning = ((int) xPos % 4);
  }
  else
  {
    padBeginning = 0;
  }

  if ((int)(width + padBeginning) % 4 != 0)
  {
    fillWithBlank = 4 - ((int)(width + padBeginning) % 4);
  }
  else
  {
    fillWithBlank = 0;
  }

  if (fillWithBlank == 4)
  {
    fillWithBlank = 0;
  }

  if (fillWithBlank + padBeginning >= 4)
  {
    paddedColsAdded = 1;
  }
  else
  {
    paddedColsAdded = 0;
  }

  loopWidth = ceil((width / 4));
  columnNums = floor(xPos / 4);

  if (width <= 4)
  {
    col = 0x1C;
  }
  else
  {
    col = ceil((width / 4)) - 1 + 0x1C + columnNums + paddedColsAdded;
  }

  //////////////////////////////////////////////////////////////////////////////
  //This section will create a new bitmap, by writing each nibble to a new buffer, mapToDraw.
  //Zeroes will be added to the bitmap order without breaking the image contained within
  //the padding.
  //////////////////////////////////////////////////////////////////////////////
  mapSize = (width + fillWithBlank + padBeginning) *(height);
  mapCount = 0;
  zeroNib = 0x0;
  fNib = 0xF;
  uint8_t mapToDraw[mapSize *2];

  for (h = 0; h < height; h++)
  {
    //Serial.println(" ");
    if (padBeginning == 1)
    {
      //Serial.print("1 F F F");
      mapToDraw[mapCount] = fNib;
      mapToDraw[mapCount + 1] = zeroNib;
      if ((fill == false) || (h == 0) || (h == height - 1))
      {
        mapToDraw[mapCount + 2] = fNib;
        mapToDraw[mapCount + 3] = fNib;
      }
      else
      {
        mapToDraw[mapCount + 2] = fillShade;
        mapToDraw[mapCount + 3] = fillShade;
      }
      mapCount = mapCount + 4;
    }
    if (padBeginning == 2)
    {
      //Serial.print("1 1 F F");
      mapToDraw[mapCount] = zeroNib;
      mapToDraw[mapCount + 1] = zeroNib;
      if ((fill == false) || (h == 0) || (h == height - 1))
      {
        mapToDraw[mapCount + 2] = fNib;
        mapToDraw[mapCount + 3] = fNib;
      }
      else
      {
        mapToDraw[mapCount + 2] = fillShade;
        mapToDraw[mapCount + 3] = fNib;
      }
      mapCount = mapCount + 4;
    }
    if (padBeginning == 3)
    {
      //Serial.print("1 1 1 F");
      mapToDraw[mapCount] = zeroNib;
      mapToDraw[mapCount + 1] = zeroNib;
      mapToDraw[mapCount + 2] = fNib;
      mapToDraw[mapCount + 3] = zeroNib;
      mapCount = mapCount + 4;
    }
    if (padBeginning == 0)
    {
      //Serial.print("F F F F");
      if ((fill == false) || (h == 0) || (h == height - 1))
      {
        mapToDraw[mapCount] = fNib;
        mapToDraw[mapCount + 1] = fNib;
        mapToDraw[mapCount + 2] = fNib;
        mapToDraw[mapCount + 3] = fNib;
      }
      else
      {
        mapToDraw[mapCount] = fillShade;
        mapToDraw[mapCount + 1] = fNib;
        mapToDraw[mapCount + 2] = fillShade;
        mapToDraw[mapCount + 3] = fillShade;
      }
      mapCount = mapCount + 4;
    }

    for (w = 1; w < (loopWidth + paddedColsAdded); w++) //Col
    {

      if (w == (loopWidth + paddedColsAdded) - 1)
      {

        if (fillWithBlank == 3)
        {
            //Serial.print(" F 0 0 0");
          mapToDraw[mapCount] = zeroNib;
          mapToDraw[mapCount + 1] = fNib;
          mapToDraw[mapCount + 2] = zeroNib;
          mapToDraw[mapCount + 3] = zeroNib;
          mapCount = mapCount + 4;
        }
        else if (fillWithBlank == 2)
        {
            //Serial.print(" F F 0 0");
          if ((fill == false) || (h == 0) || (h == height - 1))
          {
            mapToDraw[mapCount] = fNib;
            mapToDraw[mapCount + 1] = fNib;
          }
          else
          {
            mapToDraw[mapCount] = fillShade;
            mapToDraw[mapCount + 1] = fNib;
          }
          mapToDraw[mapCount + 2] = zeroNib;
          mapToDraw[mapCount + 3] = zeroNib;
          mapCount = mapCount + 4;
        }
        else if (fillWithBlank == 1)
        {
            //Serial.print(" F F F 0");
          if ((fill == false) || (h == 0) || (h == height - 1))
          {
            mapToDraw[mapCount] = fNib;
            mapToDraw[mapCount + 1] = fNib;
          }
          else
          {
            mapToDraw[mapCount] = fillShade;
            mapToDraw[mapCount + 1] = fillShade;
          }
          mapToDraw[mapCount + 2] = zeroNib;
          mapToDraw[mapCount + 3] = fNib;
          mapCount = mapCount + 4;
        }
        else if (fillWithBlank == 0)
        {
            //Serial.print(" F F F F");
          if ((fill == false) || (h == 0) || (h == height - 1))
          {
            mapToDraw[mapCount] = fNib;
            mapToDraw[mapCount] = fNib;
            mapToDraw[mapCount] = fNib;
            mapToDraw[mapCount] = fNib;
            mapCount = mapCount + 4;
          }
          else
          {
            mapToDraw[mapCount] = fillShade;
            mapToDraw[mapCount + 1] = fillShade;
            mapToDraw[mapCount + 2] = fNib;
            mapToDraw[mapCount + 3] = fillShade;
            mapCount = mapCount + 4;
          }
        }
      }
      else
      {
        //Serial.print(" F F F F");
        if ((fill == false) || (h == 0) || (h == height - 1))
        {
          mapToDraw[mapCount] = fNib;
          mapToDraw[mapCount + 1] = fNib;
          mapToDraw[mapCount + 2] = fNib;
          mapToDraw[mapCount + 3] = fNib;
        }
        else
        {
          mapToDraw[mapCount] = fillShade;
          mapToDraw[mapCount + 1] = fillShade;
          mapToDraw[mapCount + 2] = fillShade;
          mapToDraw[mapCount + 3] = fillShade;
        }
        mapCount = mapCount + 4;
      } //Else not on edge
    } //Col Loop 
  } //Height Loop

  //////////////////////////////////////////////////////////////////////////////
  //The display is ready to recieve the array to be drawn to the screen.
  //The column and row addresses are set, which tells the display what portion
  //of the screen is being written.
  //////////////////////////////////////////////////////////////////////////////
  writeCommand(0x15); //Set Column Address
  writeData(0x1C + columnNums); // + ceil(xPos/4));
  writeData(col);

  writeCommand(0x75); //Set Row Address
  writeData(yPos);
  if (height != 1)
  {
    writeData((height - 1) + yPos);
  }
  else
  {
    writeData(height + yPos);
  }

  writeCommand(0x5C); //Set Write Ram

  int count = 0;
  for (i = 0; i < height; i++)  //Row
  {
    for (j = 0; j < (loopWidth + paddedColsAdded); j++) //Col
    {
      uint8_t highNib = (uint8_t)(mapToDraw[count]);
      uint8_t lowNib = (uint8_t)(mapToDraw[count + 1]);
      uint8_t highNib2 = (uint8_t)(mapToDraw[count + 2]);
      uint8_t lowNib2 = (uint8_t)(mapToDraw[count + 3]);
      uint8_t byteToSend = nibbleCombine(highNib, lowNib);
      uint8_t byteToSend2 = nibbleCombine(highNib2, lowNib2);

      writeData(byteToSend2);
      writeData(byteToSend);

      count = count + 4;
    }
  }
}

/*
  Function Name: nibbleCombine
  Function Parameters: (uint8_t) highNibble - The high four bits to be sent.
                      (uint8_T) lowNibble - The low four bits to be sent
  Function Description: Combines two nibbles into a byte, which is returned to be immediately
  sent to the display.
*/
uint8_t Display_obj::nibbleCombine(uint8_t highNibble, uint8_t lowNibble)
{

  uint8_t emptyMask = B00000000;
  highNibble = highNibble << 4;
  emptyMask = emptyMask + highNibble + lowNibble;
  return emptyMask;
}

/*
  Function Name: drawAnimatedBitmap
  Funciton Parameters: (int) xPos - The x position of the bitmap
                      (int yPos) - The y position of the bitmap
                      (Bitmap& b) - The Bitmap object that the user wishes to draw
                      (int ms) - The delay in ms between each frame
  Function Description: Draw Each frame of a full bitmap with a certain delay.
  */
void Display_obj::drawAnimatedBitmap(double xPos, double yPos, Bitmap &b, int ms)
{

  size_t currSize = b.getSize();
  uint8_t numbOfFrames = b.getFrames();
  double width = b.getWidth();
  double height = b.getHeight();

  for (int i = 0; i < numbOfFrames; i++)
  {
    unsigned char *frameAt = b.getBitmap(i);  //Return the pointer to a certain bitmap frame
    drawBitmap(xPos, yPos, width, height, frameAt, currSize); //Draw the frame to the screen
    delay(ms);  //Wait a certain amount of time before drawing another
  }
}