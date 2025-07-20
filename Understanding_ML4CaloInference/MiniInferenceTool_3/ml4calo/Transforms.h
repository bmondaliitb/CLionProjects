#pragma once
#include "TransformBase.h"

class NormalizeFloat : public Transform<float> {
    float mean_, std_;
public:
    NormalizeFloat(float mean, float std) : mean_(mean), std_(std) {}
    float operator()(float v) const override { return (v - mean_) / std_; }
    std::unique_ptr<Transform<float>> clone() const override {
        return std::make_unique<NormalizeFloat>(mean_, std_);
    }
};

class IdentityInt : public Transform<int64_t> {
public:
    int64_t operator()(int64_t v) const override { return v; }
    std::unique_ptr<Transform<int64_t>> clone() const override {
        return std::make_unique<IdentityInt>();
    }
};

