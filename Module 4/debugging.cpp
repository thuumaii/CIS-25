#include <iostream>
using namespace std;

int main()
{
    float n1, n2, n3;

    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;

    // Check if n1 is the largest
    if (n1 >= n2)
    {
        if (n1 >= n3)
        {
            cout << "Largest number: " << n1;
        }
    }

    // Check if n2 is the largest
    if (n2 >= n1)
    {
        if (n2 >= n3)
        {
            cout << "Largest number: " << n2;
        }
    }

    // Check if n3 is the largest
    if (n3 >= n1)
    {
        if (n3 >= n2)
        {
            cout << "Largest number: " << n3;
        }
    }

    return 0;
}
