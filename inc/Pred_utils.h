#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
typedef enum Result {
    SUCCESS = 1,
    FAILED = 0
} Result;

template<typename T>
using Vec2D = std::vector<std::vector<T>>;

class params{
public:
    cv::Mat image;
    cv::Mat grayImage;
    cv::Mat edges;
    cv::Mat result;
    cv::Size2i filter = cv::Size(11, 11);
    cv::Rect boundingRect;
    Vec2D<cv::Point> contours;
    std::string imageName;
    std::string outputFilePath;
    float total_time=0;
    const uint16_t canny_min = 50;
    const uint16_t canny_max = 150;
};

#pragma once