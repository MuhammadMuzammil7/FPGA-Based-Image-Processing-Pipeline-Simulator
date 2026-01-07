# FPGA-Based Image Processing Pipeline Simulator in C++

This project implements a **C++ model of an FPGA-style image processing pipeline**, including **frame reading, color conversion, smoothing, convolution (sharpening & Sobel edge detection), and output writing**. It simulates how an FPGA processes streaming pixel data using buffers and modular processing blocks.

---

## Project Overview

The pipeline consists of the following stages:

1. **Frame Reader**
   - Loads a binary PPM (P6) image into memory (`FrameBuffer`).
   - Simulates an FPGA frame reader fetching a full frame into local memory.

2. **Color Converter**
   - Converts RGB images to grayscale using a simple average:
     ```
     gray = (R + G + B) / 3
     ```
   - Prepares the image for further processing.

3. **Smoothing Filter**
   - Applies a **3×3 mean filter** to reduce noise.
   - Each pixel is replaced by the average of its 3×3 neighborhood.

4. **Convolution Engine**
   - First applies a **sharpening filter** to enhance details:
     ```
     [ 0, -1,  0 ]
     [-1,  5, -1 ]
     [ 0, -1,  0 ]
     ```
   - Then applies **Sobel edge detection** using horizontal (`Gx`) and vertical (`Gy`) kernels:
     ```
     Gx = [ [-1, 0, 1], [-2, 0, 2], [-1, 0, 1] ]
     Gy = [ [-1, -2, -1], [0, 0, 0], [1, 2, 1] ]
     ```
   - Computes edge magnitude as `|Gx| + |Gy|`.

5. **Output Writer**
   - Writes the processed frame buffer to a **binary PPM image** (`output.ppm`), which can be viewed on any image viewer.

---

