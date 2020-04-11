#include <stdint.h>
#include <Arduino.h>

#ifndef bitmapLetter_h
#define bitmapLetter_h

#define asciiMax 0x7F


class bitmapLetter
{
  public:
  		bitmapLetter() : width(0), height(0), ascii(0),size(0),bitmap(nullptr){
  		};
  		bitmapLetter(int w, int h, uint16_t as, size_t s, const unsigned char* bmp) : width(w), height(h), ascii(as), size(s), bitmap(bmp) {
  		};
  		~bitmapLetter(){};

  		int getWidth(){return width;}
  		int getHeight(){return height;}
  		size_t getSize(){return size;}
  		unsigned char* getLetter(){return bitmap;}
  		uint16_t getAscii(){return ascii;}
  		static void createDictionary(bitmapLetter alphabet[], int w, int h);
  		static void createSmallDictionary(bitmapLetter alphabet[], int w, int h);

private:
	int width;
	int height;
	size_t size;
	uint16_t ascii;
	unsigned char* bitmap;
};
#endif
