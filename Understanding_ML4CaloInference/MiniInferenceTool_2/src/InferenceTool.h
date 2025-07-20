#pragma once
#include "Config.h"
#include "Stage.h"
#include <vector>
#include <memory>

class MiniInferenceTool {
public:
    void initialize(const std::vector<FeatureConfig>& metadata);
    void execute(const Particle& p);

private:
    std::vector<std::unique_ptr<StageBase>> m_stages;
};
