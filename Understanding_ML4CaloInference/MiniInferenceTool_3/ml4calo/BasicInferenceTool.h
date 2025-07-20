#pragma once
#include "xAODParticle.h"
#include "InferenceConfig.h"
#include "FeatureStage.h"
#include <memory>
#include <vector>

class BasicInferenceTool {
public:
    void initialize(const std::vector<FeatureConfig>& features);
    void execute(const xAODParticle& input);
private:
    std::vector<std::unique_ptr<StageBase>> m_stages;
};

