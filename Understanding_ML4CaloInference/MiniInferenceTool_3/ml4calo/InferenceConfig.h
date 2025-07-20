#pragma once
#include <string>

struct FeatureConfig {
    std::string name;
    std::string type;  // "float" or "int"
    float mean = 0.0f;
    float std = 1.0f;
};

