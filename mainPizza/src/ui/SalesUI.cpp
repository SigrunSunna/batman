#include "SalesUI.h"

void SalesUI::Sales()
{
    char inp = '\0';
    while(inp != 'q')
    {
        cout << "Hello salesperson, would you like to:" << endl;
        cout << "c: create an order, q: quit?: ";
        cin >> inp;
        if(inp == 'c')
        {
            char inp2 = 'y';
            while(inp2 == 'y')
            {
                Pizza pizza;
                cout << "input pizza" << endl;
                cin >> pizza;
                pizza.set_price(2000);
                cout << pizza;
                cout << "Anything else?: (y/n) ";
                cin >> inp2;
            }
        }
    }
}
