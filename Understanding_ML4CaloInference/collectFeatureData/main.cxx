#include <iostream>
#include <memory>
#include <variant>
#include <vector>
#include <string>
#include <map>

using FloatVec = std::vector<float>;
using IntVec   = std::vector<int64_t>;
using Shape    = std::vector<int>;
using DataVariant = std::variant<IntVec, FloatVec>;
using FeatureData = std::pair<Shape, DataVariant>;
using InputDataMap = std::map<std::string, FeatureData>;

// Base Accessor interface
class FeatureAccessor {
public:
    virtual std::string name() const = 0;
    virtual void collect(InputDataMap& map) const = 0;
    virtual ~FeatureAccessor() = default;
};


// Concrete Accessors
class EnergyAccessor : public FeatureAccessor {
public:
    std::string name() const override { return "clusterE"; }
    void collect(InputDataMap& map) const override {
        map[name()] = { {1}, FloatVec{ 100.0f } };
    }
};

class VertexCountAccessor : public FeatureAccessor {
public:
    std::string name() const override { return "nVertices"; }
    void collect(InputDataMap& map) const override {
        map[name()] = { {1}, IntVec{ 30 } };
    }
};


// collectFeatureData() simulation
void collectFeatureData(
    const std::vector<std::unique_ptr<FeatureAccessor>>& accessors,
    InputDataMap& map)
{
    for (const auto& acc : accessors) {
        acc->collect(map);
    }
}


int main() {
    std::vector<std::unique_ptr<FeatureAccessor>> accessors;
    accessors.emplace_back(std::make_unique<EnergyAccessor>());
    accessors.emplace_back(std::make_unique<VertexCountAccessor>());

    InputDataMap data;
    collectFeatureData(accessors, data);

    for (const auto& [key, value] : data) {
        std::cout << "Feature: " << key << " [shape:";
        for (auto s : value.first) std::cout << " " << s;
        std::cout << "] value: ";

        if (std::holds_alternative<FloatVec>(value.second)) {
            for (auto v : std::get<FloatVec>(value.second)) std::cout << v << " ";
        } else if (std::holds_alternative<IntVec>(value.second)) {
            for (auto v : std::get<IntVec>(value.second)) std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

