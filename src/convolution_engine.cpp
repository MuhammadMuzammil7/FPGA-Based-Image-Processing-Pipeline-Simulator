#include "convolution_engine.h"
#include <cstdlib>

void ConvolutionEngine::apply(FrameBuffer* in, FrameBuffer* out) {

    int sharp[3][3] = {
        { 0, -1,  0 },
        {-1,  5, -1 },
        { 0, -1,  0 }
    };

    FrameBuffer temp(in->width, in->height);

    for (int y = 1; y < in->height - 1; y++) {
        for (int x = 1; x < in->width - 1; x++) {
            int sum = 0;
            for (int dy = -1; dy <= 1; dy++)
                for (int dx = -1; dx <= 1; dx++)
                    sum += sharp[dy+1][dx+1] * in->at(x+dx, y+dy).r;

            sum = (sum < 0) ? 0 : (sum > 255 ? 255 : sum);
            temp.at(x, y) = { (u8)sum, (u8)sum, (u8)sum };
        }
    }

    int gx_kernel[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int gy_kernel[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    for (int y = 1; y < in->height - 1; y++) {
        for (int x = 1; x < in->width - 1; x++) {
            int gx = 0, gy = 0;

            for (int dy = -1; dy <= 1; dy++)
                for (int dx = -1; dx <= 1; dx++) {
                    gx += gx_kernel[dy+1][dx+1] * temp.at(x+dx, y+dy).r;
                    gy += gy_kernel[dy+1][dx+1] * temp.at(x+dx, y+dy).r;
                }

            int mag = std::abs(gx) + std::abs(gy);
            mag = (mag > 255) ? 255 : mag;

            out->at(x, y) = { (u8)mag, (u8)mag, (u8)mag };
        }
    }
}
