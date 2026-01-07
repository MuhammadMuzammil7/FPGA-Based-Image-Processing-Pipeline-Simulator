#ifndef CONVOLUTION_ENGINE_H
#define CONVOLUTION_ENGINE_H

#include "buffer.h"

class ConvolutionEngine {
public:
    static void apply(FrameBuffer* in, FrameBuffer* out);
};

#endif
