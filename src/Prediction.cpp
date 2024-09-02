#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem> 
#include "pred_utils.h"
#include "Prediction.h"
#include "ClogiPy.h"

namespace fs = std::filesystem;

Result prediction::process(params& params_){
    cv::cvtColor(params_.image, params_.grayImage, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(params_.grayImage, params_.grayImage, params_.filter, 0);

    cv::Canny(params_.grayImage, params_.edges, params_.canny_min, params_.canny_max);
    cv::findContours(params_.edges, params_.contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    params_.result = params_.image.clone();

    WARN_LOG("Start to bbox");
    if(!this->bbox(params_)){
        // std::cout << "ERROR!" << std::endl;
        ERROR_LOG("ERROR");
    }
    RESULT_SUCCESS_LOG("Bbox implemented successfully");
    return SUCCESS;
}

Result prediction::bbox(params& params_){
    for (size_t i = 0; i < params_.contours.size(); i++) {
    params_.boundingRect |= cv::boundingRect(params_.contours[i]);
    }
    cv::rectangle(params_.result, params_.boundingRect, cv::Scalar(0, 255, 0), 2);
    return SUCCESS;
}


Result prediction::save_img(std::string inputImagePath, std::string outputFolderPath, params& params_){
    fs::path inputImageFullPath(inputImagePath);
    std::string outputImageName = "output_" + inputImageFullPath.filename().string();
    fs::path outputImagePath = fs::path(outputFolderPath) / outputImageName;
    cv::imwrite(outputImagePath.string(), params_.result);
    return SUCCESS;
}