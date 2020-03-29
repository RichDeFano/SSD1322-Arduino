# SSD1322-Arduino
This driver was made for an NHD-3.12 OLED 256x64 screen. The NHD is driven by a SSD1322. The microcontroller used was a Bluefruit 32u4.

This driver is a WIP.

  Function Name: writeCommand
  Function Parameters: (int)binary
  Function Description: Write one byte of data to the display. As the data written should
    be classified as a command, DC is written low for the duration of the transfer.

  Function Name: writeData
  Function Parameters: (int)binary
  Function Description: Write one byte of data to the display. As the data written should
    be classified as data, DC is written high for the duration of the transfer.

  Function Name: defualtDisplay
  Function Parameters: N/A
  Function Description: Write the initialization sequence of commands to the display. The
    default display was made to function with an NHD-3.12 Display(SSD1322 Controller)
    Different displays may require tweaking of data sent.
    Please visit http://www.newhavendisplay.com/app_notes/SSD1322.pdf for an in depth 
    explination of each command.

  Function Name: drawCheckerboard
  Function Parameters: N/A
  Function Description: Writes a checkerboard to the display.

  Function Name: wipeDisplay
  Function Parameters: N/A
  Function Description: Clears the display of any pixels.

  Function Name: fillDisplay
  Function Parameters: N/A
  Function Description: Fills the display with all pixels at full brightness.

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

  Function Name: drawRect
  Function Parameters: (int) xPos - X Position of image
                      (int) yPos - Y position of image
                      (double) width - width of image in pixels
                      (double) height - height of image in pixels
  Function Description: Draw a rectangle covering the width and height inputted. This function
    is a simplified version of the draw bitmap function, where each pixel is hardcoded to maximum brightness.

  Function Name: nibbleCombine
  Function Parameters: (uint8_t) highNibble - The high four bits to be sent.
                      (uint8_T) lowNibble - The low four bits to be sent
  Function Description: Combines two nibbles into a byte, which is returned to be immediately
  sent to the display.
