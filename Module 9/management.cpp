#include <iostream>
#include <string>

using namespace std;

// Base class
class User {
protected:
    string username;

public:
    User(string name) {
        username = name;
    }

    // Virtual function
    virtual void accessLevel() {
        cout << "User\t\tGeneral Access" << endl;
    }
};

// Employee class
class Employee : public User {
public:
    Employee(string name) : User(name) {}

    void accessLevel() override {
        cout << "Employee\tView inventory" << endl;
    }
};

// Manager class
class Manager : public User {
public:
    Manager(string name) : User(name) {}

    void accessLevel() override {
        cout << "Manager\t\tView and update inventory" << endl;
    }
};

// Admin class
class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void accessLevel() override {
        cout << "Admin\t\tFull access: add, update, delete inventory" << endl;
    }
};

int main() {

    Employee employee("John");
    Manager manager("Mary");
    Admin admin("Tom");

    cout << "Inventory System" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Role\t\tPermissions" << endl;
    cout << "----------------------------------------------" << endl;

    employee.accessLevel();
    manager.accessLevel();
    admin.accessLevel();

    return 0;
}