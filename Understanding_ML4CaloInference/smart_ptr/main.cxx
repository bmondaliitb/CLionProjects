#include <iostream>
#include <memory>

class Model {
public:
    void run() {
        std::cout << "Model is running inference.\n";
    }
};

class FeatureExtractor {
public:
    void extract(){
        std::cout<<" extract method called "<<std::endl;
    }
};

int main() {
    std::unique_ptr<Model> modelPtr = std::make_unique<Model>();

    modelPtr->run();  // Use it like a normal pointer

    std::unique_ptr<FeatureExtractor> FExtractPtr = std::make_unique<FeatureExtractor>();
    FExtractPtr->extract();
    // No need to delete — automatically cleaned up!
    return 0;
}

