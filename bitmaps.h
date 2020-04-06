#include <stdint.h>
#include <Arduino.h>

#ifndef Bitmap_h
#define Bitmap_h


class Bitmap
{
  public:
    double getWidth(){return width;}
    double getHeight(){return height;}
    int getFrames(){return frames;}
    size_t getSize(){return size;}

    double setWidth(double w){width = w;}
    double setHeight(double h){height = h;}
    int setFrames(uint8_t f){frames = f;}
    size_t setSize(size_t s){size = s;}

    void setBitmap(const unsigned char* const b[], uint8_t f){
        for (int i = 0; i < f; i++)
        {
          unsigned char* frameAt = b[i];
          bitmap_frames[i] = frameAt;
        }
    }

    unsigned char* getBitmap(int f){return bitmap_frames[f];}
    
    Bitmap(double w, double h, int f, size_t s, const unsigned char* const b[]) : width(w), height(h), frames(f), size(s) {
        setBitmap(b,f);
    };
    ~Bitmap(){};

private:
    double width;
    double height;
    int frames;
    size_t size;
    unsigned char* bitmap_frames[];
};
#endif


