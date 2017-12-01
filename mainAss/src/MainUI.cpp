#include "MainUI.h"

void MainUI::startUI()
{
    char input = '\0';
    while(input != 'q')
    {
        cout << "What is your position?" << endl;
        cout << "Manager = m, Sales = s, Baker = b, Delivery = d, quit = q: ";
        cin >> input;
        if(input == 'm')
        {
            Manager manager;
        }
        if(input == 's')
        {
            Sales sales;
        }
        if(input == 'b')
        {
            Baker baker;
        }
        if(input == 'd')
        {
            Delivery delivery;
        }
        if(input != 'm' && input != 's' && input != 'b' && input != 'd' && input != 'q')
        {
            cout << endl;
            cout << "Wrong input!, please choose again." << endl;
            cout << endl;
        }
    }
}
