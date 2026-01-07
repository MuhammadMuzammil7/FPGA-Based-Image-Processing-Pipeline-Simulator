#ifndef OUTPUT_WRITER_H
#define OUTPUT_WRITER_H

#include "buffer.h"

class OutputWriter {
public:
    static void writePPM(const char* filename, FrameBuffer* fb);
};

#endif
