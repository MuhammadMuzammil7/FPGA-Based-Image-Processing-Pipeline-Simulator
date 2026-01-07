#include "smoothing_filter.h"

void SmoothingFilter::apply(FrameBuffer* in, FrameBuffer* out) {
    for (int y = 1; y < in->height - 1; y++) {
        for (int x = 1; x < in->width - 1; x++) {
            int sum = 0;
            for (int dy = -1; dy <= 1; dy++)
                for (int dx = -1; dx <= 1; dx++)
                    sum += in->at(x + dx, y + dy).r;

            u8 avg = sum / 9;
            out->at(x, y) = { avg, avg, avg };
        }
    }
}
