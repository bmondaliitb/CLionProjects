#pragma once
#include "xAODParticle.h"
#include <functional>
#include <memory>
#include <string>

template<typename T>
class Accessor {
public:
    virtual T operator()(const xAODParticle& p) const = 0;
    virtual std::unique_ptr<Accessor<T>> clone() const = 0;
    virtual ~Accessor() = default;
};

template<typename T>
class LambdaAccessor : public Accessor<T> {
public:
    using FuncType = std::function<T(const xAODParticle&)>;
    LambdaAccessor(std::string name, FuncType f) : m_name(std::move(name)), m_func(std::move(f)) {}
    T operator()(const xAODParticle& p) const override { return m_func(p); }
    std::unique_ptr<Accessor<T>> clone() const override {
        return std::make_unique<LambdaAccessor<T>>(m_name, m_func);
    }
    const std::string& name() const { return m_name; }

private:
    std::string m_name;
    FuncType m_func;
};

// Factories
std::unique_ptr<LambdaAccessor<float>> generateFloatAccessor(const std::string& name);
std::unique_ptr<LambdaAccessor<int64_t>> generateIntAccessor(const std::string& name);

