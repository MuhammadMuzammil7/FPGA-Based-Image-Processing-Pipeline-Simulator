#include "color_converter.h"

void ColorConverter::apply(FrameBuffer* in, FrameBuffer* out) {
    for (int y = 0; y < in->height; y++) {
        for (int x = 0; x < in->width; x++) {
            Pixel p = in->at(x, y);
            u8 gray = (p.r + p.g + p.b) / 3;
            out->at(x, y) = { gray, gray, gray };
        }
    }
}
