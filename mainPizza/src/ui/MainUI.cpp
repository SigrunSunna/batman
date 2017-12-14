#include "MainUI.h"
#include <stdlib.h>

void MainUI::startUI()
{
    char input = '\0';
    while(input != 'q')
    {
        cout << endl;
        cout << " WELCOME TO TURBO PIZZA MEGA SYSTEM 3000X.1337" << endl;
        cout << " ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << " What is your position?" << endl;
        cout << " Manager = m, Sales = s, Baker = b, Delivery = d, quit = q: " << endl;
        cout << " -> ";
        cin >> input;
        system("CLS");
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
            cout << " Wrong input!, please choose again." << endl;
            cout << endl;
        }
    }
}
