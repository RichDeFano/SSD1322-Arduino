# SSD1322-Arduino
This driver was made for an NHD-3.12 OLED 256x64 screen. The NHD is driven by a SSD1322. The microcontroller used was a Bluefruit 32u4.

This driver is a WIP.

The driver is helpful in cases where RAM is limited. The drawing functions will only store a maximum of four nibbles in memory at one time before pushing to the display, so it should work even for large images(64x64+) on uControllers with minimal ram(ATMega32u4 has 2.5kb), as long as there is room in progmem or some external storage for the images desired.

The driver currently supports the following features
-Initializing the display with proper settings such as internal clocks, voltages, and currents.
-Writing pixels to one of 16 grayscale colors (0-F)
-Drawing squares/rectangles that are filled solid or hollow
-Drawing Bitmaps
-Drawing animated bitmaps
-Drawing text(font stored as a bitmap in progmem)
