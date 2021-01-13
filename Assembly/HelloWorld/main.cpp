#include <iostream>
#include <memory>

class Entity{
public:
    Entity();
    ~Entity();
    int sum(int& a, int& b);

public:
    int a;
    int b;

};

int Entity::sum(int &a, int &b) {
  std::cout<< "Address of a and b:  "<<&a<<"   "<<&b<<std::endl;
  return (a + b);

}

Entity::Entity() {
  std::cout<<" ====== Entity constructed ======="<<std::endl;

}

Entity::~Entity() {

  std::cout<<" ====== Entity destroyed ======="<<std::endl;

}


int main() {
  //std::cout << "Hello, World!" << std::endl;
  std::unique_ptr<Entity> ptrEntity(new Entity);
  ptrEntity->a = 20;
  ptrEntity->b = 30;

  double sum = ptrEntity->sum(a, b);
  std::cout<< "sum of the two variable:  "<<sum<<std::endl;

  return 0;
}
