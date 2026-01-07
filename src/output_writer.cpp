#include "output_writer.h"
#include <fstream>

void OutputWriter::writePPM(const char* filename, FrameBuffer* fb) {
    std::ofstream file(filename, std::ios::binary);

    file << "P6\n";
    file << fb->width << " " << fb->height << "\n";
    file << "255\n";

    file.write(reinterpret_cast<char*>(fb->data),
               fb->width * fb->height * 3);
}
