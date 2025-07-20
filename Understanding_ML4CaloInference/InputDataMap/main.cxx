#include <variant>
#include <vector>
#include <string>
#include <map>
#include <iostream>

// Feature data variants
using FloatVec = std::vector<float>;
using IntVec   = std::vector<int64_t>;

using DataVariant = std::variant<IntVec, FloatVec>;

// Input map type with shape
using Shape = std::vector<int>;
using FeatureData = std::pair<Shape, DataVariant>;
using InputDataMap = std::map<std::string, FeatureData>;

//Insert feature example
int main() {
    InputDataMap dataMap;

    // Feature: cluster energy (float), shape: [1]
    dataMap["clusterE"] = { {1}, FloatVec{ 120.5f } };

    // Feature: number of vertices (int), shape: [1]
    dataMap["nVertices"] = { {1}, IntVec{ 28 } };

    // Print contents
    for (const auto& [key, data] : dataMap) {
        std::cout << "Feature: " << key << ", shape: [";
        for (int dim : data.first) std::cout << dim << " ";
        std::cout << "] value: ";

        if (std::holds_alternative<FloatVec>(data.second)) {
            for (float v : std::get<FloatVec>(data.second)) std::cout << v << " ";
        } else if (std::holds_alternative<IntVec>(data.second)) {
            for (int64_t v : std::get<IntVec>(data.second)) std::cout << v << " ";
        }

        std::cout << std::endl; }
}


