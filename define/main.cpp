#include <iostream>
#define printWarning(x) \
  std::cout<<x<<std::endl

int main() {
    //std::cout << "Hello, World!" << std::endl;
    printWarning("Hello World! using preprocessor directive");
    return 0;
}
