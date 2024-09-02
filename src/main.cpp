#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem> 
#include "ClogiPy.h"
#include "pred_utils.h"
#include "Prediction.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    if (argc != 3 || std::string(argv[1]) != "--image") {
        std::cerr << "Usage: " << argv[0] << " --image <image_path>\n";
        return 1;
    }
    std::string inputImagePath = argv[2];

    if (!inputImagePath.empty() && inputImagePath.front() == '"' && inputImagePath.back() == '"') {
        inputImagePath = inputImagePath.substr(1, inputImagePath.size() - 2);
    }

    std::string outputFolderPath = "../outputs/";

    // Initialize params and prediction objects
    params params_;
    prediction prediction_;

    // Load image
    LOADING_LOG("Loading images ...");
    params_.image = cv::imread(inputImagePath);
    if (params_.image.empty()) {
        ERROR_LOG("Could not open or find the image.");
        return -1;
    }
    WARN_LOG("Start the processing ...");

    // Process image
    Result ret = prediction_.process(params_);
    if (!ret) {
        RESULT_FAIL_LOG("process failed.");
        return -1;
    }
    RESULT_SUCCESS_LOG("Prediction worked successfully");

    // Extract the filename from the input image path
    ret = prediction_.save_img(inputImagePath, outputFolderPath, params_);
    if (!ret) {
    RESULT_FAIL_LOG("Save image failed");
    return -1;
    }
    RESULT_SUCCESS_LOG("Image saved successfully");


    return 0;
}
