// C++ program to demonstrate working
// of Enum Classes

#include <iostream>
using namespace std;

int main()
{

/*    enum debugLevel{muted, selPassed};

    debugLevel debug = muted;

    if(debug == selPassed) cout<<"selection pt cut has passed"<<endl;*/

    enum class Color { Red,
        Green,
        Blue };
    enum class Color2 { Red,
        Black,
        White };
    enum class People { Good,
        Bad };

    // An enum value can now be used
    // to create variables
    int Green = 10;

    // Instantiating the Enum Class
    Color x = Color::Green;

    // Comparison now is completely type-safe
    if (x == Color::Red)
        cout << "It's Red\n";
    else
        cout << "It's not Red\n";

    People p = People::Good;

    if (p == People::Bad)
        cout << "Bad people\n";
    else
        cout << "Good people\n";

    // gives an error
    // if(x == p)
    // cout<<"red is equal to good";

    // won't work as there is no
    // implicit conversion to int
    // cout<< x;

    cout << int(x)<<endl;

    return 0;
}




/*
#include <iostream>
#include <cstdint>

// enum that takes 16 bits
enum smallenum: std::int16_t
{
    a,
    b,
    c
};


// color may be red (value 0), yellow (value 1), green (value 20), or blue (value 21)
enum color
{
    red,
    yellow,
    green = 20,
    blue
};

// altitude may be altitude::high or altitude::low
enum class altitude: char
{
    high='h',
    low='l', // C++11 allows the extra comma
};

// the constant d is 0, the constant e is 1, the constant f is 3
enum
{
    d,
    e,
    f = e + 2
};

//enumeration types (both scoped and unscoped) can have overloaded operators
std::ostream& operator<<(std::ostream& os, color c)
{
    switch(c)
    {
        case red   : os << "red";    break;
        case yellow: os << "yellow"; break;
        case green : os << "green";  break;
        case blue  : os << "blue";   break;
        default    : os.setstate(std::ios_base::failbit);
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, altitude al)
{
    return os << static_cast<char>(al);
}

int main()
{
    color col = red;
    altitude a;
    a = altitude::low;

    std::cout << "col = " << col << '\n'
              << "a = "   << a   << '\n'
              << "f = "   << f   << '\n';
}
*/