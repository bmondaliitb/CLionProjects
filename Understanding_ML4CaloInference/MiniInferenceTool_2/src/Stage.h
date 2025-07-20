#pragma once
#include "Accessor.h"
#include "Transform.h"
#include "Particle.h"
#include <map>
#include <variant>
#include <vector>
#include <memory>
#include <string>

using FloatVec = std::vector<float>;
using IntVec = std::vector<int64_t>;
using Shape = std::vector<int>;
using Tensor = std::pair<Shape, std::variant<FloatVec, IntVec>>;
using OutputDataMap = std::map<std::string, Tensor>;

class StageBase {
public:
    virtual std::string name() const = 0;
    virtual void evaluate(const Particle&, OutputDataMap&) const = 0;
    virtual ~StageBase() = default;
};

template<typename T, typename VecT>
class FeatureStage : public StageBase {
public:
    FeatureStage(std::unique_ptr<Accessor<T>> acc, std::unique_ptr<Transform<T>> tr)
        : m_accessor(std::move(acc)), m_transform(std::move(tr)) {}

    std::string name() const override {
        auto* lambda = dynamic_cast<LambdaAccessor<T>*>(m_accessor.get());
        return lambda ? lambda->name() : "unknown";
    }

    void evaluate(const Particle& p, OutputDataMap& out) const override {
        T raw = (*m_accessor)(p);
        T val = m_transform ? (*m_transform)(raw) : raw;
        VecT vec = { val };
        out[name()] = { {1}, std::move(vec) };
    }

private:
    std::unique_ptr<Accessor<T>> m_accessor;
    std::unique_ptr<Transform<T>> m_transform;
};
