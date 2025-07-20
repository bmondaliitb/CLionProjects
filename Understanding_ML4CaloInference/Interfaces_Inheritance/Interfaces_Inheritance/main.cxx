#include "MyInferenceTool.h"

int main() {
    IInferenceTool* tool = new MyInferenceTool();
    tool->initialize();
    tool->execute();
    tool->preditc();
    delete tool;
    return 0;
}

