/* in this example I have used
 * how to store class objects in a vector
 * copy constructor
 * assignment operator
 * std::move function
 *
 *
*/


#include <iostream>
#include <vector>
using namespace std;

class Demo {
    double d;
public:
    Demo() {
        d = 0.0;
    }
    Demo(double x)
    : d(x)
    {
    }

    Demo &operator=(double x) {
        d = x; return *this;
    }

    //copy constructor
    // ClassName (const ClassName &old_obj);
    Demo (const Demo &obj){
        d = obj.d;
    }

    // assignment operator
    Demo& operator=(const Demo &x) {
        return *this;
    }

    double getd() const {
        return d;
    }

    friend ostream& operator<<(ostream& os, Demo &obj);
};

ostream& operator<<(ostream& os, Demo &obj){
    os<<obj.getd();

    return os;
}

bool operator<(const Demo& a, const Demo& b)
{
    return a.getd() < b.getd();
}

bool operator==(const Demo& a, const Demo& b)
{
    return a.getd() == b.getd();
}

int main()
{
    vector<Demo> v;
    int i;

    for(i = 0; i <10; i++)
        v.emplace_back(i/3.0);

    for(i = 0; i <v.size(); i++)
        cout << v[ i ].getd() << " ";

    cout << endl;

    for(i = 0; i <v.size(); i++)
        v[ i ] = v[ i ].getd() * 2.1;

    for(i = 0; i <v.size(); i++)
        cout << v[ i ].getd() << " ";

    cout<<endl;

    //copy constructor here
    vector<Demo> vCopy = v;

    for (auto v2_ptr : vCopy) {
        cout << v2_ptr << " "; // "<<" overloading operator is being used here
    }

    // Using assignment operator here. assigning v to v2.
    vector<Demo> v2;
    v2 = std::move(v); //using std::move to move the whole obj


    for (auto v2_ptr : v2) {
        cout << v2_ptr << " "; // "<<" overloading operator is being used here
    }

    // trying to access the moved obj v
    cout<< "\nTrying to access v after it is moved"<<endl;
    for (auto v_ptr : v){
        cout << v_ptr << " ";  // since it is already moved. the whole vector is null
    }


    return 0;
}