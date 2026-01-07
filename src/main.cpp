#include "frame_reader.h"
#include "color_converter.h"
#include "smoothing_filter.h"
#include "convolution_engine.h"
#include "output_writer.h"

int main() {

    FrameBuffer* input = FrameReader::loadPPM("input.ppm");
    if (!input) return -1;

    FrameBuffer gray(input->width, input->height);
    FrameBuffer smooth(input->width, input->height);
    FrameBuffer edge(input->width, input->height);

    ColorConverter::apply(input, &gray);
    SmoothingFilter::apply(&gray, &smooth);
    ConvolutionEngine::apply(&smooth, &edge);

    OutputWriter::writePPM("output.ppm", &edge);

    delete input;
    return 0;
}