#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item
{
public:
    string name;
    double price;
    int quantity;

    void saveToFile()
    {
        ofstream out("cart.txt", ios::app);

        if (out.is_open())
        {
            out << name << " "
                << price << " "
                << quantity << endl;

            out.close();
        }
    }
};

int main()
{
    Item item;
    int choice;

    do
    {
        cout << "1. Add Item" << endl;
        cout << "2. View Checkout" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Name: ";
            cin >> item.name;

            cout << "Price: ";
            cin >> item.price;

            cout << "Quantity: ";
            cin >> item.quantity;

            item.saveToFile();

            cout << "Item added!" << endl;
        }
        else if (choice == 2)
        {
            ifstream in("cart.txt");

            string name;
            double price;
            int quantity;

            while (in >> name >> price >> quantity)
            {
                cout << name << " "
                     << price << " x "
                     << quantity << " = "
                     << price * quantity << endl;
            }

            in.close();
        }
        else if (choice == 3)
        {
            cout << "Thank you for shopping!" << endl;
        }

    } while (choice != 3);

    return 0;
}
