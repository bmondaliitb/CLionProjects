#include "Accessor.h"

std::unique_ptr<LambdaAccessor<float>> generateFloatAccessor(const std::string& name) {
    if (name == "clusterE") return std::make_unique<LambdaAccessor<float>>(name, [](const Particle& p) { return p.clusterE; });
    if (name == "mu") return std::make_unique<LambdaAccessor<float>>(name, [](const Particle& p) { return p.mu; });
    return nullptr;
}

std::unique_ptr<LambdaAccessor<int64_t>> generateIntAccessor(const std::string& name) {
    if (name == "nVertices") return std::make_unique<LambdaAccessor<int64_t>>(name, [](const Particle& p) { return p.nVertices; });
    return nullptr;
}
