#include <iostream>
using namespace std;
#include <memory>

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}

	int area()
	{
		return length * breadth;
	}
};

template<typename T>
class Circle{
public:
    T m_radius;

public:
    Circle(T r)
    : m_radius(r)
    {};

    T area()
    {
        return 2*3.14*m_radius;
    }



};


int main()
{

	unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << P1->area() << endl; // This'll print 50

	// unique_ptr<Rectangle> P2(P1);

	unique_ptr<Rectangle> P2;
	P2 = std::move(P1);

	// This'll print 50
	cout << P2->area() << endl;

	// cout<<P1->area()<<endl;


	//circle
	unique_ptr<Circle<double>> circle(new Circle<double>(10.0));
	cout<<circle->area()<<endl; // area of circle

	return 0;
}
