#include <iostream>
#include <memory>
#include <variant>
#include <vector>
#include <string>
#include <map>

using FloatVec = std::vector<float>;
using IntVec   = std::vector<int64_t>;
using Shape    = std::vector<int>;
using TensorData = std::variant<FloatVec, IntVec>;
using OutputData = std::pair<Shape, TensorData>;
using OutputDataMap = std::map<std::string, OutputData>;

// Simulate inference output
void simulateModelInference(OutputDataMap& out) {
    // Simulate 1 batch of 2 predicted scores (e.g., classification probs)
    out["score"] = { {2}, FloatVec{ 0.8f, 0.2f } };

    // Simulate an integer output (e.g., predicted label)
    out["classIndex"] = { {1}, IntVec{ 0 } };
}

// Read prediction
void printPrediction(const OutputDataMap& out) {
    auto it = out.find("score");
    if (it != out.end()) {
        const auto& [shape, data] = it->second;

        std::cout << "Prediction scores: ";
        if (std::holds_alternative<FloatVec>(data)) {
            for (float v : std::get<FloatVec>(data)) {
                std::cout << v << " ";
            }
        }
        std::cout << "\n";
    }

    if (out.count("classIndex")) {
        const auto& data = out.at("classIndex").second;
        if (std::holds_alternative<IntVec>(data)) {
            std::cout << "Predicted class: " << std::get<IntVec>(data)[0] << "\n";
        }
    }
}

int main() {
    OutputDataMap output;
    simulateModelInference(output);
    printPrediction(output);
    return 0;
}

