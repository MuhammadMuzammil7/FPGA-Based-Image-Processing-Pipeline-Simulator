#ifndef COLOR_CONVERTER_H
#define COLOR_CONVERTER_H

#include "buffer.h"

class ColorConverter {
public:
    static void apply(FrameBuffer* in, FrameBuffer* out);
};

#endif
