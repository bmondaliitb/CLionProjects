#include <iostream>

class Rectangle{
public:
    int m_length;
    int m_width;

public:
    void setLength(double length){ m_length = length;}
    void setwidth(double width){ m_width = width;}

    double getLength() const{ return m_length;}

};



int main() {
    std::cout << "Hello, World!" << std::endl;

    Rectangle rectangle_obj;


    return 0;
}

//class std{
//
//};
