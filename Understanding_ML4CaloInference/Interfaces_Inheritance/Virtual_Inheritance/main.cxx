#include <iostream>

class A {
public:
    void sayHello() { std::cout << "Hello from A\n"; }
    int id;
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D obj;
    obj.sayHello();
    obj.id = 42;
    std::cout<<" value of id: "<<obj.id<<std::endl;
}

