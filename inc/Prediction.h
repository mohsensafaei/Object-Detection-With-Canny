#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include "Pred_utils.h"


class prediction{
    public:
    Result process(params& params_);
    Result bbox(params& params_);
    Result save_img(std::string inputImagePath, std::string outputFolderPath, params& params_);
    };

#pragma once