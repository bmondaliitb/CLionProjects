#pragma once
#include "Particle.h"
#include <functional>
#include <memory>
#include <string>

template<typename T>
class Accessor {
public:
    virtual T operator()(const Particle& p) const = 0;
    virtual ~Accessor() = default;
};

template<typename T>
class LambdaAccessor : public Accessor<T> {
public:
    using FuncType = std::function<T(const Particle&)>;
    LambdaAccessor(std::string name, FuncType f) : m_name(std::move(name)), m_func(std::move(f)) {}
    T operator()(const Particle& p) const override { return m_func(p); }
    const std::string& name() const { return m_name; }

private:
    std::string m_name;
    FuncType m_func;
};

// Factories
std::unique_ptr<LambdaAccessor<float>> generateFloatAccessor(const std::string& name);
std::unique_ptr<LambdaAccessor<int64_t>> generateIntAccessor(const std::string& name);
