#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Customer {
public:
    int id;
    string name;
    string service;
    double price;

    Customer(int customerId, string customerName,
             string customerService, double customerPrice) {
        id = customerId;
        name = customerName;
        service = customerService;
        price = customerPrice;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Service: " << service << endl;
        cout << "Price: $" << price << endl;
        cout << "----------------------" << endl;
    }
};

vector<Customer> customers;

// Save data
void saveData() {
    ofstream file("customers.txt");

    if (!file) {
        cout << "Error saving file.\n";
        return;
    }

    for (int i = 0; i < customers.size(); i++) {
        file << customers[i].id << endl;
        file << customers[i].name << endl;
        file << customers[i].service << endl;
        file << customers[i].price << endl;
    }

    file.close();
}

// Load data
void loadData() {
    ifstream file("customers.txt");

    if (!file)
        return;

    int id;
    string name;
    string service;
    double price;

    while (file >> id) {
        file.ignore();

        getline(file, name);
        getline(file, service);

        file >> price;
        file.ignore();

        customers.push_back(Customer(id, name, service, price));
    }

    file.close();
}

// Add customer
void addCustomer() {
    int id;
    string name;
    string service;
    double price;

    cout << "\nEnter customer ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter customer name: ";
    getline(cin, name);

    cout << "Enter service: ";
    getline(cin, service);

    cout << "Enter price: $";
    cin >> price;
    cin.ignore();

    customers.push_back(Customer(id, name, service, price));

    saveData();

    cout << "Customer added successfully.\n";
}

// View customers
void viewCustomers() {

    if (customers.empty()) {
        cout << "\nNo customers found.\n";
        return;
    }

    cout << "\n===== CUSTOMER LIST =====\n";

    for (int i = 0; i < customers.size(); i++) {
        customers[i].display();
    }
}

// Search customer
void searchCustomer() {

    int searchId;

    cout << "\nEnter customer ID: ";
    cin >> searchId;

    for (int i = 0; i < customers.size(); i++) {

        if (customers[i].id == searchId) {

            cout << "\nCustomer Found\n";
            customers[i].display();
            return;
        }
    }

    cout << "Customer not found.\n";
}

// Delete customer
void deleteCustomer() {

    int deleteId;

    cout << "\nEnter customer ID to delete: ";
    cin >> deleteId;

    for (int i = 0; i < customers.size(); i++) {

        if (customers[i].id == deleteId) {

            customers.erase(customers.begin() + i);

            saveData();

            cout << "Customer deleted successfully.\n";
            return;
        }
    }

    cout << "Customer not found.\n";
}

// Total revenue
void showRevenue() {

    double total = 0;

    for (int i = 0; i < customers.size(); i++) {
        total += customers[i].price;
    }

    cout << "\nTotal Revenue: $" << total << endl;
}

// Main
int main() {

    loadData();

    int choice = 0;

    do {

        cout << "\n===== NAIL SALON MANAGEMENT =====\n";
        cout << "1. Add Customer\n";
        cout << "2. View Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Delete Customer\n";
        cout << "5. View Total Revenue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input.\n";
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {

            case 1:
                addCustomer();
                break;

            case 2:
                viewCustomers();
                break;

            case 3:
                searchCustomer();
                break;

            case 4:
                deleteCustomer();
                break;

            case 5:
                showRevenue();
                break;

            case 6:
                cout << "\nProgram ended.\n";
                break;

            default:
                cout << "\nInvalid choice. Please enter 1-6.\n";
        }

    } while (choice != 6);

    return 0;
}
