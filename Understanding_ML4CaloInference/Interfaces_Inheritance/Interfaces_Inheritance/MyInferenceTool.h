#include <iostream>
#include "IInferenceTool.h"

class MyInferenceTool : public IInferenceTool {
public:
    void initialize() override {
        std::cout << "Tool initialized." << std::endl;
    }

    void execute() override {
        std::cout << "Executing model inference..." << std::endl;
    }

    void preditc() override
    {
        std::cout<< "Prediction 42 "<< std::endl;
    }
};

