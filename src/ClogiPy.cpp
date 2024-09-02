#include <stdio.h>
#include <string.h>
#include "ClogiPy.h"

const char* extractFileName(const char* filePath) {
    const char* fileName = strrchr(filePath, '/');
    return (fileName != nullptr) ? fileName + 1 : filePath;
}