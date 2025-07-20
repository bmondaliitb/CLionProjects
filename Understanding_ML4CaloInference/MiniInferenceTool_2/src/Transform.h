#pragma once

template<typename T>
class Transform {
public:
    virtual T operator()(T value) const = 0;
    virtual ~Transform() = default;
};

class NormalizeFloat : public Transform<float> {
    float mean_, std_;
public:
    NormalizeFloat(float mean, float std) : mean_(mean), std_(std) {}
    float operator()(float v) const override { return (v - mean_) / std_; }
};

class IdentityInt : public Transform<int64_t> {
public:
    int64_t operator()(int64_t v) const override { return v; }
};
