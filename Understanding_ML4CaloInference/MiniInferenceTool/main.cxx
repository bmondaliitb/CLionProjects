// 1. Simulated data input
struct Particle {
    float clusterE = 100.0f;
    float mu = 30.0f;
    int nVertices = 25;
};

// 2. Accessor interface and factory
// Accessor Base (templated over retrun type)
template<typename T>
class Accessor {
public:
    virtual T operator()(const Particle& p) const = 0;
    virtual ~Accessor() = default;
};

// Generic lambda accessor wrapper
template<typename T>
class LambdaAccessor : public Accessor<T> {
public:
    using FuncType = std::function<T(const Particle&)>;

    LambdaAccessor(std::string name, FuncType f) : m_name(std::move(name)), m_func(std::move(f)) {}

    T operator()(const Particle& p) const override {
        return m_func(p);
    }

    const std::string& name() const { return m_name; }

private:
    std::string m_name;
    FuncType m_func;
};


// Accessor Factory (mimics FeatureAccess::generateAccessor)
std::unique_ptr<LambdaAccessor<float>> generateFloatAccessor(const std::string& name) {
    if (name == "clusterE") {
        return std::make_unique<LambdaAccessor<float>>(name, [](const Particle& p) { return p.clusterE; });
    } else if (name == "mu") {
        return std::make_unique<LambdaAccessor<float>>(name, [](const Particle& p) { return p.mu; });
    }
    return nullptr;
}

//3. Transform Interface and Normalizer
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
    float operator()(float v) const override {
        return (v - mean_) / std_;
    }
};

// 4. FeatureStage + StageBase (polymorphic)

class StageBase {
public:
    virtual std::string name() const = 0;
    virtual void evaluate(const Particle&, std::map<std::string, float>&) const = 0;
    virtual ~StageBase() = default;
};

template<typename T>
class FeatureStage : public StageBase {
public:
    FeatureStage(std::unique_ptr<Accessor<T>> acc, std::unique_ptr<Transform<T>> tr)
        : m_accessor(std::move(acc)), m_transform(std::move(tr)) {}

    std::string name() const override {
        const auto* lambda = dynamic_cast<LambdaAccessor<T>*>(m_accessor.get());
        return lambda ? lambda->name() : "unknown";
    }

    void evaluate(const Particle& p, std::map<std::string, float>& out) const override {
        T raw = (*m_accessor)(p);
        T val = m_transform ? (*m_transform)(raw) : raw;
        out[name()] = static_cast<float>(val);  // stored as float for simplicity
    }

private:
    std::unique_ptr<Accessor<T>> m_accessor;
    std::unique_ptr<Transform<T>> m_transform;
};


// 5. Mini Inference Tool

class MiniInferenceTool {
public:
    void initialize(const std::vector<std::string>& featureList) {
        for (const auto& name : featureList) {
            auto acc = generateFloatAccessor(name);
            if (acc) {
                float mean = 100.0f, std = 10.0f;
                if (name == "mu") { mean = 40.0f; std = 5.0f; }

                m_stages.emplace_back(
                    std::make_unique<FeatureStage<float>>(std::move(acc), std::make_unique<NormalizeFloat>(mean, std))
                );
            } else {
                std::cerr << "Unknown feature: " << name << "\n";
            }
        }
    }

    void execute(const Particle& p) {
        std::map<std::string, float> inputMap;
        for (const auto& stage : m_stages) {
            stage->evaluate(p, inputMap);
        }

        std::cout << "[Exec] Collected inputs:\n";
        for (const auto& [k, v] : inputMap) {
            std::cout << "  " << k << ": " << v << "\n";
        }

        float score = 0.0f;
        for (const auto& [_, v] : inputMap) score += v;  // dummy inference logic

        std::cout << "[Pred] Score: " << score << "\n";
    }

private:
    std::vector<std::unique_ptr<StageBase>> m_stages;
};


// main

int main() {
    Particle particle;
    MiniInferenceTool tool;

    tool.initialize({ "clusterE", "mu" });  // from metadata
    tool.execute(particle);

    return 0;
}




