#include <iostream>
#include <memory>
#include <vector>

class Processor {
public:
    virtual void process() const = 0;
    virtual ~Processor() = default;
};

class TextProcessor : public Processor {
public:
    void process() const override {
        std::cout << "Processing text data\n";
    }
};

class ImageProcessor : public Processor {
public:
    void process() const override {
        std::cout << "Processing image data\n";
    }
};

class AudioProcessor : public Processor {
public:
    void process() const override {
        std::cout << "Processing audio data\n";
    }
};


int main() {
    std::vector<std::unique_ptr<Processor>> processors;

    processors.emplace_back(std::make_unique<TextProcessor>());
    processors.emplace_back(std::make_unique<ImageProcessor>());
    processors.emplace_back(std::make_unique<AudioProcessor>());

    for (const auto& processor : processors) {
        processor->process();  // Polymorphic call
    }

    return 0;
}

