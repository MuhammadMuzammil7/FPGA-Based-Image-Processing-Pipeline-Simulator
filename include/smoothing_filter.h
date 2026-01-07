#ifndef SMOOTHING_FILTER_H
#define SMOOTHING_FILTER_H

#include "buffer.h"

class SmoothingFilter {
public:
    static void apply(FrameBuffer* in, FrameBuffer* out);
};

#endif
