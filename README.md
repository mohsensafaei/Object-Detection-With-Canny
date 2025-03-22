# Object Detection with Canny Edge Detection

This project implements object detection using OpenCV's Canny edge detection algorithm. It processes input images to detect objects and draws bounding boxes around them.

## Features

- Image preprocessing with Gaussian blur
- Canny edge detection
- Contour detection
- Bounding box visualization
- Automatic output image saving

## Prerequisites

- C++17 or higher
- OpenCV library
- CMake (version 3.10 or higher)

## Installation

1. Install OpenCV:
```bash
sudo apt-get install libopencv-dev
```

2. Clone the repository:
```bash
git clone https://github.com/yourusername/Object-Detection-With-Canny.git
cd Object-Detection-With-Canny
```

3. Build the project:
```bash
mkdir build && cd build
cmake ..
make
```

## Usage

Run the program with an input image:

```bash
./PREDICT --image path/to/your/image.jpg
```

The processed image will be saved in the `outputs` directory with the prefix "output_".

## Project Structure

- `src/`: Source files
- `inc/`: Header files
- `outputs/`: Directory for processed images
- `img_dataset/`: Directory for test images
