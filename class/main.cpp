#include <iostream>

class Rectangle{
public:
    int m_length;
    int m_width;
    char* m_name;

public:
    void setLength(double length){ m_length = length;}
    void setwidth(double width){ m_width = width;}
    void setName(char* name){ m_name = name;}

    double getLength() const{ return m_length;}
    double getArea(){return m_length*m_width;}
    char* getName(){return m_name;}

};



int main() {
    std::cout << "Hello, World!" << std::endl;

    Rectangle rectangle_obj;
    rectangle_obj.setLength(11111111);
    rectangle_obj.setwidth(999999);
    rectangle_obj.setName("my Rectangle");


    std::cout<<"Area of the rectangle: "<<rectangle_obj.getArea()<<std::endl;
  std::cout<<"name of the rectangle: "<<rectangle_obj.getName()<<std::endl;


  return 0;
}

//class std{
//
//};
