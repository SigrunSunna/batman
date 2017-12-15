#include "ManagementUI.h"
#include "InvalidCharInput.h"
#include "InvalidNumInput.h"


void ManagementUI::Management()
{
    Management_services service;

    char input = '\0';
    while(input != 'q')
    {
        cout << endl;
        cout << " Hello Manager, would you like to:" << endl;
        cout << " t: add toppings" << endl;
        cout << " o: add other products" << endl;
        cout << " v: view orders" << endl;
        cout << " c: change pizza prices" << endl;
        cout << " r: retrieve a specific order." << endl;
        cout << " q: quit " << endl;
        cout << " -> ";
        try {
            cin >> input;
            system("CLS");
            if (input == 'v')
            {
                service.retrieveAllOrders();
            }
            if(input == 't')
            {
                cout << endl;
                cout << " These are the current toppings in the system: " << endl;
                service.addToppings();
            }

            if(input == 'o')
            {
                cout << endl;
                cout << " These are the current sides in the system: " << endl;
                service.addSides();
            }

            if(input == 'c')
            {
                service.sizePrice();
            }
            if(input == 'r')
            {
                int ordInp;
                cout << " What order would you like to pull?" << endl;
                cout << " ->";
                cin >> ordInp;
                system("CLS");
                service.getOrder(ordInp);
            }
            if(input != 't' && input != 'o' && input != 'v' && input != 'c' && input != 'r' && input != 'r' && input != 'q') throw InvalidCharInput();
        }
        catch(InvalidCharInput e)
        {
            cout << " Wrong input!, please choose again." << endl;
        }
    }
}
