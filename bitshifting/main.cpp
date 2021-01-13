// constructing bitsets
#include <iostream>       // std::cout
#include <string>         // std::string
#include <bitset>         // std::bitset

int main ()
{
    std::bitset<8> foo;
    //foo.set();
    std::bitset<16> bar (0xfa2);
    std::bitset<16> baz (std::string("0101111001"));

    bool b_foo = false;

    unsigned int fooint = foo.to_ulong();
    unsigned int foofinal = (fooint & 0x20) >> 5u;
    b_foo = foofinal;

    std::cout << "foo: " << foo.to_ulong() << '\n';
    std::cout <<"fooint " <<foofinal<<std::endl;
    std::cout << "bar: " << bar << '\n';
    std::cout << "baz: " << baz << '\n';
    std::cout<<"print b_foo "<<b_foo<<std::endl;

    return 0;
}