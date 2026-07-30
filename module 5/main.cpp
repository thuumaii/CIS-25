#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    int option;

    do
    {
        showMenu();
        cin >> option;

        if (option == 1)
        {
            add();
        }

        if (option == 2)
        {
            view();
        }

    } while (option != 3);

    return 0;
}
