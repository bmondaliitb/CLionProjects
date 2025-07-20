#include "InferenceTool.h"
#include "Accessor.h"
#include "Transform.h"
#include <iostream>

void MiniInferenceTool::initialize(const std::vector<FeatureConfig>& metadata) {
    for (const auto& cfg : metadata) {
        if (cfg.type == "float") {
            auto acc = generateFloatAccessor(cfg.name);
            if (acc) {
                auto tr = std::make_unique<NormalizeFloat>(cfg.mean, cfg.std);
                m_stages.emplace_back(std::make_unique<FeatureStage<float, FloatVec>>(std::move(acc), std::move(tr)));
            }
        } else if (cfg.type == "int") {
            auto acc = generateIntAccessor(cfg.name);
            if (acc) {
                auto tr = std::make_unique<IdentityInt>();
                m_stages.emplace_back(std::make_unique<FeatureStage<int64_t, IntVec>>(std::move(acc), std::move(tr)));
            }
        }
    }
}

void MiniInferenceTool::execute(const Particle& p) {
    OutputDataMap out;
    for (const auto& stage : m_stages) {
        stage->evaluate(p, out);
    }

    std::cout << "[Exec] Feature Tensor:\n";
    for (const auto& [key, tensor] : out) {
        std::cout << "  " << key << ": ";
        if (std::holds_alternative<FloatVec>(tensor.second)) {
            for (float f : std::get<FloatVec>(tensor.second)) std::cout << f << " ";
        } else if (std::holds_alternative<IntVec>(tensor.second)) {
            for (int64_t i : std::get<IntVec>(tensor.second)) std::cout << i << " ";
        }
        std::cout << "\n";
    }

    float score = 0;
    if (out.count("clusterE")) score += std::get<FloatVec>(out["clusterE"].second)[0];
    if (out.count("mu")) score += std::get<FloatVec>(out["mu"].second)[0];
    if (out.count("nVertices")) score -= static_cast<float>(std::get<IntVec>(out["nVertices"].second)[0]);

    std::cout << "[Pred] Final Score: " << score << "\n";
}
