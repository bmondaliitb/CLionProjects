// Link to the documentation https://www.geeksforgeeks.org/static-keyword-cpp/

/*
 * Static variables in a Function: When a variable is declared as static, space for it gets allocated for the lifetime
 * of the program. Even if the function is called multiple times, space for the static variable is allocated only once
 * and the value of variable in the previous call gets carried through the next function call. This is useful for
 * implementing coroutines in C/C++ or any other application where previous state of function needs to be stored.
 */


/*
 * Static variables in a class: As the variables declared as static are initialized only once as they are allocated
 * space in separate static storage so, the static variables in a class are shared by the objects. There can not be
 * multiple copies of same static variables for different objects. Also because of this reason static variables can not
 * be initialized using constructors.
 */

// CPP program to illustrate
// when not using static keyword
// C++ program to demonstrate static
// variables inside a class

/*
#include<iostream>
using namespace std;

class GfG
{
public:
    static int i;

    GfG()
    {
        // Do nothing
    };
};

int GfG::i = 1;

int main()
{
    GfG obj;
    // prints value of i
    cout << obj.i;
}

*/

// CPP program to illustrate
// class objects as static
#include<iostream>
using namespace std;

class GfG
{
    int i = 0;

public:
    GfG()
    {
        i = 0;
        cout << "Inside Constructor\n";
    }

    ~GfG()
    {
        cout << "Inside Destructor\n";
    }
};

int main()
{
    int x = 0;
    if (x==0)
    {
        static GfG obj;
    }
    cout << "End of main\n";
}
