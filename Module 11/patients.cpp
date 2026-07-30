#include <iostream>
#include <string>

using namespace std;

struct Patient
{
    int id;
    string name;
    int age;
};

int main()
{
    Patient p1;

    p1.id = 2;
    p1.name = "Hannah";
    p1.age = 25;

    Patient* p = &p1;

    cout << "ID: " << p->id << endl;
    cout << "Name: " << p->name << endl;
    cout << "Age: " << p->age << endl;

    return 0;
}