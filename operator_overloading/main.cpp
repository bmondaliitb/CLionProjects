/*
// overload_date.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

class Date
{
    int mo, da, yr;
public:
    Date(int m, int d, int y)
    {
        mo = m; da = d; yr = y;
    }
    friend ostream& operator<<(ostream& os, const Date& dt);
};

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}

int main()
{
    Date dt(5, 6, 92);
    cout << dt;
}
*/


// CPP program to illustrate
// Operator Overloading
#include<iostream>
using namespace std;

class Complex {
public:
    int real, imag;
public:
    explicit Complex(int r = 0, int i =0) {real = r; imag = i;}

    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) const {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    //void print() { cout << real << " + i" << imag << endl; }

    friend ostream& operator<<(ostream& os,  const Complex& obj);
};

ostream& operator<<(ostream& os,  const Complex& obj){
    os<<obj.real;
    os<<" +i";
    os<<obj.imag;

return os;
}



int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    cout<<c1<<" "<<c2<<" "<<c3<<endl;
    //c3.print();
}
