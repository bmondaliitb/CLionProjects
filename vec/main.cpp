#include <iostream>
#include "vector"

int main() {
auto *vecptr = new std::vector<int>;
vecptr = 0;
int a = 10;
vecptr->push_back(11);
std::cout<<"help me"<<std::endl;
std::cout<<vecptr->at(0)<<std::endl;
std::cout<<(*vecptr)[0]<<std::endl;

std::vector<int> vecObj;
vecObj.push_back(20);
std::cout<<vecObj.at(0)<<std::endl;
std::cout<<vecObj[0]<<std::endl;

return 0;

}
