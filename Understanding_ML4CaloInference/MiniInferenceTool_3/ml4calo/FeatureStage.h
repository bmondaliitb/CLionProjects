#pragma once
#include "xAODParticle.h"
#include "FeatureAccess.h"
#include "TransformBase.h"
#include <map>
#include <variant>
#include <vector>
#include <memory>
#include <string>

using FloatVec = std::vector<float>;
using IntVec   = std::vector<int64_t>;
using Shape    = std::vector<int>;
using Tensor   = std::pair<Shape, std::variant<FloatVec, IntVec>>;
using OutputDataMap = std::map<std::string, Tensor>;

class StageBase {
public:
    virtual std::string name() const = 0;
    virtual void evaluate(const xAODParticle&, OutputDataMap&) const = 0;
    virtual std::unique_ptr<StageBase> clone() const = 0;
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

    void evaluate(const xAODParticle& p, OutputDataMap& out) const override {
        T raw = (*m_accessor)(p);
        T val = m_transform ? (*m_transform)(raw) : raw;
        out[name()] = { {1}, VecT{ val } };
    }

    std::unique_ptr<StageBase> clone() const override {
        return std::make_unique<FeatureStage<T, VecT>>(m_accessor->clone(), m_transform ? m_transform->clone() : nullptr);
    }

private:
    std::unique_ptr<Accessor<T>> m_accessor;
    std::unique_ptr<Transform<T>> m_transform;
};

