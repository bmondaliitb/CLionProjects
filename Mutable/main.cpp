#include <iostream>
using namespace std;

// Customer Class
class Customer {

    // class Variables
    string name;
    mutable string placedorder;
    int tableno;
    mutable int bill;

    // member methods
public:


    // constructor
    Customer(string s, string m, int a, int p)
    {
        name= s;
        placedorder=m;
        tableno = a;
        bill = p;
    }

    // to change the place holder
    void changePlacedOrder(string p) const
    {
        placedorder=p;
    }

    // change the bill
    void changeBill(int s) const { bill = s; }

    // to display
    void display() const
    {
        cout << "Customer name is: " << name << endl;
        cout << "Food ordered by customer is: "
        << placedorder << endl;
        cout << "table no is: " << tableno << endl;
        cout << "Total payable amount: " << bill << endl;
    }
};

// Driver code
int main()
{
    const Customer c1("Pravasi Meet", "Ice Cream", 3, 100);
    c1.display();
    c1.changePlacedOrder("GulabJammuns");
    c1.changeBill(150);
    c1.display();
    return 0;
}
