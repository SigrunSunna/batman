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
            manager.Management();
        }
        if(input == 's')
        {
            sales.Sales();
        }
        if(input == 'b')
        {
            baker.Baker();
        }
        if(input == 'd')
        {
            delivery.Delivery();
        }
        if(input != 'm' && input != 's' && input != 'b' && input != 'd' && input != 'q')
        {
            cout << endl;
            cout << "Wrong input!, please choose again." << endl;
            cout << endl;
        }
    }
}
