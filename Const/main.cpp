#include <iostream>

int main() {
  int VAR=25;
  int VAR1=30;
  const int* a = &VAR1;            // In this case I can't change the value in the memory where the pointer
  std::cout<<a<<std::endl;         // is pointing to. So I can't dereference the pointer and write something
  a = &VAR;                        // in that memory.
  std::cout<<a<<std::endl;
  std::cout<<*a<<std::endl;

  int* const b = &VAR1;
  std::cout<<b<<std::endl;         // in this case the pointer is constant. no matter what the pointer (which keeps
  *b = VAR;                        // some memory address) stays same
  std::cout<<b<<std::endl;

  return 0;
}
