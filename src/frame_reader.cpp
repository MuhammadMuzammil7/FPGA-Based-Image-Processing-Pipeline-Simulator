#include "frame_reader.h"
#include <fstream>
#include <iostream>
#include <string>

FrameBuffer* FrameReader::loadPPM(const char* filename) {
    std::ifstream file(filename, std::ios::binary);

    std::string format;
    int width, height, maxval;

    file >> format >> width >> height >> maxval;
    file.ignore(1); // consume the newline after header

    FrameBuffer* fb = new FrameBuffer(width, height);

    file.read(reinterpret_cast<char*>(fb->data),
              width * height * 3);

    return fb;
}
