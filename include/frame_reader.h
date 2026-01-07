#ifndef FRAME_READER_H
#define FRAME_READER_H

#include "buffer.h"

class FrameReader {
public:
    static FrameBuffer* loadPPM(const char* filename);
};

#endif
