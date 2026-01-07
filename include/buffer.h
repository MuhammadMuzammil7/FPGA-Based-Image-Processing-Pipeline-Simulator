#ifndef BUFFER_H
#define BUFFER_H

#include "pixel.h"

struct FrameBuffer {
    int width;
    int height;
    Pixel* data;

    FrameBuffer(int w, int h) : width(w), height(h) {
        data = new Pixel[w * h];
    }

    ~FrameBuffer() {
        delete[] data;
    }

    Pixel& at(int x, int y) {
        return data[y * width + x];
    }
};

#endif
