#include <vector>
#include <string>
#include <memory>
#include <iostream>

class Feature {
public:
    virtual void compute() const = 0;
    virtual ~Feature() = default;
};

class EnergyFeature : public Feature {
public:
    void compute() const override {
        std::cout << "Computing energy feature\n";
    }
};

class TimingFeature : public Feature {
public:
    void compute() const override {
        std::cout << "Computing timing feature\n";
    }
};

class ShapeFeature : public Feature {
public:
    void compute() const override {
        std::cout << "Computing shape feature\n";
    }
};


std::unique_ptr<Feature> createFeature(const std::string& type) {
    if (type == "energy") return std::make_unique<EnergyFeature>();
    if (type == "timing") return std::make_unique<TimingFeature>();
    if (type == "shape") return std::make_unique<ShapeFeature>();
    return nullptr;
}

int main() {
    std::vector<std::string> metadata = { "energy", "timing", "shape" };
    std::vector<std::unique_ptr<Feature>> features;

    for (const auto& type : metadata) {
        auto feature = createFeature(type);
        if (feature) {
            features.push_back(std::move(feature));
        } else {
            std::cout << "Unknown feature type: " << type << std::endl;
        }
    }

    for (const auto& f : features) {
        f->compute();  // polymorphic call
    }

    return 0;
}

