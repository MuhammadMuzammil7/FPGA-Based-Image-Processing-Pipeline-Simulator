CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp \
      src/frame_reader.cpp \
      src/color_converter.cpp \
      src/smoothing_filter.cpp \
      src/convolution_engine.cpp \
      src/output_writer.cpp

TARGET = runfile

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

