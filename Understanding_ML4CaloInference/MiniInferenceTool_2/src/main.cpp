#include "InferenceTool.h"
#include "Config.h"

int main() {
    Particle p;

    MiniInferenceTool tool;

    std::vector<FeatureConfig> config = {
        {"clusterE", "float", 100.0f, 10.0f},
        {"mu", "float", 40.0f, 5.0f},
        {"nVertices", "int"}
    };

    tool.initialize(config);
    tool.execute(p);

    return 0;
}
