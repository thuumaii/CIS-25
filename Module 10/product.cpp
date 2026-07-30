#include <iostream>
using namespace std;

class Product {
    int id;
    string name;
    float price;

public:
    // Constructor
    Product(int i, string n, float p) {
        id = i;
        name = n;
        price = p;
        cout << "Constructor called" << endl;
    }

    // Destructor
    ~Product() {
        cout << "Destructor called" << endl;
    }

    // Display product information
    void printDetails() {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Price: $" << price << endl;
    }
};

int main() {

    Product p(102, "Book", 7.99);

    p.printDetails();

    return 0;
}